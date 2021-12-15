#include <memory>
#include "Book.hpp"

class BookBuy {
public: 
    BookBuy(Book book);
private: 
    Book bookToBuy;
};