#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct mots mots;
struct mots
{
    char mot[26];
    int ligne;
    int position;
};

// Déclaration de la structure de données "maillon"
typedef struct maillon maillon;
struct maillon
{
    mots mots ;
    maillon* adrd;
    maillon* adrg;
};

// Définition du nouveau type Tptr (pointeur vers un maillon)
typedef maillon* Tptr;

// On alloue dynamiquement la structure de contrôle avec un malloc.
// La taille à allouer est calculée automatiquement avec sizeof(maillon).
// L'ordinateur saura qu'il doit allouer l'espace nécessaire au stockage de la structure maillon.

void Allouer(Tptr* p)
{
    *p = (Tptr)malloc(sizeof(maillon));
}

// Procédure qui détruit le maillon pointé par p.
void Liberer (Tptr p)
{
    free(p);
}

// Procédure qui affecte q dans le champ (adrd) du maillon pointé par p.
void Aff_adrd(Tptr p, Tptr q)
{
    p->adrd = q;     // (p->adr) est l'équivalent de (*p.adr)
}

// Procédure qui affecte q dans le champ (adrg) du maillon pointé par p.
void Aff_adrg(Tptr p, Tptr q)
{
    p->adrg = q;     // (p->adr) est l'équivalent de (*p.adr)
}

// Fonction qui retourne le contenu du champ (mot) du maillon pointé par p.
char* Mot(Tptr p)
{
    return p->mots.mot;
}

// Fonction qui retourne le contenu du champ (mot) du maillon pointé par p.
int Ligne (Tptr p)
{
    return p->mots.ligne;
}

// Fonction qui retourne le contenu du champ (mot) du maillon pointé par p.
int Position (Tptr p)
{
    return p->mots.position;
}

// Procédure qui permet d'affecter dans le champ mot de l'enregistrement Mots du maillon le mot récupéré à partir du texte

void Aff_Mot(Tptr p,char Mot[])
{
   strcpy( (p->mots.mot),(Mot) );
}

// Procédure qui permet d'affecter dans le champ ligne de l'enregistrement Mots du maillon la ligne dans laquelle se trouve le mot

void Aff_Ligne(Tptr p,int ligne)
{
  p->mots.ligne = ligne ;
}

// Procédure qui permet d'affecter dans le champ mot de l'enregistrement Mots du maillon la position du mot récupéré à partir du texte

void Aff_Position(Tptr p,int position)
{
  p->mots.position = position ;
}

// Fonction qui retourne le contenu du champ (adr) du maillon pointé par p.
Tptr Suivant (Tptr P)
{
    return P->adrd;
}

// Fonction qui retourne le contenu du champ (adr) du maillon pointé par p.
Tptr Precedent (Tptr P)
{
    return P->adrg;
}


// Déclaration de la structure de données "Case"
typedef struct Case Case;
struct Case
{
    char Caractere ;
    maillon* tete ;
    maillon* queue ;
};

// Fonction qui fait la conversion des lettres majuscules  en minuscules
char * strtolower( char * dest, const char * src )
 {
    char * result = dest;
    while (*dest++ = tolower( *src++ ));
    return result;
}

void PosMots (char* txt, const char* separateurs,Tptr* tete)
{
    int l = 1, pos = 1;
    Tptr q =NULL ,q1 = NULL;

    // On cherche à récupérer, un à un, tous les mots (token) du texte (txt)
    // et on commence par le premier.
    char* strToken = strtok ( txt, separateurs );

    Allouer(&q);
    *tete = q ;
    Aff_Mot(q,strToken);
    Aff_Position(q,pos);
    Aff_Ligne(q,l);
    Aff_adrg(q,NULL);
    Aff_adrd(q,NULL);
    pos++;

    strToken = strtok ( NULL, separateurs );

    while ( strToken != NULL )
    {
        if (strcmp (strToken,"\n") == 0)    // Si le mot extrait est un saut de ligne, on met à jour la ligne et la position
        {
            //strToken = strtok ( NULL, separateurs );
            l++;
            pos = 1;
        }
        else
        {
            Allouer(&q1);
            Aff_adrd(q,q1);
            Aff_adrg(q1,q);
            Aff_adrd(q1,NULL);
            Aff_Mot(q1,strToken);// On copie le contenu de strTocken dans le champ mot de la dernière case du tableau
            Aff_Ligne(q1,l);// On insère le numéro de la ligne
            Aff_Position(q1,pos);// On insère la position
            q = q1;

            pos++;
        }

        // On demande le token suivant.
        strToken = strtok ( NULL, separateurs );
    }
}


