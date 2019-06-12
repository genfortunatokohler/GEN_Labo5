//
// Created by filipe on 5/17/19.
//

// COPYRIGHT 2019 <TBD>

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "BasketTest.h"
#include "MoviePriceTest.h"
#include "RentalTest.h"

int main(int ac, char *av[]) {
  testing::InitGoogleMock(&ac, av);
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
