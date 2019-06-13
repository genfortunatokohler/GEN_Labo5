#ifndef LABO5_MOVIEPRICE_H
#define LABO5_MOVIEPRICE_H

#include <functional>

// Java style enum to simplify compare and have some methods in C++
class MoviePrice {
 public:
  static const MoviePrice REGULAR;
  static const MoviePrice NEW_RELEASE;
  static const MoviePrice CHILDRENS;

  MoviePrice(const MoviePrice &) = delete;
  MoviePrice(MoviePrice &&) = delete;

  bool operator==(const MoviePrice &rhs) const {
    return this == &rhs;
  }

 private:
  MoviePrice(const double base_price,
             std::function<double(int)> price_calculation,
             std::function<int(int)> bonus_point_calculation)
      : base_price_(base_price),
        price_calculation_(std::move(price_calculation)),
        bonus_point_calculation_(std::move(bonus_point_calculation)) {}

 protected:
  // protected used for mocking purposes
  MoviePrice() : MoviePrice(0, nullptr, nullptr) {};

  ~MoviePrice() = default;

 public:
  virtual double getPrice(unsigned int nbDay) const {
    return price_calculation_(nbDay);
  }

  virtual double getBonusPoints(unsigned int nbDay) const {
    return bonus_point_calculation_(nbDay);
  }

 private:
  const double base_price_;
  std::function<double(int)> price_calculation_;
  std::function<int(int)> bonus_point_calculation_;
};

#endif  // LABO5_MOVIEPRICE_H
