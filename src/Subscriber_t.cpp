/*
  Subscriber_t.cpp

  Test program for class Subscriber
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>

#include "Subscriber.hpp"

int main() {

    // no rental
    {
        Subscriber subscriber("Fred");

        assert(subscriber.getName() == "Fred");

        // test using literal string
        assert(subscriber.statement() == "Rental Record for Fred\nAmount owed is: 0\n");
    }

    // no rental
    {
        Subscriber subscriber("Fred");

        assert(subscriber.getName() == "Fred");

        // test using external file
        std::ifstream finput("Subscriber_t.norental.txt");
        std::ostringstream out;
        out << finput.rdbuf();

        assert(subscriber.statement() == out.str());
    }

    // one rental
    {
        Subscriber subscriber("Fred");

        assert(subscriber.getName() == "Fred");

        // one rental
        subscriber.addRental(Rental(Video("A", Video::REGULAR), 1));

        // test using external file
        std::ifstream finput("Subscriber_t.onerental.txt");
        std::ostringstream out;
        out << finput.rdbuf();

        assert(subscriber.statement() == out.str());
    }

    // two rentals
    {
        Subscriber subscriber("Fred");

        // Create movies
        Video lotr("Lord of the Rings", Video::REGULAR);
        Video hp("Harry Potter", Video::CHILDRENS);

        // Create rentals of these movies
        Rental r1(lotr, 10);
        Rental r2(hp, 5);

        // add two rentals
        subscriber.addRental(r1);
        subscriber.addRental(r2);

        // test using external file
        std::ifstream finput("Subscriber_t.tworental.txt");
        std::ostringstream out;
        out << finput.rdbuf();
        assert(subscriber.statement() == out.str());
    }

    return 0;
}
