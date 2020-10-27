#include <iostream>
#include <string> 
#include "omp.h"
using namespace std;

const int threads = 3;

static void calculate_sum(char **array, int array_size, double* global_sum) {
  double mysum = 0;
  for(int i=0; i<array_size; ++i){
      cout << "Thread " << omp_get_thread_num() <<" : proccessing number " << array[i] << endl;
      mysum += stoi(array[i]);
  }

  #pragma omp critical 
        {
            *global_sum+=mysum;
        }
}

int main(int argc, char *argv[])
{
    if ((argc-1) % threads != 0) {
        cout << "Invalid number of parameters.\n";
        return 1;
    }

    int work = (argc-1)/threads;
    double global_sum;

     #pragma omp parallel num_threads(threads)
    {
        calculate_sum(argv+1+(omp_get_thread_num()*work),work,&global_sum);
    }

    cout << "Average: " << (global_sum / (argc-1)) << endl;
    
    return 0;
}