#include "node.h"
Node::Node(){
  value = -1;
  left = nullptr;
  right = nullptr;
}

Node::Node(int a){
  value = a;
  left = nullptr;
  right = nullptr;
}

Node::~Node(){
  left = nullptr;
  right = nullptr;
}

void Node::setValue(int a){
  value = a;
}

int Node::getValue(){
  return value;
}

void Node::setLeft(Node* newleft){
  left = newleft;
}

Node* Node::getLeft(){
  return left;
}

bool Node::hasLeft(){
  if (left != nullptr){
    return true;
  }
  else{
    return false;
  }
}

void Node::setRight(Node* newright){
  right = newright;
}

Node* Node::getRight(){
  return right;
}

bool Node::hasRight(){
  if(right != nullptr){
    return true;
  }
  else{
    return false;
  }
}


