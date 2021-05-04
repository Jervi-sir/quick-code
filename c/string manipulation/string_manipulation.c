#include <stdio.h>

//---Decoration
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

//✔🥱calculate word length     (reccursively)
//✔😣merge two words
//✔😣test eauality of two words
//✔😣miror of words            (reccursively)
//✔🥱test if palindrome        (reccursively)
//✔😣occurance                 (reccursively)
//🐒🥺🤬Make menu and styling

int longeur(char w[], int index)
{
    static int l = 0;

    if (w[index] == '\0')
        return l;
    else
        l++;

    longeur(w, index + 1);
}

int compare(char *w1, char *w2)
{

    unsigned char c1, c2;
    do
    {
        c1 = (unsigned char)*w1++;
        c2 = (unsigned char)*w2++;
        if (c1 == '\0')
            return c1 - c2;
    } while (c1 == c2);
    return c1 - c2; //if 0 means w1 == w2 else not equal
}

char *concat(char *destination, const char *source)
{
    //jump the pointer to the end of the string
    char *ptr = destination + longeur(destination, 0);

    while (*source != '\0')
    {
        *ptr++ = *source++;
    }

    *ptr = '\0'; //terminate pointer from working

    return destination;
}

void reverse(char *str)
{
    if (*str)
    {
        reverse(str + 1);
        printf("%c", *str);
        //concat(str, w2);
    }
}

int palindrome(char str[], int s, int e)
{
    //if only one character
    if (s == e)
        return 1; //true

    //if first and last characters do not match
    if (str[s] != str[e])
        return 0; //false

    //if rest characters
    if (s < e + 1)
        return palindrome(str, s + 1, e - 1);

    return 1; //true
}

int occurrence(char w[], char letter[], int index)
{
    static int nb = 0;

    if (w[index] == '\0')
        return nb;
    else if (w[index] == letter[0])
        nb++;

    occurrence(w, letter, index + 1);
}

/*-----[ Option Menu ] -----*/
//done
void longueur_option()
{
    char w1[25];
    printf("Entrez votre mot\n");
    scanf("%s", w1);
    printf("la longueur est\t %d\n", longeur(w1, 0));
}

//done
void concat_option()
{
    char w1[25];
    char w2[25];

    printf("Entrez vos deux mots\n");
    scanf("%s", w1);
    scanf("%s", w2);

    concat(w1, w2);
    printf("concatenation:\t %s\n", w1);
}

//done
void compare_option()
{
    char w1[25];
    char w2[25];

    printf("Entrez vos deux mots\n");
    scanf("%s", w1);
    scanf("%s", w2);

    int test = compare(w1, w2); //1 => true, other then 1 => false
    if (test == 1)
        printf("les deux mot sont egaux\n");
    else
        printf("les deux mots sont different\n");
}

//done
void miroir_option()
{
    char w1[25];
    printf("Entrez votre mot\n");
    scanf("%s", w1);
    printf("Mirror:\t");
    reverse(w1);
}

//done
void palindrome_option()
{
    char w1[25];

    printf("Entrez votre mot\n");
    scanf("%s", w1);

    int n = longeur(w1, 0);
    int test = palindrome(w1, 0, n - 1);

    if (test == 1)
        printf("le mot " ANSI_COLOR_GREEN "est un palindome\n" ANSI_COLOR_RESET);
    else
        printf("le mot " ANSI_COLOR_RED "n'est pas palindrome\n" ANSI_COLOR_RESET);
}

void occurrence_option()
{
    char w1[25];
    char symbole[1];

    printf("Entrez votre mot\t");
    scanf("%s", w1);

    printf("\nEntrez un symbole\t");
    scanf("%s", symbole);

    int n = longeur(w1, 0);
    printf("\nNombre d'occurrence :\t %d", occurrence(w1, symbole, 0));
}

int main()
{
    int choix;

    printf(ANSI_COLOR_GREEN "\t Manipulation sur les mots\n\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "1" ANSI_COLOR_RESET " \t Calculer de la longueur d'un mot\n");
    printf(ANSI_COLOR_YELLOW "2" ANSI_COLOR_RESET " \t Concatener deux mots\n");
    printf(ANSI_COLOR_YELLOW "3" ANSI_COLOR_RESET " \t Comparer deux mots\n");
    printf(ANSI_COLOR_YELLOW "4" ANSI_COLOR_RESET " \t Donner le miroir d'un mot\n");
    printf(ANSI_COLOR_YELLOW "5" ANSI_COLOR_RESET " \t test si le mot est un palindrome\n");
    printf(ANSI_COLOR_YELLOW "6" ANSI_COLOR_RESET " \t Calculer le nombre d'occurrence\n");

    do
    {
        printf(ANSI_COLOR_GREEN "\nVeuillez choisir une option \n" ANSI_COLOR_RESET);
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            longueur_option();
            break;
        case 2:
            concat_option();
            break;
        case 3:
            compare_option();
            break;
        case 4:
            miroir_option();
            break;
        case 5:
            palindrome_option();
            break;
        case 6:
            occurrence_option();
            break;
        default:
            break;
        }
    } while (choix > 6);

    return 0;
}
