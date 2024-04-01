
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  // ...
  unsigned long size = 0;


  /* ************************************************************************ */
  
  // Default constructor
  // Container() specifiers;
  Container() = default;


public:

  // Destructor
  // ~Container() specifiers 
  ~Container() = default;
 
 /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Empty() specifiers; // (concrete function should not throw exceptions)
  bool Empty() const noexcept{
    return size == 0;
  }

  // type Size() specifiers; // (concrete function should not throw exceptions)
  unsigned long Size() const noexcept{
    return size;
  }

};

/* ************************************************************************** */

class ClearableContainer : protected Container {
  // Must extend Container

private:

  // ...

protected:

  // ...
  ClearableContainer() = default;
public:

  // Destructor
  // ~ClearableContainer() specifiers
  ~ClearableContainer() = default;
 
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Clear() specifiers;
  void virtual Clear();
   

};

/* ************************************************************************** */

class ResizableContainer: protected ClearableContainer{
  // Must extend ClearableContainer

private:

  // ...

protected:

  // ...
  ResizableContainer() = default;

public:

  // Destructor
  // ~ResizableContainer() specifiers
  ~ResizableContainer() = default;
  
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Resize(argument) specifiers;
   void virtual Resize (unsigned long const &newSize) {
    size = newSize;
  }

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
   void virtual Clear() override{
    size = 0;
  }

};

/* ************************************************************************** */

}

#endif
