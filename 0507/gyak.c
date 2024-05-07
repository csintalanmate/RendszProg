#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    if (argc == 2 && strcmp(argv[1], "-c") == 0)
    {
        printf("titkosit\n");
    }
    else if (argc == 2 && strcmp(argv[1], "-d") == 0)
    {
        printf("dekódol\n");
    }
    else
    {
        fprintf(stderr, "Hiba! Használd a \"-c\" vagy a \"-d\" kpcsolókat!\n");
        exit(1);
    }

    char* home = getenv("HOME");
    if (chdir(home) != 0)
    {
        fprintf(stderr, "Hiba! Nem lehet belépni a Home könyvtárba!");
        exit(2);
    }

    DIR* d;
    struct dirent *entry;
    d = opendir(home);
    while ((entry = readdir(d)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }
    printf("Válasszon valamit a fenti listából!\n");
    char* valaszt = fgets(valaszt, 1000, stdin);

    printf("A választott fájl vagy mappa: %s\n", valaszt);

    char newdir[1000];
    int index = 0;

    while (index < strlen(home) + strlen(valaszt))
    {
        for (int i = 0; i < strlen(home); ++i)
        {
            newdir[index] = home[i];
            index++;
        }

        newdir[index] = '/';
        index++;

        for (int i = 0; i < strlen(valaszt);++i)
        {
            newdir[index] = valaszt[i];
            index++;
        }
    }

    printf("Az új mappa/fájl: %s\n", newdir);

    /*if (chdir(""))
    {
        printf("A fájl neve: %s\n");
    }
    else
    {
        printf("Nem fájl\n");
    }*/

    return 0;
}