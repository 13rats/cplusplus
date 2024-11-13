#include <iostream>
#include <vector>
#include <cstring>
#include "media.h"

using namespace std; // Holds all the general media commands and functions in the Classes project. Zach Russell, 11/12/24

media::media() {
  title = new char[80];
  year = 0;
}

media::media(char* newtitle){
  title = new char[80];
  strcpy(title, newtitle);
  year = 0;
}

char* media::getTitle() {
  return title;
}

int media::getYear() {
  return year;
}
