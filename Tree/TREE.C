#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;
void CreateNode(node **tree,int value){
	if(*tree==NULL){
		*tree = malloc(sizeof(node));
		(*tree)->data=value;
		(*tree)->left=NULL;
		(*tree)->right=NULL;
	}
	else{
		if(value>(*tree)->data){
			CreateNode(&(*tree)->right,value);
		}
		else{
			CreateNode(&(*tree)->left,value);
		}
	}
}
void PreOrder(node *tree){
	if(tree!=NULL){
		printf("%5d ",tree->data);
		PreOrder(tree->left);
		PreOrder(tree->right);
	}
}
void PostOrder(node *tree){
	if(tree!=NULL){
		PostOrder(tree->left);
		PostOrder(tree->right);
		printf("%5d ",tree->data);
	}
}
void InOrder(node *tree){
	if(tree!=NULL){
		InOrder(tree->left);
		printf("%5d ",tree->data);
		InOrder(tree->right);

	}
}
void DetermineHeight(node *tree,int *height){
	int left_height,right_height;
	if(tree == NULL)
		*height=0;
	else{
		DetermineHeight(tree->left, &left_height);
		DetermineHeight(tree->right, &right_height);
		if(left_height>right_height)
			*height=left_height + 1;
		else
			*height = right_height + 1;
	}
}

int TotalNodes(node *tree){
	if(tree==NULL)
		return 0;
	else
	return(TotalNodes(tree->left)+TotalNodes(tree->right)+1);
}

int InternalNodes(node *tree){
	if((tree==NULL)||(tree->left==NULL && tree->right==NULL))
		return 0;
	else
		return (InternalNodes(tree->left)+InternalNodes(tree->right)+1);
}
int ExternalNodes(node *tree){
	if(tree==NULL)
	return 0;
	else if(tree->left==NULL && tree->right==NULL)
	return 1;
	else
	return(ExternalNodes(tree->left)+ ExternalNodes(tree->right));
}
void RemoveTree(node **tree){
	if((*tree)!=NULL){
		RemoveTree(&(*tree)->left);
		RemoveTree(&(*tree)->right);
		free(*tree);
		*tree=NULL;
	}
}

//Finding InOrder_Successor of given node
//for Delete Algo.
node *Find_InO_Succ(node *curr){
	node *succ = curr->right;//move to the right subtree
	while(succ->left!=NULL)//find the leftmost node
		succ=succ->left;
	return succ;
}

void DeleteNode(node **tree,int item){
	node *curr = *tree,*succ,*pred=NULL;
	int flag=0,delcase,item1;
	//step to find location node
	while(curr!=NULL && flag!=1){
		if(item < curr->data){
			pred=curr;
			curr=curr->left;
		}
		else if(item > curr->data){
			pred=curr;
			curr=curr->right;
		}
		else{
			flag=1;
		}
	}

	if(curr==NULL){
		printf("Node with value %d nont found",item);
		return;
	}

	//Determine the delete case
	if(curr->left==NULL && curr->right==NULL){
		delcase =1;//leaf node
	}
	else if(curr->left!=NULL && curr->right!=NULL){
		delcase=3;
	}
	else{  //(curr->left==NULL || curr->right==NULL)
		delcase = 2;
	}

	//Handle deletion based on the case
	if(delcase == 1){ //delete leaf node
		if(pred == NULL){
			*tree = NULL;
		}
		else if(pred->left==curr){
			pred->left=NULL;
		}
		else{
			pred->right=NULL;
		}
		free(curr);
		printf("Deleted leaf node with value: %d\n",item);
	}
	else if(delcase==2){//Node with one child
		if(pred==NULL){//Deleting the root node
			*tree = (curr->left!=NULL)?curr->left : curr->right;
		}
		else if(pred->left==curr){
			pred->left = (curr->left!=NULL)?curr->left : curr->right;
		}
		else{
			pred->right = (curr->left!=NULL)?curr->left : curr->right;
		}
		free(curr);
		printf("Node with one child and value %d deleted",item);
	}
	else if(delcase==3){//node with two child
		succ=Find_InO_Succ(curr);
		item1=succ->data;
		DeleteNode(tree,succ->data);
		curr->data=item1;
		printf("Node with two children and value %d deleted",item);
	}

}
int  SearchNode(node *tree,int item){
	if(tree==NULL){
		return 0;
	}
	if(tree->data==item)
		return 1;
	else if(item<tree->data)
		return SearchNode(tree->left,item);
	else
		return SearchNode(tree->right,item);
}

