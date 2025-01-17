#include <iostream>
#include "node.h"
#include "student.h"
#include <cstring>
#include <iomanip> // for the # of digits used in the GPA average

using namespace std;

Node* head = nullptr; // start the head pointer as nullptr

// prototypes
void add(Node* &head, Node* n);
void print(Node* next);
void del(Node* &head, int passint);
float calculateAverage(Node* next, int &count);

int main() {
  bool mainLoop = true;

  while (mainLoop) {
    char input[20];
    memset(input, '\0', 20);

    cout << "Enter 'ADD', 'PRINT', 'DELETE', 'AVERAGE', or 'QUIT':" << endl;
    cin >> input;

    if (strcmp(input, "ADD") == 0) {
      // takes in student info
      char firstName[20], lastName[20];
      cout << "Enter the student's first name:" << endl;
      cin >> firstName;

      cout << "Enter the student's last name:" << endl;
      cin >> lastName;

      char fullName[40];
      strcpy(fullName, firstName);
      strcat(fullName, " "); // adding space between 1st and last name
      strcat(fullName, lastName);
      cout << "Enter the student's GPA:" << endl;
      float inpfloat;
      cin >> inpfloat;

      cout << "Enter the student's ID number:" << endl;
      int inpint;
      cin >> inpint;
	    
      // Create the new student and node
      Student* s = new Student(inpint, inpfloat, fullName);
      Node* n = new Node(s);

      // Add the new node to the list
      add(head, n);
    }
    else if (strcmp(input, "PRINT") == 0) {
      // Print the list
      print(head);
    }
    else if (strcmp(input, "DELETE") == 0) {
      cout << "Enter the ID of the student you would like to remove:" << endl;
      int numberphone;
      cin >> numberphone;

      // Delete the node
      del(head, numberphone);
    }
    else if (strcmp(input, "AVERAGE") == 0) {
      // fidn the gpa avg
      int count = 0;
      float avg = calculateAverage(head, count);
      if (count > 0) {
	cout << "Average GPA: " << fixed << setprecision(2) << avg << endl;
      } else {
	cout << "No students in the list." << endl;
      }
    }
    else if (strcmp(input, "QUIT") == 0) {
      cout << "Exiting program." << endl;
      mainLoop = false;
    }
    else {
      cout << "Unknown command: " << input << endl;
    }
  }

  return 0;
}

// add a node, sort by ID
void add(Node* &head, Node* n) {
  if (head == nullptr || n->getStu()->getID() < head->getStu()->getID()) {
    n->setNext(head);
    head = n;
    return;
  }
  Node* next = head->getNext();
  add(next, n);
  head->setNext(next);
}

// print the list
void print(Node* next) {
  if (next == nullptr) {
    return;
  }

  Student* temp = next->getStu();
  cout << temp->getName() << ", " << temp->getID() << ", " 
       << fixed << setprecision(2) << temp->getGPA() << endl;

  print(next->getNext());
}

// delete a node by ID
void del(Node* &head, int passint) {
  if (head == nullptr) {
    cout << "Student with ID " << passint << " not found." << endl;
    return;
  }

  if (head->getStu()->getID() == passint) {
    Node* temp = head;
    head = head->getNext();
    delete temp;
    cout << "Student with ID " << passint << " deleted." << endl;
    return;
  }

  Node* next = head->getNext();
  del(next, passint);
  head->setNext(next);
}

// calculate the GPA average
float calculateAverage(Node* next, int &count) {
  if (next == nullptr) {
    return 0.0;
  }

  count++;
  return next->getStu()->getGPA() + calculateAverage(next->getNext(), count);
}
