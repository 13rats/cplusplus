#include <iostream>
#include <vector>
#include <algorithm>
#include "DigitalMedia.h"
#include "VideoGame.h"
#include "Music.h"
#include "Movie.h"

using namespace std; // Main part of the Classes project. Holds the user commands, as well as the functions that go allong with them. Zach Russell, 11/12/24 

void addMedia(vector<DigitalMedia*>& media);
void searchMedia(const vector<DigitalMedia*>& media);
void deleteMedia(vector<DigitalMedia*>& media);

int main() { // user input loop
    vector<DigitalMedia*> media;
    string command;

    while (true) {
        cout << "Enter command (ADD, SEARCH, DELETE, QUIT): ";
        cin >> command;

        if (command == "ADD") {
            addMedia(media);
        } else if (command == "SEARCH") {
            searchMedia(media);
        } else if (command == "DELETE") {
            deleteMedia(media);
        } else if (command == "QUIT") {
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

void addMedia(vector<DigitalMedia*>& media) { // Creates a new media object
    string type;
    cout << "Enter media type (VideoGame, Music, Movie): ";
    cin >> type;

    string title;
    int year;
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter year: ";
    cin >> year;

    if (type == "VideoGame") {
        string publisher;
        float rating;
        cout << "Enter publisher: ";
        cin.ignore();
        getline(cin, publisher);
        cout << "Enter rating: ";
        cin >> rating;
        media.push_back(new VideoGame(title, year, publisher, rating));
    } else if (type == "Music") {
        string artist, publisher;
        int duration;
        cout << "Enter artist: ";
        cin.ignore();
        getline(cin, artist);
        cout << "Enter duration (in mins): ";
        cin >> duration;
        cout << "Enter publisher: ";
        cin.ignore();
        getline(cin, publisher);
        media.push_back(new Music(title, artist, year, duration, publisher));
    } else if (type == "Movie") {
        string director;
        int duration;
        float rating;
        cout << "Enter director: ";
        cin.ignore();
        getline(cin, director);
        cout << "Enter duration (in mins): ";
        cin >> duration;
        cout << "Enter rating: ";
        cin >> rating;
        media.push_back(new Movie(title, director, year, duration, rating));
    }
}

void searchMedia(const vector<DigitalMedia*>& media) { // Looking for a specific media object
    string query;
    cout << "Enter title or year to search: ";
    cin.ignore();
    getline(cin, query);

    bool found = false;
    for (const auto& item : media) {
        if (item->getTitle() == query || to_string(item->getYear()) == query) {
            item->display();
            found = true;
        }
    }
    if (!found) {
        cout << "No media found." << endl;
    }
}

void deleteMedia(vector<DigitalMedia*>& media) { // Deleting a media object
    string query;
    cout << "Enter title or year to delete: ";
    cin.ignore();
    getline(cin, query);

    auto it = remove_if(media.begin(), media.end(), [&](DigitalMedia* item) {
        if (item->getTitle() == query || to_string(item->getYear()) == query) {
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
