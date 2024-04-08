
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "traversable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MappableContainer : virtual protected TraversableContainer<Data>{
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~MappableContainer() specifiers
  virtual ~MappableContainer() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  MappableContainer& operator=(const MappableContainer &) = delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  MappableContainer& operator=(MappableContainer &&) noexcept = delete;


  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const MappableContainer &) const = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const MappableContainer &) const = delete; 
  /* ************************************************************************ */

  // Specific member function

  // using MapFun = std::function<void(Data &)>;
  using MapFun = std::function<void(Data &)>;


  // type Map(argument) specifiers;
  virtual void Map(MapFun) = 0;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer : virtual protected MappableContainer<Data>, virtual protected PreOrderTraversableContainer<Data>{
  // Must extend MappableContainer<Data>,
  //             PreOrderTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~PreOrderMappableContainer() specifiers
  virtual ~PreOrderMappableContainer() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  PreOrderMappableContainer& operator=(const PreOrderMappableContainer &) = delete;

 
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  PreOrderMappableContainer& operator=(PreOrderMappableContainer &&) noexcept = delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const PreOrderMappableContainer &) const = delete;
  bool operator!=(const PreOrderMappableContainer &) const = delete;

  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;

  // type PreOrderMap(argument) specifiers;
  virtual void PreOrderMap(MapFun) = 0;
  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
  virtual void Map(MapFun) override;

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer : virtual protected MappableContainer<Data>, virtual protected PostOrderTraversableContainer<Data>{
  // Must extend MappableContainer<Data>,
  //             PostOrderTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~PostOrderMappableContainer() specifiers
  virtual ~PostOrderMappableContainer() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  PostOrderMappableContainer& operator=(const PostOrderMappableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  PostOrderMappableContainer& operator=(PostOrderMappableContainer &&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const PostOrderMappableContainer &) const = delete;
  bool operator!=(const PostOrderMappableContainer &) const = delete; 
  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;
  // type PostOrderMap(argument) specifiers;
  virtual void PostOrderMap(MapFun) = 0;
  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
  virtual void Map(MapFun) override;
};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer: virtual protected MappableContainer<Data>, virtual protected InOrderTraversableContainer<Data>{
  // Must extend MappableContainer<Data>,
  //             InOrderTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~InOrderMappableContainer() specifiers
  virtual ~InOrderMappableContainer() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  InOrderMappableContainer& operator=(const InOrderMappableContainer &) = delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  InOrderMappableContainer& operator=(InOrderMappableContainer &&) noexcept = delete;



  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const InOrderMappableContainer &) const = delete;
  bool operator!=(const InOrderMappableContainer &) const = delete; 
  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;
  // type InOrderMap(argument) specifiers;
  virtual void InOrderMap(MapFun) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
  virtual void Map(MapFun) override;
};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer : virtual protected MappableContainer<Data>, virtual protected BreadthTraversableContainer<Data>{
  // Must extend MappableContainer<Data>,
  //             BreadthTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthMappableContainer() specifiers
  virtual ~BreadthMappableContainer() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  BreadthMappableContainer& operator=(const BreadthMappableContainer &) = delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  BreadthMappableContainer& operator=(BreadthMappableContainer &&) noexcept = delete;


  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const BreadthMappableContainer &) const = delete;
  bool operator!=(const BreadthMappableContainer &) const = delete; 

  /* ************************************************************************ */

  // Specific member function

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;
  // type BreadthMap(argument) specifiers;
  virtual void BreadthMap(MapFun) = 0;
  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
  virtual void Map(MapFun) override;
};

/* ************************************************************************** */

}

#include "mappable.cpp"

#endif
