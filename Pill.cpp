//
// Created by kgawelek on 20.10.2020.
//

#include "Pill.h"
using namespace std;
std::ostream &operator << (std::ostream& s, const Pill &med){

    cout << "Nazwa: " << med.name << endl;
    cout << "Kategoria: " << med.category << endl;
    cout << "Ilosc tabletek w opakowaniu: " << med.nr_of_pills << endl;
    cout << "Na recepte?: ";

    if(med.prescription.prescription_needed)
        cout << "Tak" << endl;
    else
        cout << "Nie" << endl;

    cout << "Odplatnosc: " << med.prescription.payment << "%" << endl;
    cout << "Zakres wieku: " << med.age.age_min << "-" << med.age.age_max << endl;

    auto pr = med.replacements;
    cout << "Zamienniki: ";
    while(pr){
        cout << pr->rep_name << " ";
        pr = pr->next;
    }
    cout << endl;
    cout << "Przeciwwskazania: ";

    auto pc = med.contraindications;
    while(pc){
        cout << pc->contraindcation << " ";
        pc = pc->next;
    }
    return cout << endl;

}