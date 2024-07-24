
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
List<Data>::List(const TraversableContainer<Data> &struttura ){

    struttura.Traverse(
        [this](const Data & dato){
            List<Data>::InsertAtBack(dato);
        }

    );

  }
template <typename Data>
List<Data>::List(MappableContainer<Data> &&struttura ){
 
    struttura.Map(
        [this](Data & dato){
            List<Data>::InsertAtBack(std::move(dato));
        }

    );

  }


template <typename Data>
List<Data>::List(const List<Data> & list){
    

    
    Node * temp = list.head;

    while(temp != nullptr){
        List<Data>::InsertAtBack(temp->elemento);
        temp = temp->next;
    }
    
  }


template <typename Data>
List<Data>::List (List && list){
    
    std::swap(size,list.size);
    std::swap(head,list.head);
    std::swap(tail,list.tail);


}

template <typename Data>
List<Data>::~List(){
   
    delete head;  
            
}

template <typename Data>
bool List<Data>::operator==(const List & list) const noexcept{
    
    if(list.size != size)
        return false;

    Node * tempThis = head;
    Node * tempList = list.head;

    while(tempThis != nullptr){
        if(tempThis->elemento != tempList->elemento)
            return false;
        
        tempThis = tempThis->next;
        tempList = tempList->next;
    }   


    return true;

}

template <typename Data>
bool List<Data>::operator!=(const List & list) const noexcept{
    return !operator==(list);

}


template <typename Data>
void List<Data>::InsertAtFront(const Data& dato){
    
    Node * nuovoNodo = new Node(dato);
    
    nuovoNodo->next = head;
    head = nuovoNodo;
    
    if(tail == nullptr)
        tail = head;
    
    size++;
}

template <typename Data>
void List<Data>::InsertAtFront(Data&& dato){

    Node * nuovoNodo = new Node(std::move(dato));
    
    nuovoNodo->next = head;
    head = nuovoNodo;
    
    if(tail == nullptr)
        tail = head;
    
    size++;
}


template <typename Data>
void List<Data>::RemoveFromFront(){
    if(size == 0)
        throw std::length_error("Lista Vuota!");
    
    Node * daEliminare = head;
    if(tail == head)
        tail = head = nullptr;
    else
        head = head->next;

    daEliminare->next = nullptr;
    delete daEliminare;
    size--;

    
}

template <typename Data>
Data List<Data>::FrontNRemove(){
    if(size == 0)
        throw std::length_error("Lista Vuota!");
        
    Data elem = head->elemento;
    RemoveFromFront();

    return elem;

}

template <typename Data>
void List<Data>::InsertAtBack(const Data& dato){
    
    Node * nuovoNodo = new Node(dato);

    if(size == 0)
        head = nuovoNodo; 
    else 
        tail->next = nuovoNodo;
       
    
    tail = nuovoNodo;
    size++;


}

template <typename Data>
void List<Data>::InsertAtBack(Data&& dato){
    Node * nuovoNodo = new Node(std::move(dato));

    if(size == 0)
        head = nuovoNodo; 
    else 
        tail->next = nuovoNodo;
       
    
    tail = nuovoNodo;
    size++;
}

template <typename Data>
void List<Data>::Clear() {
    
    delete head;
    head = nullptr;
    tail = nullptr;
    size = 0;

}

template <typename Data>
List<Data>& List<Data>::operator=(const List & list){
    
    List<Data> * dep = new List<Data>(list);
    std::swap(*this,*dep);
    delete dep;

    return (*this);

}


template <typename Data>
List<Data>& List<Data>::operator=(List && list) noexcept{
   
    std::swap(size,list.size);
    std::swap(head,list.head);
    std::swap(tail,list.tail);

    return (*this);

}

template <typename Data>
bool List<Data>::Insert(const Data & dato) {
    
    if(Exists(dato))
        return false;

    InsertAtBack(dato);
 
    return true;


}

template <typename Data>
bool List<Data>::Insert(Data && dato) {
    
    if(Exists(dato))
        return false;

    InsertAtBack(std::move(dato) );
    
    return true;


}

