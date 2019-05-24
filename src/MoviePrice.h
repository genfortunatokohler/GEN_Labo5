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

const MoviePrice MoviePrice::REGULAR = MoviePrice(2,
  [](int nb_days){
    double res = REGULAR.base_price_;
    if ( nb_days > 2 )
      res += ( nb_days - 2 ) * 1.5 ;

    return res;
  });

const MoviePrice MoviePrice::NEW_RELEASE = MoviePrice(0,
   [](int nb_days){
     return nb_days * 3;
   });

const MoviePrice MoviePrice::CHILDRENS = MoviePrice(1.5,
   [](int nb_days){
     double res = CHILDRENS.base_price_;
     if ( nb_days > 3 )
       res += ( nb_days - 3 ) * 1.5 ;

     return res;
   });

#endif //LABO5_MOVIEPRICE_H
