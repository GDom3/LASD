
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
inline Data& LinearContainer<Data>::Front() const{
    if(size != 0)
        return operator[](0);
    else
        throw std::length_error("Il LinearContainer è Vuoto!");
}

template <typename Data>
inline Data& LinearContainer<Data>::Back() const{
    if(size != 0)
        return operator[](size-1);
    else
        throw std::length_error("Il LinearContainer è Vuoto!");
}


}
