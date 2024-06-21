void printStack(st s){
 
    element e;
    printf("\nStack");
    while(topSt(s,&e)){
        popSt(&s);
        printf("\n|%5d   |\n",e);
    }
    printf("|________|\n");
}