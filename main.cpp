#include <iostream>
#include "Collection.h"
#include "Note.h"
#include  <list>
#include "Observer.h"
#include "Subject.h"
int main() {
    std::list<Collection*> collections;
    Collection important( "important");
    collections.push_back(&important);
    Note* n1=new Note("Acquario","Cambiare acqua, potare alghe, comprare mangime");
    Note* n2=new Note("Spesa","Acqua, pane, verdure, pollo, parmigiano, mele, farina");
    Note* n3=new Note("Lavoro", "meeting prossima settimana, finire relazione, organizzare trasferta");
    important.addNote(n1);
    important.addNote(n2);
    important.addNote(n3);
    n1->add(&important);
    n2->add(&important);
    n3->add(&important);
    n3->lock();
    bool close=false;
    int k=1;
    std::cout<<"Le tue collection:\n"<<std::endl;
    for(auto it:collections){
        std::cout<<k<<". "<<it->getName()<<" - "<<it->getSize()<<" elementi"<<std::endl;
        k++;
    }
    std::cout<<"\ncosa vuoi fare?"<<std::endl;
    std::cout<<"\n0. esci\n1. aggiungi una collection\n2. crea una nota\n3. accedi a una collection\n"<<std::endl;
    std::cin>>k;
    do{
        for(auto it:collections){
            std::cout<<k<<". "<<it->getName()<<" - "<<it->getSize()<<" elementi"<<std::endl;
            k++;
        }
        switch(k){
            case 0:
                close=true;
                break;
            case 1:
            {
                std::string collectionName;
                std::cout<<"Seleziona un nome per la collection: "<<std::endl;
                std::cin>>collectionName;
                collections.push_back(new Collection(collectionName));
                break;
            }
            case 2:
            {
                std::string noteName;
                std::string noteText;std::cout<<"Seleziona un nome per la nota: "<<std::endl;
                std::cin>>noteName;
                std::cout<<"Seleziona il contenuto della nota: "<<std::endl;
                std::cin>>noteText;
                Note* note=new Note(noteName,noteText);
                std::cout<<"In quali collection vuoi mettere la nota? "<<std::endl;
                bool put=false;
                int choice=0;
                for(auto it: collections){
                    std::cout<<it->getName()<<" - digita 0 per inserire, qualunque altro tasto altrimenti"<<std::endl;
                    std::cin>>choice;
                    if(!choice){
                        it->addNote(note);
                        note->add(it);
                        put=true;
                    }
                }
                if(!put){
                    std::cout<<"la nota non è stata messa in nessuna collection, verrà eliminata"<<std::endl;
                    delete note;
                }
                break;
            }
            case 3:
                break;
            default:
                std::cout<<"input non valido! "<<std::endl;
                break;
        }
    }while(!close);
}
