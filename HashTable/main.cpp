#include <iostream>
#include "node.h"
#include "student.h"
#include <cstring>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

void add(Node** HashT, int BIGNUM, Node* n);
void print(Node** HashT, int BIGNUM);
void del(int passid, Node** HashT, int BIGNUM);
void rehash(Node**& HashT, int& BIGNUM);
void random(int passcount, Node** HashT, int BIGNUM, char** FIRST, char** LAST);

int main(){
  int BIGNUM = 100;
  Node** HashT = new Node*[BIGNUM];
  for (int i = 0; i < BIGNUM; i++){
    HashT[i] = NULL;
  }
  bool mainLoop = true;

  char** FIRST = new char*[100];
  char** LAST = new char*[100];

  ifstream firstF("first.txt");
  ifstream lastF("last.txt");

  for (int i = 0; i < 100; i++){
    FIRST[i] = new char[20];
    LAST[i] = new char[20];
    firstF >> FIRST[i];
    lastF >> LAST[i];
  }
  
  
  while (mainLoop == true){
    char input[20];
    for (int i = 0; i < 20; i++){
      input[i] = '\n';
    }
    cout << "enter 'ADD' to add a student, enter 'PRINT' to print the list of students, enter 'RANDOM' to add X number of random students, enter 'DELETE' to remove a student, or enter 'QUIT to quit" << endl;
    cin >> input;
    cin.ignore();

    if (strcmp(input, "ADD")== 0){
      cout << "Enter the student's name" << endl;
      cin >> input;
      cin.ignore();
      char name[20];
      strcpy(name, input);
      cout << "Enter the sudent's GPA" << endl;
      float inpfloat = 1.23;
      cin >> inpfloat;
      cin.ignore();
      cout << "Enter the student's ID number" << endl;
      int inpint = -1;
      cin >> inpint;
      cin.ignore();
      Student* s = new Student(inpint, inpfloat, name);
      Node* n = new Node(s);
      add(HashT,BIGNUM, n);
    }

    else if (strcmp(input, "PRINT") == 0){
      print(HashT, BIGNUM);
    }
    
    else if (strcmp(input, "DELETE") == 0){
      int numberphone = -1;
      cout << "enter the ID of the student you would like to remove" << endl;
      cin >> numberphone;
      if (numberphone != -1){
	cout << "deleting " << numberphone << endl;        
	del(numberphone, HashT, BIGNUM);
      }
    }
    else if (strcmp(input, "QUIT") == 0){
      cout << "exiting program" << endl;
      mainLoop = false;
    }
    else if (strcmp(input, "RANDOM") == 0){
      int passcount = -1;
      cout << "how many students" << endl;
      cin >> passcount;
      if (passcount != -1){
	cout << "generating " << passcount << " students" << endl;
	random(passcount, HashT, BIGNUM, FIRST, LAST);
      }
    }
    else{
      cout << input << endl;
      cout << "unknown command" << endl;
    }
  }
  return 0;
}

void add(Node** HashT, int BIGNUM, Node* n){
  Student* temp = n->getStu();
  int identity = temp->getID();
  int index = identity % BIGNUM;
  if (HashT[index] != NULL){
    bool last = false;
    Node* temp = HashT[index];
    int count = 1;
    while(last == false){
      if (temp->getNext() != NULL){
	temp = temp->getNext();
      }
      else{
	last = true;
	temp->setNext(n);
      }
      count++;
    }
    if (count > 3){
      rehash(HashT, BIGNUM);
    }
  }
  else{
    HashT[index] = n;
  }
}
void print(Node** HashT, int BIGNUM){
  for (int i = 0; i < BIGNUM; i++){
    if (HashT[i] != NULL){
      Student* temp = HashT[i]->getStu();
      temp -> stuPrint();
      Node* place = HashT[i];
      bool privbool = true;
      while (privbool == true){
	if (place->getNext() != NULL){
	  Student* temp = (place->getNext())->getStu();
	  temp -> stuPrint();
	  place = place->getNext();
	}
	else {
	  privbool = false;
	}
      }
    }
  }
}
void del(int passid, Node** HashT, int BIGNUM){
  int INDEX = passid % BIGNUM;
  delete((HashT[INDEX])->getStu());
  HashT[INDEX] = NULL;
}

void rehash(Node**& HashT, int& BIGNUM){
  int newN = BIGNUM + 100;
  Node** newT = new Node*[newN];
  for (int i = 0; i < newN; i++){
    newT[i] = NULL;
  }
  for (int i = 0; i < BIGNUM; i++){
    Node* temp = HashT[i];
    Node* tptr = nullptr;
    bool endbool = false;
    if (temp != NULL){
      if (temp->getNext() != NULL){
	while (endbool == false){
	  tptr = temp->getNext();
	  temp->setNext(NULL);
	  add(newT, newN, temp);
	  if (tptr->getNext() != NULL){
	    temp = tptr;
	  }
	  else{
	    endbool = true;
	  }
	}
      }
      else{
	add(newT, newN, temp);
      }
    }
  }
  HashT = newT;
  BIGNUM = newN;
}
void random(int passcount, Node** HashT, int BIGNUM, char** FIRST, char** LAST){
  // for loop : drag in a first and last name, make a random GPA, increment ID number
  for (int i = 0; i < passcount; i++){
    char* fname = new char[40];
    char* lname = new char[20];
    char* name = new char[40];
    float whgpa = rand() % 5;
    float lgpa = (rand() % 100) / 100;
    float gpa = 0;
    if (whgpa != 4){
      gpa = (whgpa + lgpa);
    }
    else {
      gpa = 4;
    }
    int fint = rand() % 101;
    int lint = rand() % 101;

    fname = FIRST[fint];
    lname = LAST[lint];
    
    strcat(fname, lname);
    
    Student* s = new Student(i, gpa, fname);
    Node* n = new Node(s);
    add(HashT, BIGNUM, n);
  }
}
