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
typedef btree element1;
typedef struct{
    element1 data[N];
    int top;
} stack;
stack createStack(){
    stack p;
    p.top=-1;
    return p;
}
int isFull(stack p){
    return (p.top==N-1);
}
int isEmpty(stack p){
    return (p.top==-1);
}
int push(stack *p,element1 e){
    if(isFull(*p)) return 0;
    p->data[++p->top]=e;
    return 1;
}
int top(stack s,element1 *e){
    if(isEmpty(s)) return 0;
    *e=s.data[s.top];
    return 1;
}
int pop(stack *p){
    if(isEmpty(*p)) return 0;
    p->top--;
    return 1;
}

void printLevelOrderZigZag(btree b){
    stack impaire=createStack();
    stack paire=createStack();
    element1 node;
    push(&impaire,b);
    while(!isEmpty(impaire))
    {
        while(top(impaire,&node)){
            pop(&impaire);
            printf("%3d",node->data);
            if(node->left)
            push(&paire,node->left);
            if(node->right)
            push(&paire,node->right);
        
    }
        while(top(paire,&node)){
            pop(&paire);
            printf("%3d",node->data);
              if(node->right)
            push(&impaire,node->right);
            if(node->left)
            push(&impaire,node->left);
    }
}
}
push(&s,b)
while(!isEmpty(s)){
    while(top(s,&b))
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
    printLevelOrderZigZag(b);

}