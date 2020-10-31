//
// Created by kgawelek on 17.10.2020.
//

#ifndef APTEKA_LISTELEMENT_H
#define APTEKA_LISTELEMENT_H
#include "Medicine.h"
#include "Pill.h"
#include "Ointment.h"
#include "Siroup.h"

class ListElement{




    Medicine * med = nullptr;
    Pill * pill = nullptr;
    Ointment * ointment = nullptr;
    Siroup * siroup = nullptr;
    ListElement * ptr_next = nullptr;
public:

    ListElement()=default;
    ListElement(Medicine *m): med(m){};
    ListElement(Medicine *m, ListElement * ptr): med(m), ptr_next(ptr){};
    ~ListElement()=default;

    Medicine * get_med(){return med;};
    Pill * get_pill(){return pill; };
    Ointment * get_ointment(){return ointment;};
    Siroup * get_siroup(){return siroup;};
    ListElement * get_ptr_next(){return ptr_next;};

    friend class MedicineList;
};

#endif //APTEKA_LISTELEMENT_H
