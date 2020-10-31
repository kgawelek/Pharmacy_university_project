//
// Created by kgawelek on 21.10.2020.
//

#ifndef APTEKA_OINTMENT_H
#define APTEKA_OINTMENT_H
#include "Medicine.h"

class Ointment: public Medicine {

    const std::string category = "masc";
    double weight;
public:
    Ointment(std::string n, double w, Prescription p, Age a,Replacements * r, Contraindications * c, Price price1): Medicine(n, p, a, r, c, price1), weight(w){};
    const std::string get_category(){return category;};
    double get_weight(){return weight;};
};

std::ostream &operator << (std::ostream& s, Ointment &med);


#endif //APTEKA_OINTMENT_H
