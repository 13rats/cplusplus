#include "Movie.h"
#include <iostream>
// Contains the movie commands and functions for the Classes project. Zach Russell, 11/12/24

Movie::Movie(const string& title, const string& director, int year, int duration, float rating)
    : DigitalMedia(title, year), director(director), duration(duration), rating(rating) {}

void Movie::display() const {
    cout << "Movie - Title: " << title << ", Director: " << director
         << ", Year: " << year << ", Duration: " << duration << " mins"
         << ", Rating: " << rating << endl;
}
