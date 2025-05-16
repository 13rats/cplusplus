#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include "node.h"

using namespace std; // Zach Russell, May 16th 2025, Red Black Tree part 2 project --> boy was this hard to understand (rotation is messed up man idk)

void add(Node* &head, int i);
void read(Node* &head, const string& filename);
void print(Node* cur, int depth);
bool search(Node* head, int i);
void remove(Node* &head, int i);
void leftRotate(Node* &head, Node* x);
void rightRotate(Node* &head, Node* x);
void fixInsert(Node* &head, Node* z);
void fixDelete(Node* &head, Node* x);
Node* getSibling(Node* node);
void transplant(Node* &head, Node* u, Node* v);

int main() {
    Node* head = nullptr;
    bool mainloop = true;
    while (mainloop) {
        cout << "please enter one of the following: add/print/search/remove/read/quit" << endl;
        string input;
        cin >> input;
        if (input == "add") {
            cout << "Enter a number between 1 and 999 inclusive: ";
            int inpint;
            cin >> inpint;
            if (inpint >= 1 && inpint <= 999) {
                add(head, inpint);
            } else {
                cout << "number must be between 1 and 999" << endl;
            }
        } else if (input == "print") {
            if (head) {
                print(head, 0);
            } else {
                cout << "nothing to print :( " << endl;
            }
        } else if (input == "search") {
            cout << "enter number to search: ";
            int temp;
            cin >> temp;
            if (search(head, temp)) {
                cout << "number found :0" << endl;
            } else {
                cout << "number lost :(((" << endl;
            }
        } else if (input == "remove") {
            cout << "enter the number to remove: ";
            int temp;
            cin >> temp;
            remove(head, temp);
        } else if (input == "read") {
            cout << "Enter filename: ";
            string filename;
            cin >> filename;
            read(head, filename);
        } else if (input == "quit") {
            mainloop = false;
        } else {
            cout << "Invalid command" << endl;
        }
    }
    return 0;
}

// Add a number to the RBT
void add(Node* &head, int i) {
    Node* n = new Node(i);
    Node* y = nullptr;
    Node* x = head;

    // insertion from BST
    while (x != nullptr) {
        y = x;
        if (i < x->getValue()) {
            x = x->getLeft();
        } else {
            x = x->getRight();
        }
    }

    n->setParent(y);
    if (y == nullptr) {
        head = n;
    } else if (i < y->getValue()) {
        y->setLeft(n);
    } else {
        y->setRight(n);
    }

    // fix RBT properties
    fixInsert(head, n);
    cout << "Added " << i << endl;
}
// read in numbers
void read(Node* &head, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "error opening file OOPS" << endl;
        return;
    }
    int num;
    while (file >> num) {
        if (num >= 1 && num <= 999) {
            add(head, num);
        } else {
            cout << "skipping invalid number: " << num << endl;
        }
    }
    file.close();
    cout << "finished reading file \o/" << endl;
}

// print the tree with number, color, and parent
void print(Node* cur, int depth) {
    if (!cur) return;
    // Print right subtree
    if (cur->hasRight()) {
        print(cur->getRight(), depth + 1);
    }
    // Print current node
    for (int i = 0; i < depth; i++) {
        cout << "\t";
    }
    if (cur->getColor() == true){
    cout << cur->getValue() << " R";
    }
    else{
      cout << cur->getValue() << " B";
    }
    if (cur->getParent()) {
      if (cur->getParent()->getColor() == true){
      cout << " [Parent: " << cur->getParent()->getValue() << "]";
      }
      else{
	cout << " [Parent: " << cur->getParent()->getValue() << "]";
      }
    }
    else {
        cout << " [Root]";
    }
    cout << endl;
    // Print left subtree
    if (cur->hasLeft()) {
        print(cur->getLeft(), depth + 1);
    }
}

// search for a number
bool search(Node* head, int i) {
    Node* x = head;
    while (x != nullptr && i != x->getValue()) {
        if (i < x->getValue()) {
            x = x->getLeft();
        } else {
            x = x->getRight();
        }
    }
    return x != nullptr;
}
// remove a number
void remove(Node* &head, int i) {
    Node* z = head;
    while (z != nullptr && z->getValue() != i) {
        if (i < z->getValue()) {
            z = z->getLeft();
        } else {
            z = z->getRight();
        }
    }

    if (z == nullptr) {
        cout << "Number " << i << " not found" << endl;
        return;
    }

    Node* y = z;
    bool yOriginalColor = y->getColor();
    Node* x;

    if (!z->hasLeft()) {
        x = z->getRight();
        transplant(head, z, z->getRight());
    } else if (!z->hasRight()) {
        x = z->getLeft();
        transplant(head, z, z->getLeft());
    } else {
        y = z->getRight();
        while (y->hasLeft()) {
            y = y->getLeft();
        }
        yOriginalColor = y->getColor();
        x = y->getRight();
        if (y->getParent() == z) {
            if (x) x->setParent(y);
        } else {
            transplant(head, y, y->getRight());
            y->setRight(z->getRight());
            y->getRight()->setParent(y);
        }
        transplant(head, z, y);
        y->setLeft(z->getLeft());
        y->getLeft()->setParent(y);
        y->setColor(z->getColor());
    }

    delete z;

    if (!yOriginalColor) { // If y was black, fix the tree
        fixDelete(head, x);
    }

    cout << "Removed " << i << endl;
}

