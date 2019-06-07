// Rental.h
#ifndef RENTAL_H
#define RENTAL_H

#include <utility>
#include "Movie.h"

class Rental {
 public:
  Rental(Movie movie, int daysRented) : movie_(std::move(movie)), days_rented_(daysRented) {}

  int getDaysRented() const {
    return days_rented_;
  }

  const Movie &getMovie() const {
    return movie_;
  }

  double getPrice() const {
    return movie_.getPriceCode().getPrice(days_rented_);
  }

  int getFrequentRenterPoints() const {
    int result = 1;

    if (days_rented_ > 1 && getMovie().getPriceCode() == MoviePrice::NEW_RELEASE)
      result += 1;

    return result;
  }

  std::string getFigures() const {
    std::ostringstream result;

    result << "\t" << getMovie().getTitle() << "\t"
              << getPrice() << "\n";

    return result.str();
  }

 private:
  Movie movie_;
  int days_rented_;
};

#endif // RENTAL_H