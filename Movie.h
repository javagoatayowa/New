#include "media.h"

class movie:: public media{
  int duration;
  char rating[81];
  char director[81];
  int getDuration();
  char* getRating();
  char* getDirector();
  ~movie();
};
int main() {
}


