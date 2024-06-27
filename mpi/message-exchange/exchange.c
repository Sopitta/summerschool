#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, ntasks, nrecv;
    int arraysize = 100000;
    int msgsize = 100;
    int *message;
    int *receiveBuffer;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Allocate buffers
    message = (int *)malloc(sizeof(int) * arraysize);
    receiveBuffer = (int *)malloc(sizeof(int) * arraysize);

    // Initialize message and receive buffer
    for (int i = 0; i < arraysize; i++) {
        message[i] = rank;
        receiveBuffer[i] = -1;
    }

    // TODO: Implement sending and receiving as defined in the assignment
    // Send msgsize elements from the array "message", and receive into
    // "receiveBuffer"
    if (rank == 0) {

        MPI_Send(message, msgsize, MPI_INT, 1, 0, MPI_COMM_WORLD);
	MPI_Recv(receiveBuffer, msgsize, MPI_INT, 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        printf("Rank %i received %i elements, first %i\n", rank, nrecv, receiveBuffer[0]);
    } else if (rank == 1) {

	MPI_Recv(message, msgsize, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	MPI_Send(receiveBuffer, msgsize, MPI_INT, 0, 1, MPI_COMM_WORLD);

        printf("Rank %i received %i elements, first %i\n", rank, nrecv, receiveBuffer[0]);
    }

    // Free buffers
    free(message);
    free(receiveBuffer);

    MPI_Finalize();
    return 0;
}
