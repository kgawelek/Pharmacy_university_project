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

class Medicine{
public:

    std::string name;
    const std::string category = "inne";
    Prescription  prescription;
    Age age;
    Replacements * replacements;
    Contraindications * contraindications;


    Medicine()= default;
    Medicine(std::string n, Prescription p, Age a,Replacements * r, Contraindications * c):
    name(n), prescription(p), age(a), replacements(r), contraindications(c) {};
    ~Medicine()=default;



//    std::string get_category();
//    void set_category(std::string c);


    bool operator==(Medicine &med);
    bool operator!=(Medicine &med);

    friend class ListElement;
};

std::ostream &operator << (std::ostream& s, const Medicine &med);

#endif //APTEKA_MEDICINE_H
