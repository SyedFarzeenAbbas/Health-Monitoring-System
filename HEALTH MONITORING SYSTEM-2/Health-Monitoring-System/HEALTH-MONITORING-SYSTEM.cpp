#include <iostream>
using namespace std;

const int MAX_PATIENTS = 5;
int totalPatients = 0;

string names[MAX_PATIENTS];
int ages[MAX_PATIENTS];
float heights[MAX_PATIENTS];
float weights[MAX_PATIENTS];
float bmis[MAX_PATIENTS];
bool isHealthy[MAX_PATIENTS];

float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

void addPatient() {
    if (totalPatients < MAX_PATIENTS) {
        cout << "Enter name: ";
        cin >> names[totalPatients];

        cout << "Enter age: ";
        cin >> ages[totalPatients];

        cout << "Enter height (m): ";
        cin >> heights[totalPatients];

        cout << "Enter weight (kg): ";
        cin >> weights[totalPatients];


        bmis[totalPatients] = calculateBMI(weights[totalPatients], heights[totalPatients]);

        isHealthy[totalPatients] = (bmis[totalPatients] >= 18.5 && bmis[totalPatients] <= 24.9);

        totalPatients++;
        cout << "Patient added!\n";
    } else {
        cout << "Max patients reached.\n";
    }
}

void displayPatients() {
    if (totalPatients == 0) {
        cout << "No patients to show.\n";
        return;
    }

    for (int i = 0; i < totalPatients; i++) {
        cout << "\nName: " << names[i] << endl;
        cout << "Age: " << ages[i] << endl;
        cout << "Height: " << heights[i] << " m" << endl;
        cout << "Weight: " << weights[i] << " kg" << endl;
        cout << "BMI: " << bmis[i] << endl;
        cout << "Health Status: " << (isHealthy[i] ? "Healthy" : "Not Healthy") << endl;
    }
}

void showMenu() {
    int choice;
    do {
        cout << "\nMenu:\n1. Add Patient\n2. Show Patients\n3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            addPatient();
        } else if (choice == 2) {
            displayPatients();
        } else if (choice == 3) {
            cout << "Goodbye!\n";
        } else {
            cout << "Invalid option! Try again.\n";
        }
    } while (choice != 3);
}

int main() {
    showMenu();
    return 0;
}