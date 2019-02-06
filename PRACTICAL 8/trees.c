/**
    Filename:trees.c
    Author: Sushant Kumar
    Date:31-August-2017
    Aim: To study a tree data structure and demonstrate different traversals on
		 		 it – Inorder, Pre-Order, and Post-Order.
		Problem Statement: Create a self-referential structure, TreeNode to represent a node of a binary tree.
Implement the routines to - (1) create a tree node, (2) create a rooted binary tree from a
list [an array] representing DATA content of the nodes of the intended binary tree, (3)
perform inorder walk of the tree, (4) perform preorder walk of the tree, (5) perform
postorder walk of the tree, (6) find height of the tree [assume ROOT at height 0], (7)
count and print all parent [internal] nodes in the tree, and (8) to locate a KEY in the tree.
Create a menu-driven program to test these routines.
*/

/* Header file inclusion */
#include<stdio.h>
#include<stdlib.h>
#include"dspd.h"

/* The main function */
int main(){
	int *list=NULL,*listN=NULL;
	int len=0,opt,key,len2=0,i;
	tree root=NULL,cpyTree=NULL,root2=NULL;

		//len = lengthList(list);
		do{
		printf("\t-----------TREE ADT FUNCTIONS-----------\n");
		printf("\t1. Create List\t2. Build Tree \t3. Create Node\n");
		printf("\t4. InOrder\t5. PreOrder \t6. PostOrder\n");
		printf("\t7. Height\t8. Parent nodes 9. Leaf Nodes\n");
		printf("\t10. Locate\t11. Copy Tree \t12. Equal Trees?\n");
		printf("\t13. Parent with two child\t0. Exit");
		printf("\n\tYour response? ");
		scanf("%d",&opt);

		switch(opt){
		case 1: printf("\n\tPlease enter the elements of the list(999 to end):\n");
			list = createList(list);
			len = lengthList(list);
			break;
		case 2:if(list==NULL){
			printf("\n\tThe list is empty creating list:  \n");
			list = createList(list);
			}
			printf("\tNow Building Tree\n");
			len = lengthList(list);
			root = buildTree(list,len,0);
			printf("\n\tDone Building!\n");
			break;
			case 3:if(len!=MX-2&&list!=NULL){
			printf("\n\tEnter the key:");
			scanf("%d",&key);
			list[len] = key;
			list[len+1]=NDT;
			list[len+2]=MXVAL;
			len++;
			root = buildTree(list, len, 0);
			printf("\n\tLength of the list is = %d\n",len);
			}else{
			printf("\n\tThe list is empty.\n");
			}
			break;
		case 4:if(root==NULL){
			printf("\n\tTree does not exists creating tree: \n");
			if(list==NULL){
			printf("\n\tThe list is empty creating list:  \n");
			list = createList(list);
			}
			printf("\tNow Building Tree\n");
			len = lengthList(list);
			root = buildTree(list,len,0);
			printf("\n\tDone Building!\n");

			}
			printf("\n\tThe inorder traversal is: \n\t");
			inOrderT(root);
			printf("\n\t");
			break;
		case 5:if(root==NULL){
			printf("\n\tTree does not exists creating tree: \n");
			if(list==NULL){
			printf("\n\tThe list is empty creating list:  \n");
			list = createList(list);
			}
			printf("\tNow Building Tree:\n");
			len = lengthList(list);
			root = buildTree(list,len,0);
			printf("\n\tDone Building!\n");

			}
			printf("\n\tThe Preorder traversal is: \n\t");
			preOrderT(root);
			printf("\n\t");
			break;
		case 6:if(root==NULL){
			printf("\n\tTree does not exists creating tree: \n");
			if(list==NULL){
					printf("\n\tThe list is empty creating list:  \n");
					list = createList(list);
					}
					printf("\tNow Building Tree:\n");
					len = lengthList(list);
					root = buildTree(list,len,0);
					printf("\n\tDone Building!\n");

		}
			printf("\n\tThe postorder traversal is: \n\t");
			postOrderT(root);
			printf("\n\t");
			break;
		case 7: printf("\n\tThe height of the tree is %d\n",heightT(root));
					break;
		case 8:if(root!=NULL){
		printf("\n\tThe parents in the tree are: \n\t");
		allParent(root);
		printf("\n\t");
		}else{
			printf("\n\tThe tree is empty.\n");
		}
		break;
		case 9:if(root!=NULL){
		printf("\n\tThe leafs in the tree are: \n\t");
		allLeafs(root);
		printf("\n\t");
		}else{
			printf("\n\tThe tree is empty.\n");
		}
		break;
		case 10: if(root!=NULL){
		printf("\tEnter the key to locate: ");
		scanf("%d",&key);
		if(locate(root,key))
				printf("\n\tThe key is found in tree.\n");
		else
				printf("\n\tThe key is not found in tree.\n");
			}else{
				printf("\n\tThe tree is empty.\n");
			}
		break;
	case 11:printf("\n\tCopying binary tree\n");
		cpyTree = CopyBT(root);
		printf("\n\tThe inorder traversal is: \n\t");
		inOrderT(cpyTree);
		printf("\n\t");
		break;
	case 12:if(root!=NULL){
		printf("\n\tEnter the elements for 2nd tree:\n" );
		listN = createList(listN);
		printf("\tNow Building Tree:\n");
		len2 = lengthList(listN);
		root2 = buildTree(listN,len2,0);
		printf("\n\tDone Building!\n");
		if(isEqlBT(root,root2)){
				printf("\n\tThe trees are equal.\n" );
		}else{

			printf("\n\tThe trees are not equal.\n" );
		}
		}else{
		printf("\n\tThe tree is Empty!\n" );
		}
		break;
		case 13:if(root!=NULL){
		key = ParentwithtwoChild(root);
		printf("\n\tTotal no of parent with two child is: %d\n",key);
		}else{
		printf("\n\tThe tree is empty.\n");
		}
}
}while(opt!=0);


		return 0;


}
/*
	Execution Trail
	-----------TREE ADT FUNCTIONS-----------
	1. Create List	2. Build Tree 	3. Create Node
	4. InOrder	5. PreOrder 	6. PostOrder
	7. Height	8. Parent nodes 9. Leaf Nodes
	10. Locate	11. Copy Tree 	12. Equal Trees?
	13. Parent with two child	0. Exit
	Your response? 1

	Please enter the elements of the list(999 to end):
	10
	20
	30
	40
	50
	999

	List Created.
	-----------TREE ADT FUNCTIONS-----------
	1. Create List	2. Build Tree 	3. Create Node
	4. InOrder	5. PreOrder 	6. PostOrder
	7. Height	8. Parent nodes 9. Leaf Nodes
	10. Locate	11. Copy Tree 	12. Equal Trees?
	13. Parent with two child	0. Exit
	Your response? 2
	Now Building Tree

	Done Building!
	-----------TREE ADT FUNCTIONS-----------
	1. Create List	2. Build Tree 	3. Create Node
	4. InOrder	5. PreOrder 	6. PostOrder
	7. Height	8. Parent nodes 9. Leaf Nodes
	10. Locate	11. Copy Tree 	12. Equal Trees?
	13. Parent with two child	0. Exit
	Your response? 4

	The inorder traversal is:
	  40[26990912]  20[26990880]  50[26990944]  10[26990848]  30[26990976]
		-----------TREE ADT FUNCTIONS-----------
	1. Create List	2. Build Tree 	3. Create Node
	4. InOrder	5. PreOrder 	6. PostOrder
	7. Height	8. Parent nodes 9. Leaf Nodes
	10. Locate	11. Copy Tree 	12. Equal Trees?
	13. Parent with two child	0. Exit
	Your response? 5

	The Preorder traversal is:
	  10[26990848]  20[26990880]  40[26990912]  50[26990944]  30[26990976]
		-----------TREE ADT FUNCTIONS-----------
	1. Create List	2. Build Tree 	3. Create Node
	4. InOrder	5. PreOrder 	6. PostOrder
	7. Height	8. Parent nodes 9. Leaf Nodes
	10. Locate	11. Copy Tree 	12. Equal Trees?
	13. Parent with two child	0. Exit
	Your response? 6

	The postorder traversal is:
	  40[26990912]  50[26990944]  20[26990880]  30[26990976]  10[26990848]
		-----------TREE ADT FUNCTIONS-----------
	1. Create List	2. Build Tree 	3. Create Node
	4. InOrder	5. PreOrder 	6. PostOrder
	7. Height	8. Parent nodes 9. Leaf Nodes
	10. Locate	11. Copy Tree 	12. Equal Trees?
	13. Parent with two child	0. Exit
	Your response? 7

	The height of the tree is 2

		-----------TREE ADT FUNCTIONS-----------
	1. Create List	2. Build Tree 	3. Create Node
	4. InOrder	5. PreOrder 	6. PostOrder
	7. Height	8. Parent nodes 9. Leaf Nodes
	10. Locate	11. Copy Tree 	12. Equal Trees?
	13. Parent with two child	0. Exit
	Your response? 8

	The parents in the tree are:
	10	20
		-----------TREE ADT FUNCTIONS-----------
	1. Create List	2. Build Tree 	3. Create Node
	4. InOrder	5. PreOrder 	6. PostOrder
	7. Height	8. Parent nodes 9. Leaf Nodes
	10. Locate	11. Copy Tree 	12. Equal Trees?
	13. Parent with two child	0. Exit
	Your response? 9

	The leafs in the tree are:
	40	50	30
		-----------TREE ADT FUNCTIONS-----------
	1. Create List	2. Build Tree 	3. Create Node
	4. InOrder	5. PreOrder 	6. PostOrder
	7. Height	8. Parent nodes 9. Leaf Nodes
	10. Locate	11. Copy Tree 	12. Equal Trees?
	13. Parent with two child	0. Exit
	Your response? 10
	Enter the key to locate: 50
	Now Traversing: 40
	Now Traversing: 50
	Match found
	Now Traversing: 20
	Now Traversing: 30
	Now Traversing: 10

	The key is found in tree.
	-----------TREE ADT FUNCTIONS-----------
	1. Create List	2. Build Tree 	3. Create Node
	4. InOrder	5. PreOrder 	6. PostOrder
	7. Height	8. Parent nodes 9. Leaf Nodes
	10. Locate	11. Copy Tree 	12. Equal Trees?
	13. Parent with two child	0. Exit
	Your response? 11

	Copying binary tree

	The inorder traversal is:
	  40[26991072]  20[26991040]  50[26991104]  10[26991008]  30[26991136]
		-----------TREE ADT FUNCTIONS-----------
	1. Create List	2. Build Tree 	3. Create Node
	4. InOrder	5. PreOrder 	6. PostOrder
	7. Height	8. Parent nodes 9. Leaf Nodes
	10. Locate	11. Copy Tree 	12. Equal Trees?
	13. Parent with two child	0. Exit
	Your response? 12

	Enter the elements for 2nd tree:
	10
	20
	30
	40
	50
	999

	List Created.
	Now Building Tree:

	Done Building!

	The trees are equal.
	-----------TREE ADT FUNCTIONS-----------
	1. Create List	2. Build Tree 	3. Create Node
	4. InOrder	5. PreOrder 	6. PostOrder
	7. Height	8. Parent nodes 9. Leaf Nodes
	10. Locate	11. Copy Tree 	12. Equal Trees?
	13. Parent with two child	0. Exit
	Your response? 13
	10	20
	Total no of parent with two child is: 2
	-----------TREE ADT FUNCTIONS-----------
	1. Create List	2. Build Tree 	3. Create Node
	4. InOrder	5. PreOrder 	6. PostOrder
	7. Height	8. Parent nodes 9. Leaf Nodes
	10. Locate	11. Copy Tree 	12. Equal Trees?
	13. Parent with two child	0. Exit
	Your response? 0


	*/
