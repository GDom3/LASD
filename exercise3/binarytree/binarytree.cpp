
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */

template <typename Data>
bool BinaryTree<Data>::Node::operator== (const Node& altroNodo) const noexcept{
 
    
    bool ret = Element() == altroNodo.Element(); // Se hanno lo stesso valore

    //Se entrambi non hanno figli oppure sono uguali
    ret &= (!HasLeftChild() && !altroNodo.HasLeftChild()) || (HasLeftChild() && altroNodo.HasLeftChild() && LeftChild() == altroNodo.LeftChild()); 
    ret &= (!HasRightChild() && !altroNodo.HasRightChild()) || (HasRightChild() && altroNodo.HasRightChild() && RightChild() == altroNodo.RightChild()); 

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
    
    while(coda.Empty() == false){
        
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

    while(coda.Empty() == false){
        
        MutableNode& nodo = *(coda.HeadNDequeue());

        fun(nodo.Element());

        if(nodo.HasLeftChild())
            coda.Enqueue( &(nodo.LeftChild()) );
        
        if(nodo.HasRightChild())
            coda.Enqueue( &(nodo.RightChild()) );

    }

}








template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& albero){
    if (!albero.Empty()) {
        depositoRadice = &albero.Root();
        stackT.Push(depositoRadice);
    }

}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& iter)
    : depositoRadice{iter.depositoRadice},stackT{iter.stackT}
{

}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& iter) noexcept{
    std::swap(depositoRadice,iter.depositoRadice);
    std::swap(stackT,iter.stackT);
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data>& iter){
    BTPreOrderIterator<Data> copia{iter};
    std::swap(*this,copia);
    return *this;
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& iter) noexcept{
    std::swap(depositoRadice,iter.depositoRadice);
    std::swap(stackT,iter.stackT);
    return *this;
}

template <typename Data>
inline bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data>& iter) const noexcept{
    return depositoRadice == iter.depositoRadice && stackT == iter.stackT;
}

template <typename Data>
inline bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data>& iter) const noexcept{
    return !operator==(iter);
}

template <typename Data>
inline const Data& BTPreOrderIterator<Data>::operator*() const {
    if (Terminated())
        throw std::out_of_range("Finito !!");

    return stackT.Top()->Element();
}

