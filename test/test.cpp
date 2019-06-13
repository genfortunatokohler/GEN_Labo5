#include "BasketTest.h"
#include "MoviePriceTest.h"
#include "RentalTest.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int ac, char *av[]) {
  testing::InitGoogleMock(&ac, av);
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
