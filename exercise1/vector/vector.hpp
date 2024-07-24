
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : virtual public ResizableContainer , virtual public LinearContainer<Data>{
  // Must extend ResizableContainer,
  //             LinearContainer<Data>

private:

  // ...

protected:

  // using Container::???;
  using Container::size;

  // ...
  Data * elementi = nullptr;

public:

  // Default constructor
  // Vector() specifiers;
  Vector() = default;

  /* ************************************************************************ */

  // Specific constructors
  // Vector(argument) specifiers; 
  // A vector with a given initial dimension
  Vector(const unsigned long num ){
      size = num;
      elementi = new Data[num]();
  };
  
  // Vector(argument) specifiers; 
  // A vector obtained from a TraversableContainer
  Vector(const TraversableContainer<Data> & );

  // Vector(argument) specifiers; 
  // A vector obtained from a MappableContainer
  Vector(MappableContainer<Data> && );

  /* ************************************************************************ */

  // Copy constructor
  // Vector(argument) specifiers;
  Vector(const Vector<Data> & );


  // Move constructor
  // Vector(argument) specifiers;
  Vector(Vector<Data> && ) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~Vector() specifiers;
  virtual ~Vector(){
    delete[] elementi;
  }
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  Vector<Data>& operator=(const Vector<Data> &);

  // Move assignment
  // type operator=(argument) specifiers;
  Vector<Data>& operator=(Vector<Data> &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const Vector<Data> &) const noexcept;
  // type operator!=(argument) specifiers;
  bool inline operator!=(const Vector<Data> &) const noexcept;
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  inline void Clear() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)

  // type Resize(argument) specifiers; // Override ResizableContainer member
  void Resize (unsigned long ) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type operator[](argument) specifiers; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  inline const Data & operator[](unsigned long int) const override;
  // type operator[](argument) specifiers; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)
  inline Data & operator[](unsigned long int) override;

  // type Front() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  inline const Data& Front() const override;
  // type Front() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
  inline Data& Front() override;
  // type Back() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  inline const Data& Back() const override;
  // type Back() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
  inline Data& Back() override;

  inline void Stampa() const noexcept;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

template <typename Data>
class SortableVector : virtual public Vector<Data> , virtual public SortableLinearContainer<Data> {
  // Must extend Vector<Data>,
  //             SortableLinearContainer<Data>

private:

  // ...

protected:

  // using Container::???;
  using Container::size;
  

public:

  // Default constructor
  // SortableVector() specifiers;
  SortableVector() = default; 
  /* ************************************************************************ */

  // Specific constructors
  // SortableVector(argument) specifiers; 
  // A vector with a given initial dimension
  inline SortableVector(unsigned long num ) : Vector<Data>::Vector(num){}; 

  // SortableVector(argument) specifiers; 
  // A vector obtained from a TraversableContainer
  inline SortableVector(const TraversableContainer<Data> & struttura) : Vector<Data>::Vector(struttura){};

  // SortableVector(argument) specifiers; 
  // A vector obtained from a MappableContainer
  inline SortableVector(MappableContainer<Data> && struttura) : Vector<Data>::Vector(std::move(struttura)){};

  /* ************************************************************************ */

  // Copy constructor
  // SortableVector(argument) specifiers;
  inline SortableVector(const SortableVector & vet) : Vector<Data>::Vector(vet){};
  // Move constructor
  // SortableVector(argument) specifiers;
  inline SortableVector (SortableVector && vet) noexcept : Vector<Data>::Vector(std::move(vet)){};
  /* ************************************************************************ */

  // Destructor
  // ~SortableVector() specifiers;
  virtual ~SortableVector() = default;
  /* ************************************************************************ */

  //Operatori Di Confronto
  bool operator==(const SortableVector &) const noexcept;
  bool operator!=(const SortableVector &) const noexcept;


  // Copy assignment
  // type operator=(argument) specifiers;
  inline SortableVector<Data>& operator=(const SortableVector<Data> &);

  // Move assignment
  // type operator=(argument) specifiers;
  inline SortableVector<Data>& operator=(SortableVector<Data> &&) noexcept;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
