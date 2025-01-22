#include <iostream>
#include <cstring>
#include <vector>

using namespace std; // Companion file to the main media file for Classes, defines the variables and functins used and their scope in the broader Classes project. Zach Russell, 11/12/24

class Media {
 public:
  Media();
  Media(char*);
  char* getTitle();
  int getYear();
 private:
  char* title;
  int year;
};
