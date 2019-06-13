#include "MoviePrice.h"

// file used only to declare value of enum
const MoviePrice MoviePrice::REGULAR(2,
                                     [](int nb_days) {
                                       double res = REGULAR.base_price_;
                                       if (nb_days > 2)
                                         res += (nb_days - 2) * 1.5;

                                       return res;
                                     },
                                     [](int nb_days) { return 0; }
);

const MoviePrice MoviePrice::NEW_RELEASE(0,
                                         [](int nb_days) {
                                           return nb_days * 3;
                                         },
                                         [](int nb_days) {
                                           return nb_days > 1 ? 1 : 0;
                                         }
);

const MoviePrice MoviePrice::CHILDRENS(1.5,
                                       [](int nb_days) {
                                         double res = CHILDRENS.base_price_;
                                         if (nb_days > 3)
                                           res += (nb_days - 3) * 1.5;

                                         return res;
                                       },
                                       [](int nb_days) { return 0; }
);
