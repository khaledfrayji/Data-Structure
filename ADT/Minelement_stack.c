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
    stack original,min;

}st;
st createst(){
    st s;
    s.original=createStack();
    s.min=createStack();
    return s;
}
int pushSt(st *s,element e){
    element k;
    if(isFull(s->original)) return 0;
    if(isEmpty(s->original)){
    push(&(s->original),e);
    push(&(s->min),e);
    }
  else{
        push(&(s->original),e);
        top(s->min,&k);
    if(k>e){
        push(&(s->min),e);
    }
    else{
          push(&(s->min),k);
    }
  }
  return 1;

}
int popSt(st *s){
    if(isEmpty(s->original)) return 0;
    pop(&(s->original));
    pop(&(s->min));
    return 1;
}
int topSt(st s,element *e){
    if(isEmpty(s.original)) return 0;
    top(s.original,e);
    return 1;
}
int getMin(st s,element *e){
    
     if(isEmpty(s.original)) return 0;
    top(s.min,e);
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
    st s=createst();
    element e;
    pushSt(&s,5);
    pushSt(&s,6);
    pushSt(&s,2);
    pushSt(&s,8);
    printStack(s);
    getMin(s,&e);
    printf("Min is %d\n",e);
    pushSt(&s,1);
    getMin(s,&e);
    printf("Min is %d",e);

}