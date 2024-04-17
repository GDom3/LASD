
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */
template <typename Data>
Vector<Data>::Vector(const TraversableContainer<Data> &struttura ){
    LinearContainer<Data>::size = struttura.size;
    elementi = new Data[LinearContainer<Data>::size];
    unsigned long int i = 0;
    struttura.Traverse(
      [this,&i](const Data & dato){
          elementi[i++] = dato;
      }

    );

  }

template <typename Data>
Vector<Data>::Vector (Vector && vet){
    elementi = std::move(vet.elementi);
    size = std::move(vet.size);
}

template <typename Data>
Vector<Data>::Vector(const Vector & vet){
    LinearContainer<Data>::size = vet.size;
    elementi = new Data[LinearContainer<Data>::size];

    for (unsigned long int i = 0; i < vet.size; i++)
        elementi[i] = vet[i];
      
  }

template <typename Data>
Vector<Data>::Vector(MappableContainer<Data> &struttura ){
    LinearContainer<Data>::size = struttura.size;
    elementi = new Data[LinearContainer<Data>::size];
    unsigned long int i = 0;
    struttura.Traverse(
      [this,&i](const Data & dato){
            elementi[i++] = dato;
      }

    );

  }


template <typename Data>
bool Vector<Data>::operator==(const Vector & vet) const noexcept {
    if(elementi == nullptr || LinearContainer<Data>::size != vet.size)
        return false;
    
    for(unsigned long int i = 0; i < LinearContainer<Data>::size; i++)
        if(elementi[i] != vet[i])
            return false;
    

    return true;
    
}

template <typename Data>
bool inline Vector<Data>::operator!=(const Vector & vet) const noexcept {
    return !(operator==(vet));

}

template <typename Data>
void Vector<Data>::Clear(){
    if(elementi != nullptr){
        delete[] elementi; 
        elementi = nullptr;
        LinearContainer<Data>::size = 0;
   }else
        throw std::logic_error("Vettore già Vuoto!");

}

template <typename Data>
void Vector<Data>::Resize (const unsigned long  &newSize){
    if(newSize == 0)
        throw std::length_error("Non Puoi fare la Resize a Zero, Usa Clear per questo!");
    else if(newSize <= LinearContainer<Data>::size)
        throw std::length_error("Dimensione Troppo Piccola!");

    Data * newElementi = new Data[newSize];

    if(elementi != nullptr){
        for (unsigned int i = 0; i < LinearContainer<Data>::size; i++)
            newElementi[i] = elementi[i];

        delete[] elementi;
    }

    elementi = newElementi;

}




template <typename Data>
inline const Data& Vector<Data>::Front() const{
    if(elementi == nullptr)
        throw std::out_of_range("Non Ci sono elementi!");
    return elementi[0];
}

template <typename Data>
inline Data& Vector<Data>::Front(){
    if(elementi == nullptr)
        throw std::out_of_range("Non Ci sono elementi!");
    return elementi[0];
}

template <typename Data>
inline const Data& Vector<Data>::Back() const{
    if(elementi == nullptr)
        throw std::out_of_range("Non Ci sono elementi!");
    return elementi[LinearContainer<Data>::size-1];
}

template <typename Data>
inline Data& Vector<Data>::Back(){
    if(elementi == nullptr)
        throw std::out_of_range("Non Ci sono elementi!");
    return elementi[LinearContainer<Data>::size-1];
}


template <typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector & vet){
    
    if(elementi != nullptr)
        delete[] elementi;


    LinearContainer<Data>::size = vet.size;
    elementi = new Data[LinearContainer<Data>::size];

    for (unsigned long int i = 0; i < vet.size; i++)
        elementi[i] = vet[i];
    
    
    return (*this);

}

template <typename Data>
Vector<Data>& Vector<Data>::operator=(Vector && vet){
    if(elementi != nullptr)
        delete[] elementi;

    elementi = std::move(vet.elementi);
    size = std::move(vet.size);

    
    return (*this);
}

template <typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector & vet){
    if(elementi != nullptr)
        delete[] elementi;


    LinearContainer<Data>::size = vet.size;
    elementi = new Data[LinearContainer<Data>::size];

    for (unsigned long int i = 0; i < vet.size; i++)
        elementi[i] = vet[i];
    
    
    return (*this);

}



template <typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(SortableVector && vet){
    if(elementi != nullptr)
        delete[] elementi;

    elementi = std::move(vet.elementi);
    size = std::move(vet.size);

    
    return (*this);
}

template <typename Data>
SortableVector<Data>::SortableVector(MappableContainer<Data> &struttura ){
    LinearContainer<Data>::size = struttura.size;
    elementi = new Data[LinearContainer<Data>::size];
    unsigned long int i = 0;
    struttura.Traverse(
      [this,&i](const Data & dato){
            elementi[i++] = dato;
      }

    );

  }

template <typename Data>
const Data & Vector<Data>::operator[](const unsigned long int indice) const {
    if(indice >= LinearContainer<Data>::size)
        throw std::out_of_range("Dimensione Troppo Grande!");

    return elementi[indice];
}


template <typename Data>
Data & Vector<Data>::operator[](unsigned long int indice) {
    if(indice >= LinearContainer<Data>::size)
        throw std::out_of_range("Dimensione Troppo Grande!");

    return elementi[indice];
}


template <typename Data>
SortableVector<Data>::SortableVector(SortableVector && vet){
    elementi = std::move(vet.elementi);
    size = std::move(vet.size);
  }

template <typename Data>
SortableVector<Data>::SortableVector(const SortableVector & vet){
    LinearContainer<Data>::size = vet.size;
    elementi = new Data[LinearContainer<Data>::size];

    for (unsigned long int i = 0; i < vet.size; i++)
        elementi[i] = vet[i];
  }

template <typename Data>
SortableVector<Data>::SortableVector(const TraversableContainer<Data> &struttura ){
    LinearContainer<Data>::size = struttura.size;
    elementi = new Data[LinearContainer<Data>::size];
    unsigned long int i = 0;
    struttura.Traverse(
      [this,&i](const Data & dato){
          elementi[i++] = dato;
      }

    );

  }

template <typename Data>
inline void SortableVector<Data>::PreOrderTraverse(TraverseFun funzione) const{
    Vector<Data>::PreOrderTraverse(funzione);
}

template <typename Data>
inline void SortableVector<Data>::PostOrderTraverse(TraverseFun funzione) const{
    Vector<Data>::PostOrderTraverse(funzione);
}

template <typename Data>
inline void SortableVector<Data>::Map(MapFun funzione){
    Vector<Data>::PreOrderMap(funzione);
}

template <typename Data>
inline void SortableVector<Data>::Traverse(TraverseFun funzione) const noexcept{
    Vector<Data>::PreOrderTraverse(funzione);
}

template <typename Data>
inline void SortableVector<Data>::PreOrderMap(MapFun funzione) {
    Vector<Data>::PreOrderMap(funzione);
}

template <typename Data>
inline void SortableVector<Data>::PostOrderMap(MapFun funzione){
    Vector<Data>::PostOrderMap(funzione);
}



}
