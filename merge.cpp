#include <iostream> 

using namespace std; 

void printArray (int array[], int size) {
    for(int i = 0; i < size; i++) {
        cout << array[i];
        if (size - i == 1) cout << endl;
        else cout << ", ";
    }
}

int* merge (int original[], int left[], int right[], int size) {
    int a = 0, b = 0, index = 0;
    for (int i = 0; i < size; i++) {
        if (index < size/2) 
            if (a > b) index = a; 
            else index = b;
        else index++;
        if (left[a] < right[b]) {
            original[index] = left[a]; 
            a++;
        }
        else {
            original[index] = right[b];
            b++;
        }
        if (index == size - 1) {
            if (a >= size/2) original[index] = right[b];
            else original[index] = left[a];
        }
    }
    return original;
}

int main () {

    int initial [] = {2, 1};
    int left [] = {2}; 
    int right [] = {1};

    printArray(merge(initial, left, right, 2),2);


    return 0;
}