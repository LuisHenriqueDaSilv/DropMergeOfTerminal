#include <string.h>

#include "./menu.h"
#include "../keyboard/keyboard.h"

int nOfhelpPages = 4;
int helpPage = 0;

char text[63][100] = {
"Como jogar DropMerge de Terminal\n",
"\n",
"No DropMerge de Terminal, o objetivo e combinar\n",
"blocos numericos identicos para formar numeros maiores,\n",
"como 2, 4, 8, 16 e assim por diante. O jogo desafia sua\n",
"capacidade de raciocinio logico e planejamento estrategico.\n",
"\n",
"Selecionando a Coluna\n",
"No topo do tabuleiro, ha um asterisco (*) que indica\n",
"a coluna onde o proximo bloco sera solto. Voce pode\n",
"mover esse marcador usando as teclas:\n",
"\n",
"A: Move o * para a coluna a esquerda.\n",
"D: Move o * para a coluna a direita.\n",
"Escolha cuidadosamente a coluna para combinar blocos\n",
"identicos e liberar espaco no tabuleiro.\n",
"\n",
"Fim de Jogo e Uso da Borracha\n",
"O jogo acaba quando os blocos alcancam o topo do\n",
"tabuleiro, impossibilitando novos movimentos.\n",
"Quando isso ocorre, a borracha e ativada automaticamente,\n",
"permitindo que voce apague numeros para continuar jogando.\n",
"\n",
"Assim que a borracha for ativada, voce deve escolher\n",
"a posicao a ser apagada movendo o cursor com:\n",
"\n",
"W: Move para cima.\n",
"A: Move para a esquerda.\n",
"S: Move para baixo.\n",
"D: Move para a direita.\n",
"Apos escolher a posicao, o numero sera apagado,\n",
"liberando espaco para continuar o jogo.\n",
"\n",
"Desbloqueando a Borracha\n",
"A primeira borracha e desbloqueada ao alcancar 1024.\n",
"As demais sao desbloqueadas ao atingir uma pontuacao\n",
"seguindo a formula: ultima borracha * 2^3.\n",
"\n",
"Por exemplo:\n",
"\n",
"A segunda borracha e desbloqueada em 1024 * 8 = 8192.\n",
"A terceira em 8192 * 8 = 65536, e assim por diante.\n",
"Essa progressao torna o jogo desafiador, exigindo\n",
"estrategia para alcancar pontuacoes altas.\n",
"\n",
"Modos de Borracha\n",
"Existem dois modos de borracha:\n",
"\n",
"Modo Simples: Apaga apenas o numero selecionado.\n",
"Modo Avancado: Apaga todos os numeros ao redor\n",
"da posicao selecionada, permitindo limpar areas maiores.\n",
"Voce pode escolher o modo de borracha nas configuracoes.\n",
"Planeje bem o uso, pois as borrachas sao limitadas e\n",
"essenciais para continuar jogando quando o tabuleiro encher.\n",
"\n",
"Dicas para Jogar Melhor\n",
"\n",
"Combine numeros estrategicamente para liberar espaco.\n",
"Planeje seus movimentos observando as proximas pecas.\n",
"Pense antes de usar a borracha, ja que sao desbloqueadas\n",
"com pontuacoes altas e podem ser decisivas na partida.\n",
"Agora que voce conhece as regras, desafie-se a alcancar\n",
"as maiores pontuacoes e domine o DropMerge de Terminal!\n"
};

void showHelp(){
  printf("\033[0m==================================================\033[0m\n");
  printf("              Sobre o DropMerge!\n");
  printf("\033[0m--------------------------------------------------\n");
  
  for(int i = helpPage*15; i<helpPage*15+15; i++){
    printf("%s", text[i]);
  }

  printf("\n\n");
  printf("          Use A e D para passar as paginas");
  printf("\n\033[1;0m==================================================\033[0m\n");
  printf("\033[1;0mPressione ESC para voltar                 Pag: %d\033[0m\n", helpPage+1);
  printf("\033[1;0m==================================================\033[0m");
  
  char key = readKey();
  if(key == 27){
    helpPage = 0;
    gameStatus = 2;
  } else if (key == 97  || key == 65) { // A
    if(helpPage != 0){helpPage--;};
  } else if(key == 100 || key == 68){ // D
    if(helpPage<nOfhelpPages){
      helpPage++;
    }
  }
}