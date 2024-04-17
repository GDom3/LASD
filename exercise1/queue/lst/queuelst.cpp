
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
QueueLst<Data>::QueueLst(const TraversableContainer<Data> &struttura ){
    List<Data>::List(struttura);
}

template <typename Data>
QueueLst<Data>::QueueLst(MappableContainer<Data> &struttura ){
    List<Data>::List(struttura);
}

template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst & stklist){
    List<Data>::List((List<Data>) stklist);

}

template <typename Data>
QueueLst<Data>::QueueLst(QueueLst && stklist){
    List<Data>::List((List<Data>) stklist);

}

template <typename Data>
QueueLst<Data>::~QueueLst(){
    List<Data>::Clear();
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst & stklist){
    return List<Data>::operator=((List<Data>) stklist);
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst && stklist){
    return List<Data>::operator=((List<Data>) stklist);
}

template <typename Data>
bool QueueLst<Data>::operator!=(const QueueLst & stklist) const noexcept{
    return !operator==(stklist);

}

template <typename Data>
bool QueueLst<Data>::operator==(const QueueLst & stklist) const noexcept{
    return List<Data>::operator==((List<Data>)stklist);

}

template <typename Data>
const Data& QueueLst<Data>::Head() const{
    if(head == nullptr)
        throw std::length_error("Stack Vuota!");

    return head->elemento;
}

template <typename Data>
Data& QueueLst<Data>::Head(){
    if(head == nullptr)
        throw std::length_error("Stack Vuota!");

    return head->elemento;
}

template <typename Data>
inline void QueueLst<Data>::Dequeue(){
    List<Data>::RemoveFromFront();

}

template <typename Data>
Data QueueLst<Data>::HeadNDequeue(){
    Data temp = head->elemento;
    List<Data>::RemoveFromFront();
    return temp;

}

template <typename Data>
void QueueLst<Data>::Enqueue(const Data& elem) {
    List<Data>::InsertAtBack(elem);
}

template <typename Data>
void QueueLst<Data>::Enqueue(Data&& elem) {
    List<Data>::InsertAtBack(elem);
}


}

