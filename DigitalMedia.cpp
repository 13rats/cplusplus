#include "DigitalMedia.h"
#include <iostream>

DigitalMedia::DigitalMedia(const string& title, int year) : title(title), year(year) {} // Holds all of the functions needed for digital media in the classes project. Zach Russell, 11/12/24

DigitalMedia::~DigitalMedia() {}

string DigitalMedia::getTitle() const {
    return title;
}

int DigitalMedia::getYear() const {
    return year;
}
