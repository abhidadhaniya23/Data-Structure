#include <iostream>
#include "../Build-In-Classes/class.hpp"
using namespace std;

// function definition
int insert();
int deletion();
int searching();

// [!] Array Operations

// [ ] randomize the array

// [x] Insertion
    // [x] insert at beginning
    // [x] insert at the end
    // [x] insert on given index
    // [x] insert after sorting array

// [x] Deletation
    // [x] delete at given index
    // [x] delete from beginning
    // [x] delete from the end

// [x] Sorting
    // [x] using bubble short algo.

// [x] reverse an array

// [x] Find max number of array
// [x] Find average of element in array
// [x] Seach element and return index
// [x] Return size of array

// [ ] Replace number at given index

// BUG: Fix all operations for possible possibilities (like if user enter higher index for insertion or other else...)


int arr[10] = { 5,22,7,4,8,1 }, number_of_elements = 6;
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

class sorting {
public:
    // swap elements using pointer
    void swap(int* num1, int* num2) {
        int temp;
        temp = *num1;
        *num1 = *num2;
        *num2 = temp;
    }
    void reverseArr() {
        for (int i = 0;i < number_of_elements / 2;i++) {
            swap(&arr[i], &arr[(number_of_elements - 1) - i]);
        }
    }
    void sort() {
        int index = 0;
        while (index < number_of_elements) {
            for (int i = 0;i < number_of_elements - 1;i++) {
                if (arr[i] > arr[i + 1]) {
                    swap(&arr[i], &arr[i + 1]);
                }
            }
            index++;
        }
    }
}sortArray;

class searching {
    int searchElement, data, position;
public:
    int linearSearch() {
        cout << "Enter element which you want to find : ";
        cin >> data;
        for (int i = 0;i < number_of_elements;i++) {
            if (arr[i] == data) {
                cout << "Element founded at position : " << i << endl;
                return 1;
            }
        }
    }
    int binarySearch() {
        // [ ] complete this binary search
        /*
        [*]
        - how to search element using binary search
            - 1. sort the array
            - 2. find mid element of array
            - 3. check whether searching element is less or greater than mid element
                - if < then find mid of those elements
                - if > then find mid of those elements
        */

        cout << "Enter element to search : ";
        cin >> searchElement;
        int midElement;

        if (number_of_elements != 0) {
            sortArray.sort();
            midElement = arr[number_of_elements / 2];
            while (midElement != searchElement) {
                if (midElement < searchElement) {

                }
                else {

                }
            }
            // for (int i = 0;i < number_of_elements / 2;i++) {
            //     if (arr[i] < midElement) {

            //     }
            // }
            return 1;
        }
        else {
            return 0;
        }
    }
}searchElement;

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
            cout << "Enter a number to insert : ";
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
            cout << "Enter a number to insert : ";
            cin >> insertElement;
            cout << "You want to insert " << insertElement << endl;
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

            // move till index
            moveElement.moveTillIndex(givenIndex);

            // insert element at index 0
            arr[givenIndex] = insertElement;
            number_of_elements++;

            return 1;
        }
    }
    int afterSorting() {
        if (number_of_elements == sizeOfArr) {
            cout << "Oops! Array is full" << endl;
            return 0;
        }
        else {
            // there are also a simple way to add element after sorting
            // 1. insert new element at the end or you can also add it at beginning.
            // 2. then sort the array.
            atTheEnd();
            sortArray.sort();

            return 1;
        }
    }
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
            else {
                cout << "You entered higher index than total numbers of element...!" << endl;
            }
            return 0;
        }
        else {
            cout << "Array is already empty!" << endl;
            return 0;
        }
    }
}deletionArray;

class basicOperation {
    int max = arr[0], avg = 0;
public:
    void maxNumber() {
        for (int i = 0;i < number_of_elements;i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        cout << "Maximum Number in array is : " << max << endl;
    }
    void averageOfElements() {
        for (int i = 0;i < number_of_elements;i++) {
            avg += arr[i];
        }
        avg = avg / number_of_elements;
        cout << "Average of elements in array : " << avg << endl;
    }
}arrayMethods;

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
        cout << "4. Reverse the array " << endl;
        cout << "5. Search a element " << endl;
        cout << "6. Find max number in array " << endl;
        cout << "7. Find average in array " << endl;
        cout << "8. Find size of array " << endl;
        cout << "9. Quit" << endl;
        cout << "-------------------------" << endl;
        cout << "What do you want to do ? : ";
        cin >> choice;

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
        case 3:
            if (number_of_elements > 0) {
                sortArray.sort();
                result.operationResult(true, "sorting");
            }
            else {
                cout << "The array is already empty...!" << endl;
                result.operationResult(false, "sorting");
            }
            break;
        case 4:
            if (number_of_elements > 0) {
                sortArray.reverseArr();
                result.operationResult(true, "reversed");
            }
            else {
                cout << "The array is already empty...!" << endl;
                result.operationResult(false, "reversed");
            }
            break;
        case 5:
            if (searching()) {
                result.operationResult(true, "founded");
            }
            else {
                result.operationResult(false, "find");
            }
            break;
        case 6:
            arrayMethods.maxNumber();
            break;
        case(7):
            arrayMethods.averageOfElements();
            break;
        case(8):
            cout << "Size of array is : " << number_of_elements << endl;
            break;
        case(9):
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
    cout << "3. insert at given index" << endl;
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
    case 4:
        if (insertionArray.afterSorting()) {
            return 0;
        }
        else {
            // displaying array after insertion...
            arrayMethod.displayArr(arr, number_of_elements);
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
int searching() {
    // displaying array before insertion
    arrayMethod.displayArr(arr, number_of_elements);

    int searchChoice;
    cout << "1. Search element using linear search" << endl;
    cout << "1. Search element using binary search" << endl;
    cout << endl;
    cout << "Which type of deletion do you want ? : ";
    cin >> searchChoice;

    switch (searchChoice) {
    case 1:
        if (searchElement.linearSearch()) {
            return 1;
        }
        else {
            return 0;
        }
        // displaying array after deeletion...
        arrayMethod.displayArr(arr, number_of_elements);
        break;
        /* case 2:
            if (searchElement.binarySearch()) {
                return 1;
            }
            else {
                return 0;
            }
            // displaying array after deletion...
            arrayMethod.displayArr(arr, number_of_elements);
            break; */

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
2. delete

3. sort array
    - create function for swap variables
    - use for loop for swap all elements in array

*/