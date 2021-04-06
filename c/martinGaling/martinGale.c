#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main()
{
    
    float total;
    float prcnt;    
    int max;
   
    printf("ur balance!\n");
    scanf("%f",&total);
    
    printf("pourcentage of the share!\n");
    scanf("%f",&prcnt);
    
    printf("Max time of trade\n");
    scanf("%d",&max);
    
    float array[max];
    
    float start, recover, nextPrice, tempStart;
    
    start = total * 1.5 / 100;
    array[0] = start;
    
    printf("next trade\t");
    printf("gain\t\t");
    printf("total gain\t");
    printf("spent\n");



    for(int i = 1; i < max; i++)
    {
        float spent = 0;
        //spent 
        for(int j = 0;j < i; j++)
        {
            spent += array[j];
        }
        
        recover = array[i - 1] / prcnt * 100;
        array[i] = recover + spent;
        //array[i] = recover + ( start * (i + 1) );
        
    }

    
    float gain;
    for(int i = 0; i < max; i++)
    {
        float spent = 0;
        //spent 
        for(int j = 0;j <= i; j++)
        {
            spent += array[j];
        }
        gain = array[i] * prcnt / 100;
        
        if(spent > gain + array[i])
        {

            break;
        }
        

        printf(ANSI_COLOR_YELLOW "%f\t" ANSI_COLOR_RESET, array[i]);
        printf("%f\t", gain);
        printf("%f\t", gain + array[i]);
        printf("%f\n", spent);


        
    }

    return 0;
}
