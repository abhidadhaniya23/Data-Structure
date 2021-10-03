#include <iostream>
#include "../Build-In-Classes/class.hpp"
using namespace std;

// function definition
int insert();
int deletion();

// [!] Array Operations

// [-] Insertion
    // [x] insert at beginning
    // [x] insert at the end
    // [x] insert on given index
    // [ ] insert after sorting array

// [-] Deletation
    // [-] delete at given index
    // [x] delete from beginning
    // [x] delete from the end

// [ ] Sorting
    // [ ] using bubble short algo.

// [ ] reverse an array

// [ ] Replace number at given index

// BUG: Fix all return 1 while operation fail...


int arr[15] = { 1,2,3 }, number_of_elements = 3;
int sizeOfArr = sizeof(arr) / sizeof(arr[0]);

class operation {
public:
    void operationResult(bool success, string operation) {
        if (success) {
            cout << "Element " << operation << " successful..." << endl;
        }
        else {
            cout << "Oops! " << operation << " Failed..." << endl;
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
    void moveTillIndexBackward(int index) {
        for (int i = index;i < number_of_elements;i++) {
            arr[i] = arr[i + 1];
        }
    }
    // it's useful for deletion...
    void moveBackward() {
        for (int i = 0;i < number_of_elements;i++) {
            arr[i] = arr[i + 1];
        }
    }
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
    // int afterSorting() {
    //     return 0;
        // [ ] create algo for sort an array
    // }


}insertionArray;

class deletion {
    int element, givenIndex;
public:
    friend class moveElements;
    int beginning() {
        if (number_of_elements > 0) {
            arr[0] = 0;
            moveElement.moveBackward();
            number_of_elements--;
            return 1;
        }
        else {
            cout << "Array is already empty!" << endl;
            return 0;
        }
    }
    int atTheEnd() {
        if (number_of_elements != 0) {
            arr[number_of_elements - 1] = 0;
            // no need to move array elements
            number_of_elements--;
            return 1;
        }
        else {
            cout << "Array is already empty!" << endl;
            return 0;
        }
    }
    int atGivenIndex() {
        if (number_of_elements > 0) {
            cout << "Enter index of element to delete : ";
            cin >> givenIndex;
            cout << "Given index is " << givenIndex << " For deletion" << endl;
            if (givenIndex < number_of_elements) {
                arr[givenIndex] = 0;
                moveElement.moveTillIndexBackward(givenIndex);
                number_of_elements--;
                return 1;
            }
            return 0;
        }
        else {
            if (number_of_elements != 0) {
                cout << "Array is already empty!" << endl;
            }
            else if (givenIndex < number_of_elements) {
                cout << "You entered higher index than total numbers of element...!" << endl;
            }
            return 0;
        }
    }
}deletionArray;

int main() {
    system("cls");
    do {
        // display array before showing operations on array...
        arrayMethod.displayArr(arr, number_of_elements);

        int choice;
        cout << "-------------------------" << endl;
        cout << "1. Insertion " << endl;
        cout << "2. Deletation " << endl;
        cout << "3. Sorting " << endl;
        cout << "4. Quit" << endl;
        cout << "-------------------------" << endl;
        cout << "What do you want to do ? : ";
        cin >> choice;

        // [ ] create switch case here
        switch (choice) {
        case 1:
            if (insert()) {
                result.operationResult(false, "insertion");
            }
            else {
                result.operationResult(true, "insertion");
            }
            break;
        case 2:
            if (deletion()) {
                result.operationResult(true, "deletion");
            }
            else {
                result.operationResult(false, "deletion");
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

    // types of insertion
    switch (insertChoice) {
    case 1:
        // [!] Also check conditions for these operations because they return something...
        // if you don't check conditions then it's by default return 1...
        if (insertionArray.beginning()) {
            return 0;
        }
        else {
            return 1;
        }
        // displaying array after insertion...
        arrayMethod.displayArr(arr, number_of_elements);
        break;
    case 2:
        if (insertionArray.atTheEnd()) {
            return 0;
        }
        else {
            return 1;
        }
        // displaying array after insertion...
        arrayMethod.displayArr(arr, number_of_elements);
        break;
    case 3:
        if (insertionArray.atGivenIndex()) {
            return 0;
        }
        else {
            return 1;
        }
        // displaying array after insertion...
        arrayMethod.displayArr(arr, number_of_elements);
        break;

    default:
        cout << "Invalid Choice" << endl;
        break;
    }
}
int deletion() {
    // displaying array before insertion
    arrayMethod.displayArr(arr, number_of_elements);

    int deleteChoice;
    cout << "1. Delete beginning element" << endl;
    cout << "2. Delete the end element" << endl;
    cout << "3. Delete given index element" << endl;
    cout << endl;
    cout << "Which type of deletion do you want ? : ";
    cin >> deleteChoice;

    // [ ] types of insertion
    switch (deleteChoice) {
    case 1:
        if (deletionArray.beginning()) {
            return 1;
        }
        else {
            return 0;
        }
        // displaying array after deeletion...
        arrayMethod.displayArr(arr, number_of_elements);
        break;
    case 2:
        if (deletionArray.atTheEnd()) {
            return 1;
        }
        else {
            return 0;
        }
        // displaying array after deletion...
        arrayMethod.displayArr(arr, number_of_elements);
        break;
    case 3:
        if (deletionArray.atGivenIndex()) {
            return 1;
        }
        else {
            return 0;
        }
        // displaying array after deletion...
        arrayMethod.displayArr(arr, number_of_elements);
        break;

    default:
        cout << "Invalid Choice" << endl;
        break;
    }
}

/*

// [!] steps to perform complete program...

// bubble shot and insertion algo. for sorting
// reverse an array

- remove duplicate elements
- linear search / binary search
- reverse an array (using replacing last index to first...)
- concentinate / merging array (with sorting)
- min and max element finding

first of all make an array in global declaration

- create a switch case for what user want to do ?

1. insert
    - insert at beginning
    - insert at the end
    - insert at given index
    - insert after sorting array
2.

*/