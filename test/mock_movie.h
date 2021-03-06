#ifndef LABO5_MOCK_MOVIE_H
#define LABO5_MOCK_MOVIE_H7

#include "../src/Movie.h"

#include "mock_MoviePrice.h"

#include <gmock/gmock.h>  // Brings in Google Mock.


class MockMovie : public Movie {
 public:
  MOCK_CONST_METHOD0(getPriceCode, const MockMoviePrice&());
  MOCK_METHOD1(setPriceCode, void(const MockMoviePrice&));
  MOCK_CONST_METHOD0(getTitle, std::string());

  MockMovie(const std::string &title, const MockMoviePrice &moviePrice) : Movie(title, moviePrice) {}
  MockMovie() : Movie("", MockMoviePrice()){}
};

#endif  // LABO5_MOCK_MOVIE_H