template <typename Data>
inline bool BTPreOrderIterator<Data>::Terminated() const noexcept {
    return stackT.Empty();
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++(){
    if (Terminated())
        throw std::out_of_range("Finito !!");
    
    const typename BinaryTree<Data>::Node * nodo = stackT.Top();
    stackT.Pop();

    if (nodo->HasRightChild())
        stackT.Push(&nodo->RightChild());
    if (nodo->HasLeftChild())
        stackT.Push(&nodo->LeftChild());


    
    return *this;
}

template <typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept {
    
    if (depositoRadice != nullptr){
        stackT.Clear();
        stackT.Push(depositoRadice);
    }
        
}








template <typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(const BinaryTree<Data>& alb) 
    : BTPreOrderIterator<Data>::BTPreOrderIterator(alb){
    
}

template <typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(const BTPreOrderMutableIterator<Data>& iter)
    : BTPreOrderIterator<Data>::BTPreOrderIterator(iter)
{

}


template <typename Data>
BTPreOrderMutableIterator<Data>::BTPreOrderMutableIterator(BTPreOrderMutableIterator<Data>&& iter) noexcept
    :BTPreOrderIterator<Data>::BTPreOrderIterator(std::move(iter))
{

}


template <typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(const BTPreOrderMutableIterator<Data>& iter){
    BTPreOrderIterator<Data>::operator=(iter);
    return *this;
}

template <typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(BTPreOrderMutableIterator<Data>&& iter) noexcept{
    BTPreOrderIterator<Data>::operator=(std::move(iter));
    return *this;
}

template <typename Data>
inline bool BTPreOrderMutableIterator<Data>::operator==(const BTPreOrderMutableIterator<Data>& iter) const noexcept{
    return BTPreOrderIterator<Data>::operator==(iter);
}

template <typename Data>
inline bool BTPreOrderMutableIterator<Data>::operator!=(const BTPreOrderMutableIterator<Data>& iter) const noexcept{
    return BTPreOrderIterator<Data>::operator!=(iter);
}


template <typename Data>
inline Data& BTPreOrderMutableIterator<Data>::operator*(){
    return const_cast<Data&>(BTPreOrderIterator<Data>::operator*());
}


template <typename Data>
void BTPostOrderIterator<Data>::visitaPost(const typename BinaryTree<Data>::Node * tmp) noexcept{
    while(tmp != nullptr){
        if (tmp->HasRightChild())
            stackT.Push(&(tmp->RightChild()));    
        if (tmp->HasLeftChild())
            stackT.Push(&(tmp->LeftChild()));
      

        if (tmp->HasLeftChild())
            tmp = &tmp->LeftChild();
        else if (tmp->HasRightChild())
            tmp = &tmp->RightChild();
        else   
            tmp = nullptr;
    }
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& alb){
    if(!alb.Empty()){
        depositoRadice = &alb.Root();
    
        stackT.Push(depositoRadice);
        visitaPost(depositoRadice);

    }

}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data>& iter)
    : depositoRadice{iter.depositoRadice},stackT{iter.stackT}
{

}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data>&& iter) noexcept{
    std::swap(depositoRadice,iter.depositoRadice);
    std::swap(stackT,iter.stackT);
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data>& iter){
    BTPostOrderIterator<Data> copia{iter};
    std::swap(*this,copia);
    return *this;
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data>&& iter) noexcept{
    std::swap(depositoRadice,iter.depositoRadice);
    std::swap(stackT,iter.stackT);
    return *this;
}

template <typename Data>
inline bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data>& iter) const noexcept{
    return depositoRadice == iter.depositoRadice && stackT == iter.stackT;
}

template <typename Data>
inline bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data>& iter) const noexcept{
    return !operator==(iter);
}

template <typename Data>
inline const Data& BTPostOrderIterator<Data>::operator*() const {
    if (Terminated())
        throw std::out_of_range("Finito !!");

    return stackT.Top()->Element();
}

template <typename Data>
inline bool BTPostOrderIterator<Data>::Terminated() const noexcept {
    return stackT.Empty();
}


template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    if (Terminated())
        throw std::out_of_range("Finito !!");
    
    const typename BinaryTree<Data>::Node * testa = stackT.TopNPop();
    
    if(!stackT.Empty()){
        const typename BinaryTree<Data>::Node * prossimo = stackT.Top();
    

        if(
            (!prossimo->HasLeftChild() || (prossimo->HasLeftChild() && prossimo->LeftChild() != *testa)) 
                && 
            (!prossimo->HasRightChild() || (prossimo->HasRightChild() && prossimo->RightChild() != *testa))
        )
        {
            visitaPost(prossimo);
        }
            
            
        
        
    }

    return *this;
}

template <typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
    
    if (depositoRadice != nullptr){
        stackT.Clear();
        stackT.Push(depositoRadice);
        visitaPost(depositoRadice);
    }
}









template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(const BinaryTree<Data>& alb) 
    : BTPostOrderIterator<Data>::BTPostOrderIterator(alb){
    
}

template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(const BTPostOrderMutableIterator<Data>& iter)
    : BTPostOrderIterator<Data>::BTPostOrderIterator(iter)
{

}

template <typename Data>
BTPostOrderMutableIterator<Data>::BTPostOrderMutableIterator(BTPostOrderMutableIterator<Data>&& iter) noexcept
    :BTPostOrderIterator<Data>::BTPostOrderIterator(std::move(iter))
{

}

template <typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(const BTPostOrderMutableIterator<Data>& iter){
    BTPostOrderIterator<Data>::operator=(iter);
    return *this;
}

