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

 private:
  Movie movie_;
  int days_rented_;
};

#endif // RENTAL_H