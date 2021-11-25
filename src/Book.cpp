#include "Book.hpp"


Book::Book() : title("Undefined"), author("Undefined"), nrOfPages(0) {};
Book::Book(const std::string& title,
    const std::string& author,
    int nrOfPages):
    title(title),
    author(author),
    nrOfPages(nrOfPages) {}
    
Book& Book::operator=(const Book& book) {
    if(this != &book) {
    std::cout << "The object is different\n";
        title = book.title;
        author = book.author;
        nrOfPages = book.nrOfPages;
    }
    else {
        std::cout << "The object is the same\n";
    }
    return *this;
}

void Book::print () {
    std::cout << "\nTitlu: " << title << "\nAuthor: " << author << "\nNr of pages: " << nrOfPages << "\n"; 
}