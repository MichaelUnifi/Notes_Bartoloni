//
// Created by micha on 03/02/2023.
//

#include "Note.h"

std::string Note::getTitle() {
    return title;
}

void Note::setTitle(std::string& newTitle) {
    if(locked)
        std::cout<<"Impossibile modificare il titolo, nota bloccata"<<std::endl;
    else
        title=newTitle;
}

std::string Note::getText() {
    return text;
}

void Note::setText(std::string& newText) {
    if(locked)
        std::cout<<"Impossibile modificare il testo, nota bloccata"<<std::endl;
    else
        text=newText;
}

bool Note::isLocked() const {
    return locked;
}

void Note::changeLock() {
    locked=!locked;
}