//
// Created by kgawelek on 21.10.2020.
//

#ifndef APTEKA_OINTMENT_H
#define APTEKA_OINTMENT_H
#include "Medicine.h"

class Ointment: public Medicine {
public:
    const std::string category = "masc";
    double weight;
    Ointment(std::string n, double w, Prescription p, Age a,Replacements * r, Contraindications * c): Medicine(n, p, a, r, c), weight(w){};
};

std::ostream &operator << (std::ostream& s, const Ointment &med);


#endif //APTEKA_OINTMENT_H
