#include "BinaryTree.h"
#include <iostream>//inclusion
#include <cstring>
//methods
using namespace std;
void BinaryTree::setRight(BinaryTree* nr) {
  right = nr;
}
void BinaryTree::setLeft(BinaryTree* nl) {
  left = nl;
}
void BinaryTree::setNext(BinaryTree* nn) {
  next = nn;
}
BinaryTree* BinaryTree::getRight() {
  return right;
}
BinaryTree* BinaryTree::getLeft() {
  return left;
}
BinaryTree* BinaryTree::getNext() {
  return next;
}
BinaryTree::BinaryTree(char d) {
  datax = d;
  right = NULL;
  left = NULL;
  next = NULL;
}
BinaryTree::~BinaryTree() {
}


