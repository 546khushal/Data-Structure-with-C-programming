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
//*****************Linear Search******************
int LinearSearch(Node *st,int value){
	Node *tmp=st;
	int position=1;
	while(tmp != NULL){
		if(tmp->data==value){
			return position;
		}
		tmp=tmp->next;
		position++;

	}
	return -1;
}

//*****************Binary Search******************
int GetSize(Node *st){
	int size=0;
	Node *temp =st;
	while(temp != NULL){
		size++;
		temp=temp->next;
	}
	return size;
}
Node *GetNodeAt(Node *st,int pos){
	int i=0;
	Node *temp=st;
	while(temp != NULL && i<pos){
		temp=temp->next;
		i++;
	}
	return temp;
}
int BinarySearch(Node *st,int value){
	Node *midNode;
	int size=GetSize(st);
	int low=0,high=size-1,mid;
	if(st==NULL){
		printf("\nLinked List is Empty");
	}
	while(low<=high){
		mid=low+(high-low)/2;
		midNode=GetNodeAt(st,mid);
		if(midNode->data==value)
			return mid+1;
		else if(midNode->data<value)
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;

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
void SelectionSort(Node **st){
	int size=GetSize(*st); //while use kiya to size ki need nhi NULL tk jana hai
	int i,j;
	Node *current=*st;
	Node *min,*temp;
	if(*st==NULL || size < 2){
		return;
	   }
	for(i=0;i<size-1;i++){                  //while(current != NULL)
		min=current;
		temp=current->next;
		for(j=i+1;j<size;j++){            //while(temp!=NULL)
			if(temp->data < min->data){
				min=temp;
			}
			temp=temp->next;
		}
		if(min!= current){
		swap(current,min);
		}
		current=current->next;
	}
}
void InsetionSort(Node **st){
	Node *sorted=NULL;
	Node *current=*st;
	Node *next,*temp;
	if((*st)==NULL || (*st)->next==NULL){
	return;
	}
	while(current!=NULL){
	       next=current->next;
	       if(sorted==NULL || sorted->data >= current->data){
			//Insert at the beginning of the sorted list
			current->next=sorted;
			sorted=current;
	       }else{
		temp=sorted;
		while(temp->next !=NULL && temp->next->data < current->data){
			temp=temp->next;
		}
		//insert the current node after temp
		current->next = temp->next;
		temp->next =current;
	       }
	  current=next;//move to the next node in th original list
	 }
	  *st=sorted; //update the head of the list to point the sorted list



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
	printf("\n3. Search Element");
	printf("\n4. Sorting Linked list");
	printf("\n5. Display");
	printf("\n6. Exit");
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
	printf("\n2. Binary Search");
	printf("\n3. Exit");
	printf("\n\nEnter Your Choice: ");
}

void SortMenu(){
	printf("\n1. Bubble Sort");
	printf("\n2. Selection Sort");
	printf("\n3. Insetion Sort");

	printf("\n5. Exit");
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
			case 3://Searcing
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
				case 2://Binary Search
					printf("\nEnter value to search: ");
					scanf("%d",&value);
					BubbleSort(&head);
					pos=BinarySearch(head,value);
					if(pos != -1){
						printf("\nElement %d found at position: %d",value,pos);
					}
					else{
						printf("\nElement %d not found",value);
					}
				break;
				case 3:
				clrscr();
				gotoxy(35,12);
				printf("Thank You Boss!");
				break;
				default:
				printf("Invalid Choice Boss ! Please enter right Choice");
				}
			getch();
			}while(searchch!=3);


			break;
			case 4://Sorting
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
				printf("\nBefore Sort:\n");
				Display(head);

				SelectionSort(&head);
				printf("\nAfter Sort:\n");
				Display(head);
				break;
				case 3:
				printf("\nBefore Sort:\n");
				Display(head);

				InsetionSort(&head);
				printf("\nAfter Sort:\n");
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
			}while(sortch!=5);

			break;
			case 5://Display
			Display(head);
			break;
			case 6:
				clrscr();
				gotoxy(35,12);
				printf("Thank You Boss!");
			break;
			default:
			printf("Invalid Choice Boss ! Please enter right Choice");
		}
	       getch();
	}while(mch!=6);

}