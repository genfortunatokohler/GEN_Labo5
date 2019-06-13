#ifndef LABO5_MOCK_MOVIEPRICE_H
#define LABO5_MOCK_MOVIEPRICE_H

#include "../src/MoviePrice.h"

#include <gmock/gmock.h>  // Brings in Google Mock.

class MockMoviePrice : public MoviePrice {
 public:
  MOCK_CONST_METHOD1(getPrice, double(unsigned int));
  MOCK_CONST_METHOD1(getBonusPoints, double(unsigned int));

  MockMoviePrice() = default;
};

#endif  // LABO5_MOCK_MOVIEPRICE_H
