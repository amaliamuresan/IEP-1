#include<iostream>
#include "Fiction.hpp"
#include "TravelGuide.hpp"

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

    return 0;
}