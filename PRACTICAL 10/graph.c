/*
  Author: Sushant Kumar
  Aim: To study a graph data structure and demonstrate different traversals on it - Depth First
	Search and Breadth First Search
  Probelm Statement: Write a C routine to create an arbitrary graph [a minimum of 6 vertices] using adjacency
					matrix representation. Write menu driven C program that will include routines to
					(1)
					display the graph [the adjacency matrix], (2) execute depth-first search, and (3) execute
					breadth-first search.
					Write a C routine to create an arbitrary graph [a minimum of 6 vertices] using adjacency
					list representation. Write menu driven C program that will include routines to
					(1)
					display the graph [the adjacency list], (2) execute depth-first search, and (3) execute
					breadth-first search.

*/

#define MX 50
#include<stdio.h>
#include"graph.h"
int main(){
	static int AdjMat[MX][MX];
	int u,v=0,i,j,w,type,count=1,src,data,choice,tchoice,cresponse,opt;
	int VISITED[MX] = {0};
	gnode head[MX];
do{
do{
printf("\n----------------------GRAPH ADT (IMPLEMENTATION CHOICE)----------------------");
printf("\n\t1. Adjacency Matrix \t\t2.Adjacency List");
printf("\n\tEnter your choice? ");
scanf("%d",&choice);
}while(choice<1&&choice>2);
switch (choice) {
	case 1:	create_am(AdjMat,&w);
					printAM(AdjMat,w);
					do{
					do{
					printf("--------------------------TRAVERSAL CHOICE--------------------------");
					printf("\n\t1. BFS \t2. DFS\t0. Exit");
					printf("\n\tYour choice? ");
					scanf("%d",&tchoice);
					}while(tchoice<0||tchoice>2);
				switch (tchoice){
					case 1:do{
						printf("Enter the source vertext:(0 - %d) ",w-1);
						scanf("%d",&src);
						}while(src<0||src>w-1);
						printf("\n\tBreadth First search is: \n");
						bfs_adj_mat(AdjMat,src,w);
						break;
				case 2:do{
					printf("Enter the source vertext:(0 - %d) ",w-1);
					scanf("%d",&src);
					}while(src<0||src>w-1);
						printf("The depth first search is: \n");
						dfs_adj_mat(AdjMat,src,w,VISITED);
						for(int i=0;i<MX;i++)
							VISITED[i]=0;
						break;
					}
					printf("\n\tEnter 1 to continue 0 to exit: ");
					scanf("%d",&cresponse);
				}while(cresponse!=0);
				break;
	case 2:	printf("\n\tEnter the number of Vertices in Adjacency list: ");
				 	scanf("%d",&v);
				 	for(i=0;i<v;i++){
				 		//scanf("%d",&head[i].vertex);
						head[i].vertex = i;
						head[i].next = NULL;
					}
					create_al(head,v);
				 	printAdj_list(head,v);
					do{
					do{
					printf("--------------------------TRAVERSAL CHOICE--------------------------");
					printf("\n\t1. BFS \t2. DFS\t0. Exit");
					printf("\n\tYour choice? ");
					scanf("%d",&tchoice);
				}while(tchoice<0||tchoice>2);
				switch (tchoice) {
					case 1:do{
						printf("Enter the source vertext:(0 - %d) ",v-1);
						scanf("%d",&src);
							}while(src<0||src>v-1);
						printf("\n\tBreadth First search is: \n");
						bfs_adj_list(head,src);
						break;
				case 2:do{
							printf("Enter the source vertext:(0 - %d) ",v-1);
							scanf("%d",&src);
							}while(src<0||src>v-1);
					printf("\nThe depth first search is: \n");
					dfs_adj_list(head,src,VISITED);
					for(int i=0;i<MX;i++)
						VISITED[i]=0;
					break;
						}
				printf("\n\tEnter 1 to continue 0 to exit: ");
				scanf("%d",&cresponse);
			}while(cresponse!=0);
			break;
		}
		printf("\n\tEnter 1 to Main menu 0 to exit: ");
		scanf("%d",&opt);
}while(opt!=0);
	printf("You Opted to Exit.\n");
return 0;
}

