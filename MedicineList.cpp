//
// Created by konga on 24.10.2020.
//
#include "MedicineList.h"
using namespace std;

void MedicineList::add_medicine(Medicine  &med){
    if(!pHead){
        pHead = new ListElement();
        pHead->med = new Medicine(med.get_name(), med.get_prescription(), med.get_age(), med.get_replacements(), med.get_contraindications(), med.get_price());
    }
    else{
        auto p = pHead;
        while (p->ptr_next)
            p = p->ptr_next;
        p->ptr_next = new ListElement();
        p->ptr_next->med = new Medicine(med.get_name(), med.get_prescription(), med.get_age(), med.get_replacements(), med.get_contraindications(), med.get_price());

    }
}

void MedicineList::add_pill(Pill &pill) {
    if(!pHead){
        pHead = new ListElement();
        pHead->pill = new Pill(pill.get_name(), pill.get_prescription(), pill.get_age(), pill.get_replacements(), pill.get_contraindications(), pill.get_nr_of_pills(), pill.get_price());
    }
    else{
        auto p = pHead;
        while (p->ptr_next)
            p = p->ptr_next;
        p->ptr_next = new ListElement();
        p->ptr_next->pill = new Pill(pill.get_name(), pill.get_prescription(), pill.get_age(), pill.get_replacements(), pill.get_contraindications(), pill.get_nr_of_pills(), pill.get_price());

    }
}

void MedicineList::add_ointment(Ointment & ointment) {
    if(!pHead){
        pHead = new ListElement();
        pHead->ointment = new Ointment(ointment.get_name(), ointment.get_weight(), ointment.get_prescription(), ointment.get_age(), ointment.get_replacements(), ointment.get_contraindications(), ointment.get_price());
    }
    else{
        auto p = pHead;
        while (p->ptr_next)
            p = p->ptr_next;
        p->ptr_next = new ListElement();
        p->ptr_next->ointment = new Ointment(ointment.get_name(), ointment.get_weight(), ointment.get_prescription(), ointment.get_age(), ointment.get_replacements(), ointment.get_contraindications(), ointment.get_price());

    }
}

void MedicineList::add_siroup(Siroup & siroup) {
    if(!pHead){
        pHead = new ListElement();
        pHead->siroup = new Siroup(siroup.get_name(), siroup.get_volume(), siroup.get_prescription(), siroup.get_age(), siroup.get_replacements(), siroup.get_contraindications(), siroup.get_price());
    }
    else{
        auto p = pHead;
        while (p->ptr_next)
            p = p->ptr_next;
        p->ptr_next = new ListElement();
        p->ptr_next->siroup = new Siroup(siroup.get_name(), siroup.get_volume(), siroup.get_prescription(), siroup.get_age(), siroup.get_replacements(), siroup.get_contraindications(), siroup.get_price());

    }
}

void MedicineList::find_medicine(std::string name) {
    bool no_match = true;
    auto p = this->pHead;
    while(p){

        if(p->med && p->med->get_name() == name) {
            cout << *(p->med) << endl;
            no_match = false;
        }
        else if(p->pill && p->pill->get_name() == name) {
            cout << *(p->pill) << endl;
            no_match = false;
        }
        else if(p->siroup && p->siroup->get_name() == name) {
            cout << *(p->siroup) << endl;
            no_match = false;
        }
        else if (p->ointment && p->ointment->get_name() == name) {
            cout << *(p->ointment) << endl;
            no_match = false;
        }
        p = p->ptr_next;
    }
    if(no_match)
        cout << "Nie znaleziono podanego leku!" << endl;
}

void MedicineList::find_replacements(std::string name) {
    auto p = this->pHead;
    bool no_match = true;

    while(p){
        if(p->med && p->med->get_name() == name){
            no_match = false;
            cout << "Zamienniki: ";
            auto r = p->med->get_replacements();
            while (r){
                cout << r->rep_name << " ";
                r = r->next;
            }
        }

        else if(p->pill && p->pill->get_name() == name) {
            no_match = false;
            cout << "Zamienniki: ";
            auto r = p->pill->get_replacements();
            while (r) {
                cout << r->rep_name << " ";
                r = r->next;
            }
        }
        else if(p->siroup && p->siroup->get_name() == name){
            no_match = false;
            cout << "Zamienniki: ";
            auto r = p->siroup->get_replacements();
            while (r){
                cout << r->rep_name << " ";
                r = r->next;
            }
        }

        else if (p->ointment && p->ointment->get_name() == name){
            no_match = false;
            cout << "Zamienniki: ";
            auto r = p->ointment->get_replacements();
            while (r){
                cout << r->rep_name << " ";
                r = r->next;
            }
        }
        cout << endl;

        p = p->ptr_next;
    }
    if(no_match)
        cout << "Nie znaleziono podanego leku!" << endl;
}

