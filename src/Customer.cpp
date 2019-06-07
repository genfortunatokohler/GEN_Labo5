// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"
#include "MoviePrice.h"

using std::ostringstream;
using std::vector;

using namespace std;

Customer::Customer(std::string name) : name_(std::move(name)) {}

void Customer::addRental(const Rental &arg) {
  rentals_.push_back(arg);
}

std::string Customer::getName() const {
  return name_;
}

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    vector< Rental >::iterator iter = rentals_.begin();
    vector< Rental >::iterator iter_end = rentals_.end();
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for ( ; iter != iter_end; ++iter ) {
        double thisAmount = 0;
        Rental each = *iter;

        thisAmount += each.getPrice();

        // add frequent renter points
        frequentRenterPoints++;

        // add bonus for a two day new release rental
        if ( ( &each.getMovie().getPriceCode() == &MoviePrice::NEW_RELEASE )
             && each.getDaysRented() > 1 ) frequentRenterPoints++;

        // show figures for this rental
        result << "\t" << each.getMovie().getTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount;
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}