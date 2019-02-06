/**
    Filename:pract4.c
    Author:Sushant Kumar
    Date:24-August-2017
    Aim: To study and implement different linear data structures using arrays - Stack ADT, Queue ADT, and Circular Queue.
    Problem Statement: Use array based allocation to initialize a Stack, a Queue, and a Circular Queue and
	implement the permissible operations on them. Write a menu-driven program in C to test	these data structures.
*/
/* Pre-processor diectives declaration*/
#define SWAP(a,b,t) {t=a;a=b;b=t;}
#define MAXSIZE 5
#define MINVALUE -9999999
#define MAXVALUE  9999999

/* Header file inclusion*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"datastructure.h"

/*The main function*/
int main(){
int mode,op,continueResponse,top,value,stack[MAXSIZE],poppedv;
int Q[MAXSIZE],front,rear,key;
int CQ[MAXSIZE];
    do{
    printf("\n\t--------------------Choose an ADT--------------------");
    printf("\n\t1. Stack \t2. Queue \t3. Circular");
    printf("\n\t-----------------------------------------------------");
    do{
    mode = get("the choice");
    }while(mode<1||mode>3);
        switch(mode){
                case 1:initializeStack(stack,&top);
                        do{
                         menu(mode);
                         do{
                         op = get("the operation code");
                         }while(op<0||op>6);
                         switch(op){
                            case 1:if(top<MAXSIZE-1){
                                top = push(stack,top,get("the value"));
                                printf("\n\tValue Inserted. %d", top);
                                }else{
                                 printf("\n\tSTACK is full, can not add element.\n");
                                }        
                                    break;
                                    
                            case 2:if(top!=-1){
                            			top = pop(stack,top,&poppedv);
                                	   printf("\n\tThe popped value is = %d, TOP = %d",poppedv,top);
                                	   }else{
                                	   	printf("\n\tSorry the stack is empty! Please add some values first.");
                                	   }
                                	   break;
                            case 3: if(isEmpty(stack,top))
                                    printf("\n\tThe Stack is empty.");
                                    else
                                    printf("\n\tThe Stack is not empty.");break;                                    
                            case 4: if(isFull(stack,top))
                                    printf("\n\tThe Stack is Full.");
                                    else
                                    printf("\n\tThe Stack is not Full.");break;
                            case 5:if(top!=-1){
                            		printf("\n\tDisplaying the contents of STACK\n\t");
                                    displayStack(stack,top);}else{
	                                    printf("\n\tSorry the stack is empty! Please add some values first.");
                                    }break;
                            case 6:
                                        if(top==-1)
                                        printf("\n\tThe Stack is empty.");
                                        else
                                        printf("\n\tThe element at top is: %d",atTop(stack,top));
                                        break;
                         }
                          }while(op!=0);
                        break;
                case 2:
                		initializeQueue(Q,&front,&rear);
                		do{
                        menu(2);
                        do{
                         op = get("the operation code");
                         }while(op<0||op>7);
                         switch(op){
                            case 1:if(!isFullQ(Q,front,rear)){
                                insertQueue(Q,&front,&rear,get("the value"));
                                printf("\n\tValue Inserted. Value = %d ",Q[rear]);
                                }else{
                                printf("\n\tQueue is full, can not add element.\n");
                                }        
                                    break;
                                    
                            case 2:if(!isEmptyQ(Q,front,rear)){
                            			deleteQueue(Q,&front,&rear,&key);
                                	   printf("\n\tThe deleted value is = %d",key);
                                	   }else{
                                	   	printf("\n\tSorry the Queue is empty! Please add some values first.");
                                	   }
                                	   break;
                            case 3: if(isEmptyQ(Q,front,rear))
                                    printf("\n\tThe Queue is empty.");
                                    else
                                    printf("\n\tThe Queue is not empty.");break;                                    
                            case 4: if(isFullQ(Q,front,rear))
                                    printf("\n\tThe Queue is Full.");
                                    else
                                    printf("\n\tThe Queue is not Full.");break;
                            case 5:if(!isEmptyQ(Q,front,rear)){
                            		printf("\n\tDisplaying the contents of QUEUE\n\t");
                                    displayQueue(Q,front,rear);
                                    }else{
	                                    printf("\n\tSorry the Queue is empty! Please add some values first.");
                                    }break;
                            case 6:
                                        if(isEmptyQ(Q,front,rear))
                                        printf("\n\tThe Queue is empty.");
                                        else
                                        printf("\n\tThe element at front is: %d",frontValue(Q,&front,&rear));
                                        break;
                                        
                          	case 7:
                                        if(isEmptyQ(Q,front,rear))
                                        printf("\n\tThe Queue is empty.");
                                        else
                                        printf("\n\tThe element at rear is: %d",rearValue(Q,&front,&rear));
                                        break;
                       	  }
                       }while(op!=0);
                       break;
                       
                      case 3:
                		initializeCQ(CQ,&front,&rear);
                		do{
                        menu(3);
                        do{
                         op = get("the operation code");
                         }while(op<0||op>7);
                         switch(op){
                            case 1:if(!isFullCQ(&front,&rear)){
                                insertCQ(CQ,&front,&rear,get("the value"));
                                printf("\n\tValue Inserted. Value = %d ",CQ[rear]);
                               }else{
                                printf("\n\tQueue is full, can't add the elements!");
                               }      
                                    break;
                                    
                            case 2:if(!isEmptyCQ(&front,&rear)){
                            			deleteCQ(CQ,&front,&rear,&key);
                                	   printf("\n\tThe deleted value is = %d",key);
                                	   }else{
                                	   	printf("\n\tSorry the Queue is empty! Please add some values first.");
                                	   }
                                	   break;
                            case 3: if(isEmptyCQ(&front,&rear))
                                    printf("\n\tThe Queue is empty.");
                                    else
                                    printf("\n\tThe Queue is not empty.");break;                                    
                            case 4: if(isFullCQ(&front,&rear))
                                    printf("\n\tThe Queue is Full.");
                                    else
                                    printf("\n\tThe Queue is not Full.");break;
                            case 5:if(!isEmptyCQ(&front,&rear)){
                            		printf("\n\tDisplaying the contents of QUEUE\n\t");
                                    displayCQ(CQ,front,rear);
                                    }else{
	                                    printf("\n\tSorry the Queue is empty! Please add some values first.");
                                    }break;
                            case 6:
                                        if(isEmptyCQ(&front,&rear))
                                        printf("\n\tThe Queue is empty.");
                                        else
                                        printf("\n\tThe element at front is: %d",frontValue(CQ,&front,&rear));
                                        break;
                                        
                          	case 7:
                                        if(isEmptyCQ(&front,&rear))
                                        printf("\n\tThe Queue is empty.");
                                        else
                                        printf("\n\tThe element at rear is: %d",rearValue(CQ,&front,&rear));
                                        break;
                         }
                        }while(op!=0);
                        break;
                                   
        	}

    
    continueResponse = get("Press 0 to exit or any other key to continue");
    
    }while(continueResponse!=0);
    return 0;
}

