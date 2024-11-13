#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H
// Companion file to the digital media cpp file. Used to carry over some of the variables and functions from the other parts of Classes and also to define what is being used in Digital Media. Zach Russell, 11/12/24.
#include <string>
using namespace std;

class DigitalMedia {
protected:
    string title;
    int year;

public:
    DigitalMedia(const string& title, int year);
    virtual ~DigitalMedia();

    string getTitle() const;
    int getYear() const;

    virtual void display() const = 0;  // Pure virtual function to display details
};

#endif
