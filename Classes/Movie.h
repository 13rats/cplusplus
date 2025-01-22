#ifndef MOVIE_H
#define MOVIE_H

#include "DigitalMedia.h"

using namespace std;

class Movie : public DigitalMedia {
private:
    char* director;
    int duration;
    float rating;

public:
    Movie(const char* title, const char* director, int year, int duration, float rating);
    ~Movie();
    void display() const override;
};

#endif
