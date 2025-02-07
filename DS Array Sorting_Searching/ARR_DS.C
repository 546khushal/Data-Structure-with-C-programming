/*
Searching And Sorting Using Array
Array
Name:khushal
Date:
*/
#define SIZE  50
#include<stdio.h>
#include<conio.h>

void ReadArray(int a[],const int size)
{
	int i;
	for(i=0;i<size;i++){
	scanf("%d",&a[i]);
	}
}
void PrintArray(int a[],const int size)
{
	int i;
	for(i=0;i<size;i++){
	printf("%d\t",a[i]);
	}
}

void BubbleSort(int a[],const int size){
	int i,j,tmp,flag;
	for(i=0;i<size;i++){
		flag=1;
		for(j=0;j<size-i-1;j++){
			if(a[j]>a[j+1]){
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
				flag=0;
			}
		}
		if(flag==1){
		return;
		}
	}
}

void SelectionSort(int a[], const int size) {
    int i,j,minIndex,tmp;
    for (i=0;i<size-1;i++) {
	minIndex = i;
	for (j=i+1;j<size;j++) {
	    if (a[j] < a[minIndex]) {
		minIndex = j;
	    }
	}
	tmp = a[i];
	a[i] = a[minIndex];
	a[minIndex] = tmp;
    }
}
/*

void InsertionSort(int a[],const int size){
	int i,key,j;
	for(i=1;i<size;i++){                //i start from 1 but array start from 0
		key=a[i];                   //in key=a[i]  start from i=1
		j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;  //place the curr element in its currect position
	}
}
*/

void InsertionSort(int a[],const int size){
	int i,key,j;
	for(i=1;i<size;i++){                //i start from 1 but array start from 0
		key=a[i];                   //in key=a[i]  start from i=1
		j=i;
		while(j>0 && key<a[j-1]){
			a[j]=a[j-1];
			j--;
		}
		a[j]=key;  //place the curr element in its currect position
	}
}


void ShellSort(int a[],const int size){
	int i,index,j;
	int increment=3;
	//set j-1(InsertionSort) to j-increment in ShellSort
	while(increment>0){
		for(i=increment;i<size;i++){                //i start from increment in shell
			index=a[i];
			j=i;
			while(j>0 && index<a[j-increment]){
				a[j]=a[j-increment];
				j=j-increment;
			}
		a[j]=index;  //place the curr element in its currect position
		}
		increment=increment/2;
	}
}
//////////////////////Heap Sort////////////////////////
void BuildHeap(int a[],int size){
	int i,element,s,f;
	for(i=1;i<size;i++){
		element=a[i];
		s=i;
		f=(s-1)/2;
		while(s>0 && element>a[f]){
			a[s]=a[f];
			s=f;
			f=(s-1)/2;
		}
		a[s]=element;  //place the element in its currect position
	}

}

void HeapSort(int a[],int size){
	int i,ivalue,s,f;
	BuildHeap(a,size);
	for(i=size-1;i>0;i--){
		ivalue=a[i];
		a[i]=a[0];   //move the largest to the end
		f=0;
		if(i==1)
			s=-1;
		else
			s=1;
		if(i>2 && a[2]>a[1])
			s=2;
		//Restore the heap property
		while(s>=0 && ivalue < a[s]){
			a[f]=a[s];
			f=s;
			s= 2 * f + 1;           //left child
			if((s+1 < i) && (a[s] < a[s+1]))  //check right child
				s++;
			if(s>=i)
				s=-1;
		}
		a[f]=ivalue;
	}


}

