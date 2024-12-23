#pragma once

#include <cstdlib>

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.
// Modified 05/14/2024 -- Prof Sipantzi

// Singly linked list node
template <class E> 
class Link {
public:
  E element;      // Value for this node
  Link *next;        // Pointer to next node in list
  int numAccessed;
  // Constructors
  Link(const E& elemval, Link* nextval =NULL)
    { element = elemval;  next = nextval; }
  Link(Link* nextval =NULL) { next = nextval; }

  void setAccessed(int n)
  {
      numAccessed = n;
  }

  int getAccessed()
  {
      return numAccessed;
  }
};
