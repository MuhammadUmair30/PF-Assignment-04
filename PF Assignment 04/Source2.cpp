/*

   Muhammad Umair      

   PF_Section_B12_A4_Section_3

   This program checks if water can reach the last plot of a farm from the first one. You tell it the
   size of the farm and where the rocks are (using 1s for rocks and 0s for open land). It then tries to
   find a way from the top-left corner to the bottom-right, only moving right or down. If it finds a clear
   path, it says �Irrigation is Possible.� If not, it says �Irrigation is Not Possible.


*/

#include <iostream>
using namespace std;

bool isPathExists(int** farm, int i, int j, int M, int N) {
    if (i >= M || j >= N || farm[i][j] == 1) return false;
    if (i == M - 1 && j == N - 1) return true;
    return isPathExists(farm, i, j + 1, M, N) || isPathExists(farm, i + 1, j, M, N);
}

int main() {
    int M, N;
    cout << "Enter number of rows: ";
    cin >> M;
    cout << "Enter number of columns: ";
    cin >> N;

    int** farm = new int* [M];
    for (int i = 0; i < M; i++) {
        farm[i] = new int[N];
    }

    cout << "Enter farm layout:\n";
    for (int i = 0; i < M; i++) {
        cout << endl;
        for (int j = 0; j < N; j++) {
            cin >> farm[i][j];
        }
    }
    cout << "\nFarm Layout:\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << farm[i][j] << " ";
        }
        cout << endl;
    }

    bool result = isPathExists(farm, 0, 0, M, N);

    cout << "\nResult: ";
    if (result)
        cout << "Irrigation is Possible\n";
    else
        cout << "Irrigation is Not Possible\n";

    for (int i = 0; i < M; i++) {
        delete[] farm[i];
    }
    delete[] farm;

    return 0;
}
