#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include "DigitalMedia.h"
#include "VideoGame.h"
#include "Music.h"
#include "Movie.h"

using namespace std; // Main file of the Classes project, fixed by Zach russell, 1/21/25

void addMedia(vector<DigitalMedia*>& media);
void searchMedia(const vector<DigitalMedia*>& media);
void deleteMedia(vector<DigitalMedia*>& media);

int main() {
    vector<DigitalMedia*> media;
    char command[10];

    while (true) {
        cout << "Enter command (ADD, SEARCH, DELETE, QUIT): ";
        cin >> command;

        if (strcmp(command, "ADD") == 0) {
            addMedia(media);
        } else if (strcmp(command, "SEARCH") == 0) {
            searchMedia(media);
        } else if (strcmp(command, "DELETE") == 0) {
            deleteMedia(media);
        } else if (strcmp(command, "QUIT") == 0) {
            break;
        } else {
            cout << "Invalid command." << endl;
        }
    }

    // Cleanup
    for (auto item : media) {
        delete item;
    }

    return 0;
}

void addMedia(vector<DigitalMedia*>& media) {
    char type[20];
    cout << "Enter media type (VideoGame, Music, Movie): ";
    cin >> type;

    char title[256];
    int year;
    cout << "Enter title: ";
    cin.ignore();
    cin.getline(title, 256);
    cout << "Enter year: ";
    cin >> year;

    if (strcmp(type, "VideoGame") == 0) {
        char publisher[256];
        float rating;
        cout << "Enter publisher: ";
        cin.ignore();
        cin.getline(publisher, 256);
        cout << "Enter rating: ";
        cin >> rating;
        media.push_back(new VideoGame(title, year, publisher, rating));
    } else if (strcmp(type, "Music") == 0) {
        char artist[256];
        char publisher[256];
        int duration;
        cout << "Enter artist: ";
        cin.ignore();
        cin.getline(artist, 256);
        cout << "Enter duration (in mins): ";
        cin >> duration;
        cout << "Enter publisher: ";
        cin.ignore();
        cin.getline(publisher, 256);
        media.push_back(new Music(title, artist, year, duration, publisher));
    } else if (strcmp(type, "Movie") == 0) {
        char director[256];
        int duration;
        float rating;
        cout << "Enter director: ";
        cin.ignore();
        cin.getline(director, 256);
        cout << "Enter duration (in mins): ";
        cin >> duration;
        cout << "Enter rating: ";
        cin >> rating;
	media.push_back(new Movie(title, director, year, duration, rating));
    }
}

void searchMedia(const vector<DigitalMedia*>& media) {
  char query[256];
 cout << "Enter title or year to search: ";
 cin.ignore();
 cin.getline(query, 256);
 bool found = false;
 for (const auto& item : media) {
        char yearStr[20];
        sprintf(yearStr, "%d", item->getYear());
        if (strcmp(item->getTitle(), query) == 0 || strcmp(yearStr, query) == 0) {
            item->display();
            found = true;
        }
    }
    if (!found) {
        cout << "No media found." << endl;
    }
}

void deleteMedia(vector<DigitalMedia*>& media) {
    char query[256];
    cout << "Enter title or year to delete: ";
    cin.ignore();
    cin.getline(query, 256);

    auto it = remove_if(media.begin(), media.end(), [&](DigitalMedia* item) {
        char yearStr[20];
        sprintf(yearStr, "%d", item->getYear());
        if (strcmp(item->getTitle(), query) == 0 || strcmp(yearStr, query) == 0) {
            item->display();
            cout << "Confirm deletion (y/n): ";
            char confirm;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                delete item;
                return true;
            }
        }
        return false;
    });

    media.erase(it, media.end());
}
