//
// Created by micha on 24/04/2023.
//

#include "View.h"

View::View() {
    collectionsInfo=std::map<std::shared_ptr<Subject>,int>();
}

void View::update(std::shared_ptr<Subject> collection, int noteCount){
    collectionsInfo[collection]=noteCount;
}

void View::show() {
    for(auto& collectionInfo : collectionsInfo){
        std::cout<<collectionInfo.first->getName()<<":"<<collectionInfo.second<<" note"<<std::endl;
    }
}

void View::subscribe(std::shared_ptr<Subject> collection, int noteCount){
    collectionsInfo.insert(std::pair<std::shared_ptr<Subject>,int>(collection,noteCount));
    //collection->add(shared_from_this());
}

void View::unsubscribe(std::shared_ptr<Subject> collection){
    collectionsInfo.erase(collection);
    //collection->remove(shared_from_this());
}
