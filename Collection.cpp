//
// Created by micha on 03/02/2023.
//

#include "Collection.h"

void Collection::show() {
    int index=1;
    for(auto it: notes){
        std::cout<<"\nindex. "<<it->getTitle()<<"\n"<<it->getText()<<std::endl;
        index++;
    }
}

void Collection::modify() {
    show();
    std::cout<<"\nselezionare la nota da modificare"<<std::endl;
    int index;
    std::cin>>index;
    auto note=notes.begin();
    for(int i=1;i<index;i++){
        note++;
    }
    if(!(*note)->isLocked()){
        (*note)->getText();
        (*note)->getTitle();
        std::cout<<"digitare 0 per modificare il titolo, 1 per modificare il testo"<<std::endl;
        int choice;
        std::cin>>choice;
        if(choice){
            std::cout<<"Inserire il nuovo testo"<<std::endl;
            std::string newText;
            std::cin>>newText;
            (*note)->setText(newText);
        }
        else{
            std::cout<<"Inserire il nuovo titolo"<<std::endl;
            std::string newTitle;
            std::cin>>newTitle;
            (*note)->setTitle(newTitle);
        }
    }else{
        std::cout<<"Nota non modificabile!\n"<<std::endl;
    }
}

void Collection::updateForRemoval(Note* note) {
    if(!note->isLocked()){
        notes.remove(note);
    }else{
        std::cout<<"Nota non eliminabile!\n"<<std::endl;
    }
    std::cout<<"numero di note nella collezione: "<<getSize()<<std::endl;
}
