//
// Created by micha on 05/02/2023.
//

#ifndef NOTES_BARTOLONI_SUBJECT_H
#define NOTES_BARTOLONI_SUBJECT_H
#include "Observer.h"


class Subject {
public:



    virtual void add(Observer *o)=0;

    virtual void remove(Observer *o)=0;

    virtual void notifyForRemoval()=0;

};


#endif //NOTES_BARTOLONI_SUBJECT_H
