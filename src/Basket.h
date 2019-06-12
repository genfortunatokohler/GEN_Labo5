#ifndef BASKET_H_
#define BASKET_H_

#include "Customer.h"

#include <vector>

class Basket {
 public:
  explicit Basket(const Customer &customer) : customer_(customer) {}
  Basket(const Customer &customer, std::vector<std::reference_wrapper<const Rental>> rentals) : customer_(customer), rentals_(std::move(rentals)) {}

  void addRental(const Rental& rental);
  std::string billing() const;

 private:
  const Customer &customer_;
  std::vector<std::reference_wrapper<const Rental>> rentals_;
};

#endif  // BASKET_H_
