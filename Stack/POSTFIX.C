#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 50

void Push(int stack[],int *top,char operator){
	stack[++(*top)]=operator;
}
char Pop(int stack[],int *top){
	if(*top==-1){
		printf("\nStack is Empty");
		return '\0';
	}
       return stack[(*top)--];
}

char Peep(int stack[],int *top){
	if(*top==-1){
		printf("\nStack is Empty");
		return '\0';
	}
	return stack[*top];

}
int priority(char op){
	if(op=='+' || op=='-') return 1;
	if(op=='*' || op=='/') return 2;
	if(op=='^') return 3;
	return 0;
}
int isOperator( char ch){
	return ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^';
}

void Infix_To_Postfix(int stack[],char infix[],char postfix[],int *top){
	int i=0,k=0;
	//int p=0;
	while(infix[i]!='\0'){
		char ss=infix[i];
		//1.if ss is operand->copy to output
		if(isalnum(ss)){
			postfix[k++]=ss;
		}
		//2.if ss is operator && top=-1 then push in stack
		else if(isOperator(ss) && *top==-1 ){
			Push(stack,top,ss);
		}
		//3.if ss is operotr && stach[top]=='('->push
		else if(isOperator(ss) && stack[*top]=='('){
			Push(stack,top,ss);
		}
		 //4.if ss is '(' ->push
		else if(ss=='('){
			Push(stack,top,ss);
		}
		//5. if priority(ss)>priority(stack[top])->push
		else if(isOperator(ss)  &&  priority(ss)>priority(Peep(stack,top))){
			Push(stack,top,ss);
		}
		//6.if priority(ss)<=priority(stack[top])->pop & copy
		else if(isOperator(ss)){
			while(*top!=-1 && priority(ss)<=priority(Peep(stack,top))){
				postfix[k++]=Pop(stack,top);
			}
			Push(stack,top,ss);
		}
		//7.if ss=')'->pop & copy to output until'('occure &ignore both'('&')'
		else if(ss==')'){
			while(*top!=-1 && Peep(stack,top)!='('){
				postfix[k++]=Pop(stack,top);
			}
			Pop(stack,top);//remove (

		}


		i++;
	}
	//8.if ss='\0'->pop &copy to output until top!=-1
		while(*top!=-1){
			postfix[k++]=Pop(stack,top);
		}

	postfix[k]='\0';
       /*	while(postfix[p]!='\0'){
		printf("%s",postfix[p]);
		p++;
	}*/
}


void main(){
	int stack[SIZE];
	int top=-1;
	char postfix[SIZE];
	char infix[]="((A+B)*C-(D/E+F)*G)";
	//char infix[]="2+3*4";

	clrscr();
	Infix_To_Postfix(stack,infix,postfix,&top);
	printf("\nPostfix ecpression: %s",postfix);
	getch();

}