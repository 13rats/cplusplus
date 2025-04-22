// node.h
#ifndef NODE_H
#define NODE_H

class Node {
private:
    int value;
    Node* left;
    Node* right;
    Node* parent;
    bool isRed; // true for red, false for black

public:
    Node(int val);

    int getValue();
    void setValue(int val);

    Node* getLeft();
    Node* getRight();
    Node* getParent();

    void setLeft(Node* node);
    void setRight(Node* node);
    void setParent(Node* node);

    bool hasLeft();
    bool hasRight();

    bool getColor();
    void setColor(bool red);
};

#endif