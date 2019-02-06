#include<stdio.h>
#include<stdlib.h>
#define NDT -1
#define MX 50
#define MXVAL 999
#define MAXOF(a,b)({ a > b ? a : b;})
#define STOP -999
/* Linked list based implementation*/
struct treeNode {
int data;
struct treeNode *lchild;
struct treeNode *rchild;
};
typedef struct treeNode tNode;
typedef tNode* tree;

void preOrderT(tree root){
    if(root != NULL) {
        printf("%4d", root->data);
        preOrderT(root->lchild);
        preOrderT(root->rchild);
    }
}
void inOrderT(tree root){
  if(root != NULL) {
    inOrderT(root->lchild);
    printf("%4d", root->data);
    inOrderT(root->rchild);
  }
}

void destroy(tree root){
  if(root!=NULL){
    destroy(root->lchild);
    destroy(root->rchild);
    free(root);
  }
}
void postOrderT(tree root){
  if(root != NULL) {
    postOrderT(root->lchild);
    postOrderT(root->rchild);
    printf("%4d", root->data);
  }
}


int lengthList(int list[]){
  int i = 0;
  while(list[i] != MXVAL)
      i = i + 1;
  return i-1;
}

int heightT(tree root){
  int lheight,rheight;
  if(root==NULL || (root->lchild==NULL && root->rchild==NULL))
    return 0;
  lheight = heightT(root->lchild);
  rheight = heightT(root->rchild);
  return MAXOF(lheight,rheight)+1;
}

void printDepth(tree T, int level){
	if(T==NULL)
			return;
	if(level==1){
			printf("\t%d",T->data);
			return;
		}
	printDepth(T->lchild,level-1);
	printDepth(T->rchild,level-1);
}

void levelOrderT(tree T){
	int ht = heightT(T)+1;
	int i;

	for(i=1;i<=ht;i++){
		printDepth(T,i);
		printf("\n");
	}
}

int parentT(tree root){
  if(root==NULL || (root->lchild==NULL && root->rchild==NULL))
    return 0;
    printf("%d\t",root->data);
  return parentT(root->lchild)+parentT(root->rchild)+1;
}

int allLeafs(tree root){
  if(root==NULL)
    return 0;
  if(root->lchild==NULL && root->rchild==NULL){
    printf("%d\t",root->data);
    return 1;
    }
  return allLeafs(root->lchild)+allLeafs(root->rchild);
}

tree createNode(){
	tree neww;
	neww = (tree)calloc(1,sizeof(tree));
	if(neww==NULL){
		printf("Underflow\n");
		return NULL;
	}
	return neww;
}

void traverse(tree root,int mode){
	switch(mode){
		case 1:
				printf("\tThe in order traversal is: \n\t");
				inOrderT(root);
				break;
		case 2:
				printf("\n\tThe pre order traversal is: \n\t");
				preOrderT(root);
				break;
		case 3:
				printf("\n\tThe post order traversal is: \n\t");
				postOrderT(root);
				break;
		case 4:
				printf("\n\tThe level order traversal is: \n\t");
				levelOrderT(root);
				break;
	printf("\n");
	}
}

tree insertBST(tree root, int key){
	if(root==NULL){
			root = createNode();
			root->data = key;
			root->lchild = root->rchild = NULL;
		}
	else if(key<root->data)
			root->lchild = insertBST(root->lchild,key);
	else if(key>root->data)
			root->rchild = insertBST(root->rchild,key);
	else
			printf("Duplicate keys!\n");

	return root;

}
tree findMinNode(tree root){
if(root == NULL)
	return NULL;
if(root->lchild == NULL)
	return root;
return (findMinNode(root->lchild));
}

tree delete_node(tree root, int key){
	tree temp=NULL;
	if(root == NULL){
		printf("\n\tDeletion failed, empty tree\n");
		return NULL;
	}
	if(key<root->data)
		root->lchild = delete_node(root->lchild,key);
	else if(key>root->data)
		root->rchild = delete_node(root->rchild,key);
	else{
		if(root->lchild!=NULL && root->rchild!=NULL){
			temp = findMinNode(root->rchild);
			root->data = temp->data;
			root->rchild = delete_node(root->rchild,root->data);
		}else{
			temp = root;
			if(root->lchild==NULL){
					root = root->rchild;
          free(temp);
        }
      else if(root->rchild==NULL){
					root = root->lchild;
          free(temp);
        }
			else
				printf("\n\tThe key not found.\n");
		}

	}

	return root;
}

