#include <iostream> 

using namespace std; 

void printArray (int array[], int size) {
    for(int i = 0; i < size; i++) cout << array[i] << ", ";
    cout << endl;    
}

void copyArray (int array[], int size) {
    int* copyOf = new int[size];
    for (int i = 0; i < size; i++) copyOf[i] = array[i];
    printArray(copyOf, size);
    delete copyOf;
    return;
}

int main () {

    int array [] = {1, 2, 3};

    copyArray(array, sizeof(array)/sizeof(array[0]));

    return 0;
}