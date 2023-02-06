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
    Note(std::string &ti, std::string &te):title(ti),text(te),locked(false){}

    ~Note()=default;

    std::string getTitle() const{
        return title;
    }

    void setTitle(std::string &newTitle){
        title=newTitle;
    }

    std::string getText() const{
        return text;
    }

    void setText(std::string &newText){
        text=newText;
    }

    bool isLocked() const{
        return locked;
    }

    void lock(){
        locked=true;
    }

    void unlock(){
        locked=false;
    }

    void add(Observer* o) override{
        collections.push_back(o);
    }

    void remove(Observer* o) override{
        collections.remove(o);
    }

    void notifyForRemoval() override {
        for(auto it:collections)
            it->updateForRemoval(this);
    }
};


#endif //NOTES_BARTOLONI_NOTE_H
