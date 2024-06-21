#include<stdio.h>
#include<stdlib.h>
#define N 30
typedef int element;
typedef struct st{
    element data[N];
    int top;  
}stack;
stack createstack(){
    stack s;
    s.top=-1;
    return s;
}
int isfull(stack s){
    return s.top==N-1;
}
int isEmpty(stack s){
    return s.top==-1;
}
int top(stack s,element *e){
    if(isEmpty(s)) return 0;
    *e=s.data[s.top];
    return 1;
}
int push(stack *s,element e){
    if(isfull(*s)) return 0;
    s->data[++s->top]=e;
    return 1;
}
int pop(stack *s){
    if(isEmpty(*s)) return 0;
    s->top--;
    return 1;
}
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
void Prefixe(btree b) {
    if(b){
    printf("%d",b->data);
    Prefixe(b->left);
    Prefixe(b->right);
    }
}
void infixe(btree b){
    if(b){
    infixe(b->left);
    printf("%d",b->data);
    infixe(b->right);
    }
}
void postfixe(btree b){
    if(b){
        postfixe(b->left);
        postfixe(b->right);
        printf("%d",b->data);
    }
}
void prefixe_iterative(btree root){
stack s=createstack();
btree currentnode=NULL;
push(&s,root);
while(!isEmpty(s)){
    top(s,&currentnode);
    pop(&s);
    printf("%d",currentnode->data);
    if(currentnode->right)
    push(&s,currentnode->right);
    if(currentnode->left)
    push(&s,currentnode->left);
}
}
void infixe_iterative(btree root){
    stack s=createstack();
    btree currentnode=root;
   while(!isEmpty(s) || currentnode){
    if(currentnode){
        push(&s,currentnode);
        currentnode=currentnode->left;
    }
    else{
        top(s,&currentnode);
        pop(&s);
        printf("%d",currentnode->data);
        currentnode=currentnode->right;
   }
}
}
void postfixe_iterative(btree root){
    stack s=createstack();
    stack out=createstack();
    btree current;
    push(&s,root);
    while(!isEmpty(s)){
        top(s,&current);
        pop(&s);
        push(&out,current);
        if(current->left)
        push(&s,current->left);
        if(current->right)
        push(&s,current->right);
    }
    while(!isEmpty(out)){
        top(out,&current);
        pop(&out);
        printf("%d",current->data);
    }
}
