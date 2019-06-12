// Rental.h
#ifndef RENTAL_H
#define RENTAL_H

#include "Movie.h"

class Rental {
 public:
  Rental(const Movie& movie, int daysRented) : movie_(movie), days_rented_(daysRented) {}

  virtual const Movie &getMovie() const;
  virtual double getPrice() const;
  virtual int getFrequentRenterPoints() const;
  virtual std::string getFigures() const;

 private:
  const Movie& movie_;
  int days_rented_;
};

#endif // RENTAL_H