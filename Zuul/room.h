#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>

using namespace std;
class room {
 public:
  char description[700];
  void printDescription();
  bool haswest;
  bool haseast;
  bool hassouth;
  bool hasnorth;
  void printDirections();
  bool hasmask;
  bool haslaptop;
  bool hascharger;
  bool hasswag;
  bool hastrain;
  void printItems();
};
#endif
