/*
Perform Opertaio Using Singly Linked List
Name: khushal
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Define Node structure
struct Node{
	int data;
	struct Node*next;
};
struct Node* head=NULL;  //initalize the head of linked list

void InsertFront(int value){
      //Create Node
      struct Node* newNode=(struct Node*)malloc(sizeof (struct Node));
      if(newNode==NULL){
	printf("\nMemory Alloction failded!");
	return ;
      }
      newNode->data=value;
      newNode->next=head;
      head=newNode;
      printf("\nData Inserted Successfully at the front");

}
void InsertEnd(int value){
	struct Node* temp=head;
	//Create Node
	struct Node* newNode=(struct Node*)malloc(sizeof (struct Node));
	if(newNode==NULL){
		printf("\nMemory Alloction failed!");
		return;
	}
	newNode->data=value;
	newNode->next=NULL;
	if(head==NULL){  //if list empty
	head=newNode;
	return;
	}
	//Traverse to the end of list
	//struct Node* temp=head;
	while(temp->next != NULL){
		temp=temp->next;
	}
	temp->next=newNode;            //lastNode->next ==newvalue|NULL
	printf("\nData Inserted Successfully at the End");

}

void InsertAtPosition(int value,int pos){
	int i;
	struct Node* current=head;
	//create node
	struct Node* newNode=(struct Node*) malloc(sizeof(struct Node));
	if(newNode==NULL){
		printf("\nMemory Alloction failed!");
		return;
	}
	newNode->data=value;
	newNode->next=NULL;
	if(pos<1){
		printf("\nInvalid Position! Position must be >=1");
		return;
	}
	//inserting at the front
	if(pos==1){
	newNode->next=head;
	head=newNode;
	printf("\nData Inserted successfully at position %d",pos);
	return;
	}
	//struct Node* current=head;
	for(i=1;i<pos-1 && current !=NULL;i++){     //traverse to the pos-1 node
		current=current->next;
	}
	if(current==NULL){
		printf("Position Out of bounds");
		free(newNode);
		return;
	}

	newNode->next=current->next;
	current->next=newNode;
	printf("\nData Inserted successfully at position %d",pos);

}

void Traversal(){
	struct Node* current=head;
	if(current==NULL){
		printf("\nThe Linked List is Empty!");
		return;
	}
	printf("\nSingly Linked List:\n");
	while(current!=NULL){
	printf("-> %d ",current->data);
	current=current->next;
	}
	printf("->NULL");

}

void DeleteFornt(){
	struct Node* todelete=head;
	if(head==NULL){
		printf("Linked List is Empty!deletion not posible");
		return;
	}
	head=head->next;
	printf("Delete node with value %d",todelete->data);
	free(todelete);

}
void DeleteEnd(){
	struct Node* current=head;
	if(head==NULL){
		printf("Linked List is Empty!deletion not posible");
		return;
	}
	if(head->next==NULL){        //if only one node in list
	printf("\nDelete node with value %d",head->data);
	free(head);
	head=NULL;
	return ;
	}
	while(current->next->next !=NULL){     //traverse to second last node
		current=current->next;
	}
	printf("\nDelete node with value %d",current->next->data);
	free(current->next);
	current->next=NULL;

}
void LinearSearch(int value){
	struct Node* current=head;
	int position=1;
	if(head==NULL){
		printf("\nLinked List is Empty!");
		return;
	}
	while(current!=NULL){
		if(current->data==value){
			printf("Element %d found at position %d",value,position);
			return;
		}
		current=current->next;
		position++;
	}
	printf("\nElement %d is Not Found",value);
}

/*
struct Node* findMiddle(struct Node* low,struct Node* high){
	struct Node* slow=low;
	struct Node* fast=low;
	while(fast!=high && fast->next!=high){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

struct Node* BinarySearch(int target){
	struct Node* low=head;
	struct Node* high=NULL;
	while(low!=high){
		struct Node* mid=findMiddle(low,high);
		if(mid->data==target){
			return mid;
		}
		else if(mid->data<target){
			low=mid->next;     //search in right half
		}
		else{
			high=mid;     //search in left half
		}
	}

	return NULL;
}
*/
int getSize(struct Node* head){
	int size=0;
	struct Node* temp=head;
	while(temp!=NULL){
	size++;
	temp=temp->next;
	}
	return size;
}
struct Node* getNodeAt(struct Node* head,int pos){
	int i=0;
	struct Node* temp=head;
	while(temp!=NULL && i< pos){
		temp=temp->next;
		i++;
	}
	return temp;
}


