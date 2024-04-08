
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer : virtual protected PreOrderMappableContainer, virtual protected PostOrderMappableContainer{
  // Must extend PreOrderMappableContainer<Data>,
  //             PostOrderMappableContainer<Data>

private:

protected:


  using Container::size;


public:

  // Destructor
  // ~LinearContainer() specifiers
  virtual ~LinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  LinearContainer& operator=(const LinearContainer & daCopiare) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  LinearContainer& operator=(LinearContainer && daCopiare) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is possible.
  bool operator==(const LinearContainer&) const noexcept;
  // type operator!=(argument) specifiers; // Comparison of abstract types is possible.
  bool operator!=(const LinearContainer&) const noexcept;
  
  /* ************************************************************************ */

  // Specific member functions

  // type operator[](argument) specifiers; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
  // type operator[](argument) specifiers; // (mutable version; concrete function must throw std::out_of_range when out of range)
  virtual const Data & operator[](unsigned long) const = 0;
  virtual Data & operator[](unsigned long) = 0;


  // type Front() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  // type Front() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
  inline virtual const Data& Front() const;
  inline virtual Data& Front();
 
  // type Back() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  // type Back() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
  inline virtual const Data& Back() const;
  inline virtual Data& Back();
  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // using typename TraversableContainer<Data>::TraverseFun;
  using typename TraversableContainer<Data>::TraverseFun;

  // type Traverse(argument) specifiers; // Override TraversableContainer member
  inline void Traverse(TraverseFun) const noexcept;
  
  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  // type PreOrderTraverse(argument) specifiers; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  // type PostOrderTraverse(argument) specifiers; // Override PostOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFun;

  // type Map(argument) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class SortableLinearContainer {
  // Must extend LinearContainer<Data>

private:

  // ...

protected:

  

public:

  // Destructor
  // ~SortableLinearContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is possible.

  /* ************************************************************************ */

  // Specific member function

  // type Sort() specifiers;
  virtual void Sort() noexcept;


protected:

  // Auxiliary member functions
  // qui va  il sort
  // ...

};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif
