//
// Created by Jonathan Zaehringer on 2019-05-24.
//

#include "MoviePrice.h"

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