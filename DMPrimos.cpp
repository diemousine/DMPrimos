/*
	Author: Diego Socrates Dias Mousine;
	Date: 2014-02-09;

	DMPrimos é Gerador de números
	primos que permite gerar até o
	10.000.000º número primo em menos
	de um minuto.
*/

#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

// Declaração do vetor que guardará todos os primos encontrados
long int primos[100000000];

// Declaração de variáveis que auxiliarão na rotina
int primoRequerido, pos_Prox_Entrada, imprimir, soma;
long int contador;

int main() {

    do {
        // Atribuição dos primeiros primos !Muito importante!
        primos[0] = 2;
        pos_Prox_Entrada = 1;
        contador = 3;
        soma = 2;
    	
        // Requer a posição do número primo
        printf("Digite a posicao do numero primo requerido\nentre 1 - 100.000.000 (ou 0 para fechar): ");
       	scanf("%d",&primoRequerido);
       	
        if(primoRequerido == 0) { break; }       	
        
        printf("\nImprimir cada primo encontrado? (1 - sim | 0 - nao): ");
       	scanf("%d",&imprimir);
        // ! Tratar entradas inválidas futuramente !

		FILE * dataFile; // Cria uma variável do tipo Arquivo
		dataFile = fopen("grafico.dat", "w"); // Declara o arquivo magData.dat como arquivo editável
		fprintf(dataFile, "%d, %d\n", 1, soma);
        
		// Condição: Se a posição do número requerido ainda não existir no vetor...
        if(primoRequerido > pos_Prox_Entrada) {

        	// Loop: Enquanto não encontrar a posição do número requerido
         	while(pos_Prox_Entrada < primoRequerido) {
          		int i = 0;

                // Enquanto ele for maior ou igual ao quadrado do primo atual.
                while(contador >= (primos[i]*primos[i])) {

                   	// Condição: Se a divisão gerar resto igual a 0
                    if(contador%primos[i] == 0) {
	                      contador+=2; // Incrementa o CONTADOR
               		      i = 1; // Retorna o ÍNDICE para a posição inicial
                    } else { 
                           i++; 
                    } // Se a divisão não gerar resto incrementa o ÍNDICE
                }

                // Se o usuário quiser imprimir cada primo encontrado na tela
                if(imprimir == 1) { 
                            printf("\nO %do numero primo e: %d", pos_Prox_Entrada+1, contador); // Exibir na tela o número
                }
                // Caso o número atual no CONTADOR não seja divisível por nenhum primo já encontrado
                soma += contador;
                primos[pos_Prox_Entrada] = contador; // Guarda o número no vetor PRIMOS
                fprintf(dataFile, "%d, %d\n", pos_Prox_Entrada+1, soma);
                pos_Prox_Entrada++; // Incrementa o índice da próxima entrada;
                contador+=2; // Incrementa o CONTADOR;
                
            }

            // Caso encontre chegue à posição do número requerido
            if(imprimir == 0) { 
                printf("\nO %do numero primo e: %d", primoRequerido, primos[primoRequerido-1]); // Exibir na tela o número
            }
       } else { printf("\nO %do numero primo e: %d", primoRequerido, primos[primoRequerido-1]); // Se o número já existir no vetor ele imprime na tela.
       }
	   fclose(dataFile); // Fecha o arquivo magData.dat
       printf("\nSoma: %d", soma);
       printf("\n\n");
       system("pause");
       system("cls");
    } while (primoRequerido > 0);
}
