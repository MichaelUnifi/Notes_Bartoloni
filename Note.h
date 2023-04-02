//
// Created by micha on 03/02/2023.
//

#ifndef NOTES_BARTOLONI_NOTE_H
#define NOTES_BARTOLONI_NOTE_H
#include <string>
#include <iostream>
#include <list>
#include "Subject.h"

class Note :public Subject{

private:
    std::list<Observer*> collections;
    std::string title;
    std::string text;
    bool locked;
public:
    Note(std::string ti, std::string te):title(ti),text(te),locked(false){}

    ~Note()=default;

    std::string getTitle();

    void setTitle(std::string newTitle);

    std::string getText();

    void setText(std::string newText);

    bool isLocked() const;

    void changeLock();

    bool modify(std::string newTitle, std::string newText);

    void add(Observer* o) override;

    void remove(Observer* o) override;

    bool deleteAndNotify() override;
};


#endif //NOTES_BARTOLONI_NOTE_H
