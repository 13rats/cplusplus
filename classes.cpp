#include <iostream>
#include <vector>
#include <cstring>

using namespace std; // Classes section of Classes project. Creating some of the functions we need for the media objects. Zach Russell, 11/12/24

const int SIZE = 2;

void printArrayTitles(media**, int);
void printVectorTitles(vector<media*> &);

int main() {
  media* list[SIZE];
  vector<media*> vect;
  char* firtTitle = new char[80];
  strcpy(firtTitle, "First Media");
  list[0] = new media(firstTitle);
  char* secondTitle = new char[80];
  strcpy(secondTitle, "Second Media");
  list[1] = new media(secondTitle);
  printArrayTitles(list, SIZE);
  vect.push_back(list[0]);
  vect.push_back(list[1]);
  printVectorTitles(vect);
}

void printArrayDescriptions(media** newlist, int size) {
  for (int a = 0; a < size; a++) {
    cout << newlist[a] -> getTitle() << endl;
  }
}
