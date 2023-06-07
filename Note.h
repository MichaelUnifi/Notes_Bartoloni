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
    Note(const std::string& ti, const std::string& te):title(ti),text(te),locked(false){}

    const std::string getTitle();

    void setTitle(const std::string& newTitle);

    const std::string getText();

    void setText(const std::string& newText);

    bool isLocked() const;

    void changeLock();
};


#endif //NOTES_BARTOLONI_NOTE_H
