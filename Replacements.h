//
// Created by kgawelek on 20.10.2020.
//

#ifndef APTEKA_REPLACEMENTS_H
#define APTEKA_REPLACEMENTS_H
#include <iostream>

class Replacements {
public:
    std::string rep_name;
    Replacements * next;
    Replacements() = default;
    ~Replacements()= default;
    Replacements (std::string n, Replacements * ptr): rep_name(n), next(ptr){};
};


#endif //APTEKA_REPLACEMENTS_H
