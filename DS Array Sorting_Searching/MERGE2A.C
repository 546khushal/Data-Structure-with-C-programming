#include<stdio.h>
#include<conio.h>
void Read(int *a,int size){
	int i;
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
}
void Print(int *a,int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d ",a[i]);
	}
}

void InsetionSort(int *a,int size){
       int i,j,key;
       for(i=1;i<size;i++){
		j=i;
		key=a[i];
		while(j>0 && key<a[j-1]){
			a[j]=a[j-1];
			j--;
		}
		a[j]=key;

       }

}

void MergeSort(int *a,int *b,int *c,int m,int n){
    int i=0,j=0,k=0;
    while(i<m && j<n){
	if(a[i]<=b[j]){
		c[k++]=a[i++];
	}
	else{
		c[k++]=b[j++];
	}
    }
    while(i<m){
	c[k++]=a[i++];
    }
    while(j<n){
	c[k++]=b[j++];
    }
}
void main(){
	int size1,size2,size3,*a,*b,*c;
	clrscr();
	printf("\nEnter the size of Array1:");
	scanf("%d",&size1);
	a=(int *)malloc(size1*sizeof(int));
	printf("\nEnter %d Element: \n",size1);
	Read(a,size1);
	printf("\nEnter the size of Array2:");
	scanf("%d",&size2);
	b=(int *)malloc(size2*sizeof(int));
	printf("\nEnter %d Element: \n",size2);
	Read(b,size2);

	printf("\nFirst Array :\n");
	InsetionSort(a,size1);
	Print(a,size1);
	printf("\nSecond Array :\n");
	InsetionSort(b,size2);
	Print(b,size2);

	size3=size1+size2;
	c=(int *)malloc(size3*sizeof(int));
	MergeSort(a,b,c,size1,size2);
	printf("\nAfter Sorted first Array and second Array :\n");
	Print(c,size3);
	getch();
}