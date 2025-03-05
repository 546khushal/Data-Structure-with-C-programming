#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct LinkList{
	int data;
	struct LinkList *prev,*next;
}Node;
void InsertAtBegin(Node **st,int value){
	Node *newNode;
	newNode = malloc(sizeof (Node));
	if(newNode==NULL){
		printf("\nMemory Allocation Fail!");
		return;
	}
	newNode->data=value;
	newNode->next=*st;
	newNode->prev=NULL;
	if(*st!=NULL){
		(*st)->prev=newNode;
	}
	*st=newNode;
	printf("\nData inserted Successfully At the Begining!");

}

void InsertAtEnd(Node **st,int value){
	Node *newNode,*tmp;
	newNode=malloc(sizeof (Node));
	if(newNode==NULL){
		printf("\nMemory Allocation Fail!");
		return;
	}
	newNode->data=value;
	newNode->next=NULL;
	if(*st == NULL){    //list empty then
		newNode->prev=NULL;
		*st=newNode;
		printf("\nData Inserted Successfully at the End");
		return;
	}
	tmp=*st;
	while(tmp->next != NULL){
		tmp=tmp->next;
	}
	tmp->next=newNode;
	newNode->prev=tmp;
	printf("\nData Inserted Successfully at the End");
}

void SortedInsert(Node **st,int value){
	 Node *tmp,*newNode;
	 tmp= *st;
	 newNode=malloc(sizeof(Node));
	 newNode->data=value;
	 newNode->next=NULL;
	 newNode->prev=NULL;
	 //insert begin or when list empty
	 if(*st==NULL || (*st)->data>value){
		newNode->next= *st;
		if(*st != NULL){
			(*st)->prev=newNode;
		}
		*st = newNode;
		printf("\nData Inserted Successfully");

		return;


	 }
	 //traverse list find correct position
	 while(tmp->next!=NULL && tmp->next->data<value){
		tmp=tmp->next;
	 }
	 //insert node after tmp
	 newNode->next=tmp->next;
	 newNode->prev=tmp;
	 if(tmp->next!=NULL){
		tmp->next->prev=newNode;
	 }
	 tmp->next=newNode;
	 printf("\nData Inserted Successfully");


}

void InsertAtPosition(Node **st,int value,int pos){
	int i;
	Node *newNode,*tmp;
	if(pos<1){
		printf("\nInvalid Position! position must be >=1");
		return;
	}
	if(pos==1){         //inserting at the front
		InsertAtBegin(st,value);
		return;
	}
	tmp=*st;
	for(i=1;i<pos-1;i++){     //position ke previous Node tk jana
		if(tmp->next==NULL){
			printf("Invalid Position! Position out of bounds ");
			return;
		}
		tmp=tmp->next;
	}
	newNode=malloc(sizeof(Node));
	newNode->data=value;
	newNode->next=tmp->next;
	newNode->prev=tmp;

	if(tmp->next!=NULL){//update next node prev pointer if exits
		tmp->next->prev=newNode;
	}
	tmp->next=newNode ;
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
	(*st)->prev=NULL;
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
	while(current->next != NULL){   //last node tk jana
		current=current->next;
	}
	printf("\nDeleted Node with value %d",current->data);
	current ->prev-> next=NULL;
	free(current);   //free last node
}

