//
// Created by micha on 03/02/2023.
//

#ifndef NOTES_BARTOLONI_NOTE_H
#define NOTES_BARTOLONI_NOTE_H
#include <string>
#include <iostream>
#include <list>


class Note{
private:
    std::string title;
    std::string text;
    bool locked;
public:
    Note(std::string& ti, std::string& te):title(ti),text(te),locked(false){}

    ~Note()=default;

    std::string getTitle();

    void setTitle(std::string& newTitle);

    std::string getText();

    void setText(std::string& newText);

    bool isLocked() const;

    void changeLock();
};


#endif //NOTES_BARTOLONI_NOTE_H
