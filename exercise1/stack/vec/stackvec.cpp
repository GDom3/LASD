
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */
template <typename Data>
StackVec<Data>::StackVec(const TraversableContainer<Data> &struttura ):Vector<Data>(struttura){
    ultimo = size;
}

template <typename Data>
StackVec<Data>::StackVec(MappableContainer<Data> && struttura ):Vector<Data>(std::move(struttura)){
    ultimo = size;
}

template <typename Data>
StackVec<Data>::StackVec(const StackVec & stkvec): Vector<Data>(stkvec){
    ultimo = stkvec.ultimo;

}

template <typename Data>
StackVec<Data>::StackVec(StackVec && stkvec):Vector<Data>(std::move(stkvec)){
    std::swap(ultimo,stkvec.ultimo);
    
}

template <typename Data>
StackVec<Data>::~StackVec(){
    Vector<Data>::Clear();
}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec & stkvec){
   Vector<Data>::operator=(stkvec);
   ultimo = stkvec.ultimo;
    
    return (*this);

}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec && stkvec){
    
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
    for(unsigned long int i = 0; i < ultimo; i++)
        Pop();
    ultimo = 0;

}

template <typename Data>
void StackVec<Data>::Espandi(){
    if(size == 0)
        Vector<Data>::Resize(10);
    else if(ultimo == size)
        Vector<Data>::Resize(size*2);
}

template <typename Data>
void StackVec<Data>::Riduci(){
    if(ultimo == size/4)
        Vector<Data>::Resize(size/2);
}

template <typename Data>
const Data& StackVec<Data>::Top() const{
    if(ultimo == 0)
        throw std::length_error("Stack Vuota!");
    else 
        return elementi[ultimo-1];
}

template <typename Data>
Data& StackVec<Data>::Top(){
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
    Riduci();
    

}

template <typename Data>
Data StackVec<Data>::TopNPop(){
    if(ultimo == 0)
        throw std::length_error("Stack Vuota!");
    
    Data elem = elementi[ultimo-1];
    Pop();

    return elem;

}

template <typename Data>
void StackVec<Data>::Push(const Data& elem) {
    Espandi();
    elementi[ultimo++] = elem;
}

template <typename Data>
void StackVec<Data>::Push(Data&& elem) {
    Espandi();
    elementi[ultimo++] = std::move(elem);
 
}

}