template <typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(BTPostOrderMutableIterator<Data>&& iter) noexcept{
    BTPostOrderIterator<Data>::operator=(std::move(iter));
    return *this;
}

template <typename Data>
inline bool BTPostOrderMutableIterator<Data>::operator==(const BTPostOrderMutableIterator<Data>& iter) const noexcept{
    return BTPostOrderIterator<Data>::operator==(iter);
}

template <typename Data>
inline bool BTPostOrderMutableIterator<Data>::operator!=(const BTPostOrderMutableIterator<Data>& iter) const noexcept{
    return BTPostOrderIterator<Data>::operator!=(iter);
}


template <typename Data>
inline Data& BTPostOrderMutableIterator<Data>::operator*(){
    return const_cast<Data&>(BTPostOrderIterator<Data>::operator*());
}





template <typename Data>
inline BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& alb){
    if(!alb.Empty()){
        depositoRadice = &alb.Root();
        stackT.Push(depositoRadice);
        visitaIn(depositoRadice);
    }

}


template <typename Data>
void BTInOrderIterator<Data>::visitaIn(const typename BinaryTree<Data>::Node * node) noexcept{

    while(node != nullptr){ 
        if(node->HasLeftChild()){
            stackT.Push(&node->LeftChild());
            node = &node->LeftChild();
        }else{
            node = nullptr;
        }
            
        
    }
    
}


template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data>& iter)
    : depositoRadice{iter.depositoRadice},stackT{iter.stackT}
{

}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data>&& iter) noexcept{
    std::swap(depositoRadice,iter.depositoRadice);
    std::swap(stackT,iter.stackT);
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data>& iter){
    BTInOrderIterator<Data> copia{iter};
    std::swap(*this,copia);
    return *this;
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data>&& iter) noexcept{
    std::swap(depositoRadice,iter.depositoRadice);
    std::swap(stackT,iter.stackT);
    return *this;
}

template <typename Data>
inline bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data>& iter) const noexcept{
    return depositoRadice == iter.depositoRadice && stackT == iter.stackT;
}

template <typename Data>
inline bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data>& iter) const noexcept{
    return !operator==(iter);
}

template <typename Data>
inline const Data& BTInOrderIterator<Data>::operator*() const {
    if (Terminated())
        throw std::out_of_range("Finito !!");

    return stackT.Top()->Element();
}

template <typename Data>
inline bool BTInOrderIterator<Data>::Terminated() const noexcept {
    return stackT.Empty();
}

template <typename Data>
inline BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++(){
    if (Terminated())
        throw std::out_of_range("Finito !!");

    const typename BinaryTree<Data>::Node * prossima = stackT.TopNPop();

    if(prossima->HasRightChild()){
        stackT.Push(&prossima->RightChild());
        visitaIn(&prossima->RightChild());
    }
            

    return *this;
}
    

template <typename Data>
void BTInOrderIterator<Data>::Reset() noexcept {
    if (depositoRadice != nullptr){
        stackT.Clear();
        stackT.Push(depositoRadice);
        visitaIn(depositoRadice);
    }
}









template <typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(const BinaryTree<Data>& alb) 
    : BTInOrderIterator<Data>::BTInOrderIterator(alb){
    
}

template <typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(const BTInOrderMutableIterator<Data>& iter)
    : BTInOrderIterator<Data>::BTInOrderIterator(iter)
{

}

template <typename Data>
BTInOrderMutableIterator<Data>::BTInOrderMutableIterator(BTInOrderMutableIterator<Data>&& iter) noexcept
    :BTInOrderIterator<Data>::BTInOrderIterator(std::move(iter))
{

}

template <typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator<Data>& iter){
    BTInOrderIterator<Data>::operator=(iter);
    return *this;
}

template <typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(BTInOrderMutableIterator<Data>&& iter) noexcept{
    BTInOrderIterator<Data>::operator=(std::move(iter));
    return *this;
}

