//
// Created by micha on 26/03/2023.
//

#ifndef NOTES_BARTOLONI_IMPORTANT_H
#define NOTES_BARTOLONI_IMPORTANT_H

#include "Note.h"
#include "Observer.h"

class Important: public Observer{
public:
    static Important* getInstance();


    ~Important() override;

    void addNote(Note* note);


    void show();


    void updateForRemoval(Note* note) override;//metodo Observer

    int getSize();

protected:
    Important()= default;

private:
    std::list<Note*> notes;
    std::string name="Important";
    static Important* instance;
};


#endif //NOTES_BARTOLONI_IMPORTANT_H
