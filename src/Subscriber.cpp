/*
  Customer.cpp

  Definition file for Customer class
*/

#include "Customer.hpp"
#include "Video.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// constructor
Customer::Customer(const std::string& name)
    : name(name)
{ }

// customer name
std::string Customer::getName() const {

    return name;
}

// add a rental to this customer
void Customer::addRental(const Rental& rental) {

    rentals.push_back(rental);
}

// calculates amount for current statement
double Customer::amountFor(std::vector<Rental>::const_iterator it) const {
  double thisAmount = 0;
  switch(it->getVideo().getCode()) {

  case Video::REGULAR:
    thisAmount += 2;
    if (it->getDaysRented() > 2)
    thisAmount += (it->getDaysRented() - 2) * 1.5;
    break;
  
  case Video::NEW_RELEASE:
    thisAmount += it->getDaysRented() * 3;
    break;

  case Video::CHILDRENS:
    thisAmount += 1.5;
    if (it->getDaysRented() > 3)
      thisAmount += (it->getDaysRented() - 3) * 1.5;
    break;
  }

  return thisAmount;
}

// customer rental statement
std::string Customer::statement() const {

    // customer name
    std::string result("Rental Record for ");
    result += getName();
    result += "\n";

    // rentals
    double totalAmount = 0;
    for (std::vector<Rental>::const_iterator it = rentals.begin(); it != rentals.end(); ++it) {

        // title of rental
        result += "\t";
        result += it->getVideo().getTitle();
        result += "\t";

        double thisAmount = 0;
        thisAmount = amountFor(it);

        // amount of rental
        std::ostringstream out_str_stream;
        out_str_stream << thisAmount;
        result += out_str_stream.str();
        result += "\n";

        totalAmount += thisAmount;
    }

    // total amount owed
    result += "Amount owed is: ";
    std::ostringstream out_str_stream;
    out_str_stream << totalAmount;
    result += out_str_stream.str();
    result += "\n";

    return result;
}