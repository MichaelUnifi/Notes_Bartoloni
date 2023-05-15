//
// Created by micha on 05/03/2023.
//
#include "../Note.h"
#include "gtest/gtest.h"

TEST(Note, constructorTest){
    Note note((std::string &) "testing",(std::string &) "sample");
    ASSERT_EQ("testing", note.getTitle());
    ASSERT_EQ("sample", note.getText());
}

TEST(Note, getTextTest){
    Note note((std::string &) "testing",(std::string &) "sample");
    ASSERT_EQ("sample", note.getText());
}

TEST(Note, setTitleTest){
    Note note((std::string &) "testing",(std::string &) "sample");
    note.setTitle((std::string &) "changing");
    ASSERT_EQ("changing", note.getTitle());
}

TEST(Note, setTextTest){
    Note note((std::string &) "testing",(std::string &) "sample");
    note.setText((std::string &) "changes");
    ASSERT_EQ("changes", note.getText());
}

TEST(Note, lockTest){
    Note note((std::string &) "testing",(std::string &) "sample");
    ASSERT_EQ(false, note.isLocked());
    note.changeLock();
    ASSERT_EQ(true, note.isLocked());
}