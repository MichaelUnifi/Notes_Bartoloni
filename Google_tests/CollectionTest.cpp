//
// Created by micha on 01/03/2023.
//

#include "../Collection.h"
#include "../Note.h"
#include "../View.h"
#include "gtest/gtest.h"

TEST(Collection, constructorTest){
    Collection collection((std::string &) "name");
    ASSERT_EQ("name", collection.getName());
    ASSERT_EQ(0, collection.getSize());
}

TEST(Collection, setNameTest){
    Collection collection((std::string &) "name");
    std::string mod="modified";
    collection.setName(mod);
    ASSERT_EQ("modified", mod);
}

TEST(Collection, getSizeTest){
    Collection collection((std::string &) "name");
    ASSERT_EQ(0, collection.getSize());
}

TEST(Collection, addNoteTest){
    Collection collection((std::string &) "name");
    std::shared_ptr<Note> note=std::make_shared<Note>((std::string &) "prova",(std::string &) "testo");
    collection.addNote(note);
    ASSERT_EQ(1,collection.getSize());
}

TEST(Collection, notifyTest){
    View view;
    std::shared_ptr<Collection> collection=std::make_shared<Collection>((std::string &) "name");
    view.subscribe(collection, collection->getSize());
    std::shared_ptr<Note> note=std::make_shared<Note>((std::string &) "prova",(std::string &) "testo");
    collection->addNote(note);
    ASSERT_EQ(1,view.getNoteNumberByCollection(collection));
}

TEST(Collection, removeNoteTest){
    Collection collection((std::string &) "name");
    std::shared_ptr<Note> note=std::make_shared<Note>((std::string &) "prova",(std::string &) "testo");
    collection.addNote(note);
    ASSERT_EQ(1,collection.getSize());
    collection.removeNote(note);
    ASSERT_EQ(0,collection.getSize());
}

TEST(Collection, searchNoteTest){
    Collection collection((std::string &) "name");
    std::shared_ptr<Note> note=std::make_shared<Note>((std::string &) "prova",(std::string &) "testo");
    collection.addNote(note);
    ASSERT_TRUE(collection.searchNote((std::string &) "prova"));
    ASSERT_FALSE(collection.searchNote((std::string &) "prova2"));
}

TEST(Collection, takeNoteTest){
    Collection collection((std::string &) "name");
    std::shared_ptr<Note> note=std::make_shared<Note>((std::string &) "prova",(std::string &) "testo");
    collection.addNote(note);
    ASSERT_EQ("prova",collection.takeNote((std::string &) "prova").getTitle());
    ASSERT_EQ("testo",collection.takeNote((std::string &) "prova").getText());
}