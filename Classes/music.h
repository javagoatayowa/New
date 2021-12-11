#ifndef MUSIC_H
#define MUSIC_H
#include "media.h"
using namespace std;
class music: public media {//music header with defining getters and state of the art method names. 
public:
  char gpub[81]; //Mr G!(Yes, I did this on another file too)
  int duration;
  char artist[81];
  char* getArtist();
  char* getGPUB();
  int getDuration();
  void printMedia();
  ~music();//OH NO, IS THAT A DESTRUCTOR! NOOOO(I know I am not funny)
};
#endif
