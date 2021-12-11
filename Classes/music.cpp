#include <iostream>
#include <cstring>
#include<vector>
#include "music.h"//music cpp file with getters and print
using namespace std;
char* music::getGPUB() {
  return gpub;
}
char* music::getArtist(){
  return artist;
}
int music::getDuration() {
  return duration;
}
void music::printMedia() {
  cout<<titleg;
  cout<<year;
  cout<<artist;
  cout<<gpub;
  cout<<duration;
}
music::~music() {//Destruction!

}
