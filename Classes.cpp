#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>//got this from ehan
#include "media.h"
#include "videogames.h"
#include "music.h"
#include "movie.h"
//Used Ehans method to add each part to the constructor because my method was not working properly, and also got some help in the .h  and overall class interaction part of video games and media.h. (I wanted to make sure if I was doing the right thing)
using namespace std;
void add(vector<media*> &v) {//add function
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
void search(vector <media*> v&) {//search
  cout<<"What is the title of the media ur wanting??";
  char title[81];
  cin>>title;
  Vector<media*>::iterator iterator;
  for(iterator = v.begin(); iterator<v.end(); iterator++) {//Checking if the iterator(the media) has characteristics of a game, movie or music.
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
	cout<<(iterator*)->titleg;
	cout<<(iterator*)-> artist;
	cout<<(iterator*)-> year;
	cout<<(iterator*) -> duration;
	cout<<(iterator*) ->pub;
      } 
    }
  }
}
void remove(vector <media*> v&) {//remover
  cout<<"What is the title of the media ur deleting??";
  char title[81];
  cin>>title;
  Vector<media*>::iterator iterator;
  cout<<"You are deleting the following:";
  int count;
  for(iterator = v.begin(); iterator<v.end(); iterator++) {
    //Checking if the iterator(the media) has characteristics of a game, movie or music.
    count++;
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
          cout<<(iterator*) ->pub;
        }
      }
      else {
        cout<<(iterator*)->titleg;
        cout<<(iterator*)-> artist;
        cout<<(iterator*)-> year;
        cout<<(iterator*) -> duration;
        cout<<(iterator*) ->pub;
      }
    }
    cout<<"you going to delete?";
    char yn;
    cin>>yn;
    if(yn == 'y') {
      cout<<"Thats pretty tough.";
      v.erase(v.begin()+count);
    }
    else{
      cout<<"Okay";
    }
  }

}
int main() {//where everything gets called the main method
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
      }
      else if(strcmp(str,"search") == 0) {
	search(v);
      }
      else if(strcmp(str,"remove") == 0) {
	remove(v);
      }
  }
  return 0;
}
