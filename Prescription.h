//
// Created by kgawelek on 20.10.2020.
//

#ifndef APTEKA_PRESCRIPTION_H
#define APTEKA_PRESCRIPTION_H


class Prescription {
public:
    bool prescription_needed = false;
    int payment = 100;
    Prescription() = default;
    Prescription(bool pn, int p): prescription_needed(pn), payment(p){};
};


#endif //APTEKA_PRESCRIPTION_H
