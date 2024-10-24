
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr() : HashTableClsAdr(GRANDEZZA_INIZIALE){

}


template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const unsigned long& num){
    numeroCelle = GRANDEZZA_INIZIALE;
    
    if(num > GRANDEZZA_INIZIALE)
        while(numeroCelle < num)
            numeroCelle*=2;
    
    hashtable.Resize(numeroCelle);


}

  
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data>& struttura) : HashTableClsAdr(struttura.Size()){
    DictionaryContainer<Data>::InsertAll(struttura);

}

  
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const unsigned long& num, const TraversableContainer<Data>& struttura) : HashTableClsAdr(num){
    DictionaryContainer<Data>::InsertAll(struttura);
    
}

 

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data>&& struttura) noexcept : HashTableClsAdr(struttura.Size()){
    DictionaryContainer<Data>::InsertAll(std::move(struttura));

}

  
template <typename Data> 
HashTableClsAdr<Data>::HashTableClsAdr(const unsigned long& num, MappableContainer<Data>&& struttura) noexcept : HashTableClsAdr(num){
    DictionaryContainer<Data>::InsertAll(std::move(struttura));

}


template <typename Data> 
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& tabella) : HashTableClsAdr(tabella.numeroCelle){
    
    for(unsigned long i = 0; i < tabella.numeroCelle; i++)
        if(tabella.hashtable[i] != nullptr && !(tabella.hashtable[i]->Empty()))
            tabella.hashtable[i]->BreadthTraverse( 
                [this](const Data& elem){
                    this->Insert(elem);
                }

            );

}


template <typename Data> 
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& tabella) noexcept : HashTableClsAdr(GRANDEZZA_INIZIALE){
    std::swap(size,tabella.size);
    std::swap(numeroCelle,tabella.numeroCelle);
    std::swap(hashtable,tabella.hashtable);
}


template <typename Data> 
HashTableClsAdr<Data>::~HashTableClsAdr(){
    Clear();
    
}


template <typename Data> 
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data>& tabella){
    HashTableClsAdr * copia = new HashTableClsAdr(tabella);
    std::swap(*this,*copia);
    delete copia;

    return *this;

}

template <typename Data> 
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data>&& tabella) noexcept{
    std::swap(size,tabella.size);
    std::swap(numeroCelle,tabella.numeroCelle);
    std::swap(hashtable,tabella.hashtable);
    
    return *this;
}


template <typename Data> 
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data>& tabella) const noexcept{
    if(size != tabella.size)
        return false;
    
    if(size == 0 && size == tabella.size)
        return true;
    
    bool uguali = true;

    for(unsigned long i = 0; i < tabella.numeroCelle; i++)
        if(tabella.hashtable[i] != nullptr && !(tabella.hashtable[i]->Empty()))
                tabella.hashtable[i]->BreadthTraverse(
                    [this, &uguali](const Data& dato){
                        uguali &= this->Exists(dato);
                            
                    }
                );
    
    return uguali;

}

template <typename Data> 
bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr<Data>& tabella) const noexcept{
    return !operator==(tabella);

}


template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& elem) {
    if(Exists(elem))
        return false;
    
    unsigned long chiave = HashKey(elem);

    if(hashtable[chiave] == nullptr)
        hashtable[chiave] = new BST<Data>{};
        //hashtable[chiave] = new List<Data>{};

    if(hashtable[chiave]->Insert(elem)){
        size++;
        return true;
    }
   
    return false;
    

}
  
template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& elem){

    if(Exists(elem))
        return false;

    unsigned long chiave = HashKey(elem);

    if(hashtable[chiave] == nullptr)
        hashtable[chiave] = new BST<Data>{};
        //hashtable[chiave] = new List<Data>{};
    
    if(hashtable[chiave]->Insert(std::move(elem))){
        size++;
        return true;
    }
    
    return false;

}
  
template <typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& elem) {
    unsigned long chiave = HashKey(elem);

    if(hashtable[chiave] != nullptr)
        if(hashtable[chiave]->Remove(elem)){
            size--;
            return true;
        }
    
    return false;

}

template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& elem) const noexcept {
    unsigned long chiave = HashKey(elem);

    if(size == 0 || hashtable[chiave] == nullptr)
        return false;

    return hashtable[chiave]->Exists(elem);
    


}

template <typename Data>
void HashTableClsAdr<Data>::Resize (const unsigned long num){
    if(num == 0){
        Clear();
        return;
    }
  
    HashTableClsAdr<Data> * copia = new HashTableClsAdr(num);

    for(unsigned long i = 0; i < numeroCelle; i++)
        if(hashtable[i] != nullptr && !(hashtable[i]->Empty()))
            hashtable[i]->BreadthTraverse(
                [copia](const Data& elem){
                    copia->Insert(elem);
                }
            );

    std::swap(*copia,*this);
    delete copia;

}

template <typename Data>
void HashTableClsAdr<Data>::Clear() {
    
    for(unsigned int i = 0; i < numeroCelle; i++){
        delete hashtable[i];
        hashtable[i] = nullptr;
    }

    size = 0;
    numeroCelle = GRANDEZZA_INIZIALE;
    hashtable.Resize(numeroCelle);


}


template <typename Data>
void HashTableClsAdr<Data>::Stampa(){
    std::cout<<"\n[Hash]("<<size<<")";
    for(unsigned long k = 0; k < numeroCelle; k++)
        if (hashtable[k] != nullptr){
            lasd::BTBreadthIterator<Data> iteratore{*hashtable[k]};
            while(!iteratore.Terminated()){
                std::cout<<"-> "<<*iteratore;
                ++iteratore;
            }
        }
    std::cout<<" -|\n";
}



}
