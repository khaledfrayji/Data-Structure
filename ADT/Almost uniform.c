#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 20
#define N 20
typedef char element[N];

typedef struct node{
    element data;
    struct node *right,*left;
}*bst;
typedef bst hashtable[M];
void createhashtable( hashtable h){
int i;
for(i=0;i<M;i++){
    h[i]=NULL;
}
}
int hash(element e){
    int i,s=0;
    while(e[i])
    s+=e[i++];
    return s%M;
}
int inser_bst(bst *b,element e){
if(*b==NULL){
(*b)=(bst)malloc(sizeof(struct node));
if(!(*b)) return 0;
strcpy((*b)->data,e);
(*b)->left=(*b)->right=NULL;
return 1;
}
if(strcmp((*b)->data,e)==0)
return 0;
if(strcmp((*b)->data,e)<0)
return inser_bst(&((*b)->right),e);
return  inser_bst(&((*b)->left),e);
}
int inserthash(hashtable h,element n){
    return inser_bst(&h[hash(n)],n);
}
int count(bst b){
    if(!b) return 0;
    return 1+count(b->left)+count(b->right);
}
void array_collision(hashtable h,int col[]){
int x,i;
for(i=0;i<M;i++){
x=count(h[i]);
col[i]=(x<2)?x:x-1;
}
}
void interval(int arr[],int intervale[]){
    int i;
    for(i=0;i<M-1;i++){
      intervale[i]= arr[i+1]-arr[i];
    }
}
int min_max(int col[]){
    int i;
    int max=col[0];
    int min=col[0];
    for(i=1;i<M;i++){
        if(col[i]<min){
            min=col[i];
        }
        else
        if(col[i]>max)
        max=col[i];
    }
    if(max-min<=2){
        return 1;
    }
}
void almost_uniforme(hashtable h){
    int col[M];
    int intervale[M-1],i;
array_collision(h,col);
interval(col,intervale);
for(i=0;i<M-1;i++){
    if(intervale[i]<-1 || intervale[i]>1 )
    return 0;
    return 1;
}
}
void inorder(bst b){
    if(b){
    inorder(b->left);
    printf("%d ",b->data);
    inorder(b->right);
    }
}
void printhash(hashtable h){
    int i;
    for(i=0;i<M;i++){
        printf("Index %d ",i);
        inorder(h[i]);
        printf("\n");
    }
}