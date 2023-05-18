//
// Created by micha on 01/03/2023.
//

#include "../Collection.h"
#include "../Note.h"
#include "../View.h"
#include "gtest/gtest.h"

TEST(Collection, constructorTest){
    std::string name="name";
    Collection collection(name);
    ASSERT_EQ("name", collection.getName());
    ASSERT_EQ(0, collection.getSize());
}

TEST(Collection, setNameTest){
    std::string name="name";
    Collection collection(name);
    std::string mod="modified";
    collection.setName(mod);
    ASSERT_EQ("modified", mod);
}

TEST(Collection, getSizeTest){
    std::string name="name";
    Collection collection(name);
    ASSERT_EQ(0, collection.getSize());
}

TEST(Collection, notifyTest){
    std::shared_ptr<View> view=std::make_shared<View>();
    std::string name="name";
    std::shared_ptr<Collection> collection=std::make_shared<Collection>(name);
    view->subscribe(collection, collection->getSize());
    collection->add(std::dynamic_pointer_cast<Observer>(view));
    std::string title="testing";
    std::string text="sample";
    std::shared_ptr<Note> note=std::make_shared<Note>(title, text);
    collection->addNote(note);
    ASSERT_EQ(1,view->getNoteNumberByCollection(collection));
}

TEST(Collection, noteTesting){
    std::shared_ptr<View> view=std::make_shared<View>();
    std::string name="name";
    std::shared_ptr<Collection> collection=std::make_shared<Collection>(name);
    view->subscribe(collection, collection->getSize());
    collection->add(std::dynamic_pointer_cast<Observer>(view));
    std::string title="testing";
    std::string text="sample";
    std::shared_ptr<Note> note=std::make_shared<Note>(title, text);
    collection->addNote(note);
    ASSERT_EQ(1,collection->getSize());
    collection->removeNote(note);
    ASSERT_EQ(0,collection->getSize());
}

TEST(Collection, searchNoteTest){
    std::shared_ptr<View> view=std::make_shared<View>();
    std::string name="name";
    std::shared_ptr<Collection> collection=std::make_shared<Collection>(name);
    view->subscribe(collection, collection->getSize());
    collection->add(std::dynamic_pointer_cast<Observer>(view));
    std::string title="testing";
    std::string text="sample";
    std::shared_ptr<Note> note=std::make_shared<Note>(title, text);
    collection->addNote(note);
    std::string title2="testing2";
    ASSERT_TRUE(collection->searchNote(title));
    ASSERT_FALSE(collection->searchNote(title2));
}

TEST(Collection, takeNoteTest){
    std::shared_ptr<View> view=std::make_shared<View>();
    std::string name="name";
    std::shared_ptr<Collection> collection=std::make_shared<Collection>(name);
    view->subscribe(collection, collection->getSize());
    collection->add(std::dynamic_pointer_cast<Observer>(view));
    std::string title="testing";
    std::string text="sample";
    std::shared_ptr<Note> note=std::make_shared<Note>(title, text);
    collection->addNote(note);
    ASSERT_EQ("testing",collection->takeNote(title).getTitle());
}