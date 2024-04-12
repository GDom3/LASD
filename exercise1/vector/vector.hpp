
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : public ResizableContainer , public LinearContainer<Data>{
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
  // Vector(argument) specifiers; // A vector with a given initial dimension
  Vector(const unsigned long & num ){
    if(num != 0)
      elementi = new Data[num];

  }
  // Vector(argument) specifiers; // A vector obtained from a TraversableContainer
  Vector(const TraversableContainer<Data> &struttura ){
    Container::size = struttura.size;
    elementi = new Data[Container::size];
    unsigned long int i = 0;
    struttura.Traverse(
      [elementi,&i](const Data & dato){
          elementi[i++] = dato;
      }

    );

  }

  // Vector(argument) specifiers; // A vector obtained from a MappableContainer
  Vector(MappableContainer<Data> &struttura ){
    Container::size = struttura.size;
    elementi = new Data[Container::size];
    unsigned long int i = 0;
    struttura.Traverse(
      [elementi,&i](const Data & dato){
          elementi[i++] = dato;
      }

    );

  }
  /* ************************************************************************ */

  // Copy constructor
  // Vector(argument) specifiers;
  Vector(const Vector & vet){
      Container::size = vet.size;
      elementi = new Data[Container::size];

      for (unsigned long int i = 0; i < vet.size; i++)
        elementi[i] = vet[i];
      
  }
  // Move constructor
  // Vector(argument) specifiers;
  Vector (Vector && vet){
    elementi = std::move(vet.elementi);
    size = std::move(vet.size);
  }

  /* ************************************************************************ */

  // Destructor
  // ~Vector() specifiers;
  ~Vector(){
    if(elementi != nullptr)
      delete[] elementi;

  }
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  Vector& operator=(const Vector &);

  // Move assignment
  // type operator=(argument) specifiers;
  Vector& operator=(Vector &&);

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const Vector &) const noexcept;
  // type operator!=(argument) specifiers;
  bool inline operator!=(const Vector &) const noexcept;
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)

  // type Resize(argument) specifiers; // Override ResizableContainer member
  void Resize (const unsigned long  &) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type operator[](argument) specifiers; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  Data & operator[](const unsigned long int) const ;
  // type operator[](argument) specifiers; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)
  Data & operator[](unsigned long int);

  // type Front() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  inline const Data& Front() const;
  // type Front() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
  inline Data& Front();
  // type Back() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  inline const Data& Back() const;
  // type Back() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
  inline Data& Back();

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

template <typename Data>
class SortableVector: virtual public SortableLinearContainer<Data>, protected Vector<Data> {
  // Must extend Vector<Data>,
  //             SortableLinearContainer<Data>

private:

  // ...

protected:

  // using Container::???;
  using Container::size;
  // ...

public:

  // Default constructor
  // SortableVector() specifiers;
  SortableVector() = default; 
  /* ************************************************************************ */

  // Specific constructors
  // SortableVector(argument) specifiers; // A vector with a given initial dimension
  SortableVector(const unsigned long & num ){
    if(num != 0)
      elementi = new Data[num];

  }
  // SortableVector(argument) specifiers; // A vector obtained from a TraversableContainer
  SortableVector(const TraversableContainer<Data> &struttura ){
    Container::size = struttura.size;
    elementi = new Data[Container::size];
    unsigned long int i = 0;
    struttura.Traverse(
      [elementi,&i](const Data & dato){
          elementi[i++] = dato;
      }

    );

  }
  // SortableVector(argument) specifiers; // A vector obtained from a MappableContainer
SortableVector(MappableContainer<Data> &struttura ){
    Container::size = struttura.size;
    elementi = new Data[Container::size];
    unsigned long int i = 0;
    struttura.Traverse(
      [elementi,&i](const Data & dato){
          elementi[i++] = dato;
      }

    );

  }
  /* ************************************************************************ */

  // Copy constructor
  // SortableVector(argument) specifiers;
  SortableVector(const SortableVector & vet){
      Container::size = vet.size;
      elementi = new Data[Container::size];

      for (unsigned long int i = 0; i < vet.size; i++)
        elementi[i] = vet[i];
      
  }
  // Move constructor
  // SortableVector(argument) specifiers;
  SortableVector (SortableVector && vet){
    elementi = std::move(vet.elementi);
    size = std::move(vet.size);
  }
  /* ************************************************************************ */

  // Destructor
  // ~SortableVector() specifiers;
  ~SortableVector(){
    if(elementi != nullptr)
      delete[] elementi;

  }
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  SortableVector& operator=(const SortableVector &);

  // Move assignment
  // type operator=(argument) specifiers;
  SortableVector& operator=(SortableVector &&);

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
