#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef char element[10]; //in place of element I can place 10 character
typedef struct{
   char var[10];
    int val;
}couple;
typedef struct node {
    element value;
    struct node *left,*right;
}*expression;
typedef struct {
    couple arr[100];
    int size;
}interpretation;
int find(interpretation In,char v[],int *value)
{
    int i;
    for(i=0;i<In.size;i++)
        if(!strcmp(In.arr[i].var,v)){
            *value=In.arr[i].val;
            return 1;
        }
        return 0; 
}
int evaluate(interpretation in,expression e,int *value){
    int bl,br,vl,vr;
    if(!e) return 0;
    if(!e->left && !e->right)
    return find(in,e->value,value);
    bl=evaluate(in,e->left,&vl);
    br=evaluate(in,e->right,&vr);
    if(!strcmp(e->value,"NOT"))
    {
        if(bl || !br)
        return 0;
        *value=1-vr;
        return 1;
    }
    if(!bl || !br) return 0;
     if(!strcmp(e->value,"AND"))
        *value=vl && vr;
      else
       *value=vl || vr;
       return 1;
}
int valid(interpretation arr[],int NbInter,expression e){ //test if its valid for all interpreation

    int i,v;
    for(i=0;i<NbInter;i++){
        if(!evaluate(arr[i],e,&v))
        return -1;
        if(!v) return 0;
    }
    return 1;
}
expression construct(element e,expression l,expression r){
    expression temp=(expression)malloc(sizeof(struct node));
    if(!temp) return NULL;
    strcpy(temp->value,e);
    temp->left=l;
    temp->right=r;
    return temp;
}
int main(){
    int val,res;
    expression e=construct("AND",
    construct("a1",NULL,NULL),
    construct("NOT",NULL,
    construct("OR",construct("bool2",NULL,NULL),construct("bx30",NULL,NULL
    ))));
interpretation i;
i.size=3;
i.arr[0]=(couple) {"a1",1};
i.arr[1]=(couple) {"bool2",0};
i.arr[2]=(couple) {"bx30",0};
res=evaluate(i,e,&val);
if(res)
printf("Evaluation = %d\n",val);
return 0;

}