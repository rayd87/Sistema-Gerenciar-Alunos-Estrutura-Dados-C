/*  PROJETO AVALIATIVO PARA DISCIPLINA DE ESTRUTURAS DE DADOS.
OBJETIVO: Desenvolver um sistema de cadastro de aluno(a)s utilizando lista ligada, capaz de
armazenar, manipular e organizar informações de forma dinâmica.

O sistema deve permitir as operações abaixo, implementadas por meio de funções específicas:
1. Inserir um(a) novo(a) aluno(a) no início da lista.
2. Inserir um(a) novo(a) aluno(a) no final da lista.
3. Remover um(a) aluno(a) a partir da matrícula informada.
4. Buscar um(a) aluno(a) pelo número de matrícula e exibir seus dados.
5. Exibir a lista completa de aluno(a)s.
6. Calcular e exibir a média das notas de todos o(a)s aluno(a)s cadastrado(a)s.
7. Ordenar a lista de aluno(a)s por nome ou por nota, conforme escolha do usuário


ALUNO: RAY DANTAS DE BARROS
CURSO: BSI (3º PERÍODO 2025.2)

*/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

//Nó aluno

typedef struct Aluno {
  1  int matricula;
    char nome[50]; 
    float nota;
    struct Aluno* proximo; 
} Aluno;


// menu
void exibirMenu();
void limparBuffer();

//  auxiliares
Aluno* criarAluno();
void trocarDados(Aluno* a, Aluno* b);
void liberarLista(Aluno** lista);

//  lista
void inserirInicio(Aluno** lista);
void inserirFinal(Aluno** lista);
void removerAluno(Aluno** lista);
void buscarAluno(Aluno* lista);
void exibirLista(Aluno* lista);
void calcularMedia(Aluno* lista);
void ordenarLista(Aluno* lista);

// menu principal 

int main() {
    
    Aluno* lista = NULL;
    int opcao;
    
    

    do {
        exibirMenu();
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Por favor, digite um numero.\n");
            limparBuffer(); // Limpa a entrada inválida
            opcao = -1; // Força a repetição do loop
            continue;
        }
        limparBuffer(); // Limpa o '\n' deixado pelo scanf

        switch (opcao) {
            case 1:
                inserirInicio(&lista);
                break;
            case 2:
                inserirFinal(&lista);
                break;
            case 3:
                removerAluno(&lista);
                break;
            case 4:
                buscarAluno(lista);
                break;
            case 5:
                exibirLista(lista);
                break;
            case 6:
                calcularMedia(lista);
                break;
            case 7:
                ordenarLista(lista);
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar(); 
        }

    } while (opcao != 0);

    // libera memória 
    liberarLista(&lista);

    return 0;
}

// implementação das funções 


void exibirMenu() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf("--- SISTEMA DE CADASTRO DE ALUNOS ---\n");
    printf("1. Inserir aluno no inicio\n");
    printf("2. Inserir aluno no final\n");
    printf("3. Remover aluno (por matricula)\n");
    printf("4. Buscar aluno (por matricula)\n");
    printf("5. Exibir lista de alunos\n");
    printf("6. Calcular media das notas\n");
    printf("7. Ordenar lista\n");
    printf("0. Sair\n");
    printf("---------------------------------------\n");
    printf("Escolha uma opcao: ");
}


void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


Aluno* criarAluno() {
    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return NULL;
    }

    printf("Digite a matricula: ");
    while (scanf("%d", &novo->matricula) != 1) {
        printf("Entrada invalida. Digite um numero: ");
        limparBuffer();
    }
    limparBuffer(); 

    printf("Digite o nome: ");
    
    if (fgets(novo->nome, 50, stdin) != NULL) {
        novo->nome[strcspn(novo->nome, "\n")] = 0;
    }

    printf("Digite a nota final: ");
    while (scanf("%f", &novo->nota) != 1) {
        printf("Entrada invalida. Digite um numero (ex: 8.5): ");
        limparBuffer();
    }
    limparBuffer(); 

    novo->proximo = NULL; 
    return novo;
}


void inserirInicio(Aluno** lista) {
    printf("\n--- Inserir Aluno no Inicio ---\n");
    Aluno* novo = criarAluno();
    if (novo == NULL) {
        return; 
    }

    novo->proximo = *lista;
    *lista = novo;

    printf("\nAluno inserido com sucesso no inicio!\n");
}


void inserirFinal(Aluno** lista) {
    printf("\n--- Inserir Aluno no Final ---\n");
    Aluno* novo = criarAluno();
    if (novo == NULL) {
        return; 
    }

    // Caso 1: A lista está vazia
    if (*lista == NULL) {
        *lista = novo;
    } else {
        // Caso 2: A lista não está vazia
        // Percorre a lista até encontrar o último nó
        Aluno* atual = *lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        // O último nó agora aponta para o novo aluno
        atual->proximo = novo;
    }

    printf("\nAluno inserido com sucesso no final!\n");
}


