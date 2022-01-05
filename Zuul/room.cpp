#include "room.h"
#include <iostream>
#include <cstring>
//room functions
using namespace std;
void room::printDescription() {
  cout<<description;
}
void room::printDirections() {//directiosn get printed
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
    cout<<endl;
  }
  if(hasnorth == true) {
    cout<<"There is a north exit";
    cout<<endl;
  }
}//items get printed
void room::printItems() {
   cout<<"The following objects in this room are:";
   cout<<endl;
   if(haslaptop == true) {
     cout<<"laptop";
     cout<<endl;
   }
   if(hasmask == true) {
     cout<<"mask";
     cout<<endl;
   }
   if(hascharger == true) {
     cout<<"charger";
     cout<<endl;
   }
   if(hasswag == true) {
     cout<<"swag";
     cout<<endl;
   }
   if(hastrain == true) {
     cout<<"train";
     cout<<endl;
   }
}
