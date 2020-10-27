//
// Created by konga on 24.10.2020.
//

#ifndef APTEKA_CONTRAINDICATIONS_H
#define APTEKA_CONTRAINDICATIONS_H

#include <iostream>

class Contraindications {
public:
    std::string contraindcation;
    Contraindications * next;
    Contraindications() = default;
    ~Contraindications()= default;
    Contraindications(std::string contr, Contraindications * ptr_next): contraindcation(contr), next(ptr_next){};
};


#endif //APTEKA_CONTRAINDICATIONS_H
