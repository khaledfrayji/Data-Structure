#include<stdio.h>
typedef struct{
  int lower,upper;  
}interval;
typedef struct list{
    int data;
    struct list *next;
}*list;
typedef struct node{
    interval itv;
    list nbs;
    struct node *left,*right;
}*bst;
bst find(bst b,int value){
   while(b){
    if(value==b->itv.lower || value==b->itv.upper)
    return 1;
    if(value<b->itv.upper)
    return find(b->left,value);
    if(value>b->itv.upper)
    return find(b->right,value);
   
   }

}