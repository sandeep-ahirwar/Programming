#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#define MASTER 0
#define ARRAY_SIZE 8

int main (int argc, char *argv[]) {
    int * a, * b, * sum, total_proc;
    int rank, n_per_proc, n=ARRAY_SIZE, i;

    MPI_Init (&argc, &argv);
    MPI_Comm_size (MPI_COMM_WORLD, &total_proc);
    MPI_Comm_rank (MPI_COMM_WORLD,&rank);

    int * a_pvt, * b_pvt, * sum_pvt;

    if (rank == MASTER) { // initialise array
        a = (int *) malloc(sizeof(int)*n);
        b = (int *) malloc(sizeof(int)*n);
        sum = (int *) malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
            a[i] = i;
        for(i=0;i<n;i++)
            b[i] = i;
    }

    n_per_proc = n/total_proc;
    a_pvt = (int *) malloc(sizeof(int)*n_per_proc);
    b_pvt = (int *) malloc(sizeof(int)*n_per_proc);
    sum_pvt = (int *) malloc(sizeof(int)*n_per_proc);

    MPI_Scatter(a, n_per_proc, MPI_INT, a_pvt, n_per_proc, MPI_INT, MASTER, MPI_COMM_WORLD);
    MPI_Scatter(b, n_per_proc, MPI_INT, b_pvt, n_per_proc, MPI_INT, MASTER, MPI_COMM_WORLD);
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    for(i=0;i<n_per_proc;i++){
        sum_pvt[i] = a_pvt[i]+b_pvt[i];
        printf("Sum Done on %s\n", processor_name);
        printf("Sum ~ %d\n", sum_pvt[i]);
    }

    MPI_Gather(sum_pvt, n_per_proc, MPI_INT, sum, n_per_proc, MPI_INT, MASTER, MPI_COMM_WORLD);
    if (rank == MASTER) {
        free(a); free(b); free(sum);
    }
    free(a_pvt); free(b_pvt); free(sum_pvt);
    MPI_Finalize();
    return 0;
}
