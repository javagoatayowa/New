#include <iostream>
#include <cstring>
#define COUNT 10
using namespace std;
struct BST {
  int data;
  BST *left;
  BST *right;
};
void print2DUtil(BST *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->data<<"\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
void search2(BST *root, int space, bool  & bruh)
{
    if (root == NULL)
        return;

    search2(root->right, space,bruh);
    if(root->data == space) {
      bruh = true;
      //      root = NULL;
    }
    search2(root->left, space, bruh);
}
void searchBRUH(BST *root, int space, bool & bruh)
{
    // Pass initial space count as 0
   search2(root, space, bruh);
}

// Wrapper over print2DUtil()
void print2D(BST *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

void search(BST *  root, int data, bool & bruh) {
  if (root) {
    search(root->left, data, bruh);
    search(root->right, data, bruh);
  }
  if(root->data == data) {
    bruh = true;
  }
}
void insert2(BST * & root, int & data) {
  //  if(root->data ->d 
}
BST * insert(BST* & root, int & d) {
  if(root == NULL) {
    root = new BST;
    root->data = d;
    root->left = NULL;
    root->right = NULL;
  }
  else if(root->data > d) {
    root->left = insert(root->left,d);
    
  }
  else root->right = insert(root->right,d);
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
        insert(head,num);
	  //          cout<<head->left->data << endl; 
        count++;
       //insert(head, num);
    }
    else if(strcmp(arr,"PRINT") == 0) {
      //inorder_print(head);
      if (head != NULL)
	print2D(head);
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