template <typename Data>
bool List<Data>::Remove(const Data & dato) {
    if(size == 0)
        return false;
    if(head->elemento == dato){
        RemoveFromFront();
        return true;
    }


    Node * nodoDato = head->next;
    Node * precedente = head;

    while (nodoDato != nullptr){
        if(nodoDato->elemento == dato){
            precedente->next = nodoDato->next;

            if(nodoDato->next == nullptr)
                tail = precedente;
            

            nodoDato->next = nullptr;
            delete nodoDato;
            size--;

            return true;
        }

        precedente = nodoDato;
        nodoDato = nodoDato->next;

    }
    
    return false; //se il dato non c'è

}



template <typename Data>
const Data & List<Data>::operator[](const unsigned long int indice) const{
    if(indice >= size)
        throw std::out_of_range("Dimensione Eccessiva!");


    Node * temp = head;


    for(unsigned long int i = 0; i < indice; i++)
        temp = temp->next;
    
    return temp->elemento;


}

template <typename Data>
Data & List<Data>::operator[](unsigned long int indice){
    if(indice >= size)
        throw std::out_of_range("Dimensione Eccessiva!");


    Node * temp = head;

    for(unsigned long int i = 0; i < indice; i++)
        temp = temp->next;


    return temp->elemento;


}


template <typename Data>
inline const Data& List<Data>::Front() const{
    if(size == 0)
        throw std::length_error("Non Ci sono elementi!");
    return head->elemento;
}

template <typename Data>
inline Data& List<Data>::Front(){
    if(size == 0)
        throw std::length_error("Non Ci sono elementi!");
    return head->elemento;
}

template <typename Data>
inline const Data& List<Data>::Back() const{
    if(size == 0)
        throw std::length_error("Non Ci sono elementi!");
    return tail->elemento;
}

template <typename Data>
inline Data& List<Data>::Back() {
    if(size == 0)
        throw std::length_error("Non Ci sono elementi!");
    return tail->elemento;
}



template <typename Data>
inline void List<Data>::PreOrderTraverse(TraverseFun funzione)  const {
    PreOrderTraverse(funzione,head);
}

template <typename Data>
inline void List<Data>::PostOrderTraverse(TraverseFun funzione)  const {
    PostOrderTraverse(funzione,head);
}

template <typename Data>
inline void List<Data>::Traverse(TraverseFun funzione) const {
    PreOrderTraverse(funzione, head);
}

template <typename Data>
inline void List<Data>::Map(MapFun funzione) {
    PreOrderMap(funzione);
}

template <typename Data>
inline void List<Data>::PreOrderMap(MapFun funzione) {
    PreOrderMap(funzione,head);
}

template <typename Data>
inline void List<Data>::PostOrderMap(MapFun funzione) {
    PostOrderMap(funzione,head);
}

template <typename Data>
inline void List<Data>::PreOrderTraverse(TraverseFun funzione, Node * temp) const {
    while(temp != nullptr){
        funzione(temp->elemento);
        temp = temp->next;
    }
}

template <typename Data>
inline void List<Data>::PostOrderTraverse(TraverseFun funzione, Node * temp) const  {
    if(temp != nullptr){
        PostOrderTraverse(funzione,temp->next);
        funzione(temp->elemento);           
    }
}

template <typename Data>
inline void List<Data>::PreOrderMap(MapFun funzione, Node * temp) {
    while(temp != nullptr){
        funzione(temp->elemento);
        temp = temp->next;
    }
}

template <typename Data>
inline void List<Data>::PostOrderMap(MapFun funzione, Node * temp) {
    if(temp != nullptr){
        PostOrderMap(funzione,temp->next);
        funzione(temp->elemento);           
    }
}

template <typename Data>
inline void List<Data>::Stampa() const noexcept{
    Node * temp = head;
    std::cout<<"\n[Lista("<<size<<")]";
    while(temp!=nullptr){
        std::cout<<"->"<<temp->elemento;
        temp = temp->next;
    }
    std::cout<<"-|\n";
}

}

