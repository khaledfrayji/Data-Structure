#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef int element;

typedef struct tree{
    element data;
    struct tree *left,*right;
}*btree;

btree construct(element e,btree left,btree right){
    btree b=(btree)malloc(sizeof(struct tree));
    if(!b) return 0;
    b->data=e;
    b->left=left;
    b->right=right;
    return b;
}
typedef btree element1;
typedef struct {
    element1 data[50];
    int front,rear;
}queue;
queue createQueue(){
    queue q;
    q.front=1;
    q.rear=0;
    return q;
}
int isEmptyqueue(queue q){
    return (q.front==(q.rear+1)%50);
}
int isFullQueue(queue q){
    return (q.front==(q.rear+2)%50);
}
int enqueue(queue *q,element1 e){
    if(isFullQueue(*q)) return 0;
    q->rear=(q->rear+1)%50;
    q->data[q->rear]=e;
    return 1;
}
int dequeue(queue *q){
    if(isEmptyqueue(*q)) return 0;
    q->front=(q->front+1)%50;
    return 1;
}
int front(queue q,element1 *e){
    if(isEmptyqueue(q)) return 0;
    *e=q.data[q.front];
    return 1;
}
int height(btree b){
    if(!b) return 0;
     return 1+height(b->left)+height(b->right);
}
int fairly(btree b){
    int currentlevel=1;
    int prevwidth=-1;
  int i=0;
    int count = 0;
    int maxcount = 0;
    int numberOfNodesinoddLevel = 1;
    int numberOfNodesInevenLevel = 0;
    int flag = false;
    queue q = createQueue();
    enqueue(&q,b);

    while (!isEmptyqueue(q)) {
        if (flag == false) {
            while (numberOfNodesinoddLevel > 0) {
                btree node;
                front(q, &node);
                dequeue(&q);
                maxcount++;
                if (node->left) {
                    enqueue(&q, node->left);
                    numberOfNodesInevenLevel++;
                }
                if (node->right) {
                    enqueue(&q, node->right);
                    numberOfNodesInevenLevel++;
                }
                numberOfNodesinoddLevel--;
            }
            flag = true;
        } else {
            while (numberOfNodesInevenLevel > 0) {
                btree node;
                front(q, &node);
                dequeue(&q);
                maxcount++;
                if (node->left) {
                    enqueue(&q, node->left);
                    numberOfNodesinoddLevel++;
                }
                if (node->right) {
                    enqueue(&q, node->right);
                    numberOfNodesinoddLevel++;
                }
                numberOfNodesInevenLevel--;
            }
            flag = false;
        }
       
       printf("Width of level %d: %d\n", i++, maxcount);

       
        if (maxcount > count)
            count = maxcount;
       if(!currentlevel && maxcount<prevwidth)
       return 0;
       prevwidth=maxcount;
       maxcount=0;
       currentlevel=0;
       
    }
   return 1;
}


int main(){
  btree b=construct(5,
    construct(4,
    construct(3,
    construct(0,NULL,NULL),
    NULL),
    NULL),
    construct(15,
    construct(8,NULL,
    construct(9,NULL,NULL)),
    construct(35,NULL,NULL)));
    // 5
    //4  15
 //3   8    35
 //0      9

btree c=construct(5,
    construct(4,
    construct(3,
    construct(0,NULL,NULL),
    NULL),
    NULL),
    construct(15,
    construct(8,NULL,
    construct(9,NULL,NULL)),
    construct(35,
    construct(14,NULL,NULL),NULL)));

printf("Fairly tree ? %d",fairly(c));

}