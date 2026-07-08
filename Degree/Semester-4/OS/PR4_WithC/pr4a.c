#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int n, i;

    printf("Enter number of child processes: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
    {
        pid_t pid = fork();

        if(pid == 0)
        {
            printf("Child Process %d created with PID = %d\n", i + 1, getpid());
            return 0;
        }
    }
    
    return 0;
}