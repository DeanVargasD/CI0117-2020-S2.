#include <iostream>
#include <string> 
#include "omp.h"
using namespace std;

const int threads = 3;

int main(int argc, char *argv[])
{
    if ((argc-1) % threads != 0) {
        cout << "Invalid number of parameters.\n";
        return 1;
    }

    
    double global_sum;

    #pragma omp parallel for num_threads(threads) shared(global_sum,cout) 

         for(int i=0; i<argc-1; ++i){
            #pragma omp critical(global_sum)
            
             cout << "Thread " << omp_get_thread_num() <<" : iteration " << i << endl;
             global_sum += stoi(argv[i+1]);
            
         }



    cout << "Average: " << (global_sum / (argc-1)) << endl;
    
    return 0;
}