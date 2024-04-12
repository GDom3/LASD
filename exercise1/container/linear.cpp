
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

//Ricordati dell'eredità multipla 

template <typename Data>
inline bool LinearContainer<Data>::operator==(const LinearContainer<Data>& elem) const noexcept{
    if(Container::size != elem.size)
        return false;
    
    for(unsigned long i = 0; i < Container::size; i++)
        if(operator[](i) != elem[i])
            return false;

    return true;

}

template <typename Data>
inline bool LinearContainer<Data>::operator!=(const LinearContainer<Data>& elem) const noexcept{
    return !(operator==(elem));
}

template <typename Data>
inline const Data& LinearContainer<Data>::Front() const{
    if(Container::size != 0)
        return operator[](0);
    else
        throw std::length_error("Il LinearContainer è Vuoto!");
}

template <typename Data>
inline const Data& LinearContainer<Data>::Back() const{
    if(Container::size != 0)
        return operator[](Container::size-1);
    else
        throw std::length_error("Il LinearContainer è Vuoto!");
}

template <typename Data>
inline Data& LinearContainer<Data>::Front(){
    if(Container::size != 0)
        return operator[](0);
    else
        throw std::length_error("Il LinearContainer è Vuoto!");
}

template <typename Data>
inline Data& LinearContainer<Data>::Back(){
    if(Container::size != 0)
        return operator[](Container::size-1);
    else
        throw std::length_error("Il LinearContainer è Vuoto!");
}

template <typename Data>
inline void LinearContainer<Data>::PreOrderTraverse(TraverseFun funzione) const{
    for(unsigned long int i = 0; i < Container::size; i++)
        funzione(operator[](i));
}

template <typename Data>
inline void LinearContainer<Data>::PostOrderTraverse(TraverseFun funzione) const{
    unsigned long int i = Container::size;
    while(i > 0)
        funzione(operator[](--i));
}

template <typename Data>
inline void LinearContainer<Data>::Map(MapFun funzione){
    PreOrderMap(funzione);
}

template <typename Data>
inline void LinearContainer<Data>::Traverse(TraverseFun funzione) const noexcept{
    PreOrderTraverse(funzione);
}

template <typename Data>
inline void LinearContainer<Data>::PreOrderMap(MapFun funzione) {
    for(unsigned long int i = 0; i < Container::size; i++)
        funzione(operator[](i));
}

template <typename Data>
inline void LinearContainer<Data>::PostOrderMap(MapFun funzione){
    unsigned long int i = Container::size;
    while(i > 0)
        funzione(operator[](--i));
}


template <typename Data>
inline bool SortableLinearContainer<Data>::operator==(const SortableLinearContainer<Data>& elem) const noexcept{
    if(Container::size != elem.size)
        return false;
    
    for(unsigned long i = 0; i < Container::size; i++)
        if(operator[](i) != elem[i])
            return false;

    return true;

}

template <typename Data>
inline bool SortableLinearContainer<Data>::operator!=(const SortableLinearContainer<Data>& elem) const noexcept{
    return !(operator==(elem));
}


template <typename Data>
unsigned long int SortableLinearContainer<Data>::Partition(unsigned long int p, unsigned long int r) noexcept{

  Data x = operator[](p);
  unsigned long int i = p - 1;
  unsigned long int j = r + 1;

  do {

    do { j--; } while ( x < operator[](j) );

    do { i++; } while ( operator[](i) < x );

    if (i < j) { 
        std::swap(operator[](i), operator[](j)); 
    } // "swap" is standard-library function

  } while (i < j);

  return j;

}

template <typename Data>
void SortableLinearContainer<Data>::QuickSort(unsigned long int p, unsigned long int r) noexcept{
    if (p < r) {
        unsigned long int q = Partition(p, r);
        QuickSort(p, q);
        QuickSort(q + 1, r);
  }
}

template <typename Data>
void SortableLinearContainer<Data>::Sort() noexcept{
    QuickSort(0,Container::size-1);
}

}
