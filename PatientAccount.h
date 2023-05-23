#ifndef PATIENTACCOUNT_H
#define PATIENTACCOUNT_H

#include "Pharmacy.h"
#include "Surgery.h"
#include<bits/stdc++.h>


using namespace std;

class PatientAccount {
    private :
        int days;
        int cost = 100;
        int full_cost;
    
    public :
        PatientAccount() {}
        PatientAccount(int days, int cost) {
            this->days = days;
            this->cost = cost;
        }

        void setDays(int days) { 
            this->days = days; 
        }

        void setCost(int cost) {
            this->cost = cost;
        }

        int getDays() { 
            return this->days; 
        }

        int getCost() { 
            return this->cost; 
        }

        void updatePharmacy (Pharmacy index, string name) {
            this->full_cost += index.get_Medicine_cost(name);
        }

        void updateSurgery (Surgery index, string name) {
            this->full_cost += index.get_Surgery_cost(name);
        }

        void updateTotalCost () {
            this->full_cost += this->days * this->cost;
        }

        string showTotalCost () {
            string cost = "Tong so tien phai tra:" + to_string(this->full_cost);
            return cost;
        }
};


#endif