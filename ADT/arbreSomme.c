
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 100
typedef int element;
typedef struct node{
    element data;
    struct node *left,*right;
}*btree;
btree construct(element e,btree l,btree r){
    btree temp;
    temp=(btree)malloc(sizeof(struct node));
    if(!temp) return 0;
    temp->data=e;
    temp->left=l;
    temp->right=r;
    return temp;
}
typedef btree element1;
struct cell{
    element1 data;
    struct cell *next;
};

// int arbreSomme(btree b){
//     if(!b) return 1;
//     if(b->data!=(b->left->data + b->right->data))
//     return 0;
//     return 1;
//     if(b->left)
//     return arbreSomme(b->left);
//     if(b->right)
//     return arbreSomme(b->right);

// }
int arbreSomme(btree b){
    if(!b) return 1;
    if(b->data==(b->left->data+b->right->data))
    return 1;
     return 0;
    if(b->left)
    return arbreSomme(b->left);
    if(b->right)
    return arbreSomme(b->right);
   
}

int find(btree b,int val){
    if(!b) return 0;
    if(val==b->data)
    return 1;
    if(val>b->data)
    return find(b->right,val);
    if(val<b->data)
    return find(b->left,val);
   
}
void floorc(btree b,int val){
  int ceil=0,floor=0;
  int found=1;
  if(!b) return ;
  if(find(b,val)) {
    ceil=val;
    floor=val;
  }
  else
  {
    ceil=val+1;
    floor=val-1;
  }
 printf("\nfor %d:  Ceil is  %d,Floor is %d ",val,ceil,floor);
 }
    int height(btree b){
        if(!b) return 0;
        int left=height(b->left);
        int right=height(b->right);
        return (left>right) ? left+1: right +1;

}
int balanced(btree b){
  if(!b) return 1;
  int L=height(b->left);
  int R=height(b->right);
  if(abs(R-L)> 1) return 0;
  return 1;
}
int fullBalanced(btree b){
  if(!b) return 1;
  int R=height(b->right);
  int L=height(b->left);
  if(R-L==0)
  return 1;
  return 0;
}
int main(){
  btree b=construct(15,
    construct(4,
    construct(2,
    construct(2,NULL,NULL),
    NULL),
    NULL),
    construct(11,
    construct(2,NULL,
    construct(2,NULL,NULL)),
    construct(9,NULL,NULL)));
    // 15
    //4  11
 //2   2    9
 //2      2
 printf("\nis it arbre somme? %d",arbreSomme(b));
floorc(b,4);
printf("\nHeight iss %d ",height(b));
printf("\nFullBalanced ? %d",fullBalanced(b));
printf("\nBalanced ? %d ",balanced(b));
}