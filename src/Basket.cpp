#include "Basket.h"

#include <sstream>

void Basket::addRental(const Rental& rental) {
  rentals_.push_back(std::cref<Rental>(rental));
}

std::string Basket::billing() const {
  double totalAmount = 0;
  int frequentRenterPoints = 0;

  std::ostringstream result;
  result << "Rental Record for " << customer_.getName() << "\n";

  for (const Rental &rental : rentals_) {
    // add frequent renter points
    frequentRenterPoints += rental.getFrequentRenterPoints();

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
