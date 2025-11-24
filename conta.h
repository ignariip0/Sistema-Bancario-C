#ifndef CONTA_H
#define CONTA_H

#define MAX_CONTAS 100
#define TAM_NOME 100
#define TAM_CPF 15
#define TAM_AGENCIA 10
#define TAM_TELEFONE 20
#define ATIVA 1
#define ENCERRADA 0

typedef struct {
    int numero;
    char nome[TAM_NOME];
    char cpf[TAM_CPF];
    char agencia[TAM_AGENCIA];
    char telefone[TAM_TELEFONE];
    double saldo;
    int status;
} Conta;

int encontrar_conta_por_numero(const Conta contas[], int qtd, int numero);
int encontrar_conta_por_cpf(const Conta contas[], int qtd, const char* cpf);

void mostrar_dados(const Conta* c);

int abrir_conta(Conta contas[], int* qtd, int proximo_numero,
                const char* nome, const char* cpf,
                const char* agencia, const char* telefone);

int depositar(Conta contas[], int qtd, int numero, double valor);
int sacar(Conta contas[], int qtd, int numero, double valor);
int transferir(Conta contas[], int qtd, int origem, int destino, double valor);

int atualizar_contato(Conta contas[], int qtd, int numero,
                      const char* telefone, const char* agencia);

int encerrar_conta(Conta contas[], int qtd, int numero);

void listar_contas(const Conta contas[], int qtd, int filtro);

#endif
