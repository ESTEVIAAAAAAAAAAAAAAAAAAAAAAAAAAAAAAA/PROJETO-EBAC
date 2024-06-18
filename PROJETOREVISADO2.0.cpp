#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

void registro() { // Fun��o para registrar informa��es do usu�rio
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    strcpy(arquivo, cpf);

    FILE *file = fopen(arquivo, "w");
    fprintf(file, "%s", cpf);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    system("pause");
}

void consulta() { // Fun��o para consultar informa��es do usu�rio
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");

    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo. Nao localizado!\n");
    } else {
        while (fgets(conteudo, 200, file) != NULL) {
            printf("\nEssas s�o as informa��es do usu�rio:\n%s\n\n", conteudo);
        }
        fclose(file);
    }
    system("pause");
}

void deletar() { // Fun��o para deletar informa��es do usu�rio
    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Usu�rio deletado com sucesso.\n");
    } else {
        printf("Nao foi possivel deletar o usu�rio. N�o localizado!\n");
    }
    system("pause");
}

int main() {
    int opcao;
    int laco = 1;

    while (laco) {
        system("cls");
        printf("Escolha uma opcao:\n");
        printf("1 - Registro\n");
        printf("2 - Consulta\n");
        printf("3 - Deletar\n");
        printf("4 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            case 4:
            	printf("saindo do sistema....\n");
                laco = 0; // Sai do loop
                break;
            default:
                printf("Op��o inv�lida.\n");
                system("pause");
                break;
        }
    }
    return 0;
}
