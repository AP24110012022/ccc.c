#include <stdio.h>
#include <stdlib.h>

#define MAX 5   // change capacity here

int stack[MAX];
int top = -1;

// Function declarations
void push(int value);
int pop();
int peek();
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\n=== STACK SIMULATOR (Array) ===\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                printf("Popped value: %d\n", pop());
                break;

            case 3:
                printf("Top element: %d\n", peek());
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void push(int value) {
    if (top == MAX - 1) {
        printf("⚠ Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
    printf("%d pushed successfully.\n", value);
}

int pop() {
    if (top == -1) {
        printf("⚠ Stack Underflow! Stack is empty.\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (top == -1) {
        printf("⚠ Stack is empty.\n");
        return -1;
    }
    return stack[top];
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("\nCurrent Stack:\n");
    for (int i = top; i >= 0; i--) {
        printf("[ %d ]\n", stack[i]);
    }
    printf("-----TOP\n");
}
