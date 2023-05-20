//
// Created by micha on 03/02/2023.
//

#include "Collection.h"

void Collection::show() {
    int index=1;
    if(notes.empty())
        std::cout<<"Nessuna nota in "<<name<<std::endl;
    else{
        std::cout<<"Le note in "<<name<<" sono:"<<std::endl;
        for(const auto& it: notes){
            std::cout<<"\n"<<index<<"."<<it->getTitle()<<"\n"<<it->getText()<<". "<<std::endl;
            if(it->isLocked())
                std::cout<<" bloccata"<<std::endl;
            else
                std::cout<<" non bloccata"<<std::endl;
            index++;
        }
    }
}

void Collection::addNote(std::shared_ptr<Note> note) {
    notes.push_back(note);
    notify();
}

bool Collection::removeNote(std::shared_ptr<Note> note) {
    if(note->isLocked())
        return false;
    notes.remove(note);
    notify();
    return true;
}

void Collection::setName(std::string &newName) {
    name=newName;
}

Collection::~Collection() {
    notes.clear();
}

void Collection::notify() {
    view->update(shared_from_this(),notes.size());
}

bool Collection::searchNote(std::string &title) {
    for(const auto& it: notes){
        if(it->getTitle()==title)
            return true;
    }
    return false;
}

Note Collection::takeNote(std::string &title) {

    for(const auto& it: notes){
        if(it->getTitle()==title)
            return *it;
    }
}

void Collection::add(std::shared_ptr<Observer> o) {
    view=o;
    view->subscribe(shared_from_this(),notes.size());
}

void Collection::remove(std::shared_ptr<Observer> o) {
    view->unsubscribe(shared_from_this());
    view= nullptr;
}

Collection::Collection(std::string &n) {
    name=n;
    notes=std::list<std::shared_ptr<Note>>();
}


