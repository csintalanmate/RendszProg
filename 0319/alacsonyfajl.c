#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int args, char const * argv[])
{
    srand(time(NULL));
    float ertekek [1000];

    float x;

    for (int i = 0;i < 1000;++i)
    {
        ertekek[i] = (float)rand()/RAND_MAX*1000000000.0;
    }

    int f = open("szamok.txt", O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
    write(f,ertekek, 1000*sizeof(float));
    lseek(f, 822*4, SEEK_SET);
    read(f,&x,4);
    printf("%f", x);
    close(f);

    return 0;
}