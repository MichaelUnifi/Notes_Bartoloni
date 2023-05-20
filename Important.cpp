//
// Created by micha on 26/03/2023.
//

#include "Important.h"


Important* Important::instance = nullptr;

Important::Important(std::string& n): Collection(n){}

Important *Important::getInstance() {
    if(instance== nullptr){
        std::string n="Important";
        instance=new Important(n);}
    return instance;
}

Important::~Important() {
    free(instance);
}