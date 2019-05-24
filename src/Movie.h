// Movie.h
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <utility>

class Movie {
 public:
  static const int CHILDRENS = 2;
  static const int REGULAR = 0;
  static const int NEW_RELEASE = 1;

  explicit Movie(std::string title, int priceCode = REGULAR);

  int getPriceCode() const;
  void setPriceCode(int arg);
  std::string getTitle() const;

 private:
  std::string title_;
  int price_code_;
};

#endif // MOVIE_H