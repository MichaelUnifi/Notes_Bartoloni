//
// Created by micha on 01/03/2023.
//

#include "../Collection.h"
#include "gtest/gtest.h"

TEST(Collection, getNameTest){
    Collection collection("name");
    ASSERT_EQ("name", collection.getName());
}

TEST(Collection, setNameTest){
    Collection collection("name");
    std::string mod="modified";
    collection.setName(mod);
    ASSERT_EQ("modified", mod);
}

TEST(Collection, getSizeTest){
Collection collection("name");
ASSERT_EQ(0, collection.getSize());
}

TEST(Collection, addNoteTest){
    Collection collection("name");
    Note* note=new Note("prova", "testo");
    collection.addNote(note);
    EXPECT_EQ(1,collection.getSize());
}



TEST(Collection, updateForRemovalTest){
    Collection collection("name");
    Note* note=new Note("prova", "testo");
    collection.addNote(note);
    note->deleteAndNotify();
    EXPECT_EQ(0,collection.getSize());
}