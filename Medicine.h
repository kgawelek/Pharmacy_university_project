//
// Created by kgawelek on 17.10.2020.
//

#ifndef APTEKA_MEDICINE_H
#define APTEKA_MEDICINE_H
#include <iostream>
#include <vector>
#include <string>
#include "Prescription.h"
#include "Age.h"
#include "Replacements.h"
#include "Contraindications.h"
#include "Price.h"

class Medicine{

protected:
    std::string name;
    const std::string category = "inne";
    Prescription  prescription;
    Age age;
    Replacements * replacements = nullptr;
    Contraindications * contraindications = nullptr;
    Price price;
public:
    Medicine()= default;
    Medicine(std::string n, Prescription p, Age a,Replacements * r, Contraindications * c, Price price1):
    name(n), prescription(p), age(a), replacements(r), contraindications(c), price(price1) {};
    ~Medicine()=default;
    std::string  get_name(){return name;};
    const std::string get_category(){return category;};
    Prescription get_prescription(){return prescription;};
    Age get_age(){return age;};
    Replacements * get_replacements(){return replacements;};
    Contraindications * get_contraindications(){return contraindications;};
    Price get_price(){return price;};






    friend class ListElement;
};

std::ostream &operator << (std::ostream& s, Medicine &med);

#endif //APTEKA_MEDICINE_H
