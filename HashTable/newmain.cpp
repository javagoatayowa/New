#include <iostream>
#include <cstring>
#include <array>
#include <iomanip>
using namespace std;
//My code for hash table implementation for student list, by Aneeq Chowdhury. I\
 used https://stackoverflow.com/questions/64166806/c-any-way-to-initialize-sran\
d-multiple-times

struct Node {
  char * firstname;
  char * secondname;
  int id;
  double gpa;
  Node* next;
  int collisioncount;
};//node struct

int main() {
  srand(time(NULL));
  Node** hashtable;
  hashtable = new Node* [151];
  Node** hashtable2;
  hashtable2 = new Node*[302];
  for (int i = 0; i< 151; i++) {
    hashtable[i] = NULL;//making whole table null;
  }
  int a = 0;
  bool collidnew = false;
  while(a == 0) {
     cout<<"Input your needs! ADD to add, QUIT to quit, PRINT to print, DELETE t\
o delete, and Random to random."<<endl;
    char input[81];
    cin>>input;
    if(strcmp(input,"ADD") == 0) {
      char firstname[81];
      char secondname[81];
      int id;
      double gpa;
      cout<<"Give firstname, secondname, id and gpa in this order!"<<endl;
      cin>>firstname;
      cin>>secondname;
      cin>>id;
      cin>>gpa;
      int num = 0;
      int length = strlen(firstname);

      for (int i = 0; i < length; i++) {
        num = num + firstname[i];
      }
      num = num%100;
      Node* bruh = new Node;
      //bruh = NULL;
      bruh->firstname = firstname;
      bruh->secondname = secondname;
      bruh->id = id;
      bruh->gpa = gpa;
      bruh->next = NULL;
      if(collidnew == false) {
	int count = 0;
        if(hashtable[num] == NULL) {
	  hashtable[num] = bruh;
	}
	else {
	  Node* temphead = hashtable[num];
	  while(true) {
	    if(temphead->next == NULL) {
	      temphead->next = bruh;
	      bruh->next = NULL;
	      break;
	    }
	    temphead = temphead->next;
	    if(collidnew == false) {
	      count++;
	    }
	    //lcount++;
	  }
	}
	if(collidnew == false && count > 3) {
	  collidnew = true;
	  count = 0;
	  for(int j = 0; j < 151; j++) {
	    hashtable2[j*2] = hashtable[j];
	  }
	}
      }
      else {
	int num2 = num*2;
	if(hashtable2[num2] == NULL) {
	  hashtable2[num2] = bruh;
	}
	else {
          Node* temphead = hashtable2[num2];
          while(true) {
            if(temphead->next == NULL) {
              temphead->next = bruh;
              bruh->next = NULL;
            }
            temphead = temphead->next;
          } 
	}
      }
    }
    else if(strcmp(input,"QUIT") == 0) {
      a = 1;
    }
    else if(strcmp(input,"PRINT") == 0) {
      if(collidnew == false) {
	for(int i = 0; i < 151; i++) {
	  if(hashtable[i] != NULL) {
	    Node* it = NULL;
	    it = hashtable[i];
	    while(it != NULL) {
	      cout<< "First name : " << it->firstname << endl;
	      cout<<"Second name : " << it->secondname << endl;
	      cout<< "id : " << it->id<<endl;
	      cout<< "gpa : " <<it->gpa << endl;
	      it = it->next;
	      //	      cout<<"next : " << endl;
	    }
	    //cout<<"thats one node" << endl;
	  }
	}
      }
    }
  }
}
