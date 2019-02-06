			/**
			Filename : sorts.c
			Author	 : Sushant Kumar
			Date	 : 3-August-2017
			Aim		 : To study and implement basic comparative sorting methods – Selection, Insertion, Bubble, Shell, and Bucket.
			Problem 
			Statement: Write a generalized function that takes a parameter to indicate the mode (say 1 for decreasing order, 2 for increasing order, 				3 for increasing order with the Nth element out of order, 4 for a randomly generated element values), to create a list of elements. The
			parameter indicating the number of elements in a statically allocated array (the maximum size is large enough to run possible 				iterarations to	test the time complexity, say 1000000) that will be a multiple of 10. Also write appropriate functions to create a copy 			of the list and to display the list contents. Using above functions, write a menu-driven C program to order the list in ascending 				sequence using - the Bubble	Sort, the Insertion Sort, the Selection Sort, the Shell Sort and the Bucket Sort.

		*/

		/* Header file inclusion*/
		#include<stdio.h>
		#include<stdlib.h>

		/* Pre-processor diectives declaration*/
		#define SWAP(a,b,t) {t=a;a=b;b=t;}
		#define MAX_SIZE 1000000

		/* Function prototype declaration*/
		void bubbleSort(int *,int *);
		void selectionSort(int *,int *);
		void shellSort(int *,int *);
		void bucketSort(int *,int *);
		int get(char *);
		void display(int *,int *);
		void copyArr(int *, int *,int *);
		void insertionSort(int *, int *);
		void createArr(int *,int *, int *);
		/*The main function*/
		int main(){
			int *lst,*cpy, n,mode,continueResponse,sortChoice,i;
			do{
				do{
					n = get("the length in multiples of 10 (MaxSize: 1 million)");
				}while(n<1||n>MAX_SIZE||n%10!=0);
		
				printf("\n\tArray creation mode");
				printf("\n\t1. Ascending 2. Descending 3. Partial \n\t4. Random");
		
		
		
				do{
					mode = get("the mode");
				}while(mode<1||mode>4);
		
				lst = (int *)malloc(sizeof(int)*n);
				cpy = (int *)malloc(sizeof(int)*n);
			createArr(lst,&n,&mode);
			copyArr(lst,cpy,&n);
			printf("\n\tDisplaying the list elements:");
			for(i=0;i<n;i++){
				if(i%6==0)
					printf("\n\t");
				printf("%d\t",lst[i]);
			}
		
			do{
				printf("\n\n\tSorting options are:");
				printf("\n\t1. Bubble Sort\t2. Selection Sort\t3. Shell Sort");
				printf("\n\t4. Bucket Sort\t5. Insertion Sort");
				printf("\n\t0. Quit");
			sortChoice = get("your sorting choice");
				switch(sortChoice){
				case 0:printf("\n\tYou opted to exit!");
				       break;
				case 1:bubbleSort(lst,&n);
				       display(lst,&n);
				       copyArr(cpy,lst,&n);
				       break;
				case 2:selectionSort(lst,&n);
				           display(lst,&n);
				           copyArr(cpy,lst,&n);
				           break;
				case 3:shellSort(lst,&n);
				           display(lst,&n);
				           copyArr(cpy,lst,&n);
				           break;
				case 4:bucketSort(lst,&n);
				           display(lst,&n);
				           copyArr(cpy,lst,&n);
				           break;
				case 5:insertionSort(lst,&n);
				           display(lst,&n);
				           copyArr(cpy,lst,&n);
				           break;
				default:
				printf("\tPlease enter a valid choice between 1-5!\n\tPress 0 to Quit.");
				}
			}while(sortChoice!=0);
			printf("\n\tPress 0 to exit or 1 to continue! ");
			continueResponse = get("continue response");
		
			}while(continueResponse!=0);

		}
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
						SWAP(arr[j],arr[i],t)
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
		
				case 2: offset = 99999;
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
		
				case 4: offset = 12;
						srandom(14856);
						for(i=0;i<*len;i++)
							arr[i] = random()/offset;
						break;
				
			}
			printf("\n\tList created!");
		}

		/**			Execution Trail


			Please enter the the length in multiples of 10 (MaxSize: 1 million): 61
			Please enter the the length in multiples of 10 (MaxSize: 1 million): 60
			Array creation mode
			1. Ascending 2. Descending 3. Partial 
			4. Random
			Please enter the the mode: 6
			Please enter the the mode: 3
			List created!
			Displaying the list elements:
			11114	100050	100100	100150	100200	11279	
			100300	100350	100400	100450	11444	100550	
			100600	100650	100700	11609	100800	100850	
			100900	100950	11774	101050	101100	101150	
			101200	11939	101300	101350	101400	101450	
			12104	101550	101600	101650	101700	12269	
			101800	101850	101900	101950	12434	102050	
			102100	102150	102200	12599	102300	102350	
			102400	102450	12764	102550	102600	102650	
			102700	12929	102800	102850	102900	102950	

			Sorting options are:
			1. Bubble Sort	2. Selection Sort	3. Shell Sort
			4. Bucket Sort	5. Insertion Sort
			0. Quit
			Please enter the your sorting choice: 8
			Please enter a valid choice between 1-5!
			Press 0 to Quit.

			Sorting options are:
			1. Bubble Sort	2. Selection Sort	3. Shell Sort
			4. Bucket Sort	5. Insertion Sort
			0. Quit
			Please enter the your sorting choice: 1
			Contents after sorting are:
	
			11114	11279	11444	11609	11774	11939	
			12104	12269	12434	12599	12764	12929	
			100050	100100	100150	100200	100300	100350	
			100400	100450	100550	100600	100650	100700	
			100800	100850	100900	100950	101050	101100	
			101150	101200	101300	101350	101400	101450	
			101550	101600	101650	101700	101800	101850	
			101900	101950	102050	102100	102150	102200	
			102300	102350	102400	102450	102550	102600	
			102650	102700	102800	102850	102900	102950	

			Sorting options are:
			1. Bubble Sort	2. Selection Sort	3. Shell Sort
			4. Bucket Sort	5. Insertion Sort
			0. Quit
			Please enter the your sorting choice: 2
			Contents after sorting are:
	
			11114	11279	11444	11609	11774	11939	
			12104	12269	12434	12599	12764	12929	
			100050	100100	100150	100200	100300	100350	
			100400	100450	100550	100600	100650	100700	
			100800	100850	100900	100950	101050	101100	
			101150	101200	101300	101350	101400	101450	
			101550	101600	101650	101700	101800	101850	
			101900	101950	102050	102100	102150	102200	
			102300	102350	102400	102450	102550	102600	
			102650	102700	102800	102850	102900	102950	

			Sorting options are:
			1. Bubble Sort	2. Selection Sort	3. Shell Sort
			4. Bucket Sort	5. Insertion Sort
			0. Quit
			Please enter the your sorting choice: 3
			Contents after sorting are:
	
			11114	11279	11444	11609	11774	11939	
			12104	12269	12434	12599	12764	12929	
			100050	100100	100150	100200	100300	100350	
			100400	100450	100550	100600	100650	100700	
			100800	100850	100900	100950	101050	101100	
			101150	101200	101300	101350	101400	101450	
			101550	101600	101650	101700	101800	101850	
			101900	101950	102050	102100	102150	102200	
			102300	102350	102400	102450	102550	102600	
			102650	102700	102800	102850	102900	102950	

			Sorting options are:
			1. Bubble Sort	2. Selection Sort	3. Shell Sort
			4. Bucket Sort	5. Insertion Sort
			0. Quit
			Please enter the your sorting choice: 4
			Contents after sorting are:
	
			11114	11279	11444	11609	11774	11939	
			12104	12269	12434	12599	12764	12929	
			100050	100100	100150	100200	100300	100350	
			100400	100450	100550	100600	100650	100700	
			100800	100850	100900	100950	101050	101100	
			101150	101200	101300	101350	101400	101450	
			101550	101600	101650	101700	101800	101850	
			101900	101950	102050	102100	102150	102200	
			102300	102350	102400	102450	102550	102600	
			102650	102700	102800	102850	102900	102950	

			Sorting options are:
			1. Bubble Sort	2. Selection Sort	3. Shell Sort
			4. Bucket Sort	5. Insertion Sort
			0. Quit
			Please enter the your sorting choice: 5
			Contents after sorting are:
	
			11114	11279	11444	11609	11774	11939	
			12104	12269	12434	12599	12764	12929	
			100050	100100	100150	100200	100300	100350	
			100400	100450	100550	100600	100650	100700	
			100800	100850	100900	100950	101050	101100	
			101150	101200	101300	101350	101400	101450	
			101550	101600	101650	101700	101800	101850	
			101900	101950	102050	102100	102150	102200	
			102300	102350	102400	102450	102550	102600	
			102650	102700	102800	102850	102900	102950	

			Sorting options are:
			1. Bubble Sort	2. Selection Sort	3. Shell Sort
			4. Bucket Sort	5. Insertion Sort
			0. Quit
			Please enter the your sorting choice: 0
			You opted to exit!
			Press 0 to exit or 1 to continue! 
			Please enter the continue response:0
	
			**/
