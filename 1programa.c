//Curso Alura: C: conhecendo a Linguagem das Linguagens
//Janeiro de 2023

// incluindo as bibliotecas
#include <stdio.h> //biblioteca de entrada e saida
#include <stdlib.h> //fun‡äes matematicas
#include <time.h>
//#define NUMERO_TENTATIVAS 5

  int main(){
    //cabecalho do jogo
  printf("                      (( _______                                        \n");
  printf("      _______           /\\O    O\\                                     \n");
  printf("     /O     /\\         /  \\      \\                                   \n");
  printf("    /   O  /O \\       / O  \\O____O\\ ))         Bem vindo(a)          \n");
  printf(" ((/_____O/    \\      \\    /O     /                 ao                \n");
  printf("   \\O    O\\    /       \\  /   O  /            Jogo de adivinha‡Æo!   \n");
  printf("    \\O    O\\ O/         \\/_____O/                                    \n");
  printf("     \\O____O\\/ ))            ))                                       \n");
  printf("    ((                                                                  \n");
  printf("\n\n");

  // declarando variaveis que serao usadas mais a frente
  int chute;
  int acertou;
  int nivel;
  int numeroDeTentativas;

  // definindo a quantidade de pontos inicial
  double pontos = 1000;

  // gerando um numero secreto aleatorio
  srand(time(0));
  int numeroSecreto = rand() % 100;

  // escolhendo o nivel de dificuldade
  printf("\n");
  printf("Qual o n¡vel de dificuldade?\n");
  printf("(1)F cil\n(2)M‚dio\n(3)Dif¡cil\n");
  printf("Escolha: ");
  scanf("%d", &nivel);
  printf("\n\n");

  switch (nivel) {
    case 1:
      numeroDeTentativas = 20;
      break;
    case 2:
      numeroDeTentativas = 15;
      break;
    default:
      numeroDeTentativas = 8;
      break;
  }

  // loop principal do jogo
  for (int i = 1; i <= numeroDeTentativas; i++) {
    printf("-> Tentativa %d de %d \n", i, numeroDeTentativas);

    printf("Chute um numero inteiro: " );
    scanf("%d", &chute);

    // tratando chute de numero negativo
    if (chute < 0) {
      printf("Vocˆ nÆo pode chutar n£meros negativos\n");
      i--;
      continue; //break quebra o look e o coninue vai para a proxima itera‡Æo. para o bloco de codigo e continua, nao mata o loop.
    }

    // verifica se acertou, foi maior ou menor
    acertou = chute == numeroSecreto;


    if (acertou) {
      break;
    } else if (chute > numeroSecreto) {
      printf("Seu chute foi maior que o numero secreto!!\n\n");
    } else{
      printf("Seu chute foi menor que o numero secreto!!\n\n");
    }

    // calcula a quantidade de pontos
    double pontosperdidos = abs(chute - numeroSecreto) / 2.0;
    pontos = pontos - pontosperdidos;

  }

  // imprimindo mensagem de vitoria ou derrota
  printf("\n");
  if (acertou) {
      printf("             OOOOOOOOOOO               \n");
      printf("         OOOOOOOOOOOOOOOOOOO           \n");
      printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
      printf("    OOOOOO      OOOOO      OOOOOO      \n");
      printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
      printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
      printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
      printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
      printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
      printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
      printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
      printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
      printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
      printf("         OOOOOO         OOOOOO         \n");
      printf("             OOOOOOOOOOOO              \n");
      printf("Parab‚ns!! Vocˆ acertou\n");
      printf("Total de pontos: %.2f!\n", pontos);
  } else {

      printf("       \\|/ ____ \\|/    \n");
      printf("        @~/ ,. \\~@      \n");
      printf("       /_( \\__/ )_\\    \n");
      printf("          \\__U_/        \n");

    printf("Vocˆ perdeu! Tente novamente\n");
  }

}//main
