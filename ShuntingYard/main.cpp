#include <iostream>//A code created by me to do shunting yard algorithm and to convert equations to infix prefix or postfix. I used help from https://www.includehelp.com/code-snippets/implementation-of-queue-using-linked-list-in-cpp.aspx for queues and stacks: https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/
//Nihal and Ehan also helped me with the bInary tree and its methods.
//3/2/2022
#include <bits/stdc++.h>
#include <ctype.h>
#include "BinaryTree.h"//inclusions
using namespace std;
struct Node {//Node struct for stacks
  Node* link;
  char data;
};
struct QueueN{//Queue Node
  char data;
  QueueN* next;
};
class Queue {//QUeue class
  public:
    QueueN *front,*rear;
    Queue(){front=rear=NULL;}
    void enqueue(char c);
    void dequeue();
    void display2();
    char peek();
    ~Queue();
};//methods below:
char Queue::peek() {
  return front->data;
}
void Queue::enqueue(char c){
    QueueN *temp=new QueueN;
    if(temp==NULL){
        cout<<"Overflow"<<endl;
        return;
    }
    temp->data=c;
    temp->next=NULL;
    if(front==NULL){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}
void Queue::display2(){
    if(front==NULL){
        cout<<"Underflow."<<endl;
        return;
    }
    QueueN *temp=front;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;}

void Queue :: dequeue()
    {
    if (front==NULL){
        cout<<"underflow"<<endl;
        return;
    }
     
    cout<<front->data<<" is being deleted "<<endl;
    if(front==rear)
        front=rear=NULL;
    else
        front=front->next;
}
//destructor
Queue ::~Queue()
{
    while(front!=NULL)
    {
        QueueN *temp=front;
        front=front->next;
        delete temp;
    }
    rear=NULL;
}
Node* head;//head of stacks and binary tree
BinaryTree* BH = NULL;
void push(char data) {//other functions
  Node* temp = new Node();
  if(!temp) {
    exit(1);
  }
  temp->data = data;
  temp->link = head;
  head = temp;
}/*
oid pop() {
  Node* temp;
  if(head == NULL) {
    exit(1);
  }
  else {
    temp = head;
    head = head->link;
    free(head);
  }
  }*/
int isEmpty() {
  return head == NULL;
}
char peek() {
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
    free(temp);
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
char BP(BinaryTree* bH) {
  return bH->datax;
}
void BTpop(BinaryTree* &bH, BinaryTree* &curr) {
  curr = bH;
  bH = bH->next;
}
void postfix(BinaryTree* curr) {
  if(curr->left != NULL) {
    postfix(curr->left);
  }
  if(curr->right != NULL) {
    postfix(curr->right);
  }
  cout<<curr->datax;
}
void prefix(BinaryTree* curr) {
  cout<<curr->datax;
  if(curr->left != NULL) {
    prefix(curr->left);
  }
  if(curr->right != NULL) {
    prefix(curr->right);
  }
}
void infix(BinaryTree* curr) {
  if(curr->left != NULL) {
    infix(curr->left);
  }
  cout<<curr->datax;
  if(curr->right != NULL) {
    infix(curr->right);
  }
}
void BPush(BinaryTree* &bH, BinaryTree* & curr) {
  BinaryTree* temp = curr;
  temp->next = bH;
  bH = temp;
}
int main() {//main
  Queue q;//the queue
  cout<<"enter input" << endl;
  char input2[80];//input
  cin.getline(input2,80);
  //  push('5');//iterating thorugh the array
  for(int i = 0; i < strlen(input2); i++) {
    char l = input2[i];
    if(l == '0' || l == '1' || l == '2' || l == '3' || l == '4' || l == '5' || l == '6' || l == '7' || l == '8' || l == '9') {
      //cout<<i << endl;
      q.enqueue(input2[i]);
      //cout<<input2[i];
      // q.display2();
      //      cout << endl;
    }
    else if(input2[i] == '+' || input2[i] == '-' || input2[i] == '*' || input2[i] == '/'|| input2[i] == '^' || input2[i] == '(') {
      //cout<<input2[i] << endl;
      push(input2[i]);
      //   display();
      //   cout << endl;
    }//if a right parenthesis is detected
    else if(input2[i] == ')') {
      //cout<<input2[i]<<endl;
      char d;
      if(head != NULL) {
	while(head->data != '(') {
	  d = peek();
	  pop();
	  // q.display2();
	  q.enqueue(d);
	}
	pop();
      }
    }
  }
  while(head!= NULL) {
    char d;
    d = peek();    
    // cout<<d<<endl;
    pop();
    q.enqueue(d);
    }
  cout<<"The queue right now is: " << endl;
  q.display2();//queue display
  cout<< endl;
  QueueN *temp = q.front;
  //q.dequeue();
  //cout<<q.peek();//the final binary tree conversion process
  while(temp != NULL) {
    char top = temp->data;
    temp = temp->next;
    //q.dequeue();
    // cout<< top << endl;
    if(isdigit(top)) {
      BinaryTree* newBin = new BinaryTree(top);
      //      cout<<newBin->datax << endl;
      BPush(BH,newBin);
    }
    else {
      BinaryTree* newBin = new BinaryTree(top);
      //cout<<newBin->datax<<endl;
      BinaryTree* tempB = NULL;
      BTpop(BH, tempB);
      newBin->setRight(tempB);
      // cout<<newBin->getRight()->datax;
      BTpop(BH,tempB);
      newBin->setLeft(tempB);
      BPush(BH,newBin);
      //      cout<<newBin->getLeft()->datax;
    }
  }
  //PB(BH);
  cout<<"prefix: ";
  prefix(BH);
  cout<<endl;
  cout<<"postfix: ";
  postfix(BH);
  cout<<endl;
  cout<<"infix: ";
  infix(BH);
  cout<<endl;
  //  display();
  return 0;
}