void MedicineList::remove_medicine(std::string name) {

    while((pHead->med && pHead->med->get_name() == name)
    || (pHead->pill && pHead->pill->get_name() == name)
    || (pHead->siroup && pHead->siroup->get_name() == name)
    || (pHead->ointment && pHead->ointment->get_name() == name)){
        auto new_head = this->pHead->ptr_next;
        delete pHead;
        pHead = new_head;
    }

    auto p = this->pHead;
    while(p && p->ptr_next){
        if((p->ptr_next->med && p->ptr_next->med->get_name() == name)
           || (p->ptr_next->pill && p->ptr_next->pill->get_name() == name)
           || (p->ptr_next->siroup && p->ptr_next->siroup->get_name() == name)
           || (p->ptr_next->ointment && p->ptr_next->ointment->get_name() == name)){
            auto next = p->ptr_next->ptr_next;
            delete p->ptr_next;
            p->ptr_next = next;
        }
    }

}
void MedicineList::find_cheaper(std::string name) {

    auto p = this->pHead;

    while(p){
        if(p->med && p->med->get_name() == name){

            auto r = p->med->get_replacements();
            while (r){

                auto p1 = this->pHead;
                while(p1){

                    if((p1->med && p1->med->get_name() == r->rep_name) && p1->med->get_price() < p->med->get_price()) {
                        cout << p1->med->get_name() << endl;
                    }

                    p1 = p1->ptr_next;
                }


                r = r->next;
            }
        }

        else if(p->pill && p->pill->get_name() == name) {

            auto r = p->pill->get_replacements();
            while (r) {

                auto p1 = this->pHead;
                while(p1){

                    if((p1->pill && p1->pill->get_name() == r->rep_name) && p1->pill->get_price() < p->pill->get_price()) {
                        cout << p1->pill->get_name() << endl;
                    }

                    p1 = p1->ptr_next;
                }

                r = r->next;
            }
        }
        else if(p->siroup && p->siroup->get_name() == name){

            auto r = p->siroup->get_replacements();
            while (r){

                auto p1 = this->pHead;
                while(p1){

                    if((p1->siroup && p1->siroup->get_name() == r->rep_name) && p1->siroup->get_price() < p->siroup->get_price()) {
                        cout << p1->siroup->get_name() << endl;
                    }

                    p1 = p1->ptr_next;
                }

                r = r->next;
            }
        }

        else if (p->ointment && p->ointment->get_name() == name){

            auto r = p->ointment->get_replacements();
            while (r){

                auto p1 = this->pHead;
                while(p1){

                    if((p1->ointment && p1->ointment->get_name() == r->rep_name) && p1->ointment->get_price() < p->ointment->get_price()) {
                        cout << p1->ointment->get_name() << endl;
                    }

                    p1 = p1->ptr_next;
                }

                r = r->next;
            }
        }

        p = p->ptr_next;
    }

}

void MedicineList::find_more_expensive(std::string name) {

    auto p = this->pHead;

    while(p){
        if(p->med && p->med->get_name() == name){

            auto r = p->med->get_replacements();
            while (r){

                auto p1 = this->pHead;
                while(p1){

                    if((p1->med && p1->med->get_name() == r->rep_name) && p1->med->get_price() < p->med->get_price()) {
                        cout << p1->med->get_name() << endl;
                    }

                    p1 = p1->ptr_next;
                }


                r = r->next;
            }
        }

        else if(p->pill && p->pill->get_name() == name) {

            auto r = p->pill->get_replacements();
            while (r) {

                auto p1 = this->pHead;
                while(p1){

                    if((p1->pill && p1->pill->get_name() == r->rep_name) && p1->pill->get_price() > p->pill->get_price()) {
                        cout << p1->pill->get_name() << endl;
                    }

                    p1 = p1->ptr_next;
                }

                r = r->next;
            }
        }
        else if(p->siroup && p->siroup->get_name() == name){

            auto r = p->siroup->get_replacements();
            while (r){

                auto p1 = this->pHead;
                while(p1){

                    if((p1->siroup && p1->siroup->get_name() == r->rep_name) && p1->siroup->get_price() > p->siroup->get_price()) {
                        cout << p1->siroup->get_name() << endl;
                    }

                    p1 = p1->ptr_next;
                }

                r = r->next;
            }
        }

        else if (p->ointment && p->ointment->get_name() == name){

            auto r = p->ointment->get_replacements();
            while (r){

                auto p1 = this->pHead;
                while(p1){

                    if((p1->ointment && p1->ointment->get_name() == r->rep_name) && p1->ointment->get_price() > p->ointment->get_price()) {
                        cout << p1->ointment->get_name() << endl;
                    }

                    p1 = p1->ptr_next;
                }

                r = r->next;
            }
        }

        p = p->ptr_next;
    }

}

void MedicineList::find_same_price(std::string name) {

    auto p = this->pHead;

    while(p){
        if(p->med && p->med->get_name() == name){

            auto r = p->med->get_replacements();
            while (r){

                auto p1 = this->pHead;
                while(p1){

                    if((p1->med && p1->med->get_name() == r->rep_name) && p1->med->get_price() < p->med->get_price()) {
                        cout << p1->med->get_name() << endl;
                    }

                    p1 = p1->ptr_next;
                }


                r = r->next;
            }
        }

        else if(p->pill && p->pill->get_name() == name) {

            auto r = p->pill->get_replacements();
            while (r) {

                auto p1 = this->pHead;
                while(p1){

                    if((p1->pill && p1->pill->get_name() == r->rep_name) && p1->pill->get_price() == p->pill->get_price()) {
                        cout << p1->pill->get_name() << endl;
                    }

                    p1 = p1->ptr_next;
                }

                r = r->next;
            }
        }
        else if(p->siroup && p->siroup->get_name() == name){

            auto r = p->siroup->get_replacements();
            while (r){

                auto p1 = this->pHead;
                while(p1){

                    if((p1->siroup && p1->siroup->get_name() == r->rep_name) && p1->siroup->get_price() == p->siroup->get_price()) {
                        cout << p1->siroup->get_name() << endl;
                    }

                    p1 = p1->ptr_next;
                }

                r = r->next;
            }
        }

        else if (p->ointment && p->ointment->get_name() == name){

            auto r = p->ointment->get_replacements();
            while (r){

                auto p1 = this->pHead;
                while(p1){

                    if((p1->ointment && p1->ointment->get_name() == r->rep_name) && p1->ointment->get_price() == p->ointment->get_price()) {
                        cout << p1->ointment->get_name() << endl;
                    }

                    p1 = p1->ptr_next;
                }

                r = r->next;
            }
        }

        p = p->ptr_next;
    }

}