// replace node u with node v
void transplant(Node* &head, Node* u, Node* v) {
    if (!u->getParent()) {
        head = v;
    } else if (u == u->getParent()->getLeft()) {
        u->getParent()->setLeft(v);
    } else {
        u->getParent()->setRight(v);
    }
    if (v) {
        v->setParent(u->getParent());
    }
}

// left rotation
void leftRotate(Node* &head, Node* x) {
    Node* y = x->getRight();
    x->setRight(y->getLeft());
    if (y->getLeft()) {
        y->getLeft()->setParent(x);
    }
    y->setParent(x->getParent());
    if (!x->getParent()) {
        head = y;
    } else if (x == x->getParent()->getLeft()) {
        x->getParent()->setLeft(y);
    } else {
        x->getParent()->setRight(y);
    }
    y->setLeft(x);
    x->setParent(y);
}

// right rotation
void rightRotate(Node* &head, Node* y) {
    Node* x = y->getLeft();
    y->setLeft(x->getRight());
    if (x->getRight()) {
        x->getRight()->setParent(y);
    }
    x->setParent(y->getParent());
    if (!y->getParent()) {
        head = x;
    } else if (y == y->getParent()->getRight()) {
        y->getParent()->setRight(x);
    } else {
        y->getParent()->setLeft(x);
    }
    x->setRight(y);
    y->setParent(x);
}
// fix the tree after inserting a number
void fixInsert(Node* &head, Node* z) {
    while (z->getParent() && z->getParent()->getColor()) { // Parent is red
        if (z->getParent() == z->getParent()->getParent()->getLeft()) {
            Node* y = z->getParent()->getParent()->getRight(); // Uncle
            if (y && y->getColor()) { // Case 1: Uncle is red
                z->getParent()->setColor(false);
                y->setColor(false);
                z->getParent()->getParent()->setColor(true);
                z = z->getParent()->getParent();
            } else { // Uncle is black or null
                if (z == z->getParent()->getRight()) { // Case 2: z is right child
                    z = z->getParent();
                    leftRotate(head, z);
                }
                // Case 3: z is left child
                z->getParent()->setColor(false);
                z->getParent()->getParent()->setColor(true);
                rightRotate(head, z->getParent()->getParent());
            }
        } else { // Symmetric case
            Node* y = z->getParent()->getParent()->getLeft(); // Uncle
            if (y && y->getColor()) {
                z->getParent()->setColor(false);
                y->setColor(false);
                z->getParent()->getParent()->setColor(true);
                z = z->getParent()->getParent();
            } else {
                if (z == z->getParent()->getLeft()) {
                    z = z->getParent();
                    rightRotate(head, z);
                }
                z->getParent()->setColor(false);
                z->getParent()->getParent()->setColor(true);
                leftRotate(head, z->getParent()->getParent());
            }
        }
    }
    head->setColor(false); // Root is always black
}

// fix tree after deletion
void fixDelete(Node* &head, Node* x) {
    while (x != head && (!x || !x->getColor())) {
        if (x == x->getParent()->getLeft()) {
            Node* w = x->getParent()->getRight(); // Sibling
            if (w->getColor()) { // Case 1: Sibling is red
                w->setColor(false);
                x->getParent()->setColor(true);
                leftRotate(head, x->getParent());
                w = x->getParent()->getRight();
            }
            if ((!w->getLeft() || !w->getLeft()->getColor()) &&
                (!w->getRight() || !w->getRight()->getColor())) { // Case 2: Siblings children are black
                w->setColor(true);
                x = x->getParent();
            } else {
                if (!w->getRight() || !w->getRight()->getColor()) { // Case 3: Right child is black
                    if (w->getLeft()) w->getLeft()->setColor(false);
                    w->setColor(true);
                    rightRotate(head, w);
                    w = x->getParent()->getRight();
                }
                // Case 4: Right child is red
                w->setColor(x->getParent()->getColor());
                x->getParent()->setColor(false);
                if (w->getRight()) w->getRight()->setColor(false);
                leftRotate(head, x->getParent());
                x = head;
            }
        } else { // Symmetric case
            Node* w = x->getParent()->getLeft();
            if (w->getColor()) {
                w->setColor(false);
                x->getParent()->setColor(true);
                rightRotate(head, x->getParent());
                w = x->getParent()->getLeft();
            }
            if ((!w->getRight() || !w->getRight()->getColor()) &&
                (!w->getLeft() || !w->getLeft()->getColor())) {
                w->setColor(true);
                x = x->getParent();
            } else {
                if (!w->getLeft() || !w->getLeft()->getColor()) {
                    if (w->getRight()) w->getRight()->setColor(false);
                    w->setColor(true);
                    leftRotate(head, w);
                    w = x->getParent()->getLeft();
                }
                w->setColor(x->getParent()->getColor());
                x->getParent()->setColor(false);
                if (w->getLeft()) w->getLeft()->setColor(false);
                rightRotate(head, x->getParent());
                x = head;
            }
        }
    }
    if (x) x->setColor(false);
}
