#include<iostream>
using namespace std;

void getData();
void displayQueue();

// global declaration of queue
int queue[10] = { };
int front = -1, rear = -1, maxSize = 10;

// [x] enqueue() => to add an item to queue.
// [x] dequeue() => remove an item from the queue.
// [x] peek() => get the element at the front of the queue without removing it.
// [x] isFull() => check if the queue is full.
// [x] isEmpty() => check if the queue is empty.

// We don't have to print queue using for loop and other but here we have to see all thing, what is happining so that we can understand.
void displayQueue() {
    cout << endl;
    cout << "Now, Your Queue is : ";
    cout << " [ ";
    for (int i = front;i <= rear;i++) {
        cout << queue[i];
        if (i == rear) {
            break;
        }
        cout << ",";
    }
    cout << " ] " << endl;
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
        if (rear == maxSize) {
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
        if (isFull()) {
            cout << "Queue is full..." << endl;
            operationResult.queueOperation(false, "Enqueue");
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
    void peek() {
        if (!isEmpty()) {
            cout << "The front of queue is : " << queue[front] << endl;
        }
        else {
            cout << "Queue is empty..." << endl;
        }
    }

}queueOperation;

int main() {

    int choice;
    system("cls");

    cout << "=> The max size of queue is 15." << endl;

    do {
        displayQueue();
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
            queueOperation.peek();
            break;
        case 4:
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
    cout << "3. Peek()" << endl;
    cout << "4. Exit" << endl;
    cout << "----------------" << endl;
    cout << endl;
    cout << "What you want to do ? : ";
}