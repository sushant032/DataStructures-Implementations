/**
    Filename:pract1.c
    Author:Sushant Kumar
    Date:20-July-2017
    Aim:To study an Array ADT and to implement various operations on an array ADT.
    Problem Statement:Create and array and implement the operations - traverse(), insert_element(), delete_element(),sort(),   searc(),merge(), copy(),create(),isfull(), isempty() and length(). Write a C program to demonstrate an array ADT using defined operations appropriately using a menu driven approach . Your program should be able to print the array contents appropriately at any or all instances(as required may be). You must also ensure that no input is acquired within the body of functions,nor    (preferably) display any prompts/results.
*/

/* Header file inclusion*/
#include<stdio.h>

/* Pre-processor diectives declaration*/
#define max_size 10
#define min_value -999

/* Function prototype declaration*/
void initialize(int *);
int length(int *);
int isFull(int *);
int isEmpty(int *);
int getValue(char *);
int insertElement(int *, int, int,int);
int create(int arr[]);
void display(int arr[],int);
int del(int *,int,int);
int search(int *,int);
void sort(int *,int);
void copy(int *, int *,int);
int merge(int *,int *,int *,int);
void traverse(int *);
/* The main function*/

int main(){
	int response,arr[max_size],result,cpy[max_size]={0},mergedArray[2*max_size]={0},index,value;
	int arr2[max_size]={11,12,13,14,15,16,-999};
	int Glen=0,Mlen=0;
	initialize(arr);
	do{
		printf("\n\tThe list of operations you can perform on the Array ADT.\n");
		printf("\n\t1. Create\t2. Length\t3. isFull\n");
        printf("\t4. isEmpty\t5. Display\t6. Insert\n");
        printf("\t7. Delete\t8. Search\t9. Sort\n");
        printf("\t10. Copy\t11. Merge\t12. Traverse\n");
        printf("\t0. EXIT\n");
        printf("\t Enter your response? ");
        scanf("%d",&response);
        switch(response){
			case 0:printf("\tYou opted to exit!\n");break;
			case 1:Glen = create(arr);break;
        	case 2: printf("\tLength of the array is: %d\n",length(arr));break;
        	case 3:if(isFull(arr))
        			printf("\t%d The array is full.\n",isFull(arr));
        		   else
        		   	printf("\t%d The array is not full.\n",isFull(arr));
        		   break;
        	case 4:if(isEmpty(arr))
        			printf("\t%d The array is Empty.\n",isEmpty(arr));
        		   else
        		   	printf("\t%d The array is not Empty.\n",isEmpty(arr));
       		   	   break;
       		case 5:printf("\tThe elements in the array are:\n\t");
       			   display(arr,Glen);
       			   printf("\n");
       			   break;
			case 6: printf("\tArray bounds are 0-%d\n",Glen);
						do{
						index = getValue("the index: ");
						}while(index>Glen);
						do{
						value = getValue("the value: ");
						}while(value<=min_value);
					
					Glen = insertElement(arr,index,value,Glen);
       			   break;
       		case 7: if(isEmpty(arr)!=1){
						printf("\tArray bounds are (0-%d)\n",Glen-1);
						do{
						index = getValue("the index: ");
						}while(index>Glen-1);
       				Glen  = del(arr,index,Glen);
       				}else{
       					printf("\n\tThe array is empty!");
       				}
       			   break;
       		case 8:result = search(arr,getValue("the vaule to search for: "));
       				if(result==-1)
       					printf("\tThe element does not exist in the array!");
       				else
       					printf("\tElement found at index = %d",result);
       			   break;
        	case 9:sort(arr,Glen);
       			   break;
       		case 10:copy(arr, cpy, Glen);
       				printf("\tThe elements in the copied array are\n\t");
               		display(cpy,Glen);
       			   break;

 			case 11:Mlen = merge(arr,arr2,mergedArray,Glen);
 					printf("\tThe elements in the merged array are\n\t");
 					display(mergedArray,Mlen);
                   break;
            case 12:traverse(arr);
                   break;
       
        }
	}while(response!=0);
}
void initialize(int arr[]){
	arr[0]=min_value;
}
int length(int arr[]){
	int i;
	for(i=0;i<max_size&&arr[i]!=min_value;i++);
	return i;
}
int isFull(int arr[]){
	if(length(arr)==max_size)
		return 1;
	return 0;
}
int isEmpty(int arr[]){
	if(length(arr)==0)
		return 1;
	return 0;
}
int getValue(char *string){
	int value;
	printf("\tPlease enter %s",string);
	scanf("%d",&value);
	return value;
}
int insertElement(int arr[], int index, int value,int len){
    int i;
    for(i=len+1;i>index;i--)
	    arr[i] = arr[i-1] ;
    arr[i] = value;
    return len+1;
}
int create(int arr[]){
	int len,value;
	len = length(arr);
	do{


		if(len < max_size)
			{
			value = getValue("the element value: ");
			insertElement(arr,len,value,len);
			}
		else{
			printf("\tArray Bounds Reached.\n");
			}
		len++;
	}while(value!=min_value && len<=max_size);
	return len-1;
}
void display(int arr[],int len){
	int i;
	for(i=0;i<len;i++)
		printf("%d ",arr[i]);

}
int del(int arr[],int index,int len){
	int i;
	for(i=index;i<len-1;i++)
	 arr[i] = arr[i+1];
	arr[i]=-999;
	return len-1;
}
int search(int arr[],int value){
	int len = length(arr),i;
	for(i=0;i<len;i++)
		if(arr[i]==value)
		return i;
	return -1;
}
/*Selection Sort*/
void sort(int arr[],int len){
	int i,j,t,minPos;
	for(i=0;i<len-1;i++){
	    minPos = i;
	    for(j=i+1;j<len;j++)
			if(arr[i]>arr[j]){
			minPos = j;
				t = arr[j];
				arr[j]=arr[i];
				arr[i]=t;
			}
	}		
}
void copy(int arr[], int dest[],int len){
	int i;
		for(i=0;i<=len;i++)
			dest[i]=arr[i];	
}

 int merge(int arr[],int arr2[],int mergedArray[],int len1){
    int len2=length(arr2),i,count;
    for(i=0,count=0;count<len1+len2;count++,i++){
            if(count<len1)
                mergedArray[count] = arr[i];
            if(count==len1)
                    i=0;
            if(count>=len1)
                mergedArray[count] = arr2[i];
    }
    return count;
 }
 
 void traverse(int arr[]){
    int len = length(arr),i;
    for(i=0;i<len;i++)
        if(i%2==0)
            arr[i]+=100;
        else
            arr[i]+=50;
 }

