#include <iostream>
#include "mpi.h"

using namespace std;

int main(int argc, char *argv[]) {

    int my_id, num_processes;
    int message_sent = 0;
    int message_received = 0;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    
    MPI_Comm_size(MPI_COMM_WORLD, &num_processes);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_id);

    if(my_id != 0){
        MPI_Recv(&message_received, 1 /* count*/, MPI_INT, my_id-1 /*source*/, my_id -1 /*message id*/, MPI_COMM_WORLD, &status);
    }
    if(my_id != num_processes-1){
        message_sent = my_id +1;
        MPI_Send(&message_sent, 1 /*count*/, MPI_INT, my_id+1 /*dest*/, my_id/*message id*/, MPI_COMM_WORLD);
    }
    

    cout << "Hello. I am process: " << my_id << ". Total processes: " << num_processes << endl;

    MPI_Finalize();

    return 0;
}