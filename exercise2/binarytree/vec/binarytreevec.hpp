
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public MutableBinaryTree<Data>{
  // Must extend MutableBinaryTree<Data>

private:

  // ...
public:

  // using BinaryTree<Data>::???;
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

protected:

  // ...

  struct NodeVec : virtual public MutableNode { // Must extend MutableNode

  private:

    // ...

  protected:

    // ...
    unsigned long int indice = 0;
    Data elemento{};
    NodeVec * figlioSinistro = nullptr;
    NodeVec * figlioDestro = nullptr;


  public:
    friend class BinaryTreeVec<Data>;
    
    // Data Copy constructor
    inline NodeVec (const Data&, NodeVec *, NodeVec *, unsigned long int);

    // Data Move constructor
    inline NodeVec(Data&&, NodeVec *, NodeVec *, unsigned long int);

    //Copy constructor
    inline NodeVec (const NodeVec&);

    //Move constructor
    inline NodeVec(NodeVec&&);
    
    inline ~NodeVec() = default;

    using BinaryTree<Data>::Node::operator==;
    using BinaryTree<Data>::Node::operator!=;
    

    bool operator== (const NodeVec& ) const noexcept;

    inline bool operator!= (const NodeVec& ) const noexcept;

    //Da Node :
    
    const Data& Element() const noexcept override;

    inline bool HasLeftChild() const noexcept override;

    inline bool HasRightChild() const noexcept override;

    inline const Node& LeftChild() const override;

    inline const Node& RightChild() const override;

    // Da MutualeNode :

    inline Data& Element() noexcept override;

    inline MutableNode& LeftChild() override;

    inline MutableNode& RightChild() override;

  };  

  using Container::size;

  Vector<NodeVec *> vettore{};

public:

  // Default constructor
  // BinaryTreeVec() specifiers;
  inline BinaryTreeVec() = default;

  /* ************************************************************************ */
  
  // Specific constructors
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a TraversableContainer
  BinaryTreeVec(const TraversableContainer<Data>&);
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a MappableContainer
  BinaryTreeVec(MappableContainer<Data>&&); 

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeVec(argument) specifiers;
  inline BinaryTreeVec(const BinaryTreeVec&);

  // Move constructor
  // BinaryTreeVec(argument) specifiers;
  inline BinaryTreeVec(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeVec() specifiers;
  inline ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec& operator=(const BinaryTreeVec&);

  // Move assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec& operator=(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BinaryTreeVec&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BinaryTreeVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
  virtual const Node& Root() const override;
  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  // type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)
  virtual MutableNode& Root() override;
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  virtual void Clear() override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)
  using typename TraversableContainer<Data>::TraverseFun;
  // type BreadthTraverse(arguments) specifiers; // Override BreadthTraversableContainer member
  inline void BreadthTraverse(TraverseFun ) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)
  using typename BreadthMappableContainer<Data>::MapFun;
  // type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member
  inline void BreadthMap(MapFun ) override;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
