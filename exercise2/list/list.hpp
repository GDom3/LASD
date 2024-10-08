
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"
#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public ClearableContainer, virtual public LinearContainer<Data>, virtual public DictionaryContainer<Data>{
  // Must extend ClearableContainer,
  //             LinearContainer<Data>,
  //             DictionaryContainer<Data>

private:

  // ...

protected:

  // using Container::???;
  using Container::size;
  
  struct Node {

    // Data
    // ...
    Data elemento{};
    Node * next = nullptr;

    /* ********************************************************************** */

    // Specific constructors
    // ...
    inline Node() = default; 
    /* ********************************************************************** */

    // Copy constructor
    // ...
    inline Node(const Data& dato) : elemento{dato} {}

    // Move constructor
    // ...
    inline Node(Data&& dato) noexcept{
      std::swap(elemento,dato);
    }

    /* ********************************************************************** */

    // Destructor
    // ...
    ~Node() {
      delete next;
    }
    /* ********************************************************************** */

    // Comparison operators
    // ...
    inline bool operator==(const Node & nodo) const noexcept{
      return elemento == nodo.elemento;
    }
    inline bool operator!=(const Node & nodo) const noexcept{
      return !operator==(nodo);
    }

    /* ********************************************************************** */

    // Specific member functions

    // ...

  };

  // ...

  Node * head = nullptr;
  Node * tail = nullptr;

public:

  // Default constructor
  // List() specifiers;
  List() = default;
  /* ************************************************************************ */

  // Specific constructor
  // List(argument) specifiers; // A list obtained from a TraversableContainer
  List(const TraversableContainer<Data> & );
  // List(argument) specifiers; // A list obtained from a MappableContainer
  List(MappableContainer<Data> && );
  /* ************************************************************************ */

  // Copy constructor
  // List(argument) specifiers;
  List(const List & );
  // Move constructor
  // List(argument) specifiers;
  List (List && );

  /* ************************************************************************ */

  // Destructor
  // ~List() specifiers;
  ~List();
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  inline List& operator=(const List &);

  // Move assignment
  // type operator=(argument) specifiers;
  inline List& operator=(List &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const List &) const noexcept;
  // type operator!=(argument) specifiers;
  bool inline operator!=(const List &) const noexcept;
  /* ************************************************************************ */

  // Specific member functions

  // type InsertAtFront(argument) specifier; // Copy of the value
  void InsertAtFront(const Data&);

  // type InsertAtFront(argument) specifier; // Move of the value
  void InsertAtFront(Data&&);

  // type RemoveFromFront() specifier; // (must throw std::length_error when empty)
  void RemoveFromFront();
  // type FrontNRemove() specifier; // (must throw std::length_error when empty)
  Data FrontNRemove();

  // type InsertAtBack(argument) specifier; // Copy of the value
  void InsertAtBack(const Data&);
  // type InsertAtBack(argument) specifier; // Move of the value
  void InsertAtBack(Data&&);
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifier; // Copy of the value
  inline bool Insert(const Data &) override;
  // type Insert(argument) specifier; // Move of the value
  inline bool Insert(Data &&) override;
  // type Remove(argument) specifier;
  bool Remove(const Data &) override;
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


  /* ************************************************************************ */


  using typename TraversableContainer<Data>::TraverseFun;

  // type Traverse(argument) specifiers; // Override TraversableContainer member
  inline void Traverse(TraverseFun) const override;
  
  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  // type PreOrderTraverse(argument) specifiers; // Override PreOrderTraversableContainer member
  
  inline void PreOrderTraverse(TraverseFun ) const override;
 
  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  // type PostOrderTraverse(argument) specifiers; // Override PostOrderTraversableContainer member  
  inline void PostOrderTraverse(TraverseFun ) const override;
  
  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;

  // type Map(argument) specifiers; // Override MappableContainer member
  inline void Map(MapFun) override;
  
  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member
  inline void PreOrderMap(MapFun ) override;
  
  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member
  inline void PostOrderMap(MapFun ) override;
  
  /* ************************************************************************ */

  //Doppio uso : ambigua

  using TestableContainer<Data>::Exists;

  inline void Stampa() const noexcept;

protected:
  inline void PreOrderTraverse(TraverseFun,Node* ) const ;
  inline void PostOrderTraverse(TraverseFun,Node* ) const ;
  inline void PreOrderMap(MapFun ,Node*);
  inline void PostOrderMap(MapFun ,Node*);
};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
