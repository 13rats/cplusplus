#include <iostream>
#include <vector>
#include <cstring>
#include "media.h"

using namespace std; // Holds all the general media commands and functions in the Classes project. Zach Russell, 11/12/24

Media::Media() {
  title = new char[80];
  year = 0;
}

Media::Media(char* newtitle){
  title = new char[80];
  strcpy(title, newtitle);
  year = 0;
}

char* Media::getTitle() {
  return title;
}

int Media::getYear() {
  return year;
}
