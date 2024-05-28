#include "cozi.h"

Queue *createQueue()
{
    Queue *q;
    q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
        return NULL;
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