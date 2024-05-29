#include "cozi.h"

Queue *createQueue()
{
    Queue *q;
    q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(Queue *q, Team v)
{
    TeamNode *aux;
    aux = (TeamNode *)malloc(sizeof(TeamNode));
    if (aux == NULL)
    {
        printf("Eroare alocare memorie\n");
        exit(1);
    }
    aux->val = v;
    aux->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = aux;
    }
    else
    {
        q->rear->next = aux;
        q->rear = aux;
    }
}

Team deQueue(Queue *q)
{
    TeamNode *aux;
    Team v;
    if (q->front == NULL)
    {
        printf("Coada este goala\n");
        exit(1);
    }
    aux = q->front;
    v = aux->val;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(aux);
    return v;
}

TeamNode *deQueueMove(Queue *q)
{
    TeamNode *aux;
    if (q->front == NULL)
    {
        printf("Coada este goala\n");
        exit(1);
    }
    aux = q->front;
    if (q->front != q->rear)
    {
        q->front = q->front->next;
    }
    return aux;
}

void enQueueMove(Queue *q, TeamNode *aux)
{
    if (q->rear == NULL)
    {
        q->front = q->rear = aux;
    }
    else
    {
        q->rear->next = aux;
        q->rear = aux;
    }
}

int isEmptyQ(Queue *q)
{
    return (q->front == NULL);
}

void deleteQueue(Queue *q)
{
    TeamNode *aux;
    while (!isEmptyQ(q))
    {
        aux = q->front;
        q->front = q->front->next;
        free(aux);
    }
    free(q);
}
void compareTeams1(Queue *Winners, Queue *Losers, int **adjMatrix, Team t1, Team t2)
{
    if (t1.score > t2.score || (t1.score == t2.score && strcmp(t1.name, t2.name) > 0))
    {
        t1.wins++;
        enQueue(Winners, t1);
        enQueue(Losers, t2);
        adjMatrix[t2.id][t1.id] = 1;
    }
    else if (t1.score < t2.score || (t1.score == t2.score && strcmp(t1.name, t2.name) < 0))
    {
        t2.wins++;
        enQueue(Winners, t2);
        enQueue(Losers, t1);
        adjMatrix[t1.id][t2.id] = 1;
    }
}

void compareTeams2(Queue *Winners, Queue *Losers, int **adjMatrix, TeamNode *t1, TeamNode *t2)
{
    if (t1->val.score > t2->val.score || (t1->val.score == t2->val.score && strcmp(t1->val.name, t2->val.name) > 0))
    {
        t1->val.wins++;
        enQueueMove(Winners, t1);
        enQueueMove(Losers, t2);
        adjMatrix[t2->val.id][t1->val.id] = 1;
    }
    else if (t1->val.score < t2->val.score || (t1->val.score == t2->val.score && strcmp(t1->val.name, t2->val.name) < 0))
    {
        t2->val.wins++;
        enQueueMove(Winners, t2);
        enQueueMove(Losers, t1);
        adjMatrix[t1->val.id][t2->val.id] = 1;
    }
}

void compareTeams3(Queue *Losers, int **adjMatrix, TeamNode *t1, TeamNode *t2)
{
    if (t1->val.score > t2->val.score || (t1->val.score == t2->val.score && strcmp(t1->val.name, t2->val.name) > 0))
    {
        t1->val.wins++;
        enQueueMove(Losers, t2);
        enQueueMove(Losers, t1);
        adjMatrix[t2->val.id][t1->val.id] = 1;
    }
    else if (t1->val.score < t2->val.score || (t1->val.score == t2->val.score && strcmp(t1->val.name, t2->val.name) < 0))
    {
        t2->val.wins++;
        enQueueMove(Losers, t1);
        enQueueMove(Losers, t2);
        adjMatrix[t1->val.id][t2->val.id] = 1;
    }
}