void DeleteAtPosition(Node **st,int pos){
	int i;
	Node *current;
	if(pos<1){
		printf("\nInvalid Position! Position Must be >=1");
		return;
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
	for(i=1; i< pos;i++){
		if(current==NULL){
		printf("\nPosition Out Of Bound");
		return;
		}
	current=current->next;
	}
	if(current->prev!=NULL){
		current->prev->next= current->next;
	}
	if(current->next!=NULL){
		current->next->prev=current->prev;
	}
	printf("\nDeleted Node with value %d",current->data);
	free(current);

}

void DeleteAtValue(Node **st,int value){
	Node *toDelete;
	toDelete=*st;

	while(toDelete!=NULL){
		if(toDelete->data==value){
			// deleting the head node
			if(toDelete==*st){
				*st= toDelete->next;//
				if(*st!=NULL){
					(*st)->prev=NULL;
				}
				printf("\nDeleted Node with value %d",toDelete->data);
				free(toDelete);
				return;
			}
			if(toDelete->prev!=NULL){
				toDelete->prev->next=toDelete->next;
			}
			if(toDelete->next!=NULL){
				toDelete->next->prev=toDelete->prev;
			}
			printf("\nDeleted Node with value %d",toDelete->data);
				free(toDelete);
				return;

		}
		toDelete=toDelete->next;
	}
	printf("\nEntered value %d is not present",value);
}

//*****************Linear Search******************
int LinearSearch(Node *st,int value){
	Node *tmp=st;
	int position=1;
	if(st==NULL){
		printf("\nThe list is Empty!");
		return -1;
	}
	while(tmp != NULL){
		if(tmp->data==value){
			return position;
		}
		tmp=tmp->next;
		position++;

	}
	return -1;
}

int GetSize(Node *st){
	int size=0;
	Node *temp =st;
	while(temp != NULL){
		size++;
		temp=temp->next;
	}
	return size;
}

//*****************Bubble Sort******************
void swap(Node *a,Node *b){
	int temp=a->data;
	a->data=b->data;
	b->data=temp;
}
void BubbleSort(Node **st){
	   int size=GetSize(*st);
	   int i,j;
	   Node *current;
	   if(*st==NULL || size < 2){
		return;
	   }
	   for(i=0;i<size-1;i++){
		  current=*st;
		  for(j=0;j<size-i-1;j++){
			if(current->data > current->next->data){
			swap(current,current->next);
			}
			current=current->next;

		  }
	   }
}


void ReverseList(Node **st){
	Node *tmp=NULL,*current=*st;
	if(*st==NULL){
		printf("\nThe List is empty.");
		return;
	}
	while(current!=NULL){
		tmp=current->prev;
		current->prev=current->next;
		current->next=tmp;
		current=current->prev;

	}
       if(tmp!=NULL){
	*st = tmp->prev;
       }
}



void Display(Node *st){
	if(st==NULL){
		printf("\nThe Linked list is Empty");
		return;
	}
	printf("\nLinked List:\n");
	printf("\nHead");
	while(st!=NULL){
		printf("-> [%X| %d |%X] ",st->prev,st->data,st->next);
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
	printf("\n2. Insert Sorted Element");
	printf("\n3. Delete Node");
	printf("\n4. Search Element");
	printf("\n5. Sorting Linked list");
	printf("\n6. Reverse List");
	printf("\n7. Display");
	printf("\n8. Exit");
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
void SearchMenu(){
	printf("\n1. Linear Search");
	printf("\n2. Exit");
	printf("\n\nEnter Your Choice: ");
}

void SortMenu(){
	printf("\n1. Bubble Sort");
	printf("\n2. Exit");
	printf("\n\nEnter Your Choice: ");
}


void main(){
	int mch,ach,dch,searchch,sortch,value,pos;
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
			case 2://sorted insert
			    printf("\nEnter value: ");
			    scanf("%d",&value);
			    SortedInsert(&head,value);
			break;
			case 3:  //Delete Node
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
			case 4://Searcing
			do{
				clrscr();
				SearchMenu();
				scanf("%d",&searchch);
				switch(searchch){
				case 1://Linear search
					printf("\nEnter value to search: ");
					scanf("%d",&value);
					pos=LinearSearch(head,value);
					if(pos != -1){
						printf("\nElement %d found at position: %d",value,pos);
					}
					else{
						printf("\nElement %d not found",value);
					}

				break;
				case 2:
				clrscr();
				gotoxy(35,12);
				printf("Thank You Boss!");
				break;
				default:
				printf("Invalid Choice Boss ! Please enter right Choice");
				}
			getch();
			}while(searchch!=2);


			break;
			case 5://Sorting
			do{
				clrscr();
				SortMenu();
				scanf("%d",&sortch);
				switch(sortch){
				case 1://BubbleSort
				printf("\nBefore Sort:\n");
				Display(head);

				BubbleSort(&head);
				printf("\nAfter Sort:\n");
				Display(head);

				break;

				case 2:
				clrscr();
				gotoxy(35,12);
				printf("Thank You Boss!");
				break;
				default:
				printf("Invalid Choice Boss ! Please enter right Choice");
				}
			getch();
			}while(sortch!=2);

			break;
			case 6://reverse
			printf("\nReverse List :\n");
			ReverseList(&head);

			Display(head);
			break;
			case 7://Display
			Display(head);
			break;
			case 8:
				clrscr();
				gotoxy(35,12);
				printf("Thank You Boss!");
			break;
			default:
			printf("Invalid Choice Boss ! Please enter right Choice");
		}
	       getch();
	}while(mch!=8);

}