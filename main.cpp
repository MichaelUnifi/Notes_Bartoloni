#include <iostream>
#include "Collection.h"
#include "Note.h"
#include "Important.h"
#include <list>
int main() {
    Important* important=Important::getInstance();

    Note* n1=new Note("Acquario","Cambiare acqua, potare alghe, comprare mangime");
    Note* n2=new Note("Spesa","Acqua, pane, verdure, pollo, parmigiano, mele, farina");
    Note* n3=new Note("Lavoro", "meeting prossima settimana, finire relazione, organizzare trasferta");
    important->addNote(n1);
    important->addNote(n2);
    important->addNote(n3);
    n1->add(important);
    n2->add(important);
    n3->add(important);
    n3->changeLock();
    important->show();
}
