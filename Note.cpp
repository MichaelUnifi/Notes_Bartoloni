//
// Created by micha on 03/02/2023.
//

#include "Note.h"

std::string Note::getTitle() {
    return title;
}

void Note::setTitle(std::string newTitle) {
    title=newTitle;
}

std::string Note::getText() {
    return text;
}

void Note::setText(std::string newText) {
    text=newText;
}

bool Note::isLocked() const {
    return locked;
}

void Note::changeLock() {
    locked=!locked;
}

bool Note::modify(std::string &newTitle, std::string &newText) {
    if(locked)
        return false;
    title=newTitle;
    text=newText;
    return true;
}

void Note::add(Observer *o) {
    collections.push_back(o);
}

void Note::remove(Observer *o) {
    collections.remove(o);

}

bool Note::deleteAndNotify() {
    if(locked)
        return false;
    for(auto it: collections){
        it->updateForRemoval(this);
    }
    collections.clear();
    return true;
}
