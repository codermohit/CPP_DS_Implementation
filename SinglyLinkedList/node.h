#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
  T data;
  Node<T>* next;
  Node(T data);
  Node(T data , Node<T>* next); 
};

#endif 
