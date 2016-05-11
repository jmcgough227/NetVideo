/*
  VideoStore.cpp

  Basic operations of a video store
*/

#include <iostream>

#include "Video.hpp"
#include "Rental.hpp"
#include "Subscriber.hpp"

int main() {

    // Videos
    Video lotr("Lord of the Rings", Video::REGULAR);
    Video hp("Harry Potter", Video::CHILDRENS);

    // Rentals of these movies
    Rental r1(lotr, 10);
    Rental r2(hp, 5);

    // Subscriber with some rentals
    Subscriber subscriber("Fred");
    subscriber.addRental(r1);
    subscriber.addRental(r2);

    // Output subscriber statement
    std::cout << subscriber.statement();

    return 0;
}
