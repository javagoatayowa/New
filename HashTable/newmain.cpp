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
  Node** hashtable = new Node* [151];
  Node** hashtable2 = new Node*[302];
  for (int i = 0; i< 151; i++) {
    hashtable[i] = NULL;//making whole table null;
  }
  for(int j = 0; j < 302; j++) {
    hashtable2[j] = NULL;
  }
  int a = 0;
  bool collidnew = false;
  while(a == 0) {
     cout<<"Input your needs! ADD to add, QUIT to quit, PRINT to print, DELETE t\
o delete, and Random to random."<<endl;
    char input[81];
    cin>>input;
    if(strcmp(input,"ADD") == 0) {//add
      char *firstname = new char[81];
      char * secondname = new char[81];
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
	if(collidnew == false && count > 3) {// if there are morethan 3 in a chain and it hasnt been rehashed. 
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
    else if(strcmp(input,"PRINT") == 0) {//print
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
      else {
        for(int i = 0; i < 302; i++) {//if its bigger table
          if(hashtable2[i] != NULL) {
            Node* it = NULL;
            it = hashtable2[i];
            while(it != NULL) {
              cout<< "First name : " << it->firstname << endl;
              cout<<"Second name : " << it->secondname << endl;
              cout<< "id : " << it->id<<endl;
              cout<< "gpa : " <<it->gpa << endl;
              it = it->next;
              //              cout<<"next : " << endl;
            }
            //cout<<"thats one node" << endl;
          }
        }
      }

    }
    else if(strcmp(input,"DELETE") == 0) {//delete
      int idtodelete;
      cout<<"What uw ant to delete?" << endl;
      cin>>idtodelete;
      if(collidnew == false) {
	for(int i = 0; i < 151; i++) {
	  if(hashtable[i] != NULL) {
	    if(hashtable[i]->id == idtodelete) {
	      Node* temp = hashtable[i];
	      hashtable[i] = hashtable[i]->next;
	      delete temp;
	      break;
           }
	    else {
	      Node* it = hashtable[i];
	      while(it->next != NULL) {
		if(it->next->id == idtodelete) {
		  Node* temp = it->next;
		  it->next = it->next->next;
		  delete temp;
		  break;
		}
		it = it->next;
	      }
	    }
	  }
	}
      }
      else {
        for(int i = 0; i < 302; i++) {
          if(hashtable[i] != NULL) {
            if(hashtable[i]->id == idtodelete) {
              Node* temp = hashtable[i];
              hashtable[i] = hashtable[i]->next;
              delete temp;
              break;
           }
            else {
              Node* it = hashtable[i];
              while(it->next != NULL) {
                if(it->next->id == idtodelete) {
                  Node* temp = it->next;
                  it->next = it->next->next;
                  delete temp;
                  break;
                }
                it = it->next;
              }
            }
          }
        }
      }

    }
    else if(strcmp(input,"Random")== 0 ) {
      srand( (unsigned)time(NULL) );//random student generator
      int bruhmane;
      cout<<"how many nums u want?" << endl;
      cin>> bruhmane;
      for(int j= 0; j < bruhmane; j++) {
	//	srand( (unsigned)time(NULL) );
	int ind = rand() %5;
	int ind2 = rand() %5;
	char * arr  = new char[4];
	char * arr2 = new char[4];
	//cout<<index;
	float u;
	u = (float)(rand()%41)/10;
	//      cout<<u;
	if(ind == 0) {
	  strcpy(arr, "bob");
	}
	else if(ind == 1) {
	  strcpy(arr, "oob");
	}
	else if(ind == 2) {
	  strcpy(arr, "obo");
	}
	else if(ind == 3) {
	  strcpy(arr, "oco");
	}
	else if(ind == 4) {
	  strcpy(arr,"ooc");
	}
	if(ind2 == 0) {
	  strcpy(arr2, "ggg");
	}
	else if(ind2 == 1) {
	  strcpy(arr2, "hhh");
	}
	else if(ind2 == 2) {
	  strcpy(arr2, "aaa");
	}
	else if(ind2 == 3) {
	  strcpy(arr2, "lll");
	}
	else if(ind2 == 4) {
	  strcpy(arr2,"ttt");
	}
	Node *randomstud = new Node();
	randomstud->firstname = arr;
	randomstud->secondname = arr2;
	int id = rand();
	randomstud->id = id;
	// cout<<"info abt random student, who you can add to the hash table";
      //   cout<<"first name:" << endl;
      //cout<<endl;
      // cout<<"second name:" << endl;
      // for(int i = 0; i < 3; i++) {
      //        cout<<arr2[i];
      //}
      // cout<<endl;
      //cout<< "id" << endl;
      //cout<< id;
      // cout<< "gpa: " << endl;
	randomstud->gpa = u;
	randomstud->next = NULL;
	int num = 0;
	int length = strlen(arr);
	
	for (int i = 0; i < length; i++) {
	  num = num + arr[i];
	}
	num = num%100;
	//cout<<hashtable[num]->firstname << endl;
	//cout<<head->gpa;
	//cout<<head->firstname<<endl;
	if(hashtable[num] == NULL) {
	  hashtable[num] = randomstud;
	  cout<<"done" << endl;
	  //cout<<hashtable[num]->firstname << endl;
	}
	else {//if collision
	  //cout<<hashtable[num]->firstname << endl;
	  //cout<<"collision" << endl;
	  // collisioncount++;
	  //cout<<collisioncount;
	  Node* temp = hashtable[num];
	  //      cout<<hashtable[num]->firstname;
	  while(temp != NULL) {
	    if(temp->next == NULL) {
	      temp->next = randomstud;
	      break;
	    }
	    temp = temp->next;
          //cout<<hashtable[num]->firstname<<endl;
          //  cout<<hashtable[num]->secondname<<endl;
	  }
	  //cout<<temp->firstname<<endl;
	  //cout<<hashtable[num]->firstname<<endl;
	  //      cout<<hashtable[num]->secondname<<endl;
	}
	Node* temp = hashtable[num];
	while(temp != NULL) {
	  //cout<<temp->gpa;
	  temp = temp->next;
	}
	if(collidnew == false) {
	  //      cout<<collisioncount;
	  for(int i = 0; i < 151; i++) {
	    hashtable2[i*2] = hashtable[i];
	  }
	}
      }
    }
  }
}