void Creation(Tptr tete ,Case Tab[],int *taille)
{
    Tptr p , q = NULL ,tete2, temp = NULL;
    for (int i=0;i<26;i++)
    {
        p = tete ;
        tete2 = NULL ;
        q = NULL ;
        while (p!= NULL)
        {
            if ((tolower(p->mots.mot[0]))== ('a'+i))
            {
              temp = Suivant(p);
              if (p == tete)
              {
                 tete = Suivant(p);
                 if (Suivant(p)!= NULL)
                 {
                   Aff_adrg(Suivant(p),NULL);
                 }
                 Aff_adrg(p,q);
                Aff_adrd(p,NULL);
                if (q!= NULL)
                {
                    Aff_adrd(q,p);
                }
              }
              else
              {
                if (Suivant(p)== NULL)
                 {
                    Aff_adrd(Precedent(p),NULL);
                    Aff_adrg(p,q);
                    Aff_adrd(p,NULL);
                    if (q!= NULL)
                    {
                     Aff_adrd(q,p);
                    }
                 }
                 else
                 {
                   Aff_adrd(Precedent(p),Suivant(p));
                   Aff_adrg(Suivant(p),Precedent(p));
                   Aff_adrg(p,q);
                   Aff_adrd(p,NULL);
                    if (q!= NULL)
                    {
                     Aff_adrd(q,p);
                    }
                 }
               }
               q = p;
               if (tete2 == NULL)
                 {
                   Tab[*taille].Caractere = p->mots.mot[0];
                   Tab[*taille].tete = p ;
                   tete2 = p ;
                  *taille = *taille +1 ;
              }
            }
            if (temp == NULL)
            {
                p = Suivant(p);
            }
            else
            {
              p = temp ;
              temp = NULL;
            }

        }
        Tab[(*taille)-1].queue=q;

    }
}

void Affich_LlcB(Tptr tete)
{
  Tptr p = tete ;

  while(p!= NULL)
  {
      printf("\nLe mot est : %s , Sa position est : %d , Sa ligne est : %d",p->mots.mot,p->mots.position,p->mots.ligne);
      printf("\n");
      p = Suivant(p);
  }
}

// Procédure qui permet de trier la liste des participants par ordre alphabétique
void Tri_Alphab(Tptr tete )
{
  bool permut  ;
  Tptr p  ;
  int temp ;
  char Mot [20];
  char car1 [20];
  char car2 [20];

  do
  {
      permut = false ;
      p = tete ;
      while (Suivant(p) != NULL)
      {
          strtolower( (car1),(p->mots.mot) ) ;
          strtolower( (car2),(Suivant(p)->mots.mot) ) ;
          if ( strcmp((car1),( car2 ) )>0 )
          {
              // Permutation des mots
              strcpy( (Mot) , (p->mots.mot) ) ;
              strcpy( (p->mots.mot) , ( Suivant(p)->mots.mot) );
              strcpy( (Suivant(p)->mots.mot) , (Mot) );
              // Permutation des lignes
              temp=p->mots.ligne ;
              p->mots.ligne= Suivant(p)->mots.ligne;
              Suivant(p)->mots.ligne = temp;
              // Permutation des positions
              temp=p->mots.position ;
              p->mots.position=Suivant(p)->mots.position;
              Suivant(p)->mots.position=temp;


              permut = true ;

          }
          p = Suivant(p) ;

      }

  }while ( permut == true);
}

void Creer_Struct(Case Tab[],Tptr tete,int* taille)
{
    Tptr p = Suivant(tete) ,q = tete;
    int i=0 ;

    Tab[0].Caractere=tolower(q->mots.mot[0]);

    while (p != NULL)
    {

      if ((tolower (p->mots.mot[0])) != (tolower(Precedent(p)->mots.mot[0])))
      {
          Tab[i+1].Caractere=tolower(p->mots.mot[0]);
          Tab[i].queue = Precedent(p);
          Tab[i].tete = q ;
          Aff_adrd(Precedent(p),NULL);
          Aff_adrg(p,NULL);
          q = p ;
          i++;
          *taille=*taille+1;


      }
      if (Suivant(p)==NULL)
               {
                 Tab[i].queue = p;
                 Tab[i].tete = q ;
                 Aff_adrd(p,NULL);
                 Aff_adrg(p,NULL);
                 *taille=*taille+1;
               }
      p = Suivant(p);
    }
}

void Affich_Struct(Case Tab[],int taille)
{
    Tptr p ;
    for(int i = 0;i<taille;i++)
    {
        p = Tab[i].tete;
        printf("\n Just to check :%s",Suivant(p)->mots.mot);

        //printf("\n> La lettre est : %c \n",Tab[i].Caractere);
        while (p != NULL)
         {
            printf("\n> Le mot est : %s \n",p->mots.mot);
            printf("\n> Sa position est %d \n",p->mots.position);
            printf("\n> Sa ligne est %d \n",p->mots.ligne);
            p=Suivant(p);
         }
    }

}

void Affich_LisLett(Case Tab[],char Carac,int taille)
   {
       int i =0 ;
       Tptr p ;
       for (i=0;i<taille;i++)
       {
          if ( (Tab[i].Caractere) == Carac)
            {
               p = Tab[i].tete;
               printf("\n Le mot     \t\t La ligne       \t\tLa position \n");
               printf("-------------------------------------------------------------------\n");
               while (p != NULL)
               {
                 printf("%-12s\t\t   %-18d\t\t %d\n",p->mots.mot,p->mots.ligne,p->mots.position);
                 p = Suivant(p);

               }
               printf("---------------------------------------------------------------------\n");
            }
       }
   }

