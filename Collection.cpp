//
// Created by micha on 03/02/2023.
//

#include "Collection.h"

void Collection::show() {
    int index=1;
    std::cout<<name<<std::endl;
    for(auto it: notes){
        std::cout<<"\n"<<index<<"."<<it->getTitle()<<"\n"<<it->getText()<<". "<<std::endl;
        if(it->isLocked())
            std::cout<<"bloccata"<<std::endl;
        else
            std::cout<<" non bloccata"<<std::endl;
        index++;
    }
}

void Collection::modify() {
    std::cout<<"\nselezionare la nota da modificare"<<std::endl;
    int index;
    std::cin>>index;
    auto note=notes.begin();
    for(int i=1;i<index;i++){
        note++;
    }
    std::cout<<"digitare 0 per modificare il titolo, 1 per modificare il testo, 2 per bloccare/sbloccare la nota, 3 per rimuovere la nota dalla collection, qualunque altro tasto per annullare"<<std::endl;
    int choice;
    std::cin>>choice;
    std::cout<<(*note)->getTitle()<<"\n"<<(*note)->getText()<<". "<<std::endl;
    if((*note)->isLocked())
        std::cout<<"bloccata"<<std::endl;
    else
        std::cout<<"non bloccata"<<std::endl;
    if(choice==0){
        if(!(*note)->isLocked()){
            std::cout<<"Inserire il nuovo titolo"<<std::endl;
            std::string newTitle;
            std::cin>>newTitle;
            (*note)->setTitle(newTitle);
            show();
        }else{
            std::cout<<"Nota non modificabile!\n"<<std::endl;
        }
    }
    else if(choice==1){
        if(!(*note)->isLocked()){
            std::cout<<"Inserire il nuovo testo"<<std::endl;
            std::string newText;
            std::cin>>newText;
            (*note)->setText(newText);
            show();
        }else{
            std::cout<<"Nota non modificabile!\n"<<std::endl;
        }
    }else if(choice==2){
        (*note)->changeLock();
    }
    else if(choice==3){
        if(!(*note)->isLocked()){
            notes.remove(*note);
            (*note)->remove(this);
        }else{
            std::cout<<"Nota non eliminabile!\n"<<std::endl;
        }
    }
}

void Collection::updateForRemoval(Note* note, bool lock) {
    if(!lock){
        notes.remove(note);
    }else{
        std::cout<<"Nota non eliminabile!\n"<<std::endl;
    }
    std::cout<<"numero di note nella collezione: "<<getSize()<<std::endl;
}


