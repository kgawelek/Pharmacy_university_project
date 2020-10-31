//
// Created by konga on 24.10.2020.
//

#ifndef APTEKA_SIROUP_H
#define APTEKA_SIROUP_H

#include "Medicine.h"

class Siroup: public Medicine {

    const std::string category = "syrop";
    double volume;
public:
    Siroup(std::string n, double v, Prescription p, Age a,Replacements * r, Contraindications * c, Price price1):
    Medicine(n, p, a, r, c, price1), volume(v){};
    std::string get_category(){return category;};
    double get_volume(){return volume;};
};

std::ostream &operator << (std::ostream& s, Siroup &med);
#endif //APTEKA_SIROUP_H
