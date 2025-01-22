#include "Movie.h"
#include <iostream>
#include <cstring>

using namespace std;

Movie::Movie(const char* title, const char* director, int year, int duration, float rating)
    : DigitalMedia(title, year), duration(duration), rating(rating) {
    this->director = new char[strlen(director) + 1];
    strcpy(this->director, director);
}

Movie::~Movie() {
    delete[] director;
}

void Movie::display() const {
    cout << "Movie - Title: " << title << ", Director: " << director
         << ", Year: " << year << ", Duration: " << duration << " mins"
         << ", Rating: " << rating << endl;
}
