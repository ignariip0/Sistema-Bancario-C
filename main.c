#include <stdio.h>
#include <string.h>
#include "conta.h"

int main() {
    Conta contas[MAX_CONTAS];
    int qtd = 0;
    int proximo_num = 1;
    int op;

    do {
        printf("\nMenu\n");
        printf("1. Abrir conta\n");
        printf("2. Depositar\n");
        printf("3. Sacar\n");
        printf("4. Transferir\n");
        printf("5. Consultar dados\n");
        printf("6. Atualizar telefone e agencia\n");
        printf("7. Listar contas\n");
        printf("8. Encerrar conta\n");
        printf("9. Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        if (op == 1) {
            char nome[TAM_NOME], cpf[TAM_CPF], agencia[TAM_AGENCIA], telefone[TAM_TELEFONE];

            printf("Nome: ");
            getchar();
            fgets(nome, TAM_NOME, stdin);
            nome[strcspn(nome, "\n")] = 0;

            printf("CPF: "); scanf("%s", cpf);
            printf("Agência: "); scanf("%s", agencia);
            printf("Telefone: "); scanf("%s", telefone);

            int r = abrir_conta(contas, &qtd, proximo_num, nome, cpf, agencia, telefone);

            if (r == 1) {
                printf("Conta criada com sucesso!\n");
                proximo_num++;
            } else if (r == -1) {
                printf("CPF já cadastrado em conta ativa!\n");
            } else {
                printf("Não foi possível criar a conta.\n");
            }
        }

        else if (op == 2) {
            int numero;
            double valor;
            printf("Número da conta: "); scanf("%d", &numero);
            printf("Valor do depósito: "); scanf("%lf", &valor);

            int r = depositar(contas, qtd, numero, valor);
            if (r == 1) printf("Depósito realizado!\n");
            else printf("Erro no depósito!\n");
        }

        else if (op == 3) {
            int numero;
            double valor;
            printf("Número da conta: "); scanf("%d", &numero);
            printf("Valor do saque: "); scanf("%lf", &valor);

            int r = sacar(contas, qtd, numero, valor);

            if (r == 1) printf("Saque realizado!\n");
            else if (r == -2) printf("Saldo insuficiente.\n");
            else printf("Erro no saque.\n");
        }

        else if (op == 4) {
            int origem, destino;
            double valor;

            printf("Conta origem: "); scanf("%d", &origem);
            printf("Conta destino: "); scanf("%d", &destino);
            printf("Valor: "); scanf("%lf", &valor);

            int r = transferir(contas, qtd, origem, destino, valor);

            if (r == 1) printf("Transferência realizada!\n");
            else printf("Erro na transferência.\n");
        }

        else if (op == 5) {
            int numero;
            printf("Número da conta: "); scanf("%d", &numero);

            int idx = encontrar_conta_por_numero(contas, qtd, numero);

            if (idx != -1) mostrar_dados(&contas[idx]);
            else printf("Conta não encontrada.\n");
        }

        else if (op == 6) {
            int numero;
            char telefone[TAM_TELEFONE], agencia[TAM_AGENCIA];

            printf("Número da conta: "); scanf("%d", &numero);
            printf("Novo telefone: "); scanf("%s", telefone);
            printf("Nova agência: "); scanf("%s", agencia);

            if (atualizar_contato(contas, qtd, numero, telefone, agencia))
                printf("Dados atualizados!\n");
            else
                printf("Conta não encontrada.\n");
        }

        else if (op == 7) {
            int filtro;
            printf("1 - Ativas | 2 - Encerradas | 3 - Todas: ");
            scanf("%d", &filtro);

            if (filtro == 1) listar_contas(contas, qtd, ATIVA);
            else if (filtro == 2) listar_contas(contas, qtd, ENCERRADA);
            else listar_contas(contas, qtd, -1);
        }

        else if (op == 8) {
            int numero;
            printf("Número da conta: "); scanf("%d", &numero);

            int r = encerrar_conta(contas, qtd, numero);

            if (r == 1) printf("Conta encerrada.\n");
            else if (r ==-1) {
                printf("Saldo diferente de zero.Não pode encerrar\n");
            }
            else if (r == 0) {
                printf("Conta não encontrar.\n");
            }
        }

    } while (op != 9);

    return 0;
}
