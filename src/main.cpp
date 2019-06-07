#include <iostream>

#include "Customer.h"
#include "Basket.h"

int main() {

  Customer customer("Olivier");
  Basket basket(customer);
  basket.addRental(Rental(Movie("Karate Kid"), 7));
  basket.addRental(Rental(Movie("Avengers: Endgame", MoviePrice::NEW_RELEASE), 5));
  basket.addRental(Rental(Movie("Snow White", MoviePrice::CHILDRENS), 3));

  std::cout << basket.billing() << std::endl;

  return 0;
}