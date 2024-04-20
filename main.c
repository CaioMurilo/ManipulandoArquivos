#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAXIMO_ALUNOS 100

struct Aluno {
    char nome[50];
    char curso[50];
    char telefone[15];
    char situacao[15];
    float media;
    float nota1;
    float nota2;
};

void lerOsDados(const char *nomeDoArquivo, struct Aluno turma[], int *nuAlunos) {

    FILE *arquivo = fopen(nomeDoArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao Abrir o Arquivo Selecionado.\n");
        exit(1);
    }

    char linha[200];
    *nuAlunos = 0;

    while (*nuAlunos < TAMANHO_MAXIMO_ALUNOS && fgets(linha, sizeof(linha), arquivo)) {

        char *parte = strtok(linha, ",");

        if (parte == NULL) continue;

        strcpy(turma[*nuAlunos].nome, parte);
        
        parte = strtok(NULL, ",");
        if (parte == NULL) continue;
        strcpy(turma[*nuAlunos].telefone, parte);

        parte = strtok(NULL, ",");
        if (parte == NULL) continue;
        strcpy(turma[*nuAlunos].curso, parte);

        parte = strtok(NULL, ",");
        if (parte == NULL) continue;
        turma[*nuAlunos].nota1 = strtod(parte, NULL);

        parte = strtok(NULL, ",");
        if (parte == NULL) continue;
        turma[*nuAlunos].nota2 = strtod(parte, NULL);

        turma[*nuAlunos].media = (turma[*nuAlunos].nota1 + turma[*nuAlunos].nota2) / 2.0;

        if (turma[*nuAlunos].media >= 7.0) {
            strcpy(turma[*nuAlunos].situacao, "APROVADO");
        } else {
            strcpy(turma[*nuAlunos].situacao, "REPROVADO");
        }

        (*nuAlunos)++;
    }

    fclose(arquivo);
}

void escreverSituacao(const char *nomeDoArquivo, const struct Aluno turma[], int nuAlunos) {

    FILE *arquivo = fopen(nomeDoArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        exit(1);
    }

    for (int i = 0; i < nuAlunos; i++) {
        fprintf(arquivo, "%s, %.2f, %s\n", turma[i].nome, turma[i].media, turma[i].situacao);
    }
    fclose(arquivo);
}

int main() {
    
    struct Aluno turma[TAMANHO_MAXIMO_ALUNOS];
    int nuAlunos;

    lerOsDados("DadosEntrada.csv", turma, &nuAlunos);
    escreverSituacao("SituacaoFinal.csv", turma, nuAlunos);

    return 0;
}
