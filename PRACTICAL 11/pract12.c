/*
  Author: SUSHANT KUMAR
  Aim: To demonstrate different shortest path algorithms - Warshall's Algorithm (Path Matrix)
  and Dijkstra's Algorithm
  Probelm Statement: Create an arbitrary graph with a minimum of 8 nodes. Using “ graphs.h” , implement the
  routines to (1) find shortest path matrix using Warshall's algorithm, and (2) find shortest path between vertices using Dijkstra's algorithm.
  Additioally, add routine(s) to create minimum cost spanning tree of the graph using (1)
  Prim's method, and/or (2) Kruskal's method.
  Write a menu driven program to implement the solution. You must include other utility
  functions in the menu.

*/

#include<stdio.h>
#include <stdlib.h>
#include "pract12.h"
int main(){
  int AdjMat[MX][MX];
  populateMat(AdjMat,INF);
	int u,v,i,j,w,type,count=1,src,k,opt;
  int VISITED[MX] = {0};
  int distMat[MX][MX]={0};
  populateMat(distMat,INF);

  int next[MX][MX]={0};
  populateMat(next,-1);
  w = create_am(AdjMat);

  do{
    printf("\n=================Algorithm Choice=================\n");
    printf("1. Floyed Warshall  2. Dijkstra\n");
    printf("Your choice? ");
    scanf("%d",&opt);
    switch (opt) {
      case 0:printf("\nYou opted to exit!\n");
              break;
      case 1:floyed(distMat,next,AdjMat,w);
              break;
      case 2:printf("Enter the source vertex :");
             scanf("%d",&src);
             graph_Dijkstra(AdjMat,w,src);
              break;

    }
  }while(opt!=0);
}
/* Execution Trail

Enter no of vertices: 7

Enter 0 for directed 1 for undirected: 1

Vertices starts at 0 and ends at 6
Vertex ID of -1 Terminates the input
------------------------------------
Edge# uVertex# vVertex# #cost Remark
------------------------------------
1	0	1	4

     Edge taken.
2	0	2	9

     Edge taken.
3	0	3	5

     Edge taken.
4	1	2	4

     Edge taken.
5	2	5	8

     Edge taken.
6	1	4	9

     Edge taken.
7	3	4	5

     Edge taken.
8	3	5	7

     Edge taken.
9	5	6	2

     Edge taken.
10	5	4	3

     Edge taken.
11	4	6	3

     Edge taken.
12	-1	-1	5

=================Algorithm Choice=================
1. Floyed Warshall  2. Dijkstra
Your choice? 2
Enter the source vertex :0

Displaying Distance matrix:
  999     999     999     999     999     999     999

Displaying Previous matrix:
   -1      -1      -1      -1      -1      -1      -1

Displaying Visited matrix:
    0       0       0       0       0       0       0

Displaying Queue matrix:
    0       1       2       3       4       5       6
U calculated is 1
Distance is changed from 9 to 8
Distance is changed from 999 to 13
U calculated is 3
Distance is changed from 13 to 10
Distance is changed from 999 to 12
U calculated is 2
U calculated is 4
Distance is changed from 999 to 13
U calculated is 5

......After...............

Displaying Distance matrix:
    0       4       8       5      10      12      13

Displaying Previous matrix:
   -1       0       1       0       3       3       4

Displaying Visited matrix:
    1       1       1       1       1       1       0

=================Algorithm Choice=================
1. Floyed Warshall  2. Dijkstra
Your choice? 1
intial:

Distance Matrix is.....

u|v |   0   1   2   3   4   5   6
---------------------------------
0  | 999 999 999 999 999 999 999
1  | 999 999 999 999 999 999 999
2  | 999 999 999 999 999 999 999
3  | 999 999 999 999 999 999 999
4  | 999 999 999 999 999 999 999
5  | 999 999 999 999 999 999 999
6  | 999 999 999 999 999 999 999

Path Matrix is.....

u|v |   0   1   2   3   4   5   6
---------------------------------
0  |  -1  -1  -1  -1  -1  -1  -1
1  |  -1  -1  -1  -1  -1  -1  -1
2  |  -1  -1  -1  -1  -1  -1  -1
3  |  -1  -1  -1  -1  -1  -1  -1
4  |  -1  -1  -1  -1  -1  -1  -1
5  |  -1  -1  -1  -1  -1  -1  -1
6  |  -1  -1  -1  -1  -1  -1  -1

Adjacency Matrix is.....

u|v |   0   1   2   3   4   5   6
---------------------------------
0  | 999   4   9   5 999 999 999
1  |   4 999   4 999   9 999 999
2  |   9   4 999 999 999   8 999
3  |   5 999 999 999   5   7 999
4  | 999   9 999   5 999   3   3
5  | 999 999   8   7   3 999   2
6  | 999 999 999 999   3   2 999

Distance Matrix is.....

u|v |   0   1   2   3   4   5   6
---------------------------------
0  |   0   4   9   5 999 999 999
1  |   4   0   4 999   9 999 999
2  |   9   4   0 999 999   8 999
3  |   5 999 999   0   5   7 999
4  | 999   9 999   5   0   3   3
5  | 999 999   8   7   3   0   2
6  | 999 999 999 999   3   2   0

Cost Matrix is.....

u|v |   0   1   2   3   4   5   6
---------------------------------
0  |   0   4   8   5  10  12  13
1  |   4   0   4   9   9  12  12
2  |   8   4   0  13  11   8  10
3  |   5   9  13   0   5   7   8
4  |  10   9  11   5   0   3   3
5  |  12  12   8   7   3   0   2
6  |  13  12  10   8   3   2   0

Path Matrix is.....

u|v |   0   1   2   3   4   5   6
---------------------------------
0  |   0   1   1   3   3   3   3
1  |   0   1   2   0   4   2   4
2  |   1   1   2   1   5   5   5
3  |   0   0   0   3   4   5   4
4  |   3   1   5   3   4   5   6
5  |   3   2   2   3   4   5   6
6  |   4   4   5   4   4   5   6
Enter the source Vertex:
0


Path between 0 and  each vertex are:
1    :   0->    1->
2    :   0->    1->   2->
3    :   0->    3->
4    :   0->    3->   4->
5    :   0->    3->   5->
6    :   0->    3->   4->   6->

*/
