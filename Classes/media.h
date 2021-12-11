#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <cstring>//media 
using namespace std;
class media {

  
  
public:
  char titleg[81];
  int year;
  char* getTitleg();
  int getYear();
  virtual void printMedia();
  ~media();
};


#endif
