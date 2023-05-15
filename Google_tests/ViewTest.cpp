//
// Created by micha on 27/04/2023.
//

#include "../Collection.h"
#include "../Observer.h"
#include "../Note.h"
#include "../View.h"
#include "gtest/gtest.h"

TEST(View,updateTest){
    View view;
    std::shared_ptr<Collection> collection=std::make_shared<Collection>((std::string &)"name");
    view.subscribe(collection, collection->getSize());
    std::shared_ptr<Note> note=std::make_shared<Note>((std::string &)"prova",(std::string &) "testo");
    collection->addNote(note);
    ASSERT_EQ(1,view.getNoteNumberByCollection(collection));
}

TEST(View, subscribingTest){
    View view;
    std::shared_ptr<Collection> collection=std::make_shared<Collection>((std::string &)"name");
    view.subscribe(collection, collection->getSize());
    ASSERT_EQ(1,view.getCollectionsNumber().size());
    view.unsubscribe(collection);
    ASSERT_EQ(0,view.getCollectionsNumber());
}