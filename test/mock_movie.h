//
// Created by filipe on 6/7/19.
//

#ifndef LABO5_MOCK_MOVIE_H
#define LABO5_MOCK_MOVIE_H

#include "gmock/gmock.h"  // Brings in Google Mock.

#include "../src/Movie.h"

class MockMovie : public Movie {
 public:
  MOCK_CONST_METHOD0(getPriceCode, const MockMoviePrice&());
  MOCK_METHOD1(setPriceCode, void(const MockMoviePrice&));
  MOCK_CONST_METHOD0(getTitle, std::string());

  MockMovie(const std::string &title, const MockMoviePrice &moviePrice) : Movie(title, moviePrice) {}
};

#endif //LABO5_MOCK_MOVIE_H
