//
// Created by konga on 25.10.2020.
//

#include "data_handler.h"
using namespace std;

bool read_data(string file_name, MedicineList &m){
    ifstream in;
    in.open(file_name);

    if(!in){
        cout << "Błąd otwarcia bazy danych.";
        return false;
    }
    string temp;
    while (getline(in, temp) && temp != "-") {
        string name_in = temp;
        string category_in;

        in >> category_in;

        if (category_in == "tabletki") {
            int nr_of_pills_in;
            int presctription_int_in;
            int payment_in;
            int age_min;
            int age_max;

            in >> nr_of_pills_in;
            in >> presctription_int_in;
            in >> payment_in;
            in >> age_min;
            in >> age_max;


//            cout << nr_of_pills_in << endl;
//            cout << presctription_int_in << endl;
//            cout << payment_in << endl;
//            cout << age_min << endl;
//            cout << age_max << endl;

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
                p.prescription_needed = true;
            else
                p.prescription_needed = false;
            p.payment = payment_in;

            Pill pill(name_in, p, Age(age_min, age_max), r_in, c_in, nr_of_pills_in);
            m.add_pill(pill);

        }
        else if(category_in == "syrop"){
            double volume_in;
            int presctription_int_in;
            int payment_in;
            int age_min;
            int age_max;

            in >> volume_in;
            in >> presctription_int_in;
            in >> payment_in;
            in >> age_min;
            in >> age_max;



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
                p.prescription_needed = true;
            else
                p.prescription_needed = false;
            p.payment = payment_in;

            Siroup siroup(name_in, volume_in, p, Age(age_min, age_max), r_in, c_in);
            m.add_siroup(siroup);

        }
        else if(category_in == "masc"){
            double weight;
            int presctription_int_in;
            int payment_in;
            int age_min;
            int age_max;

            in >> weight;
            in >> presctription_int_in;
            in >> payment_in;
            in >> age_min;
            in >> age_max;



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
                p.prescription_needed = true;
            else
                p.prescription_needed = false;
            p.payment = payment_in;

            Ointment ointment(name_in, weight, p, Age(age_min, age_max), r_in, c_in);
            m.add_ointment(ointment);

        }
        else{
            int presctription_int_in;
            int payment_in;
            int age_min;
            int age_max;

            in >> presctription_int_in;
            in >> payment_in;
            in >> age_min;
            in >> age_max;



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
                p.prescription_needed = true;
            else
                p.prescription_needed = false;
            p.payment = payment_in;

            Medicine medicine(name_in, p, Age(age_min, age_max), r_in, c_in);
            m.add_medicine(medicine);
        }

    }
}

void save_data(std::string file_name, MedicineList m){
    ofstream data;
    data.open(file_name);
    if(!data)
        return;

    auto ptr = m.pHead;
    while (ptr){
        if(ptr->med){
            data << ptr->med->name << endl;
            data << ptr->med->category << endl;
            if(ptr->med->prescription.prescription_needed)
                data << 1 << endl;
            else
                data << 0 << endl;
            data << ptr->med->prescription.payment << endl;

            data << ptr->med->age.age_min << endl;
            data << ptr->med->age.age_max << endl;

            auto r = ptr->med->replacements;
            while(r){
                data << r->rep_name << endl;
                r = r->next;
            }
            data << "." << endl;

            auto c = ptr->med->contraindications;
            while(c){
                data << c->contraindcation << endl;
                c = c->next;
            }
            data << "." << endl;
        }
        else if(ptr->pill){
            data << ptr->pill->name << endl;
            data << ptr->pill->category << endl;
            data << ptr->pill->nr_of_pills << endl;

            if(ptr->pill->prescription.prescription_needed)
                data << 1 << endl;
            else
                data << 0 << endl;
            data << ptr->pill->prescription.payment << endl;

            data << ptr->pill->age.age_min << endl;
            data << ptr->pill->age.age_max << endl;

            auto r = ptr->pill->replacements;
            while(r){
                data << r->rep_name << endl;
                r = r->next;
            }
            data << "." << endl;

            auto c = ptr->pill->contraindications;
            while(c){
                data << c->contraindcation << endl;
                c = c->next;
            }
            data << "." << endl;
        }

        else if(ptr->ointment){

            data << ptr->ointment->name << endl;
            data << ptr->ointment->category << endl;
            data << ptr->ointment->weight << endl;

            if(ptr->ointment->prescription.prescription_needed)
                data << 1 << endl;
            else
                data << 0 << endl;
            data << ptr->ointment->prescription.payment << endl;

            data << ptr->ointment->age.age_min << endl;
            data << ptr->ointment->age.age_max << endl;

            auto r = ptr->ointment->replacements;
            while(r){
                data << r->rep_name << endl;
                r = r->next;
            }
            data << "." << endl;

            auto c = ptr->ointment->contraindications;
            while(c){
                data << c->contraindcation << endl;
                c = c->next;
            }
            data << "." << endl;

        }

        else if(ptr->siroup){

            data << ptr->siroup->name << endl;
            data << ptr->siroup->category << endl;
            data << ptr->siroup->volume << endl;
            if(ptr->siroup->prescription.prescription_needed)
                data << 1 << endl;
            else
                data << 0 << endl;
            data << ptr->siroup->prescription.payment << endl;

            data << ptr->siroup->age.age_min << endl;
            data << ptr->siroup->age.age_max << endl;

            auto r = ptr->siroup->replacements;
            while(r){
                data << r->rep_name << endl;
                r = r->next;
            }
            data << "." << endl;

            auto c = ptr->siroup->contraindications;
            while(c){
                data << c->contraindcation << endl;
                c = c->next;
            }
            data << "." << endl;
        }


        ptr = ptr->ptr_next;
    }

    data << "-" << endl;
    data.close();
}
