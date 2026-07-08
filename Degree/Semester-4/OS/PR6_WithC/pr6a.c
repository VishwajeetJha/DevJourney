#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int shmid;
    char *str;

    shmid = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);

    str = (char *)shmat(shmid, NULL, 0);

    if(fork() == 0)
    {
        strcpy(str, "Hello from Child Process");
        printf("Child wrote: %s\n", str);
    }
    else
    {
        sleep(1);
        printf("Parent read: %s\n", str);
    }

    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}