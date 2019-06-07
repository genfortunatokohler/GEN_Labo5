//
// Created by Jonathan Zaehringer on 2019-05-24.
//

#ifndef LABO5_MOVIEPRICE_H
#define LABO5_MOVIEPRICE_H

#include <functional>

class MoviePrice {
 public:
  static const MoviePrice REGULAR;
  static const MoviePrice NEW_RELEASE;
  static const MoviePrice CHILDRENS;

 private:
  MoviePrice(double base_price, std::function <double(int)> price_calculation):  base_price_(base_price), price_calculation_(std::move(price_calculation)) {}

 public:
  double getPrice(unsigned int nbDay) const {
    return price_calculation_(nbDay);
  }

 private:
  const double base_price_;
  std::function <double(int)> price_calculation_;
};

#endif //LABO5_MOVIEPRICE_H
