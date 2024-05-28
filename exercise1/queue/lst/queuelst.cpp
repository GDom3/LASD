
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
QueueLst<Data>::QueueLst(const TraversableContainer<Data> &struttura ):List<Data>(struttura){

}

template <typename Data>
QueueLst<Data>::QueueLst(MappableContainer<Data> &struttura ):List<Data>(std::move(struttura)){

}

template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst & quelist):List<Data>(quelist){

}

template <typename Data>
QueueLst<Data>::QueueLst(QueueLst && quelist):List<Data>(std::move(quelist)){

}

template <typename Data>
QueueLst<Data>::~QueueLst(){
    List<Data>::Clear();
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst & quelist){

    List<Data>::operator=(quelist);
    return (*this);

    
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst && quelist){
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
const Data& QueueLst<Data>::Head() const{
    return  List<Data>::Front();


}

template <typename Data>
Data& QueueLst<Data>::Head(){
    return  List<Data>::Front();
}

template <typename Data>
inline void QueueLst<Data>::Dequeue(){
    List<Data>::RemoveFromFront();

}

template <typename Data>
Data QueueLst<Data>::HeadNDequeue(){
   return List<Data>::FrontNRemove();

}

template <typename Data>
void QueueLst<Data>::Enqueue(const Data& elem) {
    List<Data>::InsertAtBack(elem);
}

template <typename Data>
void QueueLst<Data>::Enqueue(Data&& elem) {
    List<Data>::InsertAtBack(std::move(elem));
}


}

