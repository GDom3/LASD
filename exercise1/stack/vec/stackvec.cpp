
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
StackVec<Data>::StackVec(const TraversableContainer<Data> &struttura ):Vector<Data>::Vector(struttura){
    ultimo = size;
}

template <typename Data>
StackVec<Data>::StackVec(MappableContainer<Data> && struttura ):Vector<Data>::Vector(std::move(struttura)){
    ultimo = size;
}

template <typename Data>
StackVec<Data>::StackVec(const StackVec & stkvec): Vector<Data>::Vector(stkvec){
    ultimo = stkvec.ultimo;

}

template <typename Data>
StackVec<Data>::StackVec(StackVec && stkvec) noexcept :Vector<Data>::Vector(std::move(stkvec)) {
    std::swap(ultimo,stkvec.ultimo);
    
}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec & stkvec){
   Vector<Data>::operator=(stkvec);
   ultimo = stkvec.ultimo;
    
    return (*this);

}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec && stkvec) noexcept{
    
    Vector<Data>::operator=(std::move(stkvec));
    std::swap(ultimo,stkvec.ultimo);
    
    return (*this); 
}

template <typename Data>
bool StackVec<Data>::operator!=(const StackVec & stkvec) const noexcept{
    return !operator==(stkvec);

}

template <typename Data>
bool StackVec<Data>::operator==(const StackVec & stkvec) const noexcept{
    if(stkvec.ultimo != ultimo)
        return false;

    for(unsigned long int i = 0; i < ultimo; i++)
        if(elementi[i] != stkvec.elementi[i])
            return false;

    return true;

}

template <typename Data>
inline void StackVec<Data>::Clear(){
    Resize(GRANDEZZA_INIZIALE);
    ultimo = 0;

}

template <typename Data>
inline const Data& StackVec<Data>::Top() const{
    if(ultimo == 0)
        throw std::length_error("Stack Vuota!");
    else 
        return elementi[ultimo-1];
}

template <typename Data>
inline Data& StackVec<Data>::Top(){
    if(ultimo == 0){
        throw std::length_error("Stack Vuota!");
    }else{

        return elementi[ultimo-1];
    } 
}



template <typename Data>
inline void StackVec<Data>::Pop(){
    if(ultimo == 0)
        throw std::length_error("Stack Vuota!");
    
    ultimo--;
    if(ultimo < (size / (TASSO_RIDUZIONE * TASSO_RIDUZIONE)))
        Resize(size / TASSO_RIDUZIONE);
    

}

template <typename Data>
inline Data StackVec<Data>::TopNPop(){

    Data elem = Top();
    Pop();

    return elem;

}

template <typename Data>
inline void StackVec<Data>::Push(const Data& elem) {
    if(ultimo == size)
        Resize(size * TASSO_Espanzione);
    
    elementi[ultimo++] = elem;
}

template <typename Data>
inline void StackVec<Data>::Push(Data&& elem) {
    if(ultimo == size)
        Resize(size * TASSO_Espanzione);
    
    elementi[ultimo++] = std::move(elem);
 
}

template <typename Data>
inline void StackVec<Data>::Resize(unsigned long int newSize){
    if(newSize >= GRANDEZZA_INIZIALE)
        Vector<Data>::Resize(newSize);
}

}
