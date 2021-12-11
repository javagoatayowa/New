#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H
#include "media.h"//videogames header
class videogames: public media {
public:
  //videogames(char* titleg, int year, char* gpub, char* esrbr);
  char gpub[81];//Mr G!
  char esrbr[81];
  char* getESRBR();
  char* getGPUB();
  void printMedia();
  ~videogames();//destructor
};
#endif
