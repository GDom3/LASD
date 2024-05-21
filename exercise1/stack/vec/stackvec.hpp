
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : virtual public Stack<Data>, virtual protected Vector<Data> {
  // Must extend Stack<Data>,
  //             Vector<Data>

private:

  // ...

protected:

  // using Vector<Data>::???;
  using Vector<Data>::elementi;
  using Vector<Data>::size;
  
  
  unsigned long int ultimo = 0;

  float indiceResizePush = 1.5;
  float indiceResizePop = 2;
  // ...

public:

  // Default constructor
  // StackVec() specifier;
  StackVec() = default;
  /* ************************************************************************ */

  // Specific constructor
  // StackVec(argument) specifiers; // A stack obtained from a TraversableContainer
  StackVec(const TraversableContainer<Data> & );
  // StackVec(argument) specifiers; // A stack obtained from a MappableContainer
  StackVec(MappableContainer<Data> && );
  /* ************************************************************************ */

  // Copy constructor
  // StackVec(argument);
  StackVec(const StackVec & );
  // Move constructor
  // StackVec(argument);
  StackVec(StackVec && );
  /* ************************************************************************ */

  // Destructor
  // ~StackVec() specifier;
  ~StackVec();
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  StackVec& operator=(const StackVec &);
  // Move assignment
  // type operator=(argument);
  StackVec& operator=(StackVec && stklist);
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const StackVec &) const noexcept;
  // type operator!=(argument) specifiers;
  bool inline operator!=(const StackVec &) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  const Data& Top() const override;
  // type Top() specifiers; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  Data& Top() override;
  // type Pop() specifiers; // Override Stack member (must throw std::length_error when empty)
  void Pop() override;
  // type TopNPop() specifiers; // Override Stack member (must throw std::length_error when empty)
  Data TopNPop() override;
  // type Push(argument) specifiers; // Override Stack member (copy of the value)
  void Push(const Data&) override;
  // type Push(argument) specifiers; // Override Stack member (move of the value)
  void Push(Data&&) override;
  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member
  inline virtual bool Empty() const noexcept{
    return size==0?true:ultimo==0;
  }
  // type Size() specifiers; // Override Container member
  inline virtual unsigned long Size() const noexcept{
    return size==0?0:ultimo;
  }
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear();

protected:

  // Auxiliary functions, if necessary!
  void Espandi();
  void Riduci();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
