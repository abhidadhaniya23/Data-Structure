#include <iostream>
#include "../Build-In-Classes/class.hpp"
using namespace std;

// function definition
int insert();

// [!] Array Operations

// [-] Insertion
    // [x] insert at beginning
    // [x] insert at the end
    // [x] insert on given index
    // [ ] insert after sorting array

// [-] Deletation
    // [ ] delete at given index
    // [ ] delete from beginning
    // [ ] delete from the end

// [ ] Sorting
    // [ ] using bubble short algo.

// [ ] Replace number at given index


// [/] Delete unnecessary code
// arrayMethod.displayArr(arr, sizeOfArr);


int arr[15] = { 1,2,3 }, number_of_elements = 3;
int sizeOfArr = sizeof(arr) / sizeof(arr[0]);

class operation {
public:
    void insertionResult(bool success, string operation) {
        if (success) {
            cout << "Element " << operation << " successful..." << endl;
        }
        else {
            cout << "Oops! " << operation << " Fail..." << endl;
        }
        cout << endl;
    }
}result;

class moveElements {
public:
    void moveForward() {
        for (int i = number_of_elements;i > 0;i--) {
            arr[i] = arr[i - 1];
        }
    }
    void moveTillIndex(int index) {
        for (int i = number_of_elements;i > index;i--) {
            arr[i] = arr[i - 1];
        }
    }
    // [/] if it's not necessary then delete it...
    // void moveBackward() {
    // }
}moveElement;

class insertion {
    int insertElement, givenIndex;
public:
    friend class moveElements;
    int beginning() {
        if (number_of_elements == sizeOfArr) {
            cout << "Oops! Array is full" << endl;
            return 0;
        }
        else {
            cout << "Enter a number to insert at beginning : ";
            cin >> insertElement;
            cout << "You want to insert " << insertElement << endl;

            // [x] algo to insert element at beginning
            // move 1 index forward all elements
            moveElement.moveForward();

            // insert element at index 0
            arr[0] = insertElement;
            number_of_elements++;

            return 1;
        }
    }
    int atTheEnd() {
        if (number_of_elements == sizeOfArr) {
            cout << "Oops! Array is full" << endl;
            return 0;
        }
        else {
            cout << "Enter a number to insert at the end : ";
            cin >> insertElement;
            cout << "You want to insert " << insertElement << endl;

            // [x] algo to insert element at the end
            // insert element at index 0
            arr[number_of_elements] = insertElement;
            number_of_elements++;

            return 1;
        }
    }
    int atGivenIndex() {
        if (number_of_elements == sizeOfArr) {
            cout << "Oops! Array is full" << endl;
            return 0;
        }
        else {
            cout << "Enter a number to insert : ";
            cin >> insertElement;
            cout << "Enter the index : ";
            cin >> givenIndex;
            cout << "You want to insert " << insertElement << " at index : " << givenIndex << endl;

            // [x] algo to insert element at the given index
            // move till index
            moveElement.moveTillIndex(givenIndex);

            // insert element at index 0
            arr[givenIndex] = insertElement;
            number_of_elements++;

            return 1;
        }
    }
    int afterSorting() {
        // [ ] create algo for sort an array
    }


}insertionArray;

int main() {
    do {
        // system("cls");
        int choice;
        cout << "-------------------------" << endl;
        cout << "1. Insertion " << endl;
        cout << "2. Deletation " << endl;
        cout << "3. Sorting " << endl;
        cout << "4. Quit" << endl;
        cout << "-------------------------" << endl;
        cout << "What do you want to do ? : ";
        cin >> choice;

        // [ ] make here switch case
        switch (choice) {
        case 1:
            if (insert()) {
                result.insertionResult(true, "insertion");
            }
            else {
                result.insertionResult(false, "insertion");
            }
            break;
        case 2:
            if (deletion()) {
                result.insertionResult(true, "insertion");
            }
            else {
                result.insertionResult(false, "insertion");
            }
            break;
        case 4:
            exit(0);
            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (true);

    return 0;
}

int insert() {
    // displaying array before insertion
    arrayMethod.displayArr(arr, number_of_elements);

    int insertChoice;
    cout << "1. Insert beginning" << endl;
    cout << "2. Insert at the end" << endl;
    cout << "3. insert on given index" << endl;
    cout << "4. insert after sorting array" << endl;
    cout << endl;
    cout << "Which type of insertion do you want ? : ";
    cin >> insertChoice;

    // [ ] types of insertion
    switch (insertChoice) {
    case 1:
        insertionArray.beginning();
        // displaying array after insertion...
        arrayMethod.displayArr(arr, number_of_elements);
        break;
    case 2:
        insertionArray.atTheEnd();
        // displaying array after insertion...
        arrayMethod.displayArr(arr, number_of_elements);
        break;
    case 3:
        insertionArray.atGivenIndex();
        // displaying array after insertion...
        arrayMethod.displayArr(arr, number_of_elements);
        break;

    default:
        cout << "Invalid Choice" << endl;
        break;
    }
}
int deletion(){
    // displaying array before insertion
    arrayMethod.displayArr(arr, number_of_elements);

    int insertChoice;
    cout << "1. Insert beginning" << endl;
    cout << "2. Insert at the end" << endl;
    cout << "3. insert on given index" << endl;
    cout << "4. insert after sorting array" << endl;
    cout << endl;
    cout << "Which type of insertion do you want ? : ";
    cin >> insertChoice;

    // [ ] types of insertion
    switch (insertChoice) {
    case 1:
        insertionArray.beginning();
        // displaying array after insertion...
        arrayMethod.displayArr(arr, number_of_elements);
        break;
    case 2:
        insertionArray.atTheEnd();
        // displaying array after insertion...
        arrayMethod.displayArr(arr, number_of_elements);
        break;
    case 3:
        insertionArray.atGivenIndex();
        // displaying array after insertion...
        arrayMethod.displayArr(arr, number_of_elements);
        break;

    default:
        cout << "Invalid Choice" << endl;
        break;
    }
}

/*

[!] steps to perform complete program...

first of all make an array in global declaration

- create a switch case for what user want to do ?

1. insert
    - insert at beginning
    - insert at the end
    - insert at given index
    - insert after sorting array
2.

*/