//
// Created by kgawelek on 20.10.2020.
//

#ifndef APTEKA_PRESCRIPTION_H
#define APTEKA_PRESCRIPTION_H


class Prescription {

    bool prescription_needed = false;
    int payment = 100;
public:
    Prescription() = default;
    Prescription(bool pn, int p): prescription_needed(pn), payment(p){};
    bool get_prescription_needed() const {return prescription_needed; };
    int get_payment() const {return payment;};
    void set_prescription_needed(bool b){this->prescription_needed = b;};
    void set_payment(int p){this->payment = p;};
};


#endif //APTEKA_PRESCRIPTION_H
