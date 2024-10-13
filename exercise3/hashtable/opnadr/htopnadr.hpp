
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...
#include "../../vector/vector.hpp"

//Usa potenze di 2
#define TASSO_RIDUZIONE 2
#define TASSO_ESPANZIONE 2

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data>{
  // Must extend HashTable<Data>

private:

  // ...

protected:

  // using HashTable<Data>::???;
  using HashTable<Data>::size;
  using HashTable<Data>::numeroCelle;
  using HashTable<Data>::HashKey;
  // ...

  struct Cella {

    public:
      Data elemento{};
      bool usato = false; 
      //bool deleted = false; 
      bool vuoto = true;  

      
      bool operator==(const Cella& h ) const noexcept{ 
        if(vuoto){
          return h.vuoto;
        }else if(!h.vuoto){
          return elemento == h.elemento;
        }else{
          return false;
        }
      }
    
      inline bool operator!=(const Cella& h ) const noexcept{return !operator==(h);}
   
  
  };

  Vector<Cella> hashtable{};


public:

  // Default constructor
  // HashTableOpnAdr() specifiers;
  HashTableOpnAdr();
  
  /* ************************************************************************ */

  // Specific constructors
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size
  HashTableOpnAdr(const unsigned long&);
  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a TraversableContainer
  HashTableOpnAdr(const TraversableContainer<Data>&);
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a TraversableContainer
  HashTableOpnAdr(const unsigned long& , const TraversableContainer<Data>&);
  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a MappableContainer
  HashTableOpnAdr(MappableContainer<Data>&&) noexcept;
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a MappableContainer
  HashTableOpnAdr(const unsigned long& , MappableContainer<Data>&&) noexcept;

  /* ************************************************************************ */

  // Copy constructor
  // HashTableOpnAdr(argument) specifiers;
  HashTableOpnAdr(const HashTableOpnAdr&);

  // Move constructor
  // HashTableOpnAdr(argument) specifiers;
  HashTableOpnAdr(HashTableOpnAdr&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~HashTableOpnAdr() specifiers;
  ~HashTableOpnAdr();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  HashTableOpnAdr& operator=(const HashTableOpnAdr&);
  // Move assignment
  // type operator=(argument) specifiers;
  HashTableOpnAdr& operator=(HashTableOpnAdr&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const HashTableOpnAdr&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const HashTableOpnAdr&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  bool Insert(const Data &) override;
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  bool Insert(Data &&) override;
  // type Remove(argument) specifiers; // Override DictionaryContainer member
  bool Remove(const Data &) override;

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



  void Stampa();

protected:

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
  const unsigned long DoppioHashing(const Data& , const unsigned long& , const unsigned long& ) const;
  // type Find(argument) specifiers;
  const unsigned long Find(const Data& ) const;
  // type FindEmpty(argument) specifiers;
  const unsigned long FindEmpty(const Data& ) const;
  // type Remove(argument) specifiers;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
