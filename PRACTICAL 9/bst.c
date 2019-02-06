int bst_linked(){
	tree root=NULL;
	int op,opt,key;
	do{
	printf("\t-----------------BST OPERATIONS (LINKED BASED IMPLEMENTATION)-----------------\n");
	printf("\n\t1.Create BST \t2. Height\t3. Insert\n");
	printf("\n\t4. Traverse \t5. Delete\t6. Leaf nodes\n");
	printf("\n\t7. Parent nodes \t\t0. Exit");
	printf("\n\tYour choice?");
	scanf("%d",&opt);
	switch(opt){
	case 0:printf("\n\tYou opted to exit!\n");
					break;
	case 1: root = createBST();
	break;
	case 2: printf("\n\tThe height of the tree is: %d\n", heightT(root));
		break;
	case 3:printf("Enter the value you want to insert: \n");
		scanf("%d",&key);
		root = insertBST(root,key);
		break;
	case 4:if(root!=NULL){
	printf("\n\t1. Inorder \t2. Preorder \t3. Postorder\t4.Level-order \n\tChoice?");
	scanf("%d",&key);
	traverse(root,key);
	printf("\n");
	}else{
		printf("\n\tThe tree is empty!\n");
	}
	break;
	case 5: if(root!=NULL){
	printf("Enter the value you want to delete: \n");
	scanf("%d",&key);
	root = delete_node(root,key);
	}else{
		printf("\n\tThe tree is empty!\n");
	}
	break;
	case 6:if(root!=NULL){
	printf("\n\tPrinting leaf nodes: \n\t");
	key = allLeafs(root);
	printf("\n\tTotal leaf nodes are: %d\n",key);
	}else{
		printf("\n\tThe tree is empty!\n");
	}
	break;
	case 7:if(root!=NULL){
	printf("\n\tPrinting parent nodes: \n\t");
	key = parentT(root);
	printf("\n\tTotal parent nodes are: %d\n",key);
	}else{
	printf("\n\tThe tree is empty!\n");
	}
	break;
}

	}while(opt!=0);
	destroy(root);
	return 0;
}
