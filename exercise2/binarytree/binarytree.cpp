
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



}
