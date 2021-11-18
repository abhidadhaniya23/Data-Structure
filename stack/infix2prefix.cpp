#include<iostream>
#include<array>
using namespace std;

// rules for operator pop and push from stack
    // -

// [!] steps to perform for infix to prefix
// [x] input infix expression from user
// [x] priority
// [ ] Associativity
// [ ] use switch case to check all char
// [x] push in stack
// [x] pop from stack

// variable decleration
char stack[30] = {};
char prefixExpression[30] = {};
char infix[30] = {};
int top = 0, MAX = 30;

class stack {
public:
    // Functions to check whether stack is underflow or overflow.
    int isFull() {
        if (top == MAX - 1) {
            // stack is overflow
            return 1;
        }
        else {
            // stack is not overflow
            return 0;
        }
    }
    int isEmpty() {
        if (top == -1) {
            // stack is underflow
            return 1;
        }
        else {
            // stack is not underflow
            return 0;
        }
    }
    // these functions are not necessary to use in this program but we declared.

    // Functions for operations on stack
    void push(char data) {
        top++;
        stack[top] = data;
    }
    void pop() {
        stack[top] = 0;
        top--;
    }

    // priority
    int priority(char data) {
        // => here all return returns priority order of operators
        if (data == '+' || data == '-') {
            return 0;
        }
        else if (data == '*' || data == '/') {
            return 1;
        }
        else {
            return 2;
        }
    }

    // Associativity

}stackFunction;

int main() {
    // taking infix expression from user
    cout << "Enter your infix expression : ";
    cin >> infix;
    int length_infix = sizeof(infix) / sizeof(infix[0]);
    top += length_infix - 1;

    for (int i = 0;i < length_infix;i++) {
        // operators to scan => (, ), +, -, ^, *, /

        switch (infix[i]) {
        case '(':
            stackFunction.push('(');
            break;
        case ')':
            do {
                stackFunction.push();
            } while ();
        case '+':

        default:
            break;
        }
    }


    return 0;
}