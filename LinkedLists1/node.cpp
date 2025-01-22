#include "node.h"
Node::Node(){
  stu = new Student;
  next = nullptr;
}

Node::Node(Student* a){
  stu = a;
  next = nullptr;
}

Node::~Node(){
  next = nullptr;
}

void Node::setStu(Student* a){
  stu = a;
}

Student* Node::getStu(){
  return stu;
}

void Node::setNext(Node* newnext){
  next = newnext;
}

Node* Node::getNext(){
  return next;
}
