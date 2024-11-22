#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class room{
 public:
  room();
  room(char*, char*, char*, char*, char*);
  char* getName();
  char* getDescription();
  int getID();
  void defRooms(room*);
  char* exit1;
  char* exit2;
  char* exit3;

 private:
  char* name;
  char* description;
  int id;
};
