
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree : virtual public PreOrderTraversableContainer<Data>, virtual public PostOrderTraversableContainer<Data>, virtual public InOrderTraversableContainer<Data>, virtual public BreadthTraversableContainer<Data>{
  // Must extend PreOrderTraversableContainer<Data>,
  //             PostOrderTraversableContainer<Data>,
  //             InOrderTraversableContainer<Data>,
  //             BreadthTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:
  using Container::Empty;
  using Container::Size;

  struct Node {

  protected:

    // Comparison operators
    
    // type operator==(argument) specifiers; 
    // Comparison of abstract types is possible, but is not visible.
    virtual inline bool operator== (const Node& ) const noexcept;
    // type operator!=(argument) specifiers; 
    // Comparison of abstract types is possible, but is not visible.
    virtual inline bool operator!= (const Node& ) const noexcept;

  public:

    // friend class BinaryTree<Data>;
    friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    // ~Node() specifiers
    inline virtual ~Node() = default;
    /* ********************************************************************** */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types is not possible.
    Node& operator=(const Node&) = delete;

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types is not possible.
    Node& operator=(Node&& ) noexcept = delete;

    /* ********************************************************************** */

    // Specific member functions

    // type Element() specifiers; // Immutable access to the element (concrete function should not throw exceptions)
    virtual const Data& Element() const noexcept = 0;

    // type IsLeaf() specifiers; // (concrete function should not throw exceptions)
    virtual inline bool IsLeaf() const noexcept;
    // type HasLeftChild() specifiers; // (concrete function should not throw exceptions)
    virtual inline bool HasLeftChild() const noexcept = 0;
    // type HasRightChild() specifiers; // (concrete function should not throw exceptions)
    virtual inline bool HasRightChild() const noexcept = 0;

    // type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    virtual inline const Node& LeftChild() const = 0;
    // type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    virtual inline const Node& RightChild() const = 0;
  };

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTree() specifiers
  inline virtual ~BinaryTree() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); 
  // Copy assignment of abstract types is not possible.
  BinaryTree& operator=(const BinaryTree&) = delete;

  // Move assignment
  // type operator=(argument); 
  // Move assignment of abstract types is not possible.
  BinaryTree& operator=(BinaryTree&& ) noexcept = delete; 

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; 
  // Comparison of abstract binary tree is possible.
  virtual inline bool operator== (const BinaryTree& ) const noexcept;

  // type operator!=(argument) specifiers; 
  // Comparison of abstract binary tree is possible.
  virtual inline bool operator!= (const BinaryTree& ) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type Root() specifiers; // (concrete function must throw std::length_error when empty)
  virtual const Node& Root() const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // using typename TraversableContainer<Data>::TraverseFun;
  using typename TraversableContainer<Data>::TraverseFun;

  // type Traverse(arguments) specifiers; 
  // Override TraversableContainer member
  inline void Traverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  // type PreOrderTraverse(arguments) specifiers; 
  // Override PreOrderTraversableContainer member
  inline void PreOrderTraverse(TraverseFun ) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  // type PostOrderTraverse(arguments) specifiers; 
  // Override PostOrderTraversableContainer member
  inline void PostOrderTraverse(TraverseFun ) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderTraversableContainer)

  // type InOrderTraverse(arguments) specifiers; 
  // Override InOrderTraversableContainer member
  inline void InOrderTraverse(TraverseFun ) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  // type BreadthTraverse(arguments) specifiers; 
  // Override BreadthTraversableContainer member
  inline void BreadthTraverse(TraverseFun ) const override;

protected:

  // Auxiliary functions, if necessary!
  inline void PreOrderTraverse(TraverseFun , const Node& ) const;
  inline void PostOrderTraverse(TraverseFun , const Node& ) const;
  inline void InOrderTraverse(TraverseFun , const Node& ) const;
  
};

/* ************************************************************************** */

