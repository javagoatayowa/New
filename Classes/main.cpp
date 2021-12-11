//Aneeq Chowdhury Program to help users add video games and print them out in a database
#include <iostream>
#include <cstring>
#include <vector>
#include <limits>
#include "media.h"
#include "videogames.h"
#include "music.h"
#include "movie.h"
using namespace std;//Used a lot of nihals help because he helped me fix errors, he helped me with my search method. He also explained virtual functions to me and destructors 
void add(vector<media*> &v) {//add function
  music* musicp = new music();
  movie* f = new movie();
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
  if(input == 'm') {//if music
      char titleg[81];
      int year;
      char artist[81];
      int duration;
      char gpub[81];
      cout << "Whats title";
      cin >> musicp->titleg;
      cout << "Whats the artist name";
      cin >> musicp->artist;
      cout << "Whats year?";
      cin >> musicp->year;
      cout << "Duration?";
      cin >> musicp->duration;
      cout << "Who is publisher? ";
      cin >> musicp->gpub;//I honestly dont know why this is still called gpub, but hey! That works too!
      v.push_back(musicp);
   }
  if(input == 'f') {//if movie
     char titleg[81];
      int year;
      char duration[81];
      char MPCR[81];
      cout << "Whats title";
      cin >> f->titleg;
      cout << "Whats director name?";
      cin >> f->director;
      cout << "Whats year?";
      cin >> f->year;
      cout << "Duration?";
      cin >> f->duration;
      cout << "Age Rating?";
      cin >> f->MPCR;
      v.push_back(f);
   }
}
void removeMedia(vector<media*> &v) {//search function
  char input1;
  cout << "t or y?" << endl;
  cin >> input1;
  cin.ignore();//two if statements to se what thye wanna search by
  if (input1 == 't') {
    char input[50];
    cout << "title:" << endl;
    cin.getline(input, 50);
    cout<<"Heres what ur deleting";
    for (int i = 0; i < v.size(); i++) {//findidng the part
      if (strcmp(v[i]->titleg, input) == 0) {
	v[i]->printMedia();
	cout<<endl;
	 cout<< "You sure you want to delete this?";
	 char yn;
	 cin>>yn;
	 if (yn == 'y') {
	   v.erase(v.begin()+i);
	 }


      }
    }


  }
  else if (input1 == 'y') {
    int input2;
    cout << "year:" << endl;
    cin >> input2;
    for (int i = 0; i < v.size(); i++) {
      if (v[i]->year == input2) {
        v[i]->printMedia();
	char yn2;
	cin>>yn2;
	if(yn2 == 'y') {
	  v.erase(v.begin()+i);
	}
      }
    }

  }

}
void searchMedia(vector<media*> &v) {//search function
  char input1;
  cout << "t or y?" << endl;
  cin >> input1;
  cin.ignore();
  if (input1 == 't') {
    char input[50];
    cout << "title:" << endl;
    cin.getline(input, 50);
    for (int i = 0; i < v.size(); i++) {//finding the media and printing it with the print functions
      if (strcmp(v[i]->titleg, input) == 0) {
        v[i]->printMedia();
        cout<<endl;
      }
    }



  }
  else if (input1 == 'y') {
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
  cout<<"what do you want to do? add to add, search to search, and remove to remove!";
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
      else if(strcmp(str,"remove") == 0) {
	removeMedia(media);
	cout<<"what else do you need to do?";
      }
    }
  }
}
