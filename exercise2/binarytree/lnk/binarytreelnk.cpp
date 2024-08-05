
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
        figlioSinistro = new NodeLnk(node.figlioSinistro);
    if(nodo.HasRightChild())
        figlioDestro = new NodeLnk(nodo.figlioDestro);  
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
    return !operator==(nodo)
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
inline BinaryTreeLnk<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const{
    if(figlioSinistro == nullptr)
        throw std::out_of_range("Non c'è Figlio Sinistro")
    return figlioSinistro;
}

template <typename Data>
inline BinaryTreeLnk<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
    if(figlioDestro == nullptr)
        throw std::out_of_range("Non c'è Figlio Destro")
    return figlioDestro;
}

template <typename Data>
inline Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept{
    return elemento;
}

template <typename Data>
inline BinaryTreeLnk<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::LeftChild() {
    return figlioSinistro;
}

template <typename Data>
inline BinaryTreeLnk<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::RightChild() {
    return figlioDestro;
}

}
