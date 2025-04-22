#include "node.h"

Node::Node(int val) {
  value = val;
  left = nullptr;
  right = nullptr;
  parent = nullptr;
  isRed = true;
}

int Node::getValue() {
 return value; 
}
void Node::setValue(int val) {
 value = val; 
}

Node* Node::getLeft() {
 return left; 
}
Node* Node::getRight() {
 return right; 
}
Node* Node::getParent() {
 return parent; 
}

void Node::setLeft(Node* node) {
 left = node;
 if (node) node->parent = this; 
}
void Node::setRight(Node* node) {
 right = node;
 if (node) node->parent = this;
 }
void Node::setParent(Node* node) {
 parent = node; 
}

bool Node::hasLeft() {
 return left != nullptr; 
}
bool Node::hasRight() {
 return right != nullptr; 
}

bool Node::getColor() {
 return isRed; 
}
void Node::setColor(bool red) {
 isRed = red; 
}
