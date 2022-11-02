#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define VSIZE 1000
#define MASTER 0
#define FROM_MASTER 1
#define FROM_WORKER 2

//serial code
int main(int argc, char *argv[]) {
    double start,end;
    MPI_Init(&argc, &argv);
    start=MPI_Wtime();
    int i;
    long double a[VSIZE], b[VSIZE], c[VSIZE];

    for (i = 0; i < VSIZE; i++) {
        a[i] = i * 156.678;
    }

    for (i = 0; i < VSIZE; i++){
        b[i] = i * 2.0078;
    }

    for (i = 0; i < VSIZE; i++) {
        c[i] = a[i] + b[i];
    }

    printf("\nResultant Vector:\n");

    for (i = 0; i < VSIZE; i++) {
        printf("\n%Lf +%Lf = %Lf ", a[i],b[i],c[i]);
    }
    
    printf("\nFinished.\n");
    end=MPI_Wtime();
    printf("\nTime= %f",end-start);
    return 0;
}