#include <iostream>
#include "Collection.h"
#include "Note.h"
#include "Important.h"
#include "View.h"
#include <memory>
#include <string>

int main() {
    std::shared_ptr<View> view=std::make_shared<View>();
    std::shared_ptr<Important> important(Important::getInstance());
    std::string title1="Acquario";
    std::string text1="Cambiare acqua, potare alghe, comprare mangime";
    std::string title2="Spesa";
    std::string text2="Acqua, pane, verdure, pollo, parmigiano, mele, farina";
    std::string title3="Lavoro";
    std::string text3="meeting prossima settimana, finire relazione, organizzare trasferta";
    std::shared_ptr<Note> n1=std::make_shared<Note>(title1, text1);
    std::shared_ptr<Note> n2=std::make_shared<Note>(title2, text2);
    std::shared_ptr<Note> n3=std::make_shared<Note>(title3, text3);
    view->subscribe(important,important->getSize());
    important->add(std::dynamic_pointer_cast<Observer>(view));
    important->addNote(n3);
    n3->changeLock();
    view->show();
    std::cout<<"\n\n\n"<<std::endl;
    std::string name1="Casa";
    std::shared_ptr<Collection> c1=std::make_shared<Collection>(name1);
    view->subscribe(c1,c1->getSize());
    c1->add(std::dynamic_pointer_cast<Observer>(view));
    c1->addNote(n1);
    c1->addNote(n2);
    c1->show();
    std::cout<<"\n\n\n"<<std::endl;
    important->show();
    std::cout<<"\n\n\n"<<std::endl;
    view->show();

    //sezione modifica
    std::string newTitle2="Comprare";
    n2->setTitle(newTitle2);
    std::string newTitle1="Pesci";
    n1->setTitle(newTitle1);
    std::string newText1="Cambiare acqua, potare alghe, comprare mangime, comprare pesci";
    n1->setText(newText1);
    std::cout<<"\n\n\n"<<std::endl;
    c1->show();
    n2->changeLock();

    //sezione rimozione
    std::cout<<"\n\n\n"<<std::endl;
    std::cout<<"Rimuovo nota 2 da Casa"<<std::endl;
    c1->removeNote(n2);
    std::cout<<"\n\n\n"<<std::endl;
    view->show();
    c1->show();
    std::cout<<"\n\n\n"<<std::endl;
    std::cout<<"\n"<<std::endl;
    bool removed=important->removeNote(n3);
    std::cout<<"La nota 3 non viene rimossa!"<<std::endl;
    std::cout<<"\n\n\n"<<std::endl;
    important->show();

    //search and take

    std::cout<<"\n\n\n"<<std::endl;
    std::cout<<"Cerco nota 1 in Casa"<<std::endl;
    std::string searchTitle1="Pesci";
    bool found=c1->searchNote(searchTitle1);
    if(found)
        std::cout<<"Nota trovata!"<<std::endl;
    else
        std::cout<<"Nota non trovata!"<<std::endl;
    std::cout<<"Cerco nota 2 in Casa"<<std::endl;
    std::string searchTitle2="Pesci";
    found=c1->searchNote(searchTitle2);
    if(found)
        std::cout<<"Nota trovata!"<<std::endl;
    else
        std::cout<<"Nota non trovata!"<<std::endl;
    std::cout<<"\n\n\n"<<std::endl;
    std::cout<<"Prendo nota 1 da Casa"<<std::endl;
    std::string takeTitle1="Pesci";
    Note n4=c1->takeNote(takeTitle1);
    c1->show();
}