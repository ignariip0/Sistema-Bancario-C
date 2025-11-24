# Sistema Bancário em C
Sistema bancário desenvolvido como atividade da disciplina de Algoritmos e Programação no curso de Engenharia de Software da Universidade Católica de Brasília (UCB). O projeto foi implementado em linguagem C utilizando structs, vetores, funções e modularização. Todas as operações funcionam em memória durante a execução do programa.

## Funcionalidades
O sistema implementa as seguintes operações: abrir conta, depositar valores, sacar valores, transferir entre contas, consultar dados de uma conta, atualizar telefone e agência, listar contas (ativas, encerradas ou todas) e encerrar conta (somente com saldo igual a zero).

## Estrutura do Projeto
O código foi organizado em três arquivos principais:
main.c – interface com o usuário (menu e entradas)
conta.c – implementação de todas as operações bancárias e funções auxiliares
conta.h – constantes, struct Conta e protótipos das funções

O arquivo conta.h contém as definições de constantes, a estrutura Conta e a declaração de todas as funções. O arquivo conta.c contém as implementações completas das operações bancárias e das validações necessárias (como CPF duplicado, saldo insuficiente e conta encerrada). O arquivo main.c exibe o menu, recebe as informações do usuário e chama as funções implementadas em conta.c.

## Como Compilar
Utilizando GCC:
gcc main.c conta.c -o sistema
Para executar:
./sistema

## Menu do Sistema
1. Abrir conta
2. Depositar
3. Sacar
4. Transferir
5. Consultar dados
6. Atualizar telefone e agência
7. Listar contas
8. Encerrar conta
9. Sair

## Validações Implementadas
O sistema impede abertura de contas com CPF duplicado, bloqueia operações em contas encerradas, não permite valores inválidos em saques e depósitos, impede saques e transferências sem saldo suficiente e só permite encerrar contas cujo saldo seja exatamente zero.

## Autor
Cauê – Estudante de Engenharia de Software, Universidade Católica de Brasília (UCB)
