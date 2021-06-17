/*
	Author: Diego Socrates Dias Mousine;
	Date: 2014-02-09;

	DMPrimos é Gerador de números
	primos que permite gerar até o
	10.000.000º número primo em menos
	de um minuto.
*/
import java.util.Scanner;
import java.lang.Math;

class DMPrimos {
	public static void main(String[] args) {
		// Instancia do objeto Scanner = leia
		Scanner leia = new Scanner(System.in);
		
		// Declaração do vetor que guardará todos os primos encontrados
		long[] primos = new long[10000000];
		
		// Declaração de variáveis que auxiliarão na rotina
		int primoRequerido, pos_Prox_Entrada;
		long contador;
		
		// Atribuição dos primeiros primos !Muito importante!
		primos[0] = 1;
		primos[1] = 2;
		primos[2] = 3;
		primos[3] = 5;
		pos_Prox_Entrada = 4;
		contador = 6;
		
		// Requer a posição do número primo
		System.out.print("Digite a posicao do numero primo requerido\nentre 1 - 10.000.000 (ou 0 para fechar): ");
		primoRequerido = leia.nextInt();
		// ! Tratar entradas inválidas futuramente !
		
		// Condição: Se a posição do número requerido ainda não existir no vetor...
		if(primoRequerido > pos_Prox_Entrada) {
			
			// Loop: Enquanto não encontrar a posição do número requerido
			while(pos_Prox_Entrada < primoRequerido) {
				int i = 1;
				
				// Loop: Tenta dividir o número atual no CONTADOR por algum primo já existente
				//while(i < pos_Prox_Entrada) {
				
				// Enquanto ele for maior ou igual ao quadrado do primo atual.
				while(contador >= Math.pow(primos[i],2)) {
					
					// Condição: Se a divisão gerar resto igual a 0
					if(contador%primos[i] == 0) {
						contador++; // Incrementa o CONTADOR
						i = 1; // Retorna o ÍNDICE para a posição inicial
					} else { i++; } // Se a divisão não gerar resto incrementa o ÍNDICE
				}
				
				// Caso o número atual no CONTADOR não seja divisível por nenhum primo já encontrado
				primos[pos_Prox_Entrada] = contador; // Guarda o número no vetor PRIMOS
				pos_Prox_Entrada++; // Incrementa o índice da próxima entrada;
				contador++; // Incrementa o CONTADOR;
			}
			
			// Caso encontre chegue à posição do número requerido
			System.out.println(primos[primoRequerido-1]); // Exibir na tela o número
		} else {
			System.out.println(primos[primoRequerido-1]); // Se o número já existir no vetor ele imprime na tela.
		}
	}
}