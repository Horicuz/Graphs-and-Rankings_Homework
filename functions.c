#include "functions.h"

int isLetterOrNumber(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
        return 1;
    }
    return 0;
}

void checkFile(FILE *file)
{
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
}

void closeFiles(FILE *input1, FILE *input2, FILE *output)
{
    fclose(input1);
    fclose(input2);
    fclose(output);
}

Team createTeam(int id, char *name, float score)
{
    Team t;
    t.id = id;
    t.name = (char *)malloc(100 * sizeof(char));
    strcpy(t.name, name);
    t.score = score;
    t.wins = 0;
    return t;
}

Team readTeam(FILE *input, int j)
{
    char *name = (char *)malloc(100 * sizeof(char));
    char auxChar;
    float score;

    fscanf(input, "%f", &score);
    fscanf(input, "%c", &auxChar);
    while (fscanf(input, "%c", &auxChar) && auxChar != '\n')
    {
        name[strlen(name)] = auxChar;
    }
    for (int i = strlen(name) - 1; i >= 0; i--)
    {
        if (isLetterOrNumber(name[i]) == 0)
        {
            name[i] = '\0';
        }
        else
        {
            name[i + 1] = '\0';
            break;
        }
    }
    Team t1 = createTeam(j, name, score);
    return t1;
}

void printMatrix(FILE *output, int **adjMatrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(output, "%d ", adjMatrix[i][j]);
        }
        fprintf(output, "\n");
    }
}

void freeMatrix(int **adjMatrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
}

float power(float x, int y) // x^y
{
    float result = 1;
    for (int i = 0; i < y; i++)
    {
        result *= x;
    }
    return result;
}

float calculatePrestige(float q, int l, int r)
{
    return (float)((float)q * (float)power((float)(2 - q), r)) / ((float)power((float)2, l) + (float)power((float)(2 - q), l) * (float)(q - 1));
}