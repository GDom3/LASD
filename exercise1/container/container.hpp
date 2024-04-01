
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
  virtual Container& operator=(const Container & daCopiare);
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  virtual Container& operator=(const Container && daSpostare) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  virtual bool operator==(const Container & daConfrontare) const;

  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  virtual bool operator!=(const Container & daConfrontare) const;


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
  virtual ClearableContainer& operator=(const ClearableContainer & daCopiare);

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  virtual ClearableContainer& operator=(const ClearableContainer && daSpostare) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  virtual bool operator==(const ClearableContainer & daConfrontare) const;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  virtual bool operator!=(const ClearableContainer & daConfrontare) const;
  /* ************************************************************************ */

  // Specific member functions

  // type Clear() specifiers;
  virtual void Clear();
   

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
  virtual ResizableContainer& operator=(const ResizableContainer & daCopiare);
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  virtual ResizableContainer& operator=(const ResizableContainer && daSpostare) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  virtual bool operator==(const ResizableContainer & daConfrontare) const;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  virtual bool operator!=(const ResizableContainer & daConfrontare) const;
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
    size = 0;
  }

};

/* ************************************************************************** */

}

#endif
