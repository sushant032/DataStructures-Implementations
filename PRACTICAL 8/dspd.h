#define NDT -1
#define MX 50
#define MXVAL 999
#define MAXOF(a,b)({ a > b ? a : b;})
typedef struct treeNode {
  int data;
  struct treeNode *lchild;
  struct treeNode *rchild;
}tNode;
typedef tNode* tree;

int *createList(int *list){
  list = (int *)calloc(MX,sizeof(int));
  int ele=0,i=0;
  printf("\t");
  while(scanf("%d",&ele)&&ele!=MXVAL&&i!=MX-2){
      list[i++] = ele;
      printf("\t");
    }
    list[i++] = NDT;
    list[i++] = MXVAL;
  printf("\n\tList Created.\n");
    return list;
    }
int getLChild(int list[], int len, int ndx){
  int ele;
  if((2*ndx+1) > len)
    return len;
  return (2*ndx+1);
}
int getRChild(int list[], int len, int ndx){
int ele;
  if((2*ndx+2) > len)
      return len;
  return (2*ndx+2);
}

tree buildTree(int list[], int len, int ndx){
    tree temp = NULL;
    if(list[ndx] != NDT){
      temp = (tree) calloc(1, sizeof(tree));
      temp->lchild = buildTree(list,len, getLChild(list, len, ndx));
      temp->data = list[ndx];
      temp->rchild = buildTree(list,len, getRChild(list, len, ndx));
    }
    return temp;
}
void preOrderT(tree root){
    if(root != NULL) {
        printf("%4d[%4lu]", root->data,(long unsigned)root);
        preOrderT(root->lchild);
        preOrderT(root->rchild);
    }
}

void inOrderT(tree root){
  if(root != NULL) {
    inOrderT(root->lchild);
    printf("%4d[%4lu]", root->data,(long unsigned)root);
    inOrderT(root->rchild);
  }
}

void postOrderT(tree root){
  if(root != NULL) {
    postOrderT(root->lchild);
    postOrderT(root->rchild);
    printf("%4d[%4lu]", root->data,(long unsigned)root);
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

int allParent(tree root){
  if(root==NULL || (root->lchild==NULL && root->rchild==NULL))
    return 0;
    printf("%d\t",root->data);
  return allParent(root->lchild)+allParent(root->rchild)+1;
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

int locate(tree root, int key){
	static int res = 0;
  if (root==NULL)
    return 0;
  if(root->data != key){
  locate(root->lchild,key);
  locate(root->rchild,key);
  }
    printf("\tNow Traversing: %d \n",root->data);
    if(root->data==key){
      printf("\tMatch found\n");
      res = 1;
      return 1;
    }
    return res;
}

tree CopyBT(tree root){
tree temp;
  if(root==NULL)
    return NULL;
  temp = (tree)calloc(1,sizeof(tree));
  temp->data = root->data;
  temp->lchild = CopyBT(root->lchild);
  temp->rchild = CopyBT(root->rchild);
  return temp;
}

int isEqlBT(tree root1, tree root2){
  if(root1==NULL && root2==NULL)
      return 1;
      if(root1->data == root2->data)
      {
        isEqlBT(root1->lchild, root2->lchild);
        isEqlBT(root1->rchild, root2->rchild);
      }else{

        return 0;
      }

}

int ParentwithtwoChild(tree root){
  static int parentNode = 0;
  if(root==NULL)
    return 0;
  if(root->lchild!=NULL && root->rchild!=NULL){
    printf("\t%d",root->data);
      parentNode++;
    }
  ParentwithtwoChild(root->lchild);
  ParentwithtwoChild(root->rchild);
  return parentNode;
}
