
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
inline StackLst<Data>::StackLst(const TraversableContainer<Data> &struttura ):List<Data>::List(struttura){
 
}

template <typename Data>
inline StackLst<Data>::StackLst(MappableContainer<Data> &&struttura ):List<Data>::List(std::move(struttura)){
}

template <typename Data>
inline StackLst<Data>::StackLst(const StackLst<Data> & stklist):List<Data>::List(stklist){


}

template <typename Data>
inline StackLst<Data>::StackLst(StackLst && stklist):List<Data>::List(std::move(stklist)){

}


template <typename Data>
inline StackLst<Data>& StackLst<Data>::operator=(const StackLst<Data> & stklist){
    List<Data>::operator=(stklist);
    return (*this);
}




template <typename Data>
inline StackLst<Data>& StackLst<Data>::operator=(StackLst && stklist) noexcept{
    
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
    if(size == 0)
        throw std::length_error("Stack Vuoto!");

    return List<Data>::Front();
}

template <typename Data>
Data& StackLst<Data>::Top(){
    if(size == 0)
        throw std::length_error("Stack Vuoto!");
        
    return List<Data>::Front();
}

template <typename Data>
inline void StackLst<Data>::Pop(){
    if(size == 0)
        throw std::length_error("Stack Vuoto!");
        
    List<Data>::RemoveFromFront();

}

template <typename Data>
Data StackLst<Data>::TopNPop(){
    if(size == 0)
        throw std::length_error("Stack Vuoto!");

    return List<Data>::FrontNRemove();

}

template <typename Data>
void StackLst<Data>::Push(const Data& elem) {
    List<Data>::InsertAtFront(elem);
}

template <typename Data>
void StackLst<Data>::Push(Data&& elem) {
    List<Data>::InsertAtFront(std::move(elem));
}


}
