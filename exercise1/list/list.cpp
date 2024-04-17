
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
List<Data>::List(const TraversableContainer<Data> &struttura ){
    LinearContainer<Data>::size = struttura.Size();

    
    struttura.Traverse(
        [this](const Data & dato){
            List<Data>::InsertAtBack(dato);
        }

    );

  }
template <typename Data>
List<Data>::List(MappableContainer<Data> &struttura ){
    LinearContainer<Data>::size = struttura.Size();

    
    struttura.Traverse(
        [this](const Data & dato){
            List<Data>::InsertAtBack(dato);
        }

    );

  }


template <typename Data>
List<Data>::List(const List & list){
    LinearContainer<Data>::size = list.size;
    
    for(Node * temp = list.head; temp != nullptr ; temp = temp->next)
        List<Data>::InsertAtBack(temp->elemento);
    
      
  }


template <typename Data>
List<Data>::List (List && list){
  
    size = std::move(list.size);
    head = std::move(list.head);
    tail = std::move(list.tail);

}

template <typename Data>
List<Data>::~List(){
    Node * temp = nullptr;
    while(head != nullptr){
        temp = head->next;
        delete head;
        head = temp;
    }
        
            
}

template <typename Data>
bool List<Data>::operator==(const List & list) const noexcept{
    if(list.size != size)
        return false;


    for(Node * tempThis = head, *tempList = list.head; tempThis != nullptr; tempThis = tempThis->next, tempList = tempList->next)
        if(tempThis->elemento != tempList->elemento)
            return false;

    return true;

}

template <typename Data>
bool List<Data>::operator!=(const List & list) const noexcept{
    return !operator==(list);

}


template <typename Data>
void List<Data>::InsertAtFront(const Data& dato){
    Node * nuovoNodo = new Node(dato);

    if(head == nullptr){
        head = nuovoNodo;
        tail = head;
    }else{
        nuovoNodo->next = head;
        head = nuovoNodo;
    }


}

template <typename Data>
void List<Data>::InsertAtFront(Data&& dato){
    Node * nuovoNodo = new Node(dato);

    if(head == nullptr){
        head = nuovoNodo;
        tail = head;
    }else{
        nuovoNodo->next = head;
        head = nuovoNodo;
    }


}


template <typename Data>
void List<Data>::RemoveFromFront(){
    if(head == nullptr)
        throw std::length_error("Lista Vuota!");
        
    Node * temp = head;
    head = head->next;

    delete temp;

}

template <typename Data>
Data List<Data>::FrontNRemove(){
    if(head == nullptr)
        throw std::length_error("Lista Vuota!");
        
    Node * temp = head;
    head = head->next;
    Data elem = temp->elemento;

    delete temp;

    return elem;

}

template <typename Data>
void List<Data>::InsertAtBack(const Data& dato){
    if(tail == nullptr){
        head = new Node(dato);
        tail = head;
    }else{
        tail->next = new Node(dato);
        tail = tail->next;

    }


}

template <typename Data>
void List<Data>::InsertAtBack(Data&& dato){
    if(tail == nullptr){
        head = new Node(dato);
        tail = head;
    }else{
        tail->next = new Node(dato);
        tail = tail->next;

    }


}

template <typename Data>
void List<Data>::Clear() {
    
    while(head != nullptr){
       Node * temp = head->next;
       delete head;
       head = temp;

    }
    
    tail = nullptr;
    size = 0;    

}

template <typename Data>
List<Data>& List<Data>::operator=(const List & list){
    Clear();

    Node * temp = list.head;

    while(temp != nullptr)
        InsertAtBack(temp->elemento);

    
    return (*this);

}


template <typename Data>
List<Data>& List<Data>::operator=(List && list){
    size = std::move(list.size);
    head = std::move(list.head);
    tail = std::move(list.tail);

    return (*this);

}

template <typename Data>
bool List<Data>::Insert(const Data & dato){
    if(Exists(dato))
        return false;

    InsertAtBack(dato);

    return true;


}

template <typename Data>
bool List<Data>::Insert(Data && dato){
    if(Exists(dato))
        return false;

    InsertAtBack(dato);

    return true;


}

template <typename Data>
bool List<Data>::Remove(const Data & dato){
    Node * temp = head;
    Node * precendente = head;

    while(temp != nullptr){
        if(temp->elemento == dato){
            precendente->next = temp->next;
            delete temp;
            return true;
        }
        precendente = head;
    }

    return false;

}

template <typename Data>
const Data & List<Data>::operator[](const unsigned long int indice) const{
    if(indice >= size)
        throw std::out_of_range("Dimensione Eccessiva!");


    Node * temp = head;

    for(unsigned long int i = 0; i < indice; i++,temp = temp->next);

    return temp->elemento;


}

template <typename Data>
Data & List<Data>::operator[](unsigned long int indice){
    if(indice >= size)
        throw std::out_of_range("Dimensione Eccessiva!");


    Node * temp = head;

    for(unsigned long int i = 0; i < indice; i++,temp = temp->next);

    return temp->elemento;


}


template <typename Data>
inline const Data& List<Data>::Front() const{
    if(head == nullptr)
        throw std::out_of_range("Non Ci sono elementi!");
    return head->elemento;
}

template <typename Data>
inline Data& List<Data>::Front(){
    if(head == nullptr)
        throw std::out_of_range("Non Ci sono elementi!");
    return head->elemento;
}

template <typename Data>
inline const Data& List<Data>::Back() const{
    if(head == nullptr)
        throw std::out_of_range("Non Ci sono elementi!");
    return tail->elemento;
}

template <typename Data>
inline Data& List<Data>::Back(){
    if(head == nullptr)
        throw std::out_of_range("Non Ci sono elementi!");
    return tail->elemento;
}

template <typename Data>
inline void List<Data>::PreOrderTraverse(TraverseFun funzione) const{
    LinearContainer<Data>::PreOrderTraverse(funzione);
}

template <typename Data>
inline void List<Data>::PostOrderTraverse(TraverseFun funzione) const{
    LinearContainer<Data>::PostOrderTraverse(funzione);
}

template <typename Data>
inline void List<Data>::Map(MapFun funzione){
    LinearContainer<Data>::PreOrderMap(funzione);
}

template <typename Data>
inline void List<Data>::Traverse(TraverseFun funzione) const noexcept{
    LinearContainer<Data>::PreOrderTraverse(funzione);
}

template <typename Data>
inline void List<Data>::PreOrderMap(MapFun funzione) {
    LinearContainer<Data>::PreOrderMap(funzione);
}

template <typename Data>
inline void List<Data>::PostOrderMap(MapFun funzione){
    LinearContainer<Data>::PostOrderMap(funzione);
}

/*
template <typename Data>
inline bool List<Data>::Exists(const Data& dato) const noexcept {
    return TraversableContainer<Data>::Exists(dato);
}
*/

}
