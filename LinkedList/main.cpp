#include <iostream>
#include <cstring>
#include <vector>
#include "Node.h"
#include "Student.h"

using namespace std;
int main() {
  Student* firststudent = new Student();
  Student* nextstudent = new Student();
  Node* one = new Node(firststudent);
  Node* next = new Node(nextstudent);
  one->setNext(next);
  one->getNext();
  one->getStudent();
  one->~Node();
}
