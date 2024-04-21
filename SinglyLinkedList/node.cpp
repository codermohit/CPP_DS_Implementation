#include "node.h"
#include <string>
template <typename T> Node<T>::Node(T data) : data(data), next(nullptr) {}

template <typename T>
Node<T>::Node(T data, Node<T> *next) : data(data), next(next) {}

// explicity instantiation of template classes for int and string

template class Node<int>;
template class Node<std::string>;
