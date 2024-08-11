
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

public:

  // using BinaryTree<Data>::???;
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;


  // ...
protected:
  struct NodeLnk : virtual public MutableNode { // Must extend MutableNode

  private:

    // ...
    

  protected:

    // ...
        
    Data elemento{};
    NodeLnk * figlioSinistro = nullptr;
    NodeLnk * figlioDestro = nullptr;
  

  public:

    


    friend class BinaryTreeLnk<Data>;
    
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

    NodeLnk& operator=(NodeLnk&&) noexcept;

    // Comparison operators
    
    // type operator==(argument) specifiers; 
    // Comparison of abstract types is possible, but is not visible.
    bool operator== (const NodeLnk& ) const noexcept;
    
    // type operator!=(argument) specifiers; 
    // Comparison of abstract types is possible, but is not visible.
    inline bool operator!= (const NodeLnk& ) const noexcept;

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

  NodeLnk * radice = nullptr;

public:

  // Default constructor
  // BinaryTreeLnk() specifiers;
  inline BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeLnk(argument) specifiers; 
  // A binary tree obtained from a TraversableContainer
  BinaryTreeLnk(const TraversableContainer<Data>&);

  // BinaryTreeLnk(argument) specifiers; 
  // A binary tree obtained from a MappableContainer
  BinaryTreeLnk(MappableContainer<Data>&&); 
  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeLnk(argument) specifiers;
  inline BinaryTreeLnk(const BinaryTreeLnk&);
  // Move constructor
  // BinaryTreeLnk(argument) specifiers;
  inline BinaryTreeLnk(BinaryTreeLnk&&) noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeLnk() specifiers;
  virtual inline ~BinaryTreeLnk();
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  inline BinaryTreeLnk& operator=(const BinaryTreeLnk&);
  // Move assignment
  // type operator=(argument) specifiers;
  inline BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const BinaryTreeLnk&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BinaryTreeLnk&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
  const Node& Root() const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  // type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)
  virtual MutableNode& Root() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  virtual void Clear() override;

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
