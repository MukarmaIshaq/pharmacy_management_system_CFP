#include <iostream>
#include <fstream>
#include "functions.h"
using namespace std;


void saveMedicineData(const Medicine medicines[], int numMedicines) {
    ofstream outFile("medicines.txt");

    if (outFile.is_open()) {
        for (int i = 0; i < numMedicines; i++) {
            outFile << medicines[i].name << endl;
            outFile << medicines[i].quantity << " " << medicines[i].price << endl;
        }

        outFile.close();
    }
}
int generatePrescriptionCode() {
    static int code = 1000;
    return code++;
}
void orderPrescription(Medicine medicines[], int& numMedicines, Prescription prescriptions[], int& numPrescriptions) {
    Prescription prescription;
    prescription.prescriptionCode = generatePrescriptionCode();

    cout << "Enter patient name= ";
    cin >> prescription.patientName;
    cout << "Enter medicine name= ";
    cin >> prescription.medName;


    bool medicineFound = false;
    for (int i = 0; i < numMedicines; i++) {
        if (medicines[i].name == prescription.medName && medicines[i].quantity > 0) {
            medicineFound = true;
            cout << "Medicine ordered successfully! Prescription Code: " << prescription.prescriptionCode << endl;
            medicines[i].quantity--;
            break;
        }
    }

    if (!medicineFound) {
        cout << "Medicine not available" << endl;
    }

    prescriptions[numPrescriptions++] = prescription;
}
void refillPrescription(Medicine medicines[], int& numMedicines, const Prescription prescriptions[], int numPrescriptions) {
    int code;
    cout << "Enter prescription code= ";
    cin >> code;

    bool prescriptionFound = false;
    for (int i = 0; i < numPrescriptions; i++) {
        if (prescriptions[i].prescriptionCode == code) {
            prescriptionFound = true;

            for (int j = 0; j < numMedicines; j++) {
                if (medicines[j].name == prescriptions[i].medName) {
                    medicines[j].quantity++;
                    cout << "Medicine refilled successfully!" << endl;
                    break;
                }
            }

            break;
        }
    }

    if (!prescriptionFound) {
        cout << "Prescription not found. Please check the code and try again." << endl;
    }
}
void addMedicineToStock(Medicine medicines[], int& numMedicines) {
    Medicine newMedicine;

    cout << "Enter medicine name= " << endl;
    cin >> newMedicine.name;
    cout << "Enter quantity " << endl;
    cin >> newMedicine.quantity;
    cout << "Enter price per unit= " << endl;
    cin >> newMedicine.price;

    medicines[numMedicines++] = newMedicine;
    saveMedicineData(medicines, numMedicines);

    cout << "Medicine added to stock successfully!" << endl;
}
void displayMedicineInventory() {
    ifstream inFile("medicines.txt");

    if (inFile.is_open()) {
        string line;
        cout << "Medicine Data:" << endl;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "can't open file" << endl;
    }
}