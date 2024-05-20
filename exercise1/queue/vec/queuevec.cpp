
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
QueueVec<Data>::QueueVec(const TraversableContainer<Data> &struttura ){
    Vector<Data>::Vector(struttura);
    if(struttura.Size() > 0){
        testa = 0;
        coda = struttura.Size() - 1;
            
    }
}

template <typename Data>
QueueVec<Data>::QueueVec(MappableContainer<Data> &struttura ){
    if(struttura.Size() > 0){
        testa = 0;
        coda = struttura.Size() - 1;
    }
    Vector<Data>::Vector(struttura);
}

template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec & quevec){
    coda = quevec.coda;
    testa = quevec.testa;
    Vector<Data>::Vector((Vector<Data>) quevec);

}

template <typename Data>
QueueVec<Data>::QueueVec(QueueVec && quevec){
    std::swap(coda ,quevec.coda);
    std::swap(testa ,quevec.testa);

    Vector<Data>::Vector((Vector<Data>) quevec);

}

template <typename Data>
QueueVec<Data>::~QueueVec(){
    Vector<Data>::Clear();
    coda = 1;
    testa = 0;
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec & quevec){
    coda = quevec.coda;
    testa = quevec.testa;
    return Vector<Data>::operator=((Vector<Data>) quevec);
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec && quevec){
    std::swap(coda ,quevec.coda);
    std::swap(testa ,quevec.testa);
    return Vector<Data>::operator=((Vector<Data>) quevec);
}

template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec & quevec) const noexcept{
    return !operator==(quevec);

}

template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec & quevec) const noexcept{
    return Vector<Data>::operator==((Vector<Data>)quevec);

}

template <typename Data>
void StackVec<Data>::Espandi(){
    if(Size() == )


}

template <typename Data>
void StackVec<Data>::Riduci(){
    



}

template <typename Data>
const Data& QueueVec<Data>::Head() const{
  if(Empty())
    throw std::length_error("Queue Vuota!");

    return elementi[coda]; 

}

template <typename Data>
Data& QueueVec<Data>::Head(){
  if(Empty())
    throw std::length_error("Queue Vuota!");

    return elementi[coda]; 


}

template <typename Data>
inline void QueueVec<Data>::Dequeue(){
    

}

template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){
   

}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data& elem) {
   
}

template <typename Data>
void QueueVec<Data>::Enqueue(Data&& elem) {
    

}

}
