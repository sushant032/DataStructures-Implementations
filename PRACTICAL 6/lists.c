/**
    Filename:pract4.c
    Author:Sushant Kumar
    Date:14-September-2017
    Aim: To study singly linked linear lists and implement various operations on it – Insert, Delete, Reverse, Order, Locate, Merge, Linked Stack, and 		Linked Queue
    Problem Statement: Create a self-referential structure, NodeLL to represent a node of a singly linked linear list. Implement the routines to (1) 	find length of the list, (2) create a list, (3) insert an element at the beginning, at the end and at a specified position in the list, (4) delete 		an element fromthe front, rear, or a specified position at the list, (5) reverse the list, (6) search the list. Create a menu-driven program to 	test these routines. Use the singly linked linear list routines to implement a linked stack and a linked queue.
*/
/* Pre-processor diectives declaration*/

/*Header file inclusion*/
#include<stdio.h>
#include<stdlib.h>
#include"list.h"


/*The main function*/
int main(){
	int mode,continueResponse,op,len=0,smode;
	list first = NULL, neww,firstCpy = NULL;
	list queueFirst=NULL, tail =NULL;
	list stackFirst = NULL;
	int key = 0,cnt = 5,delValue,pos;
    do{
    printf("\n\t--------------------Choose an ADT--------------------");
    printf("\n\t1. General list \t2. Linked Stack \t3. Linked Queue");
    printf("\n\t-----------------------------------------------------");
    do{
    mode = get("the choice");
    }while(mode<1||mode>3);
        switch(mode){
			case 1:do{
				 		menu(mode);
				 		len = lengthLL(first);
				 do{
				 	op = get("the operation code");
				 }while(op<0||op>17);
				 switch(op){
					case 1: key = get("the key ");
							first = insertAtBeg(first,key);
							printf("\n\t The inserted key is: %d",key);
							break;
					case 2:key = get("the key");
							first = insertAtEnd(first,key);break;
					case 3:	do{
							printf("\n\tPlease enter the position (1 - %d):", len);
							scanf("%d",&pos);
							}while(pos>len||pos<1);
							key = get("the key");
							first = insertAtPos(first,pos,key);break;
							
					case 4: first = createRandomLL(first,get("the length"));break;
					case 5:if(first!=NULL)
							printf("\tThe length of list is: %d",lengthLL(first));
							else
							printf("\tThe list is empty!");
							break;
							
					case 6:first = deleteAtBeg(first,&key);
							if(key!=STOP)
								printf("\tThe deleted value is: %d",key);break;
					case 7: first = deleteAtEnd(first,&key);
							if(key!=STOP)
								printf("\tThe deleted value is: %d",key);break;
					case 8: first = deleteAtPos(first,get("the position"),&key);
							if(key!=STOP)
								printf("\tThe deleted value is: %d",key);break;
					case 9:if(first!=NULL){
							printf("\n\t0. Ascending \n\t1. Descending");
							scanf("%d",&smode);
							printf("\tList before sorting: ");
							displayLL(first);
							first = sortLL(first,smode);
							printf("\n\tList after sorting: ");
							displayLL(first);}else{
								printf("\n\tThe list is empty.");
							}break;
					case 10:firstCpy = copyLL(first);
							if(firstCpy!=NULL){
							printf("\n\tThe copied linked list is\n\t");
							displayLL(firstCpy);}else{
								printf("\n\tThe list is empty!");
							}break;
					case 11:first = reverse(first);	
							if(first!=NULL){				
							printf("\tThe list after reversing is\n\t");
							displayLL(first);}else{
								printf("\n\tThe list is empty!");
							}break;
					case 12:pos = searchLL(first,get("the key to search"));
							if(pos!=STOP)
								printf("\tThe key found at %d position",pos);
							else
								printf("\tThe key not found.");break;
					case 13:if(first!=NULL) {
								printf("\tDisplaying the list\n\t");
								displayLL(first);
								}
							else
								printf("\n\tThe list is empty.");
								break;
					case 14:if(first!=NULL) {
								first = mergeLL(first);
								printf("\tDisplaying the merged list\n\t");
								displayLL(first);
								}
							else
								printf("\n\tThe list is empty.");
								break;
					case 15:if(first!=NULL) { 
							first = mergeOrdered(first);
							printf("\n\tThe merged list is\n");
							displayLL(first);}else{
								printf("\n\tThe first list is empty.");
							}
							break;
					case 16: first = createList(first);break;
					case 17: first = insertOrdered(first,get("the key"));
				 }
				  }while(op!=0);
				break;
			case 2:do{
				 		menu(mode);
				 do{
				 	op = get("the operation code");
				 }while(op<0||op>5);
				 switch(op){
					case 1: key = get("the key ");
							stackFirst = push(stackFirst,key);
							printf("\n\t The inserted key is: %d",key);
							break;
					case 2:stackFirst = pop(stackFirst,&key);
							if(key!=STOP)
								printf("\tThe deleted value is: %d",key);
							break;
					case 3:	if(isEmpty(stackFirst))
								printf("\n\tThe stack is empty!");
							else
								printf("\n\tThe stack is not empty!");
							break;
					
					case 4: key = atTop(stackFirst);
							if(key!=STOP)
								printf("\tValue at Top is: %d",key);break;
					case 5:if(stackFirst!=NULL)
							displayStack(stackFirst);
							else
							printf("\tThe Stack is empty!");
							break;
				 }
				  }while(op!=0);
				break;
			case 3:do{
				 		menu(mode);
				 do{
				 	op = get("the operation code");
				 }while(op<0||op>6);
				 switch(op){
					case 1: key = get("the key ");
							queueFirst = insertQ(queueFirst,&tail,key);
							printf("\n\t The inserted key is: %d",key);
							break;
					case 2:queueFirst = deleteQueue(queueFirst,&tail,&key);
							if(key!=STOP)
								printf("\tThe deleted value is: %d",key);
							break;
					case 3:	if(isEmpty(queueFirst))
								printf("\n\tThe queue is empty!");
							else
								printf("\n\tThe queue is not empty!");
							break;
					case 4:if(queueFirst!=NULL)
							displayQueue(queueFirst);
							else
							printf("\tThe queue is empty!");
							break;
					case 5: key = front(queueFirst);
							if(key!=STOP)
								printf("\tValue at front is: %d",key);break;
					case 6: key = rear(tail);
							if(key!=STOP)
								printf("\tValue at rear is: %d",key);break;
				 }
				  }while(op!=0);
				break;
                                   
        	}

    
    continueResponse = get("Press 0 to exit or any other key to continue");
    
    }while(continueResponse!=0);
	return 0;
}
/*
		Execution trail
		
		--------------------Choose an ADT--------------------
	1. General list 	2. Linked Stack 	3. Linked Queue
	-----------------------------------------------------
	Please enter the the choice:1



	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:16

	Please enter the key (-99999 to exit): 1

	Please enter the key (-99999 to exit): 2

	Please enter the key (-99999 to exit): 3

	Please enter the key (-99999 to exit): -99999



	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the key :-1

	 The inserted key is: -1


	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:2

	Please enter the the key:4



	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:3

	Please enter the position (1 - 5):2

	Please enter the the key:33



	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:5
	The length of list is: 6


	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:6
	The deleted value is: -1


	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:7
	The deleted value is: 4


	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:4

	Please enter the the length:2



	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:9

	0. Ascending 
	1. Descending0
	List before sorting: 
	1048450 [13093040]	1692901013 [13093008]	
	List after sorting: 
	1048450 [13093040]	1692901013 [13093008]	


	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:4

	Please enter the the length:10



	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:9 

	0. Ascending 
	1. Descending0
	List before sorting: 
	1048450 [13093104]	1692901013 [13093136]	436085873 [13093168]	748533630 [13093200]	776550279 [13093232]	
	289134331 [13093264]	807385195 [13093296]	556889022 [13093328]	95168426 [13093360]	1888844001 [13093392]	
	List after sorting: 
	1048450 [13093104]	95168426 [13093136]	289134331 [13093168]	436085873 [13093200]	556889022 [13093232]	
	748533630 [13093264]	776550279 [13093296]	807385195 [13093328]	1692901013 [13093360]	1888844001 [13093392]	


	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:10

	The copied linked list is
	
	1048450 [13093424]	95168426 [13093456]	289134331 [13093488]	436085873 [13093520]	556889022 [13093552]	
	748533630 [13093584]	776550279 [13093616]	807385195 [13093648]	1692901013 [13093680]	1888844001 [13093712]	


	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:11
	The list after reversing is
	
	1888844001 [13093392]	1692901013 [13093360]	807385195 [13093328]	776550279 [13093296]	748533630 [13093264]	
	556889022 [13093232]	436085873 [13093200]	289134331 [13093168]	95168426 [13093136]	1048450 [13093104]	


	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:12

	Please enter the the key to search:807385195
	The key found at 3 position


	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:13
	Displaying the list
	
	1888844001 [13093392]	1692901013 [13093360]	807385195 [13093328]	776550279 [13093296]	748533630 [13093264]	
	556889022 [13093232]	436085873 [13093200]	289134331 [13093168]	95168426 [13093136]	1048450 [13093104]	


	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:14

	Please enter the key (-99999 to exit): 1

	Please enter the key (-99999 to exit): 2

	Please enter the key (-99999 to exit): 3

	Please enter the key (-99999 to exit): 4

	Please enter the key (-99999 to exit): -99999
	Displaying the merged list
	
	1888844001 [13093392]	1692901013 [13093360]	807385195 [13093328]	776550279 [13093296]	748533630 [13093264]	
	556889022 [13093232]	436085873 [13093200]	289134331 [13093168]	95168426 [13093136]	1048450 [13093104]	
	1 [13093744]	2 [13093776]	3 [13093808]	4 [13093840]	


	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:15

	Please enter the key (-99999 to exit): -99

	Please enter the key (-99999 to exit): -88

	Please enter the key (-99999 to exit): 55

	Please enter the key (-99999 to exit): 66

	Please enter the key (-99999 to exit): -99999

	Displaying the first list

	1 [13093392]	2 [13093360]	3 [13093328]	4 [13093296]	1048450 [13093264]	
	95168426 [13093232]	289134331 [13093200]	436085873 [13093168]	556889022 [13093136]	748533630 [13093104]	
	776550279 [13093744]	807385195 [13093776]	1692901013 [13093808]	1888844001 [13093840]	
	Displaying the Second list

	-99 [13093872]	-88 [13093904]	55 [13093936]	66 [13093968]	
	The merged list is

	-99 [13093872]	-88 [13093904]	1 [13093392]	2 [13093360]	3 [13093328]	
	4 [13093296]	55 [13093936]	66 [13093968]	1048450 [13093264]	95168426 [13093232]	
	289134331 [13093200]	436085873 [13093168]	556889022 [13093136]	748533630 [13093104]	776550279 [13093744]	
	807385195 [13093776]	1692901013 [13093808]	1888844001 [13093840]	


	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:17

	Please enter the the key:6



	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:13
	Displaying the list
	
	-99 [13093872]	-88 [13093904]	1 [13093392]	2 [13093360]	3 [13093328]	
	4 [13093296]	6 [13094000]	55 [13093936]	66 [13093968]	1048450 [13093264]	
	95168426 [13093232]	289134331 [13093200]	436085873 [13093168]	556889022 [13093136]	748533630 [13093104]	
	776550279 [13093744]	807385195 [13093776]	1692901013 [13093808]	1888844001 [13093840]	


	-----------------Linked List OPERATIONS-----------------

	1. Insert atBeg  	2. Insert atEnd 		3. Insert atPos 	4. Create Random List

	5. Length  		6. Delete atBeg 		7. Delete atEnd 	8. Delete atPos

	9. Sort			10. Copy			11. Reverse		12. Search

	13. Display		14. Merge			15. Merge Ordered 	16. Create List

	17. Insert Ordered	0. Exit
	______________________________________________________

	Please enter the the operation code:0

	Please enter the Press 0 to exit or any other key to continue:1

	--------------------Choose an ADT--------------------
	1. General list 	2. Linked Stack 	3. Linked Queue
	-----------------------------------------------------
	Please enter the the choice:2



	-----------------Stack ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. atTop
	5. Display 	0. Exit
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the key :10

	 The inserted key is: 10


	-----------------Stack ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. atTop
	5. Display 	0. Exit
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the key :20

	 The inserted key is: 20


	-----------------Stack ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. atTop
	5. Display 	0. Exit
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the key :30

	 The inserted key is: 30


	-----------------Stack ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. atTop
	5. Display 	0. Exit
	______________________________________________________

	Please enter the the operation code:2
	The deleted value is: 30


	-----------------Stack ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. atTop
	5. Display 	0. Exit
	______________________________________________________

	Please enter the the operation code:3

	The stack is not empty!


	-----------------Stack ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. atTop
	5. Display 	0. Exit
	______________________________________________________

	Please enter the the operation code:4
	Value at Top is: 20


	-----------------Stack ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. atTop
	5. Display 	0. Exit
	______________________________________________________

	Please enter the the operation code:5
	TOP => 20 [13094064]	10 [13094032]	<= BOTTOM


	-----------------Stack ADT OPERATIONS-----------------

	1. Push  	2. Pop 		3. isEmpty 	4. atTop
	5. Display 	0. Exit
	______________________________________________________

	Please enter the the operation code:0

	Please enter the Press 0 to exit or any other key to continue:1

	--------------------Choose an ADT--------------------
	1. General list 	2. Linked Stack 	3. Linked Queue
	-----------------------------------------------------
	Please enter the the choice:3



	------------QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. Display

	5. Front	6. Rear		0. Exit
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the key :1

	 The inserted key is: 1


	------------QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. Display

	5. Front	6. Rear		0. Exit
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the key :2

	 The inserted key is: 2


	------------QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. Display

	5. Front	6. Rear		0. Exit
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the key :3

	 The inserted key is: 3


	------------QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. Display

	5. Front	6. Rear		0. Exit
	______________________________________________________

	Please enter the the operation code:1

	Please enter the the key :4

	 The inserted key is: 4


	------------QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. Display

	5. Front	6. Rear		0. Exit
	______________________________________________________

	Please enter the the operation code:2
	The deleted value is: 1


	------------QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. Display

	5. Front	6. Rear		0. Exit
	______________________________________________________

	Please enter the the operation code:3

	The queue is not empty!


	------------QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. Display

	5. Front	6. Rear		0. Exit
	______________________________________________________

	Please enter the the operation code:4
	[F]         2 [13094128]	       3 [13094160]	       4 [13094192]	  [R]


	------------QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. Display

	5. Front	6. Rear		0. Exit
	______________________________________________________

	Please enter the the operation code:5
	Value at front is: 2


	------------QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. Display

	5. Front	6. Rear		0. Exit
	______________________________________________________

	Please enter the the operation code:6
	Value at rear is: 4


	------------QUEUE ADT OPERATIONS-------------

	1.Insert  	2. Delete 	3. isEmpty 	4. Display

	5. Front	6. Rear		0. Exit
	______________________________________________________

	Please enter the the operation code:0

	Please enter the Press 0 to exit or any other key to continue:0

*/
