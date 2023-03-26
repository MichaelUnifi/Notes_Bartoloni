//
// Created by micha on 05/02/2023.
//

#ifndef NOTES_BARTOLONI_OBSERVER_H
#define NOTES_BARTOLONI_OBSERVER_H
class Note;

class Observer {
public:
    virtual ~Observer()=default;

    virtual void updateForRemoval(Note *s)=0;

};


#endif //NOTES_BARTOLONI_OBSERVER_H
