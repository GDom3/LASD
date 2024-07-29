
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
    numeroElementi = struttura.Size();
}

template <typename Data>
QueueVec<Data>::QueueVec(MappableContainer<Data> &&struttura ):Vector<Data>::Vector(std::move(struttura)){
    coda = struttura.Size();
    numeroElementi = struttura.Size();

}

template <typename Data>
inline QueueVec<Data>::QueueVec(const QueueVec<Data> & quevec):Vector<Data>::Vector(quevec){
    testa = quevec.testa;
    coda = quevec.coda;
    numeroElementi = quevec.numeroElementi;
}

template <typename Data>
inline QueueVec<Data>::QueueVec(QueueVec<Data> && quevec) noexcept :Vector<Data>(std::move(quevec)){
    std::swap(testa,quevec.testa);
    std::swap(coda,quevec.coda);
    std::swap(numeroElementi,quevec.numeroElementi);
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data> & quevec){
   Vector<Data>::operator=(quevec);
    testa = quevec.testa;
    coda = quevec.coda;
    numeroElementi = quevec.numeroElementi;
    return (*this);
    
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec && quevec) noexcept{
    Vector<Data>::operator=(std::move(quevec));
    std::swap(coda ,quevec.coda);
    std::swap(testa ,quevec.testa);
    std::swap(numeroElementi ,quevec.numeroElementi);
    return (*this);

}

template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec & quevec) const noexcept{
    return !operator==(quevec);

}

template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec & quevec) const noexcept{
    if(numeroElementi != quevec.numeroElementi)
        return false;

    
    for (unsigned long int i = 0; i < numeroElementi; i++)
        if(elementi[ (i + testa ) % size ] != quevec[ (i + quevec.testa ) % quevec.size ]) // circolare
            return false;

    return true;

}


template <typename Data>
void QueueVec<Data>::Resize(unsigned long int newSize){
    if(newSize == size || numeroElementi > newSize)
        return;
    
    Data * newElem = new Data[newSize]();

    for(unsigned long int i = testa, j = 0; j < numeroElementi ; i++ , i%=size , j++)
        std::swap(newElem[j],elementi[i]);
    
    testa = 0;
    coda = numeroElementi;
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
    if(numeroElementi == 0){
        throw std::length_error("Coda Vuota!");
    }

    return elementi[testa]; 

}

template <typename Data>
Data& QueueVec<Data>::Head(){
    if(numeroElementi == 0){
        throw std::length_error("Coda Vuota!");
    }

    return elementi[testa]; 

}

template <typename Data>
inline void QueueVec<Data>::Dequeue(){
    if(numeroElementi == 0)
        throw std::length_error("Coda Vuota!");

    testa++;
    testa%=size;
    numeroElementi--;

    if(Size() <= size / (TASSO_RIDUZIONE * TASSO_RIDUZIONE))
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
    
    if(numeroElementi >= size)
        Resize(size * TASSO_ESPANZIONE);

    
    elementi[coda] = elem;
    coda++;
    coda%=size;
    numeroElementi++;
   
}

template <typename Data>
void QueueVec<Data>::Enqueue(Data&& elem) {
    if(numeroElementi >= size)
        Resize(size * TASSO_ESPANZIONE);

    elementi[coda] = std::move(elem);
    coda++;
    coda%=size;
    numeroElementi++;

}

template <typename Data>
void QueueVec<Data>::Clear() {
    Resize(GRANDEZZA_INIZIALE);
    
    testa = 0;
    coda = 0;
    numeroElementi = 0;

}

}
