
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>
#include <cmath>


/* ************************************************************************** */

#include "../container/dictionary.hpp"

#define GRANDEZZA_INIZIALE 16

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  // type operator()(argument) specifiers; // (concrete function should not throw exceptions)
  virtual double operator()(const Data& ) const noexcept = 0;

  virtual double hashDue(const Data& ) const noexcept = 0;

};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public ResizableContainer, virtual public DictionaryContainer<Data>{
                  // Must extend ResizableContainer,
                  //             DictionaryContainer<Data>

private:

  // ...

protected:

  // using DictionaryContainer<Data>::???;
  using DictionaryContainer<Data>::size;

  unsigned long numeroCelle{};

  // ...

public:

  // Destructor
  // ~HashTable() specifiers
  virtual ~HashTable() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  HashTable& operator=(const HashTable&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  HashTable& operator=(HashTable&&) noexcept = delete;
  
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract hashtable is possible but not required.
  bool operator==(const HashTable&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract hashtable is possible but not required.
  bool operator!=(const HashTable&) const noexcept = delete;

protected:

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
  virtual unsigned long HashKey(const Data& dato) const{
    Hashable<Data> hash{};
    return hash(dato) * numeroCelle;
  }

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
