#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
struct cell{
    element1 data;
    struct cell *next;
};
typedef struct{
    struct cell *front,*rear;
}queue;
queue createqueu(){
    queue q;
     q.front=q.rear=NULL;
    return q;
}
int isEmptyQueue(queue q){
    return (q.front==NULL);
}
int enqueue(queue *q,element1 e){
    struct cell *temp;
     temp=(struct cell*)malloc(sizeof(struct cell));
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
    struct cell *temp;
     if(isEmptyQueue(*q)) return 0;
     temp=q->front;
    q->front=q->front->next;
    free(temp);
    if(q->front==NULL)
    q->rear=NULL;
    return 1;
}
int front(queue q,element1 *e){
       if(isEmptyQueue(q)) return 0;
       *e=q.front->data;
       return 1;
}
void displayQueue(queue q){
    element1 e;
    printf("Queue:\n");
    while(front(q,&e)){
        dequeue(&q);
        printf("%4d|\t",e);
    }
    printf("\n");
}
int max(btree b){
if(!b) return 0;
while(b->right)
    b=b->right;
return b->data;

}
int delete_rec(btree *b,element e){

}
int Bfs(btree b){
   
   int max=0;
   queue q=createqueu();
   btree temp=b;
   enqueue(&q,temp);
   while(!isEmptyQueue(q)){
    front(q,&temp);
    dequeue(&q);
    printf("%d",temp->data);
    if(temp->left)
    enqueue(&q,temp->left);
    if(temp->right)
    enqueue(&q,temp->right);
   }
 
  }
void maxLevelSum(btree root)
{
    if(root == NULL)    return ;
    
    // flag = false => odd level, flag = true => even level
    int numberOfNodesInOddLevel = 1, numberOfNodesInpairLevel = 0, flag = false;
    int max = 0,i=1, tmpmax = 0;
     int j=0;
    queue q = createqueu();
    enqueue(&q, root);

    while(!isEmptyQueue(q))
    {
        if(flag == false)
        {
            while(numberOfNodesInOddLevel > 0)
            {
               front(q, &root);
               dequeue(&q);
                tmpmax += root->data;
                if(root->left != NULL)
                {
                    enqueue(&q, root->left);
                    numberOfNodesInpairLevel++;
                }
                if(root->right != NULL)
                {
                    enqueue(&q, root->right);
                    numberOfNodesInpairLevel++;
                }

                numberOfNodesInOddLevel--;
            }
            flag = true;
        }
        else
        {
            while(numberOfNodesInpairLevel > 0)
            {
                front(q, &root);
                dequeue(&q);
                tmpmax += root->data;

                if(root->left != NULL)
                {
                    enqueue(&q, root->left);
                    numberOfNodesInOddLevel++;
                }
                if(root->right != NULL)
                {
                    enqueue(&q, root->right);
                    numberOfNodesInOddLevel++;
                }

                numberOfNodesInpairLevel--;
            }
            flag = false;
        }
          printf("Sum of level %d: %d\n", i++,tmpmax);
         
        if(tmpmax > max)  {
            max = tmpmax;
            j++;
        }  
        tmpmax = 0;
    }
    
   printf("\nThe level that has highest sum of values is %d",j);
}

   int width(btree b){
    int count = 0;
    int maxcount = 0;
    int numberOfNodesinoddLevel = 1;
    int numberOfNodesInevenLevel = 0;
    int flag = 0;
    queue q = createqueu();
    enqueue(&q, b);

    while (!isEmptyQueue(q)) {
        if (flag == 0) {
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
            flag = 1;
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
            flag = 0;
        }
        
        if (maxcount > count)
            count = maxcount;
        maxcount = 0;
    }
    return count;
}

////print each level
int Printwidth(btree b) {
    int i=0;
    int count = 0;
    int maxcount = 0;
    int numberOfNodesinoddLevel = 1;
    int numberOfNodesInevenLevel = 0;
    int flag = false;
    queue q = createqueu();
    enqueue(&q, b);

    while (!isEmptyQueue(q)) {
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
        maxcount = 0;
       
    }
    return count;
}



int nbchil(btree b){
    int c=0;
    if(!b)return 0;
   if(b->left)
   c++;
   if(b->right)
   c++;
   c+=nbchil(b->right)+nbchil(b->left);
   return c;
  
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
    
     printf("maximum element is %d\n",max(b));
     printf("nb od child: %d\n",nbchil(b));
     maxLevelSum(b);
     printf("\n");
     Printwidth(b);
     printf("\n highest width level is %d", width(b));
     
}
