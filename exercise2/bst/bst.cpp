
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */
template <typename Data>
BST<Data>::BST(const TraversableContainer<Data>& struttura){
    struttura.Traverse(
        [this](const Data& dato){
            Insert(dato);
        }

    );
}

template <typename Data>
BST<Data>::BST(MappableContainer<Data>&& struttura){
    struttura.Map(
        [this](const Data& dato){
            Insert(std::move(dato));
        }

    );
}

template <typename Data>
BST<Data>::BST(const BST<Data>& alb) : BinaryTreeLnk<Data>::BinaryTreeLnk(alb){

}

template <typename Data>
BST<Data>::BST(BST<Data>&& alb) noexcept : BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(alb)){

}

template <typename Data>
BST<Data>& BST<Data>::operator=(const BST& alb ){
    BinaryTreeLnk<Data>::operator=(alb);
    return *this;
}

template <typename Data>
BST<Data>& BST<Data>::operator=(BST&& alb ) noexcept{
    BinaryTreeLnk<Data>::operator=(std::move(alb));
    return *this;
}

template <typename Data>
bool BST<Data>::operator==(const BST& alb ) const noexcept{
    if(size != alb.size)
        return false;

    Vector<Data> vet{size};
    unsigned long int i = 0;
    BinaryTreeLnk<Data>::InOrderTraverse(
        [&vet,&i](const Data& dato){
            vet[i++] = dato;
        }
    );

    bool uguali = true;
    i=0;
    alb.InOrderTraverse(
        [&vet,&i,&uguali](const Data& dato){
            if (vet[i++] != dato)
                uguali = false;
        }
    );

    return uguali;


}
  
template <typename Data>
bool BST<Data>::operator!=(const BST& alb ) const noexcept{
    return !operator==(alb);
}

template <typename Data>
inline const Data& BST<Data>::Min() const{
    if (radice == nullptr)
        throw std::length_error("BST Vuoto!");
    
    return Min(radice)->elemento;
}

template <typename Data>
inline Data BST<Data>::MinNRemove(){
    if (radice == nullptr)
        throw std::length_error("BST Vuoto!");
    

    Data elem = Min();
    Remove(elem);

    return elem;
}

template <typename Data>
inline void BST<Data>::RemoveMin(){
    Remove(Min());
}

template <typename Data>
inline const Data& BST<Data>::Max() const{
    if (radice == nullptr)
        throw std::length_error("BST Vuoto!");
    
    return Max(radice)->elemento;
}

template <typename Data>
inline Data BST<Data>::MaxNRemove(){
    if (radice == nullptr)
        throw std::length_error("BST Vuoto!");

    Data elem = Max();
    Remove(elem);
    return elem;
}

template <typename Data>
inline void BST<Data>::RemoveMax(){
     Remove(Max());
}

template <typename Data>
inline const Data& BST<Data>::Predecessor(const Data& elem) const{
    if (radice == nullptr)
        throw std::length_error("BST Vuoto!");
    
    NodeLnk * tmp = const_cast<BST<Data>*>(this)->Predecessor(radice,elem);
    if(tmp == nullptr)
        throw std::length_error("Predecessore Non Trovato!");

    return tmp->elemento;
}

template <typename Data>
inline BST<Data>::NodeLnk * BST<Data>::Predecessor(NodeLnk * T , const Data& k) const{
    if (T != nullptr) {
        if(T->elemento == k)
            return Max(T->figlioSinistro);
        else if (k < T->elemento)
            return Predecessor(T->figlioSinistro,k);
        else{
            NodeLnk * temp = Predecessor(T->figlioDestro,k);
            if(temp != nullptr)
                return temp;
            else    
                return T;
        }
    }
    return nullptr;
}

template <typename Data>
inline Data BST<Data>::PredecessorNRemove(const Data& k){
    Data elem = Predecessor(k);
    Remove(elem);
    return elem;
}

template <typename Data>
inline void BST<Data>::RemovePredecessor(const Data& k ){
    Remove(Predecessor(k));
}

template <typename Data>
inline const Data& BST<Data>::Successor(const Data& elem) const{
    if (radice == nullptr)
        throw std::length_error("BST Vuoto!");
    
    NodeLnk * tmp = const_cast<BST<Data>*>(this)->Successor(radice,elem);
    if(tmp == nullptr)
        throw std::length_error("Successore Non Trovato!");
    
    return tmp->elemento;
}

template <typename Data>
inline BST<Data>::NodeLnk * BST<Data>::Successor(NodeLnk * T , const Data& k) const{
    if (T != nullptr) {
        if(T->elemento == k){
            return Min(T->figlioDestro);
        }else if (k > T->elemento)
            return Successor(T->figlioDestro,k);
        else{
            NodeLnk * temp = Successor(T->figlioSinistro,k);
            if(temp != nullptr)
                return temp;
            else    
                return T;
        }
    }
    return nullptr;
}

