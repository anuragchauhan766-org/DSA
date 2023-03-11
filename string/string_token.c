
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char **split_string(char *text, char delim)
{
    char **result = (char **)malloc(1 * sizeof(char *));
    int size = 1;
    char *token = strtok(text, &delim);
    *result = token;
    while (token != NULL)
    {
        size++;
        result = (char **)realloc(result, size * sizeof(char *));
        token = strtok(NULL, &delim);
        result[size - 1] = token;
    }
    return result;
}
int main()
{
    char text[] = "Learning C is fun.\nLearning pointers is more fun.It is good to have pointers.";
    char **para = split_string(text, '\n');

    int npara = 0;
    while (para[npara] != NULL)
    {
        npara++;
    }
    printf("\n no of para -> %d\n", npara);

    char ****doc = (char ****)malloc((npara + 1) * sizeof(char ***));
    doc[npara] = NULL;

    int i = 0;
    while (para[i] != NULL)

    {
        char **sentence = split_string(para[i], '.');
        int no_of_sentences = 0;
        while (sentence[no_of_sentences] != NULL)
        {
            no_of_sentences++;
        }
        doc[i] = (char ***)malloc((npara + 1) * sizeof(char **));
        doc[i][no_of_sentences] = NULL;
        printf("no of sentences -> %d\n", no_of_sentences);
        int j = 0;
        while (sentence[j] != NULL)
        {
            // getting word inside sentence
            doc[i][j] = split_string(sentence[j], ' ');
            j++;
        }
        i++;
    }

    return 0;
}