//
// Created by micha on 26/03/2023.
//

#include "Important.h"


Important* Important::instance = nullptr;

Important::Important():Collection(name) {}

Important *Important::getInstance() {
    if(instance== nullptr)
        instance=new Important();
    return instance;
}

Important::~Important() {
    notes.clear();
    free(instance);
}





