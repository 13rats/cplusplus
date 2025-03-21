#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node{
 public:
  Node();
  Node(int a);
  ~Node();
  void setValue(int a);
  int getValue();
  void setLeft(Node* newleft);
  Node* getLeft();
  bool hasLeft();
  void setRight(Node* newright);
  Node* getRight();
  bool hasRight();
 private:
  int value;
  Node* left;
  Node* right;
};
#endif
