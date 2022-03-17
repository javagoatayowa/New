#include <iostream>
using namespace std;
  
// Structure of Linked Lists
struct Node {
    int data;
    Node* next;
};
  
// Driver Code
int main()
{
    int size = 81;
  
    // Pointer To Pointer Array
    Node** head;
  
    // Array of pointers to info struct
    // of size
    head = new Node*[size];
  
    // Initialize pointer array to NULL
    for (int i = 0; i < size; ++i) {
        *(head + i) = NULL;
    }
  
    // Traverse the pointer array
    for (int i = 0; i < size; ++i) {
 
        Node* prev = NULL;
        int s = 4;
  
        while (s--) {
  
            Node* n = new Node;
  

            n->data = i * s;
            n->next = NULL;
            if (*(head + i) == NULL) {
                *(head + i) = n;
            }
            else {
                prev->next = n;
            }
            prev = n;
        }
    }
  
    for (int i = 0; i < size; ++i) {
        Node* temp = *(head + i);
  
        cout << i << "-->\t";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
  
        cout << '\n';
    }
  
    return 0;
}
