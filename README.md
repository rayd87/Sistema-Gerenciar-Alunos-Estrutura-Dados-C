# Sistema de Gerenciamento de Alunos em C (com Lista Ligada)

Projeto acadêmico desenvolvido para a disciplina de **Estrutura de Dados**  do curso de Bacharelado em Sistemas de Informação (BSI - UFRPE).

Este projeto é um sistema de console completo que implementa um **CRUD (Create, Read, Update, Delete)** para gerenciar alunos, aplicando conceitos fundamentais de alocação dinâmica e listas ligadas em Linguagem C.

---

## 🚀 Funcionalidades Principais

O sistema permite ao usuário realizar as seguintes operações:

* **Inserir Aluno:** Adicionar um novo aluno no **início** da lista.
* **Inserir Aluno:** Adicionar um novo aluno no **final** da lista.
* **Remover Aluno:** Buscar e remover um aluno específico por **matrícula**.
* **Buscar Aluno:** Localizar um aluno na lista por **matrícula** e exibir seus dados.
* **Exibir Lista Completa:** Percorrer e imprimir todos os alunos cadastrados.
* **Calcular Média da Turma:** Calcular a média aritmética de todos os alunos na lista.
* **Ordenar Lista (Bubble Sort):** Apresentar a lista ordenada por **Nome** (alfabético) ou por **Nota** (da maior para a menor).

## 🛠️ Conceitos e Tecnologias Aplicadas

Este projeto foi construído 100% em C e foca nos seguintes conceitos-chave de ciência da computação:

* **Linguagem C**
* **Listas Ligadas (Linked Lists):** Estrutura de dados principal para o armazenamento.
* **Alocação Dinâmica de Memória:** Uso de `malloc()` e `free()` para gerenciamento de memória dos nós.
* **Ponteiros e `Structs`:** Base para a criação da lista e manipulação dos dados.
* **Algoritmos de Ordenação:** Implementação de um **Bubble Sort** otimizado para ordenação em-memória.
* **Manipulação de Input/Output:** Funções de `printf`/`scanf` com tratamento de buffer (`limparBuffer()`).

## 🔧 Como Executar

1.  Clone este repositório:
    `git clone [https://github.com/rayd87/Sistema-Gerenciar-Alunos-Estrutura-Dados-C]`

2.  Navegue até a pasta do projeto e compile o arquivo:
    `gcc "VA estrutura de dados.c" -o sistema_alunos`

3.  Execute o programa:
    `./sistema_alunos`

---