//////////////////////Quick Sort////////////////////////
void QuickSort(int a[],int left,int right){
	int pivot,l_hold,r_hold,pt;
	pivot=a[left];
	l_hold=left;
	r_hold=right;
	while(left<right){
		while(pivot<=a[right] && left!=right){
		right--;
		}
		if(left!=right){
		a[left]=a[right];
		left++;
		}
		while(pivot>=a[left] && left!=right){
		left++;
		}
		if(left!=right){
		a[right]=a[left];
		right--;
		}
	}
	a[left]=pivot;
	pt=left;
	left=l_hold;
	right=r_hold;
	if(left<pt)
		QuickSort(a,left,pt-1);
	if(right>pt)
		QuickSort(a,pt+1,right);

}
//////////////////////Merge Sort////////////////////////
void Merge(int a[],int temp[],int left,int mid,int right){
     int i=left,j=mid,k=left;
     while(i<mid && j<=right){
	if(a[i]<=a[j])
		temp[k++]=a[i++];
	else
		temp[k++]=a[j++];
     }
     while(i<mid){
	temp[k++]=a[i++];
     }
     while(j<=right){
	temp[k++]=a[j++];
     }

     for(i=left;i<=right;i++){       //temp se array a me
	a[i] = temp[i];
     }

}
void MergeSort(int a[],int temp[],int left,int right){
	int mid;
	if(right>left){
		mid=(right+left)/2;
		MergeSort(a,temp,left,mid);
		MergeSort(a,temp,mid+1,right);
			Merge(a,temp,left,mid+1,right);
	}
}

//////////////////////Redix Sort////////////////////////

int Max_In_Array(int a[],int size){
	int i,max=0;
	for(i=0;i<size;i++){
	    if(a[i]>max){
		max=a[i];
	    }
	}
	return max;
}
int FindDigits(int no){
	int r,count=0;
	while(no>0){
		no/=10;
		count++;
	}
	return count;

}


void RedixSort(int a[],int size){
	int i,j,k,pos,exp=1,index;
	int Bucket[10][50]={0};
	int counter[10]={0};
	int maxNo=Max_In_Array(a,size);
	int noOfDigits=FindDigits(maxNo);

	for(i=1;i<=noOfDigits;i++){
		for(j=0;j<10;j++){
			counter[j]=0;
		}

		for(j=0;j<size;j++){
			pos=(a[j]/exp)%10;
			Bucket[pos][counter[pos]++]=a[j];
		}

		k=0;
		for(j=0;j<10;j++){
			for( index=0;index<counter[j];index++) {
				a[k++]=Bucket[j][index];
			}
		}

	      exp*=10;
	}


}


int LinearSearch(int a[],const int size,int value){
	int i;
	for(i=0;i<size;i++){
	    if(a[i]==value){
		return i;
	    }
	}
	return -1;


}

int BinarySearch(int a[],int size,int value){
	int mid,low=0,high=size-1;
	while(low<=high){
	       mid=low+(high-low)/2;
	       if(a[mid]==value)
	       {
			return mid+1;
	       }
	       else if(a[mid]<value){
			low=mid+1;
			}
	       else{
		high=mid-1;
		}
	}
	return -1;
}

int BinarySearch_Recur(int a[],int low,int high,int value){
	int mid;
	if(low<=high){
		mid=low+(high-low)/2;
		if(a[mid]==value){
		    return mid+1;
		}
		else if(a[mid]< value){
			return BinarySearch_Recur(a,mid+1,high,value);
		}
		else{
			return BinarySearch_Recur(a,low,mid-1,value);

		}

	}
	return -1;

}


int InsertFront(int a[],int size,int value){
	int i;

	if(size==NULL){
	//printf("Your Array is not define");
	//return;
	size=0;
	}
	size++;
	for(i=size;i>1;i--){
		a[i-1]=a[i-2];
	}

	a[0]=value;
	printf("\nElement Insert Successfully\n");
	return size;
}
int InsertEnd(int a[],int size,int value){
	int i;
	if(size==NULL){
	//printf("Your Array is not define");
	//return;
	size=0;
	}
	size++;
	a[size-1]=value;
	printf("\nElement Insert Successfully\n");
	return size;
}


int InsertAtPosition(int a[],int size,int value,int pos){
	int i;
	if(pos<1 && pos>50){
	printf("\nERROR: Invalid position! plz Enter valid positon");
	return -1;
	}
	size++;
	for(i=size;i>pos;i--){
		a[i]=a[i-1];
	}
	a[pos]=value;
	printf("\nElement Insert Successfully\n");

	return size;
}

int DeleteEnd(int size){
	if(size<1){
		printf("\nERROR:Array is Empty");
		return -1;
	}
	size=size-1;
	return size;
}



