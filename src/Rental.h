// Rental.h
#ifndef RENTAL_H
#define RENTAL_H

#include "Movie.h"

class Rental {
 public:
  Rental(Movie movie, int daysRented) : movie_(std::move(movie)), days_rented_(daysRented) {}

  int getDaysRented() const;
  const Movie &getMovie() const;
  double getPrice() const;
  int getFrequentRenterPoints() const;
  std::string getFigures() const;

 private:
  Movie movie_;
  int days_rented_;
};

#endif // RENTAL_H