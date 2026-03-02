/*

   Muhammad Umair     

   PF_Section_B12_A4_Section_3

   This C++ treasure hunt game lets the player enter multiple caves, each with a different number of
   rooms. The player marks each room as either empty (0) or containing treasure (1). The program stores
   this using a jagged array (dynamic 2D array), shows the treasure layout for each cave, counts the total
   treasures, and finally frees the used memory. It's a simple and fun way to learn dynamic memory and
   jagged arrays.


*/

#include <iostream>
using namespace std;

int main() {
    int numCaves;

    cout << "Enter number of caves: ";
    cin >> numCaves;

    int** caves = new int* [numCaves];
    int* numRooms = new int[numCaves];

    for (int i = 0; i < numCaves; i++) {
        cout << "\nCave " << i + 1 << " has how many rooms? ";
        cin >> numRooms[i];

        caves[i] = new int[numRooms[i]];

        cout << "Enter treasure info for Cave " << i + 1 << " rooms (0 = empty, 1 = treasure):\n";
        for (int j = 0; j < numRooms[i]; j++) {
            cout << "Room " << j + 1 << ": ";
            cin >> caves[i][j];
        }
    }

    cout << "\nTreasure Map:\n";
    for (int i = 0; i < numCaves; i++) {
        int treasureCount = 0;
        cout << "Cave " << i + 1 << ": { ";
        for (int j = 0; j < numRooms[i]; j++) {
            cout << caves[i][j] << " ";
            if (caves[i][j] == 1)
                treasureCount++;
        }
        cout << "}\n";
        cout << "Total treasures in Cave " << i + 1 << ": " << treasureCount << "\n";
    }

    for (int i = 0; i < numCaves; i++) {
        delete[] caves[i];
    }
    delete[] caves;
    delete[] numRooms;

    return 0;
}