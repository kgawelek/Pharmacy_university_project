//
// Created by konga on 26.10.2020.
//
#include <algorithm>
#include "cli_handler.h"
using namespace std;
void interface(MedicineList &m){
 cout << "------------------------------------------------" << endl;

 cout << "Baza lekow apteki:\n\n" << endl;

 int choice = 0;
 while(choice != 5) {
     cout << "Wybierz numer opcji:\n" << endl;
     cout << "[1] Wyszukaj lek" << endl;
     cout << "[2] Dodaj lek do bazy" << endl;
     cout << "[3] Usun lek z bazy" << endl;
     cout << "[4] Znajdz zamiennik/zamienniki" << endl;
     cout << "[5] Zakoncz program" << endl;
     cin >> choice;

     if(choice == 1){
         string name;
         cout << "Podaj nazwe leku:" << endl;
         cin >> name;
         m.find_medicine(name);
     }
     else if (choice == 2){
         user_input(m);
     }
     else if(choice == 3){
         string name;
         cout << "Podaj nazwe leku:" << endl;
         cin >> name;
         m.remove_medicine(name);
     }
     else if(choice == 4){
         string name;
         cout << "Podaj nazwe leku:" << endl;
         cin >> name;
         m.find_replacements(name);
     }
 }
}

void user_input(MedicineList &m){
    string name;
    string category;
    int nr_of_pills;
    double volume_in;
    double weight;
    string presctription;
    int payment_in;
    int age_min;
    int age_max;
    cout << "Podaj nazwe leku:" << endl;
    cin >> name;
    cout << "Podaj kategorie: (tabletki, masc, syrop, inne)" << endl;
    cin >> category;
    std::transform(category.begin(), category.end(), category.begin(),
                   [](unsigned char c){ return std::tolower(c); });


    if(category == "tabletki"){
        cout << "Podaj ilosc tabletek w opakowaniu:" << endl;
        cin >> nr_of_pills;
    }
    else if(category == "masc"){
        cout << "Podaj wage:" << endl;
        cin >> weight;
    }
    else if(category == "syrop"){
        cout << "Podaj objetosc:" << endl;
        cin >> volume_in;
    }

    cout << "Czy lek jest na receptę? (wpisz tak / nie)" << endl;
    cin >> presctription;
    cout << "Czy jest refundowany? Podaj odpłatnosc leku:" << endl;
    cin >> payment_in;
    cout << "Podaj minimalny wiek (jeśli nie ma, wpisz 0): " << endl;
    cin >> age_min;
    cout << "Podaj maksymalny wiek (jeśli nie ma, wpisz 99):" << endl;
    cin >> age_max;

    Prescription p;
    if(presctription == "tak" || presctription == "TAK" || presctription == "Tak")
        p.prescription_needed = true;
    else
        p.prescription_needed = false;
    p.payment = payment_in;

    Replacements * r_in = new Replacements();
    auto ptr = r_in;
    string r;

    cout << "Podaj zamienniki (zatwierdzaj enterem, po ostatnim wpisz '-'" << endl;
    while(cin >> r){
        if(r == "-")
            break;
        ptr->rep_name = r;
        ptr->next = new Replacements();
        ptr = ptr->next;
    }

    Contraindications * c_in = new Contraindications();
    auto ptr_c = c_in;
    string c;

    cout << "Podaj przeciwwskazania (zatwierdzaj enterem, po ostatnim wpisz '-'" << endl;

    while(cin >> c){
        if(c == "-")
            break;
        ptr_c->contraindcation = c;
        ptr_c->next = new Contraindications();
        ptr_c = ptr_c->next;

    }

    if(category == "tabletki"){
        Pill pill(name, p, Age(age_min, age_max), r_in, c_in, nr_of_pills);
        m.add_pill(pill);
    }
    else if(category == "masc"){
        Ointment ointment(name, weight, p, Age(age_min, age_max), r_in, c_in);
        m.add_ointment(ointment);
    }
    else if(category == "syrop"){
        Siroup siroup(name, volume_in, p, Age(age_min, age_max), r_in, c_in);
        m.add_siroup(siroup);
    }
    else{
        Medicine medicine(name, p, Age(age_min, age_max), r_in, c_in);
        m.add_medicine(medicine);
    }

}