void Menu(){
    printf("\n1. Read");
    printf("\n2. Print");
    printf("\n3. Insertion");
    printf("\n4. Deletion");
    printf("\n5. Sort");
    printf("\n6. Search");
    printf("\n7.Exit");
    printf("\n\nEnter your Choice : ");
}
void SearchMenu(){
    printf("\n1..Linear");
    printf("\n2..Binary");
    printf("\n3.Exit");
    printf("\n\nEnter your Choice : ");
}
void SortMenu(){
    printf("\n1..Bubble Sort");
    printf("\n2.Selection Sort");
    printf("\n3.Insertion Sort");
    printf("\n4.shell Sort");
    printf("\n5.Heap Sort");
    printf("\n6.Quick Sort");
    printf("\n7.Merge Sort");
    printf("\n8.Radix Sort");
    printf("\n9.Exit");
    printf("\n\nEnter your Choice : ");
}
void InsertMenu(){
	printf("\n1. Insert at front");
	printf("\n2. Insert at End");
	printf("\n3. Insert at Position");
	printf("\n4. Exit");
	printf("\n\nEnter your Choice : ");
}

void DeleteMenu(){
	printf("\n1. Delete from front");
	printf("\n2. Delete from End");
	printf("\n3. Delete from Position");
	printf("\n4. Exit");
	printf("\n\nEnter your Choice : ");
}


