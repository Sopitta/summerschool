#include <iostream>
#include <mpi.h>

int main(int argc, char *argv[])
{
    // TODO: say hello! in parallel
    MPI_Init(&argc, &argv);
    std::cout << "Hello!" << std::endl;
    MPI_Finalize();
}
