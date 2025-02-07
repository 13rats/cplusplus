#ifndef MUSIC_H
#define MUSIC_H

#include "DigitalMedia.h"

using namespace std;

class Music : public DigitalMedia {
private:
    char* artist;
    int duration;
    char* publisher;

public:
    Music(const char* title, const char* artist, int year, int duration, const char* publisher);
    ~Music();
    void display() const override;
};

#endif
