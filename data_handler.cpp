//
// Created by konga on 25.10.2020.
//

#include <algorithm>
#include "data_handler.h"
using namespace std;

void read_data(string file_name, MedicineList &m){
    ifstream in;
    in.open(file_name);

    if(!in){
        cout << "Błąd otwarcia bazy danych.";
        return;
    }
    string temp;
    while (getline(in, temp) && temp != "-") {
        string name_in = temp;
        string category_in;
        std::transform(name_in.begin(), name_in.end(), name_in.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        in >> category_in;

        if (category_in == "tabletki") {
            int nr_of_pills_in;
            int presctription_int_in;
            int payment_in;
            int age_min;
            int age_max;
            int zloty;
            int grosze;

            in >> nr_of_pills_in;
            in >> presctription_int_in;
            in >> payment_in;
            in >> age_min;
            in >> age_max;
            in >> zloty;
            in >> grosze;
            getline(in, temp);

            Replacements * r_in = new Replacements();
            auto ptr = r_in;
            string r;

            while(getline(in, r)){
                if(r == ".")
                    break;
                ptr->rep_name = r;
                ptr->next = new Replacements();
                ptr = ptr->next;
            }


            Contraindications * c_in = new Contraindications();
            auto ptr_c = c_in;
            string c;

            while(getline(in, c)){
                if(c == ".")
                    break;
                ptr_c->contraindcation = c;
                ptr_c->next = new Contraindications();
                ptr_c = ptr_c->next;

            }



            Prescription p;
            if(presctription_int_in)
                p.set_prescription_needed(true);
            else
                p.set_prescription_needed(false);
            p.set_payment(payment_in);

            Pill pill(name_in, p, Age(age_min, age_max), r_in, c_in, nr_of_pills_in, Price(zloty, grosze));
            m.add_pill(pill);

        }
        else if(category_in == "syrop"){
            double volume_in;
            int presctription_int_in;
            int payment_in;
            int age_min;
            int age_max;
            int zloty;
            int grosze;

            in >> volume_in;
            in >> presctription_int_in;
            in >> payment_in;
            in >> age_min;
            in >> age_max;
            in >> zloty;
            in >> grosze;

            getline(in, temp);

            Replacements * r_in = new Replacements();
            auto ptr = r_in;
            string r;

            while(getline(in, r)){
                if(r == ".")
                    break;

                ptr->rep_name = r;
                ptr->next = new Replacements();
                ptr = ptr->next;

            }


            Contraindications * c_in = new Contraindications();
            auto ptr_c = c_in;
            string c;

            while(getline(in, c)){
                if(c == ".")
                    break;

                ptr_c->contraindcation = c;
                ptr_c->next = new Contraindications();
                ptr_c = ptr_c->next;

            }


            Prescription p;
            if(presctription_int_in)
                p.set_prescription_needed(true);
            else
                p.set_prescription_needed(false);
            p.set_payment(payment_in);

            Siroup siroup(name_in, volume_in, p, Age(age_min, age_max), r_in, c_in, Price(zloty, grosze));
            m.add_siroup(siroup);

        }
        else if(category_in == "masc"){
            double weight;
            int presctription_int_in;
            int payment_in;
            int age_min;
            int age_max;
            int zloty;
            int grosze;

            in >> weight;
            in >> presctription_int_in;
            in >> payment_in;
            in >> age_min;
            in >> age_max;
            in >> zloty;
            in >> grosze;

            getline(in, temp);


            Replacements * r_in = new Replacements();
            auto ptr = r_in;
            string r;

            while(getline(in, r)){
                if(r == ".")
                    break;

                ptr->rep_name = r;
                ptr->next = new Replacements();
                ptr = ptr->next;

            }


            Contraindications * c_in = new Contraindications();
            auto ptr_c = c_in;
            string c;

            while(getline(in, c)){
                if(c == ".")
                    break;
                ptr_c->contraindcation = c;
                ptr_c->next = new Contraindications();
                ptr_c = ptr_c->next;

            }


            Prescription p;
            if(presctription_int_in)
                p.set_prescription_needed(true);
            else
                p.set_prescription_needed(false);
            p.set_payment(payment_in);

            Ointment ointment(name_in, weight, p, Age(age_min, age_max), r_in, c_in, Price(zloty, grosze));
            m.add_ointment(ointment);

        }
        else{
            int presctription_int_in;
            int payment_in;
            int age_min;
            int age_max;
            int zloty;
            int grosze;

            in >> presctription_int_in;
            in >> payment_in;
            in >> age_min;
            in >> age_max;
            in >> zloty;
            in >> grosze;

            getline(in, temp);


            Replacements * r_in = new Replacements();
            auto ptr = r_in;
            string r;

            while(getline(in, r)){
                if(r == ".")
                    break;
                ptr->rep_name = r;
                ptr->next = new Replacements();
                ptr = ptr->next;

            }


            Contraindications * c_in = new Contraindications();
            auto ptr_c = c_in;
            string c;

            while(getline(in, c)){
                if(c == ".")
                    break;
                ptr_c->contraindcation = c;
                ptr_c->next = new Contraindications();
                ptr_c = ptr_c->next;

            }

            Prescription p;
            if(presctription_int_in)
                p.set_prescription_needed(true);
            else
                p.set_prescription_needed(false);
            p.set_payment(payment_in);

            Medicine medicine(name_in, p, Age(age_min, age_max), r_in, c_in, Price(zloty, grosze));
            m.add_medicine(medicine);
        }

    }
}

void save_data(std::string file_name, MedicineList m){
    ofstream data;
    data.open(file_name);
    if(!data)
        return;

    auto ptr = m.get_pHead();
    while (ptr){
        if(ptr->get_med()){
            data << ptr->get_med()->get_name() << endl;
            data << ptr->get_med()->get_category() << endl;
            if(ptr->get_med()->get_prescription().get_prescription_needed())
                data << 1 << endl;
            else
                data << 0 << endl;
            data << ptr->get_med()->get_prescription().get_payment() << endl;

            data << ptr->get_med()->get_age().get_age_min() << endl;
            data << ptr->get_med()->get_age().get_age_max() << endl;

            data << ptr->get_med()->get_price().get_zloty() << endl;
            data << ptr->get_med()->get_price().get_grosze() << endl;

            auto r = ptr->get_med()->get_replacements();
            while(r){
                data << r->rep_name << endl;
                r = r->next;
            }
            data << "." << endl;

            auto c = ptr->get_med()->get_contraindications();
            while(c){
                data << c->contraindcation << endl;
                c = c->next;
            }
            data << "." << endl;
        }
        else if(ptr->get_pill()){
            data << ptr->get_pill()->get_name() << endl;
            data << ptr->get_pill()->get_category() << endl;
            data << ptr->get_pill()->get_nr_of_pills() << endl;

            if(ptr->get_pill()->get_prescription().get_prescription_needed())
                data << 1 << endl;
            else
                data << 0 << endl;
            data << ptr->get_pill()->get_prescription().get_payment() << endl;

            data << ptr->get_pill()->get_age().get_age_min() << endl;
            data << ptr->get_pill()->get_age().get_age_max() << endl;
            data << ptr->get_pill()->get_price().get_zloty() << endl;
            data << ptr->get_pill()->get_price().get_grosze() << endl;

            auto r = ptr->get_pill()->get_replacements();
            while(r){
                data << r->rep_name << endl;
                r = r->next;
            }
            data << "." << endl;

            auto c = ptr->get_pill()->get_contraindications();
            while(c){
                data << c->contraindcation << endl;
                c = c->next;
            }
            data << "." << endl;
        }

        else if(ptr->get_ointment()){

            data << ptr->get_ointment()->get_name() << endl;
            data << ptr->get_ointment()->get_category() << endl;
            data << ptr->get_ointment()->get_weight() << endl;

            if(ptr->get_ointment()->get_prescription().get_prescription_needed())
                data << 1 << endl;
            else
                data << 0 << endl;
            data << ptr->get_ointment()->get_prescription().get_payment() << endl;

            data << ptr->get_ointment()->get_age().get_age_min() << endl;
            data << ptr->get_ointment()->get_age().get_age_max() << endl;

            data << ptr->get_ointment()->get_price().get_zloty() << endl;
            data << ptr->get_ointment()->get_price().get_grosze() << endl;

            auto r = ptr->get_ointment()->get_replacements();
            while(r){
                data << r->rep_name << endl;
                r = r->next;
            }
            data << "." << endl;

            auto c = ptr->get_ointment()->get_contraindications();
            while(c){
                data << c->contraindcation << endl;
                c = c->next;
            }
            data << "." << endl;

        }

        else if(ptr->get_siroup()){

            data << ptr->get_siroup()->get_name() << endl;
            data << ptr->get_siroup()->get_category() << endl;
            data << ptr->get_siroup()->get_volume() << endl;

            if(ptr->get_siroup()->get_prescription().get_prescription_needed())
                data << 1 << endl;
            else
                data << 0 << endl;
            data << ptr->get_siroup()->get_prescription().get_payment() << endl;

            data << ptr->get_siroup()->get_age().get_age_min() << endl;
            data << ptr->get_siroup()->get_age().get_age_max() << endl;

            data << ptr->get_siroup()->get_price().get_zloty() << endl;
            data << ptr->get_siroup()->get_price().get_grosze() << endl;

            auto r = ptr->get_siroup()->get_replacements();
            while(r){
                data << r->rep_name << endl;
                r = r->next;
            }
            data << "." << endl;

            auto c = ptr->get_siroup()->get_contraindications();
            while(c){
                data << c->contraindcation << endl;
                c = c->next;
            }
            data << "." << endl;
        }


        ptr = ptr->get_ptr_next();
    }

    data << "-" << endl;
    data.close();
}

