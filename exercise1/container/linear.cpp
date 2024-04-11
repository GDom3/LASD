
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

//Ricordati dell'eredità multipla 

template <typename Data>
inline bool LinearContainer<Data>::operator==(const LinearContainer<Data>& elem) const noexcept{
    if(size != elem.size)
        return false;
    
    for(unsigned long i = 0; i < size; i++)
        if(operator[](i) != elem[i])
            return false

    return true;

}

template <typename Data>
inline bool LinearContainer<Data>::operator!=(const LinearContainer<Data>& elem) const noexcept{
    return !(operator==(elem));
}

template <typename Data>
inline const Data& LinearContainer<Data>::Front() const{
    if(size != 0)
        return operator[](0);
    else
        throw std::length_error("Il LinearContainer è Vuoto!");
}

template <typename Data>
inline const Data& LinearContainer<Data>::Back() const{
    if(size != 0)
        return operator[](size-1);
    else
        throw std::length_error("Il LinearContainer è Vuoto!");
}

template <typename Data>
inline Data& LinearContainer<Data>::Front(){
    if(size != 0)
        return operator[](0);
    else
        throw std::length_error("Il LinearContainer è Vuoto!");
}

template <typename Data>
inline Data& LinearContainer<Data>::Back(){
    if(size != 0)
        return operator[](size-1);
    else
        throw std::length_error("Il LinearContainer è Vuoto!");
}

template <typename Data>
inline void LinearContainer<Data>::PreOrderTraverse(TraverseFun funzione) const{
    for(unsigned long int i = 0; i < size; i++)
        funzione(operator[](i));
}

template <typename Data>
inline void LinearContainer<Data>::PostOrderTraverse(TraverseFun funzione) const{
    unsigned long int i = size;
    while(i > 0)
        funzione(operator[](--i));
}

template <typename Data>
inline void LinearContainer<Data>::Map(MapFun funzione){
    PreOrderMap(funzione);
}

template <typename Data>
inline void LinearContainer<Data>::Traverse(TraverseFun funzione) const{
    PreOrderTraverse(funzione);
}

template <typename Data>
inline void LinearContainer<Data>::PreOrderMap(MapFun funzione) {
    for(unsigned long int i = 0; i < size; i++)
        funzione(operator[](i));
}

template <typename Data>
inline void LinearContainer<Data>::PostOrderMap(MapFun funzione){
    unsigned long int i = size;
    while(i > 0)
        funzione(operator[](--i));
}


template <typename Data>
inline bool SortableLinearContainer<Data>::operator==(const SortableLinearContainer<Data>& elem) const noexcept{
    if(size != elem.size)
        return false;
    
    for(unsigned long i = 0; i < size; i++)
        if(operator[](i) != elem[i])
            return false

    return true;

}

template <typename Data>
inline bool SortableLinearContainer<Data>::operator!=(const SortableLinearContainer<Data>& elem) const noexcept{
    return !(operator==(elem));
}

void SortableLinearContainer<Data>::Sort() noexcept{
    QuickSort(0,size-1);
}

void SortableLinearContainer<Data>::QuickSort(unsigned long int p, unsigned long int r) noexcept{
    if (p < r) {
        unsigned long int q = Partition(p, r);
        QuickSort(p, q);
        QuickSort(q + 1, r);
  }
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


}