void main(){
	int ch,sch,srch,size=0,value,pos,insertch,deletech;
	int result;
	int a[SIZE],temp[SIZE];
    do{
	clrscr();
	Menu();
	scanf("%d",&ch);

	switch(ch)
	{
	case 1://Read
	do{
		printf("\nEnter Size of Array : ");
		scanf("%d",&size);
		if(size<1 || size>50)
		{ printf("\nERROR:size must  be between 1 to 50");
		  getch();
		}
		}while(size<1 || size>50);
		printf("Enter %d Element of an Array",size);
		ReadArray(a,size);
	break;
	case 2://Print
	if(size<1 || size>50)
		{ printf("\nERROR:There is no Element in Array");
		  getch();
		}
	else{
	PrintArray(a,size);
	}
	break;
	case 3://insert
	do{
		clrscr();
		InsertMenu();
		scanf("%d",&insertch);

		switch(insertch)
		{
		case 1://Insert front
		printf("\nEnter element to insert: ");
		scanf("%d",&value);
		size=InsertFront(a,size,value);
		PrintArray(a,size);
		break;
		case 2://Insert End
		printf("\nEnter element to insert: ");
		scanf("%d",&value);
		size=InsertEnd(a,size,value);
		PrintArray(a,size);
		break;
		case 3://Insert at position
		printf("\nEnter element to insert: ");
		scanf("%d",&value);
		printf("\nEnter position: ");
		scanf("%d",&pos);
		size=InsertAtPosition(a,size,value,pos);
		PrintArray(a,size);
		break;
		case 4://Exit
			clrscr();
			gotoxy(31,12);
			printf("Thank You");
		break;
		default:
			printf("Enter Right Choice");
		}
		getch();

	}while(insertch!=4);
	break;
	case 4://deletion
	do{
		clrscr();
		DeleteMenu();
		scanf("%d",&deletech);

		switch(deletech)
		{
		case 1://Delete front

		break;
		case 2://Delete End
		size=DeleteEnd(size);
		break;
		case 3://Delete at the position

		break;
		case 4://Exit
			clrscr();
			gotoxy(31,12);
			printf("Thank You");
		break;
		default:
			printf("Enter Right Choice");
		}
		getch();

	}while(deletech!=4);
	break;
	case 5://Sorting
	do{
		clrscr();
		SortMenu();
		scanf("%d",&sch);

		switch(sch)
		{
		case 1://Bubble Sort
			if(size<1 || size>50)
			{ printf("\nERROR:There is no Element in Array");
			getch();
			}
			else{
				printf("\nArray Befor Sorting\n");
				PrintArray(a,size);
				printf("\nArray After Bubble Sorting\n");
				BubbleSort(a,size);
				PrintArray(a,size);
			}
		break;
		case 2://Selection Sort
			if(size<1 || size>50)
				{ printf("\nERROR:There is no Element in Array");
				getch();
				}
			else{
				printf("\nArray Befor Sorting\n");
				PrintArray(a,size);
				printf("\nArray After Selection Sorting\n");
				SelectionSort(a,size);
				PrintArray(a,size);
			}
		break;
		case 3://Insertion Sort
			if(size<1 || size>50)
				{ printf("\nERROR:There is no Element in Array");
				getch();
				}
			else{
				printf("\nArray Befor Sorting\n");
				PrintArray(a,size);
				printf("\nArray After Insertion Sorting\n");
				InsertionSort(a,size);
				PrintArray(a,size);
			}
		break;
		case 4://shell
		if(size<1 || size>50)
				{ printf("\nERROR:There is no Element in Array");
				getch();
				}
			else{
				printf("\nArray Befor Sorting\n");
				PrintArray(a,size);
				printf("\nArray After Insertion Sorting\n");
				ShellSort(a,size);
				PrintArray(a,size);
			}
		break;
		case 5: //heap
		if(size<1 || size>50)
				{ printf("\nERROR:There is no Element in Array");
				getch();
				}
			else{
				printf("\nArray Befor Sorting\n");
				PrintArray(a,size);
				printf("\nArray After Insertion Sorting\n");
				HeapSort(a,size);
				PrintArray(a,size);
			}

		break;
		case 6://quick
		if(size<1 || size>50)
				{ printf("\nERROR:There is no Element in Array");
				getch();
				}
			else{
				printf("\nArray Befor Sorting\n");
				PrintArray(a,size);
				printf("\nArray After Insertion Sorting\n");
				QuickSort(a,0,size);
				PrintArray(a,size);
			}
		break;
		case 7://merge
		if(size<1 || size>50)
				{ printf("\nERROR:There is no Element in Array");
				getch();
				}
			else{
				printf("\nArray Befor Sorting\n");
				PrintArray(a,size);
				printf("\nArray After Merge Sorting\n");
				MergeSort(a,temp,0,size-1);
				PrintArray(a,size);
			}
		break;
		case 8://radix
		if(size<1 || size>50)
				{ printf("\nERROR:There is no Element in Array");
				getch();
				}
			else{
				printf("\nArray Befor Sorting\n");
				PrintArray(a,size);
				printf("\nArray After Redix  Sorting\n");
				RedixSort(a,size);
				PrintArray(a,size);
			}
		break;
		case 9://Exit
			clrscr();
			gotoxy(31,12);
			printf("Thank You");
		break;
		default:
			printf("Enter Right Choice");
		}
		getch();

	}while(sch!=9);

	break;
	case 6://serching
	do{
		clrscr();
		SearchMenu();
		scanf("%d",&srch);

		switch(srch)
		{
		case 1://Linear Searching
			if(size<1 || size>50)
				{ printf("\nERROR:There is no Element in Array");
				getch();
			}
			else{
				printf("Enter Value to Find :");
				scanf("%d",&value);
				result=LinearSearch(a,size,value);
				if(result!=-1){
					printf("Element %d is Present at Position %d in Array",value,LinearSearch(a,size,value));
				}
				else{
				printf("Element %d is Not present in Array",value);
				}
			}
		break;
		case 2://Binary Search
			if(size<1 || size>50)
				{ printf("\nERROR:There is no Element in Array");
			  getch();
			}
			else{
			 SelectionSort(a,size);
			 printf("Enter Value to Find :");
			 scanf("%d",&value);
			 //result=BinarySearch(a,size,value);
			 result=BinarySearch_Recur(a,0,size-1,value);
				if(result!=-1){
					printf("Element %d is Present at position %d in Array",value,result);
				}
				else{
				printf("Element %d is Not present in Array",value);
				}

			}
		break;


		case 3://Exit
			clrscr();
			gotoxy(31,12);
			printf("Thank You");
		break;
		default:
			printf("Enter Right Choice");
		}
		getch();

	}while(srch!=3);


	case 7://Exit
	clrscr();
	gotoxy(31,12);
	printf("Thank You");
	break;
	default:
	printf("Enter Right Choice");
	}
	getch();
     }while(ch!=7);

}