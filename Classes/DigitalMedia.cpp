#include "DigitalMedia.h"
#include <iostream>
#include <cstring>

using namespace std;

DigitalMedia::DigitalMedia(const char* title, int year) : year(year) {
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
}

DigitalMedia::~DigitalMedia() {
    delete[] title;
}

const char* DigitalMedia::getTitle() const {
    return title;
}

int DigitalMedia::getYear() const {
    return year;
}
