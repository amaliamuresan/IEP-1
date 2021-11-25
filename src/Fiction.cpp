#include<iostream>
#include "Fiction.hpp"


Fiction::Fiction() : Book(), genre("Undefined") {};
Fiction::Fiction(const std::string& title, const std::string& author,
        int nrOfPages, std::string genre) : Book(title, author, nrOfPages), genre(genre) {};
    
Fiction& Fiction::operator=(const Fiction& book) {
    Book::operator=(book);
    if(this != &book) {
        genre = book.genre;
    }
	return *this;
}

// Fiction& Fiction::operator=(const Fiction& book) {
//     if(this != &book) {
//         genre = book.genre;
//     }
// 	return *this;
// }

void Fiction::print () {
    Book::print();
    std::cout << "Genre: " << genre <<"\n";
}
