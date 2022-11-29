# Uno

Vídeo de apresentação do projeto:
https://www.loom.com/share/6dd991e2abef48618560d80ae4c8bfdb

## Introdução

Esta é uma versão do jogo de baralho Uno, com algumas diferenças:

A primeira é que este é um jogo baseado em turnos. Ou seja, um jogador só age quando for sua vez. Logo, não haverá a opção de gritar "UNO" quando um jogador tiver apenas uma carta. Essa regra foi deixada de fora.

A segunda é que ele é jogado com as cartas do baralho tradicional. Ou seja, ao invés de  cores, teremos naipes (copas, espadas, ouro e paus) e, ao invés de cartas especiais (como "Compre duas" ou "Passe a vez"), teremos cartas do baralho como Valete, Damas, Rei, Ás e Coringa. Estas cartas substituem as cartas especiais do Uno, seguindo a correspondência:
* "COMPRE 4"   : C = CORINGA
* "COMPRE 2"   : V = VALETE
* "VOLTA"      : D = DAMA
* "PULA A VEZ" : R = REI
* "MUDE A COR" : A = ÀS (muda o naipe)

A partida será jogada com um único baralho. Assim, teremos quatro cartas de um valor. Por exemplo, 7♥, 7♦, 7♣, 7♠, com exceção do coringa, que há apenas dois: um vermelho e um preto. Porém, para seguir o padrão das cartas, os coringas terão também um naipe, mas serão apenas dos naipes: ♥ (vermelho) e ♣ (preto).

O jogo é gerenciado por um "simulador" que irá controlar o jogo, dando a vez ao bot da rodada. O bot deve ler os dados da entrada-padrão (scanf) no formato especificado pelo simulador, caso contrário ele se perderá e será eliminado da partida. O bot também deve enviar suas ações para o simulador via saída-padrão (printf) no formato esperado pelo simulador, novamente sob pena de ser eliminado da partida.

As cartas do baralho sempre são no formato "ValorNaipe".
Nesse formato, Valor é um dos valores das cartas tradicionais, ou seja, A, 2, 3, 4, 5, 6, 7, 8, 9, 10, V, D, R e C, e Naipe é um dos seguintes naipes: ♥, ♦, ♣, ♠.

Os naipes são caracteres no formato ascii estendidos, que possuem uma representação maior que um byte (char). Isso significa que eles deve ser tratados como se fossem strings.

A lógica apresentada nesse template visa ilustrar a entrada e saída de dados de um bot. Cabe a você aprimorar a lógica das ações do seu bot.

Bom jogo!!!

***

## Executando o jogo

