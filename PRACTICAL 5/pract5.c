/**
    Filename:pract5.c
    Author: Sushant Kumar
    Date:31-August-2017
    Aim: To demonstrate use of Stack ADT for evaluation of arithmetic expressions.
    Problem Statement: Using the Stack ADT created in Experiment-04, write a menu driven C program to that will include routines to acquire an 		   arithmetic expression as a string (in the infix form), to check validity of expression, and to evaluate the expression for the inputted values for
labels in the expression.
*/

/* Header file inclusion*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"stacks.h"
/* Function prototypes */
void getExp(char rpn[]);
void CreateVarTbl(char *rpn, char *varTbl);
void populateVarTbl(char *varTbl,int size);
void CreateValTbl(char *varTbl,int *valTbl);
void populateValTbl(int *valTbl,int size);
void displayT(char*varTbl,int*valTbl);
int getValue(char a, char *varTbl,int *valTbl);
int evalExp(char *rpn, char *varTbl, int *valTbl, int *oprStack, int *oprStackTop);
void convertToPostfix(char *rpn,char *opStack,char *conRPN,int *opStackTop);
int checkValidityOfExpression(char *exp);
void populateRpn(char *ConRpn);
/*Main Function*/
int main(){
    char rpn[MAXSIZE],varTbl[MAXSIZE],opStack[MAXSIZE],ConRPN[MAXSIZE]={0};
    int i,valTbl[MAXSIZE],oprStack[MAXSIZE],oprStackTop,opStackTop,bufferStackTop,conResponse,choice;
    //opstack for infix to postfix conversion operator stack
    
    
   
    printf("---------------Infix To Postfix---------------\n");
    do{
    //initializing the operator stack
    initializeCStack(opStack,&opStackTop);
    opStackTop = pushC(opStack,opStackTop,'#');
    populateRpn(rpn);
    
  	do{
    printf("\tPlease enter the Expression: ");
    getExp(rpn);
    }while(!checkValidityOfExpression(rpn));
    
    //populating the character array with #
    populateVarTbl(varTbl,MAXSIZE);
	
	//populating the valTable array with MINVALUE
    populateValTbl(valTbl,MAXSIZE);
    initializeStack(oprStack,&oprStackTop);
    
    CreateVarTbl(rpn,varTbl);
    CreateValTbl(varTbl,valTbl);
    do{
    printf("\n\t1. Validate Expression\t2. Convert to postfix \t3. Evaluate\t0. Exit");
    printf("\n\tYour Choice?");
    scanf("%d",&choice);
    switch(choice){
    	case 1: if(checkValidityOfExpression(rpn))
    				printf("\n\tThe expression is valid.");
    			else
    				printf("\n\tThe expression is invalid.");
    			break;
    	case 2: initializeStack(oprStack,&oprStackTop);
    			initializeCStack(opStack,&opStackTop);
			    opStackTop = pushC(opStack,opStackTop,'#');
    			populateRpn(ConRPN);
    			convertToPostfix(rpn,opStack,ConRPN,&opStackTop);
    			printf("\n\tThe PostFix expression is: %s\n",ConRPN);
    			break;
    	case 3: initializeStack(oprStack,&oprStackTop);
    			initializeCStack(opStack,&opStackTop);
			    opStackTop = pushC(opStack,opStackTop,'#');
    			populateRpn(ConRPN);
    			convertToPostfix(rpn,opStack,ConRPN,&opStackTop);
    			 printf("\n\tThe variable table is: \n");
    			 displayT(varTbl,valTbl);
    			 printf("\n\tThe evaluated expression is: %d\n",evalExp(ConRPN,varTbl,valTbl,oprStack,&oprStackTop));
    			  break;
    }
    }while(choice!=0);
    printf("\n\tEnter 0 to exit and 1 to continue!");
    scanf("%d",&conResponse);
    
    }while(conResponse!=0);
    return 0;
}
int isOperator(char op){
	if(op=='*'||op=='^'||op=='+'||op=='/'||op=='-')
		return 1;
	return 0;
}
int checkValidityOfExpression(char *exp){
	int ccb=0,cob=0,i;
	for(i=0;exp[i]!='\0';i++){
		//Checks if the first character is operator
		if(isOperator(exp[0]))
			return 0;
		//If both the characters are variables
		if((exp[i]>=65&&exp[i]<=90)&&(exp[i+1]>=65&&exp[i+1]<=90)){
			return 0;
			}
		//If (a+b)c condition
		if(exp[i]==')'&&(exp[i+1]>=65&&exp[i+1]<=90))
			return 0;
		//If both the charaters are operators
		if(isOperator(exp[i])&&isOperator(exp[i+1])){
			return 0;
			}
		//If blank brackets
		if(exp[i]==')'&&exp[i+1]=='('||exp[i]=='('&&exp[i+1]==')')
			return 0;
		//if (+a or )+ condition
		if(isOperator(exp[i])&&exp[i+1]==')'||isOperator(exp[i+1])&&exp[i]=='(')
			return 0;
			
		//Checking if  exp has equal no of ( and ) brackets
		if(exp[i]==')')
			 ccb++;
		if(exp[i]=='(')
			 cob++;
			}
		//If last character is an operator
		if(isOperator(exp[i-1]))
			return 0;
			
	if(ccb!=cob)
		return 0;
	
	return 1;
}
void populateRpn(char *ConRpn){
	int i;
	for(i=0;i<MAXSIZE;i++){
		ConRpn[i]='\0';
	}
}
void getExp(char rpn[]){
    char ch;int ndx=0;
    while(1){
    ch=getchar();
    if(ch=='\n'&&ndx==0)
    	continue;
    else if(ch=='\n')
    	break;   	
    if((ch>=65&&ch<=90)||(ch>=97&&ch<=122)||ch=='/'||ch=='+'||ch=='-'||ch=='*'||ch=='^'||ch==')'||ch=='('){
         if(ch>=97&&ch<=122)
         rpn[ndx++]=ch-32;
         else
         rpn[ndx++]=ch;
         
     }else{
     continue;
     }
     
     }
    rpn[ndx]='\0';
}
void populateVarTbl(char *varTbl,int size){
  int i=0;
  for(i=0;i<size;i++)
    varTbl[i]='#';
}

