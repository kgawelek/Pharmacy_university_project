//
// Created by kgawelek on 20.10.2020.
//

#ifndef APTEKA_AGE_H
#define APTEKA_AGE_H


class Age {

    int age_min = 0;
    int age_max = 0;
public:
    Age() = default;
    Age(int min, int max): age_min(min), age_max(max){};
    int get_age_min() const {return age_min;};
    int get_age_max() const {return age_max;};

};


#endif //APTEKA_AGE_H
