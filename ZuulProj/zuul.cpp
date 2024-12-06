#include <iostream>
#include <string.h>
#include <cstring>
#include "room.cpp"
#include <map>

using namespace std;
const int SIZE = 15;

void printArrayDescriptions(room**, int, map<int, char*>&);
void printRoomInfo(room*, room**, map<int, char*>&);
void doItemStuff(map<int, char*>&mp);

int main()
{
  room* list[SIZE];
  defRooms(list);
  room* currentRoom = list[0];
  map<int, char*> mp;
  doItemStuff(mp);
  map<int, char*> inv;
  cout << "WELCOME MESSAGE" << endl;

  while (true) {
    cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << endl;
    printRoomInfo(currentRoom, list, mp);
    if(currentRoom->getID() < 13){
      cout << "enter the direction you would like to go (ex. North). You may also e\
nter 'Take' to collect any items in the room, 'Inventory' to check your inventory, 'Drop' to drop an item, or 'Quit' to quit the game." << endl;
      char* input = new char[30];
      cin.getline(input, '\n');
      if(strcmp(input, (currentRoom->exit3)) == 0){
	int norLoc = currentRoom->loc3;
	currentRoom = list[norLoc];
      }
      else if(strcmp(input, (currentRoom->exit2)) == 0){
	int eastLoc = currentRoom->loc2;
	currentRoom = list[eastLoc];
      }
      else if (strcmp(input, (currentRoom->exit1)) == 0){
	int wesLoc = currentRoom->loc1;
	currentRoom = list[wesLoc];
      }
      else if (strcmp(input, "Inventory") == 0){
	for (int i = 0; i < inv.size(); i++){
	  cout << i << "; " << inv[i] << endl;
	}
	cout << "That's all you got." << endl;
      }
      else if (strcmp(input, "Quit") == 0){
	exit(0);
      }
      else if (strcmp(input, "Take") == 0){
	if (strcmp(mp[currentRoom->getID()], "-") != 0){
	  inv.insert(make_pair(inv.size(), mp[currentRoom->getID()]));
	  char* emptyItem = new char[10];
	  strcpy(emptyItem, "-");
	  mp[currentRoom->getID()] = emptyItem;
	}
	cout << "You picked up a " << inv[inv.size() - 1] << endl;
      }
      else if (strcmp(input, "Drop") == 0){
	cout << "What do you want do drop? Enter the item's number." << endl;
	for (int i = 0; i < inv.size(); i++){
	  cout << i << "; " << inv[i] << endl;
	}
	char* input = new char[10];
	cin.getline(input, '\n');
	int inpInt = atoi(input);
	cout << "okay, dropping " << inv[inpInt] << endl;
	mp[currentRoom->getID()] = inv[inpInt];
	inv.erase(inpInt);
	for(int i = inpInt + 1; i < inv.size() + 1; i++){
	  inv[i - 1] = inv[i];
	  if (i == inv.size() - 1){
	    inv.erase(i);
	  }
	}
      }
      else{
	cout << "invalid command" << endl;
      }
    }
    else if (currentRoom->getID() == 13){
      cout << "You have found the king! congratulations <3 you saved him !!!!" << endl;
      exit(0);
    }
    else if (currentRoom->getID() == 14){
      cout << "The dragon has eaten you. nothing much to do besides wait around to be digested. Nice one." << endl;
      exit(0);
    }
  }
}

void printArrayDescriptions(room** newlist, int size, map<int, char*> &mp)  {
  for(int a = 0; a < size; a++){
    cout << (*newlist[a]).getName() << "; " << (*newlist[a]).getDescription() << " There are exits to the: " << (*newlist[a]).exit1<< " and " << (*newlist[a]).exit2 << " and " << (*newlist[a]).exit3;
    if(mp.size() - 1 >= a){
      cout << " The items in the room are : " << mp[a] << endl;
    }
  }
}

void printRoomInfo(room* cur, room** newlist, map<int, char*> &mp){
  char* curName = (cur)->getName();
  char* curDesc = (cur)->getDescription();
  char* curExit1 = (cur)->exit1;
  char* curExit2 = (cur)->exit2;
  char* curExit3 = (cur)->exit3;
  int westLoc = (cur)->loc1;
  int curIndex = (cur)->getID();
  char* curItems = mp[curIndex];
  cout << "You are in the " << curName << "." << endl;
  cout << curDesc << endl;
  cout << "You may exit to the " << curExit1 << ", the " << curExit2 << ", or the " << curExit3 << endl;
  if (mp.size() - 1 >= curIndex){
    cout << "The items in the room are : " << curItems << endl;
  }
}

void doItemStuff(map<int, char*>&mp){
  char* rock = new char[10];
  strcpy(rock, "Rock");
  mp[0] = rock;
  char* helmet = new char[10];
  strcpy(helmet, "Helmet");
  mp[1] = helmet;
  char* crucifix = new char[10];
  strcpy(crucifix, "Crucifix");
  mp[2] = crucifix;
  char* bone = new char[10];
  strcpy(bone, "Bone");
  mp[3] = bone;
  char* sword = new char[10];
  strcpy(sword, "Sword");
  mp[4] = sword;
}
