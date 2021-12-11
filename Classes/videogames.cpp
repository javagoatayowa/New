#include "videogames.h"
#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"
using namespace std;

char* videogames::getESRBR() {
  return esrbr;
}
char* videogames::getGPUB() {
  return gpub;
}
void videogames::printMedia() {
  cout<<titleg;
  cout<<year;
  //cout<<getESRBR();
  //cout<<getGPUB();
}
