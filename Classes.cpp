#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>//got this from ehan
#include "media.h"
#include "videogames.h"//Used Ehans method to add each part to the constructor because my method was not working properly.
using namespace std;
void add(vector<media*> &v) {
  char input;
  cout << "You adding music(m), games(g), or f(films)?"
  cin >> input;
  if (input == 'g') {
      videogame* vg = new videogame();
      cout << "Whats title";
      cin >> vg->titleg;
      cout << "Whats year";
      cin >> vg->year;
      cout << "Who is publisher";
      cin >> vg->pub;
      cout << "Age rating of game(ESRB) format" << endl;
      cin >> vg->rating;
      v.push_back(vg);
  }
  if(input == 'm') {
      music* m = new music();
      cout << "Whats title";
      cin >> m->titleg;
      cout << "Whats the artist name";
      cin >> m->artist;
      cout << "Whats year?";
      cin >> m->year;
      cout << "Duration?";
      cin >> m->duration;
      cout << "Who is publisher? ";
      cin >> m->pub;
      v.push_back(m);
   }
   if(input == 'f') {
      movie* f = new movie();
      cout << "Whats title";
      cin >> f->titleg;
      cout << "Whats director name?";
      cin >> f->director;
      cout << "Whats year?";
      cin >> f->year;
      cout << "Duration?";
      cin >> f->duration;
      cout << "Age Rating?";
      cin >> f->rating;
      v.push_back(f);
   }				
}
void search(vector <media*> v) {
  cout<<"What is the title of the media ur wanting??";
  char title[81];
  cin>>title;
  Vector<media*>::iterator iterator;
  cout<<"Enter title of media";
  for(iterator = v.begin(); iterator<v.end(); iterator++) {
    if(strcmp((iterator*)->titleg),title) {
      if((iterator*)-> rating !=NULL) {
	if((iterator*)->pub != NULL) {
	  cout<<(iterator*)->titleg;
	  cout<<(iterator*)->year;
	  cout<<(iterator*) -> pub;
	  cout<<(iterator*) -> rating;
	}
	else {
	  cout<<(iterator*) -> titleg;
	  cout<<(iterator*) -> artist;
	  cout<<(iterator*) -> year;
	  cout<<(iterator*) -> duration;
	  cout<<(*iterator) ->pub;
	}
      }
      else {
	
      }
      
    }
  }
}
void remove() {
}
int main() {
  vector <media*> v;
  int a = 0; 
  while (a==0) {
    cout<< "what do you want to do?";
    char str[81];
    
    cin>> str;
    if (strcmp(str,"quit") == 0) {
      a = 1;
    }
    else {
      if(strcmp(str,"add") == 0) {
	add(v);
	for(int i=0; i < v.size(); i++)
   std::cout << v.at(i) << ' ';
      }
  }
  return 0;
}
