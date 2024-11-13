#include "Music.h"
#include <iostream>
// Contains all the information and commands for the music media objects in the Classes project. Zach Russell, 11/12/24
Music::Music(const string& title, const string& artist, int year, int duration, const string& publisher)
    : DigitalMedia(title, year), artist(artist), duration(duration), publisher(publisher) {}

void Music::display() const {
    cout << "Music - Title: " << title << ", Artist: " << artist
         << ", Year: " << year << ", Duration: " << duration << " mins"
         << ", Publisher: " << publisher << endl;
}
