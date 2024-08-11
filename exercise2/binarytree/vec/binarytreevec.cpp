
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>  
inline BinaryTreeVec<Data>::NodeVec::NodeVec (const Data& elem, NodeVec * left, NodeVec * right, unsigned long int i){
    elemento = elem;
    indice = i;
    figlioSinistro = left;
    figlioDestro = right;
}

template <typename Data>  
inline BinaryTreeVec<Data>::NodeVec::NodeVec(Data&& elem,  NodeVec * left, NodeVec * right, unsigned long int i){
    std::swap(elemento,elem);
    figlioSinistro = left;
    figlioDestro = right;
    indice = i;
}

template <typename Data>  
inline BinaryTreeVec<Data>::NodeVec::NodeVec(const NodeVec& nodo): NodeVec(nodo.elemento,nodo.figlioSinistro,nodo.figlioDestro,nodo.indice){
   
}


template <typename Data>    
inline BinaryTreeVec<Data>::NodeVec::NodeVec(NodeVec&& nodo): NodeVec(std::move(nodo.elemento),nodo.figlioSinistro,nodo.figlioDestro,nodo.indice){

    
}

template <typename Data>  
bool BinaryTreeVec<Data>::NodeVec::operator== (const NodeVec& nodo) const noexcept{
    return MutableBinaryTree<Data>::MutableNode::operator==(nodo);
}
    
template <typename Data> 
inline bool BinaryTreeVec<Data>::NodeVec::operator!= (const NodeVec& nodo) const noexcept{
    return !operator==(nodo);

}

template <typename Data> 
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
    return elemento;
}

template <typename Data> 
inline bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    return figlioSinistro != nullptr;

}

template <typename Data> 
inline bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    return figlioDestro != nullptr;
}

template <typename Data> 
inline const BinaryTreeVec<Data>::Node& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    if(!HasLeftChild())
        throw std::out_of_range("Non c'è Figlio Sinistro");
    return *figlioSinistro;
}

template <typename Data> 
inline const BinaryTreeVec<Data>::Node& BinaryTreeVec<Data>::NodeVec::RightChild() const {
    if(!HasRightChild())
        throw std::out_of_range("Non c'è Figlio Destro");
    return *figlioDestro;

}

template <typename Data> 
inline Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept {
    return elemento;

}

template <typename Data> 
inline BinaryTreeVec<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::LeftChild() {
    if(!HasLeftChild())
        throw std::out_of_range("Non c'è Figlio Sinistro");
    return *figlioSinistro;

}

template <typename Data> 
inline BinaryTreeVec<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::RightChild() {
    if(!HasRightChild())
        throw std::out_of_range("Non c'è Figlio Destro");
    return *figlioDestro;

}

template <typename Data> 
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data>& struttura){
    
    vettore.Resize(struttura.Size());
    size = vettore.Size();

    unsigned long int i = 0;
    struttura.Traverse(
        [&i,this](const Data & dato){
            vettore[i] = new NodeVec(dato,nullptr,nullptr,i);
            i++;
        }
    );
    
    for(unsigned long int i = 0, left = 1, right = 2; i < size/2 ; i++, left = (2*i)+1, right = 2*(i+1)+2 ){
        if(left < size)
            vettore[i]->figlioSinistro = vettore[left];
        if(right < size)
            vettore[i]->figlioDestro = vettore[right];
    }
    
}

template <typename Data> 
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data>&& struttura){
    vettore.Resize(struttura.Size());
    size = vettore.Size();

    unsigned long int i = 0;
    struttura.Traverse(
        [&i,this](Data && dato){
            vettore[i++] = new NodeVec(std::move(dato),nullptr,nullptr,i);
        }
    );

    for(unsigned long int i = 0; i < size/2 ; i++){
        vettore[i]->figlioSinistro = vettore[2*(i+1)];
        vettore[i]->figlioDestro = vettore[2*(i+1)+1];
    }
}

template <typename Data> 
inline BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec& alb){
    vettore.Resize(alb.size);
    size = alb.size;
    
    for(unsigned long int i = 0; i < size; i++){
        vettore[i] = new NodeVec(*alb.vettore[i]);
    }
}

template <typename Data> 
inline BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec&& alb) noexcept{
    std::swap(vettore,alb.vettore);
    std::swap(size,alb.size);

}
template <typename Data> 
inline BinaryTreeVec<Data>::~BinaryTreeVec(){
    for(unsigned long int i = 0; i < size ; i++)
        delete vettore[i];
    


}

template <typename Data> 
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& alb){
    Clear();

    size = alb.size;
    vettore.Resize(size);

    for(unsigned long int i = 0; i < size; i++)
        vettore[i] = new NodeVec(alb.vettore[i]->elemento,alb.vettore[i]->figlioSinistro,alb.vettore[i]->figlioDestro,i);
    
    return *this;
}


template <typename Data> 
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec&& alb) noexcept{
   std::swap(alb.size,size);
   std::swap(alb.vettore,vettore);

   return *this;

}

template <typename Data> 
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec& alb) const noexcept{
    return MutableBinaryTree<Data>::MutableNode::operator==(alb);

}
 
template <typename Data> 
inline bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec& alb) const noexcept{
    return !operator==(alb);

}

template <typename Data> 
const BinaryTreeVec<Data>::Node& BinaryTreeVec<Data>::Root() const {
    if(size == 0)
        throw std::out_of_range("Albero Vuoto!");
    return *vettore[0];
}
 
template <typename Data> 
BinaryTreeVec<Data>::MutableNode& BinaryTreeVec<Data>::Root() {
    if(size == 0)
        throw std::out_of_range("Albero Vuoto!");
    return *vettore[0];
}
  
template <typename Data> 
void BinaryTreeVec<Data>::Clear(){
    for(unsigned long int i = 0; i < size ; i++)
        delete vettore[i];
    size = 0;
}

template <typename Data> 
inline void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun funzione ) const {
    for(unsigned long int i = 0; i < size ; i++)
        funzione(vettore[i]->elemento);
}

template <typename Data> 
inline void BinaryTreeVec<Data>::BreadthMap(MapFun funzione) {
    for(unsigned long int i = 0; i < size ; i++)
        funzione(vettore[i]->elemento);

}



}
