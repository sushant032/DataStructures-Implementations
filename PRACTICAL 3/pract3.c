/**
    Filename:pract3.c
    Author:Sushant Kumar
    Date:10-August-2017
    Aim: To study and implement the divide-and-conquer sorting methods – Merge, Quick, and Heap.
	Problem 
	Statement:	Using the utility functions created in Experiment-2, write a menu driven program to order a list in ascending order 
				using following “ divide-and-conquer” approaches – the Quick Sort, the Heap Sort, and the Merge Sort.
				You should compare the running time for ordering lists different input sizes in respect of
				traditional comaprison sorts and divide-and-conquer sorts.
*/

/* Header file inclusion*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"dspd.h"
/* Pre-processor diectives declaration*/
#define SWAP(a,b,t) {t=a;a=b;b=t;}
#define MAX_SIZE 1000000

/* Function prototype declaration*/
void quickSort(int *,int , int );
int partition(int *, int, int );
void merge(int arr[],int l,int m,int h);
void mergeSort(int arr[],int low,int high);
int right(int i);
int left(int i);
int parent(int i);
void maxHeapify(int *,int ,int *);
void buildMaxHeap(int *,int ,int *);
void heapSort(int *,int ,int *);
/* The main fucntion */
int main(){
	    int *lst,*cpy, n,mode,continueResponse,sortChoice,i,heapSize;
	    time_t begin, end;
	    double elapsedT;
    	struct time_analysis{
    		double time;
    		char sort[20];
    	}t[8];
    do{
		do{
			n = get("the length in multiples of 10 (MaxSize: 1m)");
		}while(n<1||n>MAX_SIZE||n%10!=0);
		
		printf("\n\tArray creation mode");
		printf("\n\t1. Ascending 2. Descending 3. Partial \n\t4. Random");
		
		
		
		do{
			mode = get("the mode");
		}while(mode<1||mode>4);
		
		lst = calloc(n,sizeof(int));
    	cpy = calloc(n,sizeof(int));
    	
    createArr(lst,&n,&mode);
    copyArr(lst,cpy,&n);
    for(sortChoice=1;sortChoice<10;sortChoice++)
        switch(sortChoice){
        case 1: printf("\n\tBubble Sort in progress...");
        		begin = clock();
        		bubbleSort(lst,&n);
        		end = clock();
        		t[1].time = ((double)end - begin)/CLOCKS_PER_SEC;
                strcpy(t[1].sort,"Bubble");
                   copyArr(cpy,lst,&n);
              	   break;
        case 2:	printf("\n\tSelection Sort in progress...");
        		begin = clock();
        		selectionSort(lst,&n);
        		end = clock();
        		t[2].time = ((double)end - begin)/CLOCKS_PER_SEC;
                strcpy(t[2].sort,"Selection");
                   copyArr(cpy,lst,&n);
                   
                   break;
        case 3:printf("\n\tShell Sort in progress...");
        		begin = clock();
        		shellSort(lst,&n);
        		end = clock();
        		t[3].time = ((double)end - begin)/CLOCKS_PER_SEC;
                strcpy(t[3].sort,"Shell");
                   copyArr(cpy,lst,&n);
                   
                   break;
        case 4: printf("\n\tBucket Sort in progress...");
        		begin = clock();
        		bucketSort(lst,&n);
           		end = clock();
				t[4].time = ((double)end - begin)/CLOCKS_PER_SEC;
                strcpy(t[4].sort,"Bucket");
                   copyArr(cpy,lst,&n);
                   
                   break;
        case 5:printf("\n\tInsertion Sort in progress...");
        		begin = clock();
        		insertionSort(lst,&n);
        		end = clock();
				t[5].time = ((double)end - begin)/CLOCKS_PER_SEC;
                strcpy(t[5].sort,"Insertion");
                   copyArr(cpy,lst,&n);
                   
                   break;
        case 6:printf("\n\tQuick Sort in progress...");
        		begin = clock();
        		quickSort(lst,0,n-2);
        		end = clock();
        		t[6].time = ((double)end - begin)/CLOCKS_PER_SEC;
                strcpy(t[6].sort,"Quick");
        		   copyArr(cpy,lst,&n);
        		   
        		   break;
        case 7:printf("\n\tMerge Sort in progress...");
        		begin = clock();
        	   	mergeSort(lst,0,n-1);
        		end = clock();
        		display(lst,&n);
        		t[7].time = ((double)end - begin)/CLOCKS_PER_SEC;
                strcpy(t[7].sort,"Merge ");
        		   copyArr(cpy,lst,&n);
        		   break;
          case 8:printf("\n\tHeap Sort in progress...");
          		heapSize=0;
          		begin = clock();
        		heapSort(lst,n,&heapSize);
        		end = clock();
        		t[8].time = ((double)end - begin)/CLOCKS_PER_SEC;
                strcpy(t[8].sort,"Heap");
        		   copyArr(cpy,lst,&n);
        		   
        		   break;
        }
        
   printf("\n\tThe Time analysis of all the 8 sort gives following results: ");
   		
   		for(i=1;i<9;i++)
   		printf("\n\t [%d] %s Sort \n\t\tTime taken = %10f\n",i,t[i].sort,t[i].time);
    
    printf("\n\tPress 0 to exit or 1 to continue! ");
    continueResponse = get("the continue response(0 to exit)");
    
    }while(continueResponse!=0);
    if(continueResponse == 0)
    	exit(1);
return 0;
}
/* Quick Sort*/
int partition(int arr[],int p, int r){
	
	int x = arr[r],i=p-1,t,j;
	for(j=p;j<=r-1;j++)
	{
		if(arr[j]<=x)
		{
			i=i+1;
			SWAP(arr[i],arr[j],t);
		}	
	}
	SWAP(arr[i+1],arr[r],t);
	
	return i+1;	
}

