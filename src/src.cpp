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

    void printBook () {
        std::cout << "Titlu: " << title << "\nAuthor: " << author << "\nYear: " << year_published << "\n"; 
    }

    bool operator==(const Book& book) const {
    return title == book.title && author == book.author && year_published == book.year_published;
    }

    Book(const Book& book) {
        title = book.title;
        author = book.author;
        year_published = book.year_published;
    }

    Book& operator=(const Book& book)
	{
        title = book.title;
        author = book.author;
        year_published = book.year_published;

		return *this;
	}

	~Book() {
        std::cout << title << " - Book - Destructor\n";
	}


};

class Library {
private:
    std::string name;
    std::list<Book> books;

    Library& operator=(const Library& library);
    Library(const Library&);

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

    void printLibrary () {
        std::cout << "Name: " << name << "\n";
        std::cout << "Books:\n";

        for(Book b : books) {
            b.printBook();
        }
    }

	~Library()
	{
        std::cout << name << " - Library - Destructor\n";
	}
};



int main() {

    Library library("The Library");
    Book book1("Harry Potter and The Goblet of Fire", 
    "J.K. Rowling", 2000);
    Book book2("The Odyssey", "Homer", 1614);
    Book book3("Pebble in the Sky", "Isaac Asimov", 1950);
    Book book4("Circe", "Madeline Miller", 2018);

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);


    library.printLibrary();

    return 0;
}

