#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <cstring>
using namespace std;
class media {
protected:
  char titleg[81];
  int year;

  
  
public:
  media(char*titleg, int year){
   virtual void print();
  char* getTitleg();
  int getyear();
  virtual ~media();
  } 
};


#endif
