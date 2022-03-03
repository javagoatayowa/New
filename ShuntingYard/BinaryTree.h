#include <iostream>//inclusions
#include <cstring>
//Binary Tree Class

class BinaryTree {
 public:
  char datax;//parts of binary tree
  BinaryTree* left;
  BinaryTree* right;
  BinaryTree* next;
  BinaryTree* getNext();
  void setRight(BinaryTree* nr);
  void setLeft(BinaryTree* nl);
  void setNext(BinaryTree* nn);
  BinaryTree* getLeft();
  BinaryTree* getRight();
  BinaryTree(char d);
  ~BinaryTree();
};
