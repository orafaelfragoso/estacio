# Super Trunfo - Desafio C/C++

## Descrição

Este projeto é uma implementação do desafio Super Trunfo em C/C++, onde o usuário pode cadastrar cartas representando cidades de diferentes estados.

Cada carta contém informações sobre o estado, código, nome da cidade, população, área, PIB e número de pontos turísticos.

No total, serão cadastradas 32 cartas (8 estados x 4 cartas cada) via terminal.

## Estrutura do Projeto

```
project_root/
├── include/ # Arquivos de cabeçalho (Headers)
│ └── card.h
├── src/ # Código fonte do projeto
│ ├── card.cpp
│ └── main.cpp
├── Makefile # Script para compilação
└── README.md # Este arquivo de documentação
```

## Como Compilar e Executar

### Pré-requisitos

- Compilador C/C++ (Clang ou GCC).
- Editor de código (como Visual Studio Code, Xcode, etc.) é opcional.

### Compilando o Projeto

No terminal, navegue até a pasta raiz do projeto e execute:

```
make
```

Este comando compilará o projeto e gerará o executável chamado `supertrunfo`.

### Executando o Projeto

Após a compilação, execute o projeto com:

```
./supertrunfo
```

O sistema solicitará os dados para cada carta via terminal, e exibirá os dados cadastrados de forma organizada.

### Limpando o Projeto

Para remover os arquivos objeto e o executável, execute:

```
make clean
```

## Documentação do Código

Os arquivos do projeto foram comentados seguindo padrões de documentação (como o Doxygen) para facilitar a manutenção e compreensão do código.

Cada classe e função possui comentários explicativos sobre seu funcionamento, parâmetros e retorno.

## Considerações

- O projeto foi desenvolvido com o intuito de demonstrar boas práticas, modularidade e separação de responsabilidades.
- Sinta-se à vontade para expandir o projeto, adicionando novas funcionalidades ou integrando com outras APIs.
