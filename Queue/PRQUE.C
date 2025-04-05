#include <stdio.h>
#include <conio.h>
#define SIZE 5

struct Element {
    int value;
    int priority;
};

struct Queue {
    struct Element data[SIZE];
    int front;
    int rear;
};

void Menu() {
    printf("\n--- Priority Queue Using Struct ---\n");
    printf("1. Enqueue (Insert)\n2. Dequeue (Remove)\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
}

// Function to insert based on priority (highest priority first)
int Enqueue(struct Queue *q, int value, int priority) {
    int i;
    if (q->rear == SIZE - 1) {
	printf("\nQueue Overflow!");
	return 0;
    }

    if (q->front == -1) {
	q->front = q->rear = 0;
	q->data[0].value = value;
	q->data[0].priority = priority;
    } else {
	for (i = q->rear; i >= q->front && q->data[i].priority < priority; i--) {
	    q->data[i + 1] = q->data[i];
	}
	q->data[i + 1].value = value;
	q->data[i + 1].priority = priority;
	q->rear++;
    }
    return 1;
}

// Remove highest priority element
int Dequeue(struct Queue *q) {
    int val;
    if (q->front == -1) {
	printf("\nQueue Underflow!");
	return -1;
    }

    val = q->data[q->front].value;

    if (q->front == q->rear) {
	q->front = q->rear = -1;
    } else {
	q->front++;
    }

    return val;
}

void Display(struct Queue q) {
    int i;
    if (q.front == -1) {
	printf("\nQueue is Empty!");
	return;
    }

    printf("\n--- Queue Elements (With Priority) ---\n");
    for (i = q.front; i <= q.rear; i++) {
	printf("Value: %d | Priority: %d\n", q.data[i].value, q.data[i].priority);
    }
}

void main() {
    struct Queue q;
    int ch, val, pri;
    q.front = q.rear = -1;


    do {
	clrscr();
	Menu();
	scanf("%d", &ch);
	switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                printf("Enter priority: ");
                scanf("%d", &pri);
                if (Enqueue(&q, val, pri))
                    printf("\nInserted successfully!");
                break;

            case 2:
                val = Dequeue(&q);
                if (val != -1)
                    printf("\nDeleted element: %d", val);
                break;

            case 3:
                Display(q);
                break;

            case 4:
                clrscr();
                gotoxy(35, 12);
                printf("Bye Bye!");
                break;

            default:
                printf("\nInvalid choice!");
        }
        getch();
    } while (ch != 4);
    getch();
}