struct Node* BinarySearch(int value){
	struct Node* midNode;
	int size=getSize(head);
	int low=0,high=size-1,mid;
	if(head==NULL){
		printf("\nLinked List is Empty!");
		return NULL;
	}
	while(low<=high){
		mid=low+(high-low)/2;
		midNode=getNodeAt(head,mid);

		if(midNode->data==value){
			return midNode;
		}
		else if(midNode->data<value){
			low=mid+1;
		}
		else{
		high=mid-1;
		}
	}
	return NULL;
}

void BubbleSort(){
	struct Node* temp;
	struct Node* last=NULL;
	int swapped=0,tempData;
	if(head==NULL || head->next==NULL){
		//printf("Empty Linked list");
		return;
	}

	do{
		swapped=0;
		temp=head;
		 while(temp->next!=last){
			if(temp->data > temp->next->data){
			   tempData=temp->data;
			   temp->data=temp->next->data;
			   temp->next->data=tempData;
			   swapped=1;
			}
			temp=temp->next;
		 }
		 last=temp;     //update the last sorted position

	}while(swapped);
}



void SelectionSort(){
	struct Node* current=head;
	struct Node* temp;
	struct Node* minNode;
	int tempData;
	if(head==NULL || head->next==NULL){
		return;
	}
	while(current!=NULL){
		minNode=current;
		temp=current->next;
		while(temp!=NULL){
			if(temp->data < minNode->data){
				minNode=temp;
			}
			temp=temp->next;
		}
		if(minNode!=current){
			tempData=current->data;
			current->data=minNode->data;
			minNode->data=tempData;
		}
		current=current->next; //move to next node in list
	}
}


void InsertionSort() {

    struct Node* sorted = NULL; // New sorted list
    struct Node* current = head;
    struct Node* next;
    struct Node* temp;
    if (head == NULL || head->next == NULL) {
	return; // List is already sorted
    }

    while (current != NULL) {
	next = current->next;

	// Insert current into sorted list
	if (sorted == NULL || sorted->data >= current->data) {
	    current->next = sorted;
	    sorted = current;
	} else {
	    temp = sorted;
	    while (temp->next != NULL && temp->next->data < current->data) {
		temp = temp->next;
	    }
	    current->next = temp->next;
	    temp->next = current;
	}

	current = next;
    }

    head = sorted;
}

void ReverseList(){
	struct Node *prev=NULL,*current=head,*next=NULL;
	while(current!=NULL){
		next=current->next;        //save the next node
		current->next=prev;        //reverse the link
		prev=current;              //move pre forward
		current=next;              //move current forward
	}
	head=prev;       //update the head to the new first node
}

void Menu(){
	printf("\n***Perform Operation on Singly Linked List :\n");
	printf("\n 1. Insertion");
	printf("\n 2. Traversal");
	printf("\n 3. Deletion");
	printf("\n 4. Serching");
	printf("\n 5. Sorting");
	printf("\n 6. Reverse");
	printf("\n 7. Exit");
	printf("\nEnter your choice: ");
}


void InsertMenu(){
	printf("\n 1. Insertion at Front");
	printf("\n 2. Insertion at End");
	printf("\n 3. Insertion at Position");
	printf("\n 4. Exit");
	printf("\nEnter your choice: ");
}

