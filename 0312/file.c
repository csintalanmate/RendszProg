#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int args, char const * argv[])
{
    srand(time(NULL));
    float ertekek [1000];

    float x;

    for (int i = 0;i < 1000;++i)
    {
        ertekek[i] = (float)rand()/RAND_MAX*1000000000.0;
    }

    FILE* f = fopen("szamok.txt", "w");
    for (int i = 0;i < 1000;++i)
    {
        fprintf(f, "%18f", ertekek[i]);
    }
    fseek(f, 823*18, SEEK_SET);
    fscanf(f,"%f",&x);
    printf("%f", x);
    fclose(f);

    return 0;
}