#include<stdio.h>
#include<stdlib.h>


int main()
{
        int ***A;
        int **B;
        int *C;
        int D;
        printf("The Size of A is = %d, Size of B is = %d ,Size of C is = %d ,Size of D is = %d \n",sizeof(A),sizeof(B),sizeof(C),sizeof(D));
        A = (int***) malloc(sizeof(int***));
        B = (int**) malloc(sizeof(int**));
        C = (int*) malloc(sizeof(int*));
        *C = D;
        D = 8;
        ***A = *C;
        printf("the value pointed by c is %d",*C);
       
}
