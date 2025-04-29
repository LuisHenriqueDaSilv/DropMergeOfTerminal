<div align="center">
    <h1>Drop Merge de Terminal</h1>
    <p>Projeto desenvolvido como trabalho final da disciplina Algoritmo e Programação de Computadores, ofertada pela Profª. Drª. Carla Castanho na Universidade de Brasília (UnB)</p>
</div>


## O que é 

<strong>Drop Merge de Terminal</strong> é uma versão em C, jogável via terminal, inspirada no clássico jogo de lógica onde blocos numerados caem em uma grade e se fundem ao colidir com blocos do mesmo valor. Cada fusão gera um novo bloco com valor dobrado, desafiando o jogador a planejar seus movimentos para alcançar pontuações cada vez maiores.

O objetivo é simples: combinar blocos, otimizar espaço e evitar que a grade fique cheia. Com visual minimalista e jogabilidade por teclado, esta versão traz a essência do puzzle original em uma experiência leve e acessível diretamente no terminal.

## Como jogar   

### 🎯 Movimentação e Escolha da Coluna
No topo do tabuleiro há um asterisco (*) que indica em qual coluna o próximo bloco será solto. Você pode mover esse marcador lateralmente usando as teclas:

<strong>A:</strong> move o asterisco para a esquerda

<strong>D:</strong> move o asterisco para a direita

Ao posicionar o marcador sobre a coluna desejada, o bloco será lançado ali, com a possibilidade de se fundir a outros blocos de mesmo valor. Combinações bem posicionadas ajudam a liberar espaço e manter o jogo em andamento.

### 💥 Fim de Jogo e Uso da Borracha
O jogo entra em estado de fim quando os blocos atingem o topo do tabuleiro, impossibilitando novas jogadas. Nesse momento, a borracha é ativada automaticamente como último recurso.

Durante o modo borracha, você pode mover o cursor com as teclas:

<strong>W:</strong> cima

<strong>A:</strong> esquerda

<strong>S:</strong> baixo

<strong>D:</strong> direita

Após posicionar o cursor sobre o número que deseja apagar, a ação é executada automaticamente, liberando espaço para continuar jogando.

### 🧹 Modos de Borracha
O jogo oferece dois modos distintos de uso da borracha:

<strong>Modo Simples:</strong> apaga apenas o número selecionado.

<strong>Modo Avançado:</strong> apaga todos os números ao redor da posição escolhida, permitindo limpar uma área maior do tabuleiro.

Você pode alternar entre esses modos nas configurações do jogo. É importante planejar bem o uso da borracha, já que ela é limitada e se torna essencial quando o tabuleiro estiver próximo de lotar.

### 🔓 Como Desbloquear Borrachas
A borracha não está disponível desde o início. A primeira é desbloqueada quando você alcança um bloco de valor 1024. As demais seguem uma progressão exponencial com base na fórmula:

```
próxima borracha = última borracha × 8
```
Por exemplo:

<strong>2ª borracha: 1024 × 8 = 8192</strong></br>
<strong>3ª borracha: 8192 × 8 = 65536</strong></br>
<strong>4ª borracha: 65536 × 8 = 524288</strong>

Essa progressão torna o jogo mais desafiador à medida que você avança, exigindo decisões cada vez mais estratégicas.

## Como compilar o projeto

### Requisitos de sistema

- <a href="https://gcc.gnu.org/install/download.html">GNU Compiler Collection-GCC</a> 
- <a href="https://www.gnu.org/software/make/manual/make.html">GNU Make</a> (Opcional)

### Clone o repositório em sua máquina
```bash
git clone https://github.com/LuisHenriqueDaSilv/DropMergeOfTerminal.git
cd DropMergeOfTerminal # Entra no diretório clonado
```

### Compile
<strong>Usando o Make:</strong>
```bash
make
```
ou
<strong>Usando GCC: </strong>

```bash
gcc ./src/main.c ./src/keyboard/keyboard.c ./src/keyboard/keyboard.h ./src/menu/menu.c ./src/menu/menu.h ./src/game/game.h ./src/game/game.c ./src/utils/utils.h ./src/utils/printCenter.c ./src/game/fall.c ./src/utils/mySleep.c ./src/game/merge.c ./src/menu/getNickname.c ./src/utils/clearTerminal.c ./src/game/rankingController.c ./src/menu/ranking.c ./src/game/gameover.c ./src/menu/help.c ./src/menu/settings.c  -o ./run -lm
```

caso tudo tenha dado certo, já é possivel executar o jogo com o seguinte comando:

```bash
./run
```