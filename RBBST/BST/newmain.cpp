#include <iostream>
#include <cstring>
#include <fstream>//I used some help on the adding and understanding red black tree in general from https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/, and I also used print method from my BST code
using namespace std;
struct Node {
	int data;
	Node *parent; 
	Node *left; 
	Node *right;
	char color;
};
class rbt {
private:
	Node* root;
	Node* TNULL;
	void fix(Node* nf){
		Node * u;
		while (nf->parent->color == 'r') {
			if (nf->parent->parent->right == nf->parent) {
				u = nf->parent->parent->left;
				if (u->color == 'b') {
				  
					if (nf->parent->left == nf) {
                                                nf = nf->parent;
                                                rr(nf);
                                        }
                                        nf->parent->color = 'b';
                                        nf->parent->parent->color = 'r';
                                        lr(nf->parent->parent);

				}
				else {
				        u->color = 'b';
                                        nf->parent->color = 'b';
                                        nf->parent->parent->color = 'b';
                                        nf = nf->parent->parent;
				}
			}
			else {
				u = nf->parent->parent->right; 
				if (u->color == 'r') {
					u->color = 'b';
					nf->parent->color = 'b';
				 	nf->parent->parent->color = 'r';
					nf = nf->parent->parent;	
				}
				else {
				  if (nf == nf->parent->right) {
						nf = nf->parent;
						lr(nf);
				  }
					nf->parent->color = 'b';
					nf->parent->parent->color = 'r';
					rr(nf->parent->parent);
				}
			}
			if (nf == root) {
				break;
			}
		}
		root->color = 'b';
	}
public:
	rbt() {
		TNULL = new Node;
		TNULL->color = 'b';
		TNULL->left = NULL;
		TNULL->right = NULL;
		root = TNULL;
	}
	void lr(Node * x) {
		Node * y = x->right;
		x->right = y->left;
		if (y->left != TNULL) {
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == NULL) {
			this->root = y;
		} else if (x == x->parent->left) {
			x->parent->left = y;
		} else {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}
	void rr(Node * x) {
		Node * y = x->left;
		x->left = y->right;
		if (y->right != TNULL) {
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		} else if (x == x->parent->right) {
			x->parent->right = y;
		} else {
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}
	void add(int key) {
	        Node * node = new Node;
		node->parent = NULL;
		node->data = key;
		node->left = TNULL;
		node->right = TNULL;
		node->color = 'r';
		Node * it = NULL;
		Node * headie = this->root;
		while (headie != TNULL) {
			it = headie;
			if (node->data < headie->data) {
				headie = headie->left;
			} else {
				headie = headie->right;
			}
		}
		node->parent = it;
		if (!it) {
			root = node;
		} else if (node->data > it->data) {
			it->right = node;
		} else {
			it->left = node;
		}
		if (!node->parent){
	                node->color = 'b';
			return;
		}
		if (node->parent->parent == NULL) {
			return;
		}
		fix(node);
	}
	Node * getRoot(){
		return this->root;
	}
};
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
    cout<<root->data << " " << root->color << " " <<"\n";

    print(root->left, space);
}

int main() {
	rbt rbts;
	bool playing = true;
	char cstring2[81];
	while(playing == true) {
	  cout<<"What do you want to do? ADD? PRINT?" << endl;
	  cin>>cstring2;
	  if(strcmp(cstring2,"ADD") == 0) {
	    cout<<"ENTER NUMS IN THE FILEEEEE";
	    fstream myfile("numbers.txt");
	    string filename("input.txt");
	    int number;
	    ifstream input_file(filename);
	    if (!input_file.is_open()) {
	      cerr << "Could not open file L bozo + ratio + mad cuz bad" << endl;
	    }
	    
	    while (input_file >> number) {
	      rbts.add(number);
	    }
	    cout << endl;
	    input_file.close();

	  }
	  else if(strcmp(cstring2,"PRINT") == 0) {
	    if(rbts.getRoot() == NULL) {
	      cout<<"Mr Galbraith tryna catch me slippin, nah the root needs to be there bruh, ur head dis null, not ur forehead tho, thats humongous" << endl;
	    }
	    else {
	      print(rbts.getRoot(),0);
	    }
	  }
	}
	return 0;
}
