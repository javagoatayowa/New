#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H
#include "media.h"
class videogames: public media {
  char gpub[81];//Mr G!
  char esrbr[81];
public:
  videogames(char* titleg, int year, char* gpub, char* esrbr);
  char* getESRBR();
  char* getGPUB();
  void printVG();
  

};
#endif
