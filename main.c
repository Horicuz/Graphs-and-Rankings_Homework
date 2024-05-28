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
    for (int i = 1; i <= 32; i = i + 2)
    {
        Team t1 = readTeam(input, i);
        Team t2 = readTeam(input, i + 1);

        if (t1.score > t2.score || (t1.score == t2.score && strcmp(t1.name, t2.name) > 0))
        {
            enQueue(Winners, t1);
            enQueue(Losers, t2);
            adjMatrix[t2.id - 1][t1.id - 1] = 1;
        }
        else if (t1.score < t2.score || (t1.score == t2.score && strcmp(t1.name, t2.name) < 0))
        {
            enQueue(Winners, t2);
            enQueue(Losers, t1);
            adjMatrix[t1.id - 1][t2.id - 1] = 1;
        }
    }
    remainingTeams = remainingTeams / 2;

    while (!isEmptyQ(Winners) && remainingTeams > 1)
    {
        Team t1 = deQueue(Winners);
        Team t2 = deQueue(Winners);

        if (t1.score > t2.score || (t1.score == t2.score && strcmp(t1.name, t2.name) > 0))
        {
            enQueue(Winners, t1);
            enQueue(Losers, t2);
            adjMatrix[t2.id - 1][t1.id - 1] = 1;
        }
        else if (t1.score < t2.score || (t1.score == t2.score && strcmp(t1.name, t2.name) < 0))
        {
            enQueue(Winners, t2);
            enQueue(Losers, t1);
            adjMatrix[t1.id - 1][t2.id - 1] = 1;
        }
        remainingTeams = remainingTeams / 2;
        printf("%d\n", remainingTeams);
    }
    Team aux = deQueue(Winners);
    deleteQueue(Winners);
    enQueue(Losers, aux);

    printMatrix(outputGraf, adjMatrix, 32);

    return 0;
}
