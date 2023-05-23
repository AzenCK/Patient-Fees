#include <bits/stdc++.h>
#include "PatientAccount.h"
#include "Pharmacy.h"
#include "Surgery.h"

using namespace std;

void showDetails (map<string, int> temp) {
    int count = 1;
    for (const auto& kv : temp) {
        cout << count <<" Tên: " << kv.first << " gia: " << kv.second << endl;
        count ++;
    }
}

string chooseObject (map<string, int> temp, int choose) {
    int count = 1;
    for (const auto& kv : temp) {
        if (choose == count) {
            return kv.first;
        }
        count ++;
    }
    return "Unknown";
}

int main() {
    Surgery services;
    Pharmacy medicines;
    PatientAccount account1;
    map<string, int> listMedicines = medicines.getAllMedicines();
    map<string, int> listServices = services.getAllServices();
    int choose_medicine, choose_service;
    showDetails(listMedicines);
    cout<<"Chon thuoc:";
    cin>>choose_medicine;
    showDetails(listServices);
    cout<<"Chon dich vu:";
    cin>>choose_service;
    account1.setCost(100);
    account1.setDays(10);
    account1.updatePharmacy(medicines, chooseObject(listMedicines, choose_medicine));
    account1.updateSurgery(services, chooseObject(listServices, choose_service));
    account1.updateTotalCost();
    cout<<account1.showTotalCost()<<endl;
    return 0;
}