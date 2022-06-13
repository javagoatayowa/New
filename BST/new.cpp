#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
//I used help from a pseudocode document for Add and fix add and left rotate and right rotate https://www.andrew.cmu.edu/user/mm6/95-771/examples/RedBlackTreeProject/dist/javadoc/redblacktreeproject/RedBlackTree.html#levelOrderTraversal() but I used C++ code to adjust a few things and the c++ code was very similar to that. that c++ code was: https://www.programiz.com/dsa/red-black-tree#:~:text=Red%2DBlack%20tree%20is%20a,colored%2C%20either%20red%20or%20black. I also used some syntax and pseocodoe from that website for delete and delete fix. 
struct Node {
  int data;
  Node* left;
  Node * right;
  Node* parent;
  char color;
};
class RedBlackTree {
private:
  Node *root;
  Node *TNULL;
  void initNULL(Node* node, Node* parent) {
    node->data = 0;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    node->color = 'b';
  }
  
  void InsertFix(Node*z) {
    while(z->parent->color == 'r') {
      if(z->parent == z->parent->parent->left) {
	Node * y = z->parent->parent->right;
	if(y->color == 'r') {
	  z->parent->color = 'b';
	  y->color = 'b';
	  z->parent->parent->color = 'r';
	  z = z->parent->parent;
	}
	else {
	  if(z == z->parent->right) {
	    z = z->parent;
	    leftRotate(z);
	  }
	  z->parent->color = 'b';
	  z->parent->parent->color = 'r';
	  rightRotate(z->parent->parent);
	}
      }
      else {
	Node *y = z->parent->parent->left;
	if(y->color == 'r') {
	  z->parent->color = 'b';
	  y->color = 'b';
	  z->parent->parent->color = 'r';
	  z = z->parent->parent;
	}
	else {
	  if(z == z->parent->left) {
	    z = z->parent;
	    rightRotate(z);
	  }
	  z->parent->color = 'b';
	  z->parent->parent->color = 'r';
	  leftRotate(z->parent->parent);
	}
      }
      if(z == root) {
	break;
      }
      //     root->color = 'b';
    }
    root->color = 'b';
  }
  
