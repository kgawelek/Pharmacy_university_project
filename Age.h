//
// Created by kgawelek on 20.10.2020.
//

#ifndef APTEKA_AGE_H
#define APTEKA_AGE_H


class Age {
public:
    int age_min = 0;
    int age_max = 0;
    Age() = default;
    Age(int min, int max): age_min(min), age_max(max){};

};


#endif //APTEKA_AGE_H
