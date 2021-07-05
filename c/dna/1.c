#include <stdio.h>


int main()
{
    char dna[20];
    int i = 0;
    printf("Hello World\n");
    scanf("%s",&dna);
    
    char *ptr = dna;
    
    while(*ptr != '\0') {
        switch (*ptr)
        {
            case 'T': *ptr = 'A'; break;
            case 'A': *ptr = 'T'; break;
            case 'C': *ptr = 'G'; break;
            case 'G': *ptr = 'C'; break;
            default: break;
        }
        printf("%c", *ptr);
        ptr++;
    }
    
    
    
    
    return 0;
}
