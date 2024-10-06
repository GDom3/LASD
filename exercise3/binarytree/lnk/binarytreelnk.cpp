
namespace lasd {

/* ************************************************************************** */

// ...

/* ************************************************************************** */


template <typename Data>
inline BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& elem) {
    elemento = elem;
}

template <typename Data>
inline BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& elem ){
    std::swap(elemento,elem);
}

template <typename Data>
inline BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk& nodo ) : NodeLnk(nodo.elemento){
    if(nodo.HasLeftChild())
        figlioSinistro = new NodeLnk( * nodo.figlioSinistro);
    if(nodo.HasRightChild())
        figlioDestro = new NodeLnk( * nodo.figlioDestro);  
}

template <typename Data>
inline BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk&& nodo ){
    std::swap(elemento,nodo.elemento);
    std::swap(figlioDestro,nodo.figlioDestro);
    std::swap(figlioSinistro,nodo.figlioSinistro);
}

template <typename Data>
inline BinaryTreeLnk<Data>::NodeLnk::~NodeLnk() {
    delete figlioDestro;
    delete figlioSinistro;
}

template <typename Data>
inline BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& nodo){
    NodeLnk nuovoNodo = new NodeLnk(nodo);
    std::swap(*this,nuovoNodo);
    return *this;
}

template <typename Data>
inline BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& nodo) noexcept {
    std::swap(elemento,nodo.elemento);
    std::swap(figlioDestro,nodo.figlioDestro);
    std::swap(figlioSinistro,nodo.figlioSinistro);
    return *this;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator== (const NodeLnk& nodo ) const noexcept{
    return MutableBinaryTree<Data>::MutableNode::operator==(nodo);
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::operator!= (const NodeLnk& nodo ) const noexcept{
    return !operator==(nodo);
}

template <typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept{
    return elemento;
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept{
    return figlioSinistro != nullptr;
}

template <typename Data>
inline bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept{
    return figlioDestro != nullptr;
}

template <typename Data>
inline const BinaryTreeLnk<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const{
    if(figlioSinistro == nullptr)
        throw std::out_of_range("Non c'è Figlio Sinistro");
    return *figlioSinistro;
}

template <typename Data>
inline const BinaryTreeLnk<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
    if(figlioDestro == nullptr)
        throw std::out_of_range("Non c'è Figlio Destro");
    return *figlioDestro;
}

template <typename Data>
inline Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept{
    return elemento;
}

template <typename Data>
inline BinaryTreeLnk<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::LeftChild() {
    if(figlioSinistro == nullptr)
        throw std::out_of_range("Non c'è Figlio Destro");
    return *figlioSinistro;
}

template <typename Data>
inline BinaryTreeLnk<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::RightChild() {
    if(figlioDestro == nullptr)
        throw std::out_of_range("Non c'è Figlio Destro");
    return *figlioDestro;
}


template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data>& struttura){
  
  QueueVec<BinaryTreeLnk<Data>::NodeLnk *> coda{};

  struttura.Traverse([&coda, this](const Data &dato) {
    NodeLnk * nodo = new NodeLnk(dato);
    
    coda.Enqueue(nodo);
    
    size++;
    if(size - 1 == 0){
        radice = coda.Head();
    }else{
        if(size %  2 == 0){
            coda.Head()->figlioSinistro = nodo;
        }else{
            coda.HeadNDequeue()->figlioDestro = nodo; //al terzo figlio lo levo
        }
    }

  });

}


template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data>&& struttura){
    QueueVec<BinaryTreeLnk<Data>::NodeLnk *> coda{};

    struttura.Map([&coda, this](Data &dato) {
        NodeLnk * nodo = new NodeLnk(std::move(dato));
    
        coda.Enqueue(nodo);
    
        size++;
        if(size - 1 == 0){
            radice = coda.Head();
        }else{
            if(size %  2 == 0){
                coda.Head()->figlioSinistro = nodo;
            }else{
                coda.HeadNDequeue()->figlioDestro = nodo; //al terzo figlio lo levo
            }
        }

    });

}


template <typename Data>
inline BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& alb){    

    if(alb.size > 0){
        size = alb.size;
        radice = new NodeLnk(*alb.radice); //Sfrutto la ricorsività
    }


}



template <typename Data>
inline BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& alb) noexcept{
    std::swap(alb.radice,radice);
    std::swap(alb.size,size);

}


template <typename Data>
inline BinaryTreeLnk<Data>::~BinaryTreeLnk(){
    delete radice;
}

template <typename Data>
inline BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk& alb){
    
    Clear();

    BinaryTreeLnk<Data> copia{alb};

    std::swap(copia,*this);

    return *this;

}

template <typename Data>
inline BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk&& alb) noexcept{
    std::swap(size,alb.size);
    std::swap(radice,alb.radice);
    return *this;
}
  

template <typename Data>
inline bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk& alb) const noexcept{
    if(size != alb.size)
        return false;
    
    if(size == 0)
        return true;
    
    return *radice == *alb.radice;

}

template <typename Data>
inline bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk& alb) const noexcept{
    return !operator==(alb);
}


template <typename Data>
const BinaryTreeLnk<Data>::Node& BinaryTreeLnk<Data>::Root() const {
    if(radice == nullptr)
        throw std::length_error("Albero Vuoto");
    return *radice;
}

template <typename Data>
BinaryTreeLnk<Data>::MutableNode& BinaryTreeLnk<Data>::Root() {
    if(radice == nullptr)
        throw std::length_error("Albero Vuoto");
    return *radice;
}

template <typename Data>
void BinaryTreeLnk<Data>::Clear(){
    if (radice == nullptr)
        return;
    
    delete radice;
    radice = nullptr;
    size = 0; 
}

}
