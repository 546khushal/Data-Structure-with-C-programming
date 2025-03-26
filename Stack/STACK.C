#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void Menu(){
	printf("****Stack Operations****");
	printf("\n1.Push");
	printf("\n2.Pop");
	printf("\n3.Peep");
	printf("\n4.Display");
	printf("\n5.Exit");
	printf("\n\nEnter Your Choice: ");
}
int flag=0;
void Push(int stack[],int size,int *top,int data){
	if(*top==size-1){
		printf("Stack is Full");
		flag=1;
		getch();
		return;
	}
	flag=0;
	stack[++(*top)]=data;
}
int Pop(int stack[],int *top){
	int data;
	if(*top==-1){
		return -1;
	}
	data=stack[*top];
	(*top)--;
	return data;
}

int Peep(int stack[],int *top){
	int data;
	if(*top==-1){
		return -1;
	}
	data=stack[*top];
	return data;
}

void  Display(int stack[],int *top){
	if(*top==-1){
		printf("\nStack is empty");
		getch();
		return;
	}

	while(*top!=-1){
		printf("\n| %d |  ",stack[*top]);
		(*top)--;
	}

}

void main(){
	int ch,top=-1,size,value;
	int *stack;
	printf("\nEnter Size of Stack: ");
	scanf("%d",&size);
	stack=(int *)malloc(size*sizeof(int));

	do{
		clrscr();
		Menu();
		scanf("%d",&ch);
		switch(ch){
		case 1://push
		printf("\nEnter value to Add in Stack: ");
		scanf("%d",&value);
		Push(stack,size,&top,value);
		if(flag==0)
			printf("Data Push");
		break;
		case 2://pop
		value=Pop(stack,&top);
		if(value==-1){
		printf("\nStack is Empty");
		}
		else{
		printf("\nPoped Data is %d",value);
		}
		break;
		case 3://peep

		value=Peep(stack,&top);
		if(value==-1){
		printf("\nStack is Empty");
		}
		else{
		printf("\nPeeped Data is %d",value);
		}
		break;
		case 4://Display
		Display(stack,&top);
		break;

		case 5 ://exits
			clrscr();
			gotoxy(35,12);
			printf("Thank you");
		break;
		default:
		printf("Invalid choice");

		}
		getch();
	}while(ch!=5);
	getch();
}