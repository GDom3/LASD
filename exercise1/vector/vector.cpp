
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
Vector<Data>::Vector(const unsigned long & num ) noexcept{
    if(num != 0){
      elementi = new Data[num];
      size = num;
    }

  }

template <typename Data>
Vector<Data>::Vector(const TraversableContainer<Data> &struttura) noexcept{
    size = struttura.Size();
    elementi = new Data[size]{};
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
Vector<Data>::Vector(const Vector & vet){
    size = vet.size;
    elementi = new Data[size]{};

    for (unsigned long int i = 0; i < vet.size; i++)
        elementi[i] = vet.elementi[i];
      
  }

template <typename Data>
Vector<Data>::Vector(MappableContainer<Data> &&struttura )noexcept{
    size = struttura.Size();
    elementi = new Data[size]{};
    unsigned long int i = 0;
    struttura.Map(
      [this,&i](Data & dato){
            elementi[i++] = std::move(dato);
         
      }

    );

  }


template <typename Data>
bool Vector<Data>::operator==(const Vector & vet) const noexcept {
    if(elementi == nullptr || size != vet.size)
        return false;
    
    for(unsigned long int i = 0; i < size; i++)
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
    
    delete[] elementi; 
    elementi = nullptr;
    size = 0;
  

}

template <typename Data>
void Vector<Data>::Resize (const unsigned long  &newSize){
    
    if(newSize == 0)
        Clear();
    else if(newSize != size){ 
        Data * newElementi =  new Data[newSize]{};

        unsigned long int dep;
        if(size < newSize)
            dep = size;
        else
            dep = newSize;
        
        
        for(unsigned long int i = 0; i < dep ; i++)
            std::swap(newElementi[i],elementi[i]);
         
        std::swap(elementi,newElementi);
        size = newSize;
        
        delete[] newElementi;
    }
     

}

template <typename Data>
const Data & Vector<Data>::operator[](const unsigned long int indice) const {
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
    if(elementi == nullptr)
        throw std::length_error("Non Ci sono elementi!");
    return elementi[0];
}

template <typename Data>
inline Data& Vector<Data>::Front(){
    if(elementi == nullptr)
        throw std::length_error("Non Ci sono elementi!");
    return elementi[0];
}

template <typename Data>
inline const Data& Vector<Data>::Back() const{
    if(elementi == nullptr)
        throw std::length_error("Non Ci sono elementi!");
    return elementi[size-1];
}

template <typename Data>
inline Data& Vector<Data>::Back(){
    if(elementi == nullptr)
        throw std::length_error("Non Ci sono elementi!");
    return elementi[size-1];
}


template <typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector & vet){
    
    if(elementi != nullptr)
        delete[] elementi;


    size = vet.size;
    elementi = new Data[size]{};

    for (unsigned long int i = 0; i < vet.size; i++)
        elementi[i] = vet[i];
    
    
    return (*this);

}

template <typename Data>
Vector<Data>& Vector<Data>::operator=(Vector && vet){

    std::swap(elementi,vet.elementi);
    std::swap(size,vet.size);

    
    return (*this);
}

template <typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector & vet){
    if(elementi != nullptr)
        delete[] elementi;


    size = vet.size;
    elementi = new Data[size]{};

    for (unsigned long int i = 0; i < vet.size; i++)
        elementi[i] = vet.elementi[i];
    
    
    return (*this);

}



template <typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(SortableVector && vet){

    std::swap(elementi,vet.elementi);
    std::swap(size,vet.size);

    
    return (*this);
}

template <typename Data>
SortableVector<Data>::SortableVector(MappableContainer<Data> &&struttura){
    size = struttura.Size();
    elementi = new Data[size]{};
    unsigned long int i = 0;
    struttura.Map(
      [this,&i]( Data & dato){
            elementi[i++] = std::move(dato);
      }

    );

  }

template <typename Data>
SortableVector<Data>::SortableVector(SortableVector && vet) noexcept{
    std::swap(elementi,vet.elementi);
    std::swap(size,vet.size);
  }

template <typename Data>
SortableVector<Data>::SortableVector(const SortableVector & vet){
    size = vet.size;
    elementi = new Data[size]{};

    for (unsigned long int i = 0; i < vet.size; i++)
        elementi[i] = vet[i];
  }

template <typename Data>
SortableVector<Data>::SortableVector(const TraversableContainer<Data> &struttura ){
    size = struttura.Size();
    elementi = new Data[size]{};
    unsigned long int i = 0;
    struttura.Traverse(
      [this,&i](const Data & dato){
            elementi[i++] = dato;
            
      }

    );

  }

template <typename Data>
inline void SortableVector<Data>::PreOrderTraverse(TraverseFun funzione) const noexcept{
    Vector<Data>::PreOrderTraverse(funzione);
}

template <typename Data>
inline void SortableVector<Data>::PostOrderTraverse(TraverseFun funzione) const noexcept{
    Vector<Data>::PostOrderTraverse(funzione);
}

template <typename Data>
inline void SortableVector<Data>::Map(MapFun funzione) noexcept{
    Vector<Data>::PreOrderMap(funzione);
}

template <typename Data>
inline void SortableVector<Data>::Traverse(TraverseFun funzione) const noexcept{
    Vector<Data>::PreOrderTraverse(funzione);
}

template <typename Data>
inline void SortableVector<Data>::PreOrderMap(MapFun funzione) noexcept {
    Vector<Data>::PreOrderMap(funzione);
}

template <typename Data>
inline void SortableVector<Data>::PostOrderMap(MapFun funzione) noexcept{
    Vector<Data>::PostOrderMap(funzione);
}


template <typename Data>
const Data & SortableVector<Data>::operator[](const unsigned long int indice) const {
    return Vector<Data>::operator[](indice);
}


template <typename Data>
Data & SortableVector<Data>::operator[](unsigned long int indice) {
    return Vector<Data>::operator[](indice);
}
template <typename Data>
bool SortableVector<Data>::operator==(const SortableVector & v) const noexcept{
    return Vector<Data>::operator==(v);
}

template <typename Data> 
bool inline SortableVector<Data>::operator!=(const SortableVector & v) const noexcept{
    return Vector<Data>::operator!=(v);
}
template <typename Data>
inline void Vector<Data>::Stampa() const noexcept{
   
    std::cout<<"\n[Vettore("<<size<<")]";
    for(unsigned long int i = 0; i < size ; i++)
        std::cout<<"->"<<elementi[i];

    std::cout<<"-|\n";
}

}
