//
// Created by kgawelek on 17.10.2020.
//

#ifndef APTEKA_MEDICINELIST_H
#define APTEKA_MEDICINELIST_H
#include "ListElement.h"


class MedicineList{


    ListElement * pHead = nullptr;

public:
    MedicineList()=default;
    MedicineList(ListElement * ptr): pHead(ptr){};
    ~MedicineList()=default;
    void add_medicine(Medicine &med); // dodaje do listy
    void add_pill(Pill &pill);
    void add_ointment(Ointment &ointment);
    void add_siroup(Siroup &siroup);
    void remove_medicine(std::string name); // usuwa z listy
    void find_medicine(std::string name); // znajduje lek i wypisuje jego parametry
    void find_replacements(std::string name); // wypisuje same zastępniki danego leku
    void find_cheaper(std::string name);
    void find_more_expensive(std::string name);
    void find_same_price(std::string name);
    ListElement * get_pHead(){return pHead;};
};


#endif //APTEKA_MEDICINELIST_H