  void transplant(Node* x, Node* y) {
    if(x->parent == NULL) {
      root = y;
    }
    else {
      if(x == x->parent->left) {
	x->parent->left = y;
      }
      else {
	x->parent->right = y;
      }
    }
    y->parent = x->parent;
  }
  void dfix(Node* temp) {
    Node * x;
    while(temp->color == 'b' && temp != root) {
      if(temp == temp->parent->left) {
	x = temp->parent->right;
	if(x->color == 'r') {
	  temp->parent->right->color = 'b';
	  temp->parent->color = 'r';
	  leftRotate(temp->parent);
	  x = temp->parent->right;
	}
	if(x->right->color == 'b' && x->left->color == 'b') {
	  x->color = 'r';
	  temp = temp->parent;
	}
	else  {
	  if(x->right->color == 'b') {
	    x->left->color = 'b';
	    x->color = 'r';
	    rightRotate(x);
	    x = temp->parent->right;
	  }
	  x->color = temp->parent->color;
	  temp->parent->color = 'b';
	  x->right->color = 'b';
	  leftRotate(temp->parent);
	  temp = root;
	}
      } else {
	x = temp->parent->left;
	if(x -> color == 'r') {
	  x->color = 'b';
	  temp->parent->color = 'r';
	  rightRotate(temp->parent);
	  x = temp->parent->left;
	}
        if(x->right->color == 'b') {
	  x->color = 'r';
	  temp = temp->parent;
	}
	else {
	  if(x->left->color == 'b') {
	    x->right->color = 'b';
	    x->color = 'r';
	    leftRotate(x);
	    x = temp->parent->left;
	  }
	  x->color = temp->parent->color;
	  temp->parent->color =  'b';
	  x->left->color = 'b';
	  rightRotate(temp->parent);
	  temp = root;
	}
      }
    }
    temp = root;
  }
  void remove2(Node* node, int data) {
    Node* bru = TNULL;// this part finds the node to delete itself
    Node* u = new Node;
    Node* v = new Node;
    while(node != TNULL) {
      if(node->data == data) {
	bru = node;
      }
      if(node->data <= data) {
	node = node->right;
      }
      else {
	node = node->left;
      }
    }
    if(bru == TNULL) {//wasnt found
      cout<<"You are deleting something nonexistent?" << endl;
      return;
    }
    v = bru;
    char col = u->color;
    if(bru->left == TNULL) {
      u = bru->right;
      transplant(bru, bru->right);
    }
    else if(bru->right == TNULL) {
      u = bru->left;
      transplant(bru,bru->left);
    }
    else {
      v = minimum(bru->right);
      col = v->color;
      u = v->right;
      if(v->parent == bru) {
	u->parent = v;
      }
      else {
	transplant(v, v->right);
	v->right = bru->right;
	v->right->parent = v;
      }
      transplant(bru, v);
      v->left = bru->left;
      v->left->parent  = v;
      v->color = bru->color;
    }
    delete bru;
   if(col == 'b') {
      dfix(u);
   }
  }
public:
  RedBlackTree() {
    TNULL = new Node;
    TNULL->color = 'b';
    TNULL->left = NULL;
    TNULL->right = NULL;
    root = TNULL;
  }
  Node* minimum(Node* node) {
    while(node->left != TNULL) {
      node = node->left;
    }
    return node;
  }
  void leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if(y->left != TNULL) {y->left->parent = x;}
    y->parent = x->parent;
    if(x->parent == NULL) {
      this->root = y;
    }
    else {
      if(x == x->parent->left) {
        x->parent->left = y;
      }
      else {
        x->parent->right = y;
      }
    }
    y->left = x;
    x->parent = y;
  }
  void rightRotate(Node *x) {
      Node* y = x->left;
      x->left = y->right;
      if(y->right != TNULL) {y->right->parent = x;}
      y->parent = x->parent;
      if(x->parent == NULL) {
        this->root = y;
      }
      else {
        if(x == x->parent->right) {
          x->parent->right = y;
        }
        else {
          x->parent->left = y;
        }
      }
      y->right = x;
      x->parent = y;
  }
  void remove(int data) {
    remove2(this->root, data);
  }

  void insert(int n) {
    Node* node = new Node;
    node->parent = NULL;
    node->data = n;
    node->left = TNULL;
    node->right = TNULL;
    node->color = 'r';
    Node *y = NULL;
    Node *x = this->root;
    while(x != TNULL) {
      y = x;
      if(node->data < x->data) {
	x = x->left;
      }
      else {
	x = x->right;
      }
    }
    node->parent = y;
    if(y == NULL) {
      root = node;
    }
    else {
      if(node->data < y->data) {
	y->left = node;
      }
      else {
	y->right = node;
      }
    }
    if(node->parent == NULL) {
      node->color = 'b';
      return;
    }
    if(node->parent->parent == NULL) {
      return;
    }
    InsertFix(node);
  }
  Node* getRoot() {
    return this->root;
  }
  void setRoot(int data) {
    Node* bruh = new Node;
    bruh->data = data;
    bruh->color = 'b';
    bruh->left = NULL;
    bruh->right = NULL;
    bruh->parent = NULL;
    root = bruh;
  }
  void print(Node *root, int space)
  {
    if (!root)
        return;

    space = space + 10;

    print(root->right, space);

    cout<<endl;
    for (int i = 10; i < space; ++i) {
      cout << "  ";
    }
    if(root != NULL && root != TNULL) { cout<<root->data << root->color <<"\n"; }

    print(root->left, space);
   }
  void searchBRUH(Node *root, int data, bool & bruhmane)
{
    if (root == NULL || bruhmane == true)
        return;
    searchBRUH(root->right, data, bruhmane);
    if(root->data == data, data, bruhmane) {
      bruhmane = true;
    }
    searchBRUH(root->left, data, bruhmane);
     if(root->data == data) {
      bruhmane = true;
    }

}

};

int main() {
  RedBlackTree rbt;
  char input[80];
  bool tf = false;
  while(tf == false) {
    cout<<" What do you want to do? ADD? DELETE? FILE? SEARCH? PRINT?" << endl;
    cin>>input;
    if(strcmp(input,"ADD") == 0) {
	cout<<"What do you want to input? " << endl;
	int n;
	cin>> n;
	rbt.insert(n);
      }
    else if(strcmp(input, "PRINT") == 0) {
      rbt.print(rbt.getRoot(),0);
    }
    else if (strcmp(input, "DELETE") == 0) {
      cout<<"What do you want to delete? " << endl;
      int n;
      cin>>n;
      rbt.remove(n);
    }
    else if(strcmp(input, "FILE") == 0) {
      cout<<"ENTER NUMS IN THE FILEEEEE";
       fstream myfile("numbers.txt");
       string filename("input.txt");
       int number;
       ifstream input_file(filename);
       if (!input_file.is_open()) {
         cerr << "Could not open file L bozo + ratio + mad cuz bad" << endl;
       }

       while (input_file >> number) {
         rbt.insert(number);
       }
       cout << endl;
       input_file.close();
      }
    else if(strcmp(input, "SEARCH" ) == 0) {
      bool bruhmane = false;
      cout<<"enter da num u wanna find" << endl;
      int n;
      cin>>n;
      rbt.searchBRUH(rbt.getRoot(), n, bruhmane);
      if(bruhmane == true) {
	cout<<"Number is in tree" << endl;
      }
      else {
	cout<<"Number isnt in tree" << endl;
      }
    }
    else if(strcmp(input, "QUIT" ) == 0) {
      tf = true;
    }

  }
  return 0;
}
  
