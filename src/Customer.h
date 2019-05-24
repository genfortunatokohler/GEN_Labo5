// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <utility>

#include "Rental.h"

class Customer {
 public:
  Customer() = default;
  explicit Customer(std::string name);

  void addRental(const Rental &arg);
  std::string getName() const;
  std::string statement();

 private:
  std::string name_;
  std::vector<Rental> rentals_;
};

#endif // CUSTOMER_H