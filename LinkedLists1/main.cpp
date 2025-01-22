#include <iostream>
#include "node.h"
#include "student.h"
#include <cstring>
#include <iomanip>
using namespace std;

Node* head = nullptr;

// Corrected prototypes - note the reference parameter in del
void add(Node* &head, Node* n);
void print(Node* next);
void del(Node* &head, int passint);
float calculateAverage(Node* next, int &count);
void cleanup(Node* &head); // New cleanup function

int main() {
    bool mainLoop = true;
    while (mainLoop) {
        char input[20];
        memset(input, '\0', 20);
        cout << "Enter 'ADD', 'PRINT', 'DELETE', 'AVERAGE', or 'QUIT':" << endl;
        cin >> input;

        if (strcmp(input, "ADD") == 0) {
            char firstName[20], lastName[20];
            cout << "Enter the student's first name:" << endl;
            cin >> firstName;
            cout << "Enter the student's last name:" << endl;
            cin >> lastName;
            
            char fullName[40];
            strcpy(fullName, firstName);
            strcat(fullName, " ");
            strcat(fullName, lastName);
            
            float inpfloat;
            do {
                cout << "Enter the student's GPA (0.0-4.0):" << endl;
                cin >> inpfloat;
            } while (inpfloat < 0.0 || inpfloat > 4.0);
            
            int inpint;
            do {
                cout << "Enter the student's ID number (positive integer):" << endl;
                cin >> inpint;
            } while (inpint <= 0);

            Student* s = new Student(inpint, inpfloat, fullName);
            Node* n = new Node(s);
            add(head, n);
        }
        else if (strcmp(input, "PRINT") == 0) {
            print(head);
        }
        else if (strcmp(input, "DELETE") == 0) {
            cout << "Enter the ID of the student you would like to remove:" << endl;
            int numberphone;
            cin >> numberphone;
            del(head, numberphone);
        }
        else if (strcmp(input, "AVERAGE") == 0) {
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
            cleanup(head); // Clean up memory before exiting
            mainLoop = false;
        }
        else {
            cout << "Unknown command: " << input << endl;
        }
    }
    return 0;
}

// Corrected iterative add function
void add(Node* &head, Node* n) {
    if (head == nullptr || n->getStu()->getID() < head->getStu()->getID()) {
        n->setNext(head);
        head = n;
        return;
    }
    
    Node* current = head;
    while (current->getNext() != nullptr && 
           current->getNext()->getStu()->getID() < n->getStu()->getID()) {
        current = current->getNext();
    }
    
    n->setNext(current->getNext());
    current->setNext(n);
}

void print(Node* next) {
  if (next == nullptr) {
    return;
  }
  Student* temp = next->getStu();
  cout << temp->getName() << ", " << temp->getID() << ", " << fixed << setprecision(2) << temp->getGPA() << endl;
  print(next->getNext());
}

void del(Node* &head, int passint) {
    // Case 1: Empty list
    if (head == nullptr) {
        cout << "Student with ID " << passint << " not found." << endl;
        return;
    }
    
    // Case 2: Deleting first node (head)
    if (head->getStu()->getID() == passint) {
        Node* temp = head;
        head = head->getNext();
        Student* student = temp->getStu();
        delete student;  // First delete the Student object
        delete temp;     // Then delete the Node
        cout << "Student with ID " << passint << " deleted." << endl;
        return;
    }
    
    // Case 3: Deleting from middle or end
    Node* current = head;
    Node* prev = nullptr;
    
    while (current != nullptr && current->getStu()->getID() != passint) {
        prev = current;
        current = current->getNext();
    }
    
    // If student was not found
    if (current == nullptr) {
        cout << "Student with ID " << passint << " not found." << endl;
        return;
    }
    
    // Remove the node
    prev->setNext(current->getNext());
    Student* student = current->getStu();
    delete student;  // First delete the Student object
    delete current;  // Then delete the Node
    cout << "Student with ID " << passint << " deleted." << endl;
}

// Corrected average calculation
float calculateAverage(Node* next, int &count) {
    if (next == nullptr) {
        return 0.0;
    }
    float sum = next->getStu()->getGPA() + calculateAverage(next->getNext(), count);
    count++;
    return (count == 1) ? sum / count : sum;
}

// New cleanup function to prevent memory leaks
void cleanup(Node* &head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->getNext();
        delete temp->getStu();
        delete temp;
    }
}

