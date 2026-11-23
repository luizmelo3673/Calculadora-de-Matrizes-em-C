
#include <stdio.h>

#define MAX_MATRIZES 10
#define MAX_LINHAS 10
#define MAX_COLUNAS 10

double matrizes[MAX_MATRIZES][MAX_LINHAS][MAX_COLUNAS];
double resultado[MAX_LINHAS][MAX_COLUNAS];

int quantidadeMatrizes = 0;
int linhas = 0;
int colunas = 0;

int matrizesInformadas = 0;
int resultadoCalculado = 0;

// Função para escolher a quantidade de matrizes
void escolherQuantidadeMatrizes() {
    printf("\n=== QUANTIDADE DE MATRIZES ===\n");
    printf("Digite a quantidade de matrizes (2 a %d): ", MAX_MATRIZES);
    scanf("%d", &quantidadeMatrizes);

    if (quantidadeMatrizes < 2 || quantidadeMatrizes > MAX_MATRIZES) {
        printf("Quantidade invalida!\n");
        quantidadeMatrizes = 0;
        return;
    }

    printf("Quantidade de matrizes definida: %d\n", quantidadeMatrizes);
    matrizesInformadas = 0;
    resultadoCalculado = 0;
}

// Função para informar as matrizes
void informarMatrizes() {
    if (quantidadeMatrizes == 0) {
        printf("\nEscolha primeiro a quantidade de matrizes!\n");
        return;
    }

    printf("\n=== DIMENSOES DAS MATRIZES ===\n");

    printf("Digite a quantidade de linhas (1 a %d): ", MAX_LINHAS);
    scanf("%d", &linhas);

    printf("Digite a quantidade de colunas (1 a %d): ", MAX_COLUNAS);
    scanf("%d", &colunas);

    if (linhas < 1 || linhas > MAX_LINHAS ||
        colunas < 1 || colunas > MAX_COLUNAS) {
        printf("Dimensoes invalidas!\n");
        matrizesInformadas = 0;
        return;
    }

    for (int m = 0; m < quantidadeMatrizes; m++) {
        printf("\n=== MATRIZ %d ===\n", m + 1);

        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                printf("Digite o valor [%d][%d]: ", i + 1, j + 1);
                scanf("%lf", &matrizes[m][i][j]);
            }
        }
    }

    matrizesInformadas = 1;
    resultadoCalculado = 0;

    printf("\nTodas as matrizes foram cadastradas!\n");
}

// Função para exibir uma matriz
void exibirMatriz(double matriz[MAX_LINHAS][MAX_COLUNAS]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%10.2lf ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para realizar as operações
void realizarOperacao() {
    int operacao;

    if (!matrizesInformadas) {
        printf("\nInforme as matrizes primeiro!\n");
        return;
    }

    printf("\n=== OPERACOES ===\n");
    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("Escolha uma operacao: ");
    scanf("%d", &operacao);

    if (operacao < 1 || operacao > 4) {
        printf("Operacao invalida!\n");
        return;
    }

    // Inicializa o resultado com a primeira matriz
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[i][j] = matrizes[0][i][j];
        }
    }

    // Realiza a operação com as demais matrizes
    for (int m = 1; m < quantidadeMatrizes; m++) {
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {

                switch (operacao) {
                    case 1:
                        resultado[i][j] += matrizes[m][i][j];
                        break;

                    case 2:
                        resultado[i][j] -= matrizes[m][i][j];
                        break;

                    case 3:
                        resultado[i][j] *= matrizes[m][i][j];
                        break;

                    case 4:
                        if (matrizes[m][i][j] == 0) {
                            printf("\nErro: divisao por zero!\n");
                            resultadoCalculado = 0;
                            return;
                        }
                        resultado[i][j] /= matrizes[m][i][j];
                        break;
                }
            }
        }
    }

    resultadoCalculado = 1;

    printf("\nOperacao realizada com sucesso!\n");
}

// Função para apresentar a matriz solução
void apresentarResultado() {
    if (!resultadoCalculado) {
        printf("\nNenhum resultado calculado!\n");
        printf("Realize uma operacao primeiro.\n");
        return;
    }

    printf("\n=== MATRIZ SOLUCAO ===\n");
    exibirMatriz(resultado);
}

// Função para exibir o menu principal
void menuPrincipal() {
    int opcao;

    do {
        printf("\n====================================\n");
        printf("     CALCULADORA DE MATRIZES\n");
        printf("====================================\n");
        printf("1 - Escolher quantidade de matrizes\n");
        printf("2 - Informar matrizes\n");
        printf("3 - Realizar operacao\n");
        printf("4 - Apresentar matriz solucao\n");
        printf("0 - Sair\n");
        printf("------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                escolherQuantidadeMatrizes();
                break;

            case 2:
                informarMatrizes();
                break;

            case 3:
                realizarOperacao();
                break;

            case 4:
                apresentarResultado();
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);
}

// Função principal
int main() {
    menuPrincipal();

    return 0;
}
