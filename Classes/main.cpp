#include <iostream>
#include <cstring>
#include <vector>
#include <limits>
#include "media.h"
#include "videogames.h"
using namespace std;
void add(vector<media*> &v) {//add function
  char input;
  cout << "You adding music(m), games(g), or f(films)?" << endl;
  cin >> input;
  if (input == 'g') {
      char titleg[81];
      int year;
      char gpub[81];
      char esrbr[81];
      cout << "Whats title";
      cin >> titleg;
      cout << "Whats year";
      cin >> year;
      cout << "Who is publisher";
      cin >> gpub;
      cout << "Age rating of game(ESRB) format" << endl;
      cin >> esrbr;
      videogames* vg = new videogames(titleg, year, gpub, esrbr); 
      v.push_back(vg);
  }
  /*
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
  */
}

int main(){
  vector <media*> media;
  int a = 0;
  while (a == 0) {
     cout<< "what do you want to do?";
    char str[81];

    cin>> str;
    if (strcmp(str,"quit") == 0) {
      a = 1;
    }
    else {
      if(strcmp(str,"add") == 0) {
	add(media);
      }
    }
  }
}
