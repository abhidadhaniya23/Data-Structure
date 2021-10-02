#include <iostream>
using namespace std;

class arrayMethods {
public:
    void displayArr(int arr[], int size) {
        cout << endl;
        cout << "Now, Your array is : ";
        cout << " [ ";
        for (int i = 0;i < size;i++) {
            cout << arr[i];
            if (i == size - 1) {
                break;
            }
            cout << ",";
        }
        cout << " ] " << endl;
    }
}arrayMethod;