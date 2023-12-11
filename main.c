#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void
exibir_ajuda()
{
    printf("Uso: gerar-senha [ OPÇÕES ]\n\n");

    printf("  -h                    imprime essa lista de opções e sai\n");
    printf("  -M                    desabilita as letras maiúsculas\n");
    printf("  -m                    desabilita as letras minúsculas\n");
    printf("  -n                    desabilita os números\n");
    printf("  -q <quantidade>       define a <quantidade> de senhas a serem geradas [padrão: 1]\n");
    printf("  -s                    desabilita os símbolos\n");
    printf("  -t <tamanho>          define o <tamanho> da(s) senha(s) [padrão: 16]\n");
}

char *
concatenar_strings(char *string1, char *string2)
{
    char *nova_string = malloc(strlen(string1) + strlen(string2) + 1);
    if (nova_string == NULL) {
        fprintf(stderr, "Erro ao tentar alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(nova_string, string1);
    strcat(nova_string, string2);
    return nova_string;
}

char *
gerar_senha(bool maiusculas, bool minusculas, bool numeros, bool simbolos, int tamanho)
{
    char *caracteres = "";
    
    if (maiusculas)
        caracteres = concatenar_strings(caracteres, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    if (minusculas)
        caracteres = concatenar_strings(caracteres, "abcdefghijklmnopqrstuvwxyz");
    
    if (numeros)
        caracteres = concatenar_strings(caracteres, "0123456789");
    
    if (simbolos)
        caracteres = concatenar_strings(caracteres, "!\"#$%%&'()*+,-./:;<=>?@[\\]^_`{|}~");

    if (strcmp(caracteres, "") == 0) {
        fprintf(stderr, "Você precisa habilitar pelo menos um conjunto de caracteres!\n");
        exit(EXIT_FAILURE);
    }

    char *senha = malloc(tamanho + 1);
    if (senha == NULL) {
        fprintf(stderr, "Erro ao tentar alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < tamanho; i++)
        senha[i] = caracteres[rand() % strlen(caracteres)];
    senha[tamanho] = '\0';

    return senha;
}

int
main(int argc, char *argv[])
{
    bool maiusculas = true;
    bool minusculas = true;
    bool numeros = true;
    int quantidade = 1;
    bool simbolos = true;
    int tamanho = 16;

    int c;
    while ((c = getopt(argc, argv, "hMmnq:st:")) != -1) {
        switch (c) {
            case 'h':
                exibir_ajuda();
                return 0;
            case 'M':
                maiusculas = false;
                break;
            case 'm':
                minusculas = false;
                break;
            case 'n':
                numeros = false;
                break;
            case 'q':
                quantidade = atoi(optarg);
                break;
            case 's':
                simbolos = false;
                break;
            case 't':
                tamanho = atoi(optarg);
                break;
            case '?':
                if (optopt == 't')
                    fprintf(stderr, "Opção -t requer um argumento.\n");
                else if (optopt == 'q')
                    fprintf(stderr, "Opção -q requer um argumento.\n");
                return 1;
            default:
                return 1;
        }
    }

    srand((unsigned int)time(NULL));
    for (int i = 0; i < quantidade; i++) {
        char *senha = gerar_senha(maiusculas, minusculas, numeros, simbolos, tamanho);
        printf("%s\n", senha);
    }

    return 0;
}