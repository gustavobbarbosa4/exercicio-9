#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "paciente.h"

void alocacao_paciente(paciente_t *paciente, char *nome, short idade) {
   
    strncpy(paciente->nome, nome, sizeof(paciente->nome) - 1);
    paciente->nome[sizeof(paciente->nome) - 1] = '\0'; 
    paciente->idade = idade;

    srand(time(NULL));

    int andar = (rand() % 5) + 1; 
    int leito = rand() % 10;      
    paciente->leito = andar * 100 + leito;
}


int main() {
    paciente_t paciente;
    char nome[100];
    short idade;

    printf("Digite o nome do paciente: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';  

    printf("Digite a idade do paciente: ");
    scanf("%hd", &idade);

    alocacao_paciente(&paciente, nome, idade);

    printf("\n--- Dados do Paciente ---\n");
    printf("Nome: %s\n", paciente.nome);
    printf("Idade: %d\n", paciente.idade);
    printf("Leito: %d\n", paciente.leito);

    return 0;
}
