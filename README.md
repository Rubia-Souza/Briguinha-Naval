# **🚢Briguinha Naval**

## **Descrição**

Este projeto é um jogo de Batalha Naval que utiliza interface gráfica por meio da biblioteca Raylib.

## **Estrutura do Projeto**

### **Separação geral**

O código possui dois tipos principais de classe: As classes lógicas e de interface.

As classes de interface são apenas responsáveis por renderizar os componentes na tela e detectar possíveis eventos que podem ocorrer nela. Qualquer tipo de informação que será processada ou armazenada é transferida da classe de interface para a classe lógica. Para realizar esse comportamento, as classes de interface sempre possuem como um atributo uma referência para a sua representação lógica. Assim, cada classe de interface possui uma representação lógica e a interface age apenas como uma forma de coletar e filtrar dados.

Já as classes lógicas, são responsáveis por executar o fluxo do jogo e manter as informações armazenadas. Portanto, elas são responsáveis por realizar a verificação de jogadas, manter registro das pontuações dos jogadores, guardar o posicionamento das tropas entre outras necessidades do jogo.

### **Entidades do projeto**

Dentre as classes lógicas, temos os seguintes elementos principais do jogo:

- **Troop:** É uma unidade posicionada pelo jogador que possui vida e pode ser atingida pelo adversário

- **Board:** É responsável por armazenar a localização das tropas de um jogador

- **Score:** É o registro do desempenho do jogador em um determinado jogo

- **Player:** São os usuários e carregam possuem conhecimento da sua pontuação e tabuleiro

- **Match:** É a representação de uma partida entre dois jogadores, realizando a mediação durante ela

Já as classes de interface, nós temos três subtipos:

- **Components:** Representam elementos simples em uma interface, como um botão, texto e imagem

- **Views:** São agrupamentos de componentes, formando um componente mais complexo

- **Screen:** São as telas propriamente ditas que o usuário irá interagir. Além de agrupar componentes e views, elas realizam a detecção de eventos e tratam eles conforme for necessário.

Todo o fluxo de turnos do jogo, definido o começo, que seria a etapa de posicionamento, o meio e o fim é definido pelo GameManager. Essa é uma classe orquestradora, que realiza a integração entre a parte lógica e de interface, transferindo as informações de tela para tela e passando as referências lógicas para as interfaces.

Já as telas são carregadas pelo ScreenManager, que é responsável por carregar e uma determinada tela e renderizar-lá no monitor.

## **Compilação**

### **Pré requisitos**

- Para compilar o projeto, é apenas necessário que você possua o compilador g++. 

    - Para o Windows, é recomendado utilizar o [mingw32](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/8.1.0/threads-posix/dwarf/).

### **Compilar com arquivos batch**

Os batchs realizam as seguintes funções:

- **Build.bat & Build.sh:** Criam a pasta build caso não exista e executa o comando make.

- **Clean.bat & Clean.sh:** Deleta todos os arquvios na pasta build do projeto e o executável.

- **Run.bat & Run.sh:** Inicializam o executável.

#### **Windows**

No Windows, você pode abrir a pasta batchs/bats no seu terminal de preferência e executar o arquivo ``Build.bat``.

#### **Linux**

No Linux, você pode abrir a pasta batchs/shs no seu terminal de preferência.

Após isso, você deve executar o seguinte comando: (Esse passo é necessário apenas na primeira vez que você executar um dos arquivos .sh)

``chmod +x Build.sh Clean.sh Run.sh``

Por fim, você pode executar o arquivo ``Build.sh`` para compilar o projeto.

### **Compilar com make**

Caso queira compilar manualmente o projeto, primeiramente, você deve criar uma pasta chamada ``build`` na raiz do projeto.

#### **Windows**

No Windows, você deve executar o seguinte comando na pasta raiz do repositório para compilar o projeto:

``mingw32-make windows_build_BriguinhaNaval``

Para limpar o projeto, você deve executar o seguinte comando:

``mingw32-make window_clean``

#### **Linux**

No Linux, você deve executar o seguinte comando na pasta raiz do repositório para compilar o projeto:

``make linux_build_BriguinhaNaval``, ou simplesmente ``make``

Se desejar compilar e executar o projeto, você deve executar o comando:

``make run``

Para limpar o projeto, você deve executar o seguinte comando:

``make clean``

## **Dificuldades**

As principais dificuldades que encontramos ao longo do projeto foram:

1. Conseguir modelar o projeto de forma flexível que irá conseguir se adaptar a possíveis modificações no futuro.

2. Planejar a forma como os diferentes módulos do sistema iriam interagir.

3. Criar elementos de interface simples que podem ser facilmente reutilizados em diferentes contextos sem ter repetição de código ou propagação de mudanças.

4. Tempo de desenvolvimento, pois muitas coisas tiveram que ser desenvolvidas do zero.

5. Utilização da biblioteca Raylib por não ter uma documentação muito extensa.