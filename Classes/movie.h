#ifndef MOVIE_H
#define MOVIE_H
#include "media.h"//movie header file with header guard bc redefinition = bad. This file contains getters and print method.
using namespace std;
class movie: public media {
public:
  int duration;
  char MPCR[81];
  char director[81];
  char* getMPCR();
  char* getDirector();
  int getDuration();
  void printMedia();
  ~movie();
};
#endif
