//
// Created by micha on 26/03/2023.
//

#include "../Important.h"
#include "gtest/gtest.h"

TEST(Important, constructorTest){
    Important* important=Important::getInstance();
    ASSERT_EQ(0, important->getSize());
}

TEST(Important, addNoteTest){
    Important* important=Important::getInstance();
    Note* note=new Note("prova", "testo");
    important->addNote(note);
    EXPECT_EQ(1,important->getSize());
}



TEST(Important, updateForRemovalTest){//anomalia eseguendo tutti i test insieme
    Important* important=Important::getInstance();//comportamento strano, istanziato già con una nota dentro
    Note* note=new Note("prova", "testo");//se eseguo questo test singolarmente funziona
    important->addNote(note);
    note->deleteAndNotify();
    EXPECT_EQ(0,important->getSize());
}