void quickSort(int arr[],int p, int r){
	int q;
	if(p<r){
	q = partition(arr,p,r);
	quickSort(arr,p,q-1);
	quickSort(arr,q+1,r);
	}
}
/*Merge Sort*/
void merge(int arr[], int low, int mid, int high)
{
  
  int n1,n2,i,j,k;
  int L[MAX_SIZE/2],R[MAX_SIZE/2];
  n1=mid-low+1;
  n2=high-mid;
  
  for(i=0; i<n1; i++)
    L[i]=arr[low+i];
  for(j=0; j<n2; j++)
    R[j]=arr[mid+j+1];

  L[i]=99999999;  
  R[j]=99999999;

  i=0;
  j=0;
  for(k=low; k<=high; k++) {
    if(L[i]<=R[j])
      arr[k]=L[i++];
    else
      arr[k]=R[j++];
}

}
  
void mergeSort(int a[], int low, int high)
{
    if (low < high) {
        int m = (high + low)/2;
        mergeSort(a, low, m);
        mergeSort(a, m + 1, high);
        merge(a, low, m, high);
    }
}
/*Heap Sort*/
int parent(int i){
	return i/2;
}

int left(int i){
	return 2*i;
}

int right(int i){
	return (2*i+1);
}

void maxHeapify(int arr[],int i,int *heapSize){
	int l,r,largest,t;
	l = left(i);
	r = right(i);
	if(l<=*heapSize && arr[l]>arr[i])
		largest = l;
	else
		largest = i;
	if(r<=*heapSize && arr[r]>arr[largest])
		largest = r;
	else
		largest = i;
	if(largest != i){
	SWAP(arr[i],arr[largest],t);
	maxHeapify(arr,largest,heapSize);
	}
}

