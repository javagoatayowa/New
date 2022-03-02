#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node* link;
  char data;
};
struct QueueN{
  char data;
  QueueN* next;
};
class Queue {
  public:
    QueueN *front,*rear;
    Queue(){front=rear=NULL;}
    void enqueue(char c);
    void dequeue();
    void display2();
    ~Queue();
};
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
    //will check until NULL is not found
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
    if(front==rear)//if only one node is there
        front=rear=NULL;
    else
        front=front->next;
}
 
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
Node* head;
void push(char data) {
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
  Queue q;
  cout<<"enter input" << endl;
  char input2[80];
  cin.getline(input2,80);
  //  push('5');
  for(int i = 0; i < strlen(input2); i++) {
    char l = input2[i];
    if(l == '0' || l == '1' || l == '2' || l == '3' || l == '4' || l == '5' || l == '6' || l == '7' || l == '8' || l == '9') {
      q.enqueue(input2[i]);
      //cout<<input2[i];
      q.display2();
      cout << endl;
    }
    else if(input2[i] == '+' || input2[i] == '-' || input2[i] == '*' || input2[i] == '/'|| input2[i] == '^' || input2[i] == '(') {
      //cout<<input2[i] << endl;
      push(input2[i]);
      display();
      cout << endl;
    }
    else if(input2[i] == ')') {
      //cout<<input2[i]<<endl;
      char d;
      while(head->data != '(') {
	d = peek();
	pop();
	q.enqueue(d);
      }
      pop();
    }
    //q.display2();
  while(head!= NULL) {
    char d;
    d = peek();    
    // cout<<d<<endl;
    pop();
    q.enqueue(d);
  }
  }
  q.display2();
  //  display();
  return 0;
}
