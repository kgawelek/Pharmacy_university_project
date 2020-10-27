//
// Created by kgawelek on 20.10.2020.
//

#ifndef APTEKA_PILL_H
#define APTEKA_PILL_H
#include "Medicine.h"

class Pill: public Medicine {
public:
    int nr_of_pills;
    const std::string category = "tabletki";
    Pill() = default;
    Pill(std::string n, Prescription p, Age a,Replacements * r, Contraindications * c, int pills):
    Medicine(n, p, a, r, c), nr_of_pills(pills){};
};

std::ostream &operator << (std::ostream& s, const Pill &med);

#endif //APTEKA_PILL_H
