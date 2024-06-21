#include<stdio.h>
#include<stdlib.h>
#define M 100;
typedef int element;
typedef struct  node
{
    element data;
    struct node *first_child,*next_sibling;
}*GenericTree;
GenericTree create(){
    return NULL;
}
int isEmptytree(GenericTree g){
return (g==NULL);
}
GenericTree construct(element e,GenericTree firstChild,GenericTree sibling){
    GenericTree g=(GenericTree)malloc(sizeof(struct node));
    if(!g) return 0;
    g->data=e;
    g->first_child=firstChild;
    g->next_sibling=sibling;
    return g;
}
int countnodes(GenericTree g){
    if(!g) return 0;
    return 1+ countnodes(g->first_child) +countnodes(g->next_sibling);
}
int nb_of_siblings(GenericTree g){
    int count=0;
    while(!g) return 0;
    while(g){
        count ++;
        g=g->next_sibling;
    } 
    return count;
}
int children(GenericTree g){
     int count=0;
    while(!g) return 0;
    g=g->first_child;
    while(g){
        count ++;
        g=g->next_sibling;
    } 
    return count;
}
int sum(GenericTree g){
    while(!g) return 0;
    return g->data + sum(g->first_child) + sum(g->next_sibling);
}
int main(){
     GenericTree b=
    construct(1,
    construct(2,NULL,
    construct(3,
    construct(6,NULL,NULL),
    construct(4,
    construct(7,NULL,
    construct(8,
    construct(9,NULL,
    construct(10,NULL,NULL)),NULL)),
    construct(5,construct(11,NULL,
    construct(12,NULL,construct(13,NULL,NULL))),NULL)))),NULL);
    printf(" nb of nodes: %d\n ",countnodes(b));
    printf("nb of siblings: %d",nb_of_siblings(b));
    printf("\nnb of children: %d",children(b));
    printf("\nSum of nodes: %d",sum(b));
    printf("\nfinish");
   
   

}