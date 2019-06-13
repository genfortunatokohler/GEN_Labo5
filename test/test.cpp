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
