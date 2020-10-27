//
// Created by konga on 24.10.2020.
//
#include "MedicineList.h"
using namespace std;

void MedicineList::add_medicine(Medicine  &med){
    if(!pHead){
        pHead = new ListElement();
        pHead->med = new Medicine(med.name, med.prescription, med.age, med.replacements, med.contraindications);
    }
    else{
        auto p = pHead;
        while (p->ptr_next)
            p = p->ptr_next;
        p->ptr_next = new ListElement();
        p->ptr_next->med = new Medicine(med.name, med.prescription, med.age, med.replacements, med.contraindications);

    }
}

void MedicineList::add_pill(Pill &pill) {
    if(!pHead){
        pHead = new ListElement();
        pHead->pill = new Pill(pill.name, pill.prescription, pill.age, pill.replacements, pill.contraindications, pill.nr_of_pills);
    }
    else{
        auto p = pHead;
        while (p->ptr_next)
            p = p->ptr_next;
        p->ptr_next = new ListElement();
        p->ptr_next->pill = new Pill(pill.name, pill.prescription, pill.age, pill.replacements, pill.contraindications, pill.nr_of_pills);

    }
}

void MedicineList::add_ointment(Ointment & ointment) {
    if(!pHead){
        pHead = new ListElement();
        pHead->ointment = new Ointment(ointment.name, ointment.weight, ointment.prescription, ointment.age, ointment.replacements, ointment.contraindications);
    }
    else{
        auto p = pHead;
        while (p->ptr_next)
            p = p->ptr_next;
        p->ptr_next = new ListElement();
        p->ptr_next->ointment = new Ointment(ointment.name, ointment.weight, ointment.prescription, ointment.age, ointment.replacements, ointment.contraindications);

    }
}

void MedicineList::add_siroup(Siroup & siroup) {
    if(!pHead){
        pHead = new ListElement();
        pHead->siroup = new Siroup(siroup.name, siroup.volume, siroup.prescription, siroup.age, siroup.replacements, siroup.contraindications);
    }
    else{
        auto p = pHead;
        while (p->ptr_next)
            p = p->ptr_next;
        p->ptr_next = new ListElement();
        p->ptr_next->siroup = new Siroup(siroup.name, siroup.volume, siroup.prescription, siroup.age, siroup.replacements, siroup.contraindications);

    }
}

void MedicineList::find_medicine(std::string name) {
    bool no_match = true;
    auto p = this->pHead;
    while(p){

        if(p->med && p->med->name == name) {
            cout << *(p->med) << endl;
            no_match = false;
        }
        else if(p->pill && p->pill->name == name) {
            cout << *(p->pill) << endl;
            no_match = false;
        }
        else if(p->siroup && p->siroup->name == name) {
            cout << *(p->siroup) << endl;
            no_match = false;
        }
        else if (p->ointment && p->ointment->name == name) {
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
        if(p->med && p->med->name == name){
            no_match = false;
            cout << "Zamienniki: ";
            auto r = p->med->replacements;
            while (r){
                cout << r->rep_name << " ";
                r = r->next;
            }
        }

        else if(p->pill && p->pill->name == name) {
            no_match = false;
            cout << "Zamienniki: ";
            auto r = p->pill->replacements;
            while (r) {
                cout << r->rep_name << " ";
                r = r->next;
            }
        }
        else if(p->siroup && p->siroup->name == name){
            no_match = false;
            cout << "Zamienniki: ";
            auto r = p->siroup->replacements;
            while (r){
                cout << r->rep_name << " ";
                r = r->next;
            }
        }

        else if (p->ointment && p->ointment->name == name){
            no_match = false;
            cout << "Zamienniki: ";
            auto r = p->ointment->replacements;
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

    while((pHead->med && pHead->med->name == name)
    || (pHead->pill && pHead->pill->name == name)
    || (pHead->siroup && pHead->siroup->name == name)
    || (pHead->ointment && pHead->ointment->name == name)){
        auto new_head = this->pHead->ptr_next;
        delete pHead;
        pHead = new_head;
    }

    auto p = this->pHead;
    while(p->ptr_next){
        if((p->ptr_next->med && p->ptr_next->med->name == name)
           || (p->ptr_next->pill && p->ptr_next->pill->name == name)
           || (p->ptr_next->siroup && p->ptr_next->siroup->name == name)
           || (p->ptr_next->ointment && p->ptr_next->ointment->name == name)){
            auto next = p->ptr_next->ptr_next;
            delete p->ptr_next;
            p->ptr_next = next;
        }
    }

}
