#include<iostream>
#include<mutex>
#include<thread>

#include "Fiction.hpp"
#include "TravelGuide.hpp"
#include "BookBuy.hpp"
#include "BookRent.hpp" 

std::mutex mutex;

void buyBookFromLibrary() {
    mutex.lock();
    std::cout << "The book is now purchasing. Please wait.\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Done\n";
    mutex.unlock();
}

int main() {
    Book book1;
    Book book2("Song of Achilles", "Madelline Miller", 303);
    Fiction fiction1;
    Fiction fiction2("Circe", "Madelline Miller", 430, "Mythology");
    TravelGuide travel1;
    TravelGuide travel2("Explore Paris", "Joe", 300, "Paris");


    fiction2 = fiction2;
    // output: The object is the same

    fiction1 = fiction2;
    // output: The object is different

    fiction1.print();
    // output:
    // Titlu: Circe
    // Author: Madelline Miller
    // Nr of pages: 430
    // Genre: Mythology

    travel1 = travel2;
    travel1.print();
    // output:
    // Titlu: Undefined
    // Author: Undefined
    // Nr of pages: 0
    // City: Paris

    // Unit 13
   std::shared_ptr<BookBuy> bookBuy1 = std::make_shared<BookBuy>(BookBuy(fiction1));
   std::shared_ptr<BookBuy> bookBuy2 = bookBuy1;
   
   std::unique_ptr<BookRent> bookRent1 = std::make_unique<BookRent>(BookRent(travel2));
//    std::unique_ptr<BookRent> bookRent2 = bookRent1; // nu poate referi catre un unique_ptr
    std::unique_ptr<BookRent> bookRent2 = std::move(bookRent1); // bookrent1 nu va mai avea nicio referinta

    // Unit 14
    std::thread bookBuyer1(buyBookFromLibrary);
    std::thread bookBuyer2(buyBookFromLibrary);

    bookBuyer1.join();
    bookBuyer2.join();

    return 0;
}