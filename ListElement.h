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


public:

    Medicine * med = nullptr;
    Pill * pill = nullptr;
    Ointment * ointment = nullptr;
    Siroup * siroup = nullptr;
    ListElement * ptr_next = nullptr;


    ListElement()=default;
    ListElement(Medicine *m): med(m){};
    ListElement(Medicine *m, ListElement * ptr): med(m), ptr_next(ptr){};
    ~ListElement()=default;



    friend class MedicineList;
};

#endif //APTEKA_LISTELEMENT_H
