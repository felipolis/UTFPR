#include <stdio.h>

int main(){

    int i;

    for ( i = 1000; i <= 2000; i++)
    {
        if(i % 11 == 5 ){
            printf("%d \n", i);
        }
    }
    
    return 0;
}