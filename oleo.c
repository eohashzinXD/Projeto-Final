#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "structs.h"
#include "pss.h"

void txt_to_bin(const char *nome_arq_txt){
    FILE *arq_txt, *arq_bin;
    char nome_arq_bin[100];
    char caractere;
    FileInfo info_arq;
    int ano, mes, dia;
    char linha[MAX_LINE_LENGTH];

    arq_txt = fopen(nome_arq_txt, "r");
    if (arq_txt == NULL)
    {
        perror("Erro ao abrir o arquivo de texto");
        return;
    }

    sprintf(nome_arq_bin, "%s.bin", nome_arq_txt);

    arq_bin = fopen(nome_arq_bin, "wb");
    if (arq_bin == NULL)
    {
        perror("Erro ao criar o arquivo binario");
        fclose(arq_txt);
        return;
    }

    while (fgets(linha, sizeof(linha), arq_txt) != NULL)
    {
        // Extrai a data, a quantidade de caracteres e o nome do arquivo da linha
        char data_str[20], qunatidade_str[10], nome_arquivo[100];
        sscanf(linha, "%s %s %[^\n]", data_str, qunatidade_str, nome_arquivo);

        // Converte a string de data para um objeto time_t
        sscanf(data_str, "%d-%d-%d", &dia, &mes, &ano);
        struct tm tm_data = {0}; // Inicializa com zero para evitar valores indesejados
        tm_data.tm_year = ano - 1900; // tm_year conta a partir de 1900
        tm_data.tm_mon = mes - 1;     // tm_mon é baseado em 0
        tm_data.tm_mday = dia;


        // Converte a estrutura tm para time_t
        info_arq.data_modificacao = mktime(&tm_data);

        // Converte a string de quantidade para size_t
        info_arq.quantidade_caracteres  = atoi(qunatidade_str);

        // Copia o nome do arquivo
        strcpy(info_arq.nome_arquivo, nome_arquivo);

        // Escreve as informações no arquivo binário
        fwrite(&info_arq, sizeof(FileInfo), 1, arq_bin);

        fclose(arq_txt);
        fclose(arq_bin);

        printf("Arquivo binario criado com sucesso: %s\n", nome_arquivo);
    }
    
    

}

void clear(){
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #endif    
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Uso: %s <arquivo.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int op=-1;

     while (op!=6){    
     
       do{    
             
            clear();
            printf("****************************\n");
            printf(" 1 - Inserir lote           \n");
            printf(" 2 - Eliminar lote          \n");
            printf(" 3 - Criar TXT para BIN     \n");
            printf(" 4 - Somatorio mensal (csv) \n");
            printf(" 5 - Listagem (csv)         \n");
            printf(" 6 - Encerrar               \n");              
            printf("****************************\n");
            op = input_d("Digite uma Opcao: 1-6\n");
           
       }while(op < 1 || op > 6);
       
       switch(op){
           
           case 1: 
           break;
                 
           case 2: 
           break;  
                 
           case 3: txt_to_bin(argv[1]);
           break;
                 
           case 4: 
           break;
                 
           case 5: 
           break;
           case 6: printf("Saindo...!");
           break;
         
       }        
     }

    

    return 0;
}
