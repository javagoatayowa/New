#include <iostream>
#include <cstring>
#include <vector>
#include <limits>
#include "media.h"
#include "videogames.h"
using namespace std;//Used a lot of nihals help because he helped me fix errors, he helped me with my search method. 
void add(vector<media*> &v) {//add function
  //music* musicp = new Music();
  //movie* moviep = new Movies();
  videogames* gamep = new videogames();
  char input;
  cout << "You adding music(m), games(g), or f(films)?" << endl;
  cin >> input;
  if (input == 'g') {
      char titleg[81];
      int year;
      char gpub[81];
      char esrbr[81];
      cout << "Whats title";
      cin >> gamep->titleg;
      cout << "Whats year";
      cin >> gamep->year;
      cout << "Who is publisher";
      cin >> gamep->gpub;
      cout << "Age rating of game(ESRB) format" << endl;
      cin >> gamep->esrbr; 
      (v).push_back(gamep);
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
void searchMedia(vector<media*> &v) {//search function
  char input1[10];
  cout << "t or y?" << endl;
  cin >> input1;
  cin.ignore();
  if (strcmp(input1, "t") == 0) {
    char input[50];
    cout << "title:" << endl;
    cin.getline(input, 50);
    for (int i = 0; i < v.size(); i++) {
      if (strcmp(v[i]->titleg, input) == 0) {
	v[i]->printMedia();
	cout<<endl;
      }
    }
    


  }
  else if (strcmp(input1, "y") == 0) {
    int input2;
    cout << "year:" << endl;
    cin >> input2;
    for (int i = 0; i < v.size(); i++) {
      if (v[i]->year == input2) {
        v[i]->printMedia();
      }
    }

  }

}

int main(){//main method
  vector <media*> media;
  int a = 0;
  cout<<"what do you want to do?";
  while (a == 0) {
    char str[81];

    cin>> str;
    if (strcmp(str,"quit") == 0) {
      a = 1;
    }
    else {
      if(strcmp(str,"add") == 0) {
	add(media);
	cout<<"What else do you want to do?";
      }
      else if(strcmp(str,"search") == 0) {
	searchMedia(media);
	cout<<"What else do you need to do?";
      }
    }
  }
}
