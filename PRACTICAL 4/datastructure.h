/**
    Filename:datastructure.h
    Author:Sushant Kumar
    Date:24-August-2017
    Aim:Holds the ADTs(Stacks, Queues, Circular Queues) and respective functions.
*/

int get(char *string){
    int val;
    printf("\n\tPlease enter the %s:", string);
    scanf("%d",&val);
    return val;
}

/* Functions for CIRCULAR QUEUE ADT*/
void populateCQ(int *CQ){
int i;
	for(i=0;i<MAXSIZE;i++)
		CQ[i] = MINVALUE;
}
void initializeCQ(int CQ[], int *front, int *rear){
	*front = -1;
	*rear = -1;
	populateCQ(CQ);
}
int isFullCQ(int *front, int *rear){
	if((*front == 0 && *rear == MAXSIZE-1) || (*front==*rear+1))
		return 1;
	return 0;
}
int isEmptyCQ(int *front, int *rear){
		if(*front==-1)
		return 1;
	return 0;
}

void insertCQ(int CQ[],int *front, int *rear, int key){
	if(isFullCQ(front,rear)){
		printf("\tOverflow");
		}
	
		if(*rear == -1){
			*rear	= 0;
			*front  = 0;
			}
		else if(*rear == MAXSIZE-1)
			*rear = 0;
		else
			*rear = *rear +1;		 
	
	printf("\n\tRear is: %d",*rear);
	CQ[*rear] = key;
}
void deleteCQ(int CQ[], int *front, int *rear, int *key){
	if(isEmptyCQ(front,rear)){
		printf("Queue is empty");
		return;
	}else{
		*key=CQ[*front];
		CQ[*front]=MINVALUE;
		if(*front == *rear){
			*rear = -1;
			*front = -1;
			}
		else if(*front == MAXSIZE-1)
			*front = 0;
		else
			*front = *front+1;
	}
	printf("\n\tFront = %d",*front);
}
void displayCQ(int CQ[],int front, int rear){
	int i=0;
	if(front<=rear)
		for(i=0;i<=rear;i++){
			if(i==front)
				printf("\t[F]");
			if(CQ[i]==MINVALUE)
				printf("\t--");
			else
			printf("\t%d",CQ[i]);
			if(i==rear)
				printf("\t[R]");
			}
	else{
		for(i=0;i<front;i++){
			if(i==rear)
				printf("\t[R]");
			
			if(CQ[i]==MINVALUE)
				printf("\t--");
			else
			printf("\t%d",CQ[i]);	
	
			}
		for(i=front;i<MAXSIZE;i++){		
			if(i==front)
				printf("\t[F]");
			printf("\t%d",CQ[i]);
		
			}
			
	}

}

/* Functions for QUEUE ADT*/
void populateQ(int *Q){
	int i;
	for(i=0;i<MAXSIZE;i++)
		Q[i] = MINVALUE;
}
void initializeQueue(int Q[],int *front, int *rear){
	*front = -1;
	*rear = -1;
	populateQ(Q);
	
}
int isEmptyQ(int Q[],int front,int rear){
	if(front==-1)
		return 1;
	else
		return 0;
}
int isFullQ(int Q[],int front,int rear){
	if(rear==MAXSIZE-1)
		return 1;
	return 0;
}
void insertQueue(int Q[],int *front,int *rear,int key){
	if(*rear==MAXSIZE){
		printf("\n\tOverflow");
		return;
		}
	*rear = *rear+1;
	Q[*rear]= key;
	
		if(*front==-1)
			*front = 0;
}
void deleteQueue(int Q[],int* front,int* rear,int *key){
	if(front==0){
		printf("\n\tUnderflow");
	return;
	}
	*key = Q[*front];
	Q[*front]=MINVALUE;
	if(*front==*rear){
		*front = -1;;
		*rear  = -1;
	}else{
		*front=*front+1;
	}
}
int frontValue(int Q[], int *front, int *rear){
	if(*front!=-1)
		return Q[*front];
	else
		return MINVALUE;
		
}
int rearValue(int Q[], int *front, int *rear){
	if(*rear!=-1)
		return Q[*rear];
	else
		return MINVALUE;
}
void displayQueue(int Q[],int front, int rear){
	int i;
	for(i=0;i<=rear;i++){
	if(i == front)
		printf("[F]");
	if(Q[i]==MINVALUE)
		printf("\t--");
	else
		printf("\t %d",Q[i]);
	if(i == rear)
		printf("[R]");
	}
}

/*Functions for STACK ADT*/
void initializeStack(int *stack,int *top){
	*top =-1;
}
int push(int *stack, int top, int x){
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

int isEmpty(int *stack, int top){
    if(top==-1)
        return 1;
    return 0;
}
int isFull(int *stack, int top){
    if(top==MAXSIZE-1)
        return 1;
    return 0;
}
void displayStack(int *stack, int top){
	printf("\tTOP =>");
    while(top>=0&&stack[top]!=MINVALUE){
        printf("\t%d",stack[top]);
        top--;
        }
    printf("\t<= BOTTOM");
}
int atTop(int *stack,int top){
    return stack[top];
}
/*Menu function*/
void menu(int adt ){
	
	switch(adt){
    case 1 :
    printf("\n\t-----------------STACK ADT OPERATIONS-----------------");

    printf("\n\n\t1. Push  \t2. Pop \t\t3. isEmpty \t4. isFull");
    printf("\n\t5. Display\t6. atTop");
    printf("\n\t______________________________________________________\n");
    break;
     case 2 :
    printf("\n\t-----------------QUEUE ADT OPERATIONS-----------------");

    printf("\n\n\t1. Insert  \t2. Delete \t3. isEmpty \t4. isFull");
    printf("\n\t5. Display\t6. Front\t7. Rear");
    printf("\n\t______________________________________________________\n");
    break;
     case 3 :
    printf("\n\t------------CIRCULAR QUEUE ADT OPERATIONS-------------");

    printf("\n\n\t1.Insert  \t2. Delete \t3. isEmpty \t4. isFull");
    printf("\n\t5. Display\t6. Front\t7. Rear");
    printf("\n\t______________________________________________________\n");
    break;
    }

}
