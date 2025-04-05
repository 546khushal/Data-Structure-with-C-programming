#include<stdio.h>
#include<conio.h>
#define SIZE 5
void Menu(){
	printf("\n-----Queue Operations-----\n");
	printf("\n1. Enque\n2. Deque\n3. Display\n4. Exit\n\nEnter Your Choice: ");
}
int Enque(int queue[],int value,int *f,int *r){
	if(*r==SIZE-1){
		printf("\nQueue is Overflow");
		return NULL;
	}
	if(*f==-1)
	    *f = 0;
	++(*r);
	queue[*r]=value;
	return 1;

}
int Deque(int queue[],int *f,int *r){
	int data;
	if(*f==-1){
		printf("\nQueue is Underflow!");
		return NULL;
	}
	if(*f==*r){
		data=queue[*f];
		*f=-1;
		*r=-1;
	}
	else{
		data=queue[*f];
		++(*f);
	}
	return data;
}
void Display(int queue[],int f,int r){
	int i;
	if(f==-1 || f>r){
		printf("\nQueue is Empty");
	}
	else{
		printf("---Queue Element---\n");
		for(i=f;i<=r;i++){
			printf("%d ",queue[i]);
		}
	}
}


void main(){
	int queue[SIZE],front,rear;
	int ch,value;
	front=rear=-1;
	do{
		clrscr();
		Menu();
		scanf("%d",&ch);
		switch(ch){
			case 1:
			printf("Enter Element to insert: ");
			scanf("%d",&value);
			if(Enque(queue,value,&front,&rear)==1)
			   printf("\nData Inserted SuccessFully");
			break;
			case 2:
			value=Deque(queue,&front,&rear);
			if(value!=NULL)
				printf("\nDeleted element is: %d",value);
			break;
			case 3:
			Display(queue,front,rear);
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