int FindMinValue(node *tree){
	node *curr=tree;
	if(tree==NULL){
		printf("Tree is Empty\n");
		return -1;
	}
	//recursive
	if(curr->left==NULL){
		return tree->data;
	}
	return FindMinValue(tree->left);

	/*
	//without recursive
	 while(curr->left!=NULL){
		curr=curr->left;
	 }
	 return curr->data;
	*/
}
int FindMaxValue(node *tree){
	node *curr=tree;
	if(tree==NULL){
		printf("Tree is Empty\n");
		return -1;
	}
	//recursive
	if(curr->right==NULL){
		return tree->data;
	}
	return FindMaxValue(tree->right);

	/*
	//without recursive
	 while(curr->right!=NULL){
		curr=curr->right;
	 }
	 return curr->data;
	*/
}


void Menu(){
	printf("----Binary Search Tree Operations----\n\n");
	printf("1. Create Tree\n");
	printf("2. Traveral\n");
	printf("3. Height of Tree\n");
	printf("4. Total Nodes\n");
	printf("5. Internal Nodes\n");
	printf("6. External Nodes\n");
	printf("7. Remove tree\n");
	printf("\n--Only Binary Search Tree Opeartion--\n");
	printf("8. Insert Node\n");
	printf("9. Search Node\n");
	printf("10.Find Smallest Node\n");
	printf("11.Find Largest Node\n");
	printf("12.Delete Node \n");
	printf("13.Exit\n");
	printf("\nEnter Your Choice: ");
}
void main(){
	node *tree=NULL;
	int ch,value,n,i,height;
	do{
		clrscr();
		Menu();
		scanf("%d",&ch);
		switch(ch){
			case 1://create Node
			clrscr();
			printf("Enter no. of Node to Create: ");
			scanf("%d",&n);
			for(i=0;i<n;i++){
				printf("Enter value to insert: ");
				scanf("%d",&value);
				CreateNode(&tree,value);
			}
			break;
			case 2://Traversal
				clrscr();
				printf("\nPreOrder: ");
				PreOrder(tree);
				printf("\nPostOrder: ");
				PostOrder(tree);
				printf("\nInOrder: ");
				InOrder(tree);
			break;
			case 3://Height of Tree
				clrscr();
				if(height==NULL){
					printf("Tree is Empty. Height is 0\n");
				}
				else{
					DetermineHeight(tree, &height);
					printf("Height of Tree: %d\n",height);
				}
			break;
			case 4://Total Nodes
			n=TotalNodes(tree);
			if(n!=0)
				printf("Total Nodes is: %d",n);
			else
				printf("Tree is Empty. Total Node : 0");
			break;
			case 5://Internal
			n=InternalNodes(tree);
			if(n!=0)
				printf("Internal Nodes is: %d",n);
			else
				printf("Tree is Empty. Total Node : 0");
			break;
			case 6://External
			n=ExternalNodes(tree);
			if(n!=0)
				printf("External Nodes is: %d",n);
			else
				printf("Tree is Empty. Total Node : 0");

			break;
			case 7://remove tree
			clrscr();
			if(tree==NULL)
				printf("Tree  is already empty\n");
			else{
				RemoveTree(&tree);
				printf("Tree has been successfully deleted\n");
			}

			break;
			//BST Operations
			case 8: //insert
			printf("Enter value to insert: ");
			scanf("%d",&value);
			CreateNode(&tree,value);
			printf("Inseted Successfully\n");
			break;
			case 9: //search
			printf("Enter value to Search: ");
			scanf("%d",&value);
			if( SearchNode(tree,value))
				printf("Element present\n");
			else
				printf("Element not present\n");

			break;
			case 10: //small
			value=FindMinValue(tree);
			if(value!= -1)
				printf("Smallest value: %d",value);
			break;
			case 11: //largest
			value=FindMaxValue(tree);
			if(value!= -1)
				printf("Largest value: %d",value);
			break;
			case 12: //delete
			printf("Enter the value to delete: ");
			scanf("%d",&value);
			DeleteNode(&tree,value);
			break;
			case 13://Exit
				clrscr();
				gotoxy(35,12);
				printf("Program Ended....");
			break;
			default:
			printf("Invalid choice!");
		}
		getch();
	}while(ch!=13);
}