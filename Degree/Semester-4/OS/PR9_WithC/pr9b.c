#include <stdio.h>
#include <utmp.h>

int main()
{
    struct utmp *user;

    setutent();

    while((user = getutent()) != NULL)
    {
        if(user->ut_type == USER_PROCESS)
        {
            printf("%s\t%s\t(%s)\n",
                   user->ut_user,
                   user->ut_line,
                   user->ut_host);
        }
    }

    endutent();
    return 0;
}