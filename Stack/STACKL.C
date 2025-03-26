#include<stdio.h>
#include<stdlib.h>

typedef struct Stack {
    int data;
    struct Stack* next;
} Stack;

void Menu() {
    printf("****Stack Operations****");
    printf("\n1.Push");
    printf("\n2.Pop");
    printf("\n3.Peep");
    printf("\n4.Display");
    printf("\n5.Exit");
    printf("\n\nEnter Your Choice: ");
}

void Push(Stack** top, int data) {
    Stack* node;
    node = malloc(sizeof(Stack));
    node->data = data;
    node->next = (*top);
    (*top) = node;
}

int Pop(Stack** top) {
    int data;
    Stack* tmp;
    tmp = *top;
    if ((*top) == NULL) {
        return -1; // Stack is empty
    }

    data = tmp->data;
    (*top) = (*top)->next;
    free(tmp);
    return data;
}

void Peep(Stack* top) {
    if (top == NULL) {
        printf("\nStack is empty\n");
        return;
    }
    printf("| %d |\n", top->data);
}

void Display(Stack* top) {
    if (top == NULL) {
        printf("\nStack is empty\n");
        return;
    }
    printf("\nStack contents:\n");
    while (top != NULL) {
        printf("| %d |  ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    int ch, value;
    Stack* top = NULL;
    do {
        // Uncomment the next line for Turbo C or old compilers
        // clrscr(); 

        Menu();
        scanf("%d", &ch);
        switch (ch) {
            case 1: // Push
                printf("\nEnter value to Add in Stack: ");
                scanf("%d", &value);
                Push(&top, value);
                printf("Data Pushed\n");
                break;
            case 2: // Pop
                value = Pop(&top);
                if (value == -1) {
                    printf("\nStack is Empty\n");
                } else {
                    printf("\nPopped Data is %d\n", value);
                }
                break;
            case 3: // Peep
                Peep(top);
                break;
            case 4: // Display
                Display(top);
                break;
            case 5: // Exit
                printf("Thank you\n");
                break;
            default:
                printf("Invalid choice\n");
        }
        // Uncomment for Turbo C or old compilers
        // getch(); 
    } while (ch != 5);

    return 0;
}
