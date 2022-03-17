#include <iostream>
#include <cstring>

using namespace std;

struct Node {
  char * firstname;
  char * secondname;
  int id;
  double gpa;
  Node* next;
};
int main() {
  Node** hashtable;
  hashtable = new Node* [151];
  Node** hashtable2;
  hashtable2 = new Node*[302];
  for (int i = 0; i< 151; i++) {
    hashtable[i] = NULL;
  }
  int a = 0;
  int collisioncount = 0;
  while(a == 0) {
    char input[81];
    cin>>input;
    if(strcmp(input,"ADD") == 0) {
      char firstname2[81];
      char secondname2[81];
      int id;
      double gpa;
      cin>>firstname2;
      cin>>secondname2;
      cin>>id;
      cin>>gpa;
      int num = 0;
      int length = strlen(firstname2);
      
      for (int i = 0; i < length; i++) {
	num = num + firstname2[i];
      }
      num = num%100;
      Node* head = new Node();
      head->firstname = firstname2;
      head->secondname = secondname2;
      head->id = id;
      head->gpa = gpa;
      head->next = NULL;
      //cout<<head->gpa;
      if(hashtable[num] == NULL) {
	 hashtable[num] = head;
	 cout<<"done" << endl;
         cout<<hashtable[num]->firstname << endl;
      }
      else {
	cout<<"collision" << endl;
	collisioncount++;
	cout<<collisioncount;
	Node* temp = hashtable[num];
	cout<<hashtable[num]->firstname;
	while(temp != NULL) {
	  if(temp->next == NULL) {
	    temp->next = head;
	    break;
	  }
	  temp = temp->next;
	  //cout<<hashtable[num]->firstname<<endl;
	  //  cout<<hashtable[num]->secondname<<endl;
	}
	//cout<<temp->firstname<<endl;
	//cout<<hashtable[num]->firstname<<endl;
	//	cout<<hashtable[num]->secondname<<endl;
      }
      Node* temp = hashtable[num];
      while(temp != NULL) {
	//cout<<temp->gpa;
	temp = temp->next;
      }
      if(collisioncount > 3) {
	//	cout<<collisioncount;
	for(int i = 0; i < 151; i++) {
	  hashtable2[i*2] = hashtable[i];
	}
      }
      /*
      for(int i = 0; i < 302; i++) {
	if(hashtable2[i] != NULL) {
	  cout<<hashtable2[i]->gpa;
	}
      }
      */
    }
    else if(strcmp(input,"QUIT") == 0) {
      a = 1;
    }
    else if(strcmp(input,"PRINT") == 0) {
      if(collisioncount > 3) {
	for(int i = 0; i < 302; i++) {
	  Node* temp = hashtable2[i];
	  while(temp != NULL) {
	    cout<< temp->firstname << endl;
	    cout<< temp->secondname<< endl;
	    cout<< temp->id << endl;
	    cout<< temp->gpa<< endl;
	    temp = temp->next;
	  }
	}
      }
      else {
	for(int i = 0; i < 151; i++) {
	  if(hashtable[i] != NULL) {
	    Node* temp = hashtable[i];
	    while(temp != NULL) {
	      cout<<temp->firstname << endl;
	      cout<< temp->secondname<<endl;
	      cout<< temp->id << endl;
	      cout<< temp->gpa << endl;
	      temp = temp->next;
	    }
	    cout<<temp->firstname << endl;
	    cout<<temp->secondname << endl;
	  }
        }
      }
    }
    else if(strcmp(input,"DELETE") == 0) {
      cout<<"Who do you want to delete?" << endl;
      int idin;
      cin>>idin;
      if(collisioncount > 3) {
	for(int i = 0; i < 302; i++) {
	  Node* temp = hashtable2[i];
	  Node* aftertemp = hashtable2[i]->next;
	  while(aftertemp != NULL) {
	    if(aftertemp->id == idin) {
	      temp->next = aftertemp->next;
	      break;
	    }
	    aftertemp = aftertemp->next;
	    temp = temp->next;
	  }
	}
	for(int i = 0; i < 302; i++) {
	  Node* temp = hashtable2[i];
	  while(temp != NULL) {
	    cout<<temp->gpa << endl;
	  }
	}
      }
      else {
	for(int i = 0; i < 151; i++) {
          Node* temp = hashtable[i];
          Node* aftertemp = hashtable[i]->next;
          while(aftertemp != NULL) {
            if(aftertemp->id == idin) {
              temp->next = aftertemp->next;
              break;
            }
            aftertemp = aftertemp->next;
            temp = temp->next;
          }
        }
        for(int i = 0; i < 151; i++) {
          Node* temp = hashtable[i];
          while(temp != NULL) {
            cout<<temp->gpa << endl;
          }
        }

      }
    }
  }
  return 0;
}
