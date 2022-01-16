#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"
using namespace std;
class Node {
 public:
  Node(Student*);
  ~Node();
  Student* getStudent();
  Node* getNext();
  void setNext(Node*);
 private:
  Student* student;
  Node* next;
};
#endif
