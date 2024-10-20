
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../iterator/iterator.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : virtual public ClearableContainer, 
            virtual public DictionaryContainer<Data>, 
            virtual public BinaryTree<Data>, 
            virtual protected BinaryTreeLnk<Data>{
  // Must extend ClearableContainer,
  //             DictionaryContainer<Data>,
  //             BinaryTree<Data>,
  //             BinaryTreeLnk<Data>

private:

  // ...

protected:

  using typename BinaryTreeLnk<Data>::NodeLnk;

  // using BinaryTreeLnk<Data>::???;
  using BinaryTreeLnk<Data>::radice;
  using Container::size;

public:

  // Default constructor
  // BST() specifiers;
  BST() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BST(argument) specifiers; // A bst obtained from a TraversableContainer
  BST(const TraversableContainer<Data>& );
  // BST(argument) specifiers; // A bst obtained from a MappableContainer
  BST(MappableContainer<Data>&& );
  /* ************************************************************************ */

  // Copy constructor
  // BST(argument) specifiers;
  BST(const BST<Data>& );

  // Move constructor
  // BST(argument) specifiers;
  BST(BST<Data>&& ) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BST() specifiers;
  virtual ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BST& operator=(const BST& );

  // Move assignment
  // type operator=(argument) specifiers;
  BST& operator=(BST&& ) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BST& ) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const BST& ) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type Min(argument) specifiers; // (concrete function must throw std::length_error when empty)
  virtual inline const Data& Min() const;  
  // type MinNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  virtual inline Data MinNRemove();
  // type RemoveMin(argument) specifiers; // (concrete function must throw std::length_error when empty)
  virtual inline void RemoveMin();

  // type Max(argument) specifiers; // (concrete function must throw std::length_error when empty)
  virtual inline const Data& Max() const;
  // type MaxNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  virtual inline Data MaxNRemove();
  // type RemoveMax(argument) specifiers; // (concrete function must throw std::length_error when empty)
  virtual inline void RemoveMax();

  // type Predecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  virtual inline const Data& Predecessor(const Data& ) const;
  // type PredecessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  virtual inline Data PredecessorNRemove(const Data& );
  // type RemovePredecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  virtual inline void RemovePredecessor(const Data& );
  
  // type Successor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  virtual inline const Data& Successor(const Data& ) const;
  // type SuccessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  virtual inline Data SuccessorNRemove(const Data& );
  // type RemoveSuccessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  virtual inline void RemoveSuccessor(const Data& );

  /* ************************************************************************ */

  // Specific member function (inherited from BinaryTree)

  // type Root(argument) specifiers; // Override BinaryTree member
  using BinaryTree<Data>::Root;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  virtual bool Insert(const Data &) override;
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  virtual bool Insert(Data &&) override;
  // type Remove(argument) specifiers; // Override DictionaryContainer member
  virtual bool Remove(const Data &) override;
  
  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  using typename TraversableContainer<Data>::TraverseFun;
  inline void Traverse(TraverseFun) const override;
  
  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  inline virtual bool Exists(const Data&) const noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear(argument) specifiers; // Override ClearableContainer member
  using BinaryTreeLnk<Data>::Clear;


  void Stampa();
  

protected:

  // Auxiliary functions, if necessary!

  // type DataNDelete(argument) specifiers;

  // type Detach(argument) specifiers;

  // type DetachMin(argument) specifiers;
  // type DetachMax(argument) specifiers;

  // type Skip2Left(argument) specifiers;
  // type Skip2Right(argument) specifiers;

  // type FindPointerToMin(argument) specifiers; // Both mutable & unmutable versions
  // type FindPointerToMax(argument) specifiers; // Both mutable & unmutable versions

  // type FindPointerTo(argument) specifiers; // Both mutable & unmutable versions

  // type FindPointerToPredecessor(argument) specifiers; // Both mutable & unmutable versions
  // type FindPointerToSuccessor(argument) specifiers; // Both mutable & unmutable versions

  NodeLnk * Min(NodeLnk * ) const;
  NodeLnk * Max(NodeLnk * ) const;
  
  NodeLnk * Successor(NodeLnk * , const Data& ) const;
  NodeLnk * Predecessor(NodeLnk * , const Data& ) const;
  
  NodeLnk * Remove(NodeLnk * , const Data &);
  NodeLnk * CancellaRadiceBST(NodeLnk *);
  NodeLnk * StaccaMin(NodeLnk *,NodeLnk *);

  NodeLnk * Insert(NodeLnk * , const Data &);
  NodeLnk * Insert(NodeLnk * , Data &&);

  NodeLnk * RicercaBST(NodeLnk * , const Data &) const;

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
