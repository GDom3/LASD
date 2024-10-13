
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...
#include "../../vector/vector.hpp"
#include "../../bst/bst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr : virtual public HashTable<Data> {
  // Must extend HashTable<Data>

private:

  // ...

protected:

  // using HashTable<Data>::???;
  using HashTable<Data>::size;
  using HashTable<Data>::numeroCelle;
  using HashTable<Data>::HashKey;

  Vector<BST<Data> *> hashtable{};

  // ...

public:

  // Default constructor
  // HashTableClsAdr() specifiers;
  HashTableClsAdr();
  
  /* ************************************************************************ */

  // Specific constructors
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size
  HashTableClsAdr(const unsigned long& );
  // HashTableClsAdr(argument) specifiers; // A hash table obtained from a TraversableContainer
  HashTableClsAdr(const TraversableContainer<Data>& );
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a TraversableContainer
  HashTableClsAdr(const unsigned long& , const TraversableContainer<Data>& );
  // HashTableClsAdr(argument) specifiers; // A hash table obtained from a MappableContainer
  HashTableClsAdr(MappableContainer<Data>&& ) noexcept;
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a MappableContainer
  HashTableClsAdr(const unsigned long& , MappableContainer<Data>&& ) noexcept;
  /* ************************************************************************ */

  // Copy constructor
  // HashTableClsAdr(argument) specifiers;
  HashTableClsAdr(const HashTableClsAdr<Data>&);

  // Move constructor
  // HashTableClsAdr(argument) specifiers;
  HashTableClsAdr(HashTableClsAdr<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~HashTableClsAdr() specifiers;
  ~HashTableClsAdr();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  HashTableClsAdr& operator=(const HashTableClsAdr<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  HashTableClsAdr& operator=(HashTableClsAdr<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const HashTableClsAdr<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const HashTableClsAdr<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  inline bool Insert(const Data &) override;
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  inline bool Insert(Data &&) override;
  // type Remove(argument) specifiers; // Override DictionaryContainer member
  inline bool Remove(const Data &) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  inline bool Exists(const Data&) const noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  // type Resize(argument) specifiers; // Resize the hashtable to a given size
  void Resize (const unsigned long) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  // type Clear() specifiers; // Override Container member
  void Clear() override;

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
