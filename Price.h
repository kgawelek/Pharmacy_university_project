//
// Created by konga on 29.10.2020.
//

#ifndef APTEKA_PRICE_H
#define APTEKA_PRICE_H


class Price {

    int zloty;
    int grosze;
public:
    Price()= default;
    Price(int zl, int gr): zloty(zl), grosze(gr){};
    int get_zloty() const {return zloty;};
    int get_grosze(){return grosze;};
    bool operator==(Price p);
    bool operator>(Price p);
    bool operator<(Price p);

};


#endif //APTEKA_PRICE_H
