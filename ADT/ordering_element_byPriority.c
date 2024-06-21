#include<stdio.h>
#define N 100
#define M 100
#define T 100
typedef struct{
    int id;
    int priority;
}element; 
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
        printf("%d, %d|\t",e.id,e.priority);
    }
    printf("\n");

}
void priority(queue *q)
{
    stack s[T];
    element e;
    for(int i=0;i<T;i++)
        s[i]=createStack();

         while(front(*q,&e)){
            dequeue(q);
            push(&s[e.priority],e);
         }
         for(int i=0;i<T;i++){
            while(top(s[i],&e)){
                pop(&s[i]);
                enqueue(q,e);
            }
         }
                
    }
    int main(){
    queue q=createqueu();
    enqueue(&q,(element){1,5});
    enqueue(&q,(element){2,3});
    enqueue(&q,(element){3,1});
    enqueue(&q,(element){4,3});
    enqueue(&q,(element){5,3});
    enqueue(&q,(element){6,5});
    enqueue(&q,(element){7,2});
    enqueue(&q,(element){8,1});
    //priority(&q);
    displayQueue(q);
     priority(&q);
    displayQueue(q);


}