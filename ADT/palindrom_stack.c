#include<stdio.h>
#include<string.h>
#define N 100
typedef char element;
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
char is_palindrom(char str[])
{
    stack s=createStack();
    element e;
    for(int i=0;i<strlen(str)/2;i++){
     push(&s,str[i]);
    }
      for(int i=(strlen(str)/2)+1;i<=strlen(str);i++){
     top(s,&e);
     pop(&s);
     if(e!=str[i])
       return 0;
     else{
      return 1;
     }
    }
}
int main(){
    char str[N];
    printf("Enter a string: ");
    scanf("%s",str);
    if(is_palindrom(str)){
          printf("%s is palindrom",str);
    }
    else{
          printf("%s is not palindrom",str);
    }
}