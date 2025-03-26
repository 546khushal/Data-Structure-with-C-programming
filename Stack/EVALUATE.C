#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define SIZE 50

void Push(char stack[],int *top,char operator){
	stack[++(*top)]=operator;
}
char Pop(char stack[],int *top){
	if(*top==-1){
		printf("\nStack is Empty");
		return '\0';
	}
       return stack[(*top)--];
}

char Peep(char stack[],int *top){
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
//infix to postfix**********************
void Infix_To_Postfix(char stack[],char infix[],char postfix[],int *top){
	int i=0,k=0;
	//int p=0;
	while(infix[i]!='\0'){
		char ss=infix[i];
		if(ss==' '){   //skip when space in infix exp...
			i++;
			continue;
		}
		//1.if ss is operand->copy to output
		if(isdigit(ss)){
			while(isdigit( infix[i] )){
				postfix[k++]=infix[i++];
			}
			postfix[k++]='$';
			continue;
		}
		if(isalpha(ss)){
			postfix[k++]=ss;
			i++;
			continue;
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
void PushNum(int stack[],int *top,int num){
	stack[++(*top)]=num;
}
int PopNum(int stack[],int *top){
	if(*top==-1){
		printf("\nStack is Empty");
		return 0;
	}
       return stack[(*top)--];
}
int EvaluatePostfix(char postfix[]){
	int numStack[SIZE];
	int numTop=-1;
	int i=0,j=0;
	char tmpNum[SIZE];
	for(i=0;postfix[i]!='\0';i++){
		if(isdigit(postfix[i])){       //tmpNum stack me multi digit tk string stack banayi
			tmpNum[j++]=postfix[i];
		}
		else if(postfix[i]=='$' && j>0 ){//convert str to int and Push
			tmpNum[j]='\0';
			PushNum(numStack,&numTop,atoi(tmpNum));
			j=0;
		}
		else if(isOperator(postfix[i])){
			int num2=PopNum(numStack,&numTop);
			int num1=PopNum(numStack,&numTop);
			int res;
			switch(postfix[i]){
				case '+':
					res=num1+num2; break;
				case '-':
					res=num1-num2; break;
				case '*':
					res=num1*num2; break;
				case '/':
					res=num1/num2; break;

				case '^':
					res=(int)pow(num1,num2); break;
			}
			PushNum(numStack,&numTop,res);
		}
	}
	return PopNum(numStack,&numTop);
}


void Rev(char infix[]){
	  int len=strlen(infix);
	  char tmp;
	  int i=0;
	  while(i<len/2){
		tmp=infix[i];
		infix[i]=infix[len-i-1];
		infix[len-i-1]=tmp;
		i++;
	  }

}

//infix to prefix****************
void Infix_To_Prefix(char stack[],char infix[],char postfix[],char prefix[],int *top){
	int i,j=0;
	char tmp[SIZE];
	strcpy(tmp,infix);
	Rev(tmp);
	for(i=0;tmp[i]!='\0';i++){
		if(tmp[i]==')'){ tmp[i]='(';}
		else if(tmp[i]=='('){ tmp[i]=')';}
	  }
	*top=-1;
	Infix_To_Postfix(stack,tmp,postfix,top);

	Rev(postfix);
	//strcpy(prefix,postfix);
	for(i=0;i<postfix[i]!='\0';i++){
		if(postfix[i]!='(' && postfix[i]!=')'){
			prefix[j++]=postfix[i];
		}
	}
	prefix[j]='\0';
}

void main(){
	char stack[SIZE];
	int top=-1,ch,Result;
	char postfix[SIZE],prefix[SIZE],infix[SIZE];
	//char infix[]="((A+B)*C-(D/E+F)*G)";
	//char infix[]="2+3*4";

	clrscr();
	printf("Enter Expression: ");
	gets(infix);

	printf("\n1. Infix to Postfix\n2. Infix to Prefix\n3. Both\n4. Evaluate ExpressionResult\n\nEnter Choice");
	scanf("%d",&ch);
	if(ch==1){
		Infix_To_Postfix(stack,infix,postfix,&top);
		printf("\nPostfix expression: %s",postfix);
	}
	else if(ch==2){
		Infix_To_Prefix(stack,infix,postfix,prefix,&top);
		printf("\nPrefix expression: %s",prefix);
	}
	else if(ch==3){
		Infix_To_Postfix(stack,infix,postfix,&top);
		printf("\nPostfix expression: %s",postfix);
		Infix_To_Prefix(stack,infix,postfix,prefix,&top);
		printf("\nPrefix expression: %s",prefix);
	}
	else if(ch==4){
		Infix_To_Postfix(stack,infix,postfix,&top);
		Result=EvaluatePostfix(postfix);
		printf("\n\nThe Final Result Of Exp(%s) is: %d",infix,Result);
	}
	else{
		printf("Invalid Choice");
	}
	getch();

}