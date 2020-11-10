#include <iostream>
#include <cmath>
#include <stdio.h>
#include <omp.h>

int main(int argc, char* argv[]){

    int n;
    int primes = 0;

    if(argc > 1){
        sscanf(argv[1], "%d", &n);
    }
    else
        return 0;

#pragma omp parallel for reduction(+: primes) schedule(runtime)
    for(int i = 2; i <= n; ++i){
        ++primes;
        for(int j = 2; j <= (int)sqrt(i); ++j){
            if(i % j == 0){
                --primes;
                break;
            }
        }
    }

    std::cout<<"Primes = "<<primes<<std::endl;

}
