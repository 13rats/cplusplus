#ifndef VIDEOGAME_H
#define VIDEOGAME_H
// Companion file to the main Video Game.cpp file in Classes. Contains a list of variables and functions, and the scope, for broader use in the classes project. Zach Russell, 11/12/24
#include "DigitalMedia.h"

class VideoGame : public DigitalMedia {
private:
    string publisher;
    float rating;

public:
    VideoGame(const string& title, int year, const string& publisher, float rating);
    float getRating() const;
    void display() const override;
};

#endif
