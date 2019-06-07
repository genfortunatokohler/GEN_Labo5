// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Rental.h"

#include <string>
#include <vector>
#include <utility>


class Customer {
 public:
  Customer() = default;
  explicit Customer(std::string name);

  std::string getName() const;

 private:
  std::string name_;
};

#endif // CUSTOMER_H