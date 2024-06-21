
//Checking if a string  have the same length before and after the column : using a queue;
#include<stdio.h>
#define N 100
#define M 100
typedef int element; 
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

char string_queue(char  *str){
    queue q=createqueu();
   element e;
   char *p=str;
   int found=0,equal=1;
 while(*p!='\0'){
    if(*p==':'){
        
         found=1;
          p++;
          break;
    }
    enqueue(&q,*p);
   p++;
 }
    if(found==1){
        while(*p!='\0' && front(q,&e)){
            dequeue(&q);
            if(*p!=e && equal==1) //kermel eza fi haref wahad gher ltene b tene kelme deghre betla3 
                equal=0;
               *p++;
        }
        if(*p!='\0')
            return 'R';
            if(front(q,&e))
            return 'L';
    if(equal==1)
        return 'S';//same length and character
    return 'D';//different char
    }
    return 'N';//there is not a column;
}
int main(){
 queue q=createqueu();
char str[100];
 printf("Enter a sting: ");scanf("%s",str);
 printf("%c",string_queue(str));

}