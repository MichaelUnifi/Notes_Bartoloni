//
// Created by micha on 05/02/2023.
//

#ifndef NOTES_BARTOLONI_SUBJECT_H
#define NOTES_BARTOLONI_SUBJECT_H
#include "Observer.h"
#include <memory>

class Subject {
public:



    virtual void add(std::shared_ptr<Observer> o)=0;

    virtual void remove(std::shared_ptr<Observer> o)=0;

    virtual void notify()=0;

    virtual std::string getName()const =0 ;

    virtual ~Subject()= default;

};


#endif //NOTES_BARTOLONI_SUBJECT_H