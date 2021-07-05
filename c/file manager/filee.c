#include <stdio.h>
#include <unistd.h>

int main()
{
    FILE *fp;
    char ch = '\0';
    char filename[10];

    //create the file
    printf("Enter file name: \n");
    scanf("%s", filename);

    //if exist then just read and display
    if (access(filename, F_OK) == 0)
    {
        fp = fopen(filename, "r");
        do
        {
            /* Read single character from file */
            ch = fgetc(fp);
            /* Print character read on console */
            putchar(ch);
        } 
        while (ch != EOF); /* Repeat this if last read character is not EOF */
    }
    //doesnt exist, so create one
    else
    {
        
        printf("Enter data.(crtl + c to exit)\n");

        fp = fopen(filename, "w");

        while ((ch = getchar()) != EOF)
        {
            putc(ch, fp);
        }
    }
    fclose(fp);
    return 0;
}

/*
[create file]
[fill file]
[open file]
[read what inside file]
turn red file's content in array
apply the arc algorithm


*/