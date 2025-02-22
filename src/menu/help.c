#include <string.h>

#include "./menu.h"
#include "../keyboard/keyboard.h"

int nOfhelpPages = 4;
int helpPage = 0;

char text[63][100] = {
"Como jogar DropMerge de Terminal\n",
"\n",
"No DropMerge de Terminal, o objetivo é combinar\n",
"blocos numéricos idênticos para formar números maiores,\n",
"como 2, 4, 8, 16 e assim por diante. O jogo desafia sua\n",
"capacidade de raciocínio lógico e planejamento estratégico.\n",
"\n",
"Selecionando a Coluna\n",
"No topo do tabuleiro, há um asterisco (*) que indica\n",
"a coluna onde o próximo bloco será solto. Você pode\n",
"mover esse marcador usando as teclas:\n",
"\n",
"A: Move o * para a coluna à esquerda.\n",
"D: Move o * para a coluna à direita.\n",
"Escolha cuidadosamente a coluna para combinar blocos\n",
"idênticos e liberar espaço no tabuleiro.\n",
"\n",
"Fim de Jogo e Uso da Borracha\n",
"O jogo acaba quando os blocos alcançam o topo do\n",
"tabuleiro, impossibilitando novos movimentos.\n",
"Quando isso ocorre, a borracha é ativada automaticamente,\n",
"permitindo que você apague números para continuar jogando.\n",
"\n",
"Assim que a borracha for ativada, você deve escolher\n",
"a posição a ser apagada movendo o cursor com:\n",
"\n",
"W: Move para cima.\n",
"A: Move para a esquerda.\n",
"S: Move para baixo.\n",
"D: Move para a direita.\n",
"Após escolher a posição, o número será apagado,\n",
"liberando espaço para continuar o jogo.\n",
"\n",
"Desbloqueando a Borracha\n",
"A primeira borracha é desbloqueada ao alcançar 1024.\n",
"As demais são desbloqueadas ao atingir uma pontuação\n",
"seguindo a fórmula: ultima borracha * 2^3.\n",
"\n",
"Por exemplo:\n",
"\n",
"A segunda borracha é desbloqueada em 1024 * 8 = 8192.\n",
"A terceira em 8192 * 8 = 65536, e assim por diante.\n",
"Essa progressão torna o jogo desafiador, exigindo\n",
"estratégia para alcançar pontuações altas.\n",
"\n",
"Modos de Borracha\n",
"Existem dois modos de borracha:\n",
"\n",
"Modo Simples: Apaga apenas o número selecionado.\n",
"Modo Avançado: Apaga todos os números ao redor\n",
"da posição selecionada, permitindo limpar áreas maiores.\n",
"Você pode escolher o modo de borracha nas configurações.\n",
"Planeje bem o uso, pois as borrachas são limitadas e\n",
"essenciais para continuar jogando quando o tabuleiro encher.\n",
"\n",
"Dicas para Jogar Melhor\n",
"\n",
"Combine números estrategicamente para liberar espaço.\n",
"Planeje seus movimentos observando as próximas peças.\n",
"Pense antes de usar a borracha, já que são desbloqueadas\n",
"com pontuações altas e podem ser decisivas na partida.\n",
"Agora que você conhece as regras, desafie-se a alcançar\n",
"as maiores pontuações e domine o DropMerge de Terminal!\n"
};

void showHelp(){
  printf("\033[0m==================================================\033[0m\n");
  printf("              Sobre o DropMerge!\n");
  printf("\033[0m--------------------------------------------------\n");
  
  for(int i = helpPage*15; i<helpPage*15+15; i++){
    printf("%s", text[i]);
  }

  printf("\n\n");
  printf("          Use A e D para passar as páginas");
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