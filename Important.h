//
// Created by micha on 26/03/2023.
//

#ifndef NOTES_BARTOLONI_IMPORTANT_H
#define NOTES_BARTOLONI_IMPORTANT_H

#include <memory>
#include "Note.h"
#include "Observer.h"
#include "Subject.h"
#include "Collection.h"

class Important: public Collection{
public:
    static Important* getInstance();

    virtual ~Important() override;

protected:
    Important(std::string& n);

private:
    static Important* instance;
};


#endif //NOTES_BARTOLONI_IMPORTANT_H
