#include <iostream>
#include <cstring>
#include <vector>
#include "Node.h"
#include "Student.h"//Aneeq Chowdhury 1/16/2021 LinkedList code to do add students to a data base with linked lists and I used a bit of help from Nihal with constructors and directions for the assignment. I used Ehan's verification method to prove my thing works. 

using namespace std;
int main() {
  Student* firststudent = new Student();//first student and their next
  Student* nextstudent = new Student();
  Node* one = new Node(firststudent);
  Node* next = new Node(nextstudent);
  one->setNext(next);//setting their next
  one->getNext();//getting their next
  one->getStudent();//getting the student pointer
  one->~Node();//destroying it !!!! :(((
}
