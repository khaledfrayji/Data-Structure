#include<stdio.h>
#include<stdlib.h>
#define N 100
typedef int element;
typedef struct{
    element data[N];
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
int push(stack *p,element e){
    if(isFull(*p)) return 0;
    p->data[++p->top]=e;
    return 1;
}
int top(stack s,element *e){
    if(isEmpty(s)) return 0;
    *e=s.data[s.top];
    return 1;
}
int pop(stack *p){
    if(isEmpty(*p)) return 0;
    p->top--;
    return 1;
}
int stacking(stack *s,stack *p){
   stack temp=createStack();
    element e;
    while(top(*s,&e) &&  pop(s) &&  push(&temp,e));
    while (top(*p,&e)&&  pop(p) && push(s,e));
    while(top(temp,&e) && pop(&temp) &&  push(p,e));
    while (top(*p,&e)&&  pop(p) && push(s,e));
}
void display_stack(stack s){
if(isFull(s)){
        printf("\nStack Overflow\n");
        exit(1);
    }
    else if(isEmpty(s)){
        printf("\nStack Underflow\n");
        exit(1);
    }
    element e;
    printf("\nStack");
    while(top(s,&e)){
        pop(&s);
        printf("\n|%5d   |\n",e);
    }
    printf("|________|\n");
}
int main(){
    stack s=createStack();
    stack q=createStack();
    push(&q,7);
    push(&q,6);
    push(&q,2);
    printf("Stack 1\n");
    display_stack(q);
    push(&s,-1);
    push(&s,-7);
    push(&s,-6);
     printf("Stack 2\n");
    display_stack(s);
    stacking(&s,&q);
    display_stack(s);
    display_stack(q);
    
}