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
  name = new char[20];
  description = new char[300];
  strcpy(name, newname);
  strcpy(description, newdescription);
  id = newID;
  exit1 = new char[30];
  strcpy(exit1, Nexit1);
  loc1 = nX1;
  exit2 = new char[30];
  strcpy(exit2, Nexit2);
  loc2 = nX2;
  exit3 = new char[30];
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
  room* dungeon = new room(0, "Dungeon", "A cold and damp brick laden room. Chains hang on some of the walls, the ceiling drips. This is a bad place", "West", 6, "East", 1, "South", 4);
  list[0] = dungeon;

  room* hall = new room(1, "Royal Hall", "A large, grandiose hallway towards the entrance of the castle. Sets of ornate armor flank the walkway, with red and gold carpet running down the entire hall.", "West", 0, "East", 2, "North", 11);
  list[1] = hall;

  room* chapel = new room(2, "Chapel", "An ornate room, centered with a red hall flanked by rows of pews.", "West", 1, "East", 3, "South", 4);
  list[2] = chapel;

  room* grave = new room(3, "Graveyard", "a cold, dark courtyard with gravel and mud scattered around the ground, intterupted by the last rememberances of the departed.", "West", 2, "West again", 1, "West some more", 1);
  list[3] = grave;

  room* armory = new room(4, "Armory", "A brutish red and gold interior, the walls laden with every sort of armament in the known world. This is a place of preperation, a place of war.", "West", 0, "East", 4, "North", 2);
  list[4] = armory;

  room* ohouse = new room(5, "Outhouse", "A smelly, messy place laden with waste and ruin. This place sucks", "West", 4, "West again", 4, "West some more", 4);
  list[5] = ohouse;

  room* hole = new room(6,"Hole","its a very large hole. potentially dug by ninjas. i dont really know.", "Down", 7, "East", 0, "Down again", 7);
  list[6] = hole;
  
  room* ladder = new room(7,"Ladder", "at the bottom of the hole, a small rocky outcrop with wood supporting beams. all that is here are cobwebs, and a ladder up. strangely, not the direction you came.", "Up", 8, "Up please", 8, "Please go up", 8);
  list[7] = ladder;

  room* barn = new room(8,"Barn", "a bright, smelly wooden building full of hay, horses, and god knows what. best not to dwindle, it smells very bad.", "Down", 7, "North", 9, "Trip and fall down the ladder", 7);
  list[8] = barn;

  room* court = new room(9,"Courtyard", "a grassy outcrop, with an open gray sky full of mean looking birds", "South", 8, "East", 10, "Just lie down and stay here", 9);
  list[9] = court;

  room* mill = new room(10,"Mill", "a dark, musty room full of pulp and sawdust. There are rusted blades and forges dotted around the room.", "West", 9, "South", 1, "East", 11);
  list[10] = mill;

  room* keep = new room(11,"Keep", "the main hold of the castle, the keep is full of knick nacks and places to lounge around. really, this is the common area.", "South", 1, "West", 10, "East", 12);
  list[11] = keep;

  room* drag = new room(12,"Chambers", "a large, royal chamber full of gold, topped off by a terrible, sleeping dragon looming over his bulging hoarde.", "West", 11, "East", 13, "Wake him", 14);
  list[12] = drag;

  room* king = new room(13, "Royal Bedroom", "a lavish living quarters, walls decorated with gold and marble, large purple and red banners flank the room.", "West", 12, "Leave", 12, "Go Back", 12);
  list[13] = king;

  room* die = new room(14,"The End", "You try to wake the dragon, and instead it just plain eats you. Nothing big and grandiose, it just eats you. You are now inside the dragon", "No", 14, "Way", 14, "Out", 14);
  list[14] = die;
}
