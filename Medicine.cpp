//
// Created by kgawelek on 17.10.2020.
//

#include "Medicine.h"
using namespace std;



bool Medicine::operator==(Medicine &med) {
    if (this->name == med.name)
        return true;
    else
        return false;
}

bool Medicine::operator!=(Medicine &med) {
    if (this->name == med.name)
        return false;
    else
        return true;
}

std::ostream &operator << (std::ostream& s, const Medicine &med){

    cout << "Nazwa: " << med.name << endl;
    cout << "Kategoria: " << med.category << endl;
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
