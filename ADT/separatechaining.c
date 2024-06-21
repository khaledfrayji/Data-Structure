#include<stdio.h>
#include<stdlib.h>
#define N 20
typedef int element;
typedef struct node{
    element data;
    struct node *next;
}*list;
typedef list hashtable[N];
void createhash(hashtable h){
    int i;
    for(i=0;i<N;i++){
        h[i]==NULL;
    }
}
int hash(int n){
    return n%N;
}
int insert_list(list *l,element e){
    if(*l==NULL) {
        *l=(list)malloc(sizeof(struct node));
        if(!(*l)) return 0;
        (*l)->data=e;
        (*l)->next=NULL;
        return 1;
    }
    return insert_list(&((*l)->next),e);
}
int insert_hash(hashtable h,element e){
    return insert_list(&h[hash(e)],e);
}
void print(hashtable h){
    int i=0;
    list temp;
    for(i=0;i<N;i++){
        printf("Index %d",i);
        temp=h[i];
        while(temp){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("\n\n");
    }
}
int main(){
    hashtable h;
    int nb;
    createhash(h);
    while(1){
        printf("Enter a number terminated by 0");
        scanf("%d",&nb);
        if(nb==0) break;
        if(!insert_hash(h,nb)) break;
    }
    print(h);
    printf("\n\n\n");
    return 0;
}