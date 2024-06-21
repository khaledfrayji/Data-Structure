#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 100
typedef int element;
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
int sum(char str1[],char str2[],char str3[])
{
    stack s=createStack();
    stack p=createStack();
    stack k=createStack();
     int result=0;
     element e1,e2;
     for(int i=0;i<strlen(str1);i++){
        push(&s,str1[i]-'0');
     }
      for(int i=0;i<strlen(str2);i++){
        push(&p,str2[i]-'0');
     }
     while(!isEmpty(s) || !isEmpty(p)){
        if(top(s,&e1))
        pop(&s);
        if(top(p,&e2))
        pop(&p);
        result+=e1+e2;
        push(&k,result%10);
        result/=10;
        e1=e2=0;
     }
      if(result)
      push(&k,result);
      int i=0;
      while(top(k,&e1)){
        pop(&k);
    str3[i++]=e1+'0';
      }
      str3[i]='\0';
}
int main(){
    char str[N],str2[N],str3[N];
    printf("enter a number: ");
    scanf("%s",str);
    printf("Enter second number: ");
    scanf("%s",str2);
    sum(str,str2,str3);
    printf("The sum is %s",str3);
}
