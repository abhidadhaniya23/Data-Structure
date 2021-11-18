#include<stdio.h>
#include<stdlib.h>

void insert(int data);
void display();

struct node {
    struct node* next;
    int data;
};

struct node* head = NULL;

int main() {

    insert(1);
    insert(2);
    insert(3);
    insert(4);

    display();

    return 0;
}

void insert(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        struct node* ptr;
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void display() {
    // printf("test");
    struct node* ptr = head;
    while (ptr != NULL) {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
}