#include <stdio.h>
#include <conio.h>
#define SIZE 5

void Menu(){
	printf("\n-----Queue Operations-----\n");
	printf("\n1. Enque\n2. Deque\n3. Display\n4. Exit\n\nEnter Your Choice: ");
}

int Enque(int queue[], int value, int *f, int *r){
	if ((*r == SIZE - 1 && *f == 0) || (*r + 1 == *f)) {
		printf("\nQueue is Overflow");
		return 0;
	}
	if (*f == -1) {
		*f = *r = 0;
	} else if (*r == SIZE - 1 && *f != 0) {
		*r = 0;
	} else {
		(*r)++;
	}
	queue[*r] = value;
	return 1;
}

int Deque(int queue[], int *f, int *r){
	int data;
	if (*f == -1) {
		printf("\nQueue is Underflow!");
		return -9999;
	}
	data = queue[*f];
	queue[*f] = 0;

	if (*f == *r) {
		*f = *r = -1;
	} else if (*f == SIZE - 1) {
		*f = 0;
	} else {
		(*f)++;
	}
	return data;
}

void Display(int queue[], int f, int r){
	int i=f;
	if (f == -1) {
		printf("\nQueue is Empty");
		return;
	}

	printf("---Queue Elements---\n");
	while (1) {
		printf("%d ", queue[i]);
		if (i == r)break;
		i++;
		if (i == SIZE)
			i = 0;
	}
}

void main(){
	int queue[SIZE], front = -1, rear = -1;
	int ch, value;

	do {
		clrscr();
		Menu();
		scanf("%d", &ch);
		switch (ch) {
			case 1:
				printf("Enter Element to insert: ");
				scanf("%d", &value);
				if (Enque(queue, value, &front, &rear) == 1)
					printf("\nData Inserted Successfully");
				break;

			case 2:
				value = Deque(queue, &front, &rear);
				if (value != -9999)
					printf("\nDeleted element is: %d", value);
				break;

			case 3:
				Display(queue, front, rear);
				break;

			case 4:
				clrscr();
				gotoxy(35, 12);
				printf("Bye Bye!");
				break;

			default:
				printf("\nInvalid Choice!");
		}
		getch();
	} while (ch != 4);

	getch();
}
