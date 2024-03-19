#include <stdio.h>

void int_to_bit(int n)
{
    unsigned int m = 1 << sizeof(int) * 8 - 1;
    while(m)
    {
        printf("%d", n&m?1:0);
        m = m/2;
    }
    printf("\n");
}

int plus1 (int n)
{
    int m = 1;
    while(n&m)
    {
        n&=~m;
        m<<=1;
    }
    return n|m;
}

int tminus1 (int n)
{
    return plus1(~n);
}

int main()
{
    int x = 77;
    int_to_bit(x);

    printf("%d\n", plus1(x));

    printf("%d\n", tminus1(x));

    return 0;
}