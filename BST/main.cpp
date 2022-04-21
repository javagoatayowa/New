#include <iostream>
#include <cstring>
using namespace std;
struct BST {
  int data;
  BST *left;
  BST *right;
};
void inorder_print(BST *  root) {
  if (root) {
     inorder_print(root->left);
     cout <<root->data;
     inorder_print(root->right);
  }
}
BST * insert(BST* & root, int & d) {
  if(!root) {
    root = new BST;
    root->data = d;
    root->left = NULL;
    root->right = NULL;
  }
  else if(root->data > d) {
    root->left = insert(root->left,d);
    
  }
  else
    root->right = insert(root->right,d);
  return root;
}
int main() {
  int a = 0;
  while(a == 0) {
    cout<<"Enter what you want to do "<<endl;
    char arr[81];
    cin>>arr;
    int count = 0;
    BST * head;

    if(strcmp(arr,"INPUT") == 0) {
        int num;
        cin >> num;
        if(count == 0) {
         head->data = num;
          head->left = NULL;
           head->right = NULL;
        }  
        else {
          insert(head,num);
	  //          cout<<head->left->data << endl;
        } 
        count++;
       //insert(head, num);
    }
    else if(strcmp(arr,"PRINT") == 0) {
	inorder_print(head);
    }
    //cout<<head->data;

  }
  /*
  cout<<"Enter what you want to do "<<endl;
  char arr[81];
  cin>>arr;
  int count = 0;
  BST * head;
 
  if(strcmp(arr,"INPUT") == 0) {
      int num;
      cin >> num;
      if(count == 0) {
        head->data = num;
	head->left = NULL;
	head->right = NULL;
      }
      else {
	insert(head,num);
	cout<<head->left->data << endl;
      }
  
    return 0;
  */
  return 0;
}
