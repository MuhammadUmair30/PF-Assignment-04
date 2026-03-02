/*

    Muhammad Umair    

    PF_Section_B12_A4_Section_1

    This program lets the user enter numbers into a list and performs actions like adding values at the
    start or end, modifying elements, and finding the first, last, largest, and most repeated number
    (mode). It updates and displays the list after each change, and finally frees the used memory.


*/

#include <iostream>
using namespace std;

int* appendList(int* arr, int& size, int value) {
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; i++)
        newArr[i] = arr[i];
    newArr[size] = value;
    size++;
    delete[] arr;
    return newArr;
}

int* appendShiftList(int* arr, int& size, int value) {
    int* newArr = new int[size + 1];
    newArr[0] = value;
    for (int i = 0; i < size; i++)
        newArr[i + 1] = arr[i];
    size++;
    delete[] arr;
    return newArr;
}

int* modifyList(int* arr, int size, int pos, int newValue) {
    if (pos >= 0 && pos < size)
        arr[pos] = newValue;
    return arr;
}

int getFirst(int* arr) {
    return arr[0];
}

int getLast(int* arr, int size) {
    return arr[size - 1];
}

int getMaximum(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int getMinimum(int* arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

void getMode(int* arr, int size) {
    int maxCount = 1;
    int modes[100], modeCount = 0;
    bool hasMode = false;

    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++)
            if (arr[i] == arr[j])
                count++;

        bool alreadyExists = false;
        for (int k = 0; k < i; k++)
            if (arr[k] == arr[i])
                alreadyExists = true;

        if (!alreadyExists) {
            if (count > maxCount) {
                maxCount = count;
                modes[0] = arr[i];
                modeCount = 1;
                hasMode = true;
            }
            else if (count == maxCount && count > 1) {
                modes[modeCount++] = arr[i];
                hasMode = true;
            }
        }
    }

    if (!hasMode)
        cout << "The list has no mode" << endl;
    else {
        cout << "The list has the following mode: ";
        for (int i = 0; i < modeCount; i++)
            cout << modes[i] << (i < modeCount - 1 ? ", " : "");
        cout << endl;
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << (i < size - 1 ? ", " : "");
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter the " << size << " numbers: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    getMode(arr, size);

    arr = appendList(arr, size, 1);
    printArray(arr, size);

    arr = appendShiftList(arr, size, -1);
    printArray(arr, size);

    cout << " First element in the list is: " << getFirst(arr) << endl;

    cout << " Maximum number in the list is: " << getMaximum(arr, size) << endl;

    arr = appendShiftList(arr, size, 1);
    printArray(arr, size);

    getMode(arr, size);

    cout << " Last element in the list is: " << getLast(arr, size) << endl;

    arr = modifyList(arr, size, 1, -1);
    printArray(arr, size);

    getMode(arr, size);

    delete[] arr;
    return 0;
}
