#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a+b;
}

int sub(int a, int b) {
    return a-b;
}

int main() {
    int (*ptr) (int,int);
    
    ptr=add;
    
    fprintf(stdout,"%d\n",ptr(1,4));

    ptr=sub;
    fprintf(stdout,"%d\n",ptr(5,4));

    return 0;
}
