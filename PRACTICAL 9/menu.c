/**
    Filename:menu.c
    Author: Tanvi Kausar
    Date:13-September-2017
    Aim: To study and implement binary search tree (BST) - using an Array and Linked List
		Problem Statement: Create a header file, “ treeAdt.h” to include the self-referential structure, TreeNode cretaed
    in Experiment-8 and the routines to – (1) traversal the tree (pre-, post-, and in- order), (2)
    find the height of a tree, (3) to count and list all leaf nodes and parent nodes.
    Using “ treeAdt.h” , implement the routines for a binary search tree to – (1) insert a node,
    (2) delete a node with specified key value, (3) traverse the tree in level-order, and (4)
    create binary tree at once using insertNode().
    Write C routines involving array-based implementation of a binary search tree to – (1)
    insert a node, (2) delete a node, and (3) traverse a tree in inorder and either in preorder or
    postorder.
    Write a menu driven program to enable simulating the array-based and the linked-based
    routines for the binary search tree.
*/

/* Header file inclusion*/
#include<stdio.h>
#include"bst.h"
#include"bst.c"
#include"bst_a.c"

/* The main function */

int main(){
  int option;
  do{
      printf("\n\t--------------BST ADT (IMPLEMENTATION CHOICE)--------------\n");
      printf("\n\t1) Linked Based\t\t2) Array List");
      printf("\n\tYour choice: ");
      scanf("%d",&option);
      switch (option) {
        case 1:bst_linked();
                break;
        case 2:bst_array_imp();
                break;
      }
  }while(option!=0);

}
/** Execution Trail
--------------BST ADT (IMPLEMENTATION CHOICE)--------------

	1) Linked Based		2) Array List
	Your choice: 1
	-----------------BST OPERATIONS (LINKED BASED IMPLEMENTATION)-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?1
	Enter the key(-999 to STOP):10
	Enter the key(-999 to STOP):20
	Enter the key(-999 to STOP):-10
	Enter the key(-999 to STOP):-5
	Enter the key(-999 to STOP):-15
	Enter the key(-999 to STOP):40
	Enter the key(-999 to STOP):15
	Enter the key(-999 to STOP):-999
	-----------------BST OPERATIONS (LINKED BASED IMPLEMENTATION)-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?2

	The height of the tree is: 2
	-----------------BST OPERATIONS (LINKED BASED IMPLEMENTATION)-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?4

	1. Inorder 	2. Preorder 	3. Postorder	4.Level-order
	Choice?1
	The in order traversal is:
	 -15 -10  -5  10  15  20  40
	-----------------BST OPERATIONS (LINKED BASED IMPLEMENTATION)-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?2

	The height of the tree is: 2
	-----------------BST OPERATIONS (LINKED BASED IMPLEMENTATION)-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?3
Enter the value you want to insert:
100
	-----------------BST OPERATIONS (LINKED BASED IMPLEMENTATION)-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?4

	1. Inorder 	2. Preorder 	3. Postorder	4.Level-order
	Choice?2

	The pre order traversal is:
	  10 -10 -15  -5  20  15  40 100
	-----------------BST OPERATIONS (LINKED BASED IMPLEMENTATION)-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?4

	1. Inorder 	2. Preorder 	3. Postorder	4.Level-order
	Choice?3

	The post order traversal is:
	 -15  -5 -10  15 100  40  20  10
	-----------------BST OPERATIONS (LINKED BASED IMPLEMENTATION)-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?4

	1. Inorder 	2. Preorder 	3. Postorder	4.Level-order
	Choice?4

	The level order traversal is:
		10
	-10	20
	-15	-5	15	40
	100

	-----------------BST OPERATIONS (LINKED BASED IMPLEMENTATION)-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?6

	Printing leaf nodes:
	-15	-5	15	100
	Total leaf nodes are: 4
	-----------------BST OPERATIONS (LINKED BASED IMPLEMENTATION)-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?7

	Printing parent nodes:
	10	-10	20	40
	Total parent nodes are: 4
	-----------------BST OPERATIONS (LINKED BASED IMPLEMENTATION)-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?0

	You opted to exit!

	--------------BST ADT (IMPLEMENTATION CHOICE)--------------

	1) Linked Based		2) Array List
	Your choice: 2
	-----------------BST OPERATIONS( ARRAY IMPLEMENTATION )-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?10
	-----------------BST OPERATIONS( ARRAY IMPLEMENTATION )-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?20
	-----------------BST OPERATIONS( ARRAY IMPLEMENTATION )-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?1
	Enter a node value (-999 to STOP): 10
	Enter a node value (-999 to STOP): 20
	Enter a node value (-999 to STOP): -10
	Enter a node value (-999 to STOP): -5
	Enter a node value (-999 to STOP): -15
	Enter a node value (-999 to STOP): 15
	Enter a node value (-999 to STOP): 30
	Enter a node value (-999 to STOP): -999

	Created tree is:
	10
	-10	20
	-15	-5	15	30
	-----------------BST OPERATIONS( ARRAY IMPLEMENTATION )-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?4

	1. Inorder 	2. Preorder 	3. Postorder	4.Level-order
	Choice?1
	The in order traversal is:
		-15	-10	-5	10	15	20	30
	-----------------BST OPERATIONS( ARRAY IMPLEMENTATION )-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?4

	1. Inorder 	2. Preorder 	3. Postorder	4.Level-order
	Choice?2

	The pre order traversal is:
		10	-10	-15	-5	20	15	30
	-----------------BST OPERATIONS( ARRAY IMPLEMENTATION )-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?4

	1. Inorder 	2. Preorder 	3. Postorder	4.Level-order
	Choice?3

	The post order traversal is:
		-15	-5	-10	15	30	20	10
	-----------------BST OPERATIONS( ARRAY IMPLEMENTATION )-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?6

	Printing leaf nodes:
	-15	-5	15	30
	Total leaf nodes are: 4
	-----------------BST OPERATIONS( ARRAY IMPLEMENTATION )-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?5

	Enter the value you want to delete: -5

	Displaying the tree:
	10
	-10	20
	-15	15	30
	-----------------BST OPERATIONS( ARRAY IMPLEMENTATION )-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?7

	Printing parent nodes:
	10	-10	20
	Total parent nodes are: 3
	-----------------BST OPERATIONS( ARRAY IMPLEMENTATION )-----------------

	1.Create BST 	2. Height	3. Insert

	4. Traverse 	5. Delete	6. Leaf nodes

	7. Parent nodes 		0. Exit
	Your choice?0

	You opted to exit!

	--------------BST ADT (IMPLEMENTATION CHOICE)--------------

	1) Linked Based		2) Array List
	Your choice: 0
**/
