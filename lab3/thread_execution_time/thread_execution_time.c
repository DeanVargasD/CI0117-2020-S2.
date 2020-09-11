#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void* run(){
	//Vacio.
	return NULL;
}

int main(int argc, char* arg[]){
    struct timespec start,stop;
    float minTime = 100000000000000000000.0;
	pthread_t thread;
    size_t trials = 1;
    
    if(argc>=2){
     trials = (size_t)strtoul(arg[1], NULL, 10);
    } 
     
    for(size_t i = 0; i<trials; ++i){
     clock_gettime(CLOCK_REALTIME,&start);
	 pthread_create(&thread, NULL, run, NULL);
     pthread_join(thread, NULL);
     clock_gettime(CLOCK_REALTIME,&stop);
     float time = (stop.tv_nsec - start.tv_nsec);
     if(time < minTime){
         minTime = time;
     }
    }

	printf("Minimum thread creation and destruction time was %3.2f nanoseconds among %zu trials\n",minTime,trials);
	

	return 0;
}
