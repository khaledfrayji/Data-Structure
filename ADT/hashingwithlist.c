#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}*list;
typedef list hashtable[100];
void createhashtable(hashtable h){
    
    int i;
    for(i=0;i<199;i++)
        h[i]==NULL;
}
int hash(int key){
    return key%100;
}
int insertlist(list *l,int e){
    if(*l==NULL){
        *l=(list)malloc(sizeof(struct node));
        if(!(*l)) return 0;
        (*l)->data=e;
        (*l)->next=NULL;
        return 1;
    }
    return insertlist(&((*l)->next),e);
}
int inserthash(hashtable h,int e){
    return insertlist(&h[hash(e)],e);
}
int searchlist(list l,int e){
    if(!l) return 0;
    list temp=l;
    while(temp){
        if(temp->data==e) return 1;
        temp=temp->next;
    }
 return 0;
}
int searchhash(hashtable h,int e){
    return searchlist(h[hash(e)],e);
}
int deletelist(list *l,int e){
   list current=*l;
   list prev=NULL;
   if(current && current->data==e){
    *l=current->next;
    free(current);
    
   }
   while(current && current->data !=e){
    prev=current;
    current=current->next;
   }
   if(!current){
    printf("Element not found");
    
   }
   prev->next=current->next;
   free(current);
}
int delethash(hashtable h,int e){
    return deletelist(&h[hash(e)],e);
}
void printhash(hashtable h){
    list temp;
    for(int i=0;i<100;i++){
        temp=h[i];
        printf("Index %d",i);
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    }
}
int main(){
     hashtable h;
       createhashtable(h);
     for(int i=0;i<10;i++){
      inserthash(h,i);
printhash(h);
     }

    
}