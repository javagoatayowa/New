#include <iostream>// used https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/ for psecoducode mostly and a bit of syntax help. 
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
    parent = left = right = NULL;
    color = 'r';
  }
  Node *uncle() {
    if(parent == NULL or parent->parent == NULL) {
      return NULL;
    }
    if(parent->isLeft()) {
      return parent->parent->right;
    }
    else {
      return parent->parent->left;
    }
  }
  bool isLeft() { return this == parent->left;}
  Node* sib() {
    if(parent == NULL) {
      return NULL;
    }
    if(isLeft()) {
      return parent->right;
    }
    return parent->left;
  }
  void down(Node *parent2) {
    if(parent != NULL) {
      if(isLeft()) {
	parent->left = parent2;
      }
      else{
	parent->right = parent2;
      }
    }
    if(parent2 != NULL && parent2->parent != NULL) {
      parent2->parent = parent;
    }
    //    parent2->parent = parent;
    parent = parent2;
  }
  bool hasRedC() {
    return( left != NULL && left->color == 'r') or (right != NULL && right->color == 'r');
  }
};
class RBT {
  Node* root;
  //root->color = 'b';
  void lr(Node* rot) {
    Node* parent2 = rot->right;
    if(rot == root) {
      root = parent2;
    }
    rot->down(parent2);
    if(parent2 != NULL) {
       rot->right = parent2->left;
    }
    if(parent2->left != NULL) {
      parent2->left->parent = rot;
    }
    parent2->left = rot;
  }
  void rr(Node* rot) {
    Node* parent2 = rot->left;
    if(rot == root) {
      root = parent2;
    }
    rot->down(parent2);
    rot->left = parent2->right;
    if(parent2->right != NULL) {
      parent2->right->parent = rot;
    }
    parent2->right = rot;
  }
  void switchColours(Node *x, Node*y) {
    char temp;
    temp = x->color;
    x->color = y->color;
    y->color = temp;
  }

  void switchDatas(Node *x, Node*y) {
    int temp;
    temp = x->data;
    x->data = y->data;
    y->data = temp;
  }
  Node *BSTrepl(Node *x) {
    if (x->left != NULL && x->right != NULL)
      return successor(x->right);
    
    if (x->left == NULL && x->right == NULL)
      return NULL;
    if (x->left != NULL)
      return x->left;
    else
      return x->right;
  }

  void fixRR(Node * x) {
    if(x == root) {
      x->color = 'b';
      return;
    }
    Node * parent = x->parent, *grandparent = parent->parent, *uncle = x->uncle();
    if(parent->color != 'b') {
      if(uncle != NULL && uncle->color == 'r') {
	parent->color = 'b';
        uncle->color = 'b';
        grandparent->color = 'r';
        fixRR(grandparent);
      }
      else {
	if(parent ->isLeft()) {
	  switchColours(parent, grandparent);
	}
	else {
	  lr(parent);
	  switchColours(x,grandparent);
	}
	lr(grandparent);
      }
      //(grandparent);
    }
  }
  Node *successor(Node *x) {
    Node *temp = x;
    while (temp->left != NULL)
      temp = temp->left;
    return temp;
  }
  void fixBB(Node *rot) {
    if (rot == root){
      return;
    }
    Node *sibling = rot->sib(), *parent = rot->parent;
    if (!sibling) {
      fixBB(parent);
    } else {
      if (sibling->color == 'r') {
        parent->color = 'r';
        sibling->color = 'b';
        if (sibling->isLeft()) {
          rr(parent);
        } else {
          lr(parent);
        }
        fixBB(rot);
      } else {
        if (sibling->hasRedC()) {
          if (sibling->left != NULL && sibling->left->color == 'r') {
            if (sibling->isLeft()) {
              sibling->left->color = sibling->color;
              sibling->color = parent->color;
              rr(parent);
            } else {
              sibling->left->color = parent->color;
              rr(sibling);
              lr(parent);
            }
          } else {
            if (sibling->isLeft()) {
              sibling->right->color = parent->color;
              lr(sibling);
              rr(parent);
            } else {
              sibling->right->color = sibling->color;
              sibling->color = parent->color;
              lr(parent);
            }
          }
          parent->color = 'b';
        } else {
          sibling->color = 'r';
          if (parent->color == 'b')
            fixBB(parent);
          else
            parent->color = 'b';
        }
      }
    }
  }
  
