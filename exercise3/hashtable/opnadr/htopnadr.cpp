
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
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& tabella) noexcept{
    std::swap(size,tabella.size);
    std::swap(numeroCelle,tabella.numeroCelle);
    std::swap(hashtable,tabella.hashtable);
}

template <typename Data> 
HashTableOpnAdr<Data>::~HashTableOpnAdr(){
    Clear();


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
    //Stampa();
    //std::cout<<"\nENTROOOOOOOOO";

    if(Exists(elem))
        return false;
    
    if(size >= numeroCelle)
        Resize(numeroCelle * TASSO_ESPANZIONE);

    unsigned long posizione = FindEmpty(elem);
    
     //std::cout<<"\nECCOMIIIII\n";   
    hashtable[posizione].elemento = elem;  
    //hashtable[posizione].deleted = false;
    hashtable[posizione].vuoto = false;
    hashtable[posizione].usato = true;
    size++;
    
    //std::cout<<"\n["<<size<<"] "<<elem<<"\n";

    //std::cout<<"\n["<<posizione<<"] "<<elem<<"\n";

    return true;
    
}


template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& elem){
    if(Exists(elem))
        return false;

    if(size >= numeroCelle)
        Resize(numeroCelle * TASSO_ESPANZIONE);

    unsigned long posizione = FindEmpty(elem);
    
    //std::cout<<"["<<size+1<<"] "<<elem<<"\n";
    std::swap(hashtable[posizione].elemento,elem);
    //hashtable[posizione].deleted = false;  
    hashtable[posizione].vuoto = false;
    hashtable[posizione].usato = true;
    size++; 
    //std::cout<<"size = "<<size<<"\n";
    

    return true;

}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& elem) {
    //Stampa();
    if(!Exists(elem)){
        return false;
    }

    unsigned long posizione = Find(elem);

    //hashtable[posizione].deleted = true;
    hashtable[posizione].vuoto = true;
    size--;
    //std::cout<<"\nsize = "<<size;
    
    
    if(numeroCelle > GRANDEZZA_INIZIALE && size < (numeroCelle / (TASSO_RIDUZIONE * TASSO_RIDUZIONE)))
        Resize(numeroCelle / TASSO_RIDUZIONE);

    
    return true;

}


template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& elem) const noexcept { 
    unsigned long pos = HashKey(elem);
    
    unsigned long i = 0;
    for( i = 0 ; i < numeroCelle; i++ ){
        
        if(hashtable[pos].usato && !hashtable[pos].vuoto && hashtable[pos].elemento == elem){
            return true;
        }
            

        pos = DoppioHashing(elem,pos,i);
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
    
    unsigned long newNumCelle = num < numeroCelle?GRANDEZZA_INIZIALE:numeroCelle;
    while(newNumCelle < num)
        newNumCelle*=2;
    
    
    HashTableOpnAdr<Data> * copia = new HashTableOpnAdr(newNumCelle);
    for(unsigned long i = 0; i < numeroCelle; i++)
        if(hashtable[i].usato && !hashtable[i].vuoto )
            copia->Insert(hashtable[i].elemento);

    
    std::swap(*copia,*this);
    delete copia;

}


template <typename Data>
void HashTableOpnAdr<Data>::Clear() {
    
    size = 0;
    numeroCelle = GRANDEZZA_INIZIALE;
    hashtable.Resize(numeroCelle);
    for(unsigned long i = 0; i < numeroCelle; i++){
        //hashtable[i].deleted = false;
        hashtable[i].vuoto = true;
        hashtable[i].usato = false;
    }


}

template <typename Data>
const unsigned long HashTableOpnAdr<Data>::DoppioHashing(const Data& dato, const unsigned long& h, const unsigned long& i) const{

    //return (h+num) % numeroCelle; Lineare
    Hashable<Data> hash{};
    
    unsigned long dispari = std::floor(hash.hashDue(dato) * numeroCelle) * 2 + 1;
    return (HashKey(dato) + i * dispari) % numeroCelle;



}

template <typename Data>
const unsigned long HashTableOpnAdr<Data>::Find(const Data& dato) const{
    unsigned long pos = HashKey(dato);

    unsigned long i = 0;
    for( i = 0 ; i < numeroCelle ; i++ ){
        if(hashtable[pos].usato && hashtable[pos].vuoto == false && hashtable[pos].elemento == dato)
            return pos;

        pos = DoppioHashing(dato,pos,i);
    }

        
    return numeroCelle + 1;
    

}

template <typename Data>
const unsigned long HashTableOpnAdr<Data>::FindEmpty(const Data& dato) const{

    unsigned long pos = HashKey(dato);
    
    for(unsigned long i = 0; i < numeroCelle; i++ ){
        if(hashtable[pos].vuoto)
            return pos;

        //std::cout<<"\n["<<pos<<"] "<<dato<<"\n";
        pos = DoppioHashing(dato,pos,i); 

    }

        
    return pos;
}


template <typename Data>
void HashTableOpnAdr<Data>::Stampa(){
    std::cout<<"\n[Hash]";
    for(unsigned long k = 0; k < numeroCelle; k++)
        if (hashtable[k].usato && hashtable[k].vuoto == false)
            std::cout<<"-> "<<hashtable[k].elemento;
    std::cout<<" -|\n";
}








}
