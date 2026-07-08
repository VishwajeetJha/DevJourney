#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *d;
    struct dirent *dir;

    d = opendir(".");

    if(d == NULL)
    {
        printf("Unable to open directory\n");
        return 1;
    }

    while((dir = readdir(d)) != NULL)
    {
        printf("%s\t", dir->d_name);
    }
    printf("\n");

    closedir(d);

    return 0;
}