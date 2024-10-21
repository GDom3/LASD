
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr() : HashTableOpnAdr(GRANDEZZA_INIZIALE) {


}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const unsigned long& num){
    numeroCelle = GRANDEZZA_INIZIALE;
    
    if(num > GRANDEZZA_INIZIALE)
        while(numeroCelle < num)
            numeroCelle*=2;
    
    hashtable.Resize(numeroCelle);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data>& struttura) : HashTableOpnAdr(struttura.Size()){
    DictionaryContainer<Data>::InsertAll(struttura);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const unsigned long& num , const TraversableContainer<Data>& struttura) : HashTableOpnAdr(num){
    DictionaryContainer<Data>::InsertAll(struttura);
}
  
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data>&& struttura) noexcept : HashTableOpnAdr(struttura.Size()){
    DictionaryContainer<Data>::InsertAll(std::move(struttura));
}
  
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const unsigned long& num , MappableContainer<Data>&& struttura) noexcept : HashTableOpnAdr(num){
    DictionaryContainer<Data>::InsertAll(std::move(struttura));
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr& tabella) : HashTableOpnAdr(tabella.numeroCelle){
    for(unsigned long i = 0; i < tabella.numeroCelle; i++)
        if(tabella.hashtable[i].usato && !tabella.hashtable[i].vuoto)
            Insert(tabella.hashtable[i].elemento);     
}

template <typename Data> 
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& tabella) noexcept : HashTableOpnAdr(GRANDEZZA_INIZIALE){
    std::swap(size,tabella.size);
    std::swap(numeroCelle,tabella.numeroCelle);
    std::swap(hashtable,tabella.hashtable);
}

template <typename Data> 
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data>& tabella){
    HashTableOpnAdr * copia = new HashTableOpnAdr(tabella);
    std::swap(*this,*copia);
    delete copia;

    return *this;

}

template <typename Data> 
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data>&& tabella) noexcept{
    std::swap(size,tabella.size);
    std::swap(numeroCelle,tabella.numeroCelle);
    std::swap(hashtable,tabella.hashtable);
    
    return *this;
}

template <typename Data> 
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data>& tabella) const noexcept{
    if(size != tabella.size)
        return false;
    
    if(size == 0 && size == tabella.size)
        return true;

    bool uguali = true;
    
    for(unsigned long i = 0; i < numeroCelle ; i++){
        if(tabella.hashtable[i].usato && !tabella.hashtable[i].vuoto){
            uguali &= Exists(tabella.hashtable[i].elemento);
            if(!uguali)
                return false;
        }
            

    }


    return uguali;

}

template <typename Data> 
bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr<Data>& tabella) const noexcept{
    return !operator==(tabella);

}


template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& elem) {
    if(Exists(elem))
        return false;
    
    if(size >= numeroCelle)
        Resize(numeroCelle * TASSO_ESPANZIONE);

    unsigned long posizione = FindEmpty(elem);
      
    hashtable[posizione].elemento = elem;  
    hashtable[posizione].vuoto = false;
    hashtable[posizione].usato = true;
    size++;

    return true;
    
}


template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& elem){
    if(Exists(elem))
        return false;

    if(size >= numeroCelle)
        Resize(numeroCelle * TASSO_ESPANZIONE);

    unsigned long posizione = FindEmpty(elem);
    
    std::swap(hashtable[posizione].elemento,elem);

    hashtable[posizione].vuoto = false;
    hashtable[posizione].usato = true;
    size++; 
    
    return true;

}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& elem) {
    
    unsigned long posizione = Find(elem);

    if(posizione > numeroCelle){ // equivale a exists
        return false;
    }

    hashtable[posizione].vuoto = true;
    size--;
     
    if(numeroCelle > GRANDEZZA_INIZIALE && size < (numeroCelle / (TASSO_RIDUZIONE * TASSO_RIDUZIONE)))
        Resize(numeroCelle / TASSO_RIDUZIONE);

    
    return true;
}


template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& elem) const noexcept { 

    unsigned long pos = 0;
    
    for(unsigned long i = 0 ; i < numeroCelle; i++ ){
        pos = DoppioHashing(elem,i);

        if(hashtable[pos].usato && !hashtable[pos].vuoto && hashtable[pos].elemento == elem){
            return true;
        }  
        
    }
    
        
    return false;
}


template <typename Data>
void HashTableOpnAdr<Data>::Resize (const unsigned long num){
    if(num == 0){
        Clear();
        return;
    }else if (num < GRANDEZZA_INIZIALE || num == numeroCelle)
        return;
   
    HashTableOpnAdr<Data> * copia = new HashTableOpnAdr(num);
    for(unsigned long i = 0; i < numeroCelle; i++)
        if(hashtable[i].usato && !hashtable[i].vuoto )
            copia->Insert(std::move(hashtable[i].elemento));

    
    std::swap(*copia,*this);
    delete copia;

}


template <typename Data>
void HashTableOpnAdr<Data>::Clear() {
    
    size = 0;
    numeroCelle = GRANDEZZA_INIZIALE;
    hashtable.Resize(numeroCelle);
    for(unsigned long i = 0; i < numeroCelle; i++){
        hashtable[i].vuoto = true;
        hashtable[i].usato = false;
    }


}

template <typename Data>
const unsigned long HashTableOpnAdr<Data>::DoppioHashing(const Data& dato, const unsigned long& i) const{

    Hashable<Data> hash{};
    unsigned long dispari = std::floor(hash.hashDue(dato) * numeroCelle) * 2 + 1;

    return (HashKey(dato) + i * dispari) % numeroCelle;
}

template <typename Data>
const unsigned long HashTableOpnAdr<Data>::Find(const Data& dato) const{

    unsigned long pos = 0;

    for(unsigned long i = 0 ; i < numeroCelle ; i++ ){
        
        pos = DoppioHashing(dato,i);

        if(hashtable[pos].usato && !hashtable[pos].vuoto && hashtable[pos].elemento == dato)
            return pos;
        
    }
    
    return numeroCelle + 1;
    

}

template <typename Data>
const unsigned long HashTableOpnAdr<Data>::FindEmpty(const Data& dato) const{

    unsigned long pos = 0;
    
    for(unsigned long i = 0; i < numeroCelle; i++ ){
        pos = DoppioHashing(dato,i); 
        
        if(hashtable[pos].vuoto)
            return pos;

    }
      
    return pos;
}


template <typename Data>
void HashTableOpnAdr<Data>::Stampa(){
    std::cout<<"\n[Hash]("<<size<<")";
    for(unsigned long k = 0; k < numeroCelle; k++)
        if (hashtable[k].usato && hashtable[k].vuoto == false)
            std::cout<<"-> "<<hashtable[k].elemento;
    std::cout<<" -|\n";
}








}
