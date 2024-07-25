
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

#define GRANDEZZA_INIZIALE 16
#define TASSO_RIDUZIONE 2
#define TASSO_Espanzione 2

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
  using Container::size;
  
  
  unsigned long int ultimo = 0;

  

  // ...

public:

  // Default constructor
  // StackVec() specifier;
  StackVec(): Vector<Data>::Vector(GRANDEZZA_INIZIALE){std::cout<<"\nArrivato\n";};
  
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
  StackVec(StackVec && ) noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~StackVec() specifier;
  virtual ~StackVec() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  StackVec& operator=(const StackVec &);

  // Move assignment
  // type operator=(argument);
  StackVec& operator=(StackVec && stklist) noexcept;
  
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const StackVec &) const noexcept;
  // type operator!=(argument) specifiers;
  bool inline operator!=(const StackVec &) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  // type Top() specifiers; 
  // Override Stack member (non-mutable version; must throw std::length_error when empty)
  inline const Data& Top() const override;
  
  // type Top() specifiers; 
  // Override Stack member (non-mutable version; must throw std::length_error when empty)
  inline Data& Top() override;
  
  // type Pop() specifiers; 
  // Override Stack member (must throw std::length_error when empty)
  inline void Pop() override;
  
  // type TopNPop() specifiers; 
  // Override Stack member (must throw std::length_error when empty)
  inline Data TopNPop() override;
  
  // type Push(argument) specifiers; 
  // Override Stack member (copy of the value)
  inline void Push(const Data&) override;
  
  // type Push(argument) specifiers; 
  // Override Stack member (move of the value)
  inline void Push(Data&&) override;
  
  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; 
  // Override Container member
  inline virtual bool Empty() const noexcept override{
    return ultimo==0;
  }

  // type Size() specifiers; 
  // Override Container member
  inline virtual unsigned long Size() const noexcept override{
    return ultimo;
  }
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; 
  // Override ClearableContainer member
  void Clear() override;

  inline void Resize(unsigned long int ) override;

protected:

  // Auxiliary functions, if necessary!
  //void Espandi();
  //void Riduci();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
