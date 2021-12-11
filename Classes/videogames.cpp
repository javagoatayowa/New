#include "videogames.h"
#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"//videogames.cpp file, with the getters and this was basically the base of all the other files. 
using namespace std;

char* videogames::getESRBR() {
  return esrbr;
}
char* videogames::getGPUB() {
  return gpub;
}
void videogames::printMedia() {//printer
  cout<<titleg;
  cout<<year;
  cout<<esrbr;
  cout<<gpub;
}
videogames::~videogames() {//DESTRUCTOR HAHAHA!!!
  
}

