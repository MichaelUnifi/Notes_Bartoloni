//
// Created by micha on 03/02/2023.
//

#ifndef NOTES_BARTOLONI_COLLECTION_H
#define NOTES_BARTOLONI_COLLECTION_H
#include <string>
#include <iostream>
#include <list>
#include <memory>
#include "Note.h"
#include "Subject.h"
#include"View.h"

class Collection: public Subject, public std::enable_shared_from_this<Collection>{

protected:
    std::list<std::shared_ptr<Note>> notes;
    std::string name;
    std::shared_ptr<Observer> view;
public:

    explicit Collection(const std::string& n);

    ~Collection() override;

    std::string getName() const override {return name;}

    void setName(const std::string &newName);

    bool searchNote(const std::string& title);

    Note takeNote(const std::string& title);

    void addNote(std::shared_ptr<Note> note);

    bool removeNote(std::shared_ptr<Note> note);

    void show();

    void add(std::shared_ptr<Observer> o) override;

    void remove(std::shared_ptr<Observer> o) override;

    int getSize() const{return notes.size();}

    void notify() override;
};


#endif //NOTES_BARTOLONI_COLLECTION_H
