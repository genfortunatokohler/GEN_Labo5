//
// Created by filipe on 6/12/19.
//

#ifndef LABO5_BASKETTEST_H
#define LABO5_BASKETTEST_H

#include <gtest/gtest.h>
#include "../src/Customer.h"
#include "../src/Basket.h"
#include "../src/Movie.h"
#include "../src/Rental.h"
#include "mock_rental.h"

using ::testing::Exactly;
using ::testing::Return;
using ::testing::ReturnRef;

// this is to validate that a statement without rentals is always empty
TEST(BillingTest, NoRentalsStatement) {

  Customer c("John");
  Basket b(c);

  EXPECT_STREQ(b.billing().c_str(), "Rental Record for John\n"
                                    "Amount owed is 0\n"
                                    "You earned 0 frequent renter points");

}

// this is a real world scenario test.
TEST(BillingTest, MaxRentalStatement) {

  Customer c("John");
  Basket b(c);
  MockMovie m;
  MockRental r(m, 0);

  EXPECT_CALL(r, getFrequentRenterPoints())
      .Times(Exactly(4))
      .WillOnce(Return(2))
      .WillOnce(Return(1))
      .WillOnce(Return(1))
      .WillOnce(Return(1));

  EXPECT_CALL(r, getPrice())
      .Times(Exactly(4))
      .WillOnce(Return(6))
      .WillOnce(Return(30))
      .WillOnce(Return(51.5))
      .WillOnce(Return(147.5));

  EXPECT_CALL(r, getFigures())
      .Times(Exactly(4))
      .WillOnce(Return("\tAmazing Spiderman 63\t6\n"))
      .WillOnce(Return("\tPeter Pan\t30\n"))
      .WillOnce(Return("\tClockwork Orange\t51.5\n"))
      .WillOnce(Return("\tThe Human Centipede\t147.5\n"));

  b.addRental(r);
  b.addRental(r);
  b.addRental(r);
  b.addRental(r);
  EXPECT_STREQ(b.billing().c_str(), "Rental Record for John\n"
                                    "\tAmazing Spiderman 63\t6\n"
                                    "\tPeter Pan\t30\n"
                                    "\tClockwork Orange\t51.5\n"
                                    "\tThe Human Centipede\t147.5\n"
                                    "Amount owed is 235\n"
                                    "You earned 5 frequent renter points");
}

// this test has for goal to verify that the statement changes as you add more rentals
TEST(BillingTest, StatementChangeWhenAddingRental) {

  Customer c("John");
  Basket b(c);
  MockMovie m;
  MockRental r(m, 0);

  // mock the frequentRenterPoints getter to always return one, as it's irrelevant to the current test
  EXPECT_CALL(r, getFrequentRenterPoints())
      .WillRepeatedly(Return(1));

  // mock the price getter to always return one, as it's irrelevant to the current test
  EXPECT_CALL(r, getPrice())
      .WillRepeatedly(Return(1));

  // mock the figures getter to always return "test", as it's irrelevant to the current test
  EXPECT_CALL(r, getFigures())
      .WillRepeatedly(Return("test"));

  b.addRental(r);
  std::string billing1 = b.billing();
  b.addRental(r);
  std::string billing2 = b.billing();
  b.addRental(r);
  std::string billing3 = b.billing();

  EXPECT_STRNE(billing1.c_str(), billing2.c_str());
  EXPECT_STRNE(billing1.c_str(), billing3.c_str());
  EXPECT_STRNE(billing2.c_str(), billing3.c_str());
}

#endif //LABO5_BASKETTEST_H
