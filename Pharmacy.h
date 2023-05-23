#ifndef PHARMACY_H
#define PHARMACY_H
#include<iostream>
#include <map>
#include <string>

using namespace std;

class Pharmacy{
    private:
        map< string, int > medicine;

        bool checkMedicine (string name) {
            if (medicine.find (name) == medicine.end ()) {
                return false;
            }
            return true;
        }

    public:
        Pharmacy(){
            medicine.insert(make_pair("Paralmax Extra",144000));
            medicine.insert(make_pair("Mexcold Imex",84000));
            medicine.insert(make_pair("Glotadol Power",90000));
            medicine.insert(make_pair("Paracold 500 Effervescent",32000));
            medicine.insert(make_pair("Paracetamon Stada",45000));
        }

        void addMedicine(string name_medicine, int cost){ /*them loai thuoc moi*/
            medicine.insert(make_pair(name_medicine,cost));
        }

        void setMedicine(string elt_medicine, int new_cost){ /*sua gia tien cua thuoc*/
            if (checkMedicine(elt_medicine)) {
                medicine[elt_medicine] = new_cost;
            }
            else {
                medicine.insert(make_pair(elt_medicine, new_cost));
            }
        }

        int get_Medicine_cost(string name_medicine){
            if (checkMedicine(name_medicine)) {
                return this->medicine[name_medicine];
            }
            else {
                cout << "Không tồn tai: " << name_medicine << "!" <<endl;
            }
            return 0;
        };

        map<string, int> getAllMedicines () {
            return this->medicine;
        }

};

#endif