#include "VideoGame.h"
#include <iostream>
// Contains the functions and information used for video game media objects in the Classes project. Zach Russell, 11/12/24
VideoGame::VideoGame(const string& title, int year, const string& publisher, float rating)
    : DigitalMedia(title, year), publisher(publisher), rating(rating) {}

float VideoGame::getRating() const {
    return rating;
}

void VideoGame::display() const {
    cout << "Video Game - Title: " << title << ", Year: " << year
         << ", Publisher: " << publisher << ", Rating: " << rating << endl;
}
