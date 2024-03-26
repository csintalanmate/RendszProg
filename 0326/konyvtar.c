#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

FILE* browse()
{
    char valasz[1024];
    DIR *d;
    struct dirent *entry;
    struct stat inode;

    chdir(getenv("HOME"));
    do{
        d=opendir(".");

        while((entry=readdir(d))!=NULL)
        {
            printf("%s\t",(*entry).d_name);
        }

        closedir(d);

        printf("\nVálassz! ");
        scanf("%s", valasz);

        if(stat(valasz,&inode) < 0)
        {
            continue;
        }

        if(inode.st_mode&S_IFREG)
        {
            break;
        }
        chdir(valasz);
    } while(1);
    return fopen(valasz,"r+");
}

int main()
{
    FILE *f;
    char c;
    f = browse();
    while(!feof(f))
    {
        fscanf(f, "%c", &c);
        fprintf(stdout, "%c", c);
    }
    fclose(f);

    return 0;
}