//
// Created by kgawelek on 20.10.2020.
//

#ifndef APTEKA_PILL_H
#define APTEKA_PILL_H
#include "Medicine.h"

class Pill: public Medicine {

    int nr_of_pills;
    const std::string category = "tabletki";
public:
    Pill() = default;
    Pill(std::string n, Prescription p, Age a,Replacements * r, Contraindications * c, int pills, Price price1):
    Medicine(n, p, a, r, c, price1), nr_of_pills(pills){};
    int get_nr_of_pills(){return nr_of_pills;};
    const std::string get_category(){return category; };
};

std::ostream &operator << (std::ostream& s, Pill &med);

#endif //APTEKA_PILL_H
