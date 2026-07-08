#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid1, pid2;

    pid1 = fork();

    if(pid1 == 0)
    {
        printf("Executing who command:\n");
        execlp("who", "who", NULL);
    }
    else
    {
        pid2 = fork();

        if(pid2 == 0)
        {
            printf("Executing ls command:\n");
            execlp("ls", "ls", NULL);
        }
    }

    return 0;
}