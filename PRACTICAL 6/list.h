#define STOP -99999
#define SWAP(a,b,t) {t=a;a=b;b=t;}
typedef struct nodell{
	int data;
	struct nodell* link;
}Node;
typedef Node* list;

list createNode(void){
	list neww;
	neww = (list)malloc(sizeof(Node));
	if(neww == NULL)
		printf("Stack Underflow");
	return neww;
}
int lengthLL(list first){
	int count = 0;
	list temp = first;
	if(first==NULL)
		return 0;
	while(temp->link!=NULL){
		temp = temp->link;
		count++;
		}
		return count+1;
}
int isEmptyLL(list first){
	if(first==NULL)
		return 1;
	return 0;
}
list sortLL(list first,int mode){
	list iptr,jptr;
	int key;
	if(first==NULL||first->link==NULL)
		return first;
		
		for(iptr=first;iptr->link!=NULL;iptr=iptr->link)
			for(jptr=iptr->link;jptr!=NULL;jptr=jptr->link){
				if(iptr->data>jptr->data&& mode == 0){
					key = iptr->data;
					iptr->data = jptr->data;
					jptr->data = key;
				}
				if(iptr->data<jptr->data&& mode == 1){
				
					key = iptr->data;
					iptr->data = jptr->data;
					jptr->data = key;
				}
			}
		return first;
				
}
list insertAtBeg(list first, int key){
	list neww;
	neww = createNode();
	
	neww->data = key;
	neww->link = NULL;
	
	//These lines can be ommited i guess!
	if(first == NULL)
		return neww;
		
	neww->link = first;
	return neww;
}

list insertAtEnd(list first, int key){
	list neww,temp=first;
	neww = createNode();
	
	neww->data = key;
	neww->link = NULL;
	
	if(first==NULL)
		return neww;
		
	while(temp->link!=NULL){
		temp=temp->link;
	}
	temp->link = neww;
	return first;
}
list insertAtPos(list first, int pos, int key){
	list neww,temp;
	int ndx=0;
	if(pos>lengthLL(first)||pos<0){
		printf("\n\tThe position does not exist!");
		return first;
	}
	neww = createNode();
	if(neww == NULL){
		printf("\n\tNode not allocated!");
		return first;
	}
	neww->data = key;
	neww->link = NULL;
	if(pos==1){
		neww->link = first;
		return neww;
	}
	temp = first;
	while(ndx<pos-2){
		temp = temp->link;
		ndx++;
	}
	neww->link = temp->link;
	temp->link = neww;
	
	return first;
}
list insertOrdered(list first, int key){
	list temp,neww;
	first = sortLL(first,0);
	neww=createNode();
	neww->data = key;
	neww->link = NULL;
	if(neww==NULL){
		printf("\n\tNode not allocated!");
		return first;
	}
	if(first==NULL)
		return neww;
	if(key<=first->data)
	{
		neww->link = first;
		return neww;
	
	}
	temp = first;	
	while(temp->link!=NULL && key>=temp->link->data){
		temp =temp->link;
	}
	neww->link = temp->link;
	temp->link = neww;
	return first;
}
list deleteAtEnd(list first,int * delValue){
	list temp;
	if(first == NULL){
		printf("\tDelete Failed, List is empty");
		*delValue = STOP;
		return first;
		}
	if(first->link == NULL){
		*delValue = first->data;
		free(first);
		return NULL;
		}
	temp = first;
	while(temp->link->link!=NULL){
		temp = temp->link;
	}
	*delValue = temp->link->data;
	free(temp->link);
	temp->link = NULL;
	return first;
	
}
void displayLL(list first){
	list neww = first;
	int count=0;
	while(neww!=NULL)
	{	
		if(count%5==0)
			printf("\n\t");	
		printf("%d [%lu]\t",neww->data,(unsigned long)neww);
		neww = neww->link;
		count++;
	}
}
list createRandomLL(list first, int length){
	int offset = 123,i;
	first = createNode();
	list neww,temp=first;
	srandom(offset);
	first->data = random()/offset;
	for(i=0;i<length-1;i++)
	{
		neww = createNode();
		neww->data = random();
		neww->link = NULL;
		temp->link = neww;
		temp = temp->link; 
	}
	return first;
}
list createList(list first){
	int key;
	do{
		printf("\n\tPlease enter the key (-99999 to exit): ");
		scanf("%d",&key);
		if(key!=STOP)
			first = insertAtEnd(first, key);
	}while(key!=STOP);

	return first;
}
list deleteAtBeg(list first, int *key){
	list temp;
	if(first==NULL){
		printf("\tDeletion failed the list is empty!");
		*key = STOP;
		return first;
		}
	if(first->link==NULL)
		{		
			printf("Deletion is successful!");
			*key = first->data;
			temp = first;
			free(temp);
		return NULL;
		}
	*key = first->data;
	temp = first;
	first = first->link;
	free(temp);
	return first;	
}

