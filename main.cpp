#include <iostream>
#include "Collection.h"
#include "Note.h"
#include "Important.h"
#include "View.h"
#include <memory>

int main() {
    View view;
    std::shared_ptr<Important> important(Important::getInstance());
    std::shared_ptr<Note> n1=std::make_shared<Note>((std::string &) "Acquario",(std::string &) "Cambiare acqua, potare alghe, comprare mangime");
    std::shared_ptr<Note> n2=std::make_shared<Note>((std::string &) "Spesa",(std::string &) "Acqua, pane, verdure, pollo, parmigiano, mele, farina");
    std::shared_ptr<Note> n3=std::make_shared<Note>((std::string &) "Lavoro",(std::string &) "meeting prossima settimana, finire relazione, organizzare trasferta");
    view.subscribe(important,important->getSize());
    important->addNote(n3);
    n3->changeLock();
    view.show();
    std::cout<<"\n\n\n"<<std::endl;
    std::shared_ptr<Collection> c1=std::make_shared<Collection>((std::string &) "Casa");
    view.subscribe(c1,c1->getSize());
    c1->addNote(n1);
    c1->addNote(n2);
    view.show();

    //sezione modifica
    n2->setTitle((std::string &) "Spesa");
    n2->setTitle((std::string &) "Spesa");
    n1->setTitle((std::string &) "Acquario");
    n1->setText((std::string &) "Cambiare acqua, potare alghe, comprare mangime, comprare pesci");
    std::cout<<"\n\n\n"<<std::endl;
    c1->show();
    n2->changeLock();

    //sezione rimozione
    std::cout<<"\n\n\n"<<std::endl;
    std::cout<<"Rimuovo nota 2 da Casa"<<std::endl;
    c1->removeNote(n2);
    std::cout<<"\n\n\n"<<std::endl;
    view.show();
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
    bool found=c1->searchNote((std::string &) "Acquario");
    if(found)
        std::cout<<"Nota trovata!"<<std::endl;
    else
        std::cout<<"Nota non trovata!"<<std::endl;
    std::cout<<"\n\n\n"<<std::endl;
    std::cout<<"Prendo nota 1 da Casa"<<std::endl;
    Note n4=c1->takeNote((std::string &) "Acquario");
    c1->show();
}