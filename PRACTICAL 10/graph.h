#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <malloc.h>
#include"queue.h"
#define MX 50

// typedef struct adjListNode{
// 	int vertex;
// 	struct adjListNode *next;
// }gnode;
// typedef gnode *graph;

void initGnodes(graph head[],int n){
	for(int i=0;i<n;i++)
		head[i]->next = NULL;
}

void create_al(gnode head[],int n){
	int type,count=1,u,v;
	int i,j;
	printf("\n\tVertexs available are: ");
	for(i=0;i<n;i++)
		printf("%4d",head[i].vertex);
	printf("\n\tEnter 0 for directed 1 for undirected: ");
	scanf("%d",&type);
	//printf("\nVertices starts at 0 and ends at %d",*w-1);
	printf("\n\tVertex ID of -1 Terminates the input");
	printf("\n------------------------------------");
	printf("\nEdge# uVertex# vVertex# Remark");
	printf("\n------------------------------------\n");
	do{
		do{
		printf("%4d\t",count);
		scanf("%d%d",&u,&v);
		if(u>=n||v>=n)
			printf("\n\t\t\t\tInvalid edge.\n");
		}while(u>n&&v>n);

		if(u==-1||v==-1)
			break;
		for(i=0;i<n;i++){
				if(head[i].vertex==u)
					break;
		}
		for(j=0;j<n;j++){
				if(head[j].vertex==v)
					break;
		}

		graph tempG = &head[i];
		if(searchLL(tempG,v)==-1){
			if(type==0)
			head[i].next = insertOrdered(head[i].next,v);
			else{
				head[i].next = insertOrdered(head[i].next,v);
				head[j].next = insertOrdered(head[j].next,u);
			}
			printf("\n\t\t\t\tEdge taken\n");
		count++;
		}else{
		printf("\n\t\t\t\tEdge already taken\n");
		}

	}while( u!=-1 && v!=-1);

}
void printAdj_list(gnode G[],int n){
	for(int i=0;i<n;i++){
		displayLL(&G[i]);
		printf("\n");
	}
}
void create_am(int AdjMat[][MX],int *w){
	int type,count=1,u,v;
	printf("\n\t Enter no of vertices: ");
	scanf("%d",w);
	printf("\n\tEnter 0 for directed 1 for undirected: ");
	scanf("%d",&type);
	printf("\nVertices starts at 0 and ends at %d",*w-1);
	printf("\n\tVertex ID of -1 Terminates the input");
	printf("\n------------------------------------");
	printf("\nEdge# uVertex# vVertex# Remark");
	printf("\n------------------------------------\n");
	do{
		do{
		printf("%4d\t",count);
		scanf("%d%d",&u,&v);
		if(u>=*w||v>=*w)
			printf("\n\t\t\t\tInvalid edge.\n");
		}while(u>*w&&v>*w);

		if(u==-1||v==-1)
			break;

		if(AdjMat[u][v]==0){
			if(type)
				AdjMat[u][v]=AdjMat[v][u]=1;
			else
				AdjMat[u][v]=1;
			printf("\n\t\t\tEdge taken.\n");
			count++;
		}else{
			printf("\n\t\t\tEdge already taken.\n");
		}

	}while( u!=-1 && v!=-1);

}

void printAM(int AdjMat[][MX],int w){
	int i,j;
	printf("\n\nAdjacency Matrix is.....\n\n");
	printf("\t u|v |");
	for(i=0;i<w;i++)
			printf("%4d",i);
	printf("\n\t -----");
	for(i=0;i<w;i++)
			printf("----");
	printf("\n");
	for(i=0;i<w;i++){
		printf("\t %-2d |",i);
		for(j=0;j<w;j++)
		printf("%4d",AdjMat[i][j]);
		printf("\n");
	}
}
void dfs_adj_mat(int g[][MX],int v,int n,int VISITED[]){
	int count;
	printf("%4d",v);
	VISITED[v] = 1;
	for(count=0;count<n;count++){
	if( VISITED[count] != 1 && g[v][count] == 1 )
			dfs_adj_mat(g,count,n,VISITED);
	}
}

void dfs_adj_list(gnode G[],int v, int VISITED[]){
	int count;
	graph temp  = &G[v];
	if(VISITED[temp->vertex]!=1)
	printf("\t%d",G[v].vertex);
	VISITED[v]=1;
	while(temp!=NULL){
				if(VISITED[temp->vertex]!=1)
					dfs_adj_list(G,temp->vertex,VISITED);
					temp = temp -> next;
		}
}

void bfs_adj_mat(int g[][MX],int v,int n){
		 int VISITED[MX]={0},temp,count;
	list queueFirst = NULL, tail = NULL;
	queueFirst =	insertQ(queueFirst,&tail,v);
	VISITED[v] = 1;

while (isEmpty(queueFirst)!=1) {
			queueFirst = deleteQueue(queueFirst,&tail,&temp);
		if(VISITED[temp]==1)
			 	printf("%4d",temp);
			for(count = 0;count<n;count++){
					if(g[temp][count]==1&&VISITED[count]==0){
							VISITED[count]=1;
						queueFirst = insertQ(queueFirst,&tail,count);
						//displayQueue(queueFirst);
					}
		 }
	}
}

void bfs_adj_list(gnode G[],int v){
	int VISITED[MX]={0},temp,count;
		list queueFirst = NULL, tail = NULL;
		queueFirst = insertQ(queueFirst,&tail,v);
		VISITED[v] = 1;
		graph tempG = &G[v];
while(isEmpty(queueFirst)!=1){
		queueFirst = deleteQueue(queueFirst,&tail,&temp);
	if(VISITED[temp]==1)
			printf("\t%d",temp);
		while(tempG!=NULL){
				if( VISITED[tempG->vertex] == 0){
						VISITED[tempG->vertex] = 1;
					queueFirst = insertQ(queueFirst,&tail,tempG->vertex);
					//displayQueue(queueFirst);
			}
			tempG = tempG->next;

	 	}
		tempG = &G[temp];
	}
}