list deleteAtPos(list first,int pos, int *key){
		list temp;int len = lengthLL(first);
	if(first==NULL){
		printf("\tDeletion failed the list is empty!");
		*key = STOP;
		return first;
		}
	if(pos>len){
		printf("\tDeletion failed no such position!");
		*key = STOP;
		return first;
		}
	//Single node is present
	if(first->link==NULL)
		{
			printf("Deletion is successful!");
			*key = first->data;
			temp = first;
			free(temp);
		return NULL;
		}
	//Checking for postion 1
	if(pos==1){
			printf("Deletion is successful!");
			*key = first->data;
			temp = first;
			first = first->link;
			free(temp);
		return first;
	}
	//Rest of the positions
	temp = first;
	while(temp->link->link!=NULL)
		temp = temp->link;
	*key = temp->link->data;
	free(temp->link);
	temp->link = NULL;
	return first;
		
}

list reverse(list first){
list ptr1,ptr2,rev;
//Check if the  list is empty
	if(first==NULL)
		return NULL;
		
//Initializing the pointers
	rev = first;
	ptr2 = first->link->link;
	ptr1 = first->link;
//Put first node is removed
	rev->link = NULL;
	ptr1->link = rev;
//Traversing remaining list and reassign nodes
	while(ptr2!=NULL){
		rev = ptr1;
		ptr1 = ptr2;
		ptr2 = ptr2->link;
		ptr1->link = rev;
		}
	return ptr1;
}

list copyLL(list first){
list dupl,neww,cpy;
	if(first==NULL)	
		return NULL;
	neww = createNode();
	if(neww==NULL){
		printf("Node Not Assigned!");
		return NULL;
	}
	dupl = neww;
	neww->data = first->data;
	while(first->link!=NULL){
		//Copying the previous node pointer
		cpy = neww;
		//Advancing the pointer 
		first = first->link;
		
		neww = createNode();
		neww->data = first->data;
		
		//Setting up the link of the last node
		cpy->link = neww;
	}
	//Grounding the list at the end
	neww->link=NULL;
	return dupl;
}

list mergeLL(list first){
	list newList = NULL,temp;
	newList = createList(newList);
	if(first==NULL){
	printf("\t\nThe list is empty!");
		return NULL;
		}
	temp = first;
	while(temp->link!=NULL)
		temp = temp->link;
	temp->link = newList;
	return first;
}

list mergeOrdered(list first){
	list listNew=NULL,temp,mergedList,toReturn;
	
	listNew = createList(listNew);
	
	//Ordering given list
	first = sortLL(first,0);
	printf("\n\tDisplaying the first list\n");
	displayLL(first);
	///Ordering created list
	listNew = sortLL(listNew,0);
	printf("\n\tDisplaying the Second list\n");
	displayLL(listNew);
	temp = first;
	//Determine the smallest node
	if(temp->data>=listNew->data){
		mergedList = listNew;
		//mergedList->link = NULL;
		
		listNew = listNew->link;	
	}else{
		mergedList = temp;
		//mergedList->link = NULL;
		
		temp = temp->link;
	}
	
	toReturn = mergedList;
	
	while(temp!=NULL && listNew!=NULL){
		
		if(temp->data >= listNew->data){
			mergedList->link = listNew;
			mergedList = mergedList->link;
			listNew = listNew->link;
		}
		else{		
			mergedList->link = temp;
			mergedList = mergedList->link;
			temp = temp->link;
		}
	}
	
	if(temp==NULL)
		mergedList->link = listNew;
	else
		mergedList->link = temp;
	return toReturn;
}	
int searchLL(list first, int key){
	int i=0;
	list temp = first;
	while(first!=NULL){
		i++;
		if(first->data==key)
			break;
		first = first->link;
				
	}
	if(temp!=NULL&&first!=NULL)
		return i;
	else 
		return STOP;
}

