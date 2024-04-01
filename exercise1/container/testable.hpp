
#ifndef TESTABLE_HPP
#define TESTABLE_HPP

/* ************************************************************************** */

#include "container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TestableContainer : protected Container {
  // Must extend Container

private:

  // ...

protected:

  // ...
  TestableContainer() = default;

public:

  // Destructor
  // ~TestableContainer() specifiers
  ~TestableContainer() = default;
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  virtual TestableContainer& operator=(const TestableContainer & daCopiare);
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.
  virtual TestableContainer& operator=(const TestableContainer && daSpostare) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  virtual bool operator==(const TestableContainer & daConfrontare) const;
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.
  virtual bool operator!=(const TestableContainer & daConfrontare) const;
  /* ************************************************************************ */

  // Specific member function

  // type Exists(argument) specifiers; // (concrete function should not throw exceptions)
  virtual bool Exists(const Data &elemento) const noexcept;
};

/* ************************************************************************** */

}

#endif
