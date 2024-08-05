
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : virtual public MutableBinaryTree<Data> {
  // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  // using BinaryTree<Data>::???;
  using BinaryTree<Data>::Node;
  using BinaryTree<Data>::MutableNode;

  // ...

  struct NodeLnk : virtual public MutableNode { // Must extend MutableNode

  private:

    // ...
    

  protected:

    // ...


  public:

    friend class BinaryTreeLnk<Data>;

    Data elemento;
    Node * figlioSinistro = nullptr;
    Node * figlioDestro = nullptr;

    // ...
    // constructor
    inline NodeLnk() = default;

    // Data Copy constructor
    inline NodeLnk(const Data&);

    // Data Move constructor
    inline NodeLnk(Data&&);

    // Copy constructor
    inline NodeLnk(const NodeLnk&);

    // Move constructor
    inline NodeLnk(NodeLnk&&);

    inline ~NodeLnk();

    inline NodeLnk& operator=(const NodeLnk&);

    NodeLnk& operator=(NodeLnk&& nodo) noexcept;

    // Comparison operators
    
    // type operator==(argument) specifiers; 
    // Comparison of abstract types is possible, but is not visible.
    bool operator== (const NodeLnk& nodo ) const noexcept;
    
    // type operator!=(argument) specifiers; 
    // Comparison of abstract types is possible, but is not visible.
    inline bool operator!= (const NodeLnk& nodo ) const noexcept;

    //Da Node :
    
    const Data& Element() const noexcept override;

    inline bool HasLeftChild() const noexcept override;

    inline bool HasRightChild() const noexcept override;

    inline Node& LeftChild() const override;

    inline Node& RightChild() const override;

    // Da MutualeNode :

    inline Data& Element() noexcept override;

    inline MutableNode& LeftChild() override;

    inline MutableNode& RightChild() override;

  };

  NodeLnk * radice = nullptr;

public:

  // Default constructor
  // BinaryTreeLnk() specifiers;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a TraversableContainer
  // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeLnk(argument) specifiers;

  // Move constructor
  // BinaryTreeLnk(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeLnk() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  // type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
