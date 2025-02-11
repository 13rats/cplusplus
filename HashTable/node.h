#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "student.h"

using namespace std;

class Node{
 public:
  Node();
  Node(Student* a);
  ~Node();
  void setStu(Student* a);
  Student* getStu();
  void setNext(Node* newnext);
  Node* getNext();
 private:
  Student* stu;
  Node* next;
};
#endif
