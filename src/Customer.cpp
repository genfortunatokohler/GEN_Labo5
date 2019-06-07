// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"
#include "MoviePrice.h"

using std::ostringstream;
using std::vector;

using namespace std;

Customer::Customer(std::string name) : name_(std::move(name)) {}

void Customer::addRental(const Rental &arg) {
  rentals_.push_back(arg);
}

std::string Customer::getName() const {
  return name_;
}

string Customer::statement() {
  double totalAmount = 0;
  int frequentRenterPoints = 0;

  ostringstream result;
  result << "Rental Record for " << getName() << "\n";

  for (const Rental &rental : rentals_) {
    // add frequent renter points
    frequentRenterPoints++;

    // add bonus for a two day new release rental
    if ((&rental.getMovie().getPriceCode() == &MoviePrice::NEW_RELEASE)
        && rental.getDaysRented() > 1)
      frequentRenterPoints++;

    // show figures for this rental
    result << rental.getFigures();

    totalAmount += rental.getPrice();
  }
  // add footer lines
  result << "Amount owed is " << totalAmount << "\n";
  result << "You earned " << frequentRenterPoints
         << " frequent renter points";
  return result.str();
}