/*
	EXECUTION TRAIL
	----------------------GRAPH ADT (IMPLEMENTATION CHOICE)----------------------
	1. Adjacency Matrix 		2.Adjacency List
	Enter your choice? 1

	 Enter no of vertices: 5

	Enter 0 for directed 1 for undirected: 1

Vertices starts at 0 and ends at 4
	Vertex ID of -1 Terminates the input
------------------------------------
Edge# uVertex# vVertex# Remark
------------------------------------
   1	0	1

			Edge taken.
   2	0	2

			Edge taken.
   3	0	3

			Edge taken.
   4	0	4

			Edge taken.
   5	1	2

			Edge taken.
   6	1	3

			Edge taken.
   7	1	4

			Edge taken.
   8	2	3

			Edge taken.
   9	2	4

			Edge taken.
  10	3	4

			Edge taken.
  11	-1	-1


Adjacency Matrix is.....

	 u|v |   0   1   2   3   4
	 -------------------------
	 0  |   0   1   1   1   1
	 1  |   1   0   1   1   1
	 2  |   1   1   0   1   1
	 3  |   1   1   1   0   1
	 4  |   1   1   1   1   0
--------------------------TRAVERSAL CHOICE--------------------------
	1. BFS 	2. DFS	0. Exit
	Your choice? 1
Enter the source vertext:(0 - 4) 0

	Breadth First search is: 
   0   1   2   3   4
	Enter 1 to continue 0 to exit: 1
--------------------------TRAVERSAL CHOICE--------------------------
	1. BFS 	2. DFS	0. Exit
	Your choice? 2
Enter the source vertext:(0 - 4) 4
The depth first search is: 
   4   0   1   2   3
	Enter 1 to continue 0 to exit: 0

	Enter 1 to Main menu 0 to exit: 1

----------------------GRAPH ADT (IMPLEMENTATION CHOICE)----------------------
	1. Adjacency Matrix 		2.Adjacency List
	Enter your choice? 2

	Enter the number of Vertices in Adjacency list: 5

	Vertexs available are:    0   1   2   3   4
	Enter 0 for directed 1 for undirected: 1

	Vertex ID of -1 Terminates the input
------------------------------------
Edge# uVertex# vVertex# Remark
------------------------------------
   1	0	1

				Edge taken
   2	0	2

				Edge taken
   3	0	3

				Edge taken
   4	0	4

				Edge taken
   5	1	2

				Edge taken
   6	1	3

				Edge taken
   7	1	4

				Edge taken
   8	2	3

				Edge taken
   9	2	4

				Edge taken
  10	3	4

				Edge taken
  11	-1	-1

	0 [140735131598000]	1 [35158224]	2 [35158288]	3 [35158352]	4 [35158416]	

	1 [140735131598016]	0 [35158256]	2 [35158480]	3 [35158544]	4 [35158608]	

	2 [140735131598032]	0 [35158320]	1 [35158512]	3 [35158672]	4 [35158736]	

	3 [140735131598048]	0 [35158384]	1 [35158576]	2 [35158704]	4 [35158800]	

	4 [140735131598064]	0 [35158448]	1 [35158640]	2 [35158768]	3 [35158832]	
--------------------------TRAVERSAL CHOICE--------------------------
	1. BFS 	2. DFS	0. Exit
	Your choice? 1
Enter the source vertext:(0 - 4) 0

	Breadth First search is: 
	0	1	2	3	4
	Enter 1 to continue 0 to exit: 1
--------------------------TRAVERSAL CHOICE--------------------------
	1. BFS 	2. DFS	0. Exit
	Your choice? 2
Enter the source vertext:(0 - 4) 4

The depth first search is: 
	4	0	1	2	3
	Enter 1 to continue 0 to exit: 0

	Enter 1 to Main menu 0 to exit: 0
You Opted to Exit.


*/
