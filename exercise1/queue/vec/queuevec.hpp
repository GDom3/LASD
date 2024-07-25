
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

#define GRANDEZZA_INIZIALE 16
#define TASSO_RIDUZIONE 2
#define TASSO_ESPANZIONE 2


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
  using Container::size;
  
  
  unsigned long int testa = 0;
  unsigned long int coda = 0;


public:

  // Default constructor
  // QueueVec() specifier;
  QueueVec();
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
  QueueVec(QueueVec && ) noexcept;
  /* ************************************************************************ */

  // Destructor
  // ~QueueVec() specifier;
  virtual ~QueueVec() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  QueueVec& operator=(const QueueVec &);
  // Move assignment
  // type operator=(argument);
  QueueVec& operator=(QueueVec &&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool inline operator==(const QueueVec &) const noexcept;
  // type operator!=(argument) specifiers;
  bool inline operator!=(const QueueVec &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Head() specifiers; 
  // Override Queue member (non-mutable version; must throw std::length_error when empty)
  inline const Data& Head() const override;
  
  // type Head() specifiers; 
  // Override Queue member (mutable version; must throw std::length_error when empty)
  inline Data& Head() override;
  
  // type Dequeue() specifiers; 
  // Override Queue member (must throw std::length_error when empty)
  inline void Dequeue() override;
  
  // type HeadNDequeue() specifiers; 
  // Override Queue member (must throw std::length_error when empty)
  inline Data HeadNDequeue() override;
  
  // type Enqueue(argument) specifiers; 
  // Override Queue member (copy of the value)
  inline void Enqueue(const Data&) override;
  
  // type Enqueue(argument) specifiers; 
  // Override Queue member (move of the value)
  inline void Enqueue(Data&&) override;
  
  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member
  inline bool Empty() const noexcept override{
    return testa == coda;
  }
  // type Size() specifiers; // Override Container member
  inline unsigned long Size() const noexcept override{
      return abs(coda - testa);
      
  }
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  inline void Clear() override;

  void Resize(unsigned long int) override;

  void Stampa() const;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
