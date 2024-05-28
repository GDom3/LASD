
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
StackLst<Data>::StackLst(const TraversableContainer<Data> &struttura ):List<Data>(struttura){
 
}

template <typename Data>
StackLst<Data>::StackLst(MappableContainer<Data> &&struttura ):List<Data>(std::move(struttura)){
}

template <typename Data>
StackLst<Data>::StackLst(const StackLst & stklist):List<Data>(stklist){


}

template <typename Data>
StackLst<Data>::StackLst(StackLst && stklist):List<Data>(std::move(stklist)){

}

template <typename Data>
StackLst<Data>::~StackLst(){
    List<Data>::Clear();
}

template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst & stklist){
    List<Data>::operator=(stklist);
   
    return (*this);
}




template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst && stklist){
    
     List<Data>::operator=(std::move(stklist));

    return (*this);
}

template <typename Data>
bool StackLst<Data>::operator!=(const StackLst & stklist) const noexcept{
    return !operator==(stklist);

}

template <typename Data>
bool StackLst<Data>::operator==(const StackLst & stklist) const noexcept{
    return List<Data>::operator==(stklist);

}

template <typename Data>
const Data& StackLst<Data>::Top() const{
    return List<Data>::Front();
}

template <typename Data>
Data& StackLst<Data>::Top(){
    return List<Data>::Front();
}

template <typename Data>
inline void StackLst<Data>::Pop(){
    List<Data>::RemoveFromFront();

}

template <typename Data>
Data StackLst<Data>::TopNPop(){
    return List<Data>::FrontNRemove();

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
