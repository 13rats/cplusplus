#include <iostream>
#include "node.h"
#include "student.h"
#include <cstring>

using namespace std;

Node* head;

void add(Node* &head, Node* cur, Node* n);
void print(Node* next);

int main(){
  Student* Stu1 = new Student(419746, 3.7, "Zach");
  Node* Znode = new Node(Stu1);
  Student* Stu2 = new Student(419744, 3.1, "Izzy");
  Node* Inode = new Node (Stu2);
  add(head, head, Znode);
  add(head, head, Inode);
  print(head);
}
void add(Node* &head, Node* cur, Node* n){
  if (head == NULL) {
    head = n;
    return;
  }
  else if((n->getStu())->getID() < (head->getStu())->getID()){
    n->setNext(head);
    head = n;
    return;
  }
  else {
    do ({
	cur = cur->getNext();
      });
    while (((n->getStu())->getID() < (cur->getStu())->getID()));
  }
  add(head, cur->getNext(), n);
}
void print(Node* next){
  if (next == head){
    cout << "list: ";
  }
  if (next != NULL){
    Student* temp = next->getStu();
    temp->stuPrint();
    print(next->getNext());
  }
}
