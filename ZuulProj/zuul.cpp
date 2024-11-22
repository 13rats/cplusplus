#include <iostream>
#include <string.h>
#include <cstring>
#include "room.cpp"
#include <map>

using namespace std;
const int SIZE = 3;

void printArrayDescriptions(room**, int);

int main()
{ 
  room* list[SIZE];
  defRooms(list);
  printArrayDescriptions(list,SIZE);
}

void printArrayDescriptions(room** newlist, int size) {
  for(int a = 0; a < size; a++){
    cout << (*newlist[a]).getName() << "; " << (*newlist[a]).getDescription() << " There are exits to the: " << (*newlist[a]).exit1<< " and " << (*newlist[a]).exit2 << " and " << (*newlist[a]).exit3 << endl;
  }
}
