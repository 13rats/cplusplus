#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H

using namespace std;

class DigitalMedia {
protected:
    char* title;
    int year;

public:
    DigitalMedia(const char* title, int year);
    virtual ~DigitalMedia();

    const char* getTitle() const;
    int getYear() const;

    virtual void display() const = 0;
};

#endif
