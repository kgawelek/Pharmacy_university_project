#include <iostream>
#include <vector>

#include "Medicine.h"
#include "Pill.h"
#include "data_handler.h"
#include "cli_handler.h"

using namespace std;
int main() {
//    vector<string> c;
//    c.push_back("alertec");
//    Replacements * phead;
//
//
//    Replacements r("allegra", nullptr);
//    Prescription p(true, 100);
//    Medicine medicine;
//    medicine.name = "zyrtec";
//    cout << medicine << endl;
//    Pill pill;
//    pill.name = "zyrtec";
string data = "data.txt";
MedicineList m;

read_data(data, m);
//auto p = m.pHead;
//while(p){
//    if(p->pill)
//        cout << *(p->pill) << endl;
//    else if (p->siroup)
//        cout << *(p->siroup) << endl;
//    else if(p->ointment)
//        cout << *(p->ointment) << endl;
//    else if (p->med)
//        cout << *(p->med) << endl;
//
//    p = p->ptr_next;
//}


interface(m);

save_data(data, m);
    return 0;
}