template <typename Data>
class MutableBinaryTree : virtual public ClearableContainer, virtual public BinaryTree<Data>, virtual public PreOrderMappableContainer<Data>, virtual public PostOrderMappableContainer<Data>, virtual public InOrderMappableContainer<Data>, virtual public BreadthMappableContainer<Data>{
  // Must extend ClearableContainer,
  //             BinaryTree<Data>,
  //             PreOrderMappableContainer<Data>,
  //             PostOrderMappableContainer<Data>,
  //             InOrderMappableContainer<Data>,
  //             BreadthMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  struct MutableNode : virtual public BinaryTree<Data>::Node {
    // Must extend Node
  
  public:
    // friend class MutableBinaryTree<Data>;
    friend class MutableBinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    // ~MutableNode() specifiers
    virtual ~MutableNode() = default;
    /* ********************************************************************** */

    // Copy assignment
    // type operator=(argument); 
    // Copy assignment of abstract types is not possible.
    MutableNode& operator=(const MutableNode& ) = delete;

    // Move assignment
    // type operator=(argument); 
    // Move assignment of abstract types is not possible.
    MutableNode& operator=(MutableNode&& ) noexcept = delete;

    /* ********************************************************************** */

    // Specific member functions

    // type Element() specifiers; 
    // Mutable access to the element (concrete function should not throw exceptions)
    virtual Data& Element() noexcept = 0;

    // type LeftChild() specifiers; 
    // (concrete function must throw std::out_of_range when not existent)
    virtual MutableNode& LeftChild() = 0;

    // type RightChild() specifiers; 
    // (concrete function must throw std::out_of_range when not existent)
    virtual MutableNode& RightChild() = 0;

  };

  /* ************************************************************************ */

  // Destructor
  // ~MutableBinaryTree() specifiers
  virtual ~MutableBinaryTree() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); 
  // Copy assignment of abstract types is not possible.
  MutableBinaryTree& operator=(const MutableBinaryTree& ) = delete;

  // Move assignment
  // type operator=(argument); 
  // Move assignment of abstract types is not possible.
  MutableBinaryTree& operator=(MutableBinaryTree&& ) noexcept = delete; 
  /* ************************************************************************ */

  // Specific member functions

  // type Root() specifiers; // (concrete function must throw std::length_error when empty)
  virtual MutableNode& Root() = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;

  // type Map(argument) specifiers; 
  // Override MappableContainer member
  inline void Map(MapFun) override; 
  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; 
  // Override PreOrderMappableContainer member
  inline void PreOrderMap(MapFun ) override;
  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; 
  // Override PostOrderMappableContainer member
  inline void PostOrderMap(MapFun ) override;
  /* ************************************************************************ */

  // Specific member function (inherited from InOrderMappableContainer)

  // type InOrderMap(arguments) specifiers; 
  // Override InOrderMappableContainer member
  inline void InOrderMap(MapFun ) override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; 
  // Override BreadthMappableContainer member
  inline void BreadthMap(MapFun ) override;

