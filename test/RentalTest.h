#ifndef LABO5_RENTALTEST_H
#define LABO5_RENTALTEST_H

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "mock_MoviePrice.h"
#include "mock_movie.h"

using ::testing::Exactly;
using ::testing::Return;
using ::testing::ReturnRef;

TEST(RentalTest, IsPriceCalculatedProperly) {
  MockMoviePrice moviePrice;
  MockMovie movie("TEST_MOVIE", moviePrice);

  // mock movie price to return once 1.62 USD and then 7.312 if called for 1 day
  EXPECT_CALL(moviePrice, getPrice(1))
      .Times(Exactly(2))
      .WillOnce(Return(1.626))
      .WillOnce(Return(7.312));

  // mock movie price to return once 53.52 USD and then 234.3 if called for 32 days
  EXPECT_CALL(moviePrice, getPrice(32))
      .Times(Exactly(2))
      .WillOnce(Return(53.52))
      .WillOnce(Return(234.3));

  // mock movie to always return the mock moviePrice when trying to get PriceCode
  EXPECT_CALL(movie, getPriceCode)
      .Times(Exactly(4))
      .WillRepeatedly(ReturnRef(moviePrice));

  Rental rental1(movie, 1);
  Rental rental2(movie, 32);

  EXPECT_EQ(rental1.getPrice(), 1.626);
  EXPECT_EQ(rental1.getPrice(), 7.312);

  EXPECT_EQ(rental2.getPrice(), 53.52);
  EXPECT_EQ(rental2.getPrice(), 234.3);
}

TEST(RentalTest, areRentalBonusPointsCalculatedProperly) {
  MockMoviePrice moviePrice;
  MockMovie movie("TEST_MOVIE", moviePrice);

  // mock movie price to return once 1 point and then 0 points if called for 1 day
  EXPECT_CALL(moviePrice, getBonusPoints(1))
      .Times(Exactly(2))
      .WillOnce(Return(1))
      .WillOnce(Return(0));

  // mock movie price to return once 43 point and then 6 points if called for 32 days
  EXPECT_CALL(moviePrice, getBonusPoints(32))
      .Times(Exactly(2))
      .WillOnce(Return(43))
      .WillOnce(Return(6));

  // mock movie to always return the mock moviePrice when trying to get PriceCode
  EXPECT_CALL(movie, getPriceCode)
      .Times(Exactly(4))
      .WillRepeatedly(ReturnRef(moviePrice));

  Rental rental1(movie, 1);
  Rental rental2(movie, 32);

  // we expect numbers larger than mocked values by one, due to the system always giving a freebie point per rental
  EXPECT_EQ(rental1.getFrequentRenterPoints(), 2);
  EXPECT_EQ(rental1.getFrequentRenterPoints(), 1);

  EXPECT_EQ(rental2.getFrequentRenterPoints(), 44);
  EXPECT_EQ(rental2.getFrequentRenterPoints(), 7);
}

#endif //LABO5_RENTALTEST_H
