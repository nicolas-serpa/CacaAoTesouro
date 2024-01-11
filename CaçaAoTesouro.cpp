#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define Tamanho 5
#define Objetos_Totais 4
#define Max_Tentativas 7

void inicializarBoard(char board[Tamanho][Tamanho]) {
	    srand( (unsigned)time(NULL) );
    for (int i = 0; i < Tamanho; i++) {
        for (int j = 0; j < Tamanho; j++) {
            board[i][j] = rand() % 2 + '0'; // '0' ou '1'
        }
    }
}

void displayBoard(char board[Tamanho][Tamanho]) {
    printf("  0 1 2 3 4\n");
    for (int i = 0; i < Tamanho; i++) {
        printf("%d ", i);
        for (int j = 0; j < Tamanho; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
  
   
    char board[Tamanho][Tamanho];
    inicializarBoard(board);
	setlocale(LC_ALL, "portuguese");
    printf("Bem-vindo ao jogo!\n");
    printf("Há quatro Objetos escondidos num tabuleiro de 5x5, você tem 10 tentativas para encontra-los! Use o padrão 'x y', com números de 0 a 4 para encontra-los! \n");

    int tentativas = 0;
    int Objetos_Encontrados = 0;

    while (tentativas < Max_Tentativas && Objetos_Encontrados < Objetos_Totais) {
        int tentativaLinha, tentativaColuna;

        printf("Tentativa %d: Digite as coordenadas: ", tentativas + 1);
        scanf("%d %d", &tentativaLinha, &tentativaColuna);

       if (tentativaLinha >= 0 && tentativaLinha < Tamanho && tentativaColuna >= 0 && tentativaColuna < Tamanho) {
            if (board[tentativaLinha][tentativaColuna] == '1') {
                printf("Um Objeto foi encontrado! \n" );
                Objetos_Encontrados++;
                board[tentativaLinha][tentativaColuna] = 'X';
                 tentativas++;
                 
            } else if (board[tentativaLinha][tentativaColuna] == '0') {
                printf("Nenhum Objeto aqui. Tente novamente.\n");
                board[tentativaLinha][tentativaColuna] = 'O';
                tentativas++;
            } else {
                printf("Você já tentou essas coordenadas. Tente novamente.\n");
            }


        } else {
            printf("Coordenadas inválidas. Tente novamente.\n");
        }

       
    }
	system("cls");
	printf("=============================================================================\n");
    printf("Fim do jogo!\n");
  	printf("=============================================================================\n");
    printf("Tabuleiro final:\n");
 	printf("=============================================================================\n");
    displayBoard(board);
    

    if (Objetos_Encontrados == Objetos_Totais) {
  	printf("=============================================================================\n");
	printf("Parabéns! Você encontrou todos os Objetos!\n");
 	printf("=============================================================================\n");
        	
    } else {
 	printf("=============================================================================\n");
	printf("Você excedeu o número máximo de tentativas. Melhor sorte da próxima vez!\n");
	printf("Você encontrou apenas %d dos Objetos \n", Objetos_Encontrados );
 	printf("=============================================================================\n");
    }

    return 0;
}
                                                                                             