void linearsearch(Tptr tete, Case Tab[], char x[], int *position, int *ligne, int Taille)
{
    Tptr p;
    int i;
    for (i=0;i<Taille;i++)
    {
        p= Tab[i].tete;
        while (p != NULL)
        {
            if(strcmp(p->mots.mot, x) == 0)
            {
            printf("%s\t\t   %d\t\t %d\n",p->mots.mot,p->mots.ligne,p->mots.position);
           // *position = p->mots.position;
            //*ligne = p->mots.ligne;
            //*trouv = true ;
            return;
            }
            p = p->adrd;
       }
    /*if (p == NULL)
    {
        //*trouv = false;
        printf("le mot mksh");
        return;*/
        if (p==NULL)
        {
            printf("le mot n'existe pas");
            return;
        }
    }
}

void jumpsearch(Tptr tete, char *x, int *position, int *ligne, int *trouv)
{
    struct maillon *p = tete;
    while (p != NULL)
    {
        if (strcmp(p->mots.mot , x) == 0)
        {
            printf("La valeur existe");
            *position = p->mots.position;
            *ligne = p->mots.ligne;
            *trouv = true;
            return;
        }
        else
        {
            if (strcmp(p->mots.mot, x) < 0)
            {
                if (p->adrd != NULL)
                    p = ((p->adrd)->adrd);
                else
                    p = NULL;
            }
            else if (strcmp(p->adrg->mots.mot, x) <= 0)
            {
                p = p->adrg;
            }
            else
                p = NULL;
        }
    }
    if (trouv == false)
    {
        printf("the value doesn't exist in the list");
    }
}

int main()
{
    Case Tmots [26] ;
    Tptr tete = NULL ;
    int position,ligne;
    int Taille = 0;
    // La définitions de séparateurs connus.
    const char* separateurs = " 1234567890±(),.:;()[]-!?</>\\|%%";
    // La chaine de caractères à traiter.
    char txt[] = " increasing interests in using magnetic resonance imaging only in radiation therapy require methods \n "
               " for predicting the computed tomography numbers from MRi data. Here we propose a simple voxel \n "
               " method to generate the pseudo-ct (pct) image using dual-contrast pelvic MRi data. the method is first \n "
               " trained with the CT data and dual-contrast MRI data (two sets of ZTE MRI with different sequences) of \n "
               " multiple patients, where the anatomical structures in the images after deformable image registration \n "
               " are segmented into several regions, and after MRi intensity normalizations a regression analysis is used \n "
               " to determine a two-variable polynomial function for each region to relate a voxel's two MRi intensity \n "
               " values to its CT number. We first evaluate the accuracy via the Hounsfield unit (HU) difference between \n "
               " the pseudo-CT and reference-CT (rCT) images and obtain the average mean absolute error as 40.3 ±2.9 \n "
               " HU from leave-one-out-cross-validation (LOOCV) across all six patients, which is better than most \n "
               " previous results and comparable to another study using the more complicated atlas-based method. \n "
               " We also perform a dosimetric evaluation of the treatment plans based on pCT and rCT images and find \n "
               " the average passing rate within 2% dose difference to be 95.4% in point-to-point dose comparisons. \n "
               " therefore, our method shows encouraging results in predicting the ct numbers. this polynomial \n "
               " method needs less computer storage than the interpolation method and can be readily extended to \n "
               " the case of more than two MRi sequences \n ";


    // Appel de la procédure PosMots
    PosMots(txt , separateurs,&tete);

    // Appel de la procédure Création 2
    Creation(tete,Tmots,&Taille);

    char lettre ;
    printf("\n> Veuillez donner une lettre : ");
    fflush(stdin);
    lettre =tolower(getchar());

    // Appel de la procédure Affich_LisLett
    Affich_LisLett(Tmots,lettre,Taille);

    // Appel de la procédure Tri_Alphab
    for (int n=0;n<Taille;n++)
    {
        Tptr point = Tmots[n].tete;
        Tri_Alphab(point);
    }

    printf("\n> Veuillez donner une lettre : ");
    fflush(stdin);
    lettre =tolower(getchar());

    // Appel de la procédure Affich_LisLett
    Affich_LisLett(Tmots,lettre,Taille);

        //Appel de la fonction jump_search
    /* for(int i = 0; i < 26; i++)
    {
        if(trouv == FALSE)
            jumpsearch(tete, "more", &position, &ligne, &trouv);
        else
            break;
    }
    if(trouv == TRUE)
        printf("La position: %d\nLa ligne : %d", position, ligne);
    else
        printf("Le Mot n'existe pas!\n"); */


    //Appel de la fonction linear_search
    printf("Quel mot voulez vous trouvez\n");
    fflush(stdin);
    char *mot;
    mot = getchar();
    linearsearch(tete, Tmots, *mot, &position, &ligne, Taille);
    printf("La position: %d\nLa ligne : %d", position, ligne);


    return 0 ;

}