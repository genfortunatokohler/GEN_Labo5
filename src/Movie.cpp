#include "Movie.h"

const int Movie::CHILDRENS;
const int Movie::REGULAR;
const int Movie::NEW_RELEASE;

Movie::Movie(std::string title, int priceCode) : title_(std::move(title)), price_code_(priceCode) {}

int Movie::getPriceCode() const {
  return price_code_;
}

void Movie::setPriceCode(int arg) {
  price_code_ = arg;
}

std::string Movie::getTitle() const {
  return title_;
}