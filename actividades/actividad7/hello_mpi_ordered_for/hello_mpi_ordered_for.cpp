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
        MPI_Recv(&message_received, 1 /* count*/, MPI_INT, 0 /*source*/, my_id/*message id*/, MPI_COMM_WORLD, &status);
        cout << "Hello. I am process: " << my_id << ". Total processes: " << num_processes << ". msg: " << message_received<< endl;
    } else {
        cout << "Hello. I am process: " << my_id << ". Total processes: " << num_processes << endl;
        for(int i = 1; i<num_processes; ++i){
        message_sent = i;
        MPI_Ssend(&message_sent, 1 /*count*/, MPI_INT, i /*dest*/,i/*message id*/, MPI_COMM_WORLD);
        }
        
    }
    


    MPI_Finalize();

    return 0;
}