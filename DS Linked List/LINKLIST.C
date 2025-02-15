#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct LinkList{
	int data;
	struct LinkList *next;
}Node;
void InsertAtBegin(Node **st,int value){
	Node *newNode,*r;
	newNode = malloc(sizeof (Node));
	if(newNode==NULL){
		printf("\nMemory Allocation Fail!");
		return;
	}
	newNode->data=value;
	newNode->next=*st;
	*st=newNode;
	printf("\nData inserted Successfully At the Begining!");

}

void InsertAtEnd(Node **st,int value){
	Node *newNode,*r;
	newNode=malloc(sizeof (Node));
	if(newNode==NULL){
		printf("\nMemory Allocation Fail!");
		return;
	}
	newNode->data=value;
	newNode->next=NULL;
	if(*st == NULL){
		*st=newNode;
		printf("\nData Inserted Successfully at the End");
		return;
	}
	r=*st;
	while(r->next != NULL){
		r=r->next;
	}
	r->next=newNode;
	printf("\nData Inserted Successfully at the End");
}

void InsertAtPosition(Node **st,int value,int pos){
	int i;
	Node *newNode,*r;
	if(pos<1){
		printf("\nInvalid Position! position must be >=1");
		return;
	}
	if(pos==1){         //inserting at the front
		InsertAtBegin(st,value);
		return;
	}
	r=*st;
	for(i=1;i<pos-1;i++){     //position ke previous Node tk jana
		if(r->next==NULL){
			printf("Invalid Position! Position out of bounds ");
			free(newNode);
			return;
		}
		r=r->next;
	}
	newNode=malloc(sizeof(Node));
	newNode->data=value;
	newNode->next=r->next;
	r->next=newNode;
	printf("\nData Inserted Successfully at the Positon %d",pos);

}

void DeleteAtBegin(Node **st){
	Node *toDelete;
	toDelete=*st;
	if(*st==NULL){
		printf("\nLinked List is Empty!Deleteion Posible");
		return;
	}
	*st=(*st)->next;
	printf("Deleted Node with value %d ",toDelete->data);
	free(toDelete);
}
void DeleteAtEnd(Node **st){
	Node *current;
	current= *st;
	if((*st)==NULL){
		printf("\nLinked List is Empty!Deleteion Posible");
		return;
	}
	if((*st)->next==NULL){
		printf("\nDeleted Node with value %d",current->data);
		free((*st));
		*st = NULL;
		return;
	}
	while(current->next->next != NULL){   //second last node tk jana
		current=current->next;
	}
	printf("\nDeleted Node with value %d",current->next->data);
	free(current->next);   //free last node
	current -> next=NULL;
}

void DeleteAtPosition(Node **st,int pos){
	int i;
	Node *current,*toDelete;
	if(pos<1){
		printf("\nInvalid Position! Position Must be >=1");
	}
	if((*st)==NULL){
		printf("\nLinked List is Empty!Deleteion Posible");
		return;
	}
	if(pos==1){
		DeleteAtBegin(st);
		return;
	}
	current=*st;
	for(i=1; i< pos-1 && (*st)!=NULL ;i++){
		current=current->next;
	}
	if(current==NULL || current->next==NULL){
		printf("\nPosition Out Of Bound");
		return;
	}
	toDelete=current->next;
	current->next=toDelete->next;
	printf("\nDeleted Node with value %d",toDelete->data);
	free(toDelete);

}

void DeleteAtValue(Node **st,int value){
	Node *toDelete,*old;
	toDelete=*st;

	while(toDelete!=NULL){
		if(toDelete->data==value){
			if(toDelete==*st){
				*st= (*st)->next;
				printf("\nDeleted Node with value %d",toDelete->data);
				return;
			}else{
				printf("\nDeleted Node with value %d",toDelete->data);
				old->next=toDelete->next;
				free(toDelete);
				return;
			}
		}
		else{
			old=toDelete;
			toDelete=toDelete->next;
		}
	}
	printf("\nEntered value %d is not present",value);
}

void Display(Node *st){
	if(st==NULL){
		printf("\nThe Linked list is Empty");
		return;
	}
	printf("\nLinked List:\n");
	printf("\nHead");
	while(st!=NULL){
		printf("-> [%d|%X] ",st->data,st->next);
		st=st->next;
	}
	printf("-> NULL");
}


/*
void Display(Node *st){
	if(st==NULL){
		printf("\nThe Linked list is Empty");
		return;
	}
	printf("\nLinked List:\n");
	while(st!=NULL){
	      if(st!=NULL)
		printf("-> %d|%X ",st->data,st->next);
	      else
		printf("-> %d|%X ",st->data,st->next);
	st=st->next;
	}
}
*/



void Menu(){
	printf("\n1. Add New Node");
	printf("\n2. Delete Node");
	printf("\n3. ");
	printf("\n4. Display");
	printf("\n5. Exit");
	printf("\n\nEnter Your Choice: ");
}
void AddMenu(){
	printf("\n1. Add At Begin");
	printf("\n2. Add At Ending");
	printf("\n3. Add At Position");
	printf("\n4. Exit");
	printf("\n\nEnter Your Choice: ");

}
void DeleteMenu(){
	printf("\n1. Delete At Begin");
	printf("\n2. Delete At Ending");
	printf("\n3. Delete At Position");
	printf("\n4. Delete At Value");
	printf("\n5. Exit");
	printf("\n\nEnter Your Choice: ");

}



void main(){
	int mch,ach,dch,value,pos;
	Node *head=NULL;
	do{
		clrscr();
		Menu();
		scanf("%d",&mch);
		switch(mch){
			case 1://Add New Node
			do{
				clrscr();
				AddMenu();
				scanf("%d",&ach);
				switch(ach){
				case 1://Add At Begin
				printf("\nEnter value: ");
				scanf("%d",&value);
				InsertAtBegin(&head,value);
				break;
				case 2://Add At End
				printf("\nEnter value: ");
				scanf("%d",&value);
				InsertAtEnd(&head,value);

				break;
				case 3://Add At position
				printf("\nEnter value: ");
				scanf("%d",&value);
				printf("\nEnter Position: ");
				scanf("%d",&pos);
				InsertAtPosition(&head,value,pos);
				break;
				case 4:
				clrscr();
				gotoxy(35,12);
				printf("Thank You Boss!");
				break;
				default:
				printf("Invalid Choice Boss ! Please enter right Choice");
				}
			getch();
			}while(ach!=4);
			break;
			case 2:  //Delete Node
			do{
				clrscr();
				DeleteMenu();
				scanf("%d",&dch);
				switch(dch){
				case 1://Delete At Begin
				DeleteAtBegin(&head);
				break;
				case 2://Delete At End
				DeleteAtEnd(&head);
				break;
				case 3://Delete At position
				printf("\nEnter position: ");
				scanf("%d",&pos);
				DeleteAtPosition(&head,pos);

				break;
				case 4://Delete At Value
				printf("\nEnter value: ");
				scanf("%d",&value);
				DeleteAtValue(&head,value);
				break;
				case 5:
				clrscr();
				gotoxy(35,12);
				printf("Thank You Boss!");
				break;
				default:
				printf("Invalid Choice Boss ! Please enter right Choice");
				}
			getch();
			}while(dch!=5);
			break;
			case 3:
			break;
			case 4://Display
			Display(head);
			break;
			case 5:
				clrscr();
				gotoxy(35,12);
				printf("Thank You Boss!");
			break;
			default:
			printf("Invalid Choice Boss ! Please enter right Choice");
		}
	       getch();
	}while(mch!=5);

}