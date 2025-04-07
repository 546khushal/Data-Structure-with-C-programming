#include<stdio.h>
#include<conio.h>
#define SIZE 5

void Menu(){
	printf("----Double Ended Queue Operations----\n");
	printf("1. Insert Front\n");
	printf("2. Insert Rear\n");
	printf("3. Delete Front\n");
	printf("4. Delete Rear\n");
	printf("5. Display\n");
	printf("6. Exit\n");
	printf("\nEnter Your Choice: ");
}

void InsertFront(int Queue[], int value, int *front, int *rear){
	if((*front == (*rear + 1) % SIZE)) {
		printf("Queue is Overflow\n");
	}
	else{
		if(*front == -1){
			*front = *rear = 0;
		}
		else{
			*front = (*front - 1 + SIZE) % SIZE;
		}
		Queue[*front] = value;
		printf("Inserted at front: %d\n", value);
	}
}

void InsertRear(int Queue[], int value, int *front, int *rear){
	if((*front == (*rear + 1) % SIZE)) {
		printf("Queue is Overflow\n");
	}
	else{
		if(*rear == -1){
			*front = *rear = 0;
		}
		else{
			*rear = (*rear + 1) % SIZE;
		}
		Queue[*rear] = value;
		printf("Inserted at rear: %d\n", value);
	}
}

int DeleteFront(int Queue[], int *front, int *rear){
	int value;
	if(*front == -1){
		printf("Queue is Underflow\n");
		return -1;
	}
	value = Queue[*front];
	if(*front == *rear){
		*front = *rear = -1;
	}
	else{
		*front = (*front + 1) % SIZE;
	}
	return value;
}

int DeleteRear(int Queue[], int *front, int *rear){
	int value;
	if(*rear == -1){
		printf("Queue is Underflow\n");
		return -1;
	}
	value = Queue[*rear];
	if(*front == *rear){
		*front = *rear = -1;
	}
	else{
		*rear = (*rear - 1 + SIZE) % SIZE;
	}
	return value;
}

void Display(int Queue[], int front, int rear){
	int i;
	if(front == -1){
		printf("\nQueue is Empty\n");
		return;
	}
	printf("--Queue Elements--\n");
	i = front;
	do{
		printf("%d ", Queue[i]);
		i = (i + 1) % SIZE;
	}while(i != (rear + 1) % SIZE);
	printf("\n");
}

void main(){
	int ch, value, Queue[SIZE];
	int front = -1, rear = -1;
	do{
		clrscr();
		Menu();
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("Enter Value: ");
				scanf("%d", &value);
				InsertFront(Queue, value, &front, &rear);
				break;
			case 2:
				printf("Enter Value: ");
				scanf("%d", &value);
				InsertRear(Queue, value, &front, &rear);
				break;
			case 3:
				value = DeleteFront(Queue, &front, &rear);
				if(value != -1)
					printf("Deleted from Front: %d\n", value);
				break;
			case 4:
				value = DeleteRear(Queue, &front, &rear);
				if(value != -1)
					printf("Deleted from Rear: %d\n", value);
				break;
			case 5:
				Display(Queue, front, rear);
				break;
			case 6:
				clrscr();
				gotoxy(35,12);
				printf("Bye Bye\n");
				break;
			default:
				printf("Invalid Choice\n");
		}
		getch();
	}while(ch != 6);
}
