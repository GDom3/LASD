
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
StackLst<Data>::StackLst(const TraversableContainer<Data> &struttura ){
    struttura.Traverse(
        [this](const Data & dato){
            Push(dato);
        }

    );
}

template <typename Data>
StackLst<Data>::StackLst(MappableContainer<Data> &&struttura ){
   struttura.Traverse(
        [this](const Data & dato){
            Push(dato);
        }

    );
}

template <typename Data>
StackLst<Data>::StackLst(const StackLst & stklist){
    stklist.Traverse(
        [this](const Data & dato){
            Push(dato);
        }

    );

}

template <typename Data>
StackLst<Data>::StackLst(StackLst && stklist){
    stklist.Traverse(
        [this](const Data & dato){
            Push(dato);
        }

    );
}

template <typename Data>
StackLst<Data>::~StackLst(){
    List<Data>::Clear();
}

template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst & stklist){
    return List<Data>::operator=((List<Data>) stklist);
}

template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst && stklist){
    return List<Data>::operator=((List<Data>) stklist);
}

template <typename Data>
bool StackLst<Data>::operator!=(const StackLst & stklist) const noexcept{
    return !operator==(stklist);

}

template <typename Data>
bool StackLst<Data>::operator==(const StackLst & stklist) const noexcept{
    return List<Data>::operator==((List<Data>)stklist);

}

template <typename Data>
const Data& StackLst<Data>::Top() const{
    if(head == nullptr)
        throw std::length_error("Stack Vuota!");

    return head->elemento;
}

template <typename Data>
Data& StackLst<Data>::Top(){
    if(head == nullptr)
        throw std::length_error("Stack Vuota!");

    return head->elemento;
}

template <typename Data>
inline void StackLst<Data>::Pop(){
    List<Data>::RemoveFromFront();

}

template <typename Data>
Data StackLst<Data>::TopNPop(){
    Data temp = head->elemento;
    List<Data>::RemoveFromFront();
    return temp;

}

template <typename Data>
void StackLst<Data>::Push(const Data& elem) {
    List<Data>::InsertAtFront(elem);
}

template <typename Data>
void StackLst<Data>::Push(Data&& elem) {
    List<Data>::InsertAtFront(elem);
}


}
