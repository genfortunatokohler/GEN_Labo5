// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "Rental.h"

class Customer {
 public:
  Customer() = default;
  explicit Customer(const std::string &name) : _name(name) {};

  void addRental(const Rental &arg) {
    _rentals.push_back(arg);
  }
  std::string getName() const {
    return _name;
  };
  std::string statement();

 private:
  std::string _name;
  std::vector<Rental> _rentals;
};

#endif // CUSTOMER_H