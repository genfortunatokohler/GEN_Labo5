#ifndef LABO5_MOCK_RENTAL_H
#define LABO5_MOCK_RENTAL_H

#include "gmock/gmock.h"  // Brings in Google Mock.

#include "../src/Rental.h"
#include "mock_movie.h"

class MockRental : public Rental {
 private:
  MockMovie movie;
 public:
  MOCK_CONST_METHOD0(getPrice, double());
  MOCK_CONST_METHOD0(getFrequentRenterPoints, int());
  MOCK_CONST_METHOD0(getFigures, std::string());
  MOCK_CONST_METHOD0(getMovie, const MockMovie&());

  MockRental(const MockMovie& movie, int days) : Rental(movie, days) {}
};

#endif //LABO5_MOCK_RENTAL_H
