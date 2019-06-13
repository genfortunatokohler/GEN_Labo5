#ifndef MOVIE_H
#define MOVIE_H

#include "MoviePrice.h"

#include <string>
#include <utility>

class Movie {
 public:
  explicit Movie(std::string title, const MoviePrice& movie_price = MoviePrice::REGULAR);

  virtual const MoviePrice& getPriceCode() const;
  virtual void setPriceCode(const MoviePrice& movie_price);
  virtual std::string getTitle() const;



 private:
  std::string title_;
  const MoviePrice* movie_price_;
};

#endif // MOVIE_H