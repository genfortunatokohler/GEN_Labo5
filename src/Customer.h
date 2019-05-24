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
  std::string _name;
  std::vector<Rental> _rentals;
};

#endif // CUSTOMER_H