/*
WAP to create two link list and perform Operation Union,intersect
Name: Khushal
Date: 21/02/2025
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct LinkList{
	int data;
	struct LinkList *next;
}Node;

void Append(Node **st,int value){
	 Node *tmp,*r;
	 tmp= *st;
	 r=malloc(sizeof(Node));
	 r->data=value;
	 r->next=NULL;
	 if(*st==NULL || (*st)->data>value){
		r->next=*st;
		*st=r;
	 }
	 else{
		while(tmp->next != NULL && tmp->next->data<=value){
			tmp=tmp->next;
		}
		r->next=tmp->next;
		tmp->next=r;
	 }
}



void UnionList(Node *p,Node *q,Node **result){
	Node *tmp;
	int flag;

	while(p!=NULL){
		Append(result,p->data) ;
		p=p->next;
	}
	while(q!=NULL){
		tmp=*result;
		flag=0;
		while(tmp!=NULL){     //check current element already in result list
			if(tmp->data==q->data){
				flag=1;
				break;
			}
			tmp=tmp->next;
		}
		if(!flag){
			Append(result,q->data);
		}
		q=q->next;
	}
}

void Intersect(Node *p,Node *q,Node **result){
	Node *tmp1=p;
	Node *tmp2;
	Node *check;
	int flag;
	while(tmp1 !=NULL){
		tmp2=q;
		while(tmp2!=NULL){
			if(tmp1->data==tmp2->data){
				check= *result;
				flag=0;
				while(check!=NULL){
					if(check->data == tmp1->data){
						flag=1;
						break;
					}
					check=check->next;
				}

				if(!flag){
				Append(result,tmp1->data);
				}
				break;
			}
			tmp2=tmp2->next;
		}
		tmp1=tmp1->next;
	}
}


void Display(Node *st){
	if(st==NULL){
		printf("The List is Empty!");
		return;
	}
	printf("\nHead");
	while(st!=NULL){
		printf("-> %d ",st->data);
		//printf("-> [%d|%X] ",st->data,st->next);
		st=st->next;

	}
	printf("-> NULL");

}
void Menu(){
	printf("\n1. Insert First list");
	printf("\n2. Display First list");
	printf("\n3. Insert Second list");
	printf("\n4. Display Second list");
	printf("\n5. Union Both List");
	printf("\n6. InterSect Both List");
	printf("\n7. Exit");
	printf("\n\nEnter Your Choice: ");
}

void main(){
	int ch,value;
	Node *start1=NULL;
	Node *start2=NULL;
	Node *result=NULL;

	do{
		clrscr();
		Menu();
		scanf("%d",&ch);
		switch(ch){
			case 1: //first list
			printf("\nEnter value(L1): ");
			scanf("%d",&value);
			Append(&start1,value);
			break;
			case 2: //display first list
			Display(start1);
			break;
			case 3://second list
			printf("\nEnter value(L2): ");
			scanf("%d",&value);
			Append(&start2,value);
			break;
			case 4://display  second
			Display(start2);
			break;
			case 5://Union
			printf("\nFirst List:");
			Display(start1);
			printf("\nSecond List:");
			Display(start2);
			printf("\n\nUnion List:\n");
			UnionList(start1,start2,&result);
			Display(result);
			break;
			case 6://Intersect
			printf("\nFirst List:");
			Display(start1);
			printf("\nSecond List:");
			Display(start2);
			printf("\n\nIntersect List:\n");
			Intersect(start1,start2,&result);
			Display(result);
			break;
			case 7:
				clrscr();
				gotoxy(35,12);
				printf("Thank you!");
			break;
			default:
				printf("Invalid Choice! Please try Again");
		}
		getch();
	}while(ch!=7);

}