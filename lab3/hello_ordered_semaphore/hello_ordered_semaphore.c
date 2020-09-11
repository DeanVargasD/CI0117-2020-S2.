#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>

typedef struct {
    size_t total;
    size_t position;
    sem_t* semaphores;
} shared_data_t;

typedef struct {
    size_t thread_num;
    shared_data_t* shared_data;

} thread_data_t;

struct timespec start,stop;

void* helloWorld(void* args) {

    thread_data_t* data = (thread_data_t*) args;

    size_t thread_num = data->thread_num;
    shared_data_t* shared_data = data->shared_data;

    sem_wait(&shared_data->semaphores[thread_num]);

    printf("Thread %zu/%zu: I arrived at position %zu\n", thread_num+1, shared_data->total, shared_data->position);
    
    ++shared_data->position;
    if(thread_num < shared_data->total){

    sem_post(&shared_data->semaphores[thread_num+1]);

    }
    return NULL;
}

int main(int argc, char* arg[]) {

    size_t thread_count = 0;

    if (argc >= 2) {
        thread_count = (size_t)strtoul(arg[1], NULL, 10);
    } else {
        fprintf(stderr, "Error, invalid number of parameters\n");
        return 1;
    }
    clock_gettime(CLOCK_REALTIME,&start);
    pthread_t* threads = malloc((size_t)(thread_count * sizeof(pthread_t)));

    shared_data_t* shared_data = (shared_data_t*)calloc(1, sizeof(shared_data_t));
    shared_data->semaphores = (sem_t*)calloc(thread_count, sizeof(sem_t));

    shared_data->total = thread_count;
    shared_data->position = 1;
    
    sem_init(&shared_data->semaphores[0], 0, 1);
    for(size_t i = 1; i<thread_count; ++i){
     sem_init(&shared_data->semaphores[i], 0, 0);
    }  
    

    thread_data_t* thread_data_list = malloc((size_t)(thread_count * sizeof(thread_data_t)));

    for (size_t i = 0; i < thread_count; ++i) {
        thread_data_list[i].thread_num = i;
        thread_data_list[i].shared_data = shared_data;
        pthread_create(&threads[i], NULL, helloWorld, (void*)&thread_data_list[i]);
    }

    for (size_t i = 0; i < thread_count; ++i) {
        pthread_join(threads[i], NULL);
    }

     for (size_t i = 0; i < thread_count; ++i) {
        sem_destroy(&shared_data->semaphores[i]);
    }

    clock_gettime(CLOCK_REALTIME,&stop);
    size_t time = (stop.tv_nsec - start.tv_nsec);
    printf("execution time was %zu nanoseconds\n",time);

    free(threads);
    free(shared_data->semaphores);
    free(shared_data);
    

    return 0;
}