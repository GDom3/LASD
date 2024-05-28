
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : virtual public Queue<Data>, virtual protected Vector<Data>{
  // Must extend Queue<Data>,
  //             Vector<Data>

private:

  // ...

protected:

  // using Vector<Data>::???;
  using Vector<Data>::elementi;
  using Vector<Data>::size;
  
  
  unsigned long int testa = 0;
  unsigned long int coda = 0;


public:

  // Default constructor
  // QueueVec() specifier;
  QueueVec() = default;
  /* ************************************************************************ */

  // Specific constructor
  // QueueVec(argument) specifiers; // A stack obtained from a TraversableContainer
  QueueVec(const TraversableContainer<Data> & );
  // QueueVec(argument) specifiers; // A stack obtained from a MappableContainer
  QueueVec(MappableContainer<Data> && );

  /* ************************************************************************ */

  // Copy constructor
  // QueueVec(argument);
  QueueVec(const QueueVec & );

  // Move constructor
  // QueueVec(argument);
  QueueVec(QueueVec && );
  /* ************************************************************************ */

  // Destructor
  // ~QueueVec() specifier;
  ~QueueVec();
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  QueueVec& operator=(const QueueVec &);
  // Move assignment
  // type operator=(argument);
  QueueVec& operator=(QueueVec && stklist);
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const QueueVec &) const noexcept;
  // type operator!=(argument) specifiers;
  bool inline operator!=(const QueueVec &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Head() specifiers; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  const Data& Head() const override;
  // type Head() specifiers; // Override Queue member (mutable version; must throw std::length_error when empty)
  Data& Head() override;
  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  void Dequeue() override;
  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override;
  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
  void Enqueue(const Data&) override;
  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)
  void Enqueue(Data&&) override;
  
  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member
  inline virtual bool Empty() const noexcept override{
    return testa == coda;
  }
  // type Size() specifiers; // Override Container member
  inline virtual unsigned long Size() const noexcept override{
      return size==0?0:((size + coda) - testa) % size;
  }
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;
protected:

  // Auxiliary functions, if necessary!
  void Espandi();
  void Riduci();
  void Resize(const unsigned long int nuovaSize, unsigned long int numeroElementi);

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
