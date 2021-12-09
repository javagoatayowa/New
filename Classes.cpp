#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>//got this from ehan
#include "media.h"
#include "videogames.h"
using namespace std;
void add(<media*> &v) {
  cout<<"You adding m(movie), g(games), or f(films)?";
  char c;
  cin>> c;
  if(c == g) {
    cout<<"what is the title?";
    char titleg[81];
    cin>>titleg;

    cout<<"what is the year?";
    int year;
    cin>>year;
    cout<<"who published it?";
    char publisher[81];
    cin>> publisher;
    cout<<"whats your age rating?(Esrb)?";
    char rating[81];
    cin>>rating;
    videogame* vg = new videogame(titleg, year, publisher, rating);
    v.pushback(vg);

  }

  if(c == 'f') {
    cout<<"What is the title?";
    char titleg[81];
    cin>> titleg;

    cout<<"what is the year?";
    int year;
    cin>>year;
    cout<<"who is the director";
    char director[81];
    cin>>director;
    cout<<"who published it?";
    char publisher[81];
    cin>> publisher;
    cout<<"whats the rating?";
    char rating[81];
    cin>> rating;

    movie* mv = new movie(titleg, year, director, publisher, rating);
    v.pushback(mv);

  }



  }
  if(c == 'm') {
    cout<"What is the artist?";
    char artist[81];
    cin>>artist;

    cout<<"what is the year?";
    char year[81];
    cin>>year;
    cout<<"who published it?";
    char publisher[81];
    cin>> publisher;
    cout<<"whats the rating?";
    char rating[81];
    cin>>rating;

    movie* mv = new movie(titleg, year, publisher, rating);
    v.pushback(m);
  }

  
  }
void search() {
}
void remove() {
}
int main() {
  vector <media*>
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
	for(int i=0; i < m.size(); i++)
   std::cout << m.at(i) << ' ';
      }
  }
  return 0;
}
