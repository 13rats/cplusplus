#include "DigitalMedia.h"

#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "DigitalMedia.h"

using namespace std;

class VideoGame : public DigitalMedia {
private:
    char* publisher;
    float rating;

public:
    VideoGame(const char* title, int year, const char* publisher, float rating);
    ~VideoGame();
    float getRating() const;
    void display() const override;
};

#endif
