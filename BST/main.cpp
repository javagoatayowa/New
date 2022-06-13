//Code created by Aneeq Chowdhury due 4/24/2021. Im v sick Mr Galbraith, sry for not showing up in advance. This code is a binary search tree and it deletes and adds and all sorts of excitigng stuff! I used Karla fants notes, and Geekfs for geek print https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/, and I also learned from a Java website on how to delete from BST. https://www.java2novice.com/java-interview-programs/delete-node-binary-search-tree-bst/., using Geeks for geeks for delete https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/ got help from nihal on how to delete the head
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct BST {
  BST* parent;
  int data;
  BST *left;
  BST *right;
  char color;
};

BST* uncle(BST* bruh) {
  if(bruh->parent == NULL or bruh->parent->parent == NULL) {
    return NULL;
  }
  if(bruh == bruh->parent->left) {
    return bruh->parent->parent->right;
  }
  else
    return bruh->parent->parent->left;
}
BST* sibling(BST* bruh) {
  if(bruh->parent == NULL) {
    return NULL;
  }
  if(bruh == bruh->parent->left) {
    return brbuh->parent->right;
  }
  return bruh->parent->left;
}
void Down(BST* bruh, BST* n) {
  if(bruh->parent != NULL) {
    if(bruh = bruh->parent->left) {
      bruh ->parent = n;
    }
    else {
      bruh->parent->right = n;
    }
  }
  n->parent = bruh->parent;
  bruh->parent = n;
}

BST* minNode(BST* n) {
  BST* temp = n;
  while(temp && temp->left != NULL)
    temp = temp->left;
  return temp;
}

/*
BST* deleteTing(BST* root, int data) {
  if(!root) {
    return; 
  }
  if(root->data < data)
    deleteTing(root-right, data);
  if (root->data > data)
    deleteTing(root->left, data);
  else 
    if (root->left == NULL && root->right == NULL)
      return NULL;

    else if (root->right == NULL) 
      return root->left;
    if (root->
}
*/

BST* LeftRotate(BST *& root, BST* node) {
  BST* y = node->right;
  y->left = x->right;
  if(y != NULL) {
    x  = y->left->parent;
  }
  x->parent = y->parent;
  if(x->parent == NULL) {
    y = root;
  }
  else if(x == x->parent->left) {
    y = x->parent->left;
  }
}

/*
BST* checkAdd(BST* &root, BST* temp) {
  BST* p = NULL;
  BST* u = NULL;
  BST* gp = NULL;

  if(temp->parent != NULL) {
    p = temp->parent;
    if(p->parent != NULL) {
      gp = p->parent;
      if(gp ->left == p) {
	u = gp->right;
      }
      else if(gp->right == p) {
	u = gp->left;
      }
    }
  }
}
*/
BST* leftRotate() {
}
BST* deleteNode(BST* root, int data, BST *& root2)
{
    if(data == root2->data) {
      if(root2-> left != NULL && root2-> right == NULL) {
	root2 = root2->left;
	root = NULL;
      }
      else if(root2->left == NULL && root2->right != NULL) {
	root2 = root->right;
	root = NULL;
      }
      else if(root2->left == NULL && root2->right == NULL) {
	root2 = NULL;
	root = NULL;
      }
    }
    if (!root) 
        return root;
    if (data > root->data)
      root->right = deleteNode(root->right, data,root2);
    
    else if (data < root->data)
      root->left= deleteNode(root->left, data,root2);
    else {
       if (root->left == NULL) {
            BST* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->left==NULL && root->right==NULL)
            return NULL;
      
        else if (root->right == NULL) {
            BST* temp = root->left;
            delete root;
            return temp;
        }

        BST* temp;
	temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data,root2);
    }
    return root;
}
/*
BST* deleteBRUH(BST* root, int data) {
  if(root == NULL) {
    return root;
  }
  else if(data > root->data) {
    root->right = deleteBRUH(root->right,data);
  }
  else {
    if(root->left == NULL && root->right == NULL) {
      return NULL;
    }
    else if(root->left == NULL) {
      return root->right;
    }
    else if(root->right == NULL) {
      return root->left;
    }
    else {
      int min = minValue(root->right);
      root->data = min;
      root->right = deleteBRUH(root->right, min);
    }
  }
  return root;
}
*/
void print(BST *root, int space)
{
    if (!root)
        return;
 
    space = space + 10;
 
    print(root->right, space);
 
    cout<<endl;
    for (int i = 10; i < space; ++i) {
      cout << "  ";
    }
    cout<<root->data<<"\n";
 
    print(root->left, space);
}
void searchBRUH(BST *root, int data, bool & bruhmane)
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

BST * add(BST* & root, int & data) {
  if(root == NULL) {
    root = new BST;
    root->data = data;
    root->right = NULL;
    root->left = NULL;
  }
  else if(root->data < data) {
    root->right = add(root->right,data);
    
  }
  else root->left = add(root->left,data);
  return root;
}
int main() {
  int a = 0;
  BST * head;
  head = NULL;

  while(a == 0) {
    cout<<"Enter what you want to do, INPUT to add, FILE to file, DELETE to delete, PRINT to print and SEARCH to search. "<<endl;
    char arr[81];
    cin>>arr;
    int count = 0;
    if(strcmp(arr,"INPUT") == 0) {
        int num;
        cin >> num;
	////     if(count == 0) {
        // head->data = num;
	 ////head->left = NULL;
	// head->right = NULL;
        //} 
    //else {
        add(head,num);
	  //          cout<<head->left->data << endl; 
        count++;
       //insert(head, num);
    }
    else if(strcmp(arr, "FILE") == 0) {
      cout<<"ENTER NUMS IN THE FILEEEEE";
       fstream myfile("numbers.txt");
       string filename("input.txt");
       int number;
       ifstream input_file(filename);
       if (!input_file.is_open()) {
	 cerr << "Could not open file L bozo + ratio + mad cuz bad" << endl;
       }
       
       while (input_file >> number) {
	 add(head,number);
       }
       cout << endl;
       input_file.close();
    }
    else if(strcmp(arr,"PRINT") == 0) {
      //inorder_print(head);
      if (head != NULL)
	print(head,0);
    }
    else if(strcmp(arr,"SEARCH") == 0) {
      bool e = false;
      int num;
      cout<< "Enter your number you want to search";
      cin>> num;
      searchBRUH(head, num, e);
      if(e == true) {
	cout<< "BST contains num";
	cout<<endl;
      }
      else  {
	cout<<" not found";
	cout<<endl;
      }
    }
    //cout<<head->data;
    else if(strcmp(arr,"DELETE") == 0) {
    cout<< "Watchu wana delete?" << endl;
    int ee;
    cin>> ee;
    deleteNode(head, ee, head);
  }

  }
  return 0;
}
