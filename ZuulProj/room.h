#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class room{
 public:
  room();
  room(int, char*, char*, char*, int, char*, int, char*, int);
  char* getName();
  char* getDescription();
  int getID();
  void defRooms(room*);
  char* exit1;
  char* exit2;
  char* exit3;
  int loc1;
  int loc2;
  int loc3;

 private:
  char* name;
  char* description;
  int id; 
};
