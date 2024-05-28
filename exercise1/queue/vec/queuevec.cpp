
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
QueueVec<Data>::QueueVec(const TraversableContainer<Data> &struttura ): Vector<Data>(struttura){
    coda = size;
    Vector<Data>::Resize(size*2);

}

template <typename Data>
QueueVec<Data>::QueueVec(MappableContainer<Data> &&struttura ):Vector<Data>(std::move(struttura)){
    coda = size;
    Vector<Data>::Resize(size*2);

}

template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec & quevec):Vector<Data>(quevec){
    testa = quevec.testa;
    coda = quevec.coda;
}

template <typename Data>
QueueVec<Data>::QueueVec(QueueVec && quevec):Vector<Data>(std::move(quevec)){
    std::swap(testa,quevec.testa);
    std::swap(coda,quevec.coda);
}


template <typename Data>
QueueVec<Data>::~QueueVec(){
    Vector<Data>::Clear();
    coda = 1;
    testa = 0;
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec & quevec){
   Vector<Data>::operator=(quevec);
    testa = quevec.testa;
    coda = quevec.coda;
    return (*this);
    
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec && quevec){
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

    unsigned long int temp = testa;

    while(temp != coda){
        if(quevec.elementi[temp] != elementi[temp])
            return false;
        
        temp++;
        temp%=size;
    }
    return true;

}

template <typename Data>
void QueueVec<Data>::Espandi(){
    if (size == 0)
        Resize(10,0);
    else if(Size() + 1 == size ){
        Resize(size*2,Size());
    }


}

template <typename Data>
void QueueVec<Data>::Riduci(){
    if(Size() + 1 == size / 4){
        Resize(size/2,Size());
    }


}

template <typename Data>
void QueueVec<Data>::Resize(const unsigned long int nuovaSize, unsigned long int numeroElementi){
    
    if(nuovaSize == 0){
        Clear();
        return;
    }
    
    unsigned long int min = nuovaSize;
    if(min > numeroElementi)
        min = numeroElementi;

    if(nuovaSize != size){
        Data * nuovo =new Data[nuovaSize]{};
        unsigned long int
            i = testa,
            j = 0;
        
        while(i != coda && j < min){
            std::swap(nuovo[j++],elementi[i++]);
            i%=size;
        }

        size = nuovaSize;
        std::swap(elementi,nuovo);
        delete[] nuovo;
        testa = 0;
        coda = min;


    }

}


template <typename Data>
const Data& QueueVec<Data>::Head() const{
    if(Empty()){
        throw std::length_error("Queue Vuota!");
    }
    

    return elementi[testa]; 

}

template <typename Data>
Data& QueueVec<Data>::Head(){
    if(Empty()){
        throw std::length_error("Queue Vuota!");
    }

    return elementi[testa]; 

}

template <typename Data>
inline void QueueVec<Data>::Dequeue(){
    if(testa == coda)
        throw std::length_error("Queue Vuota!");

    Riduci();
    testa++;
    testa%=size;

    if(testa == coda)
        Clear();
}

template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){
    std::cout<<coda<<std::endl;
    Data elem = Head();
    Dequeue();
    return elem;

}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data& elem) {
    Espandi();
    
    elementi[coda] = elem;
    coda++;
    coda%=size;
}

template <typename Data>
void QueueVec<Data>::Enqueue(Data&& elem) {
    Espandi();
    
    std::swap(elementi[coda],elem);
    coda++;
    coda%=size;
}

template <typename Data>
void QueueVec<Data>::Clear() {

    testa = 0;
    coda = 0;
    size = 0;

    delete[] elementi;
    elementi = new Data[10]{};




}

}
