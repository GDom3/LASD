
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */
template <typename Data>
QueueVec<Data>::QueueVec() : Vector<Data>::Vector(GRANDEZZA_INIZIALE){
    
}


template <typename Data>
QueueVec<Data>::QueueVec(const TraversableContainer<Data> &struttura ): Vector<Data>::Vector(struttura){
    coda = struttura.Size();
    std::cout<<"\n("<< Size() <<")"<< testa << " " << coda << "[" << elementi[0] << "," << elementi[1] << "]\n";
}

template <typename Data>
QueueVec<Data>::QueueVec(MappableContainer<Data> &&struttura ):Vector<Data>::Vector(std::move(struttura)){
    coda = size;
  

}

template <typename Data>
inline QueueVec<Data>::QueueVec(const QueueVec<Data> & quevec):Vector<Data>::Vector(quevec){
    testa = quevec.testa;
    coda = quevec.coda;
}

template <typename Data>
inline QueueVec<Data>::QueueVec(QueueVec<Data> && quevec) noexcept :Vector<Data>(std::move(quevec)){
    std::swap(testa,quevec.testa);
    std::swap(coda,quevec.coda);
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data> & quevec){
   Vector<Data>::operator=(quevec);
    testa = quevec.testa;
    coda = quevec.coda;
    return (*this);
    
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec && quevec) noexcept{
    Vector<Data>::operator=(std::move(quevec));
    std::swap(coda ,quevec.coda);
    std::swap(testa ,quevec.testa);

    return (*this);

}

template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec & quevec) const noexcept{
    return !operator==(quevec);

}

template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec & quevec) const noexcept{
    if(Size() != quevec.Size())
        return false;

    
    for (unsigned long int i = 0; i < Size(); i++)
        if(elementi[ (i + testa ) % size ] != quevec[ (i + quevec.testa ) % quevec.size ]) // circolare
            return false;

    return true;

}


template <typename Data>
void QueueVec<Data>::Resize(unsigned long int newSize){
    if(Size() < newSize)
        return;
    
    Data * newElem = new Data[newSize]();

    unsigned long int j = 0;
    for(unsigned long int i = testa, j = 0; i < coda ; i++ , i%=size , j++)
        std::swap(newElem[j],elementi[i]);
    
    testa = 0;
    coda = j;
    size = newSize;

    std::swap(elementi,newElem);
    delete[] newElem;

}

template <typename Data>
void QueueVec<Data>::Stampa() const {
    std::cout<<"\n [Coda]";
    for(unsigned long int i = 0; i < Size();i++)
        std::cout<<"->"<<elementi[ (testa + i) % size ];
    std::cout<<"-|\n";
}

template <typename Data>
const Data& QueueVec<Data>::Head() const{
    if(Empty()){
        throw std::length_error("Coda Vuota!");
    }

    return elementi[testa]; 

}

template <typename Data>
Data& QueueVec<Data>::Head(){
    if(Empty()){
        throw std::length_error("Coda Vuota!");
    }

    return elementi[testa]; 

}

template <typename Data>
inline void QueueVec<Data>::Dequeue(){
    if(testa == coda)
        throw std::length_error("Coda Vuota!");

    testa++;
    testa%=size;

    if(Size() < size / (TASSO_RIDUZIONE * TASSO_RIDUZIONE))
        Resize(size / TASSO_RIDUZIONE);

   
}

template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){
   
    Data elem = Head();
    Dequeue();
    return elem;

}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data& elem) {
    
    if(Size() >= size)
        Resize(size * TASSO_ESPANZIONE);

    
    elementi[coda] = elem;
    coda++;
    coda%=size;
}

template <typename Data>
void QueueVec<Data>::Enqueue(Data&& elem) {
    if(Size() >= size)
        Resize(size * TASSO_ESPANZIONE);

    
    elementi[coda] = elem;
    coda++;
    coda%=size;
}

template <typename Data>
void QueueVec<Data>::Clear() {
    Resize(GRANDEZZA_INIZIALE);
    
    testa = 0;
    coda = 0;
    

}

}
