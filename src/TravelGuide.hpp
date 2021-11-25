#include<iostream>
#include "Book.hpp"

class TravelGuide : public Book{
private:
    std::string city;

public:
    TravelGuide();
    TravelGuide(const std::string& title, const std::string& author,
        int nrOfPages, std::string city);
    
    TravelGuide& operator=(const TravelGuide& book);

    void print();
};