O gerenciador do jogo Uno se encontra no formato binário do Linux. Então, você precisará executá-lo sobre esse sistema operacional. Se seu computador for Windows, poderá usar o [WSL](https://learn.microsoft.com/pt-br/windows/wsl/install).

Caso não tenha o WSL, nem queira instalá-lo, você poderá executar o jogo também via replit. Assim, você pode tanto baixar os arquivos do github e trabalhar localmente, quanto acessar e trabalhar remotamente pelo replit, como descrito a seguir.

### Trabalhando localmente

Para trabalhar no seu projeto localmente, instale o git (caso não já tenha) e crie um clone do projeto (ou faça um fork) digitando a seguinte linha no terminal (linux):

```sh
git clone https://github.com/amccampos/uno
```

Você encontrará 6 arquivos:
- `readme.md`: este arquivo.
- `bot_A.c`: template inicial com explicações para a criação de um bot.
- `bot_B.c`: contém o mesmo conteúdo de `bot_A.c`, permitindo ter um backup das explicações.
- `bot_A`: executável com um comportamento básico para fins de teste.
- `bot_B`: mesmo executável `bot_A`, mas outro nome para você poder colocar um para jogar com o outro.
- `uno`: programa gerenciador do jogo Uno.

Os arquivos `uno`, `bot_A` e `bot_B` são executáveis no formato do linux (não funcionam em outro S.O.). Você deve trabalhar, portanto, no Linux ou no WSL (sobre o Windows).

Para ter uma ideia do funcionamento do jogo, chame o programa `uno` passando como parâmetro os dois programas-bot que irão jogar na partida.

```sh
./uno bot_A bot_B
```

O console apresentará a sequência de ações realizadas pelos bots.

Para construir teu projeto, edite um dos arquivos `bot_A.c` ou `bot_B.c`. Estes arquivos são templates de um bot rudimentar, mas com instruções preciosas para você começar a implementar teu próprio bot. O arquivo compila e executa normalmente, usando, por exemplo:

```sh
gcc bot_A.c -o bot_A
```

Com esse comando, uma nova versão do programa `bot_A` é gerada e pode ser testada com `./uno bot_A bot_B`. Porém, como você verá, o comportamento é simples. O único comportamento que ele tem é descartar a carta A♥ na sua vez. Cabe a você melhorá-lo.

Lembre-se de organizar tua solução em diferentes funções e separando em diferentes módulos (arquivos .c e .h). Você pode, por exemplo, ter um módulo só com operações sobre as cartas do baralho, outro com as funções de raciocínio sobre as cartas que os outros jogadores têm na mão, entre outros.

### Trabalhando no replit

Antes de qualquer coisa, quem for trabalhar no replit terá que criar um fork do projeto que se encontra em https://replit.com/@amccampos/uno. O botão "Fork Repl" fará isso.

Os mesmos encaminhamentos fornecidos para quem for trabalhar localmente são válidos para quem for trabalhar no replit, visto que há também um terminal Linux sobre o qual você poderá trabalhar.

A principal diferença é que você não precisará instalar nada. Além disso, o botão "Play" do projeto está configurado para executar o comando:
```sh
./uno bot_A bot_B
```

Ao clicar no Play, uma nova partida será executada com os bots `bot_A` `bot_B`, levando em conta que eles já foram compilados. A responsabilidade de gerar o executável do seu bot é sua. Portanto, **sempre que você fizer uma alteração no código-fonte de seu bot, certifique-se de compilá-lo antes de clicar no botão Play**.

A forma de compilar é idêntica à compilação de quem trabalha localmente:

```sh
gcc bot_A.c -o bot_A
```
***

## Instruções para a construção do Bot

Antes da partida começar, o simulador irá enviar alguns dados para seu bot, a saber:
  * os bots que estão jogando, no formato: "PLAYERS <bot_1> <bot_2> ...";
  * o identificador de seu bot, no formato: "YOU <id>";
  * as cartas da sua mão, no formato: "HAND [ <c_1> <c_2> ... ]";
  * a carta que se encontra sobre a mesa, no formato "TABLE <c>".

Um exemplo de dados iniciais é:

```sh
    PLAYERS b1 b2 b3
    YOU b1
    HAND [ 4♥ 7♦ 2♣ V♠ A♥ 3♦ 2♣ 9♠ ]
    TABLE 8♦
```
  Seu bot deve, então, ler todos esses dados no início do programa. Veja que o conjunto de cartas na mão do bot está entre []. Cabe a você tratar essa entrada.
  

### Inicio da partida

A primeira coisa fazer é "esperar sua vez". É preciso, então, de um laço enquanto a vez do seu bot não chega. Enquanto não chega a vez do seu bot, ele estará "escutando" todos os eventos do jogo. Estes eventos são repassados para todos os bots em uma linha no formato:
  
```sh
  <ação> <complemento1> [complemento2]
```
    
Ou seja, <ação> <complemento1> estão sempre presentes na mensagem do evento, porém a presença de [complemento2] vai depender da ação e do complemento1. Por exemplo, se um bot descartar um 7 de paus, será gerado o seguinte evento:

```sh
   DISCARD 7♣
```

>  A ação é DISCARD e o complemento é 7♣. Portanto, o próximo bot deverá descartar ou um 7 (de qualquer naipe) ou uma carta do naipe ♣. Guarde essa informação porque o próximo bot poderá ser o seu.

Se a carta descartada for, por exemplo, A♣ (Ás = muda de cor), haverá um segundocomplemento com o naipe a ser seguido pelos próximos jogadores. Por exemplo: no evento "DISCARD A♣ ♥", o próximo bot deverá então descartar alguma carta do naipe ♥. O valor da carta descartada pode também pedir uma ação do próximo jogador. Por  exemplo, se for descartado o V (valete = compre 2), a primeira ação do próximo bot (pode ser o seu) deverá ser obrigatoriamente "BUY 2", sob pena do bot ser eliminado da partida.

### Sua vez de Jogar
    
Há um evento especial que não é gerado pelos outros bots, mas pelo simulador. Ele tem o formato: "TURN <id>". O simulador envia esta mensagem quando for a vez do bot de identificador <id>. Então, termine este laço interno quando for a vez do seu bot agir.
    
Seu bot realiza uma ação no jogo enviando para a saída-padrão uma string no formato:

```sh
  <ação> <complemento1> [complemento2]
```
    
Por exemplo, se o bot anterior soltar uma carta de compra (compre 2 ou compre 4), a <ação> que seu bot deve fazer é "BUY" e o <complemento1> será "2" ou "4", dependendo da quantidade de cartas que ele deve comprar. Ou seja, a string que seu bot deve enviar para a saída-padrão será:
    
    * "BUY 4", se o bot anterior soltou um Coringa (C), ou;
    * "BUY 2", se o bot anterior soltou um Valete (V).

Depois do envio desta ação, o simulador irá enviar para o seu bot uma quantidade de cartas correspondente ao número solicitado. Então, prepare-se para ler da entrada padrão as cartas. Se a ação for "BUY 2", leia duas strings. Elas serão as cartas compradas e você deve guardá-las na sua mão. Se for "BUY 4", leia 4 strings. Depois da leitura, termina a vez do seu bot e o simulador passa a vez para um outro bot.

Caso não tenha nenhuma ação de compra a ser realizada, seu bot deve jogar normalmente, que é descartar uma carta cujo valor ou naipe é o mesmo da carta da mesa. Ou seja, você deve saber qual a última carta descartada ou, se foi um Ás ou Coringa, qual o naipe solicitado. No exemplo abaixo, a <ação> é "DISCARD" e o <complemento1> é a carta a ser descartada:
    
```sh
  "DISCARD 2♣"
```
    
O bot também pode descartar uma carta especial, independente do naipe da mesa, que pode ser um Ás (A = muda de naipe) ou um Coringa (C = além de fazer o próximo comprar 4, também muda o naipe). As demais cartas devem obrigatoriamente seguir o naipe da mesa. Ao descartar um Ás ou Coringa, você deve enviar um segundo complemento para sua ação com o naipe que você deseja. Por exemplo: 

```sh
  "DISCARD C♣ ♥"
```

Neste caso, seu bot soltou um coringa preto e pediu para o naipe mudar para ♥ (o próximo jogador precisar comprar 4 cartas e o seguinte levar em conta que o ♥ é o naipe da vez). Depois do descarte, a vez do seu bot termina. 
    
 Se o bot não tiver carta com o naipe da mesa para descartar, ele deve comprar uma carta do baralho, enviando a ação "BUY" e o complemento "1", informando que ele irá comprar uma carta da pilha. Assim como as ações "BUY 2" e "BUY 4", após o envio desta ação, seu bot deve ler da entrada-padrão a carta puxada da pilha e guarde na sua mão. 
    
Vale ressaltar que nada impede do bot comprar quantas cartas quiser, mesmo tendo uma carta na mão com o valor ou naipe da mesa. Só não é possível comprar uma quantidade diferente de cartas quando ele deve obrigatoriamente comprar 2 (por causa de um Valete) ou 4 (por causa de um coringa). Depois da carta lida, não há opção de descarte. Agora, é a vez de um outro bot jogar.

### Penalidades
    
> Todas as mensagens enviadas **DEVEM terminar com salto de linha ('\n')**, caso contrário, o simulador não saberá quando uma ação termina e quebrar o sincronização das mensagens.


Qualquer ação enviada para o simulador que não seja condizente com o estado do jogo, haverá uma penalidade para o bot:
    
    * Se o bot descartar uma carta que não tem na mão ou se o naipe da carta não for o que se encontra sobre a mesa, a ação será ignorada. Ou seja, para o simulador, o bot continuará com a referida carta na mão;
    
    * Se o bot precisar comprar 2 ou 4 cartas e não enviar a ação "BUY" com o complemento correspondente, o bot sai do jogo e perde de vez a partida. 

Outra penalidade é se o bot demorar mais de 3 segundos para responder uma ação. Isso significa que a leitura e escrita dos dados está fora de sincronia com o simulador (o bot esperando um dado do simulador e o simulador esperando um dado do bot). Nesse caso, o bot também será removido da partida.
    
### Comentários durante a partida
    
Além das ações de descartar (DISCARD) e comprar (BUY), o bot pode também enviar mensagens para serem apresentadas no jogo. Essas mensagens não são repassadas para os outros bot, mas aparecem no console. Para enviar uma mensagem, o bot deverá enviar para a saída-padrão o seguinte comando:
    
```sh
  SAY <text>
```
    
O bot pode enviar quantas mensagens quiser, desde que seja *ANTES* das ações de descarte ou de compra. Alguns exemplos de mensagens são:
    
```sh
  "SAY Caramba! Eu já ia bater!"
  "SAY Tu tá lascado!!!"
```