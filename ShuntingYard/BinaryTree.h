#include <iostream>
#include <cstring>
//Binary Tree Class

class BinaryTree {
 public:
  char datax;
  BinaryTree* left;
  BinaryTree* right;
  BinaryTree* next;
  BinaryTree* getNext();
  void setData(char d);
  void setRight(BinaryTree* nr);
  void setLeft(BinaryTree* nl);
  char getData();
  BinaryTree* getLeft();
  BinaryTree* getRight();
  BinaryTree(char d);
  ~BinaryTree();
};
