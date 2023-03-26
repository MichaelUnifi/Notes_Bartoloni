//
// Created by micha on 26/03/2023.
//

#include "Important.h"


Important* Important::instance = nullptr;

Important *Important::getInstance() {
    if(instance== nullptr)
        instance=new Important();
    return instance;
}

void Important::addNote(Note *note) {
    notes.push_back(note);
    note->add(this);
}

void Important::show() {
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

void Important::updateForRemoval(Note *note) {
    notes.remove(note);
}

int Important::getSize() {
    return notes.size();
}

Important::~Important() {
    for(auto it: notes)
        free(it);

}