int get(char *string){
    int val;
    printf("\n\tPlease enter the %s:", string);
    scanf("%d",&val);
    return val;
}

//Functions for stack

list push(list first, int key){
	list neww = createNode();
	neww->data = key;
	neww->link = first;
	return neww;
}
list pop(list first,int *key){
	list temp;
	if(first==NULL){
		printf("\n\tThe stack is empty!");
		*key = STOP;
		return first;
	}
	temp = first;
	*key = first->data;
	first = first->link;
	free(temp);
	return first;
}

int atTop(list first){
	if(first==NULL){
		printf("\n\tThe stack is empty!");
		return STOP;
	}
	return first->data;
}
void displayStack(list first){
	list neww = first;
	int count=1;
	printf("\tTOP => ");
	while(neww!=NULL)

	{	
		if(count%6==0)
			printf("\n\t");	
		printf("%d [%lu]\t",neww->data,(unsigned long)neww);
		neww = neww->link;
		count++;
	}
	printf("<= BOTTOM");
}

//Functions for Queue
list insertQ(list first,list *tail, int key){
	
	list neww = createNode();
	
	neww->data = key;
	neww->link = NULL;
	
	if(first == NULL){
		*tail = neww;
		return neww;
	}
	(*tail)->link = neww;
	(*tail) = neww;
	return first;
}

list deleteQueue(list first,list *tail ,int *key){
	list temp = first;
	if(first==NULL){
		printf("\n\tDeletion failed, the queue is empty!");
		*key  = STOP;
		*tail = NULL;
		return first;
		}
	*key = first->data;
	first = first->link;
	if(first==NULL){
		*tail=NULL;
		*key=STOP;
		}
	free(temp);
	return first;
}
int front(list first){
	if(first==NULL){
		printf("\n\tThe queue is empty!");
		return STOP;
		}
	return first->data;
}
int rear(list tail){
	if(tail==NULL){
		printf("\n\tThe queue is empty!");
		return STOP;
		}
	return tail->data;
}
void displayQueue(list first){
	list neww = first;
	int count=1;
	printf("\t[F]  ");
	while(neww!=NULL)

	{	
		if(count%6==0)
			printf("\n\t");	
		printf("%8d [%lu]\t",neww->data,(unsigned long)neww);
		neww = neww->link;
		count++;
	}
	printf("  [R]");
}
int isEmpty(list first){
	if(first==NULL)
		return 1;
	else 
		return 0;
}
void menu(int ll ){
	
	switch(ll){
    case 1 :
    printf("\n\n\n\t-----------------Linked List OPERATIONS-----------------");

    printf("\n\n\t1. Insert atBeg  \t2. Insert atEnd \t\t3. Insert atPos \t4. Create Random List");
    printf("\n\n\t5. Length  \t\t6. Delete atBeg \t\t7. Delete atEnd \t8. Delete atPos");
    printf("\n\n\t9. Sort\t\t\t10. Copy\t\t\t11. Reverse\t\t12. Search");
    printf("\n\n\t13. Display\t\t14. Merge\t\t\t15. Merge Ordered \t16. Create List\n\n\t17. Insert Ordered\t0. Exit");
    printf("\n\t______________________________________________________\n");
    break;
     case 2 :
    printf("\n\n\n\t-----------------Stack ADT OPERATIONS-----------------");

    printf("\n\n\t1. Push  \t2. Pop \t\t3. isEmpty \t4. atTop");
    printf("\n\t5. Display \t0. Exit");
    printf("\n\t______________________________________________________\n");
    break;
     case 3 :
    printf("\n\n\n\t------------QUEUE ADT OPERATIONS-------------");

    printf("\n\n\t1.Insert  \t2. Delete \t3. isEmpty \t4. Display");
    printf("\n\n\t5. Front\t6. Rear\t\t0. Exit");
    printf("\n\t______________________________________________________\n");
    break;
    }

}