void populateValTbl(int *valTbl,int size){
  int i=0;
  for(i=0;i<size;i++)
    valTbl[i]=MINVALUE;
}
int isPresent(char a,char *varTbl){
    int i;
    for(i=0;varTbl[i]!='#';i++)
        if(varTbl[i]==a)
            return 1;
    return 0;
}
void CreateVarTbl(char *rpn, char *varTbl){
    int i,c=0;
    for(i=0;rpn[i]!='\0';i++)
        if(rpn[i]>=65&&rpn[i]<=90&&!isPresent(rpn[i],varTbl)){
            varTbl[c]=rpn[i];
            c++;
            }            
}

void CreateValTbl(char *varTbl,int *valTbl){
    int i=0;
    for(i=0;varTbl[i]!='#';i++){
        printf("\tEnter the value of %c: ",varTbl[i]);
        scanf("%d",&valTbl[i]);
        }
}
void displayT(char*varTbl,int*valTbl){
    int i;
    for(i=0;varTbl[i]!='#';i++)
        printf("\t%c",varTbl[i]);
     printf("\n");
     for(i=0;valTbl[i]!=MINVALUE;i++)
        printf("\t%d",valTbl[i]);
     printf("\n");
}
int getValue(char a, char *varTbl,int *valTbl){
    int i;
    for(i=0;varTbl[i]!='#';i++)
        if(varTbl[i]==a)    
            return valTbl[i];
}

