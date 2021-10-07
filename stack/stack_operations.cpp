#include <iostream>
#include "../Build-In-Classes/class.hpp"
using namespace std;
#define max 15

int stack[15] = { 20,4,12,89,9,23,52,54,23,90,76,87,23,45 }, top = 13;

class result {
public:
    void resultOfOperation(bool success, string operation) {
        if (success) {
            cout << "Data " << operation << " successfully...!" << endl;
        }
        else {
            cout << "Oops! Data " << operation << " failed...!" << endl;
        }
    }
}operationResult;

class operations {
public:
    int pop() {
        if (top == -1) {
            cout << "Stack underflow...!" << endl;
            return 0;
        }
        else {
            stack[top] = 0;
            top--;
            return 1;
        }
    }
    int push() {
        if (top == max - 1) {
            cout << "Stack overflow...!" << endl;
            return 0;
        }
        else {
            int data;
            cout << "Enter element to push in stack : ";
            cin >> data;
            top++;
            stack[top] = data;
            return 1;
        }
    }
    // another peep() function for display elements but here i'm using build-in-class functions, created in another file by me.
}operation;

int main() {
    system("cls");
    arrayMethod.displayArr(stack, top + 1);

    int choice;
    do {

        cout << "------------------" << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Deletion" << endl;
        cout << "3. Exit" << endl;
        cout << "------------------" << endl;
        cout << "What you want to do ? : ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (operation.push()) {
                operationResult.resultOfOperation(true, "inserted");
                arrayMethod.displayArr(stack, top + 1);
            }
            else {
                operationResult.resultOfOperation(false, "inserted");
                arrayMethod.displayArr(stack, top + 1);
            }
            break;
        case 2:
            if (operation.pop()) {
                operationResult.resultOfOperation(true, "deleted");
                arrayMethod.displayArr(stack, top + 1);
            }
            else {
                operationResult.resultOfOperation(false, "deleted");
                arrayMethod.displayArr(stack, top + 1);
            }
            break;
        case 3:
            exit(0);
            break;

        default:
            break;
        }

    } while (true);

    return 0;
}