//
// Created by micha on 05/03/2023.
//
#include "../Note.h"
#include "gtest/gtest.h"

TEST(Note, constructorTest){
    std::string title="testing";
    std::string text="sample";
    Note note(title,text);
    ASSERT_EQ("testing", note.getTitle());
    ASSERT_EQ("sample", note.getText());
}

TEST(Note, getTextTest){
    std::string title="testing";
    std::string text="sample";
    Note note(title,text);
    ASSERT_EQ("sample", note.getText());
}

TEST(Note, setTitleTest){
    std::string title="testing";
    std::string text="sample";
    Note note(title,text);
    std::string newTitle="changing";
    note.setTitle(newTitle);
    ASSERT_EQ("changing", note.getTitle());
}

TEST(Note, setTextTest){
    std::string title="testing";
    std::string text="sample";
    Note note(title,text);
    std::string newText="changes";
    note.setText(newText);
    ASSERT_EQ("changes", note.getText());
}

TEST(Note, lockTest){
    std::string title="testing";
    std::string text="sample";
    Note note(title,text);
    ASSERT_EQ(false, note.isLocked());
    note.changeLock();
    ASSERT_EQ(true, note.isLocked());
}