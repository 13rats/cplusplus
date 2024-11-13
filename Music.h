#ifndef MUSIC_H
#define MUSIC_H
// Companion file to music.cpp, contains scope information and a list of variables/functions used in Music, for the broader project. Zach Russell, 11/12/24.
#include "DigitalMedia.h"

class Music : public DigitalMedia {
private:
    string artist;
    int duration;
    string publisher;

public:
    Music(const string& title, const string& artist, int year, int duration, const string& publisher);
    void display() const override;
};

#endif
