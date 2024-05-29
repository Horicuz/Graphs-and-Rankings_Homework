#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "team.h"

int isLetterOrNumber(char c);
void checkFile(FILE *file);
void closeFiles(FILE *input1, FILE *input2, FILE *output);
Team createTeam(int id, char *name, float score);
Team readTeam(FILE *input, int j);
void printMatrix(FILE *output, int **adjMatrix, int n);
void freeMatrix(int **adjMatrix, int n);
float calculatePrestige(float q, int l, int r);