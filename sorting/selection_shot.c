#include<stdio.h>


int minElement();
void swap(int*, int*);

int arr[10] = { 5,22,7,4,8,1,3,15,12,34 };
int number_of_elements = sizeof(arr) / sizeof(arr[0]);

int main() {
    // display sorted array
    printf("\nArray before sorting : ");
    printf(" [ ");
    for (int i = 0;i < number_of_elements;i++) {
        printf("%d", arr[i]);
        if (i == number_of_elements - 1) {
            break;
        }
        printf(",");
    }
    printf(" ] \n\n");

    int element;

    // do {

    //     element++;
    // } while (element <= element);

    minElement();

    return 0;
}

// -------- Function Declaration ---------
void swap(int* num1, int* num2) {
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int minElement() {
    int minimum = arr[0];
    for (int i = 0;i < number_of_elements;i++) {
        if (minimum > arr[i]) {
            minimum = arr[i];
        }
    }
}