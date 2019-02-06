#define SWAP(a,b,t) {t=a;a=b;b=t;}
void bubbleSort(int arr[],int *len){
    int i,j,flag,t;
    for(i=1;i<*len;i++){
        flag=0;
        for(j=0;j<(*len)-i;j++)
            if(arr[j]>arr[j+1])
                SWAP(arr[j],arr[j+1],t);
                flag=1;
            if(flag==0)
                break;

        }
}
void selectionSort(int arr[],int *len){
    int i,j,t,minPos;
	for(i=0;i<*len-1;i++){
	    minPos = i;
	    for(j=i+1;j<*len;j++)
			if(arr[i]>arr[j]){
			minPos = j;
				SWAP(arr[j],arr[i],t);
			}
	}
}

void shellSort(int arr[],int *len){
    int i,j,gap,key;

    for(gap=*len/2;gap>0;gap/=2)
    for(i=gap;i<*len;i++){
        key = arr[i];
        for(j=i;j>=gap&&arr[j-gap]>key;j-=gap)
            arr[j]=arr[j-gap];
        arr[j]=key;

    }
}
void bucketSort(int arr[],int *len){
    int flag=0,i,pos,k,j,m;
    
    int *bucket[10];
 	   for(i=0;i<10;i++)
 	   	bucket[i] = (int *)malloc(*len * sizeof(int));
    
    for(pos=1;flag!= *len;pos*=10){
        flag = 0;
        for(k=0;k<*len;k++){
            bucket[(arr[k]/pos)%10][k]=arr[k];
        if((arr[k]/pos)%10==0)
            flag++;            
        }
    if(flag==*len)
        return;
    for(j=0,m=0;j<10;j++){
        for(k=0;k<*len;k++){
            if(bucket[j][k]>0){
            arr[m]=bucket[j][k];
            bucket[j][k]=0; 
            m++;
           }
        }
        
      }
      
   }
}

void insertionSort(int arr[], int *len){
    int key,j,i;
    for(j=1;j<*len;j++){
        key = arr[j];
        i=j-1;
        while(i>=0&&arr[i]>key){
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
    }
}
void display(int arr[],int *len){
    int i;
    printf("\n\tContents after sorting are:\n\t");
    for(i=0;i<*len;i++){
        if(i%6==0)
        	printf("\n\t");
        printf("%d\t",arr[i]);
		}
}

int get(char *string){
    int val;
    printf("\n\tPlease enter the %s:", string);
    scanf("%d",&val);
    return val;
}
void copyArr(int arr[], int dest[],int *len){
	int i;
		for(i=0;i<=*len;i++)
			dest[i]=arr[i];		
}
void createArr(int arr[],int *len, int *mode){
	int offset,i;

	switch(*mode){
		case 1: offset = 100000;
				for(i=0;i<*len;i++)
					arr[i] = offset + 43*i;
				break;
		
		case 2: offset = 9999999;
				for(i=0;i<*len;i++)
					arr[i] = offset - 3*i;
				break;
		
		case 3: offset = 100000;
				for(i=0;i<*len;i++){
					if(i%5==0)
						arr[i] = 11114 + 33*i;
					else
						arr[i] = offset + 50*i;
						}
				break;
		
		case 4: offset = 100000;
				srandom(14856);
				for(i=0;i<*len;i++)
					arr[i] = random()/14523;
				break;
				
	}
	printf("\n\tList created!");
}
