#include <iostream>

using namespace std;

void printArray(int array[], int size) {
    for(int i = 0; i < size; i++) {
        cout << array[i];
        if (i != size - 1)
            cout << ", ";
        else
            cout << endl;
    }
}

void merge(int original[], int left[], int right[], int size) {
    int a = 0, b = 0, index = 0;
    while (a < size / 2 && b < size - size / 2) {
        if (left[a] <= right[b]) {
            original[index++] = left[a++];
        } else {
            original[index++] = right[b++];
        }
    }
    while (a < size / 2) {
        original[index++] = left[a++];
    }
    while (b < size - size / 2) {
        original[index++] = right[b++];
    }
}

int* mergeSort (int array[], int size) {
    if (size == 1) return array; // base case
    else {
        int* leftArray = new int[size];
        int* rightArray = new int[size-size/2];
        for (int i = 0; i < size; i++) {
            if (i < size/2) leftArray[i] = array[i];
            else rightArray[i-size/2]= array[i]; 
        }
        mergeSort(leftArray, size / 2);
        mergeSort(rightArray, size - size / 2);
        merge(array, leftArray, rightArray, size);
        delete[] leftArray;
        delete[] rightArray;
        return array;
    }
}

int main () {
    int unsorted [] = {72, 680, 555, 13, 69, 888, 92, 2, 110, 1675};
    int size = sizeof(unsorted) / sizeof(unsorted[0]);
    int* sorted = mergeSort(unsorted, size);
    printArray(sorted, size);
    return 0; 
}