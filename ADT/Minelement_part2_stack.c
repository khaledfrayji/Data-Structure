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
typedef struct{
    stack original;
    int min;

}st;
st createSt(){
 st s;
 s.original=createStack();
 return s;
}
int pushSt(st *s,element e){
    element k;
 if(isFull((s->original))) return 0;
 if(isEmpty(s->original)){
    push(&(s->original),e);
    s->min=e;
 }
 else{
    if(e<s->min){
         push(&(s->original),2*e-s->min);
        s->min=e;
    }
    else
    push(&(s->original),e);
 }
return 1;
}
int popSt(st *s){
    element e;
     if(isEmpty(s->original)) return 0;
    top(s->original,&e);
      pop(&(s->original));
    if(e<s->min){
       s->min=(s->min*2)-e;
    }
 return 1;
}
int topSt(st s,element *e){
    element el;
    if(isEmpty(s.original)) return 0;
    top(s.original,&el);
    *e=(el<s.min ? s.min : el);
    return 1;
}
int getMin(st s,element *e){
    *e=s.min;
    return 1;
}
void printStack(st s){
 
    element e;
    printf("\nStack");
    while(topSt(s,&e)){
        popSt(&s);
        printf("\n|%5d   |\n",e);
    }
    printf("|________|\n");
}

int main(){
    st s=createSt();
    element e;
    pushSt(&s,5);
    pushSt(&s,10);
    pushSt(&s,3);
    pushSt(&s,2);
    printStack(s);
    getMin(s,&e);
    printf("min= %d\n",e);
    popSt(&s);
    popSt(&s);
    pushSt(&s,1);
    popSt(&s);
    pushSt(&s,2);
    pushSt(&s,9);
    pushSt(&s,7);
    pushSt(&s,12);
    printStack(s);
    getMin(s,&e);
    printf("min= %d",e);

}