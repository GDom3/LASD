
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */
template <typename Data>
bool Vector<Data>::operator==(const Vector & vet) const noexcept {
    if(elementi == nullptr || Container::size != vet.size)
        return false;
    
    for(unsigned long int i = 0; i < Container::size; i++)
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
        Contener::size = 0;
   }else
        throw logic_error("Vettore già Vuoto!");

}

template <typename Data>
void Vector<Data>::Resize (const unsigned long  &newSize){
    if(newSize == 0)
        throw length_error("Non Puoi fare la Resize a Zero, Usa Clear per questo!");
    else if(newSize <= Container::size)
        throw length_error("Dimensione Troppo Piccola!");

    Data * newElementi = new Data[newSize];

    if(elementi != nullptr){
        for (unsigned int i = 0; i < Container::size; i++)
            newElementi[i] = elementi[i];

        delete[] elementi;
    }

    elementi = newElementi;

}

template <typename Data>
Data & Vector<Data>::operator[](const unsigned long int indice) const {
    if(indice >= Container::size)
        throw out_of_range("Dimensione Troppo Grande!");

    return elementi[indice];
}


template <typename Data>
Data & Vector<Data>::operator[](unsigned long int indice) {
    if(indice >= Container::size)
        throw out_of_range("Dimensione Troppo Grande!");

    return elementi[indice];
}


template <typename Data>
inline const Data& Vector<Data>::Front() const{
    if(elementi == nullptr)
        throw out_of_range("Non Ci sono elementi!");
    return elementi[0];
}

template <typename Data>
inline const Data& Vector<Data>::Front(){
    if(elementi == nullptr)
        throw out_of_range("Non Ci sono elementi!");
    return elementi[0];
}

template <typename Data>
inline const Data& Vector<Data>::Back() const{
    if(elementi == nullptr)
        throw out_of_range("Non Ci sono elementi!");
    return elementi[Container::size-1];
}

template <typename Data>
inline const Data& Vector<Data>::Back(){
    if(elementi == nullptr)
        throw out_of_range("Non Ci sono elementi!");
    return elementi[Container::size-1];
}


template <typename Data>
Vector& Vector<Data>::operator=(const Vector & vet){
    Vector nuovoVet = new Vector(vet);
    
    if(elemnti != nullptr)
        delete[] elementi;
    
    return nuovoVet;

}

template <typename Data>
Vector& Vector<Data>::operator=(Vector && vet){
    Vector nuovoVet = new Vector(vet);
    
    if(elemnti != nullptr)
        delete[] elementi;
    
    return nuovoVet;
}

template <typename Data>
SortableVector& SortableVector<Data>::operator=(const SortableVector & vet){
    SortableVector nuovoVet = new SortableVector(vet);
    
    if(elemnti != nullptr)
        delete[] elementi;
    
    return nuovoVet;

}

template <typename Data>
SortableVector& SortableVector<Data>::operator=(SortableVector && vet){
    SortableVector nuovoVet = new SortableVector(vet);
    
    if(elemnti != nullptr)
        delete[] elementi;
    
    return nuovoVet;
}


}
