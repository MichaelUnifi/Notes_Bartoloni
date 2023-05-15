//
// Created by micha on 24/04/2023.
//

#ifndef NOTES_BARTOLONI_VIEW_H
#define NOTES_BARTOLONI_VIEW_H
#include "Observer.h"
#include "Collection.h"
#include "Subject.h"
#include <memory>
#include <list>
#include <utility>
#include <map>

class View : public Observer{
private:
    std::map<std::shared_ptr<Subject>,int> collectionsInfo;
public:
    View();

    int getCollectionsNumber(){return collectionsInfo.size();}

    void show();

    int getNoteNumberByCollection(std::shared_ptr<Subject> collection){return collectionsInfo.at(collection);}

    virtual void update(std::shared_ptr<Subject> collection, int noteCount);

    virtual void subscribe(std::shared_ptr<Subject> collection, int noteCount);

    virtual void unsubscribe(std::shared_ptr<Subject> collection);

    ~View() override= default;
};


#endif //NOTES_BARTOLONI_VIEW_H
