
#include <stdio.h>
#include <math.h>

void init(int *t, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        t[i] = 0;
    }
}
int max(int n, int m)
{
    if (n > m)
        return n;
    return m;
}
int alldiffrent(int *t, int n)
{
    int i = 0, j = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (t[i] == t[j])
                return 0;
        }
    }
    return 1;
}
void generate_and_test(int *t, int n, int j)
{
    int p, l, k, i;
    p = pow(j, n);
    for (i = 0; i < p; i++)
    {
        for (l = 0; l < n; l++)
        {
            if ((i) % (int)pow(j, l) == 0)
            {
                t[n - l - 1] = max(1, (t[n - l - 1] + 1) % (j + 1));
            }
        }
        for (k = 0; k < n; k++)
        {
            printf("P[%d]=%d  ", k, t[k]);
        }
        if (alldiffrent(t, n) == 1)
            printf("C'est une solutions \ ");
        else
            printf("Pas une solutions \ ");
        printf("\n");
    }
}
main()
{
    int n, i, j, k, l = 0;
    printf("Donner Le nombre des pigeons N : \n");
    scanf("%d", &n);
    printf("Donner Le nombre des nids K : \n");
    scanf("%d", &j);
    int t[n];
    init(t, n);
    generate_and_test(t, n, j);
}