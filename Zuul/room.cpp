#include "room.h"
#include <iostream>
#include <cstring>

using namespace std;
void room::printDescription() {
  cout<<description;
}
void room::printDirections() {
  if(haswest == true) {
    cout<<"There is a west exit";
    cout<<endl;
  }
  if(haseast == true) {
    cout<<"There is a east exit";
    cout<<endl;
  }
  if(hassouth == true) {
    cout<<"There is a south exit";
    cout<<endl
  }
  if(hasnorth == true) {
    cout<<"There is a north exit";
    cout<<endl;
  }
  else {
    cout<<"There are no exits";
    cout<< endl;
  }
}
