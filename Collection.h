//
// Created by micha on 03/02/2023.
//

#ifndef NOTES_BARTOLONI_COLLECTION_H
#define NOTES_BARTOLONI_COLLECTION_H
#include <string>
#include <iostream>
#include <list>
#include "Note.h"
#include "Observer.h"

class Collection: public Observer{

private:
    std::list<Note*> notes;
    std::string name;
public:

    explicit Collection(std::string n):name(n){}

    ~Collection() override;

    std::string getName(){return name;}

    void setName(std::string &newName);


    void addNote(Note* note);

    void show();

    void updateForRemoval(Note* note) override;//metodo Observer

    int getSize(){return notes.size();}

};


#endif //NOTES_BARTOLONI_COLLECTION_H