void removerAluno(Aluno** lista) {
    printf("\n--- Remover Aluno por Matricula ---\n");
    if (*lista == NULL) {
        printf("Lista vazia! Nao ha alunos para remover.\n");
        return;
    }

    int matricula;
    printf("Digite a matricula do aluno a remover: ");
    scanf("%d", &matricula);
    limparBuffer();

    Aluno* atual = *lista;
    Aluno* anterior = NULL;

    // Procura o aluno na lista, mantendo o rastro do nó anterior
    while (atual != NULL && atual->matricula != matricula) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Caso 1: Aluno não encontrado
    if (atual == NULL) {
        printf("Aluno com matricula %d nao encontrado.\n", matricula);
        return;
    }

    // Caso 2: Aluno a ser removido é o primeiro da lista
    if (anterior == NULL) {
        *lista = atual->proximo; 
    } else {
        // Caso 3: Aluno está no meio ou fim da lista
        anterior->proximo = atual->proximo; 
    }

    // Libera a memória do nó removido
    free(atual);
    printf("Aluno com matricula %d removido com sucesso!\n", matricula);
}


void buscarAluno(Aluno* lista) {
    printf("\n--- Buscar Aluno por Matricula ---\n");
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    int matricula;
    printf("Digite a matricula do aluno a buscar: ");
    scanf("%d", &matricula);
    limparBuffer();

    Aluno* atual = lista;

    // Percorre a lista
    while (atual != NULL) {
        if (atual->matricula == matricula) {
            printf("\n--- Aluno Encontrado ---\n");
            printf("Matricula: %d\n", atual->matricula);
            printf("Nome: %s\n", atual->nome);
            printf("Nota Final: %.2f\n", atual->nota);
            return; // Encontrou, encerra a função
        }
        atual = atual->proximo;
    }

    // Se saiu do loop, não encontrou
    printf("Aluno com matricula %d nao encontrado.\n", matricula);
}


void exibirLista(Aluno* lista) {
    printf("\n--- Lista Completa de Alunos ---\n");
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Aluno* atual = lista;
    int contador = 1;

    while (atual != NULL) {
        printf("--- Aluno %d ---\n", contador++);
        printf("Matricula: %d\n", atual->matricula);
        printf("Nome: %s\n", atual->nome);
        printf("Nota Final: %.2f\n", atual->nota);
        printf("----------------\n");
        atual = atual->proximo; // Avança para o próximo nó
    }
}


void calcularMedia(Aluno* lista) {
    printf("\n--- Media das Notas da Turma ---\n");
    if (lista == NULL) {
        printf("Lista vazia! Nao e possivel calcular a media.\n");
        return;
    }

    float soma = 0;
    int contador = 0;
    Aluno* atual = lista;

    while (atual != NULL) {
        soma += atual->nota;
        contador++;
        atual = atual->proximo;
    }

    // Evita divisão por zero 
    if (contador > 0) {
        printf("Numero de alunos: %d\n", contador);
        printf("Soma total das notas: %.2f\n", soma);
        printf("Media da turma: %.2f\n", (soma / contador));
    }
}


void trocarDados(Aluno* a, Aluno* b) {
    // Troca matricula
    int tempMat = a->matricula;
    a->matricula = b->matricula;
    b->matricula = tempMat;

    // Troca nome
    char tempNome[100];
    strcpy(tempNome, a->nome);
    strcpy(a->nome, b->nome);
    strcpy(b->nome, tempNome);

    // Troca nota
    float tempNota = a->nota;
    a->nota = b->nota;
    b->nota = tempNota;
}


void ordenarLista(Aluno* lista) {
    printf("\n--- Ordenar Lista ---\n");
    // Se a lista estiver vazia ou tiver apenas 1 elemento, já está ordenada
    if (lista == NULL || lista->proximo == NULL) {
        printf("Lista vazia ou com apenas um aluno. Nao e necessario ordenar.\n");
        return;
    }

    int criterio;
    printf("Ordenar por (1-Nome, 2-Nota): ");
    while (scanf("%d", &criterio) != 1 || (criterio != 1 && criterio != 2)) {
        printf("Opcao invalida. Digite 1 (Nome) ou 2 (Nota): ");
        limparBuffer();
    }
    limparBuffer();

    int trocado;
    Aluno* p1;
    Aluno* lptr = NULL; // O último nó ordenado

    do {
        trocado = 0;
        p1 = lista;

        // Percorre a lista até o último nó não ordenado
        while (p1->proximo != lptr) {
            int comparar = 0;
            if (criterio == 1) { // Ordenar por Nome
                comparar = (strcmp(p1->nome, p1->proximo->nome) > 0);
            } else { // Ordenar por Nota (Maior para Menor)
                comparar = (p1->nota < p1->proximo->nota); 
            }

            // Se for (Nome A > Nome B) ou (Nota A < Nota B), troca
            if (comparar) {
                trocarDados(p1, p1->proximo);
                trocado = 1; // Marca que uma troca ocorreu nesta passagem
            }
            p1 = p1->proximo; // Avança para o próximo
        }
        // O nó p1 está no lugar certo
        lptr = p1;

    } while (trocado); 

    printf("Lista ordenada com sucesso!\n");
    // Exibe a lista ordenada
    exibirLista(lista);
}



void liberarLista(Aluno** lista) {
    Aluno* atual = *lista;
    Aluno* proximo;

    while (atual != NULL) {
        proximo = atual->proximo; // Guarda o endereço do próximo
        free(atual);             // Libera o nó atual
        atual = proximo;         // Avança para o próximo
    }

    *lista = NULL; // Garante que a lista está vazia após a liberação
    printf("\n\n");
}
