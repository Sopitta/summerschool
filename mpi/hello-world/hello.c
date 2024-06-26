#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    // TODO: say hello! in parallel
    int size, rank ;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    printf("Hello from rank %d of %d\n", rank, size);

    //printf("Hello!\n");

    MPI_Finalize();
}
