#include <iostream>
#include "Collection.h"
#include "Note.h"
#include "Important.h"
#include <list>
#include <memory>


int main() {
    std::unique_ptr<Important> important(Important::getInstance());

    Note* n1=new Note("Acquario","Cambiare acqua, potare alghe, comprare mangime");
    Note* n2=new Note("Spesa","Acqua, pane, verdure, pollo, parmigiano, mele, farina");
    Note* n3=new Note("Lavoro", "meeting prossima settimana, finire relazione, organizzare trasferta");

    important->addNote(n3);
    n3->changeLock();
    important->show();
    std::cout<<"\n\n\n"<<std::endl;

    std::unique_ptr<Collection> c1(new Collection("Casa"));
    c1->addNote(n1);
    c1->addNote(n2);
    c1->show();


    //sezione modifica
    n1->modify( "Acquario","Cambiare acqua, potare alghe, comprare mangime, pulire filtro");
    std::cout<<"\n\n\n"<<std::endl;
    c1->show();


    //sezione rimozione
    std::cout<<"\n\n\n"<<std::endl;
    std::cout<<"Rimuovo nota 2 da tutte le collection"<<std::endl;
    std::cout<<"\n\n\n"<<std::endl;
    n2->deleteAndNotify();
    c1->show();
    n3->deleteAndNotify();
    std::cout<<"\n\n\n"<<std::endl;
    important->show();
    std::cout<<"\n"<<std::endl;
    std::cout<<"La nota 3 non viene rimossa!"<<std::endl;
    std::cout<<"\n\n\n"<<std::endl;
    important->show();

}
