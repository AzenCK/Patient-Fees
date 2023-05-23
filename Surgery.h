#ifndef SURGERY_H
#define SURGERY_H

#include<bits/stdc++.h>

using namespace std;


class Surgery {
    private:
        map<string, int> surgery;

        bool checkSurgery (string name) {
            if (surgery.find (name) == surgery.end ()) {
                return false;
            }
            return true;
        }

    public:
        Surgery () {
            this->surgery.insert(make_pair("Resection surgery", 150000000));
            this->surgery.insert(make_pair("Pancreatectomy", 200000000));
            this->surgery.insert(make_pair("Hepatectomy", 300000000));
            this->surgery.insert(make_pair("Appendectomy", 30000000));
            this->surgery.insert(make_pair("CABG", 200000000));
        }

        void addSurgery (string name, int value) {  
            this->surgery.insert(make_pair(name, value));
        }

        void updateSurgery (string name, int value) {
            if (checkSurgery(name)) {
                this->surgery[name] = value;
            }
            else {
                this->surgery.insert(make_pair(name, value));
            }

        }

        int get_Surgery_cost(string name) {
            if (checkSurgery(name)) {
                return this->surgery[name];
            }
            else {
                cout <<"Không tồn tại surgery: " << name << "!" << endl;
            }
            return 0;
        }

        pair<string, int> getSurgery (string name) {
            if (checkSurgery(name)) {
                return make_pair(name, this->surgery[name]);
            }

            else {
                cout <<"Không tồn tại surgery: " << name << "!" << endl;
            }
        }

        map<string, int> getAllServices () {
            return this->surgery;
        }
};

#endif