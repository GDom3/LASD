
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
QueueLst<Data>::QueueLst(const TraversableContainer<Data> &struttura ){
    struttura.Traverse(
        [this](const Data & dato){
            Enqueue(dato);
        }

    );
}

template <typename Data>
QueueLst<Data>::QueueLst(MappableContainer<Data> &struttura ){
    struttura.Traverse(
        [this](const Data & dato){
            Enqueue(dato);
        }

    );
}

template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst & quelist){
    quelist.Traverse(
        [this](const Data & dato){
            Enqueue(dato);
        }

    );

}

template <typename Data>
QueueLst<Data>::QueueLst(QueueLst && quelist){
    quelist.Traverse(
        [this](const Data & dato){
            Enqueue(dato);
        }

    );

}

template <typename Data>
QueueLst<Data>::~QueueLst(){
    List<Data>::Clear();
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst & quelist){
    return List<Data>::operator=((List<Data>) quelist);
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst && quelist){
    return List<Data>::operator=((List<Data>) quelist);
}

template <typename Data>
bool QueueLst<Data>::operator!=(const QueueLst & quelist) const noexcept{
    return !operator==(quelist);

}

template <typename Data>
bool QueueLst<Data>::operator==(const QueueLst & quelist) const noexcept{
    return List<Data>::operator==((List<Data>)quelist);

}

template <typename Data>
const Data& QueueLst<Data>::Head() const{
    if(head == nullptr)
        throw std::length_error("Queue Vuota!");

    return head->elemento;
}

template <typename Data>
Data& QueueLst<Data>::Head(){
    if(head == nullptr)
        throw std::length_error("Queue Vuota!");

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

