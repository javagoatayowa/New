#include <iostream>
#include <cstring>

using namespace std;

class room {
 public:
  char description[100];
  void printDescription();
  bool haswest;
  bool haseast;
  bool hassouth;
  bool hasnorth;
  void printDirections();
}

