//
// Created by kgawelek on 17.10.2020.
//

#ifndef APTEKA_DATA_HANDLER_H
#define APTEKA_DATA_HANDLER_H
#include <iostream>
#include <fstream>
#include "MedicineList.h"


bool read_data(std::string file_name, MedicineList &m);
void save_data(std::string file_name, MedicineList m);

#endif //APTEKA_DATA_HANDLER_H
