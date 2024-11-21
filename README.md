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

### TODO: Inserir link

## Stack

- C++ para backend
- Compilador: g++11
- Qt ou Similar para frontend (a ser definido)
- Não é necessário banco de dados, então salvaremos em JSON
- Makefile para compilação
- Catch2 para testes (a ser definido)

Sujeridos:

- [Qt para frontend](https://doc.qt.io/qt-5/qtgui-index.html)
- [ou ImGUI para o frontend](https://github.com/ocornut/imgui)
- [JSON for Modern C++ para persistência](https://github.com/nlohmann/json)
- [Catch2 para testes](https://github.com/catchorg/Catch2)

## Estrutura de Diretórios

```bash
onpoint/
  ├── src/
  │   ├── main.cpp
  │   ├── models/         # Classes de modelo
  │   ├── views/          # Classes de visualização
  │   ├── controllers/    # Classes de controle
  │   
  ├── test/               # Arquivos de unit-testing com a framework escolhida
  │
  ├── data/               # Arquivos de persistência JSON (Bando de dados de pobre)
  │
  ├── include/            # Headers e bibliotecas
  ├── build/              # Arquivos de compilação
  │   ├── bin/            # Executável
  │   ├── obj/            # Objetos
  │
  ├── Makefile            # Compilação
  ├── README.md           # Documentação
  ├── LICENSE             # Licença
```

## Build

Para compilar o projeto, basta rodar o comando `make` na raiz do projeto. O executável será gerado na pasta `build/bin/`.
Em caso de erros do make, rodar `make clean` para limpar o cache e `make` novamente.
