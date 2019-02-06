#define MAXSIZE 20
#define MINVALUE -999
/*Functions for STACK ADT*/
void initializeStack(int *stack,int *top){
	stack[0]=MINVALUE;
	*top =-1;
}
int push(int *stack, int top, int x){
    if(top == MAXSIZE-1){
        return 0;
        }
    top = top +1;
    stack[top]=x;
    return top;
}
int pop(int *stack, int top, int *x){
    if(top==-1)
        return top;
    *x = stack[top];
    return --top;
}

void displayStack(int *stack, int top){
    while(top>=0&&stack[top]!=MINVALUE){
        printf("\t%d",stack[top]);
        top--;
        }
}
int atTop(int *stack,int top){
    return stack[top];
}
//Char stack
void initializeCStack(char *stack,int *top){
	*top =-1;
}
int pushC(char *stack, int top, char x){
    if(top == MAXSIZE-1){
        return 0;
        }
    top = top +1;
    stack[top]=x;
    return top;
}
int popC(char *stack, int top, char *x){
    if(top==-1)
        return top;
    *x = stack[top];
    return --top;
}
char atTopC(char *stack,int top){
    return stack[top];
}
void displayCStack(char *stack, int top){
    while(top>=0&&stack[top]!=MINVALUE){
        printf(" %c",stack[top]);
        top--;
        }
}

