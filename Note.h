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

    ~Note(){
        locked=true;
        for(auto it: collections)
            free(it);
    }

    std::string getTitle() const{
        return title;
    }

    void setTitle(std::string newTitle){
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

    void changeLock(){
        if(locked)
            locked=false;
        else
            locked=true;
    }

    void add(Observer* o) override{
        collections.push_back(o);
    }

    void remove(Observer* o) override{
        collections.remove(o);
        if(collections.size()==0){
            delete this;
        }
    }

    void notifyForRemoval() override {
        for(auto it:collections)
            it->updateForRemoval(this,isLocked());
    }
};


#endif //NOTES_BARTOLONI_NOTE_H
