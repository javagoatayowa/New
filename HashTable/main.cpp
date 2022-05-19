#include <iostream>
#include <cstring>
#include <array>
#include <iomanip>
using namespace std;
//My code for hash table implementation for student list, by Aneeq Chowdhury. I used https://stackoverflow.com/questions/64166806/c-any-way-to-initialize-srand-multiple-times

struct Node {
  char * firstname;
  char * secondname;
  int id;
  double gpa;
  Node* next;
  int collisioncount;
};//node struct
int main() {//main method
  //int index = rand() %5;
  srand(time(NULL));     
  Node** hashtable;
  hashtable = new Node* [151];
  Node** hashtable2;
  hashtable2 = new Node*[302];
  for (int i = 0; i< 151; i++) {
    hashtable[i] = NULL;//making whole table null;
  }
  int a = 0;
  int collisioncount = 0;
  while(a == 0) {
    cout<<"Input your needs! ADD to add, QUIT to quit, PRINT to print, DELETE to delete, and Random to random."<<endl;
    char input[81];
    cin>>input;
    if(strcmp(input,"ADD") == 0) {// add function
      char firstname2[81];
      char secondname2[81];
      int id;
      double gpa;
      cout<<"Give firstname, secondname, id, and gpa"<<endl;
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
      Node* temp = new temp();
      temp->firstname = firstname2;
      temp->secondname = secondname2;
      temp->id = id;
      temp->gpa = gpa;
      temp->next = NULL;
      //cout<<hashtable[num]->firstname << endl;
      //cout<<head->gpa;
      //cout<<head->firstname<<endl;
      if(hashtable[num] == NULL) {
	 hashtable[num] = temp;
	 cout<<"done" << endl;
         //cout<<hashtable[num]->firstname << endl;
      }
      else {//if collision
	//cout<<hashtable[num]->firstname << endl;
	//cout<<"collision" << endl;
	collisioncount++;
	//cout<<collisioncount;
	Node* temp2 = hashtable[num];
	//	cout<<hashtable[num]->firstname;
	while(temp2 != NULL) {
	  if(temp2->next == NULL) {
	    temp2->next = temp;
	    break;
	  }
	  temp2 = temp2->next;
	  //cout<<hashtable[num]->firstname<<endl;
	  //  cout<<hashtable[num]->secondname<<endl;
	}
	//cout<<temp->firstname<<endl;
	//cout<<hashtable[num]->firstname<<endl;
	//	cout<<hashtable[num]->secondname<<endl;
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
      //delete[] firstname2;
      //      delete[] secondname2;
    }
    else if(strcmp(input,"QUIT") == 0) {
      a = 1;//quit method
    }//print 
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
	      cout<< setprecision(3) << temp->gpa << endl;
	      temp = temp->next;
	    }
	    //   cout<<temp->firstname << endl;
	    //	    cout<<temp->secondname << endl;
	  }
        }
      }
    }
    else if(strcmp(input,"DELETE") == 0) {//delete method
      int id2;
      cout<<"Which id you want to delete? " << endl;
      cin>>id2;
      if(collisioncount <= 3) {
	for(int i = 0; i < 151; i++) {
	  if(hashtable[i]->id == id2) {
	    
	  }
	}
      }
	/*
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
	    */
	/*
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
	*/
    }
       /*
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
       */
    else if(strcmp(input,"Random")== 0 ) {//random student generator
      //     int index = rand() % 5;
      //      cout<<index;
      //      int index2 = rand() % 5;
      //cout << index2;
      /*
      double u;
      for (int i = 0; i < 1; i++) 
      {
         u =  (float) rand()/5;
      }
      cout<<u * 10;
      */
      int bruhmane;
      cout<<"how many nums u want?" << endl;
      cin>> bruhmane;
      for(int j= 0; j < bruhmane; j++) {
	srand( (unsigned)time(NULL) ); 

      int index = rand() %5;
      int index2 = rand() %5;
      char arr[4];
      char arr2[4];
      //cout<<index;
      float u;
      u = (float)(rand()%41)/10;
      //      cout<<u;
      if(index == 0) {
	strcpy(arr, "bob");
      }
      else if(index == 1) {
        strcpy(arr, "oob");
      }
      else if(index == 2) {
        strcpy(arr, "obo");
      }
      else if(index == 3) {
        strcpy(arr, "oco");
      }
      else if(index == 4) {
	strcpy(arr,"ooc");
      }
      if(index2 == 0) {
        strcpy(arr2, "ggg");
      }
      else if(index2 == 1) {
        strcpy(arr2, "hhh");
      }
      else if(index2 == 2) {
        strcpy(arr2, "aaa");
      }
      else if(index2 == 3) {
        strcpy(arr2, "lll");
      }
      else if(index2 == 4) {
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
      //	cout<<arr2[i];
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
        collisioncount++;
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
      if(collisioncount > 3) {
        //      cout<<collisioncount;
        for(int i = 0; i < 151; i++) {
          hashtable2[i*2] = hashtable[i];
        }
      }
      }
      /*
      for(int j = 0; j < bruhmane; j++) {
	rand((unsigned)time(NULL));

	int index = rand() %5;
	int index2 = rand() %5;
	char arr[4];
	char arr2[4];
	//cout<<index;
	float u;
	u = (float)(rand()%41)/10;
	//      cout<<u;
	if(index == 0) {
	  strcpy(arr, "bob");
	}
	else if(index == 1) {
	  strcpy(arr, "oob");
	}
	else if(index == 2) {
	  strcpy(arr, "obo");
	}
	else if(index == 3) {
        strcpy(arr, "oco");
	}
	else if(index == 4) {
	  strcpy(arr,"ooc");
	}
	if(index2 == 0) {
	  strcpy(arr2, "ggg");
	}
	else if(index2 == 1) {
	  strcpy(arr2, "hhh");
	}
	else if(index2 == 2) {
	  strcpy(arr2, "aaa");
	}
	else if(index2 == 3) {
	  strcpy(arr2, "lll");
	}
	else if(index2 == 4) {
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
	  collisioncount++;
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
	if(collisioncount > 3) {
	  //      cout<<collisioncount;
	  for(int i = 0; i < 151; i++) {
	    hashtable2[i*2] = hashtable[i];
	  }
	}
	//cout<<setprecision(3) << u
      }
      //cout<<setp
      */
    }
    
  }
  return 0;
}
      /*
rand( (unsigned)time(NULL) );

      int index = rand() %5;
      int index2 = rand() %5;
      char arr[4];
      char arr2[4];
      //cout<<index;
      float u;
      u = (float)(rand()%41)/10;
      //      cout<<u;
      if(index == 0) {
        strcpy(arr, "bob");
      }
      else if(index == 1) {
        strcpy(arr, "oob");
      }
      else if(index == 2) {
        strcpy(arr, "obo");
      }
      else if(index == 3) {
        strcpy(arr, "oco");
      }
      else if(index == 4) {
        strcpy(arr,"ooc");
      }
      if(index2 == 0) {
        strcpy(arr2, "ggg");
      }
      else if(index2 == 1) {
        strcpy(arr2, "hhh");
      }
      else if(index2 == 2) {
        strcpy(arr2, "aaa");
      }
      else if(index2 == 3) {
        strcpy(arr2, "lll");
      }
      else if(index2 == 4) {
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
rand( (unsigned)time(NULL) );

      int index = rand() %5;
      int index2 = rand() %5;
      char arr[4];
      char arr2[4];
      //cout<<index;
      float u;
      u = (float)(rand()%41)/10;
      //      cout<<u;
      if(index == 0) {
        strcpy(arr, "bob");
      }
      else if(index == 1) {
        strcpy(arr, "oob");
      }
      else if(index == 2) {
        strcpy(arr, "obo");
      }
      else if(index == 3) {
        strcpy(arr, "oco");
      }
      else if(index == 4) {
        strcpy(arr,"ooc");
      }
      if(index2 == 0) {
        strcpy(arr2, "ggg");
      }
      else if(index2 == 1) {
        strcpy(arr2, "hhh");
      }
      else if(index2 == 2) {
        strcpy(arr2, "aaa");
      }
      else if(index2 == 3) {
        strcpy(arr2, "lll");
      }
      else if(index2 == 4) {
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
OAOAOAOA         cout<<"done" << endl;
OAOA         //cout<<hashtable[num]->firstname << endl;
OAOA      }
OAOA      else {//if collision
OAOA        //cout<<hashtable[num]->firstname << endl;
        //cout<<"collision" << endl;
OAOA        collisioncount++;
OAOAOA        //cout<<collisioncount;
OA        Node* temp = hashtable[num];
        //      cout<<hashtable[num]->firstname;
OAOA        while(temp != NULL) {
OAOA          if(temp->next == NULL) {
OA            temp->next = randomstud;
OAOA            break;
          }
OA          temp = temp->next;
OA          //cout<<hashtable[num]->firstname<<endl;
          //  cout<<hashtable[num]->secondname<<endl;
OAOA        }
        //cout<<temp->firstname<<endl;
OAOA        //cout<<hashtable[num]->firstname<<endl;
        //      cout<<hashtable[num]->secondname<<endl;
OAOA      }
      Node* temp = hashtable[num];
OAOA      while(temp != NULL) {
        //cout<<temp->gpa;
OAOA        temp = temp->next;
      }
OA      if(collisioncount > 3) {
        //      cout<<collisioncount;
        for(int i = 0; i < 151; i++) {
          hashtable2[i*2] = hashtable[i];
OA        }
      }
OA
      //cout<<setprecision(3) << u;

       */

