#include <iostream>
#include <cstring>
#include <vector>
#include "movie.h"//movie cpp with getters and print function
int movie::getDuration() {
  return duration;
}
char* movie::getMPCR() {
  return MPCR;
}
char* movie::getDirector() {
  return director;
}
void movie::printMedia() {
  cout<<titleg;
  cout<<year;
  cout<<MPCR;
  cout<<duration;
}
movie::~movie() {//destructor 
}
