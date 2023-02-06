//
// Created by micha on 05/02/2023.
//

#ifndef NOTES_BARTOLONI_OBSERVER_H
#define NOTES_BARTOLONI_OBSERVER_H
class Subject;

class Observer {
public:
    virtual ~Observer()=default;

    virtual void updateForRemoval(Subject *s)=0;

};


#endif //NOTES_BARTOLONI_OBSERVER_H
