#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

template <typename T>
class LinkedList {
private:
  Node<T> *head;
  Node<T> *tail;
  int length;

public:
  LinkedList<T>();  // constructor
  ~LinkedList<T>(); // destructor
  // Insertion in LinkedList
  void lInsert(T data); // add new node at the end by default
  void lInsert(T data, int position);

  // Deletion in LinkedList
  void lDelete(); // delete the tail
  void lDelete(int position);

  // traversal
  void traversal();

  // searching
  void search(T element);

  //reverse linked list
  void reverseLL();
};

#endif
