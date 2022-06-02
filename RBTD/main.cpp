#include <iostream>
#include <queue>
#include <cstring>
#include <fstream>
using namespace std;

class Node {
public:
  int data;
  char color;
  Node *left, *right, *parent;
  Node(int data) : data(data) {
    parent = left = right =
    color = 'r'
  }
  Node *uncle() {
    if(!parent || parent->parent == NULL) {
      return NULL;
    }
  }
