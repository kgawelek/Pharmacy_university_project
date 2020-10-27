//
// Created by konga on 24.10.2020.
//

#ifndef APTEKA_SIROUP_H
#define APTEKA_SIROUP_H

#include "Medicine.h"

class Siroup: public Medicine {
public:
    const std::string category = "syrop";
    double volume;
    Siroup(std::string n, double v, Prescription p, Age a,Replacements * r, Contraindications * c):
    Medicine(n, p, a, r, c), volume(v){};
};

std::ostream &operator << (std::ostream& s, const Siroup &med);
#endif //APTEKA_SIROUP_H
