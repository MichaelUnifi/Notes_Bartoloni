//
// Created by micha on 27/04/2023.
//

#include "../Collection.h"
#include "../Observer.h"
#include "../Note.h"
#include "../View.h"
#include "gtest/gtest.h"

TEST(View,updateTest){
    std::shared_ptr<View> view=std::make_shared<View>();
    std::string name="name";
    std::shared_ptr<Collection> collection=std::make_shared<Collection>(name);
    std::string title="testing";
    std::string text="sample";
    std::shared_ptr<Note> note=std::make_shared<Note>(title, text);
    view->subscribe(collection, collection->getSize());
    collection->add(std::dynamic_pointer_cast<Observer>(view));
    collection->addNote(note);
    ASSERT_EQ(1,view->getNoteNumberByCollection(collection));
}

TEST(View, subscribingTest){
    std::shared_ptr<View> view=std::make_shared<View>();
    std::string name="name";
    std::shared_ptr<Collection> collection=std::make_shared<Collection>(name);
    view->subscribe(collection, collection->getSize());
    collection->add(std::dynamic_pointer_cast<Observer>(view));
    ASSERT_EQ(1,view->getCollectionsNumber());
    view->unsubscribe(collection);
    collection->remove(std::dynamic_pointer_cast<Observer>(view));
    ASSERT_EQ(0,view->getCollectionsNumber());
}