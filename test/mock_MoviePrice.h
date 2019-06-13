#ifndef LABO5_MOCK_MOVIEPRICE_H
#define LABO5_MOCK_MOVIEPRICE_H

#include <gmock/gmock.h>  // Brings in Google Mock.

#include "../src/MoviePrice.h"

class MockMoviePrice : public MoviePrice {
 public:
  MOCK_CONST_METHOD1(getPrice, double(unsigned int));
  MOCK_CONST_METHOD1(getBonusPoints, double(unsigned int));

  MockMoviePrice() {};

};

#endif //LABO5_MOCK_MOVIEPRICE_H
