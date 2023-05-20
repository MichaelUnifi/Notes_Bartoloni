//
// Created by micha on 20/05/2023.
//
#include "gtest/gtest.h"
#include "../Note.h"
#include "../Important.h"
#include "../Observer.h"

TEST(Important, constructorTest){
    std::string title="testing";
    std::string text="sample";
    Note note1(title,text);
    Important* important=Important::getInstance();
    ASSERT_EQ("Important", important->getName());
    ASSERT_EQ(0, important->getSize());
}