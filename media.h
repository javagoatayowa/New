#include <iostream>
#include <cstring>
#include <vector>
#ifndef mediah
#define mediah

class media {
 protected:
  char titleg[81];
  int year;
  char* getitle();
  int getyear();
  ~virtual ~media();
};

#endif
