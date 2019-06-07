//
// Created by filipe on 5/17/19.
//

// COPYRIGHT 2019 <TBD>
#ifndef INCLUDE_test_H_
#define INCLUDE_test_H_

#include <gtest/gtest.h>
#include "../src/Customer.h"
#include "../src/Basket.h"
#include "../src/Movie.h"
#include "../src/Rental.h"

class BillingTest : public ::testing::Test {
 protected:
  void SetUp() override {
    c1 = std::make_unique<Customer>(Customer("John"));
    b1 = std::make_unique<Basket>(Basket(*c1));
    m1 = std::make_unique<Movie>(Movie("Amazing Spiderman 63", MoviePrice::NEW_RELEASE));
    m2 = std::make_unique<Movie>(Movie("Peter Pan", MoviePrice::CHILDRENS));
    m3 = std::make_unique<Movie>(Movie("Clockwork Orange", MoviePrice::REGULAR));
    m4 = std::make_unique<Movie>(Movie("The Human Centipede", MoviePrice::REGULAR));
    r1 = std::make_unique<Rental>(Rental(*m1, 2));
    r2 = std::make_unique<Rental>(Rental(*m2, 22));
    r3 = std::make_unique<Rental>(Rental(*m3, 35));
    r4 = std::make_unique<Rental>(Rental(*m4, 99));
  }

  void TearDown() override {}
  std::unique_ptr<Customer> c1;
  std::unique_ptr<Basket> b1;
  std::unique_ptr<Movie> m1, m2, m3, m4;
  std::unique_ptr<Rental> r1, r2, r3, r4;

};

TEST_F(BillingTest, NoRentalsStatement) {
  EXPECT_STREQ(b1->billing().c_str(), "Rental Record for John\n"
                                        "Amount owed is 0\n"
                                        "You earned 0 frequent renter points");

}

TEST_F(BillingTest, MaxRentalStatement) {
  b1->addRental(*r1);
  b1->addRental(*r2);
  b1->addRental(*r3);
  b1->addRental(*r4);
  EXPECT_STREQ(b1->billing().c_str(), "Rental Record for John\n"
                                        "\tAmazing Spiderman 63\t6\n"
                                        "\tPeter Pan\t30\n"
                                        "\tClockwork Orange\t51.5\n"
                                        "\tThe Human Centipede\t147.5\n"
                                        "Amount owed is 235\n"
                                        "You earned 5 frequent renter points");
}

TEST_F(BillingTest, StatementChangeWhenAddingRental) {
  b1->addRental(*r1);
  std::string billing1 = b1->billing();
  b1->addRental(*r2);
  std::string billing2 = b1->billing();
  b1->addRental(*r1);
  std::string billing3 = b1->billing();
  EXPECT_STRNE(billing1.c_str(), billing2.c_str());
  EXPECT_STRNE(billing1.c_str(), billing3.c_str());
  EXPECT_STRNE(billing2.c_str(), billing3.c_str());
}
#endif // INCLUDE_test_H_
