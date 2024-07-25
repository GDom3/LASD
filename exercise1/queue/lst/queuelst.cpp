
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
QueueLst<Data>::QueueLst(const TraversableContainer<Data> &struttura ):List<Data>::List(struttura){

}

template <typename Data>
QueueLst<Data>::QueueLst(MappableContainer<Data> &&struttura ) :List<Data>::List(std::move(struttura)){

}

template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst & quelist):List<Data>::List(quelist){

}

template <typename Data>
QueueLst<Data>::QueueLst(QueueLst && quelist) noexcept : List<Data>::List(std::move(quelist)){

}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst & quelist){

    List<Data>::operator=(quelist);
    return (*this);

    
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst && quelist) noexcept{
    List<Data>::operator=(std::move(quelist));
    return (*this);

}

template <typename Data>
bool QueueLst<Data>::operator!=(const QueueLst & quelist) const noexcept{
    return !operator==(quelist);

}

template <typename Data>
bool QueueLst<Data>::operator==(const QueueLst & quelist) const noexcept{
    return List<Data>::operator==(quelist);

}

template <typename Data>
inline const Data& QueueLst<Data>::Head() const{
    if(size == 0)
        throw std::length_error("Coda Vuota !");

    return  List<Data>::Front();


}

template <typename Data>
inline Data& QueueLst<Data>::Head(){
    if(size == 0)
        throw std::length_error("Coda Vuota !");

    return  List<Data>::Front();
}

template <typename Data>
inline void QueueLst<Data>::Dequeue(){
    if(size == 0)
        throw std::length_error("Coda Vuota !");
    
    return List<Data>::RemoveFromFront();

}

template <typename Data>
inline Data QueueLst<Data>::HeadNDequeue(){
    if(size == 0)
        throw std::length_error("Coda Vuota !");

   return List<Data>::FrontNRemove();

}

template <typename Data>
inline void QueueLst<Data>::Enqueue(const Data& elem) {
    return List<Data>::InsertAtBack(elem);
}

template <typename Data>
inline void QueueLst<Data>::Enqueue(Data&& elem) {
    return List<Data>::InsertAtBack(std::move(elem));
}


}

