#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
using namespace std;

int main(){
    cout << "         PHARMACY MANAGEMENT SYSTEM        " << endl;
    int y = 1;
    int ope;
    Medicine medicines[MAX_MEDICINES];
    int numMedicines = 0;

    do {
        cout << "Press 1 if you are a customer" << endl;
        cout << "Press 2 if you are a pharmacist" << endl;
        cin >> ope;

        if (ope == 1) {
            int x = 1;
            int op;

            Prescription prescriptions[MAX_PRESCRIPTIONS];
            int numPrescriptions = 0;
            do {
                cout << "Press 1 to place a new prescription" << endl;
                cout << "Press 2 to update previous prescription using prescription code" << endl;
                cout << "Press 3 to display medicines" << endl;
                cin >> op;

                if (op == 1) {
                    orderPrescription(medicines, numMedicines, prescriptions, numPrescriptions);
                } else if (op == 2) {
                    refillPrescription(medicines, numMedicines, prescriptions, numPrescriptions);
                } else if (op == 3) {
                    displayMedicineInventory();
                }
                else {
                    cout << "Invalid Input" << endl;
                }
                cout << "Enter 0 to exit" << endl;
                cin >> x;

            } while (x != 0);
        } else if (ope == 2) {
            string username;
            int password;
            cout << "Enter your username= ";
            cin >> username;
            cout << "Enter your password= ";
            cin >> password;
            int z = 1;
            int choice;

            if (username=="abc"&&password==123) {
                    cout << "Add medicines" << endl;
                        addMedicineToStock(medicines, numMedicines);
            } else {
                cout << "Authentication failed! Invalid username or password." << endl;
            }
        }

        cout << "Press 0 to exit" << endl;
        cin >> y;
    } while (y != 0);

    return 0;
}