/*
		--------------------Choose an ADT--------------------
	1. Stack 	2. Queue 	3. Circular
	-----------------------------------------------------
	Please enter the the choice:1

	-----------------STACK ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. isFull
	5. Display	6. atTop
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the value:1

	Value Inserted. 0
	-----------------STACK ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. isFull
	5. Display	6. atTop
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the value:2

	Value Inserted. 1
	-----------------STACK ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. isFull
	5. Display	6. atTop
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the value:3

	Value Inserted. 2
	-----------------STACK ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. isFull
	5. Display	6. atTop
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the value:4

	Value Inserted. 3
	-----------------STACK ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. isFull
	5. Display	6. atTop
	______________________________________________________

	Please enter the the operation code:15

	Please enter the the operation code:1

	Please enter the the value:5

	Value Inserted. 4
	-----------------STACK ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. isFull
	5. Display	6. atTop
	______________________________________________________

	Please enter the the operation code:5

	Displaying the contents of STACK
		TOP =>	5	4	3	2	1	<= BOTTOM
	-----------------STACK ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. isFull
	5. Display	6. atTop
	______________________________________________________

	Please enter the the operation code:3

	The Stack is not empty.
	-----------------STACK ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. isFull
	5. Display	6. atTop
	______________________________________________________

	Please enter the the operation code:4

	The Stack is Full.
	-----------------STACK ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. isFull
	5. Display	6. atTop
	______________________________________________________

	Please enter the the operation code:6

	The element at top is: 5
	-----------------STACK ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. isFull
	5. Display	6. atTop
	______________________________________________________

	Please enter the the operation code:2

	The popped value is = 5, TOP = 3
	-----------------STACK ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. isFull
	5. Display	6. atTop
	______________________________________________________

	Please enter the the operation code:2

	The popped value is = 4, TOP = 2
	-----------------STACK ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. isFull
	5. Display	6. atTop
	______________________________________________________

	Please enter the the operation code:2

	The popped value is = 3, TOP = 1
	-----------------STACK ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. isFull
	5. Display	6. atTop
	______________________________________________________

	Please enter the the operation code:0
	
		--------------------Choose an ADT--------------------
	1. Stack 	2. Queue 	3. Circular
	-----------------------------------------------------
	Please enter the the choice:2

	-----------------QUEUE ADT OPERATIONS-----------------

	1. Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the value:1

	Value Inserted. Value = 1 
	-----------------QUEUE ADT OPERATIONS-----------------

	1. Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the value:2

	Value Inserted. Value = 2 
	-----------------QUEUE ADT OPERATIONS-----------------

	1. Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the value:3

	Value Inserted. Value = 3 
	-----------------QUEUE ADT OPERATIONS-----------------

	1. Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the value:4

	Value Inserted. Value = 4 
	-----------------QUEUE ADT OPERATIONS-----------------

	1. Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the value:5

	Value Inserted. Value = 5 
	-----------------QUEUE ADT OPERATIONS-----------------

	1. Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:5

	Displaying the contents of QUEUE
	[F]	 1	 2	 3	 4	 5	[R]
	-----------------QUEUE ADT OPERATIONS-----------------

	1. Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:3

	The Queue is not empty.
	-----------------QUEUE ADT OPERATIONS-----------------

	1. Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:4

	The Queue is Full.
	-----------------QUEUE ADT OPERATIONS-----------------

	1. Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:6

	The element at front is: 1
	-----------------QUEUE ADT OPERATIONS-----------------

	1. Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:7

	The element at rear is: 5
	-----------------QUEUE ADT OPERATIONS-----------------

	1. Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:2

	The deleted value is = 1
	-----------------QUEUE ADT OPERATIONS-----------------

	1. Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:2

	The deleted value is = 2
	-----------------QUEUE ADT OPERATIONS-----------------

	1. Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:2

	The deleted value is = 3
	-----------------QUEUE ADT OPERATIONS-----------------

	1. Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:5

	Displaying the contents of QUEUE
		--	--	--[F]	 4	 5[R]
	-----------------QUEUE ADT OPERATIONS-----------------

	1. Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:6

	The element at front is: 4
	-----------------QUEUE ADT OPERATIONS-----------------

	1. Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:7

	The element at rear is: 5
	-----------------QUEUE ADT OPERATIONS-----------------

	1. Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:0

	Please enter the Press 0 to exit or any other key to continue:1

	--------------------Choose an ADT--------------------
	1. Stack 	2. Queue 	3. Circular
	-----------------------------------------------------
	Please enter the the choice:3

	------------CIRCULAR QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the value:11

	Rear is: 0
	Value Inserted. Value = 11 
	------------CIRCULAR QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the value:22

	Rear is: 1
	Value Inserted. Value = 22 
	------------CIRCULAR QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the value:33

	Rear is: 2
	Value Inserted. Value = 33 
	------------CIRCULAR QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the value:44

	Rear is: 3
	Value Inserted. Value = 44 
	------------CIRCULAR QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the value:55

	Rear is: 4
	Value Inserted. Value = 55 
	------------CIRCULAR QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:3

	The Queue is not empty.
	------------CIRCULAR QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:4

	The Queue is Full.
	------------CIRCULAR QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:6

	The element at front is: 11
	------------CIRCULAR QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:7

	The element at rear is: 55
	------------CIRCULAR QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:5

	Displaying the contents of QUEUE
		[F]	11	22	33	44	55	[R]
	------------CIRCULAR QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:2

	Front = 1
	The deleted value is = 11
	------------CIRCULAR QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:2

	Front = 2
	The deleted value is = 22
	------------CIRCULAR QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:5

	Displaying the contents of QUEUE
		--	--	[F]	33	44	55	[R]
	------------CIRCULAR QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the value:100

	Rear is: 0
	Value Inserted. Value = 100 
	------------CIRCULAR QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:5

	Displaying the contents of QUEUE
		[R]	100	--	[F]	33	44	55
	------------CIRCULAR QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. isFull
	5. Display	6. Front	7. Rear
	______________________________________________________

	Please enter the the operation code:0

	Please enter the Press 0 to exit or any other key to continue:0


*/
