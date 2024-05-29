#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "cozi.h"

int main(int argc, char *argv[])
{
    FILE *input = fopen(argv[1], "r");
    checkFile(input);
    FILE *outputGraf = fopen(argv[2], "w");
    checkFile(outputGraf);
    FILE *outputScor = fopen(argv[3], "w");
    checkFile(outputScor);

    // task 1
    char *name = (char *)malloc(100 * sizeof(char));
    char auxChar;
    float score;
    Queue *Winners = createQueue();
    Queue *Losers = createQueue();

    int **adjMatrix = (int **)malloc(32 * sizeof(int *));
    for (int i = 0; i < 32; i++)
    {
        adjMatrix[i] = (int *)malloc(32 * sizeof(int));
        for (int j = 0; j < 32; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
    int remainingTeams = 32;
    for (int i = 0; i < 31; i = i + 2)
    {
        Team t1 = readTeam(input, i);
        Team t2 = readTeam(input, i + 1);
        compareTeams1(Winners, Losers, adjMatrix, t1, t2);
        // se compara echipele iar castigatoarea se pune in coada de Winners, iar cealalta in coada de Losers
        // se compara structurile de echipe si se aloca memorie, deoarece se adauga pentru prima data in coada
    }
    remainingTeams = remainingTeams / 2;
    while (!isEmptyQ(Winners) && remainingTeams > 2)
    {
        TeamNode *t1 = deQueueMove(Winners);
        TeamNode *t2 = deQueueMove(Winners);
        compareTeams2(Winners, Losers, adjMatrix, t1, t2);
        // se compara echipele iar castigatoarea se pune in coada de Winners, iar cealalta in coada de Losers
        // se compara nodurile de echipe si nu se aloca memorie, deoarece nodurile sunt deja in coada
        // doar se muta dintr-o coada in altas
        remainingTeams--;
    }
    compareTeams3(Losers, adjMatrix, Winners->front, Winners->front->next); // se compara ultimele 2 echipe
    free(Winners);                                                          // toate echipele sunt in coada de Winners
    printMatrix(outputGraf, adjMatrix, 32);                                 // afisare matrice de adiacenta
    freeMatrix(adjMatrix, 32);

    // task 2
    float q = 0.15;
    int l = 5;
    float prestige;
    int s = 0;

    while (s < 32)
    {
        Team aux21 = deQueue(Losers);
        prestige = calculatePrestige(q, l + 1, aux21.wins);
        fprintf(outputScor, "%.4f %s\n", prestige, aux21.name);
        s++;
    }

    free(Losers);
    closeFiles(input, outputGraf, outputScor);
    return 0;
}
