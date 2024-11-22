#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"

using namespace std;

room::room() {
  name = new char[10];
  description = new char[200];
  id = 0;
  exit1 = new char[10];
  loc1 = 0;
  exit2 = new char[10];
  loc2 = 1;
  exit3 = new char[10];
  loc3 = 2;
}

room::room(int newID, char* newname, char* newdescription, char* Nexit1, int nX1, char* Nexit2, int nX2, char* Nexit3, int nX3){
  name = new char[10];
  description = new char[200];
  strcpy(name, newname);
  strcpy(description, newdescription);
  id = newID;
  exit1 = new char[10];
  strcpy(exit1, Nexit1);
  loc1 = nX1;
  exit2 = new char[10];
  strcpy(exit2, Nexit2);
  loc2 = nX2;
  exit3 = new char[10];
  strcpy(exit3, Nexit3);
  loc3 = nX3;
}

char* room:: getName(){
  return name;
}

char* room:: getDescription(){
  return description;
}

int room::getID(){
  return id;
}
void defRooms(room** list)
{
  // DUNGEON / SPAWN
  char dungeonName[] = "Dungeon";
  char dungeonDesc[] = "A cold and damp brick laden room. Chains hang on some of the walls, the ceiling drips. This is a bad place";
  char Dexit1[] = "West";
  int DnX1 = 2;
  char Dexit2[] = "East";
  int DnX2 = 1;
  char Dexit3[] = "North";
  int DnX3 = 1;
  list[0] = new room(0, dungeonName, dungeonDesc, Dexit1, DnX1, Dexit2, DnX2, Dexit3, DnX3);
  // ROYAL HALL
  char hallName[] = "Royal Hall";
  char hallDesc[] = "A large, grandiose hallway towards the entrance of the castle. Sets of ornate armor flank the walkway, with red \
and gold carpet running down the entire hall.";
  char Hexit1[] = "West";
  int HnX1 = 0;
  char Hexit2[] = "East";
  int HnX2 = 0;
  char Hexit3[] = "North";
  int HnX3 = 0;
  list[1] = new room(1, hallName, hallDesc, Hexit1, HnX1, Hexit2, HnX2, Hexit3, HnX3);
  // Chapel
  char chapelName[] = "Chapel";
  char chapelDesc[] = "An ornate room, centered with a red hall flanked by rows of pews.";
  char Cexit1[] = "West";
  int CnX1 = 0;
  char Cexit2[] = "East";
  int CnX2 = 0;
  char Cexit3[] = "North";
  int CnX3 = 0;
  list[2] = new room(2, chapelName, chapelDesc, Cexit1, CnX1, Cexit2, CnX2, Cexit3, CnX3);
}
