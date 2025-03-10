#include "node.h"
Node::Node(){
  stu = new Student;
  next = NULL;
}

Node::Node(Student* a){
  stu = a;
  next = NULL;
}

Node::~Node(){
  delete &stu;
  next = NULL;
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
