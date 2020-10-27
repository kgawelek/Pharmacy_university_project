#include <iostream>
#include <vector>

#include "Medicine.h"
#include "Pill.h"
#include "data_handler.h"
#include "cli_handler.h"

using namespace std;
int main() {

string data = "data.txt";
MedicineList m;

read_data(data, m);

interface(m);

save_data(data, m);
    return 0;
}
