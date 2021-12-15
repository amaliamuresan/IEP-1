#include "TravelGuide.hpp"

TravelGuide::TravelGuide() : Book(), city("Undefined") {};
TravelGuide::TravelGuide(const std::string& title, const std::string& author,
        int nrOfPages, std::string city) : Book(title, author, nrOfPages), city(city) {};
    
TravelGuide& TravelGuide::operator=(const TravelGuide& book) {
    if(this != &book) {
        city = book.city;
    }
	return *this;
}

void TravelGuide::print () {
    Book::print();
    std::cout << "City: " << city <<"\n";
}
