#include "VideoGame.h"
#include <iostream>
#include <cstring>

using namespace std;

VideoGame::VideoGame(const char* title, int year, const char* publisher, float rating)
  : DigitalMedia(title, year), rating(rating) {
  this->publisher = new char[strlen(publisher) + 1];
  strcpy(this->publisher, publisher);
}

VideoGame::~VideoGame() {
    delete[] publisher;
}

float VideoGame::getRating() const {
    return rating;
}

void VideoGame::display() const {
    cout << "Video Game - Title: " << title << ", Year: " << year
         << ", Publisher: " << publisher << ", Rating: " << rating << endl;
}
