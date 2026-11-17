# Editor de Imagens por Scripts (Scrim) — C++

Projeto da unidade curricular de **Programação** da Licenciatura em Engenharia Informática e Computação (L.EIC), **FEUP**, 2024/2025.

**Nota final do projeto: 18/20**

## Descrição

Programa em C++ que lê e executa **scripts de comandos ("scrims")** para criar e transformar imagens PNG. Cada script é uma sequência de comandos (abrir, editar, guardar), executados por ordem como um *pipeline* de processamento de imagem.

O projeto pratica **programação orientada a objetos**: classes com responsabilidades bem definidas, herança, polimorfismo e gestão manual de memória.

## Comandos implementados

| Comando | O que faz |
|---|---|
| `blank` | Cria uma imagem nova com largura, altura e cor de fundo dadas |
| `open` / `save` | Lê e grava imagens PNG |
| `invert` | Inverte as cores de todos os píxeis (negativo) |
| `to_gray_scale` | Converte a imagem para escala de cinzentos |
| `replace` | Substitui todos os píxeis de uma cor por outra |
| `fill` | Pinta um retângulo com uma cor |
| `h_mirror` / `v_mirror` | Espelha a imagem na horizontal ou na vertical |
| `add` | Sobrepõe outra imagem numa posição, ignorando uma cor "neutra" (transparência) |
| `move` | Desloca a imagem (dx, dy), preenchendo o espaço livre com a cor de fundo |
| `slide` | Deslocamento cíclico: o que sai por um lado entra pelo outro |

## Arquitetura

- **`Image`** e **`Color`**: representação de uma imagem como matriz de píxeis RGB.
- **`Command`**: classe abstrata com o método virtual `apply(Image*)`. Cada operação (`Fill`, `Slide`, `Add`, ...) é uma subclasse, segundo o padrão *Command*.
- **`ScrimParser`**: lê o ficheiro de script e cria os objetos `Command` correspondentes.
- **`Scrim`**: guarda a sequência de comandos e aplica-os por ordem à imagem.
- **`PNG`**: leitura e escrita de ficheiros PNG.
- **`Logger`** e **`Utils`**: mensagens de erro e funções auxiliares.

Para acrescentar um comando novo basta criar uma subclasse de `Command` e registá-la no parser, sem alterar o resto do código.

## Exemplo de script

```
blank 200 100 255 255 255
fill 20 20 50 50 255 0 0
h_mirror
save output/exemplo.png
```

## Tecnologias

C++ · Programação Orientada a Objetos · Padrão Command · libpng

## Autores

- André Rocha (up202407636)
- Gustavo Tibério
