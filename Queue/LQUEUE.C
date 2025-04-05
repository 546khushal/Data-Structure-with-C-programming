#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Queue{
	int data;
	struct Queue* next;
}Queue;

void Menu(){
	printf("\n-----Queue Operations-----\n");
	printf("\n1. Enque\n2. Deque\n3. Display\n4. Exit\n\nEnter Your Choice: ");
}
void Enque(int value,Queue **f,Queue **r){
	Queue *newNode;
	newNode = (Queue *)malloc(sizeof(Queue));
	if(!newNode){
		printf("Memory Allocation failed!");
		return;
	}
	newNode->data=value;
	newNode->next=NULL;
	if(*r==NULL){      //Queue is Empty
		*f = *r = newNode;
	}
	else{
		(*r)->next=newNode;
		*r=newNode;
	}
	printf("%d inserted into Queue\n",value);
}
void Deque(Queue **f,Queue **r){
	Queue *tmp;
	if(*f==NULL){
		printf("\nQueue is Underflow!");
		return;
	}
	tmp= *f;
	printf("%d removed from Queue\n",tmp->data);
	*f=(*f)->next;
	if(*f==NULL){
		*r=NULL;
	}
	free(tmp);
}
void Display(Queue *f){
	Queue *tmp;
	if(f==NULL){
		printf("\nQueue is Empty");
		return;
	}
	printf("Queue element: ");
	tmp=f;
	while(tmp!=NULL){
		printf("%d ",tmp->data);
		tmp=tmp->next;
	}
}


void main(){
	Queue *front=NULL,*rear=NULL;
	int ch,value;

	do{
		clrscr();
		Menu();
		scanf("%d",&ch);
		switch(ch){
			case 1:
			printf("Enter Element to insert: ");
			scanf("%d",&value);
			Enque(value,&front,&rear);
			break;
			case 2:
			Deque(&front,&rear);
			break;
			case 3:
			Display(front);
			break;
			case 4:
				clrscr();
				gotoxy(35,12);
				printf("Bye Bye!");
			break;
			default:
			printf("\nInvalid Choice!");
		}
		getch();
	}while(ch!=4);

	getch();
}