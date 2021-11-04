#include<iostream>
#include<stdlib.h>
#include<list>
#include<algorithm>


class Book {
private:
    std::string title;
    std::string author;
    int year_published;

public:
    Book(const std::string& title,
        const std::string& author,
        int year_published):
        title(title),
        author(author),
        year_published(year_published) {
            std::cout << "Book - Constructor\n";
        }
    
    Book() : title("Undefined"), author("Undefined"), year_published(0) {};

    friend std::ostream& operator<< (std::ostream &output, const Book &book) {
        output << "Titlu: " << book.title << "\nAuthor: " << book.author << "\nYear: " << book.year_published << "\n"; 
        return output;
    }

    bool operator==(const Book& book) const {
    return
       title == book.title
       && author == book.author
       && year_published == book.year_published
    ;
}

    // Destructor
	~Book() {
        std::cout << title << " Book - Destructor\n";
	}


};

class Library {
private:
    std::string name;
    std::list<Book> books;

public:
    Library(const std::string& name) :
    name(name),
    books({}) {}

    Library() : name("Undefined"), books({}) {};

    void addBook(Book book) {
        books.push_back(book);
    }

    bool isBookAvailable(Book book) 
    {
        for(Book b : books) {
            if (book == b) {
                return true;
            }
        }
        return false;
    }

    std::list<Book> getBooks() {
        return books;
    }

    friend std::ostream& operator<< (std::ostream &output, const Library &library) {
        output << "Name: " << library.name << "\n";
        output << "Books:\n";

        for(Book b : library.books) {
            output << b;
        }

        return output;
    }

    // Destructor
	~Library()
	{
        std::cout << name << " Library - Destructor\n";
	}

    // Copy assigment operator
	Library& operator = (const Library& library) {

        this->name = library.name;
        this->books = library.books;

        std::cout << "Library - Copy Assignment Operator\n";
		return *this;
	}
};



int main() {

    Library library("The Library");
    Book book1("Harry Potter and The Goblet of Fire", 
    "J.K. Rowling", 2000);
    Book book2("The Oddysey", "Homer", 1614);
    Book book3("Pebble in the Sky", "Isaac Asimov", 1950);
    Book book4("Circe", "Madeline Miller", 2018);

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);



    std::cout << library;
    return 0;
}

