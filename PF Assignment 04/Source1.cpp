/*

    Muhammad Umair 
    PF_Section_B12_A4_Section_2


This program manages a mall�s parking system with 5 floors and 8 slots on each floor. Each floor allows
specific vehicle types: Electric (Floor 1), Compact (Floors 2-3), and SUV (Floors 4-5). It loads parking
data from a file and lets users park vehicles, view the layout, or exit. When parking, it checks if the
floor matches the vehicle type and if the slot is free. If valid, it parks the car and saves updates when
exiting.


*/

#include <iostream>
#include <fstream>
using namespace std;

const int FLOORS = 5;
const int SLOTS = 8;
char slotLabels[SLOTS] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

bool isEqual(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

void loadParkingData(int parking[FLOORS][SLOTS]) {
    ifstream in("parking.txt");
    for (int i = 0; i < FLOORS; i++)
        for (int j = 0; j < SLOTS; j++)
            in >> parking[i][j];
    in.close();
}

void saveParkingData(int parking[FLOORS][SLOTS]) {
    ofstream out("parking.txt");
    for (int i = 0; i < FLOORS; i++) {
        for (int j = 0; j < SLOTS; j++) {
            out << parking[i][j];
            if (j < SLOTS - 1) out << " ";
        }
        out << "\n";
    }
    out.close();
}

void displayParking(int parking[FLOORS][SLOTS]) {
    cout << "\n          ";
    for (int i = 0; i < SLOTS; i++)
        cout << slotLabels[i] << "   ";
    cout << "\n";

    for (int i = 0; i < FLOORS; i++) {
        cout << "Floor " << i + 1 << "   ";
        for (int j = 0; j < SLOTS; j++) {
            cout << " " << parking[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "\nLegend: 0 = Empty, 1 = Occupied\n\n";
}


int getSlotIndex(char ch) {
    for (int i = 0; i < SLOTS; i++)
        if (slotLabels[i] == ch) return i;
    return -1;
}

bool isVehicleAllowed(const char* type, int floor) {
    if (floor == 1 && isEqual(type, "Electric"))
        return true;
    if ((floor == 2 || floor == 3) && isEqual(type, "Compact"))
        return true;
    if ((floor == 4 || floor == 5) && isEqual(type, "SUV"))
        return true;
    return false;
}

void parkVehicle(int parking[FLOORS][SLOTS]) {
    char type[20];
    char temp[20];
    int floor;
    char slotChar;

    cout << "\nEnter vehicle type (Electric/Compact/SUV): ";
    cin >> type;

    cout << "Enter desired slot (Floor 4 Slot C): ";
    cin >> temp >> floor >> temp >> slotChar;

    int slotIndex = getSlotIndex(slotChar);

    if (floor < 1 || floor > 5 || slotIndex == -1) {
        cout << "Invalid floor or slot.\n";
        return;
    }

    if (!isVehicleAllowed(type, floor)) {
        cout << " Vehicle type is not allowed on Floor " << floor << ".\n";
        return;
    }

    if (parking[floor - 1][slotIndex] == 1) {
        cout << "Slot is already occupied.\n";
        return;
    }

    parking[floor - 1][slotIndex] = 1;
    cout << "Vehicle parked successfully!\n";
}

int main() {
    int parking[FLOORS][SLOTS];
    loadParkingData(parking);

    int choice;
    cout << "Welcome to Mall Parking System\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Park a vehicle\n";
        cout << "2. Display parking layout\n";
        cout << "3. Save and exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            parkVehicle(parking);
        else if (choice == 2)
            displayParking(parking);
        else if (choice == 3) {
            cout << "Saving data.\n";
            saveParkingData(parking);
            cout << "Goodbye\n";
        }
        else
            cout << "Invalid choice.\n";

    } while (choice != 3);

    return 0;
}

