#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node* link;
  char data;
};
Node* head;
void push(char data) {
  Node* temp = new Node();
  if(!temp) {
    exit(1);
  }
  temp->data = data;
  temp->link = head;
  head = temp;
}
int isEmpty() {
  return head == NULL;
}
int peek() {
  if(!isEmpty())
    return head->data;
  else {
    exit(1);
  }
}
void pop() {
  Node* temp;
  if(head == NULL) {
    exit(1);
  }
  else {
    temp = head;
    head = head->link;
    free(head);
  }
}
  void display() {
    Node* temp;
    if(temp == NULL) {
      exit(1);
    }
    else {
      temp = head;
      while(temp != NULL) {
	cout<<temp->data << " ->";
	temp = temp->link;
      }
    }
  }
int main() {
   push('c');
   push('5');
   push('H');
   display();
   return 0;
}
