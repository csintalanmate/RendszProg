#include <stdio.h>
#include <stdlib.h>

typedef struct ize{
    int adat;
    struct ize * bal, * jobb;
} ELEM;

void beszur(int a, ELEM** gyoker)
{
    if (*gyoker == NULL)
    {
        gyoker = calloc(1, sizeof(ELEM));
        (**gyoker).adat = a;
        return;
    }
    
    if ((**gyoker).adat == a)
    {
        return;
    }
    
    if ((**gyoker).adat > a)
    {
        beszur(a,(**gyoker).bal);
    }
    else
    {
        beszur(a,(**gyoker).jobb);
    }
}

ELEM* keres(int a, ELEM** gyoker)
{
    if (*gyoker == NULL)
    {
        return NULL;
    }

    if ((**gyoker).adat == a)
    {
        return *gyoker;
    }

    if ((**gyoker).adat > a)
    {
        return keres(a, (**gyoker).bal);
    }
    else
    {
        return keres(a, (**gyoker).jobb);
    }
}

void inorder(ELEM* gyoker)
{
    if (gyoker == NULL)
    {
        printf("%d ", (*gyoker).adat);
    }

    inorder((*gyoker).bal);
    inorder((*gyoker).jobb);
}

int main(int args, char const * argv[])
{
    ELEM* gy = NULL;

    beszur(10,gy);
    beszur(4, gy);
    beszur(21, gy);
    beszur(7, gy);
    beszur(5, gy);
    beszur(2, gy);
    beszur(11, gy);


    inorder(gy);
    
    return 0;
}