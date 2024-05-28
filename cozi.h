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
void enQueue(Queue *q, Team v);
void deleteQueue(Queue *q);