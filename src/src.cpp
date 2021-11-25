#include<iostream>
#include "Fiction.hpp"

int main() {
    Book book1;
    Book book2("Song of Achilles", "Madelline Miller", 303);
    Fiction fiction1;
    Fiction fiction2("Circe", "Madelline Miller", 430, "Mythology");

    fiction1 = fiction2;

    fiction2 = fiction2;

    fiction2.print();

    return 0;
}