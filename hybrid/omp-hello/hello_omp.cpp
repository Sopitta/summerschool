#include <cstdio>
#include <omp.h>
int main()
{
    int tid, nthreads;
    printf("Hello world!\n");
    #pragma omp parallel private(tid) shared(nthreads)
    {
        tid = omp_get_thread_num();
        nthreads = omp_get_num_threads();
        printf("  ... from thread ID %i.\n", tid);
    }
    printf("There were %i threads in total.\n", nthreads);

    return 0;
  
}

