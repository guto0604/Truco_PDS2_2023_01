# Truco_PDS2_2023_01
Repositório para armazenar os códigos e informações do projeto de PDS2 da UFMG.

Disciplina ministrada pelo professor Luigi Domenico. 

Membros do grupo: 
- Augusto Cavalcanti 
- Joaquim Neto
- Mateus Alves


O projeto em questão consiste na implementação de um jogo de Truco Mineiro em C++ para 4 jogadores. A ideia é jogar pelo terminal do computador. 

O desenvolvimento do projeto busca explicitar e usar os conceitos e técnicas que aprendemos ao longo do curso, como Programação Orientada a Objetos, Modelagem, Corretude e Boas Práticas de Desenvolvimento de Software no Geral. 

## O Truco Mineiro:

O jogo que será implementado nessa disciplina consiste no Truco mineiro. Vamos passar brevemente pelas regras do Truco, assim como foi feito no arquivo de modelagem.

No truco mineiro temos 4 jogadores, unidos em duas duplas. O jogo é baseado em umsistema de mãos (rodadas), em que cada mão vale inicialmente 2 pontos para a dupla vencedora. O critério para ganhar o jogo é fazer 12 pontos, a dupla que atingir essa pontuação antes vence.

Em cada mão, cada um dos jogadores recebe 3 cartas. Dentro de uma mão, vão existir 3 rodadas, a dupla vencedora é a que vencer duas dessas, em caso de empate em alguma delas, a dupla que venceu a primeira rodada que não foi empate é a vencedora daquela mão.

Em cada rodada, o jogador que está à direita de quem deu cartas (o jogador que deu cartas e a direita são apenas simbólicos no programa) mostra uma de suas cartas, com o objetivo de ter a maior carta ao final da rodada. Depois os jogadores da direita vão mostrando, até os 4 terem mostrado.

Para que uma rodada seja vencida por uma dupla, a carta mostrada por um dos membros da dupla deve ser a maior entre as 4 cartas mostradas naquela rodada. Após vencer a rodada, a pessoa que venceu é a primeira a mostrar sua carta na próxima e seguimos a regra de pessoa a direita.

A ordem das cartas segue no truco tem a seguinte ordem:

| Carta                   | Quantidade no Baralho| OBS                          |Valor         |  
|-------------------------|----------------------|------------------------------|---------|
| 4 de Paus (Zap)         | 1                    | Vence de Todos               |14|
| 7 de Copas              | 1                    |                              |13|
| Ás de Espadas (Espadilha)         | 1                    |                    |12|
| 7 de Ouros              | 1                    |                              |11|
| Todos os 3              | 4                    | Empata com os iguais         |10|
| Todos os 2              | 4                    | Empata com os iguais         |9|
| Todos os Ás exceto o Espadilha | 3             | Empata com os iguais         |8|
| Todos os Reis           | 4                    | Empata com os iguais         |7|
| Todos os Valetes        | 4                    | Empata com os iguais         |6|
| Todas as Damas          | 4                    | Empata com os iguais         |5|
| 7 de Espadas e Paus     | 2                    | Empata com os iguais         |4|
| Todos os 6              | 4                    | Empata com os iguais         |3|
| Todos os 5              | 4                    | Empata com os iguais         |2|
| Todos os 4 exceto o Zap | 3                    | Perde de Todos menos os iguais               |1|


O valor é o que define quais cartas vencem das outras, foi usado no programa para comparar as cartas.

Como disse previamente, cada mão vale inicialmente 2 pontos para a dupla que vencer. Esse valor pode aumentar ao longo da mão, caso o jogador na sua vez, pedir Truco. Quando se pede truco, é uma proposta para o adversário que está a direita de aumentar o valor daquela mão para 4 pontos, ele tem as seguintes opções:
- Correr: Ele desiste daquela mão e a dupla que propôs o Truco faz 2 pontos
- Aceitar: A mão continua normalmente, valendo 4 pontos.
- Pedir SEIS: Contraproposta para a mão valer 6.

Caso seja pedido 6, o jogador que pediu truco tem a opção de:
- Correr: Ele desiste e a dupla que pediu 6 faz 4 pontos
- Aceitar: A mão continua normalmente valendo 6.
- Pedir "9": Contraproposta para a mão valer 10 pontos.

Na contraproposta existem as mesmas opções para quem trucou originalmente. Com o aumento sendo para valer 12, que se aceito vai ser o valor máximo, pois é a pontuação do jogo.
Existem algumas outras regras que variam de grupo e localide, mas o principal é isso.

## Classes

Vamos falar um pouquinho das classes criadas, todas estão modularizdas com seus arquvios .h e .cpp. Todos arquivos estão documentados no padrão Doxygen, dessa maneira vamos apenas passar brevemente aqui pois acompanhar pelo código é mais intuitivo.

Carta: A classe carta é uma classe onde armazenamos as informações das possíveis cartas, número, naipe e valor no jogo. Contêm os métodos entregarCarta, getValor, getCarta e jogada.

Baralho: A classe baralho contêm as 40 possibilidades de cartas armazenadas em um vetor. Tem os métodos de embaralhar e darCarta.

Jogador: Classe que armazena o Nome do jogador, número dele e qual a sua dupla. Tem os métodos, getNumero, gerNome, getDupla, receberCartas e jogarCarta.

Dupla: Essa classe cria a dupla do jogo, recebendo dois Jogadores. Tem os métodos getPontuacao, aumentarPontuacao, setNome e getNome.

Mão: Classe contendo a mão do jogo. Recebe qual jogador embaralhou aquela mão e qual a partida sendo jogada. Tem os métodos definirOrdemInicial, darCartas, pedir_truco, pedir_seis, pedir_nove, pedir_doze, comecar_mao, fim_mao, getVencedor.

Partida: Classe que define uma partida que será jogada. Tem os métodos copy, definirDuplas, setRodada, incrementarPontuacaodupla, verificarVencedor, imprimirParabens, imprimirTrofeu, imprimirPartida, getJogador, getDupla e iniciarPartida.

Rodada: Classe que define uma rodada dentro da mão, recebe o jogador que deu as cartas, qual a rodada e qual a partida. Tem os métodos getResultado, getVencedor, definirOrdem, jogar e definirVencedor.

Em relação as classes o principal é isso. Os arquivos de definição das classes estão bem documentados e com comentários, com o objetivo de facilitar a compreensão.


## Main

O arquivo Main é onde todas Classes são instanciadas e conversam entre si, de maneira a fazer o jogo acontecer. Nele temos a opção de iniciar o jogo e ao final podemos reiniciar o jogo ou finalizar o programa.



Por enquanto é isso. Obrigado
