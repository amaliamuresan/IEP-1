#include<iostream>
#include "Book.hpp"

class Fiction : public Book {

private:
    std::string genre;

public:
    Fiction();
    Fiction(const std::string& title, const std::string& author,
        int nrOfPages, std::string genre);
    
    Fiction& operator=(const Fiction& book);

    void print();

};