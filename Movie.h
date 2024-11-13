#ifndef MOVIE_H
#define MOVIE_H
// Companion file to the main Movie file for Classes. Contains scope information and a list of variables/functions used in Movie for the broader project. Zach Russell, 11/12/24.
#include "DigitalMedia.h"

class Movie : public DigitalMedia {
private:
    string director;
    int duration;
    float rating;

public:
    Movie(const string& title, const string& director, int year, int duration, float rating);
    void display() const override;
};

#endif
