//
// Created by Jonathan Zaehringer on 2019-05-24.
//

#ifndef LABO5_MOVIEPRICETEST_H
#define LABO5_MOVIEPRICETEST_H

#include <gtest/gtest.h>
#include "../src/MoviePrice.h"

TEST(MoviePriceTest, NEW_RELEASECalculateCorrecly) {
  MoviePrice movie_price = MoviePrice::NEW_RELEASE;
  EXPECT_EQ(movie_price.getPrice(2), 6);
}

TEST(MoviePriceTest, REGULARCalculateCorrecly) {
  MoviePrice movie_price = MoviePrice::REGULAR;
  EXPECT_EQ(movie_price.getPrice(35), 51.5);
  EXPECT_EQ(movie_price.getPrice(99), 147.5);
}

TEST(MoviePriceTest, CHILDRENSCalculateCorrecly) {
  MoviePrice movie_price = MoviePrice::CHILDRENS;
  EXPECT_EQ(movie_price.getPrice(22), 30);
}

#endif //LABO5_MOVIEPRICETEST_H
