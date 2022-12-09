<h1 align = "center">
  <img src = "https://i.imgur.com/wZEodaH.png" style = "width: 40%;">

  <p align="center">
    <img src="https://img.shields.io/github/last-commit/JosManoel/ITP_Project-UNO">
    <img src="https://img.shields.io/github/languages/code-size/JosManoel/ITP_Project-UNO">
  </p>
</h1>

<p align="center">
  <a href = "#sobre-este-projeto">👨🏻‍💻 Sobre este projeto </a> &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href = "#sobre-o-jogo">🕹️ Sobre o jogo</a> &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href = "#executando_o_jogo">🤖 Executando o jogo</a> &nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;
  <a href = "#estrutura-do-bot">🏗️ Estrutura do bot</a> 
</p>
 
 ***

<h2 id = "sobre-este-projeto">👨🏻‍💻 Sobre este projeto </h2>

Este repositório contém o projeto final desenvolvido pelos alunos [José Manoel Freitas da Silva](https://github.com/JosManoel) e [João Marcelo de Souza](https://github.com/MarceloJoao), na matéria de **Introdução às Técnicas de Programação** do Bacharelado em Tecnologia da Informação, ofertada pelo IMD/UFRN. 

Neste trabalho desenvolvemos um bot em C que joga uma versão simplificada do **UNO Card Game**, criada pelos professores especificamente para esta atividade. Dentre as particularidades dessa versão está a utilização de um baralho convencional e algumas limitações, como a impossibilidade de bloquear ações de outros jogadores fora do seu turno.

O **Yugi**, bot criado para esta atividade, implementa os elementos aprendidos durante a matéria de modo a proporcionar uma partida de UNO seguindo os moldes de um duelo de [**Yu-Gi-Oh!**](https://pt.wikipedia.org/wiki/Yu-Gi-Oh!), um card game baseado no anime de mesmo nome, criado por [**Kazuki Takahashi**](https://pt.wikipedia.org/wiki/Kazuki_Takahashi).  

_**É HORA DO DUELO!**_

***

<h2 id = "sobre-o-jogo">🕹️ Sobre o jogo</h2>
Esta é uma versão do jogo de baralho Uno, com algumas diferenças:

A primeira é que este é um jogo baseado em turnos. Ou seja, um jogador só age quando for sua vez. Logo, não haverá a opção de gritar "UNO" quando um jogador tiver apenas uma carta. Essa regra foi deixada de fora.

A segunda é que ele é jogado com as cartas do baralho tradicional. Ou seja, ao invés de  cores, teremos naipes (copas ♥️, espadas ♠️, ouro ♦ e paus ♣️) e, ao invés de cartas especiais (como "Compre duas" ou "Passe a vez"), teremos cartas do baralho como Valete, Damas, Rei, Ás e Coringa. Estas cartas substituem as cartas especiais do Uno, seguindo a correspondência:

* "COMPRE 4"   : C = CORINGA
* "COMPRE 2"   : V = VALETE
* "VOLTA"      : D = DAMA
* "PULA A VEZ" : R = REI
* "MUDE A COR" : A = ÀS (muda o naipe)

O jogo é gerenciado por um "simulador" que irá controlar o jogo, dando a vez ao bot da rodada. O bot deve ler os dados da entrada-padrão (scanf) no formato especificado pelo simulador, caso contrário ele se perderá e será eliminado da partida. O bot também deve enviar suas ações para o simulador via saída-padrão (printf) no formato esperado pelo simulador, novamente sob pena de ser eliminado da partida.

As cartas do baralho sempre são no formato "ValorNaipe".
Nesse formato, Valor é um dos valores das cartas tradicionais, ou seja, **A, 2, 3, 4, 5, 6, 7, 8, 9, 10, V, D, R e C**, e Naipe é um dos seguintes naipes: ♥, ♦, ♣, ♠.

**Bom jogo!!!**
***

<h2 id = "executando-o-jogo">🤖 Executando o jogo</h2>
  
O gerenciador do jogo Uno se encontra no formato binário do Linux. Então, você precisará executá-lo sobre esse sistema operacional. Se seu computador for Windows, poderá usar o [WSL](https://learn.microsoft.com/pt-br/windows/wsl/install).

Caso não tenha o WSL, nem queira instalá-lo, você poderá executar o jogo também via [replit](https://replit.com/).

### Yugi
O bot é composto de multiplos arquivos dispostos nas pastas `controllers` e `resources`, utilizando um makefile para evitar nossa fadiga. Por isso, para compilar o projeto, é necessário ir ao terminal e executar o seguinte comando:

```sh
make all
```

> Obviamente, após compilar o projeto, o bot estará endiabrado para jogar o carteado e gritará "É HORA DO DUELO!".


### UNO!

O jogo é inteiramente gerenciado pelo `uno`, por isso, para executar o game, deve-se chamar o programa passando como parâmetro os bots que irão jogar na partida.

```sh
./uno yugi kaiba
```

> O gerenciador também possui outras opções. Para ter acesso à documentação completa, execute o gerenciador com o parâmetro **-h**.


***

<h2 id = "estrutura-do-bot">🏗️ Estrutura do bot</h2>

Neste projeto você encontrará 6 arquivos responsáveis pelo bot:


- <kbd><font color="#F3778F">main.c</font></kbd>
: Arquivo principal do projeto.
- <kbd><font color="#C472A0">definitions.h</font></kbd>
: Local onde estão todas as constantes e definições de struct e enum.
- <kbd><font color="#C5DF6A">funcs.c</font></kbd>
: Definição de todas as funções comuns a ambos os arquivos.
- <kbd><font color="#AFCEE9">playerController.c</font></kbd>
: Contém todas as ferramentas necessárias para manipular as cartas da mão do bot.
- <kbd><font color="#F9B8A0">movementController.c</font></kbd>
: Responsável pelas ações de compra e descarte de cartas.
- <kbd><font color="#FFF7A9">commentController.c</font></kbd>
: Invoca o faraó Atem para o duelo.

>  A **commentController.c** também poderia ser chamada de **Enigma do Milênio**, mas ficaria complicado de entender as requisições com esse título.


<h3 align="center">Estrutura básica das funções</h3>

<p align="center">
    <img src="https://i.imgur.com/Jc8Ndko.png" style = "width: 96%;"> 
</p>

<h3 align="center">Estrutura de decisões</h3>

<p align="center">
    <img src="https://i.imgur.com/Fum7avS.png" style = "width: 90%;"> 
</p>


***

<div align = "center">

  👋 Feito com muito ☕ , 🎧, 💻 e mais um pouco de ☕.

</div>
