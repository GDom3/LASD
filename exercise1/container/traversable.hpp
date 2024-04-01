
#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TraversableContainer : protected TestableContainer<Data>  {
  // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...
  TraversableContainer() = default;

public:

  // Destructor
  // ~TraversableContainer() specifiers
  ~TraversableContainer() = default;
  
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  virtual ConTraversableContainertainer& operator=(const TraversableContainer & daCopiare);
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  virtual ContTraversableContainerainer& operator=(const TraversableContainer && daSpostare) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  virtual bool operator==(const TraversableContainer & daConfrontare) const;
  // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.
  virtual bool operator!=(const TraversableContainer & daConfrontare) const;
  /* ************************************************************************ */

  // Specific member function

  // using TraverseFun = std::function<void(const Data &)>;

  // type Traverse(arguments) specifiers;

  // template <typename Accumulator>
  // using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;

  // template <typename Accumulator>
  // type Fold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PreOrderTraversableContainer : protected TraversableContainer<Data>{
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~PreOrderTraversableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  // using typename TraversableContainer<Data>::TraverseFun;

  // type PreOrderTraverse(arguments) specifiers;

  // template <typename Accumulator>
  // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  // template <typename Accumulator>
  // type PreOrderFold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // type Traverse(arguments) specifiers; // Override TraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderTraversableContainer : protected TraversableContainer<Data>{
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~PostOrderTraversableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  // using typename TraversableContainer<Data>::TraverseFun;

  // type PostOrderTraverse(arguments) specifiers;

  // template <typename Accumulator>
  // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  // template <typename Accumulator>
  // type PostOrderFold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // type Traverse(arguments) specifiers; // Override TraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class InOrderTraversableContainer : protected TraversableContainer<Data>{
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~InOrderTraversableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  // using typename TraversableContainer<Data>::TraverseFun;

  // type InOrderTraverse(arguments) specifiers;

  // template <typename Accumulator>
  // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  // template <typename Accumulator>
  // type InOrderFold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // type Traverse(arguments) specifiers; // Override TraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class BreadthTraversableContainer : protected TraversableContainer<Data>{
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthTraversableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  // using typename TraversableContainer<Data>::TraverseFun;

  // type BreadthTraverse(arguments) specifiers;

  // template <typename Accumulator>
  // using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  // template <typename Accumulator>
  // type BreadthFold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // type Traverse(arguments) specifiers; // Override TraversableContainer member

};

/* ************************************************************************** */

}

#include "traversable.cpp"

#endif
