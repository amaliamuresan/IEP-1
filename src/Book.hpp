#include<iostream>

#ifndef BOOK_H
#define BOOK_H

class Book {

protected:
    std::string author;
    std::string title;
    int nrOfPages;

public:
    Book();
    Book(const std::string& title, const std::string& author, int nrOfPages);
    
    Book& operator=(const Book& book);

    virtual void print();

};
#endif