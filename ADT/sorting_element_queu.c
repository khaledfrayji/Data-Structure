#include<stdio.h>
#define N 100
#define M 100


typedef int element; 
typedef struct{
    element data[N];
    int top;
}stack;
stack createstack(){
    stack s;
    s.top=-1;
    return s;
}
int isfullStack(stack s){
return s.top==N-1;
}
int isEmptyStack(stack s){
    return s.top==-1;
}
int push(stack *s,element e){
    if(isfullStack(*s)) return 0;
    s->data[++s->top]=e;
    return 1;
}
int pop(stack *s){
    if(isEmptyStack(*s)) return 0;
    s->top--;
    return 1;
}
int top(stack s,element *e){
    if(isEmptyStack(s)) return 0;
    *e=s.data[s.top];
    return 1;
}
typedef struct{
    element data[M];
    int front,rear;
}queue;
queue createqueu(){
    queue q;
    q.front=1;
    q.rear=0;
    return q;
}
int isEmptyQueue(queue q){
    return (q.front==(q.rear+1)%M);
}
int isfullQueue(queue q){
    return (q.front==(q.rear+2)%M);
}
int enqueue(queue *q,element e){
    if(isfullQueue(*q)) return 0;
    q->rear=(q->rear+1)%M;
    q->data[q->rear]=e;
    return 1;
}
int dequeue(queue *q){
    if(isEmptyQueue(*q)) return 0;
    q->front=(q->front+1)%M;
    return 1;
}
int front(queue q,element *e){
       if(isEmptyQueue(q)) return 0;
       *e=q.data[q.front];
       return 1;
}
void displayQueue(queue q){
    element e;
    printf("Queue:\n");
    while(front(q,&e)){
        dequeue(&q);
        printf("%4d|\t",e);
    }
    printf("\n");

}
void  sortqueue(queue *q){
    stack s=createstack();
    queue aux=createqueu();
    element e;
    while(front(*q,&e)){
        dequeue(q);
        if(e%2==0)
         enqueue(&aux,e);
        else 
            push(&s,e);
        
    }
    while(front(aux,&e)){
        dequeue(&aux);
        enqueue(q,e);
    }
       while(top(s,&e)){
            pop(&s);
            enqueue(q,e);
        }

}
void display_stack(stack s){
    element e;
    while(top(s,&e)){
        pop(&s);
        printf(" %d\t",e);
    }
    printf("\n");
}
int main(){
    queue q=createqueu();
   enqueue(&q,2);
     enqueue(&q,5);
      enqueue(&q,8);
       enqueue(&q,3);
        enqueue(&q,9);
         enqueue(&q,6);
          enqueue(&q,4);
          enqueue(&q,1);
            enqueue(&q,7);
            displayQueue(q);
            sortqueue(&q);
            displayQueue(q);     


    
}