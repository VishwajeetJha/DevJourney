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
            printf("Child %d with PID %d is doing task %d\n", 
                   i + 1, getpid(), i + 1);

            sleep(2);

            printf("Child(PID %d) completed task %d\n", getpid(), i + 1);
            return 0;
        }
    }

    return 0;
}


// -------- Better Version of pr4a.c                         -------- 
// -------- but I hate myself, so I'mma use the lazy one :D  --------

/*

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static int is_prime(int number){
    if(number < 2){
        return 0;
    }

    for(int divisor = 2; divisor * divisor <= number; divisor++){
        if(number % divisor == 0){
            return 0;
        }
    }

    return 1;
}

int main(){
    int n, i;

    printf("Enter number of child processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        pid_t pid = fork();

        if(pid == 0){
            int task = i + 1;
            int start = (task - 1) * 10000 + 2;
            int end = task * 10000 + 1;
            int prime_count = 0;

            for(int number = start; number <= end; number++){
                if(is_prime(number)){
                    prime_count++;
                }
            }

            printf("Child %d with PID %d checked numbers %d-%d and found %d primes\n",
                   task, getpid(), start, end, prime_count);
            return 0;
        }
    }

    for(i = 0; i < n; i++){
        wait(NULL);
    }

    return 0;
}

*/