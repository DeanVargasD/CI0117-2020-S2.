#include <iostream>
#include <string> 
#include "omp.h"
using namespace std;

const int threads = 3;

int main()
{
    cout << "parallel for"<< endl;
    #pragma omp parallel for num_threads(threads)
         for(int i=0; i<5; ++i)
            cout << "Thread " << omp_get_thread_num() <<" : iteration " << i << endl;
         
    cout << endl;
    cout << "parallel, for"<< endl;
    #pragma omp parallel num_threads(threads)
        #pragma omp for 
            for(int i=0; i<5 ;++i)
                cout << "Thread " << omp_get_thread_num() <<" : iteration " << i << endl;
     
    
    cout << endl;
    cout << "for"<< endl;
    #pragma omp for
        for(int i=0; i<5; ++i)
            cout << "Thread " << omp_get_thread_num() <<" : iteration " << i << endl;
        
    return 0;
}