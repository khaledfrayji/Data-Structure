#include<stdio.h>
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
//Find the nth element
element nth(stack p,int n){
    int count=1;
    element e;
  while(top(p,&e) && count<n){
    count ++;
    pop(&p);}
    if(isEmpty(p))
    return -1;
  return e;
}
element insertelement(stack *p,element e,int n){
    element k;
    int count=1;
    if(isEmpty(*p)) return 0;
   stack s;
   s=createStack();
   while(top(*p,&k)&& count<n){
     count ++;
        pop(p);
        push(&s,k);
    }
    push(p,e);
  while(top(s,&k)){
    pop(&s);
  push(p,k);
   }
}
void printStack(stack s){
    if(isFull(s)){
        printf("\nStack Overflow\n");
        exit(1);
    }
    else if(isEmpty(s)){
        printf("\nStack Underflow\n");
        exit(1);
    }
    element e;
    printf("\nStack");
    while(top(s,&e)){
        pop(&s);
        printf("\n|%5d   |\n",e);
    }
    printf("|________|\n");
}
element delete_nth(stack *s,int n)
{
    if(isEmpty(*s)) return -1;
    element e;
    int count=1;
    stack p;
    p=createStack();
    while(top(*s,&e) && count<n){
        count++;
        pop(s);
        push(&p,e);
    }
    pop(s);
    while(top(p,&e)){
        pop(&p);
        push(s,e);
    }
}
    int interchange(stack *s)
    {
   
     element e1,e2;
     if(top(*s,&e1)&& pop(s));
     {
        if(top(*s,&e2)&& pop(s)){
            push(s,e1);
            push(s,e2);
        }
        else
        push(s,e1);
     }
   
    }
 int sum(stack s){
    int sum=0;
    element e;
    while(top(s,&e)){
        pop(&s);
        sum=sum+e;
    }
    return sum;
 }
double avg(stack s){
   int count=0;
    int sum=0;
    element e;
    while(top(s,&e)){
        count++;
        pop(&s);
        sum=sum+e;
    }
    return (double)sum/count;

 }
 int reverse_order(stack *s)
{
    element e;
    stack temp=createStack();
    stack aux=createStack();
    while(top(*s,&e)){
        pop(s);
        push(&temp,e);
    }
    while(top(temp,&e)){
        pop(&temp);
        push(&aux,e);
    }
    while(top(aux,&e)){
        pop(&aux);
        push(s,e);
    }
}
 int remove_negative(stack *s)
    {
      element e;
      stack p=createStack();
       while(top(*s,&e)){
       pop(s);
       if(e>0){
        push(&p,e);
       }
       }
       while(top(p,&e)){
        pop(&p);
        push(s,e);
       }
      
    }
      
int first_element(stack s)
{
 element e;
 stack p=createStack();
 while(top(s,&e)){
 pop(&s);
 push(&p,e);
 }
 if(top(p,&e)){
    return e;
}
}

int insertAtBottom(stack *s,element nb)
{
    element e;
    if(isEmpty(*s)){
       push(s,nb);
    }
    else{
        top(*s,&e);
        pop(s);
       insertAtBottom(s,nb);
        push(s,e);
    }
}
int recursive_reverse(stack *s)
{
    element e;
    if(!isEmpty(*s)){
        top(*s,&e);
        pop(s);
        recursive_reverse(s);
        insertAtBottom(s,e);
    }
    
    }


int main(){
    stack s;
    int data,n;
    s=createStack();
    printf("Enter how many elements you want to push: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    printf("Enter the %d.number to be pushed: ",i);
    scanf("%d",&data);
    push(&s,data);
    }
    //Find the nth element of the stack
    printf("1st element in the stack is: %d\n",nth(s,1));
    printf("7th element in the stack is: %d\n",nth(s,7));
    printf("2nd element in the stack is: %d\n",nth(s,2));
    printf("3th element in the stack is: %d  ",nth(s,3));
    printStack(s);
    //inserting elements
    printf("\nInsert element 4 at position 3\n");
    insertelement(&s,4,3);
    printStack(s);
    printf("\nInsert element 7 at position 2\n");
    insertelement(&s,7,2);
    printStack(s);
    printf("\nInsert element 99 at position 1\n");
    insertelement(&s,99,1);
    printStack(s);
     printf("\nInsert element 100 at position 100\n");
    insertelement(&s,100,100);
    printStack(s);
    //Deleting elements
    printf("\nDelete the 2nd element\n");
    delete_nth(&s,2);
    printStack(s);
     printf("\nDelete the 10th element\n");
    delete_nth(&s,10);
    printStack(s);
     printf("\nDelete the 5th element\n");
    delete_nth(&s,5);
    printStack(s);
    //interchange top 2 elements
    printf("\nInterchange the top 2 elements\n");
    interchange(&s);
    printStack(s);
    //Sum of elements
    printf("\nThe sum of the elements in the stack = %d\n",sum(s));
    printf("\nthe average of all numbers on the stack = %.2lf\n",avg(s));
    //reversed stack
    printf("\nReverse the order of  the element on the stack\n");
    reverse_order(&s);
    printStack(s);
    //Remove negative numbers from the stack
    printf("Remove negative value\n");
    remove_negative(&s);
    printStack(s);
    printf("The first element in the stack is: %d\n",first_element(s));
    printf("\nRecursive reversed Stack:\n");
    recursive_reverse(&s);
    printStack(s);
    return 0;
}