tree createBST(){
	tree root = NULL;
	int key;
	do{
		printf("\tEnter the key(%d to STOP):",STOP);
		scanf("%d",&key);
			if(key!=STOP)
				root = insertBST(root,key);
	}while(key!=STOP);

	return root;

}
/* Array based implementation */
typedef struct treeNodeA{
  int lchild;
  int data;
  int rchild;
}bstArr;
typedef bstArr *bstA;
bstA createNodeA(bstA root, int key){
  root->data = key;
  root->lchild = root->rchild = -1;
  return root;
}
int insertBSTArr(bstA root, int tail, int key){
    int base=0;
    if(tail==0){
      createNodeA(&root[tail],key);
      return tail + 1;
    }else{
    while(base<=tail){
        if(key<root[base].data){
            if(root[base].lchild == -1){
                root[base].lchild = tail;
                createNodeA(&root[tail],key);
                /*root[tail].data = key;
                root[tail].lchild=root[tail].rchild = -1;*/
                return tail+1;
            }
          else{
              base = root[base].lchild;
              continue;
          }
        }
        else if(key>root[base].data){
            if(root[base].rchild == -1){
                root[base].rchild = tail;
                createNodeA(&root[tail],key);
                /*root[tail].data = key;
                root[tail].lchild=root[tail].rchild = -1;*/
                return tail+1;
            }
          else{
              base = root[base].rchild;
              continue;
          }
        }else{
          printf("Duplicate keys!\n");
          return tail;
        }
      }
    }
}
int createBSTA(bstA root){
  int key,tail=0;
    do{
      printf("\tEnter a node value (%d to STOP): ",STOP);
      scanf("%d",&key);
      if(key!=STOP)
        tail = insertBSTArr(root,tail,key);
    }while(key!=STOP);
    return tail;
}
void preOrderTA(bstA root, int i){
    if(i!=-1){
    printf("\t%d",root[i].data);
    preOrderTA(root,root[i].lchild);
    preOrderTA(root,root[i].rchild);
  }
  return;
}
void postOrderTA(bstA root, int i){
    if(i!=-1){
    postOrderTA(root,root[i].lchild);
    postOrderTA(root,root[i].rchild);
    printf("\t%d",root[i].data);
  }
  return;
}
void inOrderTA(bstA root, int i){
    if(i!=-1){

    inOrderTA(root,root[i].lchild);
    printf("\t%d",root[i].data);
    inOrderTA(root,root[i].rchild);
  }
  return;
}
int minNOdeA(bstA root,int index){
  while(index!=-1){
    if(root[index].lchild==-1){
        return index;
    }
    index = root[index].lchild;
  }
}
int deleNodeA(bstA root, int index, int key,int tail,int parent){
  int minIndex;
    if(tail==0){
        printf("\n\tDeletion failed BST is empty!\n");
        return 0;
    }
    if(index!=-1 && key<root[index].data)
      deleNodeA(root,root[index].lchild,key,tail,index);
    else if(index!=-1 && key>root[index].data)
      deleNodeA(root,root[index].rchild,key,tail,index);
    else{
      if(index!=-1){
      if(root[index].lchild!=-1&&root[index].rchild!=-1){
        minIndex = minNOdeA(root,root[index].rchild);
        printf("\nminIndex = %d\n",minIndex);
        root[index].data = root[minIndex].data;
        //printf("index: %d\n",index);
        deleNodeA(root,root[index].rchild,root[index].data,tail,index);
        }
        else if(root[index].lchild==-1)
          {
          //  printf("\nparent data: %d",root[parent].data);
            if(root[parent].data<=root[index].data)
              root[parent].rchild = root[index].rchild;
            else
              root[parent].lchild = root[index].rchild;
            return tail;
          }else if(root[index].rchild==-1){
            if(root[parent].data<=root[index].data)
              root[parent].rchild = root[index].lchild;
            else
              root[parent].lchild = root[index].lchild;
            return tail;
          }
        }
        else{
          printf("\n\tThe key not found.\n");
          return tail;
        }
        }
}
int heightTA(bstA root, int index){
  int lheight,rheight;
  if(index==-1 || (root[index].lchild==-1 && root[index].rchild==-1))
    return 0;
  lheight = heightTA(root,root[index].lchild);
  rheight = heightTA(root,root[index].rchild);
  return MAXOF(lheight,rheight)+1;
}
void printDepthA(bstA root, int index,int level){
	if(index==-1)
			return;
	if(level==1){
			printf("\t%d",root[index].data);
			return;
		}
	printDepthA(root,root[index].lchild,level-1);
	printDepthA(root,root[index].rchild,level-1);
}

void levelOrderTA(bstA root,int index){
	int ht = heightTA(root,0)+1;
	int i;

	for(i=1;i<=ht;i++){
		printDepthA(root,index,i);
		printf("\n");
	}
}
void traverseA(bstA root,int mode){
	switch(mode){
		case 1:
				printf("\tThe in order traversal is: \n\t");
				inOrderTA(root,0);
				break;
		case 2:
				printf("\n\tThe pre order traversal is: \n\t");
				preOrderTA(root,0);
				break;
		case 3:
				printf("\n\tThe post order traversal is: \n\t");
				postOrderTA(root,0);
				break;
		case 4:
				printf("\n\tThe level order traversal is: \n\t");
				levelOrderTA(root,0);
				break;
	printf("\n");
	}
}
int leafNodesA(bstA root,int index){

  if(index==-1)
    return 0;
  if(root[index].lchild==-1 && root[index].rchild==-1){
    printf("%d\t",root[index].data);
    return 1;
    }
  return leafNodesA(root,root[index].lchild)+leafNodesA(root,root[index].rchild);
}

int parentTA(bstA root,int index){
  if(index==-1 || (root[index].lchild==-1 && root[index].rchild==-1))
    return 0;
    printf("%d\t",root[index].data);
  return parentTA(root,root[index].lchild)+parentTA(root,root[index].rchild)+1;
}
