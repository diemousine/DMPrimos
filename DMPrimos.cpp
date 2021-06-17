/*
	Author: Diego Socrates Dias Mousine;
	Date: 2014-02-09;

	DMPrimos � Gerador de n�meros
	primos que permite gerar at� o
	10.000.000� n�mero primo em menos
	de um minuto.
*/

#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

// Declara��o do vetor que guardar� todos os primos encontrados
long int primos[100000000];

// Declara��o de vari�veis que auxiliar�o na rotina
int primoRequerido, pos_Prox_Entrada, imprimir, soma;
long int contador;

int main() {

    do {
        // Atribui��o dos primeiros primos !Muito importante!
        primos[0] = 2;
        pos_Prox_Entrada = 1;
        contador = 3;
        soma = 2;
    	
        // Requer a posi��o do n�mero primo
        printf("Digite a posicao do numero primo requerido\nentre 1 - 100.000.000 (ou 0 para fechar): ");
       	scanf("%d",&primoRequerido);
       	
        if(primoRequerido == 0) { break; }       	
        
        printf("\nImprimir cada primo encontrado? (1 - sim | 0 - nao): ");
       	scanf("%d",&imprimir);
        // ! Tratar entradas inv�lidas futuramente !

		FILE * dataFile; // Cria uma vari�vel do tipo Arquivo
		dataFile = fopen("grafico.dat", "w"); // Declara o arquivo magData.dat como arquivo edit�vel
		fprintf(dataFile, "%d, %d\n", 1, soma);
        
		// Condi��o: Se a posi��o do n�mero requerido ainda n�o existir no vetor...
        if(primoRequerido > pos_Prox_Entrada) {

        	// Loop: Enquanto n�o encontrar a posi��o do n�mero requerido
         	while(pos_Prox_Entrada < primoRequerido) {
          		int i = 0;

                // Enquanto ele for maior ou igual ao quadrado do primo atual.
                while(contador >= (primos[i]*primos[i])) {

                   	// Condi��o: Se a divis�o gerar resto igual a 0
                    if(contador%primos[i] == 0) {
	                      contador+=2; // Incrementa o CONTADOR
               		      i = 1; // Retorna o �NDICE para a posi��o inicial
                    } else { 
                           i++; 
                    } // Se a divis�o n�o gerar resto incrementa o �NDICE
                }

                // Se o usu�rio quiser imprimir cada primo encontrado na tela
                if(imprimir == 1) { 
                            printf("\nO %do numero primo e: %d", pos_Prox_Entrada+1, contador); // Exibir na tela o n�mero
                }
                // Caso o n�mero atual no CONTADOR n�o seja divis�vel por nenhum primo j� encontrado
                soma += contador;
                primos[pos_Prox_Entrada] = contador; // Guarda o n�mero no vetor PRIMOS
                fprintf(dataFile, "%d, %d\n", pos_Prox_Entrada+1, soma);
                pos_Prox_Entrada++; // Incrementa o �ndice da pr�xima entrada;
                contador+=2; // Incrementa o CONTADOR;
                
            }

            // Caso encontre chegue � posi��o do n�mero requerido
            if(imprimir == 0) { 
                printf("\nO %do numero primo e: %d", primoRequerido, primos[primoRequerido-1]); // Exibir na tela o n�mero
            }
       } else { printf("\nO %do numero primo e: %d", primoRequerido, primos[primoRequerido-1]); // Se o n�mero j� existir no vetor ele imprime na tela.
       }
	   fclose(dataFile); // Fecha o arquivo magData.dat
       printf("\nSoma: %d", soma);
       printf("\n\n");
       system("pause");
       system("cls");
    } while (primoRequerido > 0);
}
