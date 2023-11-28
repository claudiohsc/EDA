#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINHAS 1000000 // Defina o número máximo de linhas no arquivo

typedef struct {
    int ibge;
    int linha;
} DadosMunicipio;

typedef struct {
    int ibge;
    char municipio[100];
    char uf[3];
    char regiao[20];
    int populacao2010;
    char porte[20];
} InformacoesMunicipio;

// Função para carregar os dados do arquivo para o vetor
void carregarDados(FILE *arquivo, DadosMunicipio vetor[], int *numLinhas) {
    *numLinhas = 0;

    while ((*numLinhas < MAX_LINHAS) && (fscanf(arquivo, "%d,%*[^,],%[^,],%[^,],%*d,%d,%[^\n]", &vetor[*numLinhas].ibge, vetor[*numLinhas].uf, vetor[*numLinhas].regiao, &vetor[*numLinhas].populacao2010, vetor[*numLinhas].porte) == 5)) {
        vetor[*numLinhas].linha = *numLinhas;
        (*numLinhas)++;
    }
}

// Função para buscar as informações de um município por busca sequencial
void buscaSequencial(DadosMunicipio vetor[], int numLinhas, int codigoMunicipio, InformacoesMunicipio *infoMunicipio, clock_t *tempo) {
    *tempo = clock();

    for (int i = 0; i < numLinhas; i++) {
        if (vetor[i].ibge == codigoMunicipio) {
            *tempo = clock() - *tempo;
            fseek(stdin, 0, SEEK_END); // Limpa o buffer de entrada
            infoMunicipio->ibge = vetor[i].ibge;
            FILE *arquivo = fopen("municipios.csv", "r");
            for (int j = 0; j < vetor[i].linha; j++)
                fscanf(arquivo, "%*[^\n]\n");
            fscanf(arquivo, "%*d,%[^,],%[^,],%*d,%d,%[^\n]", infoMunicipio->municipio, infoMunicipio->uf, &infoMunicipio->populacao2010, infoMunicipio->porte);
            fclose(arquivo);
            return;
        }
    }

    *tempo = clock() - *tempo;
    infoMunicipio->ibge = -1; // Código de município não encontrado
}

// Função para buscar as informações de um município por busca binária
void buscaBinaria(DadosMunicipio vetor[], int numLinhas, int codigoMunicipio, InformacoesMunicipio *infoMunicipio, clock_t *tempo) {
    *tempo = clock();

    int inicio = 0;
    int fim = numLinhas - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio].ibge == codigoMunicipio) {
            *tempo = clock() - *tempo;
            fseek(stdin, 0, SEEK_END); // Limpa o buffer de entrada
            infoMunicipio->ibge = vetor[meio].ibge;
            FILE *arquivo = fopen("municipios.csv", "r");
            for (int j = 0; j < vetor[meio].linha; j++)
                fscanf(arquivo, "%*[^\n]\n");
            fscanf(arquivo, "%*d,%[^,],%[^,],%*d,%d,%[^\n]", infoMunicipio->municipio, infoMunicipio->uf, &infoMunicipio->populacao2010, infoMunicipio->porte);
            fclose(arquivo);
            return;
        }

        if (vetor[meio].ibge < codigoMunicipio)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    *tempo = clock() - *tempo;
    infoMunicipio->ibge = -1; // Código de município não encontrado
}

int main() {
    FILE *arquivo = fopen("6-lab/Lista_Municípios_com_IBGE_Brasil_Versao_CSV.csv", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    DadosMunicipio vetor[MAX_LINHAS];
    int numLinhas;

    carregarDados(arquivo, vetor, &numLinhas);
    fclose(arquivo);

    int opcao;
    int codigoMunicipio;
    InformacoesMunicipio infoMunicipio;
    clock_t tempo;

    do {
        printf("\nMenu:\n");
        printf("1. Carregar vetor\n");
        printf("2. Buscar informacoes de um municipio\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                arquivo = fopen("municipios.csv", "r");

                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo.\n");
                    return 1;
                }

                carregarDados(arquivo, vetor, &numLinhas);
                fclose(arquivo);
                printf("Vetor carregado com sucesso!\n");
                break;

            case 2:
                printf("Digite o codigo do municipio: ");
                scanf("%d", &codigoMunicipio);

                // Busca Sequencial
                buscaSequencial(vetor, numLinhas, codigoMunicipio, &infoMunicipio, &tempo);
                if (infoMunicipio.ibge != -1) {
                    printf("\nInformacoes do municipio:\n");
                    printf("Municipio: %s\n", infoMunicipio.municipio);
                    printf("UF: %s\n", infoMunicipio.uf);
                    printf("Regiao: %s\n", infoMunicipio.regiao);
                    printf("Populacao em 2010: %d\n", infoMunicipio.populacao2010);
                    printf("Porte: %s\n", infoMunicipio.porte);
                    printf("Tempo de busca sequencial: %f segundos\n", ((float)tempo) / CLOCKS_PER_SEC);
                } else {
                    printf("Codigo de municipio nao encontrado.\n");
                }

                // Busca Binaria
                buscaBinaria(vetor, numLinhas, codigoMunicipio, &infoMunicipio, &tempo);
                if (infoMunicipio.ibge != -1) {
                    printf("\nInformacoes do municipio:\n");
                    printf("Municipio: %s\n", infoMunicipio.municipio);
                    printf("UF: %s\n", infoMunicipio.uf);
                    printf("Regiao: %s\n", infoMunicipio.regiao);
                    printf("Populacao em 2010: %d\n", infoMunicipio.populacao201
