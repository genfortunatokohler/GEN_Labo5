#include <utility>
#include <sstream>

#include "Rental.h"

const Movie &Rental::getMovie() const {
  return movie_;
}

double Rental::getPrice() const {
  return movie_.getPriceCode().getPrice(days_rented_);
}

int Rental::getFrequentRenterPoints() const {
  return 1 + movie_.getPriceCode().getBonusPoints(days_rented_);
}

std::string Rental::getFigures() const {
  std::ostringstream result;

  result << "\t" << getMovie().getTitle() << "\t"
         << getPrice() << "\n";

  return result.str();
}
