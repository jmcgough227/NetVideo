/*
  Subscriber.hpp

  Include file for Subscriber class
*/

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Rental.hpp"

#include <string>
#include <vector>

class Subscriber {
public:

    // constructor
    Subscriber(const std::string& name);

    // subscriber name
    std::string getName() const;

    // add a new rental
    void addRental(const Rental& rental);

    // subscriber rental statement
    std::string statement() const;

    // calculates amount for current statement
    double amountFor(std::vector<Rental>::const_iterator it) const;

private:
    std::string name;
    std::vector<Rental> rentals;
};

#endif
