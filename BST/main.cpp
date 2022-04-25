//Code created by Aneeq Chowdhury due 4/24/2021. Im v sick Mr Galbraith, sry for not showing up in advance. This code is a binary search tree and it deletes and adds and all sorts of excitigng stuff! I used Karla fants notes, and Geekfs for geek print https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/, and I also learned from a Java website on how to delete from BST. https://www.java2novice.com/java-interview-programs/delete-node-binary-search-tree-bst/.
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
struct BST {
  int data;
  BST *left;
  BST *right;
};
int minValue(BST* node) {
  if(node->left == NULL) {
    return minValue(node->left);
  }
  return node->data;
}

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
    cout<<"Enter what you want to do "<<endl;
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
    deleteBRUH(head, ee);
  }

  }
  return 0;
}
