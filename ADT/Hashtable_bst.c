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
int findbst(bst b,element e){
    if(!b) return 0;
    if(!strcmp(b->data,e)) return 1;
    else if(strcmp(b->data,e)<0) return findbst(b->right,e);
    else return findbst(b->left,e);
}
int findhash(hashtable h,element e){
    return findbst(h[hash(e)],e);
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
int main(){
    hashtable h;
    createhashtable(h);
    char nb[N];
    while(1){
        printf("enter a string terminated with stop: ");
        scanf("%s",nb);
        if(strcmp(nb,"stop")==0)
        break;
        inserthash(h,nb);
    }
    printf("\n\n\n");
    printhash(h);
    // printf("find one=%d",findhash(h,"one"));
    return 0;
}