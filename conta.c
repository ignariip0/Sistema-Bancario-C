#include <stdio.h>
#include <string.h>
#include "conta.h"

int encontrar_conta_por_numero(const Conta contas[], int qtd, int numero) {
    for (int i = 0; i < qtd; i++) {
        if (contas[i].numero == numero) return i;
    }
    return -1;
}

int encontrar_conta_por_cpf(const Conta contas[], int qtd, const char* cpf) {
    for (int i = 0; i < qtd; i++) {
        if (strcmp(contas[i].cpf, cpf) == 0 && contas[i].status == ATIVA)
            return i;
    }
    return -1;
}

void mostrar_dados(const Conta* c) {
    printf("\n--- Dados da Conta ---\n");
    printf("Número: %d\n", c->numero);
    printf("Nome: %s\n", c->nome);
    printf("CPF: %s\n", c->cpf);
    printf("Agência: %s\n", c->agencia);
    printf("Telefone: %s\n", c->telefone);
    printf("Status: %s\n", c->status == ATIVA ? "Ativa" : "Encerrada");
    printf("Saldo: R$ %.2lf\n", c->saldo);
}

int abrir_conta(Conta contas[], int* qtd, int proximo_numero,
                const char* nome, const char* cpf,
                const char* agencia, const char* telefone) {

    if (*qtd >= MAX_CONTAS)
        return 0;

    if (encontrar_conta_por_cpf(contas, *qtd, cpf) != -1)
        return -1;

    Conta nova;
    nova.numero = proximo_numero;
    strcpy(nova.nome, nome);
    strcpy(nova.cpf, cpf);
    strcpy(nova.agencia, agencia);
    strcpy(nova.telefone, telefone);
    nova.saldo = 0;
    nova.status = ATIVA;

    contas[*qtd] = nova;
    (*qtd)++;

    return 1;
}

int depositar(Conta contas[], int qtd, int numero, double valor) {
    if (valor <= 0) return 0;

    int idx = encontrar_conta_por_numero(contas, qtd, numero);
    if (idx == -1 || contas[idx].status == ENCERRADA) return -1;

    contas[idx].saldo += valor;
    return 1;
}

int sacar(Conta contas[], int qtd, int numero, double valor) {
    if (valor <= 0) return 0;

    int idx = encontrar_conta_por_numero(contas, qtd, numero);
    if (idx == -1 || contas[idx].status == ENCERRADA) return -1;

    if (contas[idx].saldo < valor) return -2;

    contas[idx].saldo -= valor;
    return 1;
}

int transferir(Conta contas[], int qtd, int origem, int destino, double valor) {
    if (valor <= 0) return 0;

    int idxOrigem = encontrar_conta_por_numero(contas, qtd, origem);
    int idxDestino = encontrar_conta_por_numero(contas, qtd, destino);

    if (idxOrigem == -1 || idxDestino == -1) return -1;
    if (contas[idxOrigem].status == ENCERRADA || contas[idxDestino].status == ENCERRADA)
        return -2;
    if (contas[idxOrigem].saldo < valor) return -3;

    contas[idxOrigem].saldo -= valor;
    contas[idxDestino].saldo += valor;

    return 1;
}

int atualizar_contato(Conta contas[], int qtd, int numero,
                      const char* telefone, const char* agencia) {

    int idx = encontrar_conta_por_numero(contas, qtd, numero);
    if (idx == -1) return 0;

    strcpy(contas[idx].telefone, telefone);
    strcpy(contas[idx].agencia, agencia);

    return 1;
}

int encerrar_conta(Conta contas[], int qtd, int numero) {
    int idx = encontrar_conta_por_numero(contas, qtd, numero);

    if (idx == -1) return 0;
    if (contas[idx].saldo != 0) return -1;

    contas[idx].status = ENCERRADA;
    return 1;
}

void listar_contas(const Conta contas[], int qtd, int filtro) {
    printf("\n--- Lista de Contas ---\n");

    for (int i = 0; i < qtd; i++) {
        if (filtro == ATIVA && contas[i].status != ATIVA) continue;
        if (filtro == ENCERRADA && contas[i].status != ENCERRADA) continue;

        mostrar_dados(&contas[i]);
    }
}
