#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 1000

int a[SIZE], b[SIZE], sum[SIZE], sub[SIZE];

int main()
{
    int i;
    pid_t pid1, pid2;

    for(i = 0; i < SIZE; i++)
    {
        a[i] = i + 1;
        b[i] = i + 2;
    }

    pid1 = fork();

    if(pid1 == 0)
    {
        for(i = 0; i < SIZE; i++)
            sum[i] = a[i] + b[i];

        printf("Addition completed by Child 1\n");
        return 0;
    }

    pid2 = fork();

    if(pid2 == 0)
    {
        for(i = 0; i < SIZE; i++)
            sub[i] = a[i] - b[i];

        printf("Subtraction completed by Child 2\n");
        return 0;
    }

    wait(NULL);
    wait(NULL);

    return 0;
}