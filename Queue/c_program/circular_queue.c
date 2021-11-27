#include<stdio.h>
#include<stdbool.h>

int isFull();
int isEmpty();
void enqueue(int data);
void dequeue();
void display();
void getData();

int queue[5];
int front = -1, rear = 0, maxSize = 5;

int isFull() {
    if ((rear == front + 1) || ((front == maxSize - 1) && (rear == 0))) {
        return 1;
    }
    else {
        return 0;
    }
}
int isEmpty() {
    if ((front < rear) || ((front == maxSize - 1) && (rear == 0))) {
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is already full.\n");
    }
    else if (front == maxSize - 1) {
        front = -1;
        front++;
        queue[front] = data;
    }
    else {
        front++;
        queue[front] = data;
    }
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    }
    else if (front == rear) {
        rear = 0;
    }
    else {
        queue[rear] = 0;
        rear++;
    }
}
void display() {
    // this is just for test purpose
    printf("Rear : %d , Front : %d\n", queue[rear], queue[front]);
}

void getData() {
    printf("\n");
    printf("----------------\n");
    printf("1. Enqueue()\n");
    printf("2. Dequeue()\n");
    printf("3. Display()\n");
    printf("4. Exit\n");
    printf("----------------\n");
}

int main() {
    int choice, data;
    getData();
    while (true) {
        printf("\nWhich operation do you want to perform ? : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter element to insert : ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice...!\n");
            break;
        }
    }
    return 0;
}