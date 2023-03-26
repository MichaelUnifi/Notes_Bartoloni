//
// Created by micha on 03/02/2023.
//

#include "Collection.h"

void Collection::show() {
    int index=1;
    std::cout<<name<<std::endl;
    for(auto it: notes){
        std::cout<<"\n"<<index<<"."<<it->getTitle()<<"\n"<<it->getText()<<". "<<std::endl;
        if(it->isLocked())
            std::cout<<" bloccata"<<std::endl;
        else
            std::cout<<" non bloccata"<<std::endl;
        index++;
    }
}

void Collection::updateForRemoval(Note* note) {
        notes.remove(note);
}

void Collection::addNote(Note *note) {
    notes.push_back(note);
    note->add(this);
}

void Collection::setName(std::string &newName) {
    name=newName;
}

Collection::~Collection() {
    for(auto it: notes)
        free(it);//in futuro possono finire in eliminati di recente?

}