template <typename Data>
inline Data BST<Data>::SuccessorNRemove(const Data& k){
    Data elem = Successor(k);
    Remove(elem);
    return elem;
}

template <typename Data>
inline void BST<Data>::RemoveSuccessor(const Data& k){
    Remove(Successor(k));
}

template <typename Data>
bool BST<Data>::Insert(const Data & k) {
    unsigned long int dim = size;
    radice = Insert(radice,k);
    return dim == (size - 1);
}
  
template <typename Data>
bool BST<Data>::Insert(Data && k) {
    unsigned long int dim = size;
    radice = Insert(radice,std::move(k));
    return dim == (size - 1);
}

template <typename Data>
bool BST<Data>::Remove(const Data & k) {
    unsigned long int dim = size;
    radice = Remove(radice,k);
    return size == (dim - 1);

}

template <typename Data>  
inline void BST<Data>::Traverse(TraverseFun funzione) const {
    BST<Data>::InOrderTraverse(funzione);
}

template <typename Data>
inline bool BST<Data>::Exists(const Data& k) const noexcept{
    return RicercaBST(radice,k) != nullptr;
}

template <typename Data>
BST<Data>::NodeLnk * BST<Data>::Remove(NodeLnk * T ,const Data & k) {
    if(T != nullptr){
        if(k < T->elemento){
            T->figlioSinistro = Remove(T->figlioSinistro,k);
        }else if (k > T->elemento){
            T->figlioDestro = Remove(T->figlioDestro,k);
        }else{
            T = CancellaRadiceBST(T);
            size--;
        }
    }
    return T;
}

template <typename Data>
inline BST<Data>::NodeLnk * BST<Data>::CancellaRadiceBST(NodeLnk * T){
    if (T != nullptr){
        if(T->figlioSinistro == nullptr || T->figlioDestro == nullptr) {
            NodeLnk * tmp = nullptr;

            if(T->figlioDestro != nullptr)
                tmp = T->figlioDestro;
            else
                tmp = T->figlioSinistro;
                
            
            
            T->figlioSinistro = nullptr;
            T->figlioDestro = nullptr;
            delete T;
            return tmp;

        }else{

            NodeLnk * min = StaccaMin(T->figlioDestro,T);
            T->elemento = min->elemento;
            min->figlioDestro = nullptr;
            delete min;
            return T;
            

        }

    }
    return nullptr; 
}

template <typename Data>
BST<Data>::NodeLnk * BST<Data>::StaccaMin(NodeLnk * T, NodeLnk * Padre){
    if(T != nullptr){
        if(T->figlioSinistro != nullptr){
            return StaccaMin(T->figlioSinistro,T);
        }else{
            if (Padre->figlioSinistro == T){
                Padre->figlioSinistro = T->figlioDestro;
            }else{
                Padre->figlioDestro = T->figlioDestro;
            }
            return T;
        }
    }
        
    return nullptr;
}

template <typename Data>
inline BST<Data>::NodeLnk * BST<Data>::Min(NodeLnk * T) const{
    if (T != nullptr){
        if (T->figlioSinistro != nullptr)
            return Min(T->figlioSinistro);
        else   
            return T;
    }
        
    
    return nullptr;


}

template <typename Data>
inline BST<Data>::NodeLnk * BST<Data>::Max(NodeLnk * T) const{
    if (T != nullptr){
        if (T->figlioDestro != nullptr)
            return Max(T->figlioDestro);
        else   
            return T;
    }
        
    
    return nullptr;


}

template <typename Data>
BST<Data>::NodeLnk * BST<Data>::Insert(NodeLnk * T, const Data & k){
    if(T == nullptr){
        size++;
        return new NodeLnk(k);
    }else{
        if(T->elemento == k){
            return T;
        }else if ( k > T->elemento){
            T->figlioDestro = Insert(T->figlioDestro,k);
            return T;
        }else{
            T->figlioSinistro = Insert(T->figlioSinistro,k);
            return T;
        }
    }

}

template <typename Data>
BST<Data>::NodeLnk * BST<Data>::Insert(NodeLnk * T,Data && k){
    if(T == nullptr){
        size++;
        T = new NodeLnk(std::move(k));
        return T;
    }else{
        if(T->elemento == k){
            return T;
        }else if ( k > T->elemento){
            T->figlioDestro = Insert(T->figlioDestro,k);
            return T;
        }else{
            T->figlioSinistro = Insert(T->figlioSinistro,k);
            return T;
        }
    }

}

template <typename Data>
BST<Data>::NodeLnk * BST<Data>::RicercaBST(NodeLnk * T, const Data & k) const{
    if(T != nullptr){
        if(k > T->elemento){
            return RicercaBST(T->figlioDestro,k);
        }else if (k < T->elemento){
            return RicercaBST(T->figlioSinistro,k);
        }else{
            return T;
        }

    }
    return nullptr;




}


}
