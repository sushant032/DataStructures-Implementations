int bst_array_imp(){
	int op,opt,key,tail=0,minIndex;
	bstArr bst_a[50];

do{
printf("\t-----------------BST OPERATIONS( ARRAY IMPLEMENTATION )-----------------\n");
printf("\n\t1.Create BST \t2. Height\t3. Insert\n");
printf("\n\t4. Traverse \t5. Delete\t6. Leaf nodes\n");
printf("\n\t7. Parent nodes \t\t0. Exit");
printf("\n\tYour choice?");
scanf("%d",&opt);
	switch(opt){
	case 0:printf("\n\tYou opted to exit!\n");
	break;
	case 1: tail  = createBSTA(bst_a);
	printf("\n\tCreated tree is: \n");
	levelOrderTA(bst_a,0);
	break;
	case 2: printf("\n\tThe height of the tree is: %d\n", heightTA(bst_a,0));
	break;
	case 3:printf("Enter the value you want to insert: \n");
	scanf("%d",&key);
	tail = insertBSTArr(bst_a,tail,key);
	break;
	case 4:if(tail!=0){
	printf("\n\t1. Inorder \t2. Preorder \t3. Postorder\t4.Level-order \n\tChoice?");
	scanf("%d",&key);
	traverseA(bst_a,key);
	printf("\n");
	}else{
	printf("\n\tThe tree is empty!\n");
	}
	break;
	case 5: if(tail!=0){
	printf("\n\tEnter the value you want to delete: ");
	scanf("%d",&key);
		deleNodeA(bst_a,0,key,tail,0);
		printf("\n\tDisplaying the tree: \n");
		levelOrderTA(bst_a,0);
	}else{
		printf("\n\tThe tree is empty!\n");
	}
	break;
	case 6:if(tail!=0){
	printf("\n\tPrinting leaf nodes: \n\t");
	key = leafNodesA(bst_a,0);
	printf("\n\tTotal leaf nodes are: %d\n",key);
	}else{
		printf("\n\tThe tree is empty!\n");
	}
	break;
	case 7:if(tail!=0){
	printf("\n\tPrinting parent nodes: \n\t");
	key = parentTA(bst_a,0);
	printf("\n\tTotal parent nodes are: %d\n",key);
	}else{
	printf("\n\tThe tree is empty!\n");
	}
	break;
}

}while(opt!=0);
//destroy(root);
return 0;
}
