#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 256

typedef struct{
    char nome_arquivo[100];
    time_t data_modificacao;
    size_t quantidade_caracteres;
} FileInfo;
