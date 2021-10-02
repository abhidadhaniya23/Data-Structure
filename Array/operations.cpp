#include<iostream>
using namespace std;

class arrayMethods {
public:
    void displayArr(int arr[], int size) {
        for (int i = 0;i < size;i++) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    // creating objects for class
    arrayMethods arrMethod;

    int arr[] = { 20,43,90 };
    int sizeOfArr = sizeof(arr) / sizeof(arr[0]);
    cout << "Length : "<<sizeOfArr << endl;

    arrMethod.displayArr(arr, sizeOfArr);

    return 0;
}