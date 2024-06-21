#include<stdio.h>
#include<stdlib.h>
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
int max(btree b){
  if(b){
    if(!b->right) return b->data;
    return max(b->right);
  }
  return 0;
}
int min(btree b){
   while(b){
    while(!b->left)
    return b->data;
    b=b->left;
   }
   return 0;
}
int insert_rec(btree *b,element e){
    if(!*b){
        *b=(btree)malloc(sizeof(struct node));
        if(!b) return 0;
        (*b)->data=e;
        (*b)->left=(*b)->right=0;
        return 1;
    }
    if(e==(*b)->data) return 0;
    if(e>(*b)->data)
    insert_rec(&((*b)->right),e);
    if(e<(*b)->data)
    insert_rec(&((*b)->left),e);
}
int insert_iter(btree *b,element e){
    btree c,d;
    c=*b;
    while(c){
        d=c;
        if(c->data==e) return 0;
        if(e<c->data)
        c=c->left;
        else
        c=c->right;
    }
    //if c ==null
    c=(btree)malloc(sizeof(struct node));
    if(!c) return 0;//if i cant malloc it;
    c->data=e;
    c->right=c->left=NULL;
    if(*b==NULL)
    *b=c;
    else 
    if(e<d->data)
    d->left=c;
    else
    d->right=c;
    return 1;
    
}
int print(btree b){
 if(!b) return 0;
 print(b->left);
 printf("\n%d",b->data);
 print(b->right);
 
}
btree *find(btree *b,element e){
    if(!b) return 0;
    if(e==(*b)->data) return b;
    if(e<(*b)->data) return find(&((*b)->left),e);
     return find(&((*b)->right),e);
}
int delete_root(btree *b){
    btree c,d;
    if(!b) return 0;
    if((*b)->right==NULL && (*b)->left==NULL){
        c=*b;
        *b=NULL;
        free(c);
    }
    else if((*b)->left==NULL){
        c=*b;
        *b=(*b)->left;
        free(c);
    }
    else if((*b)->right==NULL){
        c=*b;
        *b=(*b)->right;
        free(c); 
    }
    else{ //find the max on the left;
    c=(*b)->left;
   if(c->right==NULL)
   {
    (*b)->left=c->left;
    (*b)->data=c->data;
    free(c);
   }
   else {
    while(c->right){
        d=c;
        c=c->right;
    }
    (*b)->data=c->data;
    d->right=c->left;
    free(c);
   }
    }
    return 1;
}
int delete_iter(btree *b,element e){
    btree *A=find(b,e);
    if(A) 
    return delete_root(A);
    return 1;
}
int delete_rec(btree *b,element e){
    btree temp;
    if(!b) return 0;
    if(e<(*b)->data)
    return delete_rec(&((*b)->left),e);
  else if(e>(*b)->data)
    return delete_rec(&((*b)->right),e);
    else{
        if((*b)->left && (*b)->right){
            temp->data=max((*b)->left);
            (*b)->data=temp->data;
           return  delete_rec(&((*b)->left),temp->data);
        }
        else{
            temp=*b;
             if((*b)->left==NULL)
                *b=(*b)->right;
             
             else if((*b)->left==NULL)
              *b=(*b)->left;
              free(temp);
        }
    }
    return 1;
}
btree kth_element(btree b,int k,int *count){
    btree left;
if(!b) return 0;
  left=kth_element(b->left,k,count);
  if(left) return left;
  if(++(*count)==k)
  return b;
  return kth_element(b->right,k,count);
}
btree kth_smallest(btree b,int k){
int count=0;
return kth_element(b,k,&count);

}
int isBst(btree b){
    if(!b) return 1;
    if(b->left !=NULL && max(b->left) > b->data )
    return 0;
     if(b->right!=NULL && min(b->right) < b->data)
    return 0;
    //recursivly check all the nodes
    if(!isBst(b->left ) || !isBst(b->right))
    return 0;
    return 1;
}
int isBstVersion2(btree b,int *previous)
{
    if(!b) return 1;
    //inorder traversal bydmanle sorted list so eza llist msh sorted ma3neta msh bst
    return isBstVersion2(b->left,previous) ; // or if(!isBstversion2(b->left,previous) return 0) ;
    if(b->data < *previous) return 0;
    *previous=b->data;
     return isBstVersion2(b->right,previous) ;
}
btree belong_bst_iter(btree b,int v){
   while(b){
    if(v==b->data)
    return b;
    if(v<b->data)
    b=b->left;
    if(v>b->data)
    b=b->right;
   }
   return NULL;
}
btree belong_bst_rec(btree b,int v){
   if(b){
    if(v==b->data)
    return b;
    if(v<b->data)
    return belong_bst_rec(b->left,v);
    if(v>b->data)
    return belong_bst_rec(b->right,v);
   }
   printf("\nnot found");
}
int main(){
    btree b=construct(5,
    construct(4,
    construct(3,
    construct(2,NULL,NULL),
    NULL),
    NULL),
    construct(35,
    construct(30,NULL,
    construct(33,NULL,NULL)),
    construct(45,NULL,NULL)));
    // 5
    //4  35
 //3   30    45
 //2      33
 int prev=INT_MIN;
 printf("the max is %d",max(b));
    printf("\nthe min is  %d",min(b));
    printf("\ninsert 65\n");
    insert_rec(&b,65);
    printf("\n Now the max is %d",max(b));
    printf("\nDelete 65");
    delete_rec(&b,65);
     printf("\nthe new max is %d",max(b));
    printf("\nthe 3th smallest element is %d", kth_smallest(b,3)->data);
    printf("\n is Bst ? %d",isBst(b));
    printf("\n is Bstversion 2 ? %d",isBstVersion2(b,&prev));
    printf("\n found...%d",belong_bst_rec(b,5)->data);
    print(b);
}