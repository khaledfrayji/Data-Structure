#include<stdio.h>
#include<stdlib.h>
#define N 100
#define M 100


typedef int element; 
typedef struct cell{
    element data;;
    struct cell *next;
}*stack;
stack createstack(){
    return NULL;
}

int isEmptyStack(stack s){
    return s==NULL;
}
int push(stack *s,element e){
  stack temp=(stack)malloc(sizeof(struct cell));
  if(!temp) return 0;
  temp->data=e;
  temp->next=*s;
  *s=temp;
   return 1;
}
int pop(stack *s){
    if(isEmptyStack(*s)) return 0;
   stack temp=*s;
   *s=(*s)->next;
   free(temp);
   return 1;
}
int top(stack s,element *e){
    if(isEmptyStack(s)) return 0;
    *e=s->data;
    return 1;
}
 struct node{
    element data;
    struct node *next;
};
typedef struct{
    struct node *front,*rear;
}queue;
queue createqueu(){
    queue q;
     q.front=q.rear=NULL;
    return q;
}
int isEmptyQueue(queue q){
    return (q.front==NULL);
}
int enqueue(queue *q,element e){
    struct node *temp;
     temp=(struct node*)malloc(sizeof(struct node));
    if(!temp) return 0;
    temp->data=e;
    temp->next=NULL;
    if(isEmptyQueue(*q))
    q->front=q->rear=temp;
    q->rear->next=temp;
    q->rear=temp;
    return 1;
}
int dequeue(queue *q){
    struct node *temp;
     if(isEmptyQueue(*q)) return 0;
     temp=q->front;
    q->front=q->front->next;
    free(temp);
    if(q->front==NULL)
    q->rear=NULL;
    return 1;
}
int front(queue q,element *e){
       if(isEmptyQueue(q)) return 0;
       *e=q.front->data;
       return 1;
}
void displayQueue(queue q){
    element e;
    printf("Queue:\n");
    while(front(q,&e)){
        dequeue(&q);
        printf("%3d  |\t",e);
    }
    printf("\n");
}
int reverse(queue *q){
    if(isEmptyQueue(*q)) return 0;
    stack s=createstack();
    element e;
    while(front(*q,&e)){
        dequeue(q);
        push(&s,e);
    }
    while(top(s,&e)){
        pop(&s);
        enqueue(q,e);
    }
}
int main(){
    queue q=createqueu();
    //1 2 3 4 5 6 
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    enqueue(&q,5);
    enqueue(&q,6);
    // 6 5 4 3 2 1 
    reverse(&q);
    displayQueue(q);
    
}