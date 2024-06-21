#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef int element;
typedef struct node{
    element data;
    struct node *left,*right;
}*btree;
btree construct(element e,btree l,btree r){
    btree b=(btree)malloc(sizeof(struct node));;
    if(!b)
    return 0;
    b->data=e;
    b->left=l;
    b->right=r;
    return b;
}
int heightTree(btree b){
    if(!b) return 0;

    return(1+heightTree(b->left)>1+heightTree(b->right))?1+heightTree(b->left):1+heightTree(b->right);
}
int dif_lr(btree b){
    int l,r;
    int difference=0;
    if(!b) return 0;
    if(b->left)
    l=1+dif_lr(b->left);
    if(b->right)
    r=1+dif_lr(b->right);
    if(l>r)
    difference=l-r;
    else if(l<r)
    difference=r-l;
    return 0;
return difference;
}
int balanced(btree b){
    if(!b) return 1;
    if(abs(heightTree(b->left)-heightTree(b->right))<2)
    return 1;
    return 0;
    if(b->left)
    return balanced(b->left);
    if(b->right)
    return balanced(b->right);
}
int main(){
 btree b=construct(5,
    construct(7,
    construct(11,
    construct(0,NULL,NULL),
    NULL),
    NULL),
    construct(35,
    construct(8,NULL,
    construct(9,NULL,NULL)),
    construct(15,NULL,NULL)));
    // 5
    //7  35
 //11   8    15
 //0      9
 printf("height: %d",heightTree(b));
 printf("\nthe difference between left and right is %d",dif_lr(b));
 printf("\n%d",balanced(b));
}