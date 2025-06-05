# Raycasting com minecraft

Este projeto é uma implementação simplificada de um jogo estilo "Minecraft" rodando inteiramente no terminal, desenvolvido como Trabalho de Conclusão de Curso (TCC) para o curso de Ciência da Computação (2026).

> **Destaque:** O principal foco do projeto é a implementação de um sistema de **raycasting** em C puro para renderizar um ambiente 3D de blocos em ASCII no terminal, simulando visão em primeira pessoa de forma eficiente e didática.

## Sumário

- [Descrição](#descrição)
- [Controles](#controles)
- [Como compilar e rodar](#como-compilar-e-rodar)
- [Arquitetura e arquivos principais](#arquitetura-e-arquivos-principais)
- [Dependências](#dependências)
- [Autor](#autor)

---

## Descrição

O projeto simula um ambiente 3D de blocos, permitindo ao usuário navegar, visualizar e interagir com o mundo usando apenas o teclado.  
O **diferencial** deste trabalho é o uso de técnicas de **raycasting** para renderizar o mundo em ASCII diretamente no terminal, proporcionando uma experiência de visão em primeira pessoa semelhante a jogos clássicos, mas totalmente em modo texto.

O raycasting é responsável por calcular, para cada "raio" disparado da posição do jogador, qual bloco é atingido e como ele deve ser exibido na tela, levando em conta ângulo de visão, profundidade e obstáculos.

## Controles

- `i`, `j`, `k`, `l`: Movimentação do jogador (frente, esquerda, trás, direita)
- `w`, `a`, `s`, `d`: Rotação da câmera (cima, esquerda, baixo, direita)
- `q`: Sair do jogo
- `x`: Remover bloco à frente
- `espaço`: Colocar bloco à frente

## Como compilar e rodar

1. **Clone o repositório** (se necessário):

    ```sh
    git clone <url-do-repo>
    cd Tcc_Minicraft_In_Terminal-CC-2026
    ```

2. **Compile o projeto**:

    ```sh
    make
    ```

3. **Execute o jogo**:

    ```sh
    ./minecraft
    ```

4. **Para limpar os binários**:

    ```sh
    make clean
    ```

## Arquitetura e arquivos principais

- **source/main.c**  
  Função principal do jogo. Inicializa o terminal, mundo, laço principal de execução e gerencia a entrada do usuário.

- **source/LibCKayke.h**  
  Header central do projeto, define structs, funções utilitárias e constantes globais.

- **source/init.c**  
  Inicialização das estruturas do mundo (blocos, direções de visão, etc).

- **source/vector.c**  
  Funções matemáticas para manipulação de vetores e ângulos.

- **source/raycasting.c**  
  **Coração do projeto:** Implementa o algoritmo de raycasting para renderização do mundo em ASCII.

- **source/draw.c**  
  Responsável por desenhar o mundo no terminal usando caracteres ASCII e cores.

- **source/terminal.c**  
  Configura e restaura o terminal para entrada não bloqueante e sem eco.

- **source/inputKeyboard.c**  
  Gerencia o estado das teclas pressionadas.

- **source/player.c**  
  Lógica de movimentação, rotação e interação do jogador com o mundo.

## Dependências

- **Compilador C** (gcc)
- **Bibliotecas padrão do C**:  
  `unistd.h`, `fcntl.h`, `stdio.h`, `termios.h`, `stdlib.h`, `math.h`

O projeto foi desenvolvido e testado em ambiente Linux.

## Autor

- Kayke Gy (kaykegy@proton.me)

---

Sinta-se à vontade para contribuir ou sugerir melhorias!