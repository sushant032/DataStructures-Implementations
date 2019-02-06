#define MX 50
#define INF 999
void display_path(int next[][MX],int src,int dest){

    if(next[src][dest]==-1){
        printf("Path does not exists between %d to %d\n",src,dest);
        return;
    }
    printf("%4d-> ",src);
    while(src!=dest){
        src=next[src][dest];
        printf("%4d->",src);
    }
 }
void displayArr(int arr[],int w,char * s){
	printf("\nDisplaying %s matrix: \n",s);

		for(int i=0;i<w;i++){
			printf("%8d",arr[i] );
		}
		printf("\n");
}
int find_min_dist(int dist[],int vertices,int visited[])
{
 int i,min_dist=INF,min_pos=-1;
 for(i=0;i<vertices;i++)
 {
    if(dist[i]<min_dist && !visited[i])
    {
        min_dist=dist[i];
        min_pos=i;
    }
 }

 return min_pos;
}
 void graph_Dijkstra(int graph[][MX],int vertices,int src)
 {
    int u,w,i,alt;
    int dist[MX],visited[MX],pre[MX],q[MX];
    for(i=0;i<vertices;i++)
    {
        dist[i]=INF;
        pre[i]=-1;
        visited[i]=0;
        q[i]=i;
    }
    displayArr(dist,vertices,"Distance");
    displayArr(pre,vertices,"Previous");
    displayArr(visited,vertices,"Visited");
    displayArr(q,vertices,"Queue");
    for(i=0;i<vertices;i++)
    {
    dist[i]=graph[src][i];
    if(dist[i]!=INF)
        pre[i]=src;
     }//initial settting of Matrices
    dist[src]=0;
    visited[src]=1;//first is always zero unles there is self loop at source
    i=vertices-1;
    while(i!=1)
    {        //while Q is not empty
        u=find_min_dist(dist,vertices,visited);
        printf("U calculated is %d\n",u);
        if(u==-1)
        {
            printf("No Path from the vertex\n");
            continue;
        }
        visited[u]=1;
        for(w=0;w<vertices;w++)
        {
        alt=dist[u]+graph[u][w];
            if(!visited[w])
            {
                if(alt<dist[w])
                {
                    printf("Distance is changed from %d to %d\n",dist[w],alt);
                    dist[w]=alt;
                    pre[w]=u;
                }
            }
        }
    i--;//removed from Queue
    }
    printf("\n......After...............\n");
    displayArr(dist,vertices,"Distance");
    displayArr(pre,vertices,"Previous");
    displayArr(visited,vertices,"Visited");

    return;
}

int create_am(int AdjMat[][MX]){
	int w,type,count=1,u,v,weight;
	printf("\n\t Enter no of vertices: ");
	scanf("%d",&w);
	printf("\n\tEnter 0 for directed 1 for undirected: ");
	scanf("%d",&type);
	printf("\nVertices starts at 0 and ends at %d",w-1);
	printf("\n\tVertex ID of -1 Terminates the input");
	printf("\n------------------------------------");
	printf("\nEdge# uVertex# vVertex# #cost Remark");
	printf("\n------------------------------------\n");
	do{
		do{
		printf("%4d\t",count);
		scanf("%d%d%d",&u,&v,&weight);
		if(u == v && weight < 0)
		printf("\n\t\t\t\t\tNegative Cycle\n");
		if(u>=w||v>=w)
			printf("\n\t\t\t\t\tInvalid edge.\n");
		}while((u==v)&&u<w&&v>w&&u<0&&v<0);

		if(u==-1||v==-1)
			break;

		if(AdjMat[u][v]==INF){
			if(type)
				AdjMat[u][v]=AdjMat[v][u]=weight;
			else
				AdjMat[u][v]=weight;
			printf("\n\t\t\t\tEdge taken.\n");
			count++;
		}else{
			printf("\n\t\t\t\tEdge already taken.\n");
		}
	}while( u!=-1 && v!=-1);
return w;
}

void printAM(int AdjMat[][MX],int w,char *str){
	int i,j;
	printf("\n\t%s Matrix is.....\n\n",str);
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

void populateMat(int mat[][MX],int val){
	for(int i=0;i<MX;i++)
		for(int j=0;j<MX;j++)
			mat[i][j]=val;
}

void floyed(int distMat[MX][MX],int next[MX][MX],int AdjMat[MX][MX],int w){
int m,i,j,k;
 printf("intial:\n");
 printAM(distMat,w,"Distance");
 printAM(next,w,"Path");
 printAM(AdjMat,w,"Adjacency");
 for(i=0;i<w;i++){
	 for(j=0;j<w;j++){
				 if(i==j&&AdjMat[i][j]==INF)
						 distMat[i][j]=0;
					 else
						 distMat[i][j]=AdjMat[i][j];
						 next[i][j] = j;
			 }
		 }

printAM(distMat,w,"Distance");
//FLoyed-Warshall
	 for(k=0;k<w;k++){
		 for(i=0;i<w;i++){
			for(j=0;j<w;j++){
				 if(distMat[i][j] > distMat[i][k] + distMat[k][j]){
						distMat[i][j] = distMat[i][k] + distMat[k][j];
						next[i][j] = next[i][k];
					}
				}
		 }
 }
printAM(distMat,w,"Cost");
printAM(next,w,"Path");
printf("Enter the source Vertex:\n");
			 scanf("%d",&m);
			 printf("\n\nPath between %d and  each vertex are:\n",m);
			 for(i=1;i<w;i++){
				 printf("%-4d :",i);
				 display_path(next,m,i);
				 printf("\n");
				 }

}
