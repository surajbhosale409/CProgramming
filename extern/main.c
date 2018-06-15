#include <stdio.h>

extern int worked();

int main() {
    extern int a;
    extern char str;
    
    int (*fPtr) () = worked;

    fscanf(stdin,"%d",&a);
    fscanf(stdin,"%c",&str);
    fprintf(stdout,"%d",fPtr());

    return 0;
}
