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
  exit2 = new char[10];
  exit3 = new char[10];
}

room::room(char* newname, char* newdescription, char* Nexit1, char* Nexit2, char* Nexit3){
  name = new char[10];
  description = new char[200];
  strcpy(name, newname);
  strcpy(description, newdescription);
  id = 0;
  exit1 = new char[10];
  strcpy(exit1, Nexit1);
  exit2 = new char[10];
  strcpy(exit2, Nexit2);
  exit3 = new char[10];
  strcpy(exit3, Nexit3);
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
  char Dexit2[] = "East";
  char Dexit3[] = "North";
  list[0] = new room(dungeonName, dungeonDesc, Dexit1, Dexit2, Dexit3);
  // ROYAL HALL
  char hallName[] = "Royal Hall";
  char hallDesc[] = "A large, grandiose hallway towards the entrance of the castle. Sets of ornate armor flank the walkway, with red \
and gold carpet running down the entire hall.";
  char Hexit1[] = "West";
  char Hexit2[] = "East";
  char Hexit3[] = "North";
  list[1] = new room(hallName, hallDesc, Hexit1, Hexit2, Hexit3);
  // Chapel
  char chapelName[] = "Chapel";
  char chapelDesc[] = "An ornate room, centered with a red hall flanked by rows of pews.";
  char Cexit1[] = "West";
  char Cexit2[] = "East";
  char Cexit3[] = "North";
  list[2] = new room(chapelName, chapelDesc, Cexit1, Cexit2, Cexit3);
}