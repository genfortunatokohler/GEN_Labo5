// Movie.h
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <utility>

#include "MoviePrice.h"

class Movie {
 public:
  explicit Movie(std::string title, const MoviePrice& movie_price = MoviePrice::REGULAR);

  const MoviePrice& getPriceCode() const;
  void setPriceCode(const MoviePrice& movie_price);
  std::string getTitle() const;

 private:
  std::string title_;
  const MoviePrice* movie_price_;
};

#endif // MOVIE_H