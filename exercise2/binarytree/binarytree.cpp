
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
bool BinaryTree<Data>::Node::operator== (const Node& altroNodo) const noexcept{
    bool ret = this->Element() == altroNodo.Element(); // Se hanno lo stesso valore
    ret &= this->HasLeftChild() == altroNodo.HasLeftChild(); // Se hanno entrambi un filgio sinistro o no
    ret &= this->HasRightChild() == altroNodo.HasRightChild(); // Se hanno entrambi un filgio destro o no
    ret &= this->HasLeftChild() && this->LeftChild() == this->LeftChild(); // Se hanno figlio sinistro deve essere uguale
    ret &= this->HasRightChild() && this->RightChild() == this->RightChild(); // Se hanno figlio detro deve essere uguale
 
    return ret;
}

template <typename Data>
bool BinaryTree<Data>::Node::operator!= (const Node& altroNodo) const noexcept{
    return !this->operator==(altroNodo);
}

template <typename Data>
bool BinaryTree<Data>::Node::IsLeaf () const noexcept{
    return !this->HasLeftChild() || !this->HasRightChild(); // Devo avere almeno un figlio
}

template <typename Data>
inline bool BinaryTree<Data>::operator== (const BinaryTree& alb) const noexcept{
    if(Size() != alb.Size())
        return false;
    
    if(Size() == 0)
        return true;
    
    return Root() == alb.Root(); //Sfrutto l'uguaglianza ricorsiva dei miei nodi
    
}

template <typename Data>
inline bool BinaryTree<Data>::operator!= (const BinaryTree& alb) const noexcept{
    return !operator==(alb);
}

template <typename Data>
inline void BinaryTree<Data>::Traverse(TraverseFun fun) const {
    return BreadthTraverse(fun);
}

template <typename Data>
inline void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun) const {
    if(!Empty())
        PreOrderTraverse(fun,Root());

}

template <typename Data>
inline void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun , const Node& nodo) const {
    fun(nodo.Element());

    if(nodo.HasLeftChild())
        PreOrderTraverse(fun,nodo.LeftChild());

    if(nodo.HasRightChild())
        PreOrderTraverse(fun,nodo.RightChild());

}

template <typename Data>
inline void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun) const {
    if(!Empty())
        PostOrderTraverse(fun,Root());
}

template <typename Data>
inline void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun, const Node& nodo) const {
    if(nodo.HasLeftChild())
        PostOrderTraverse(fun,nodo.LeftChild());

    if(nodo.HasRightChild())
        PostOrderTraverse(fun,nodo.RightChild());

    fun(nodo.Element());
}

template <typename Data>
inline void BinaryTree<Data>::InOrderTraverse(TraverseFun fun ) const {
    if(!Empty())
        InOrderTraverse(fun,Root());
}

template <typename Data>
inline void BinaryTree<Data>::InOrderTraverse(TraverseFun fun, const Node& nodo) const {
    if(nodo.HasLeftChild())
        InOrderTraverse(fun,nodo.LeftChild());
    
    fun(nodo.Element());

    if(nodo.HasRightChild())
        InOrderTraverse(fun,nodo.RightChild());
}

template <typename Data>
inline void BinaryTree<Data>::BreadthTraverse(TraverseFun fun) const {
    if(Empty())
        return;

    QueueLst<const Node*> coda{};
    coda.Enqueue(&Root());

    while(coda.Empty() == true){
        
        const Node& nodo = *(coda.HeadNDequeue());

        fun(nodo.Element());

        if(nodo.HasLeftChild())
            coda.Enqueue( &(nodo.LeftChild()) );
        
        if(nodo.HasRightChild())
            coda.Enqueue( &(nodo.RightChild()) );

    }

}







template <typename Data>
inline void MutableBinaryTree<Data>::Map(MapFun fun){
    return BreadthMap(fun);
}

template <typename Data>
inline void MutableBinaryTree<Data>::PreOrderMap(MapFun fun) {
    if(!Empty())
        PreOrderMap(fun,Root());

}

template <typename Data>
inline void MutableBinaryTree<Data>::PreOrderMap(MapFun fun , MutableNode& nodo) {
    fun(nodo.Element());

    if(nodo.HasLeftChild())
        PreOrderMap(fun,nodo.LeftChild());

    if(nodo.HasRightChild())
        PreOrderMap(fun,nodo.RightChild());

}

template <typename Data>
inline void MutableBinaryTree<Data>::PostOrderMap(MapFun fun) {
    if(!Empty())
        PostOrderMap(fun,Root());
}

template <typename Data>
inline void MutableBinaryTree<Data>::PostOrderMap(MapFun fun, MutableNode& nodo) {
    if(nodo.HasLeftChild())
        PostOrderMap(fun,nodo.LeftChild());

    if(nodo.HasRightChild())
        PostOrderMap(fun,nodo.RightChild());

    fun(nodo.Element());
}

template <typename Data>
inline void MutableBinaryTree<Data>::InOrderMap(MapFun fun ){
    if(!Empty())
        InOrderMap(fun,Root());
}

template <typename Data>
inline void MutableBinaryTree<Data>::InOrderMap(MapFun fun, MutableNode& nodo) {
    if(nodo.HasLeftChild())
        InOrderMap(fun,nodo.LeftChild());
    
    fun(nodo.Element());

    if(nodo.HasRightChild())
        InOrderMap(fun,nodo.RightChild());
}

template <typename Data>
inline void MutableBinaryTree<Data>::BreadthMap(MapFun fun) {
    if(Empty())
        return;

    QueueLst<MutableNode*> coda{};
    coda.Enqueue(&Root());

    while(coda.Empty() == true){
        
        MutableNode& nodo = *(coda.HeadNDequeue());

        fun(nodo.Element());

        if(nodo.HasLeftChild())
            coda.Enqueue( &(nodo.LeftChild()) );
        
        if(nodo.HasRightChild())
            coda.Enqueue( &(nodo.RightChild()) );

    }

}


}
