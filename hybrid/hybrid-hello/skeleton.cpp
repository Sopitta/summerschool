#include <cstdio>
#include <mpi.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    int my_id, omp_rank;
    int provided, required=MPI_THREAD_FUNNELED;

    /* TODO: Initialize MPI with thread support. */

    /* TODO: Find out the MPI rank and thread ID of each thread and print
     *       out the results. */

    /* TODO: Investigate the provided thread support level. */
    MPI_Init_thread(&argc, &argv, required, &provided);


    #pragma omp parallel private(omp_rank)
    {
        omp_rank = omp_get_thread_num();
        MPI_Comm_rank(MPI_COMM_WORLD, &my_id); //determines the rank of the calling process
        printf("I'm thread %d in process %d\n", omp_rank, my_id);

    }

    MPI_Finalize();
    return 0;
}