int evalExp(char *rpn, char *varTbl, int *valTbl, int *oprStack, int *oprStackTop){
    int i,key,op1,op2;
    for(i=0;rpn[i]!='\0';i++){
        if(rpn[i]>=65&&rpn[i]<=90){
            key = getValue(rpn[i],varTbl,valTbl);
           *oprStackTop = push(oprStack,*oprStackTop,key);
           
           }
         else{
         		*oprStackTop = pop(oprStack,*oprStackTop,&op1);
         		*oprStackTop = pop(oprStack,*oprStackTop,&op2);
         		
         		switch(rpn[i]){
         			case '+':*oprStackTop = push(oprStack,*oprStackTop,op2+op1);
         			break;
         			case '-':*oprStackTop = push(oprStack,*oprStackTop,op2-op1);
         			break;
         			case '/':*oprStackTop = push(oprStack,*oprStackTop,op2/op1);
         			break;
         			case '*':*oprStackTop = push(oprStack,*oprStackTop,op2*op1);
         			break;
         			case '^':*oprStackTop = push(oprStack,*oprStackTop,(int)pow(op2,op1));
         			break;
         		}
         }
     }
     return oprStack[*oprStackTop];
}
int priority(char c){
	switch(c){
		case '+':
		case '-':	return 1;
		case '/':
		case'*':	return 2;
		case ('^')	   :	return 3;
		default:return 0;
	}

}
void convertToPostfix(char *rpn,char *opStack,char *ConRPN,int *opStackTop){
	int i,j;
	char poppedChar,token,count=0;
	printf("\n");
			printf("\t Operator Stack \tOutput Buffer ");
	for(i=0;rpn[i]!='\0';i++){
		
		if(rpn[i]>=65&&rpn[i]<=90){
			ConRPN[count] = rpn[i];
			count++;
		}
			
		else{
				if(rpn[i]=='(')
					*opStackTop = pushC(opStack,*opStackTop,'(');
					else if(rpn[i]==')'){
					while(1){
							*opStackTop = popC(opStack,*opStackTop,&poppedChar);
							if(poppedChar=='('||poppedChar=='#')
								break;
								ConRPN[count] = poppedChar;
								count++;
								//printf("Popped: %c\n",poppedChar);
						}
						if(poppedChar=='#')
					*opStackTop = pushC(opStack,*opStackTop,'#');
				}
				else if(priority(rpn[i])>=priority(opStack[*opStackTop]))	
					*opStackTop = pushC(opStack,*opStackTop,rpn[i]);
				else{
						while(1){
							*opStackTop = popC(opStack,*opStackTop,&poppedChar);
							if(priority(rpn[i])<=priority(opStack[*opStackTop])||poppedChar=='#'||poppedChar=='(')
								break;
								ConRPN[count] = poppedChar;
								count++;
								//printf("Popped: %c\n",poppedChar);
						}	
					if(poppedChar=='#')
					*opStackTop = pushC(opStack,*opStackTop,'#');
				*opStackTop = pushC(opStack,*opStackTop,rpn[i]);
				if(poppedChar!='#'&&poppedChar!='('){
				ConRPN[count] = poppedChar;
								count++;
				}
			}
		}
			ConRPN[count+1]='\0';
			
			//Displays the operator stack
			printf("\n\t");
			displayCStack(opStack,*opStackTop);
			//Display the character buffer
			printf("\t\t\t\t");
				for(j=0;ConRPN[j]!='\0';j++)
					printf("%c",ConRPN[j]);
			printf("\n");
		}
					while(1){
						    *opStackTop = popC(opStack,*opStackTop,&poppedChar);
						    if(poppedChar=='#')
						    	break;
							ConRPN[count] = poppedChar;
							count++;
							//printf("Popped in end: %c\n",poppedChar);
						}
						ConRPN[count] = '\0';

}
/*
		Execution Trail

---------------Infix To Postfix---------------
	Please enter the Expression: (a+b)*(c^(p+f))-d
Enter the value of A: 1
Enter the value of B: 2
Enter the value of C: 3
Enter the value of P: 4
Enter the value of F: 5
Enter the value of D: 6

	1. Validate Expression	2. Convert to postfix 	3. Evaluate	0. Exit
	Your Choice?1

	The expression is valid.
	1. Validate Expression	2. Convert to postfix 	3. Evaluate	0. Exit
	Your Choice?2

	 Operator Stack 	Output Buffer 
	 ( #				

	 ( #				A

	 + ( #				A

	 + ( #				AB

	 #					AB+

	 * #				AB+

	 ( * #				AB+

	 ( * #				AB+C

	 ^ ( * #			AB+C

	 ( ^ ( * #			AB+C

	 ( ^ ( * #			AB+CP

	 + ( ^ ( * #		AB+CP

	 + ( ^ ( * #		AB+CPF

	 ^ ( * #			AB+CPF+

	 * #				AB+CPF+^

	 - #				AB+CPF+^*

	 - #				AB+CPF+^*D

	The PostFix expression is: AB+CPF+^*D-

	1. Validate Expression	2. Convert to postfix 	3. Evaluate	0. Exit
	Your Choice?3

	 Operator Stack 	Output Buffer 
	 ( #				

	 ( #				A

	 + ( #				A

	 + ( #				AB

	 #					AB+

	 * #				AB+

	 ( * #				AB+

	 ( * #				AB+C

	 ^ ( * #			AB+C

	 ( ^ ( * #			AB+C

	 ( ^ ( * #			AB+CP

	 + ( ^ ( * #		AB+CP

	 + ( ^ ( * #		AB+CPF

	 ^ ( * #			AB+CPF+

	 * #				AB+CPF+^

	 - #				AB+CPF+^*

	 - #				AB+CPF+^*D

	The variable table is: 
	A	B	C	P	F	D
	1	2	3	4	5	6

	The evaluated expression is: 59043

	1. Validate Expression	2. Convert to postfix 	3. Evaluate	0. Exit
	Your Choice?0

	Enter 0 to exit and 1 to continue!1
	Please enter the Expression: a+b+c+d
Enter the value of A: 1
Enter the value of B: 1
Enter the value of C: 2
Enter the value of D: 2

	1. Validate Expression	2. Convert to postfix 	3. Evaluate	0. Exit
	Your Choice?3

	 Operator Stack 	Output Buffer 
	 #					A

	 + #				A

	 + #				AB

	 + + #				AB

	 + + #				ABC

	 + + + #			ABC

	 + + + #			ABCD

	The variable table is: 
	A	B	C	D
	1	1	2	2

	The evaluated expression is: 6

	1. Validate Expression	2. Convert to postfix 	3. Evaluate	0. Exit
	Your Choice?2

	 Operator Stack 	Output Buffer 
	 #					A

	 + #				A

	 + #				AB

	 + + #				AB

	 + + #				ABC

	 + + + #			ABC

	 + + + #			ABCD

	The PostFix expression is: ABCD+++

	1. Validate Expression	2. Convert to postfix 	3. Evaluate	0. Exit
	Your Choice?1

	The expression is valid.
	1. Validate Expression	2. Convert to postfix 	3. Evaluate	0. Exit
	Your Choice?0

	Enter 0 to exit and 1 to continue!0


*/














