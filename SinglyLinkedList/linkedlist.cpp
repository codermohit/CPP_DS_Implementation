#include "linkedlist.h"
#include "node.h"
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), length(0) {}

template <typename T> LinkedList<T>::~LinkedList() {
  Node<T> *tempHead = head;
  while (tempHead != nullptr) {
    head = tempHead;
    std::cout << "Deleting : " << head->data << '\n';
    tempHead = tempHead->next;
    delete head;
  }
}

template <typename T> void LinkedList<T>::lInsert(T data) {
  Node<T> *node = new Node<T>(data);

  // first insertion
  if (head == nullptr) {
    head = node;
    tail = head;
    return;
  } else {
    tail->next = node;
    tail = node;
  }
  length++;
}

template <typename T> void LinkedList<T>::lInsert(T data, int position) {
  // invalid position
  if (position <= 0 || position > length + 1) {
    std::cerr << "Invalid position\n";
    return;
  }
  // add node to the first position
  if (position == 1) {
    Node<T> *node = new Node<T>(data, head);
    head = node;
    if (tail == nullptr) {
      tail = head;
    }
  }
  // add node at position other than first node
  else {
    Node<T> *temp = head;
    for (int i = 1; i < position - 1; i++) {
      temp = temp->next;
    }

    Node<T> *node = new Node<T>(data, temp->next);
    temp->next = node;
    if (node->next == nullptr) {
      tail = node;
    }
  }
  length++;
}

template <typename T> void LinkedList<T>::traversal() {
  Node<T> *tempHead = head;
  while (tempHead != nullptr) {
    std::cout << tempHead->data << " ";
    tempHead = tempHead->next;
  }
  std::cout << "\n";
}

template <typename T> void LinkedList<T>::lDelete() {
  Node<T> *temp = head;
  while (temp->next->next != nullptr) {
    temp = temp->next;
  }
  delete tail;
  tail = temp;
  tail->next = nullptr;
  this->length--;
}

template <typename T> void LinkedList<T>::lDelete(int position) {
  // reach the position-1 node
  // get the next node from position node
  if (position <= 0 || position >= length) {
    std::cerr << "position of node out of bounds.\n";
    return;
  }

  if (position == 1) {
    Node<T> *temp = head;
    head = head->next;
    delete temp;
  } else {

    Node<T> *temp = head;
    for (int i = 1; i < position - 1; i++) {
      temp = temp->next;
    }

    Node<T> *tempNextToDeleted = nullptr;
    tempNextToDeleted = temp->next->next;
    delete temp->next;
    temp->next = tempNextToDeleted;
  }
  this->length--;
}

template <typename T> void LinkedList<T>::search(T element) {
  if (head == nullptr) {
    std::cout << "LinkedList empty\n";
    return;
  }
  Node<T> *temp = head;
  int elPost = 1;
  while (temp != nullptr) {
    if (temp->data == element) {
      std::cout << "Element found at position : " << elPost << '\n';
      break;
    }
    temp = temp->next;
    elPost++;
  }
  std::cout << "Element not found \n";
}

template <typename T> void LinkedList<T>::reverseLL() {
  if(head == nullptr) return;
  if(length == 1) return;
  tail = head;
  Node<T>* curr = head;
  Node<T>* prev = nullptr, *next = nullptr;

  while(curr!=nullptr){
    //move the next pointer to next node 
    next = curr->next;
    //reverse the pointer of current node to the previous node
    curr->next = prev;
    //update the prev pointer to current pointer
    prev = curr;
    curr = next;
  }
  head = prev;
}


// explicit instantiation of template class for int and string
template class LinkedList<int>;
template class LinkedList<std::string>;