  void deleteN(Node *e) {
    Node *l = BSTrepl(e);
    bool leb = ((!l || l->color == 'b') && (e->color == 'b'));
    Node *parent = e->parent;

    if (!l) {
      if (e == root) {
        root = NULL;
      } else {
        if (leb == true) {
          fixBB(e);
        } else {
          if (e->sib() != NULL)
            e->sib()->color = 'r';
        }
        if (e->isLeft()) {
          parent->left = NULL;
        } else {
          parent->right = NULL;
        }
      }
      delete e;
      return;
    }

    if (e->left == NULL or e->right == NULL) {
      if (e == root) {
        e->data = l->data;
        l->left = e->right = NULL;
        delete l;
      } else {
        if (e->isLeft()) {
          parent->left = l;
        } else {
          parent->right = l;
        }
        delete e;
        l->parent = parent;
        if (leb) {
          fixBB(l);
        } else {
          l->color = 'b';
        }
      }
      return;
  }
    switchDatas(l,e);
    deleteN(l);
  }
public:
   RBT() {
     root = NULL;
   }
  Node *getRoot() {
    return root;
  }
  Node *search(int find) {//the point of this is to find the closest Node to the node, so ignore the two search functions.
    Node *temp = root;
    while (temp != NULL) {
      if (find < temp->data) {
        if (temp->left == NULL)
          break;
        else
          temp = temp->left;
      } else if (find == temp->data) {
        break;
      } else {
         if (temp->right == NULL)
           break;
	 else
	   temp = temp->right;
      }
    }

    return temp;
  }

  void insert(int n) {
    Node * n2 = new Node(n);
    if(root == NULL) {
      //   cout<<"yo" << endl;
      n2->color == 'b';
      root = n2;
      root->color = 'b';
    }
    else {
      Node* temp = search(n);
      if(temp->data == n) {
	return;
      }
      n2->parent = temp;
      if(n < temp->data) {
        temp->left = n2;
      }
      else {
	temp->right = n2;
      }
      fixRR(n2);
    }
  }
  void deleteData(int dat) {
    if(root == NULL) {
      return;
    }
    Node * bruh = search(dat), *uh;
    if(bruh->data != dat) {
      cout<<"Its not here bruh why u tryna give a seg fault";
    }
    else {
      deleteN(bruh);
    }
    //deleteN(da);
  }
   void print(Node* root, int space) {
    if (!root)
        return;

    space = space + 10;

    print(root->right, space);

    cout<<endl;
    for (int i = 10; i < space; ++i) {
      cout << "  ";
    }
    cout<<root->data;
    if(root->color == 'r') {
      cout<<" r" << "\n";
    }
    else {
      cout<<"b" << "\n";
    }

    print(root->left, space);
  }
  void get(Node* root, int find, bool & bru) {
    if (!root || bru == true)
        return;

    get(root->right, find, bru);
    if(root->data == find) {
      bru = true;
    }
    get(root->left, find, bru);
  }
};

int main() {
  RBT tree;
  char input[81];
  int a = 0;
  while(a == 0) {
    cout<<"INPUT to input, FILE to file, DELETE to delete, PRINT to print, FILE to file" << endl;
    cin>> input;
    if(strcmp(input,"INPUT") == 0) {
      cout<<"Enter number " << endl;
      int n;
      cin>>n;
      tree.insert(n);
    }
    else if(strcmp(input, "DELETE") ==0) {
      cout<<"Enter number " << endl;
      int n;
      cin>>n;
      tree.deleteData(n);
      }
    else if(strcmp(input, "PRINT") == 0) {
      tree.print(tree.getRoot(),0);
    }
    else if(strcmp(input,"SEARCH") == 0) {
      cout<<"Enter number " << endl;
      int n;
      cin>>n;
      bool bru = false;
      tree.get(tree.getRoot(), n, bru);
      if(bru == false) {
        cout<<"THATS NOT HERE" << endl;
      }
      else {
        cout<<"Found it!" << endl;
      }
    }
    else if(strcmp(input,"FILE") == 0) {
           cout<<"ENTER NUMS IN THE FILEEEEE";
           fstream myfile("numbers.txt");
           string filename("input.txt");
           int number;
           ifstream input_file(filename);
           if (!input_file.is_open()) {
             cerr << "Could not open file L bozo + ratio + mad cuz bad" << endl;
           }

           while (input_file >> number) {
             tree.insert(number);
           }
           cout << endl;
           input_file.close();

    }

  }
  return 0;
}


