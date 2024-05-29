#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "team.h"

struct TeamNode
{
    Team val;
    struct TeamNode *next;
};

typedef struct TeamNode TeamNode;

struct Queue
{
    TeamNode *front;
    TeamNode *rear;
};

typedef struct Queue Queue;

Queue *createQueue();
int isEmptyQ(Queue *q);
Team deQueue(Queue *q);
TeamNode *deQueueMove(Queue *q);
void enQueue(Queue *q, Team v);
void enQueueMove(Queue *q, TeamNode *aux);
void deleteQueue(Queue *q);
void compareTeams1(Queue *Winners, Queue *Losers, int **adjMatrix, Team t1, Team t2);
void compareTeams2(Queue *Winners, Queue *Losers, int **adjMatrix, TeamNode *t1, TeamNode *t2);
void compareTeams3(Queue *Losers, int **adjMatrix, TeamNode *t1, TeamNode *t2);