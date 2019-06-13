#include "Customer.h"
#include "MoviePrice.h"

#include <sstream>
#include <vector>

using std::ostringstream;
using std::vector;

using namespace std;

Customer::Customer(std::string name) : name_(std::move(name)) {}

std::string Customer::getName() const {
  return name_;
}
