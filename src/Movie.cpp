#include "Movie.h"

Movie::Movie(std::string title, const MoviePrice& movie_price) : title_(std::move(title)), movie_price_(&movie_price) {}

const MoviePrice& Movie::getPriceCode() const {
  return *movie_price_;
}

void Movie::setPriceCode(const MoviePrice& movie_price) {
  movie_price_ = &movie_price;
}

std::string Movie::getTitle() const {
  return title_;
}