void buildMaxHeap(int arr[],int length,int *heapSize){
	int i;
	*heapSize = length-1;
	for(i=length/2;i>=0;i--)
		maxHeapify(arr,i,heapSize);
}
void heapSort(int arr[],int length,int *heapSize){
	int i,t;
	buildMaxHeap(arr,length,heapSize);
	for(i=length-1;i>0;i--){
		SWAP(arr[1],arr[i],t);
	}
}
/*	Execution Trail
	Please enter the the length in multiples of 10 (MaxSize: 1m):100000

	Array creation mode
	1. Ascending 2. Descending 3. Partial 
	4. Random
	Please enter the the mode:1

	List created!
	Bubble Sort in progress...
	Selection Sort in progress...
	Shell Sort in progress...
	Bucket Sort in progress...
	Insertion Sort in progress...
	Quick Sort in progress...
	Merge Sort in progress...
	Heap Sort in progress...
	The Time analysis of all the 8 sort gives following results: 
	 [1] Bubble Sort 
		Time taken =  13.426416

	 [2] Selection Sort 
		Time taken =  11.669432

	 [3] Shell Sort 
		Time taken =   0.006740

	 [4] Bucket Sort 
		Time taken =   0.035840

	 [5] Insertion Sort 
		Time taken =   0.000455

	 [6] Quick Sort 
		Time taken =  21.530132

	 [7] Merge  Sort 
		Time taken =   0.010773

	 [8] Heap Sort 
		Time taken =   0.001895

	Press 0 to exit or 1 to continue! 
	Please enter the the continue response(0 to exit):1

	Please enter the the length in multiples of 10 (MaxSize: 1m):100000

	Array creation mode
	1. Ascending 2. Descending 3. Partial 
	4. Random
	Please enter the the mode:2

	List created!
	Bubble Sort in progress...
	Selection Sort in progress...
	Shell Sort in progress...
	Bucket Sort in progress...
	Insertion Sort in progress...
	Quick Sort in progress...
	Merge Sort in progress...
	Heap Sort in progress...
	The Time analysis of all the 8 sort gives following results: 
	 [1] Bubble Sort 
		Time taken =  24.180582

	 [2] Selection Sort 
		Time taken =  23.486612

	 [3] Shell Sort 
		Time taken =   0.009451

	 [4] Bucket Sort 
		Time taken =   0.035885

	 [5] Insertion Sort 
		Time taken =  15.068240

	 [6] Quick Sort 
		Time taken =  18.286632

	 [7] Merge  Sort 
		Time taken =   0.010751

	 [8] Heap Sort 
		Time taken =   0.000934

	Press 0 to exit or 1 to continue! 
	Please enter the the continue response(0 to exit):1

	Please enter the the length in multiples of 10 (MaxSize: 1m):100000

	Array creation mode
	1. Ascending 2. Descending 3. Partial 
	4. Random
	Please enter the the mode:3

	List created!
	Bubble Sort in progress...
	Selection Sort in progress...
	Shell Sort in progress...
	Bucket Sort in progress...
	Insertion Sort in progress...
	Quick Sort in progress...
	Merge Sort in progress...
	Heap Sort in progress...
	The Time analysis of all the 8 sort gives following results: 
	 [1] Bubble Sort 
		Time taken =  14.283202

	 [2] Selection Sort 
		Time taken =  12.703697

	 [3] Shell Sort 
		Time taken =   0.009123

	 [4] Bucket Sort 
		Time taken =   0.035656

	 [5] Insertion Sort 
		Time taken =   0.947338

	 [6] Quick Sort 
		Time taken =   3.173897

	 [7] Merge  Sort 
		Time taken =   0.016211

	 [8] Heap Sort 
		Time taken =   0.002455

	Press 0 to exit or 1 to continue! 
	Please enter the the continue response(0 to exit):100000

	Please enter the the length in multiples of 10 (MaxSize: 1m):100000

	Array creation mode
	1. Ascending 2. Descending 3. Partial 
	4. Random
	Please enter the the mode:4

	List created!
	Bubble Sort in progress...
	Selection Sort in progress...
	Shell Sort in progress...
	Bucket Sort in progress...
	Insertion Sort in progress...
	Quick Sort in progress...
	Merge Sort in progress...
	Heap Sort in progress...
	The Time analysis of all the 8 sort gives following results: 
	 [1] Bubble Sort 
		Time taken =  33.344865

	 [2] Selection Sort 
		Time taken =  33.086508

	 [3] Shell Sort 
		Time taken =   0.030283

	 [4] Bucket Sort 
		Time taken =   0.057897

	 [5] Insertion Sort 
		Time taken =   7.775777

	 [6] Quick Sort 
		Time taken =   0.015246

	 [7] Merge  Sort 
		Time taken =   0.016577

	 [8] Heap Sort 
		Time taken =   0.001890

	Press 0 to exit or 1 to continue! 
	Please enter the the continue response(0 to exit):0

		Please enter the the length in multiples of 10 (MaxSize: 1m):1000000

	Array creation mode
	1. Ascending 2. Descending 3. Partial 
	4. Random
	Please enter the the mode: 4

	List created!
	Bubble Sort in progress...
	Selection Sort in progress...
	Bucket Sort in progress...
	Insertion Sort in progress...
	Quick Sort in progress...
	Merge Sort in progress...
	Heap Sort in progress...
	The Time analysis of all the 8 sort gives following results: 
	 [1] Bubble Sort 
		Time taken = 3282.323100

	 [2] Selection Sort 
		Time taken = 3397.830992

	 [3] Shell Sort 
		Time taken =   0.424820

	 [4] Bucket Sort 
		Time taken =   0.561480

	 [5] Insertion Sort 
		Time taken = 792.780435

	 [6] Quick Sort 
		Time taken =   0.182339

	 [7] Merge  Sort 
		Time taken =   0.187659

	 [8] Heap Sort 
		Time taken =   0.019976

	Press 0 to exit or 1 to continue! 


*/
