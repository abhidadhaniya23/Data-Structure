#include<iostream>
using namespace std;

void getData();
void displayQueue();

int queue[5] = {};
int front = -1, rear = -1, maxSize = 5;

void displayQueue() {
    cout << endl;
    cout << "Now, Front is : " << queue[front] << ", Rear is : " << queue[rear] << endl;
}

class retult {
public:
    void queueOperation(bool success, string operation) {
        if (success) {
            cout << "Element " << operation << " successful..." << endl;
        }
        else {
            cout << "Oops! " << operation << " Failed..." << endl;
        }
    }
}operationResult;

class queueDatastructure {
    int dataElement;
public:
    bool isFull() {
        if (rear == maxSize - 1) {
            return true;
        }
        else {
            return false;
        }
    }
    bool isEmpty() {
        if (front > rear || (front == -1 && rear == -1)) {
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue() {    // insertion
        // [ ] check the conditions for if some spaces are available at beginning then push that data to their (circular queue)
        if (isFull()) {
            if (front != -1 && rear == maxSize - 1) {
                rear = -1;
                cout << "Enter element to enqueue : ";
                cin >> dataElement;
                if (isEmpty()) {
                    rear++;
                    front++;
                }
                else {
                    rear++;
                }
                queue[rear] = dataElement;
            }
            else {
                cout << "Queue is full..." << endl;
                operationResult.queueOperation(false, "Enqueue");
            }
        }
        else {
            if (isEmpty()) {
                front = -1;
                rear = -1;
            }
            cout << "Enter element to enqueue : ";
            cin >> dataElement;
            if (isEmpty()) {
                rear++;
                front++;
            }
            else {
                rear++;
            }
            queue[rear] = dataElement;
        }
    }
    void dequeue() {    // deletion
        if (isEmpty()) {
            cout << "Queue is empty..." << endl;
            operationResult.queueOperation(false, "Dequeue");
        }
        else {
            front++;
        }
    }

}queueOperation;

int main() {

    int choice;
    system("cls");

    cout << "=> The max size of queue is 5." << endl;

    do {
        if (front == -1 && rear == -1) {
            cout << "Your queue is empty...!";
        }
        else {
            displayQueue();
        }
        getData();
        cin >> choice;
        switch (choice) {
        case 1:
            queueOperation.enqueue();
            break;
        case 2:
            queueOperation.dequeue();
            break;
        case 3:
            exit(0);
            break;

        default:
            cout << "Invalid choice for operation...!" << endl;
            break;
        }
    } while (true);

    return 0;
}

void getData() {
    cout << endl;
    cout << "----------------" << endl;
    cout << "1. Enqueue()" << endl;
    cout << "2. Dequeue()" << endl;
    cout << "3. Exit" << endl;
    cout << "----------------" << endl;
    cout << endl;
    cout << "What you want to do ? : ";
}