//
// Created by konga on 29.10.2020.
//

#include "Price.h"

bool Price::operator==(Price p) {
    if(this->zloty == p.get_zloty() && this->grosze == p.get_grosze())
        return true;
    else return false;

}

bool Price::operator>(class Price p) {
    if(this->zloty > p.zloty || (this->zloty == p.get_zloty() && this->grosze > p.get_grosze()))
        return true;
    else return false;
}

bool Price::operator<(class Price p) {
    if(this->zloty < p.get_zloty() || (this->zloty == p.get_zloty() && this->grosze < p.get_grosze()))
        return true;
    else return false;
}
