#include <stdio.h>
#include <conio.h>
#define SIZE 5

struct Element {
    int value;
    int priority;
};

struct Queue {
    struct Element data[SIZE];
    int size;
};

void Menu() {
    printf("\n--- Priority Queue ---\n");
    printf("1. Enqueue (Insert)\n2. Dequeue (Delete Highest Priority)\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
}

// Insert without ordering (simple insertion)
int Enqueue(struct Queue *q, int value, int priority) {
    if (q->size == SIZE) {
	printf("\nQueue Overflow!");
	return 0;
    }

    q->data[q->size].value = value;
    q->data[q->size].priority = priority;
    q->size++;
    return 1;
}

// Delete element with highest priority
int Dequeue(struct Queue *q) {
    int i,pos,highest;
    int deletedValue;
    if (q->size == 0) {
	printf("\nQueue Underflow!");
	return -1;
    }

    pos = 0;
    highest = q->data[0].priority;

    // Find highest priority element
    for (i = 1; i < q->size; i++) {
	if (q->data[i].priority > highest) {
	    highest = q->data[i].priority;
	    pos = i;
	}
    }

    deletedValue = q->data[pos].value;

    // Shift remaining elements
    for (i = pos; i < q->size - 1; i++) {
	q->data[i] = q->data[i + 1];
    }

    q->size--;
    return deletedValue;
}

void Display(struct Queue q) {
    int i;
    if (q.size == 0) {
	printf("\nQueue is Empty!");
	return;
    }

    printf("\n--- Queue Elements (With Priority) ---\n");
    for ( i = 0; i < q.size; i++) {
	printf("Value: %d | Priority: %d\n", q.data[i].value, q.data[i].priority);
    }
}

void main() {
    struct Queue q;
    int ch, val, pri;
    q.size=0;

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
                    printf("\nInserted Successfully!");
                break;

            case 2:
                val = Dequeue(&q);
                if (val != -1)
                    printf("\nDeleted element with highest priority: %d", val);
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
