#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"
using namespace std;

char* media::getTitleg() {
  return titleg;
}

int media::getYear() {
  return year;
}
void media::printMedia() {
  cout<<titleg;
  //cout<<esrbr;
  //cout<<gpub;
  cout<<year;
}
