# Programa de locação de carros.

## Obetivos.

O objetivo desse projeto é criar um programa que permite cadastrar, editar e buscar itens relacionados a locação de carros.


## Funcionamento.

O program funciona com argumentos em sua chamada.

### Linux.

1. Vá até a pasta onde encontra-se o arquivo `program.c`.

2. Compile o programa com o comando `gcc program.c -o program`.
 
3. Chame o programa passando um argumento, por exeplo `./program --help`.

### Windows

Não tive a opotunidade de testar o programa em um ambiente windows. No entanto, tenho conhecimento de que agora o microsoft disponibilizou o kernel do linux integrado, assim podendo reproduzir o sistema igualmente nesse sistema operacional.

Caso deseje, você pode seguir o tutorial disponibilizado pela [microsoft](https://docs.microsoft.com/pt-br/windows/wsl/install-win10).


### Comandos.

**Argumentos principais**:

| Comando | Descrição |
|:-------:|:----------|
| --help  | Argumento de ajuda, mostra os argumentos do programa em tela. |
| --register| Argumento que realiza o registro dos veículos. | 
| --show  | Argumento que mostra todas os veículos registrados no arquivo em tela. |
| --filter | Argumento que realiza filtro dos veículos registrados em arquivo. |

**Argumentos secundários**:

| Argumentos | Alias | Descrição |
|:----------:|:-----:|:----------|
| --brand    | -b    | Marca do veículo. |
| --model    | -m    | Modelo do veículo. |
| --color    | -c    | Cor do veículo. |
| --year     | -y    | Ano do veículo. |
| --rented   | -r    | Veículo se encontra alugado. |


**Sobre os comandos**:

| Argumento | Observação |
|:---------:|:-----------|
| --register| Necessário informar todos os argumentos secundários. |
| --filter  | Passe apenas um dos argumentos secundários por filtragem. |
| --rented  | precisa de um argumento -t para verdadeiro ou -f para falso. |

**Exemplo de uso**:

Registrando um veículo:

    ./program --register -b nissan -m 350z -c preto -y 2009 -r -t

Mostrando todos os veículos cadastrados:

    ./program --show

Filtrando um veículo por marca:

    ./program --filter -b nissan
