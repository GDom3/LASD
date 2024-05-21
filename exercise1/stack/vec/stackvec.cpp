
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */
template <typename Data>
StackVec<Data>::StackVec(const TraversableContainer<Data> &struttura ){
    struttura.Traverse(
        [this](const Data & dato){
            Push(dato);
        }

    );
    
    ultimo = struttura.Size() - 1;
}

template <typename Data>
StackVec<Data>::StackVec(MappableContainer<Data> && struttura ){
    ultimo = struttura.Size() - 1;
    
    struttura.Traverse(
        [this](const Data & dato){
            Push(dato);
        }

    );
    
}

template <typename Data>
StackVec<Data>::StackVec(const StackVec & stkvec){
    stkvec.Traverse(
        [this](const Data & dato){
            Push(dato);
        }

    );
    ultimo = stkvec.Size() - 1;

}

template <typename Data>
StackVec<Data>::StackVec(StackVec && stkvec){
    ultimo = stkvec.Size() - 1;
    stkvec.Traverse(
        [this](const Data & dato){
            Push(dato);
        }

    );
    
}

template <typename Data>
StackVec<Data>::~StackVec(){
    Vector<Data>::Clear();
}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec & stkvec){
    ultimo = stkvec.ultimo - 1;
    return Vector<Data>::operator=((Vector<Data>) stkvec ); 
}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec && stkvec){
    std::swap(ultimo,stkvec.ultimo);
    return Vector<Data>::operator=((Vector<Data>)std::move(stkvec));
    
}

template <typename Data>
bool StackVec<Data>::operator!=(const StackVec & stkvec) const noexcept{
    return !operator==(stkvec);

}

template <typename Data>
bool StackVec<Data>::operator==(const StackVec & stkvec) const noexcept{
    return Vector<Data>::operator==((Vector<Data>)stkvec);

}

template <typename Data>
inline void StackVec<Data>::Clear(){
    Vector<Data>::Clear();
    ultimo = 0;

}

template <typename Data>
void StackVec<Data>::Espandi(){
    if(ultimo == size)
        Vector<Data>::Resize(size * indiceResizePush);
}

template <typename Data>
void StackVec<Data>::Riduci(){
    if(ultimo <= size / (2 * indiceResizePop))
        Vector<Data>::Resize(size / indiceResizePop);
}

template <typename Data>
const Data& StackVec<Data>::Top() const{
    if(Empty())
        throw std::length_error("Stack Vuota!");
    else return elementi[ultimo];
}

template <typename Data>
Data& StackVec<Data>::Top(){
    if(Empty())
        throw std::length_error("Stack Vuota!");
    else return elementi[ultimo];
}



template <typename Data>
inline void StackVec<Data>::Pop(){
    if(Empty())
        throw std::length_error("Stack Vuota!");
   
    Riduci();
    ultimo--;

}

template <typename Data>
Data StackVec<Data>::TopNPop(){
    if(Empty())
        throw std::length_error("Stack Vuota!");
    Data elem = elementi[ultimo];
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
