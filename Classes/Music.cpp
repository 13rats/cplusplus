#include "Music.h"
#include <iostream>
#include <cstring>

using namespace std;

Music::Music(const char* title, const char* artist, int year, int duration, const char* publisher)
    : DigitalMedia(title, year), duration(duration) {
    this->artist = new char[strlen(artist) + 1];
    strcpy(this->artist, artist);
    this->publisher = new char[strlen(publisher) + 1];
    strcpy(this->publisher, publisher);
}

Music::~Music() {
    delete[] artist;
    delete[] publisher;
}

void Music::display() const {
    cout << "Music - Title: " << title << ", Artist: " << artist
         << ", Year: " << year << ", Duration: " << duration << " mins"
         << ", Publisher: " << publisher << endl;
}
