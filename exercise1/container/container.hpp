
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

protected:

  unsigned long size = 0;

public:

  // Destructor
  ~Container() = default;
 
 /* ************************************************************************ */

  // Copy assignment
  Container& operator=(const Container &) = delete; // Non è ancora possibile
 
  // Move assignment
  Container& operator=(Container &&) noexcept = delete; // Non ancora possibile

  /* ************************************************************************ */

  // Comparison operators (Non ancora possibili)
  bool operator==(const Container &) const noexcept = delete;
  bool operator!=(const Container &) const noexcept = delete;


  /* ************************************************************************ */

  // Specific member functions

  // type Empty() specifiers; // (concrete function should not throw exceptions)
  inline virtual bool Empty() const noexcept{
    return size == 0;
  }

  // type Size() specifiers; // (concrete function should not throw exceptions)
  inline virtual unsigned long Size() const noexcept{
    return size;
  }

};

/* ************************************************************************** */

class ClearableContainer : virtual protected Container {
  // Must extend Container

private:

protected:

public:

  // Destructor
  // ~ClearableContainer() specifiers
  ~ClearableContainer() = default;
 
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  ClearableContainer& operator=(const ClearableContainer &) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  ClearableContainer& operator=(const ClearableContainer &&) noexcept = delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const ClearableContainer &) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const ClearableContainer &) const noexcept = delete;
  /* ************************************************************************ */

  // Specific member functions

  // type Clear() specifiers;
  virtual void Clear() = 0; // virtual puro (l'erede deve definirlo)
   

};

/* ************************************************************************** */

class ResizableContainer: virtual protected ClearableContainer{
  // Must extend ClearableContainer

private:

  // ...

protected:

public:

  // Destructor
  // ~ResizableContainer() specifiers
  ~ResizableContainer() = default;
  
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  ResizableContainer& operator=(const ResizableContainer &) = delete;
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  ResizableContainer& operator=(const ResizableContainer &&) noexcept = delete;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator==(const ResizableContainer &) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  bool operator!=(const ResizableContainer &) const noexcept = delete;
  /* ************************************************************************ */

  // Specific member functions

  // type Resize(argument) specifiers;
  virtual void Resize (const unsigned long  &newSize) {
    size = newSize;
  }

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  virtual void Clear() override{
    size = 0; // Resize(0)
  }

};

/* ************************************************************************** */

}

#endif
