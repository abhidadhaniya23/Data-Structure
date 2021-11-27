#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>

char postfix[30];
int stack[30], top = -1;
int postfix_length;

void push(int data);
int pop();
int charToInt(char c);

int charToInt(char c) {
    return c - '0';
}
void push(int data) {
    top++;
    stack[top] = data;
}
int pop() {
    int popElement = stack[top];
    top--;
    return popElement;
}


int main() {
    printf("Enter postfix express : ");
    scanf("%s", &postfix);

    for (int i = 0;postfix[i] != '\0';i++) {
        postfix_length++;
    }
    for (int i = 0; i < postfix_length; i++) {
        if (isdigit(postfix[i])) {
            push(charToInt(postfix[i]));
        }
        else {
            int element;

            switch (postfix[i]) {
            case '+':
                element = pop() + pop();
                push(element);
                break;
            case '-':
                element = pop() - pop();
                push(element);
                break;
            case '*':
                element = pop() * pop();
                push(element);
                break;
            case '/':
                element = pop() / pop();
                push(element);
                break;
            default:
                break;
            }

        }
    }
    if (postfix[postfix_length - 1] == '-') {
        printf("Ans : -%d\n", stack[top]);
    }
    else {
        printf("Ans : %d\n", stack[top]);
    }
    // printf("Ans : %d\n", stack[top - 1]);
    return 0;
}