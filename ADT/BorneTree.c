#include<stdio.h>
#define N 20
typedef int element[];
typedef struct node{
    int data[N];
    struct node *right,*left;
}*btree;
btree construct(element e[],btree l,btree r,int inf,int sup){
    int i,j;
btree temp=(btree)malloc(sizeof(struct node));
if(!temp) return 0;
for(j=0;j<=N;j++)
for(i=inf;i<=sup;i++){
temp->data[j]=i;
}
temp->left=l;
temp->right=r;
}