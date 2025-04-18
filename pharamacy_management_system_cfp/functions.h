#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H
#include<iostream>
using namespace std;
#include<string>

const int MAX_MEDICINES = 100;
const int MAX_PRESCRIPTIONS = 100;
struct Medicine {
    string name;
    int quantity;
    float price;
};
struct Prescription {
    string patientName;
    string medName;
    int prescriptionCode;
};
void saveMedicineData(const Medicine medicines[], int numMedicines);
int generatePrescriptionCode();
void orderPrescription(Medicine medicines[], int& numMedicines, Prescription prescriptions[], int& numPrescriptions);
void refillPrescription(Medicine medicines[], int& numMedicines, const Prescription prescriptions[], int numPrescriptions);
void addMedicineToStock(Medicine medicines[], int& numMedicines);
void displayMedicineInventory();

#endif