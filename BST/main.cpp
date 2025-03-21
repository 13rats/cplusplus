#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include "node.h"

void add(Node* &head, int i);
void print(Node* cur, int depth);
bool search(Node* head, int i);
void remove(Node* &head, int i);


using namespace std; // Zach Russell 3/21/25 Binary Search Tree

int main(){
  Node* head = nullptr;
  bool mainloop = true;
  while (mainloop == true){
    cout << "enter words and things. add/print/search/remove/quit" << endl;
    string input;
    cin >> input;
    if (input == "add"){
      cout << "enter numbies seperated by single space. end loop by typing -1" << endl;
      int inpint = 0;
      cin >> inpint;
      while (inpint >= 0){
	add(head, inpint);
	cout << inpint << endl;
	cin >> inpint;
      }
    }
    else if (input == "print"){
      print(head, 0);
    }
    else if (input == "search"){
      cout << "enter the number you want to search" << endl;
      int temp = -1;
      cin >> temp;
      if(search(head, temp) == true){
	cout << "that number is in there" << endl;
      }
      else{
	cout << "not in there" << endl;
      }
    }
    else if (input == "remove"){
      cout << "enter the number you want to remove" << endl;
      int temp = -1;
      cin >> temp;
      remove(head, temp);
    }
    else if (input == "quit"){
      mainloop = false;
    }
  }
  
  return 0;
}

void add(Node* &head, int i){
  Node* n = new Node(i);
  int nv = i;
  Node* cur = head;
  bool added = false;
  if (head != nullptr){
    while (added == false){
      int cv = cur->getValue();
      if (nv > cv){
	if ((cur->hasRight()) == true){
	  cur = cur->getRight();
	}
	else{
	  cur->setRight(n);
	  added = true;
	}
      }
      else{
	if ((cur->hasLeft()) == true){
	  cur = cur->getLeft();
	}
	else{
	  cur->setLeft(n);
	  added = true;
	}
      }
    }
  }
  else{
    head = n;
  }
  cout << "added" << nv << endl;
}

void print(Node* cur, int depth){
  int temp = cur->getValue();
  if (cur->hasRight() == true){
    print(cur->getRight(), depth + 1);
  }
  for(int a = 0; a < depth; a++){
    cout << '\t';
  }
  cout << temp << endl;
  if (cur->hasLeft() == true){
    print(cur->getLeft(), depth + 1);
  }
}

bool search(Node* head, int i){
  Node* xnode = head;
  while ((xnode != nullptr ) && (i != xnode->getValue())){
    if (i < xnode->getValue()){
      xnode = xnode->getLeft();
    }
    else{
      xnode = xnode->getRight();
    }
  }
  if (xnode != nullptr){
    return true;
  }
  else{
    return false;
  }
}

void remove(Node* &head, int i){
  // first, find the number
  Node* xnode = head;
  Node* parent = nullptr;
  while ((xnode != nullptr ) && (i != xnode->getValue())){
    parent = xnode;
    if (i < xnode->getValue()){
      xnode = xnode->getLeft();
    }
    else {
      xnode = xnode->getRight();
    }
  }

  if (xnode->getValue() == nullptr) {
    cout << "Number not found" << endl;
    return;
  }

  if (xnode != nullptr){
    if ((xnode->hasLeft()) == (xnode->hasRight())){
      if (xnode->hasLeft() == true){
	// 2 children
	if (((xnode->getRight())->hasLeft()) == false){
	  Node* left = xnode->getLeft();
	  xnode = xnode->getRight();
	  xnode->setLeft(left);
	}
	else{
	  Node* cur = xnode->getRight();
	  Node* curP = nullptr;
	  while(cur->hasLeft() == true){
	    curP = cur;
	    cur = cur->getLeft();
	  }
	  int newv = cur->getValue();
	  xnode->setValue(newv);
	  if(cur->hasRight()){
	    curP->setRight(cur->getRight());
	  }
	}
      }
      else {
	// no children
	if (xnode == head){
	  head = nullptr;
	}
	else if (parent->getLeft() == xnode){
	  parent->setLeft(nullptr);
	}
	else if (parent->getRight() == xnode){
	  parent->setRight(nullptr);
	}

	delete xnode;
      }
    }
    else{
      // 1 child
      if (xnode->hasLeft() == true){
	parent->setLeft(xnode->getLeft());
      }
      else{
	parent->setRight(xnode->getRight());
      }
      delete xnode;
    }
  }
}