protected:

  // Auxiliary functions, if necessary!
  inline void PreOrderMap(MapFun , MutableNode& );
  inline void PostOrderMap(MapFun , MutableNode& );
  inline void InOrderMap(MapFun , MutableNode& );

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : virtual public ForwardIterator<Data> , virtual public ResettableIterator<Data>{
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  StackLst <const typename BinaryTree<Data>::Node *> stackT{};
  const typename BinaryTree<Data>::Node * depositoRadice = nullptr;


public:

  // Specific constructors
  // BTPreOrderIterator(argument) specifiers; // An iterator over a given binary tree
  BTPreOrderIterator(const BinaryTree<Data>& );

  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderIterator(argument) specifiers;
  BTPreOrderIterator(const BTPreOrderIterator<Data>& );

  // Move constructor
  // BTPreOrderIterator(argument) specifiers;
  BTPreOrderIterator(BTPreOrderIterator<Data>&& ) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderIterator() specifiers;
  virtual ~BTPreOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPreOrderIterator<Data>& operator=(const BTPreOrderIterator<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTPreOrderIterator<Data>& operator=(BTPreOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const BTPreOrderIterator<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTPreOrderIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  inline const Data& operator*() const override;

  // type Terminated() specifiers; // (should not throw exceptions)
  inline bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  BTPreOrderIterator<Data>& operator++() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTPreOrderIterator<Data> { 
  // Must extend MutableIterator<Data>,
  //             BTPreOrderIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTPreOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  BTPreOrderMutableIterator(const BinaryTree<Data>& );
  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderMutableIterator(argument) specifiers;
  BTPreOrderMutableIterator(const BTPreOrderMutableIterator<Data>& );

  // Move constructor
  // BTPreOrderMutableIterator(argument) specifiers;
  BTPreOrderMutableIterator(BTPreOrderMutableIterator<Data>&& ) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderMutableIterator() specifiers;
  virtual ~BTPreOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPreOrderMutableIterator<Data>& operator=(const BTPreOrderMutableIterator<Data>& );

  // Move assignment
  // type operator=(argument) specifiers;
  BTPreOrderMutableIterator<Data>& operator=(BTPreOrderMutableIterator<Data>&&) noexcept;


  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const BTPreOrderMutableIterator<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTPreOrderMutableIterator<Data>&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  inline Data& operator*() override;

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data> {
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...
  StackLst <const typename BinaryTree<Data>::Node *> stackT{};
  const typename BinaryTree<Data>::Node * depositoRadice = nullptr;

public:

  // Specific constructors
  // BTPostOrderIterator(argument) specifiers; // An iterator over a given binary tree
  BTPostOrderIterator(const BinaryTree<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderIterator(argument) specifiers;
  BTPostOrderIterator(const BTPostOrderIterator<Data>&);

  // Move constructor
  // BTPostOrderIterator(argument) specifiers;
  BTPostOrderIterator(BTPostOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderIterator() specifiers;
  virtual ~BTPostOrderIterator() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPostOrderIterator& operator=(const BTPostOrderIterator<Data>& );
  // Move assignment
  // type operator=(argument) specifiers;
  BTPostOrderIterator& operator=(BTPostOrderIterator<Data>&& ) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BTPostOrderIterator<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const BTPostOrderIterator<Data>&) const noexcept;
  /* ************************************************************s************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  inline const Data& operator*() const override;
  // type Terminated() specifiers; // (should not throw exceptions)
  inline bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  BTPostOrderIterator<Data>& operator++() override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept override;

protected:

  void visitaPost(const typename BinaryTree<Data>::Node *) noexcept;


};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTPostOrderIterator<Data> {
  // Must extend MutableIterator<Data>,
  //             BTPostOrderIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTPostOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  BTPostOrderMutableIterator(const BinaryTree<Data>& );
  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderMutableIterator(argument) specifiers;
  BTPostOrderMutableIterator(const BTPostOrderMutableIterator<Data>& );

  // Move constructor
  // BTPostOrderMutableIterator(argument) specifiers;
  BTPostOrderMutableIterator(BTPostOrderMutableIterator<Data>&& ) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderMutableIterator() specifiers;
  virtual ~BTPostOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPostOrderMutableIterator<Data>& operator=(const BTPostOrderMutableIterator<Data>& );

  // Move assignment
  // type operator=(argument) specifiers;
  BTPostOrderMutableIterator<Data>& operator=(BTPostOrderMutableIterator<Data>&&) noexcept;


  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const BTPostOrderMutableIterator<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTPostOrderMutableIterator<Data>&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  inline Data& operator*() override;

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>{
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...
  StackLst <const typename BinaryTree<Data>::Node *> stackT{};
  const typename BinaryTree<Data>::Node * depositoRadice = nullptr;

public:

  // Specific constructors
  // BTInOrderIterator(argument) specifiers; // An iterator over a given binary tree
  inline BTInOrderIterator(const BinaryTree<Data>&);
  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderIterator(argument) specifiers;
  inline BTInOrderIterator(const BTInOrderIterator&);

  // Move constructor
  // BTInOrderIterator(argument) specifiers;
  inline BTInOrderIterator(BTInOrderIterator&&) noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderIterator() specifiers;
  virtual ~BTInOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  inline BTInOrderIterator& operator=(const BTInOrderIterator&);

  // Move assignment
  // type operator=(argument) specifiers;
  inline BTInOrderIterator& operator=(BTInOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const BTInOrderIterator&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTInOrderIterator&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  inline const Data& operator*() const override;

  // type Terminated() specifiers; // (should not throw exceptions)
  inline bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  inline BTInOrderIterator& operator++() override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept override;

protected:
  void visitaIn(const typename BinaryTree<Data>::Node *) noexcept;

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTInOrderIterator<Data>{
  // Must extend MutableIterator<Data>,
  //             BTInOrderIterator<Data>

private:

  // ...

protected:

  // ...


public:

  // Specific constructors
  // BTInOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  BTInOrderMutableIterator(const BinaryTree<Data>& );
  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderMutableIterator(argument) specifiers;
  BTInOrderMutableIterator(const BTInOrderMutableIterator<Data>& );

  // Move constructor
  // BTInOrderMutableIterator(argument) specifiers;
  BTInOrderMutableIterator(BTInOrderMutableIterator<Data>&& ) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderMutableIterator() specifiers;
  virtual ~BTInOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTInOrderMutableIterator<Data>& operator=(const BTInOrderMutableIterator<Data>& );

  // Move assignment
  // type operator=(argument) specifiers;
  BTInOrderMutableIterator<Data>& operator=(BTInOrderMutableIterator<Data>&&) noexcept;


  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const BTInOrderMutableIterator<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTInOrderMutableIterator<Data>&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  inline Data& operator*() override;

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>{
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...
  QueueLst <const typename BinaryTree<Data>::Node *> codaT{};
  const typename BinaryTree<Data>::Node * depositoRadice = nullptr;

public:

  // Specific constructors
  // BTInOrderIterator(argument) specifiers; // An iterator over a given binary tree
  inline BTBreadthIterator(const BinaryTree<Data>&);
  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthIterator(argument) specifiers;
  inline BTBreadthIterator(const BTBreadthIterator&);

  // Move constructor
  // BTBreadthIterator(argument) specifiers;
  inline BTBreadthIterator(BTBreadthIterator&&) noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthIterator() specifiers;
  virtual ~BTBreadthIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  inline BTBreadthIterator& operator=(const BTBreadthIterator&);

  // Move assignment
  // type operator=(argument) specifiers;
  inline BTBreadthIterator& operator=(BTBreadthIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const BTBreadthIterator&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTBreadthIterator&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  inline const Data& operator*() const override;

  // type Terminated() specifiers; // (should not throw exceptions)
  inline bool Terminated() const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  inline BTBreadthIterator& operator++() override;
  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept override;
};

/* ************************************************************************** */

template <typename Data>
class BTBreadthMutableIterator : virtual public MutableIterator<Data>, virtual public BTBreadthIterator<Data>{
  // Must extend MutableIterator<Data>,
  //             BTBreadthIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTBreadthMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree
  BTBreadthMutableIterator(const BinaryTree<Data>& );
  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthMutableIterator(argument) specifiers;
  BTBreadthMutableIterator(const BTBreadthMutableIterator<Data>& );

  // Move constructor
  // BTBreadthMutableIterator(argument) specifiers;
  BTBreadthMutableIterator(BTBreadthMutableIterator<Data>&& ) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthMutableIterator() specifiers;
  virtual ~BTBreadthMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTBreadthMutableIterator<Data>& operator=(const BTBreadthMutableIterator<Data>& );

  // Move assignment
  // type operator=(argument) specifiers;
  BTBreadthMutableIterator<Data>& operator=(BTBreadthMutableIterator<Data>&&) noexcept;


  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const BTBreadthMutableIterator<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const BTBreadthMutableIterator<Data>&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  inline Data& operator*() override;

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
