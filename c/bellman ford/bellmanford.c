/*  [Bellman Ford Algorith -- C --] 

    Description: in the end
    12/March/2021 -> sameday
*/
#include <stdio.h>
#include <stdlib.h>

#define INFINI 999;

/*-- Strucutre pour les Noeud --*/
struct Arc
{
    int source;
    int destination;
    int poid;
};

/*-- Strucutre pour le graph --*/
struct Graph
{
    int nb_sommet;
    int nb_arc;
    struct Arc *arc;
};

/*-- Creer le graph --*/
struct Graph *create_graph(int nb_sommet, int nb_arc)
{
    //Allocate space for this graph
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));

    graph->nb_sommet = nb_sommet;
    graph->nb_arc = nb_arc;

    //creer kinda a tableau to save the arc,
    graph->arc = (struct Arc *)malloc(graph->nb_arc * sizeof(struct Arc));

    return graph;
}

//afficher le resultat final s il n existe pas de cycle negative
void solution_finale(int dist[], int n)
{
    printf("\nVertex\tDistance from Source Vertex\n");

    for (int i = 0; i < n; ++i)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

/*--
    Bellmanford Algorithm, 
    detect negative cycle, 
    ask to display result
--*/
void bellman_ford(struct Graph *graph, int source)
{
    int nb_sommet = graph->nb_sommet;
    int nb_arc = graph->nb_arc;

    int save_dist[nb_sommet];

    //initialiser all distances to infiniti
    for (int i = 0; i < nb_sommet; i++)
    {
        save_dist[i] = INFINI; //tous en infini
    }

    //make source's distance to 0
    save_dist[source] = 0;

    //Executer l'algorithm
    for (int i = 1; i <= nb_sommet - 1; i++)
        for (int j = 0; j < nb_arc; j++)
        {
            int s = graph->arc[j].source;
            int d = graph->arc[j].destination;
            int p = graph->arc[j].poid;

            if (save_dist[s] + p < save_dist[d])
            {
                save_dist[d] = save_dist[s] + p;
            }
        }

    //detecter sil exist un cycle negative
    for (int i = 0; i < nb_arc; i++)
    {
        int s = graph->arc[i].source;
        int d = graph->arc[i].destination;
        int p = graph->arc[i].poid;

        if (save_dist[s] + p < save_dist[d])
        {
            printf("Ce graph contien un cycle negative");
            return;
        }
    }
    solution_finale(save_dist, nb_sommet);
}

int main()
{
    int nb_sommet;
    int nb_arc;
    int source;

    printf("Entrez nombre de noeuds\n");
    scanf("%d", &nb_sommet);
    while (nb_sommet < 0) //if source Negative
    {
        printf("[Nombre de noeuds doit etre positive]\n");

        printf("Entrez nombre de noeuds\n");
        scanf("%d", &nb_sommet);
    }

    printf("Entrez nombre d'arcs\n");
    scanf("%d", &nb_arc);
    while (nb_arc < 0) //if source Negative
    {
        printf("[Nombre d'arcs doit etre positive]\n");

        printf("Entrez nombre d'arcs\n");
        scanf("%d", &nb_arc);
    }

    printf("Entrez le numerau de la source\n");
    scanf("%d", &source);
    while (source < 0) //if source Negative
    {
        printf("[Le numerau de la source doit etre positive]\n");

        printf("Entrez le numerau de la source\n");
        scanf("%d", &source);
    }

    //creer un graph
    struct Graph *graph = create_graph(nb_sommet, nb_arc);

    //save les arcs
    for (int i = 0; i < nb_arc; i++)
    {
        printf("\nArc %d: Source, destination, poid\n", i);

        /*Verivication Naive way*/
        //Source
        printf("Source:\t\t");
        scanf("%d", &graph->arc[i].source);
        while (graph->arc[i].source < 0 || graph->arc[i].source > nb_sommet - 1) //if source Negative or greater
        {
            printf("{ Source doit etre entre [0 et %d] }\n", nb_sommet - 1);
            printf("Source:\t\t");
            scanf("%d", &graph->arc[i].source);
        }

        //Destination
        printf("Destination:\t");
        scanf("%d", &graph->arc[i].destination);
        while (graph->arc[i].destination < 0 || graph->arc[i].destination > nb_sommet - 1) //if destination Negative or greater
        {
            printf("{ Destination doit etre entre [0 et %d] }\n", nb_sommet - 1);
            printf("Destination:\t");
            scanf("%d", &graph->arc[i].destination);
        }

        //Poid
        printf("Poid:\t\t");
        scanf("%d", &graph->arc[i].poid);
    }

    //solution
    bellman_ford(graph, source);

    return 0;
}

/* [Details]
    date: 12/march/2021 10:00pm
    author: Gacem -Jervi-
    language: C
    compiler: 6.3.0
    github: https://github.com/Jervi-sir/quick-code/tree/main/c/bellman%20ford
*/

/*  [Bellman Ford Algorith in c]

    links   :   https://www.youtube.com/watch?v=FtN3BYH2Zes&t=10s
                https://www.youtube.com/watch?v=lyw4FaxrwHg&t=279s

    --idea--
        is to turn point of view of the graph as couple of structured arc not node,
        since the algorithm works with arcs, a structure of arc ll store source destination weight
        the run the algorithm,.... 

    --Todo--
    [done] 1. make structure ta3 ::
                .. Neud, fiha: le poid, source, destination
                .. Graph, fih: S -> nb de sommet, A -> nb d arc, et Neud
    [done] 2. CreateGraph(Sommet, Arc) 
                return Graph
    [done]3. Bellman ford Algorithm(Graph, Source)
                ..get nb S, nb A, 
                ..create table to store distances,
                ..and wah i, j ta3 for loop
                ..for loop to initialise all table by INF
                    ..and ta3 source dirha 0
                ..for loop i 1 -> S     bah tel9a short path
                    for loop j 0 -> A
                        source, destination, poid in temp variable
                        if(Distarray[s] + p < Distarray[a])
                            Distarray[d] = p + Distarray[s]
                ..for loop 0 -> A       bah tvirifi cicle negative
                    source, destination, weight temp value
                    if(Distarray[s] + p < Distarray[d])
                        printf cycle negative
                ..show result final(Distarry, nb neud)
    [done]4. finalSolution(array[], source) just to display array
    [done]5. main::
                . ask for nb Node, nb Arc, Node source(its number)
                . create graph(nb Node, nb Arc)
                . ask au fur et au mesure les Nodes(source, destination, poid)
                . Bellmanford(graph, S)
*/
