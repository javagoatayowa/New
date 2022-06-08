#include <iostream>
#include <cstring>
using namespace std;


struct Node {
  int data;
  Node* parent = NULL;
  Node* left = NULL;
  Node* right = NULL;
  char color = 'r';
};
class RBT {
 public:
  Node* root;
  Node* TNULL;
  void initializeNull(Node* node, Node* parent) {
    node->data = 0;
    node->left = NULL;
    node->parent = parent;
    node->right = NULL;
    node->color = 'b';
  }
  void insertNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->parent = NULL;
    node->left = TNULL;
    node->right = TNULL;
    node->color = 'r';
    Node* y = NULL;
    Node* x = root;
    while(x != TNULL && x != NULL && node != NULL) {
      y = x;
      if(node->data < x->data) {
	x = x->left;
      }
      else
	x = x->right;
    }
    node->parent = y;
    if(y == NULL)
      root = node;
    else if( node->data < y->data ) {
      y->left = node;
    }
    else
      y->right = node;
    if(node->parent == NULL) {
      node->color = 'b';
      return;
    }
    if(node->parent->parent == NULL) {
      return;
     }
    fixInsert(node);
  }
  RBT() {
    TNULL = new Node;
    TNULL->color = 'b';
    TNULL->left = NULL;
    TNULL->right = NULL;
    root = TNULL;
  }
  Node* min(Node* node) {
    while(node->left != TNULL) {
      node = node->left;
    }
    return node;
  }
  void LeftRotate(Node * x) {
    Node* y = x->right;
    x->right = y->left;
    if(y->left != TNULL) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == NULL) {
      root = y;
    }
    else if(x == x->parent->left) {
      x->parent->left = y;
    }
    else
      x->parent->right = y;
    y->left = x;
    x->parent = y;
  }
  void RightRotate(Node * x) {//just swithc left and right from left rotate lol
    Node* y = x->left;
    x->right = y->right;
    if(y->right != TNULL) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == NULL) {
      root = y;
    }
    else if(x == x->parent->right) {
      x->parent->right = y;
    }
    else
      x->parent->left = y;
    y->right= x;
    x->parent = y;
  }
  void switche(Node* u, Node* v) {
    if(u->parent == NULL) {
      root = v;
    }
    else if(u == u->parent->left) {
      u->parent->left = v;
    }
    else
      u->parent->right = v;
    v->parent = u->parent;
  }
  void fixInsert(Node* k) {
    while(k->parent ->color == 'r') {
      if(k->parent == k->parent->parent->right) {
	Node* u = k->parent->parent->left;
	if(u != NULL && u->color == 'r') {
	  u->color = 'b';
	  k->parent->color = 'b';
	  k->parent->parent->color = 'r';
	  k = k->parent->parent;
	}
	else {
	  if(k == k->parent->left) {
	    k = k->parent;
	    RightRotate(k);
	  }
	  k->parent->color = 'b';
	  k->parent->parent->color = 'r';
	  LeftRotate(k->parent->parent);
	}
      }
      else {
	Node* u = k->parent->parent->right;
	if(u->color == 'r')  {
	  u->color = 'b';
	  k->parent->color = 'b';
	  k->parent->parent->color = 'r';
	  k = k->parent->parent;
	}
	else {
	  if(k == k->parent->right) {
	    k = k->parent;
	    LeftRotate(k);
	    k->parent->color = 'b';
	    k->parent->parent->color = 'r';
	    RightRotate(k->parent->parent);
	  }
	}
      }
      if(k== root) {
	break;
      }
    }
    root->color = 'b';
  }
  void fixDelete(Node* x) {
    while(x != root and x->color == 'b') {
      if(x == x->parent->left) {
	Node *s = x->parent->right;
	if(x->color == 'r') {
	  s->color = 'b';
	  x->parent->color = 'r';
	  LeftRotate(x->parent);
	  s = x->parent->right;
	}
	if(s->left->color == 'b' and s->right->color == 'b') {
	 s->color = 'r';
	 x = x->parent;
       }
       else {
	 if(s->right->color == 'b') {
	   s->left->color = 'b';
	   s->color = 'r';
	   RightRotate(s);
	   s = x->parent->right;
	 }
	 s->color = x->parent->color;
	 x->parent->color = 'b';
	 s->right->color = 'b';
	 LeftRotate(x->parent);
	 x = root;
       }
      }
      else {
	Node * s = x->parent->left;
	if(s->color == 'r') {
	  s->color = 'b';
	  x->parent->color = 'r';
	  RightRotate(x->parent);
	  s = x->parent->left;
	}
	if(s->right->color == 'b' and s->right->color == 'b') {
	  s->color = 'r';
	  x = x->parent;
	}
	else {
	  if(s->left->color == 'b') {
	    s->right->color = 'b';
	    s->color = 'r';
	    LeftRotate(s);
	    s = x->parent->left;
	  }
	  s->color = x->parent->color;
	  x->parent->color = 'b';
	  s->left->color = 'b';
	  RightRotate(x->parent);
	  x= root;
	}
      }
    }
    x->color = 'b';
  }
  void deleteHelp(Node* node, int data) {
    Node *z= TNULL;
    while(node != TNULL) {
      if(node->data == data) {
	z = node; 
      }
      if(node->data <= data) {
	node = node->right;
      }
      else {
	node = node->left;
      }
    }
    if(z == TNULL) {
      cout<<"No value in here!" << endl;
      return;
    }
    Node* y = z;
    char yc = y->color;
    Node * x;
    if(z->left == TNULL) {
      x = z->right;
      switche(z, z->right);
    }
    else if(z->right == TNULL) {
      x = z->left;
      switche(z,z->left);
    }
    else {
      y = min(z->right);
      yc = y->color;
      x = y->right;
      if(y->parent == z) {
	x->parent = y;

      }
      else {
	switche(y,y->right);
	y->right = z->right;
	y->right->parent = y;
      }
      switche(z,y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
    if(yc == 'b') {fixDelete(x);}
  }
  void deleteN(int data) {
    deleteHelp(root,data);
  }
  Node* predecessor(Node * node) {
    Node * right = node->right;
    while(right != TNULL) {
      if(right->left == TNULL) {
	return right->left;
	break;
      }
      right = right->left;
    }
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
    if(root != TNULL && root != NULL) {cout<<root->data<< " " << root->color << "\n";}
 
    print(root->left, space);
}
  void setRoot(Node* rot) {
    root = rot;
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
  RBT rbt;
  bool bruh = false;
  Node * root = new Node;
  char arr[81];
  int index = 0;
  while(bruh == false) {
    cout<<"What do you want to do? ADD? PRINT? DELETE? FILE?" << endl;
    cin>>arr;
    if(strcmp(arr,"ADD") == 0) {
      cout<<"Enter ur number" << endl;
      int n;
      cin>>n;
      if(index == 0) {
	index++;
	Node * newroot = new Node;
	newroot->left = NULL;
	newroot->data = n;
	newroot->right = NULL;
	newroot->parent = NULL;
	newroot->color = 'b';
	rbt.setRoot(newroot);
      }
      else {
	rbt.insertNode(n);
      }
    }
    else if(strcmp(arr,"PRINT") == 0) {
      rbt.print(rbt.root,0);
    }
    else if(strcmp(arr,"DELETE")==0) {
      int n;
      cout<<"What do you want to delete?" << endl;
      cin>>n;
      rbt.deleteN(n);
    }
  }
  //  rbt.print(rbt.root, 0);
}