template <typename Data>
inline bool BTInOrderMutableIterator<Data>::operator==(const BTInOrderMutableIterator<Data>& iter) const noexcept{
    return BTInOrderIterator<Data>::operator==(iter);
}

template <typename Data>
inline bool BTInOrderMutableIterator<Data>::operator!=(const BTInOrderMutableIterator<Data>& iter) const noexcept{
    return BTInOrderIterator<Data>::operator!=(iter);
}


template <typename Data>
inline Data& BTInOrderMutableIterator<Data>::operator*(){
    return const_cast<Data&>(BTInOrderIterator<Data>::operator*());
}















template <typename Data>
inline BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& alb){
    if(!alb.Empty()){
        depositoRadice = &alb.Root();
        codaT.Enqueue(depositoRadice);
    }

}


template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& iter)
    : depositoRadice{iter.depositoRadice},codaT{iter.codaT}
{

}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& iter) noexcept{
    std::swap(depositoRadice,iter.depositoRadice);
    std::swap(codaT,iter.codaT);
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data>& iter){
    BTBreadthIterator<Data> copia{iter};
    std::swap(*this,copia);
    return *this;
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data>&& iter) noexcept{
    std::swap(depositoRadice,iter.depositoRadice);
    std::swap(codaT,iter.codaT);
    return *this;
}

template <typename Data>
inline bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data>& iter) const noexcept{
    return depositoRadice == iter.depositoRadice && codaT == iter.codaT;
}

template <typename Data>
inline bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data>& iter) const noexcept{
    return !operator==(iter);
}

template <typename Data>
inline const Data& BTBreadthIterator<Data>::operator*() const {
    if (Terminated())
        throw std::out_of_range("Finito !!");

    return codaT.Head()->Element();
}

template <typename Data>
inline bool BTBreadthIterator<Data>::Terminated() const noexcept {
    return codaT.Empty();
}

template <typename Data>
inline BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++(){
  
    const typename BinaryTree<Data>::Node * nodo = codaT.HeadNDequeue();
    if(nodo->HasLeftChild())
        codaT.Enqueue(&nodo->LeftChild());
    if(nodo->HasRightChild())
        codaT.Enqueue(&nodo->RightChild());


    return *this;
}
    

template <typename Data>
void BTBreadthIterator<Data>::Reset() noexcept {
  
    if (depositoRadice != nullptr){
        codaT.Clear();
        codaT.Enqueue(depositoRadice);
    }
}









template <typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(const BinaryTree<Data>& alb) 
    : BTBreadthIterator<Data>::BTBreadthIterator(alb){
    
}

template <typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(const BTBreadthMutableIterator<Data>& iter)
    : BTBreadthIterator<Data>::BTBreadthIterator(iter)
{

}

template <typename Data>
BTBreadthMutableIterator<Data>::BTBreadthMutableIterator(BTBreadthMutableIterator<Data>&& iter) noexcept
    :BTBreadthIterator<Data>::BTBreadthIterator(std::move(iter))
{

}

template <typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(const BTBreadthMutableIterator<Data>& iter){
    BTBreadthIterator<Data>::operator=(iter);
    return *this;
}

template <typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(BTBreadthMutableIterator<Data>&& iter) noexcept{
    BTBreadthIterator<Data>::operator=(std::move(iter));
    return *this;
}

template <typename Data>
inline bool BTBreadthMutableIterator<Data>::operator==(const BTBreadthMutableIterator<Data>& iter) const noexcept{
    return BTBreadthIterator<Data>::operator==(iter);
}

template <typename Data>
inline bool BTBreadthMutableIterator<Data>::operator!=(const BTBreadthMutableIterator<Data>& iter) const noexcept{
    return BTBreadthIterator<Data>::operator!=(iter);
}


template <typename Data>
inline Data& BTBreadthMutableIterator<Data>::operator*(){
    return const_cast<Data&>(BTBreadthIterator<Data>::operator*());
}
}
