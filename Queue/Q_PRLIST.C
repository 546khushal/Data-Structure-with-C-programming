//Priority Queue with LinkedList use Globel Queue* front=NULL;
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	int priority;
	struct Node* next;
}Queue;

Queue* front=NULL;
void Menu(){
	printf("----Priority Queue Operations----\n");
	printf("1 .Enqueue\n");
	printf("2 .Dequeue\n");
	printf("3 .Display\n");
	printf("4. Exit\n");
	printf("\n\nEnter Your Choice: ");
}
void Enqueue(int value,int priority){
      Queue *tmp = (Queue *)malloc(sizeof(Queue));
      tmp->data = value;
      tmp->priority = priority;
      tmp->next = NULL;
      if(front==NULL || priority>front->priority){
	tmp->next=front;
	front=tmp;
      }
      else{
	Queue* current=front;
	while(current->next!=NULL && current->next->priority>=priority){
		current=current->next;
	}
	tmp->next=current->next;
	current->next=tmp;
      }
      printf("\nData Inserted Successfully");
}

int Dequeue(){
	Queue *tmp;
	int val;
	if(front==NULL){
		printf("\nQueue is Underflow");
		return -1;
	}
	tmp=front;
	val=tmp->data;
	front=front->next;
	free(tmp);

	return val;
}
void Display(){
	Queue *tmp;
	if(front==NULL){
		printf("\nQueue is Empty");
		return;
	}
	tmp=front;
	printf("Priority Queue is:\n");
	while(tmp!=NULL){
		printf("Value is: %d | Priority is: %d\n",tmp->data,tmp->priority);
		tmp=tmp->next;
	}
}
void main(){
	int ch,value,pr;
	do{
		clrscr();
		Menu();
		scanf("%d",&ch);
		switch(ch){
			case 1:
			printf("Enter Value: ");
			scanf("%d",&value);
			printf("Enter Priority");
			scanf("%d",&pr);
			Enqueue(value,pr);
			break;
			case 2:
			value=Dequeue();
			if(value!=-1){
				printf("Data Deleted with value: %d",value);
			}
			break;
			case 3:
			Display();
			break;
			case 4:
				clrscr();
				gotoxy(35,12);
				printf("Bye Bye");
			break;
			default:
			printf("Invalid Choice");
		}
	  getch();
	}while(ch!=4);
}       getch();