//
// Created by konga on 24.10.2020.
//

#include "Siroup.h"
using namespace std;
std::ostream &operator << (std::ostream& s, Siroup &med){

    cout << "Nazwa: " << med.get_name() << endl;
    cout << "Kategoria: " << med.get_category() << endl;
    cout << "Objetosc: " << med.get_volume() << endl;
    cout << "Na recepte?: ";

    if(med.get_prescription().get_prescription_needed())
        cout << "Tak" << endl;
    else
        cout << "Nie" << endl;

    cout << "Odplatnosc: " << med.get_prescription().get_payment() << "%" << endl;
    cout << "Zakres wieku: " << med.get_age().get_age_min() << "-" << med.get_age().get_age_max() << endl;

    cout << "Cena: " << med.get_price().get_zloty() << "." << med.get_price().get_grosze() << endl;

    auto pr = med.get_replacements();
    cout << "Zamienniki: ";
    while(pr){
        cout << pr->rep_name << " ";
        pr = pr->next;
    }
    cout << endl;
    cout << "Przeciwwskazania: ";

    auto pc = med.get_contraindications();
    while(pc){
        cout << pc->contraindcation << " ";
        pc = pc->next;
    }
    return cout << endl;

}