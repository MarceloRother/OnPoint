# OnPoint

Trabalho de Modelagem de Sistemas 2024.3

## Conceito

OnPoint é um sistema (aplicativo desktop) de gerenciamento de ponto de empresas, onde os funcionários podem registrar seus pontos de entrada e saída, e os gestores podem visualizar e gerenciar esses registros.

## Funcionalidades Básicas

- Cadastro (F/G)
- Bater ponto de entrada e saída (F)
- Justificar ausência (F)
- Ver banco de horas (F/G)
- Registrar feriado (G)
- Férias (F/G)*
- Definir jornada de trabalho (F/G)
- Remover/Adicionar Funcionário (G)

## Funcionalidades Avançadas

- Banco de Horas X Horas Extras
- Férias*
  - Solicitação férias, vender férias, (F)
  - Aprovação férias (G)

*F: Funcionário*  
*G: Gerente*  
*Férias entra uma parte como funcionalidade básica e outra como avançada*

## Documento de Requisitos

**[Link](https://docs.google.com/document/d/1xuJsYoNLxCbsjtd0VRltBEp-ul_sF35xkzdqI95Chf4/edit?tab=t.0) para Google Docs**

## Stack

- C++ para backend
- Compilador: g++11
- Dear ImGUI para frontend
- Não é necessário banco de dados, então salvaremos em JSON
- Makefile para compilação
- Catch2 para testes (a ser definido)

Sujeridos:

- [JSON for Modern C++ para persistência](https://github.com/nlohmann/json)
- [Catch2 para testes](https://github.com/catchorg/Catch2)

## Estrutura de Diretórios

```bash
onpoint/
  ├── src/
  │   ├── main.cpp
  │   ├── model/         # Classes de modelo
  │   ├── view/          # Classes de visualização
  │   ├── controller/    # Classes de controle
  │   
  ├── test/               # Arquivos de unit-testing com a framework escolhida
  │
  ├── data/               # Arquivos de persistência JSON (Bando de dados de pobre)
  │
  ├── imgui               # Biblioteca de interface gráfica 
  ├── include/            # Headers e bibliotecas
  ├── build/              # Arquivos de compilação
  │   ├── bin/            # Executável
  │   ├── obj/            # Objetos
  │
  ├── Makefile            # Compilação
  ├── README.md           # Documentação
  ├── LICENSE             # Licença
```

## Requisitos de Desenvolvimento

- C++11 ou superior
- Compilador g++11 ou superior
- Make
- Git
- Bibliotecas necessárias para Dear ImGUI (GLFW + OpenGL)
- Dear ImGUI (incluso no projeto)

### Instalação

Ubuntu:

```bash
sudo apt install libglfw3-dev libglew-dev git build-essential -y
git clone git@github.com:MarceloRother/OnPoint.git
cd OnPoint
make
make run
```

Windows:  
*Não sei ainda kkkk*

## Build

Para compilar o projeto, basta rodar o comando `make` na raiz do projeto. O executável será gerado na pasta `build/bin/`.  
Em caso de erros do make, rodar `make clean` para limpar o cache e `make` novamente.  
**TODO: Regras de compilação para diferentes arquiteturas**
