#ifndef LABO5_MOVIEPRICETEST_H
#define LABO5_MOVIEPRICETEST_H

#include "../src/MoviePrice.h"

#include <gtest/gtest.h>

TEST(MoviePriceTest, NEW_RELEASE_PriceCalculateCorrecly) {
  const MoviePrice &movie_price = MoviePrice::NEW_RELEASE;
  EXPECT_EQ(movie_price.getPrice(2), 6);
}

TEST(MoviePriceTest, REGULAR_PriceCalculateCorrecly) {
  const MoviePrice &movie_price = MoviePrice::REGULAR;
  EXPECT_EQ(movie_price.getPrice(35), 51.5);
  EXPECT_EQ(movie_price.getPrice(99), 147.5);
}

TEST(MoviePriceTest, CHILDRENS_PriceCalculateCorrecly) {
  const MoviePrice &movie_price = MoviePrice::CHILDRENS;
  EXPECT_EQ(movie_price.getPrice(22), 30);
}

TEST(MoviePriceTest, NEW_RELEASE_BonusCalculateCorrecly) {
  const MoviePrice &movie_price = MoviePrice::NEW_RELEASE;
  EXPECT_EQ(movie_price.getBonusPoints(1), 0);
  EXPECT_EQ(movie_price.getBonusPoints(2), 1);
  EXPECT_EQ(movie_price.getBonusPoints(150), 1);
}

TEST(MoviePriceTest, REGULAR_BonusCalculateCorrecly) {
  const MoviePrice &movie_price = MoviePrice::REGULAR;
  EXPECT_EQ(movie_price.getBonusPoints(1), 0);
  EXPECT_EQ(movie_price.getBonusPoints(2), 0);
  EXPECT_EQ(movie_price.getBonusPoints(150), 0);
}

TEST(MoviePriceTest, CHILDRENS_BonusCalculateCorrecly) {
  const MoviePrice &movie_price = MoviePrice::CHILDRENS;
  EXPECT_EQ(movie_price.getBonusPoints(1), 0);
  EXPECT_EQ(movie_price.getBonusPoints(2), 0);
  EXPECT_EQ(movie_price.getBonusPoints(150), 0);
}

#endif  // LABO5_MOVIEPRICETEST_H
