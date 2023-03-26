//
// Created by micha on 05/03/2023.
//
#include "../Note.h"
#include "../Collection.h"
#include "gtest/gtest.h"

TEST(Note, getTitleTest){
    Note note("testing", "sample");
    ASSERT_EQ("testing", note.getTitle());
}

TEST(Note, getTextTest){
    Note note("testing", "sample");
    ASSERT_EQ("sample", note.getText());
}

TEST(Note, setTitleTest){
    Note note("testing", "sample");
    note.setTitle("changing");
    ASSERT_EQ("changing", note.getTitle());
}

TEST(Note, setTextTest){
    Note note("testing", "sample");
    note.setText("changes");
    ASSERT_EQ("changes", note.getText());
}

TEST(Note, lockTest){
    Note note("testing", "sample");
    ASSERT_EQ(false, note.isLocked());
    note.changeLock();
    ASSERT_EQ(true, note.isLocked());
}

TEST(Note, observersTest){
    Collection collection("name");
    Collection collection2("name");
    Collection collection3("name");
    Note* note=new Note("testing", "sample");
    note->add(&collection);
    note->add(&collection2);
    note->add(&collection3);
    collection.addNote(note);
    note->deleteAndNotify();
    EXPECT_EQ(0,0);
}