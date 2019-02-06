#define STOP -99999
#define SWAP(a,b,t) {t=a;a=b;b=t;}
typedef struct nodell{
	int data;
	struct nodell* link;
}Node;
typedef Node* list;

typedef struct adjListNode{
	int vertex;
	struct adjListNode *next;
}gnode;
typedef gnode *graph;

list createNode(void){
	list neww;
	neww = (list)malloc(sizeof(Node));
	if(neww == NULL)
		printf("Stack Underflow");
	return neww;
}

graph createGNode(void){
	graph neww;
	neww = (graph)malloc(sizeof(gnode));
	if(neww == NULL)
		printf("Stack Underflow");
	return neww;
}

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
		}
	//free(temp);
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

int isEmpty(list first){
	if(first==NULL)
		return 1;
	else
		return 0;
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
graph sortLL(graph first,int mode){
	graph iptr,jptr;
	int key;
	if(first==NULL||first->next==NULL)
		return first;

		for(iptr=first;iptr->next!=NULL;iptr=iptr->next)
			for(jptr=iptr->next;jptr!=NULL;jptr=jptr->next){
				if(iptr->vertex>jptr->vertex&& mode == 0){
					key = iptr->vertex;
					iptr->vertex = jptr->vertex;
					jptr->vertex = key;
				}
				if(iptr->vertex<jptr->vertex&& mode == 1){

					key = iptr->vertex;
					iptr->vertex = jptr->vertex;
					jptr->vertex = key;
				}
			}
		return first;

}


graph insertOrdered(graph first, int key){
	graph temp,neww;
	first = sortLL(first,0);
	neww=createGNode();
	neww->vertex = key;
	neww->next = NULL;
	if(first==NULL)
		return neww;
	if(key<=first->vertex)
	{
		neww->next = first;
		return neww;

	}
	temp = first;
	while(temp->next!=NULL && key>=temp->next->vertex){
		temp =temp->next;
	}
	neww->next = temp->next;
	temp->next = neww;
	return first;
}

int searchLL(graph first, int key){
	int i=0;
	graph temp = first;
	while(first!=NULL){
		i++;
		if(first->vertex==key)
			break;
		first = first->next;

	}
	if(temp!=NULL&&first!=NULL)
		return i;
	else
		return -1;
}
void displayLL(graph first){
	graph neww = first;
	int count=0;
	while(neww!=NULL)
	{
		if(count%5==0)
			printf("\n\t");
		printf("%d [%lu]\t",neww->vertex,(uintptr_t)neww);
		neww = neww->next;
		count++;
	}
}
