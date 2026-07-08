#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

void *process1(void *arg)
{
    sem_wait(&sem);

    printf("Process 1 is using shared resource\n");
    sleep(1);
    printf("Process 1 released resource\n");

    sem_post(&sem);
    return NULL;
}

void *process2(void *arg)
{
    sem_wait(&sem);

    printf("Process 2 is using shared resource\n");
    sleep(1);
    printf("Process 2 released resource\n");

    sem_post(&sem);
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    sem_init(&sem, 0, 1);

    pthread_create(&t1, NULL, process1, NULL);
    pthread_create(&t2, NULL, process2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem);

    return 0;
}