void DeleteMenu(){
	printf("\n 1. Deletion Front");
	printf("\n 2. Deletion  End");
	printf("\n 3. Deletion with Position");
	printf("\n 4. Exit");
	printf("\nEnter your choice: ");
}
void SearchMenu(){
	printf("\n 1. Linear Search");
	printf("\n 2. Binary Search");
	printf("\n 3. Exit");
	printf("\nEnter your choice: ");
}
void SortMenu(){
	printf("\n 1. Bubble Sort");
	printf("\n 2. Selection Sort");
	printf("\n 3. Insertion Sort");

	printf("\n 4. Exit");
	printf("\nEnter your choice: ");
}


void main(){
	int ch,ich,dch,value,pos,searchch,result,sortch;


	do{
		clrscr();
		Menu();
		scanf("%d",&ch);
		switch(ch){
		case 1://Insertion
			do{
			clrscr();
			InsertMenu();
			scanf("%d",&ich);
			switch(ich){
			case 1://Insertion  at front
			printf("Enter value to insert :");
			scanf("%d",&value);
			InsertFront(value);
			break;
			case 2://Insertion at End
			printf("Enter value to insert :");
			scanf("%d",&value);
			InsertEnd(value);
			break;
			case 3://Insertion at Position
			printf("Enter value to insert :");
			scanf("%d",&value);
			printf("Enter Position :");
			scanf("%d",&pos);
			InsertAtPosition(value,pos);
			break;
			case 4:
			clrscr();
			gotoxy(35,12);
			printf("Thank You for Insert Boss!");
			break;
			default:
			printf("Invalid choice!plz try again");
			}
		  getch();
		}while(ich!=4);
		break;
		case 2://Traversal
		Traversal();
		break;
		case 3://Deletion
			do{
			clrscr();
			DeleteMenu();
			scanf("%d",&dch);
			switch(dch){
			case 1://Deletion front
			DeleteFornt();
			break;
			case 2://Deletion End
			DeleteEnd();
			break;
			case 3://Deletion at Position
			break;
			case 4:
			clrscr();
			gotoxy(35,12);
			printf("Thank You for Delete Boss!");
			break;
			default:
			printf("Invalid choice!plz try again");
			}
		    getch();
		}while(dch!=4);
		break;
		case 4://Searcing
		do{
			clrscr();
			SearchMenu();
			scanf("%d",&searchch);
			switch(searchch){
			case 1://linear search
			printf("Enter Element to search :");
			scanf("%d",&value);
			LinearSearch(value);
			break;
			case 2://Binary search
			printf("Enter Element to search :");
			scanf("%d",&value);

			result= BinarySearch(value);
			if(result!=NULL){
			printf("\nElement %d found in linked list",value);
			}
			else{
			printf("\nElement Not found");
			}
			break;
			case 3://Exit
			clrscr();
			gotoxy(35,12);
			printf("Thank You for Search Boss!");
			break;
			default:
			printf("Invalid choice!plz try again");
			}
		    getch();
		}while(searchch!=3);
		break;
		case 5://Sorting
		do{
			clrscr();
			SortMenu();
			scanf("%d",&sortch);
			switch(sortch){
			case 1:
			BubbleSort();
			Traversal();
			break;
			case 2:
			SelectionSort();
			Traversal();
			break;
			case 3://insertion sort
			InsertionSort();
			Traversal();
			break;
			case 4://Exit
			clrscr();
			gotoxy(35,12);
			printf("Thank You for Sorting Boss!");
			break;
			default:
			printf("Invalid choice!plz try again");
			}
		    getch();
		}while(sortch!=4);
		break;
		case 6://Reverse
		ReverseList();
		Traversal();
		break;
		case 7:
		clrscr();
		gotoxy(35,12);
		printf("Thank You Boss!");
		break;
		default:
		printf("Invalid choice!plz try again");
		}
	 getch();
	}while(ch!=7);

}