//
// Created by micha on 05/02/2023.
//

#ifndef NOTES_BARTOLONI_OBSERVER_H
#define NOTES_BARTOLONI_OBSERVER_H

class Subject;

class Observer {
public:
    virtual ~Observer()=default;

    virtual void update(std::shared_ptr<Subject> collection, int noteCount)=0;

    virtual void subscribe(std::shared_ptr<Subject> collection, int noteCount)=0;

    virtual void unsubscribe(std::shared_ptr<Subject> collection)=0;

};


#endif //NOTES_BARTOLONI_OBSERVER_H
