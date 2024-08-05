
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */
template <typename Data>
Vector<Data>::Vector(const TraversableContainer<Data> &struttura) : Vector(struttura.Size()) {
    unsigned long int i = 0;
    struttura.Traverse(
        [this,&i](const Data & dato){
            elementi[i++] = dato;  
        }

    );

}

template <typename Data>
Vector<Data>::Vector (Vector && vet) noexcept{
    std::swap(elementi,vet.elementi);
    std::swap(size,vet.size);
}

template <typename Data>
Vector<Data>::Vector(const Vector<Data> & vet): Vector(vet.size){
    std::copy(vet.elementi, vet.elementi + size , elementi);
      
}

template <typename Data>
Vector<Data>::Vector(MappableContainer<Data> &&struttura ): Vector(struttura.Size()) {
    unsigned long int i = 0;
    struttura.Map(
        [this,&i](Data & dato){
            std::swap(elementi[i++],dato);   
        }

    );

  }


template <typename Data>
bool Vector<Data>::operator==(const Vector & vet) const noexcept {
    if(size != vet.size)
        return false;
    
    for(unsigned long int i = 0; i < size; i++)
        if(elementi[i] != vet[i])
            return false;
    

    return true;
    
}

template <typename Data>
bool inline Vector<Data>::operator!=(const Vector & vet) const noexcept {
    return !(*this == vet);

}

template <typename Data>
void Vector<Data>::Clear(){
    
    delete[] elementi; 
    elementi = nullptr;
    size = 0;
  

}

template <typename Data>
void Vector<Data>::Resize (unsigned long int newSize){
    
    if(newSize == 0){
        Clear();
    }else if (newSize != size){
        
        unsigned long minimo = newSize < size ? newSize : size ;

        Data * newElementi =  new Data[newSize]();

        for(unsigned long int i = 0; i < minimo; i++)
            std::swap(newElementi[i],elementi[i]);

        std::swap(elementi,newElementi);
        size = newSize;
        delete[] newElementi;
    }

    return;
}

template <typename Data>
const Data & Vector<Data>::operator[](unsigned long int indice) const {
    if(indice >= size)
        throw std::out_of_range("Dimensione Troppo Grande!");

    return elementi[indice];
}


template <typename Data>
Data & Vector<Data>::operator[](unsigned long int indice) {
    if(indice >= size)
        throw std::out_of_range("Dimensione Troppo Grande!");

    return elementi[indice];
}


template <typename Data>
inline const Data& Vector<Data>::Front() const{
    if(size == 0)
        throw std::length_error("Non Ci sono elementi!");
    return elementi[0];
}

template <typename Data>
inline Data& Vector<Data>::Front(){
    if(size == 0)
        throw std::length_error("Non Ci sono elementi!");
    return elementi[0];
}

template <typename Data>
inline const Data& Vector<Data>::Back() const{
    if(size == 0)
        throw std::length_error("Non Ci sono elementi!");
    return elementi[size-1];
}

template <typename Data>
inline Data& Vector<Data>::Back(){
    if(size == 0)
        throw std::length_error("Non Ci sono elementi!");
    return elementi[size-1];
}


template <typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector & vet){
    
    Vector<Data> *dep = new Vector(vet);
    std::swap(*dep,*this);
    delete dep;
    
    return (*this);

}

template <typename Data>
Vector<Data>& Vector<Data>::operator=(Vector && vet) noexcept{
    std::swap(elementi,vet.elementi);
    std::swap(size,vet.size);
    
    return (*this);
}

template <typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector & vet){
    Vector<Data>::operator=(vet);
    return (*this);

}


template <typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(SortableVector && vet) noexcept{
    Vector<Data>::operator=(std::move(vet));
    return (*this);
}

template <typename Data>
bool SortableVector<Data>::operator==(const SortableVector & vet) const noexcept{
   return Vector<Data>::operator==(vet);
}

template <typename Data>
bool SortableVector<Data>::operator!=(const SortableVector & vet) const noexcept{
   return Vector<Data>::operator!=(vet);
}


template <typename Data>
inline void Vector<Data>::Stampa() const noexcept{
   
    std::cout<<"\n[Vettore("<<size<<")]";
    for(unsigned long int i = 0; i < size ; i++)
        std::cout<<"->"<<elementi[i];

    std::cout<<"-|\n";
}

};