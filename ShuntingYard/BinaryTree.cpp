#include "BinaryTree.h"
#include <iostream>
#include <cstring>

using namespace std;
void BinaryTree::setData(char d) {
  datax = d;
}
void BinaryTree::setRight(BinaryTree* nr) {
  right = nr;
}
void BinaryTree::setLeft(BinaryTree* nl) {
  left = nl;
}
char BinaryTree::getData() {
  return datax;
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
}



