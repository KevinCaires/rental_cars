/*
Trabalho semestral número dois da turma de Programção Estruturada, das Faculdades Integradas Camões.

Supervisora: Profª Rosemari.
Desenvolvedores: Eduarda Costa e Kevin Caires.

Sintese:
    Objetivo: Implementar um sistema de locação de carros.

    Entradas : String.

    Respostas: Criação | Edição | Busca  de objetos.

    Help: Param : --help
*/

// Importações.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


// SESSÃO DE CONSTANTES.

// Mensagens do sistema.
#define INVLID_PARAM "Parâmetro não encontrado. Para mais ajuda use '--help'"
#define EMPTY_ARG "É necessário que passe uma informação no argumento. "
#define INCOMPLETE_CMD "Comando incompleto, é necessário passar argumentos!\nPara mais ajuda use '--help'"
#define SAVE_W_SUCCESS "Dados salvos com sucesso!"

// Constantes de definição.
#define MAX_SIZE 100
#define CSV_FILE "car_rent.csv"


// SESSÃO DE EUNMS

// Enumerate para diferenciar carros alugados dos não alugados.
enum rentend_car{
    yes = 0,
    no
};


// SESSÃO DE STRUCTS

typedef struct car_struct{
    char brand[MAX_SIZE];
    char model[MAX_SIZE];
    char color[MAX_SIZE];
    char year[MAX_SIZE];
    int rented;
} Car;


// SESSÃO DE MODULAÇÃO DAS FUNÇÕES.

void create_file(void);
void car_register(Car car);
void car_show(void);
void car_search(Car filter);
void help(void);


// PROGRAM

int main(int argc, char *argv[]){
    // Seta a linguagem para portugues.
    setlocale(LC_ALL, "portuguese");
    // Cria o arquivo caso não exista.
    create_file();
    Car car;
    char rented[1];
 
    // Se o resultado for 0, então o argumento é igual ao esperado.
    if(argc == 1 || strcmp(argv[1], "--help")==0){
        help();
    }
    // Condição e tratamento do parametro --register.
    else if(strcmp(argv[1], "--register")==0){
        // Valida o segundo argumento passado.
        for(int i=1; i<argc; i++){
            if(strcmp(argv[i], "--brand")==0 || strcmp(argv[i], "-b")==0){
                // Copia o conteúdo de arg para o ponteiro.
                strcpy(car.brand , argv[i+1]);
            }
            if(strcmp(argv[i], "--model")==0 || strcmp(argv[i], "-m")==0){
                strcpy(car.model,argv[i+1]);
            }
            if(strcmp(argv[i], "--color")==0 || strcmp(argv[i], "-c")==0){
                strcpy(car.color, argv[i+1]);
            }
            if(strcmp(argv[i], "--year")==0 || strcmp(argv[i], "-y")==0){
                strcpy(car.year, argv[i+1]);
            }
            if(strcmp(argv[i], "--rented")==0 || strcmp(argv[i], "-r")==0){
                if(strcmp(argv[i+1], "--true")==0 || strcmp(argv[i+1], "-t")==0){
                    car.rented = yes;
                }
                else if(strcmp(argv[i+1], "--false")==0 || strcmp(argv[i+1], "-f")==0){
                    car.rented = no;
                }
                else{
                    printf(INVLID_PARAM);
                }
            }
        }
        car_register(car);
    }
    // Condição que mostra os registros em tela.
    else if(strcmp(argv[1], "--show")==0){
        car_show();
    }
    // Condição que filtra a partir dos parâmetros passados.
    else if(strcmp(argv[1], "--filter")==0){
        for(int i=1; i<argc; i++){
            if(strcmp(argv[i], "--brand")==0 || strcmp(argv[i], "-b")==0){
                strcpy(car.brand, argv[i+1]);
            }
            if(strcmp(argv[i], "--model")==0 || strcmp(argv[i], "-m")==0){
                strcpy(car.model, argv[i+1]);
            }
            if(strcmp(argv[i], "--color")==0 || strcmp(argv[i], "-c")==0){
                strcpy(car.color, argv[i+1]);
            }
            if(strcmp(argv[i], "--year")==0 || strcmp(argv[i], "-y")==0){
                strcpy(car.year, argv[i+1]);
            }
            if(strcmp(argv[i], "--rented")==0 || strcmp(argv[i], "-r")==0){
                if(strcmp(argv[i+1], "--true")==0 || strcmp(argv[i+1], "-t")==0){
                    car.rented = yes;
                }
                else if(strcmp(argv[i+1], "--false")==0 || strcmp(argv[i+1], "-f")==0){
                    car.rented = no;
                }
                else{
                    printf(INVLID_PARAM);
                }
            }
        }
        car_search(car);
    }
    // Caso o parametro seja inválido ele retorna a informação na tela.
    else{
        printf(INVLID_PARAM);
    }

    return 0;
}


// Função que cria o arquivo CSV.
void create_file(void){
    FILE *file;
    // Se for NULL então o arquivo não existe.
    if(fopen(CSV_FILE, "r") == NULL){
        file = fopen(CSV_FILE, "ab");
        fprintf(file, "");
        fclose(file);
    }
}


// Registra os carros no arquivo.
void car_register(Car car){
    FILE *file = fopen(CSV_FILE, "ab");
    fprintf(file, "%s;%s;%s;%s;%d\n", car.brand, car.model, car.color, car.year, car.rented);
    fclose(file);
    printf(SAVE_W_SUCCESS);
}


// Mostra os carros em tela.
void car_show(void){
FILE *file = fopen(CSV_FILE, "rb");
    Car car[MAX_SIZE];
    char line[MAX_SIZE];
    int cars=0;

    while(fgets(line, MAX_SIZE, file) != NULL){
        char *control = strtok(line, ";");
        strcpy(car[cars].brand, control);
        control = strtok(NULL, ";");
        strcpy(car[cars].model, control);
        control = strtok(NULL, ";");
        strcpy(car[cars].color, control);
        control = strtok(NULL, ";");
        strcpy(car[cars].year, control);
        control = strtok(NULL, ";");
        car[cars].rented = atoi(control);
        cars++;
    }

    for(int i=0; i<cars; i++){
        printf("\nMARCA: %s", car[i].brand);
        printf("\nMODELO: %s", car[i].model);
        printf("\nCOR: %s", car[i].color);
        printf("\nANO: %s", car[i].year);
        if(car[i].rented == yes){
            printf("\nALUGADO [sim]");
        }
        else{
            printf("\nALUGADO [não]");
        }
        printf("\n");
    }
    fclose(file);
}


// Busca por filtro.
void car_search(Car filter){
    FILE *file = fopen(CSV_FILE, "rb");
    Car car[MAX_SIZE];
    char line[MAX_SIZE];
    int cars=0;

    while(fgets(line, MAX_SIZE, file) != NULL){
        char *control = strtok(line, ";");
        strcpy(car[cars].brand, control);
        control = strtok(NULL, ";");
        strcpy(car[cars].model, control);
        control = strtok(NULL, ";");
        strcpy(car[cars].color, control);
        control = strtok(NULL, ";");
        strcpy(car[cars].year, control);
        control = strtok(NULL, ";");
        car[cars].rented = atoi(control);
        cars++;
    }

    for(int i=0; i<cars; i++){
        // Filtra por marca.
        if(strcmp(filter.brand, car[i].brand)==0){
            printf("\nMARCA: %s", car[i].brand);
            printf("\nMODELO: %s", car[i].model);
            printf("\nCOR: %s", car[i].color);
            printf("\nANO: %s", car[i].year);
            if(car[i].rented == yes){
                printf("\nALUGADO [sim]");
            }
            else{
                printf("\nALUGADO [não]");
            }
            printf("\n");
        }
        // Filtra por modelo.
        else if(strcmp(filter.model, car[i].model)==0){
            printf("\nMARCA: %s", car[i].brand);
            printf("\nMODELO: %s", car[i].model);
            printf("\nCOR: %s", car[i].color);
            printf("\nANO: %s", car[i].year);
            if(car[i].rented == yes){
                printf("\nALUGADO [sim]");
            }
            else{
                printf("\nALUGADO [não]");
            }
            printf("\n");
        }
        // Filtra por cor.
        else if(strcmp(filter.color, car[i].color)==0){
            printf("\nMARCA: %s", car[i].brand);
            printf("\nMODELO: %s", car[i].model);
            printf("\nCOR: %s", car[i].color);
            printf("\nANO: %s", car[i].year);
            if(car[i].rented == yes){
                printf("\nALUGADO [sim]");
            }
            else{
                printf("\nALUGADO [não]");
            }
            printf("\n");
        }
        // Filtra por ano.
        else if(atoi(filter.year) == atoi(car[i].year)){
            printf("\nMARCA: %s", car[i].brand);
            printf("\nMODELO: %s", car[i].model);
            printf("\nCOR: %s", car[i].color);
            printf("\nANO: %s", car[i].year);
            if(car[i].rented == yes){
                printf("\nALUGADO [sim]");
            }
            else{
                printf("\nALUGADO [não]");
            }
            printf("\n");
        }
        // Filtra por calugado
        else if(filter.rented == car[i].rented){
            printf("\nMARCA: %s", car[i].brand);
            printf("\nMODELO: %s", car[i].model);
            printf("\nCOR: %s", car[i].color);
            printf("\nANO: %s", car[i].year);
            if(car[i].rented == yes){
                printf("\nALUGADO [sim]");
            }
            else{
                printf("\nALUGADO [não]");
            }
            printf("\n");
        }
    }
}


// Função que exibe mensagem de ajuda.
void help(void){
    printf(""
    "--help         Mostra essa messagem.\n\n"
    "PARAMETROS DE CADASTRO:\n"
    "--register     Registra novo veículo.\n"
    "       ARGUMENTOS DE REGISTER:\n"
    "           --brand : -b        Armazena a marca do veículo.\n"
    "           --model : -m        Armazena o modelo do veículo.\n"
    "           --color : -c        Armazena a cor do veículo.\n"
    "           --year  : -y        Armazena o ano do veículo.\n"
    "           --rented : -r       Armazena se o veículo está alugado ou não. "
    "Passar -t para verdadeiro e -f para falso.\n"
    "\n"
    "PARAMETROS DE LEITURA:\n"
    "--show         Mostra todos os carros registrados.\n"
    "--filter       Filtra um veículo do registro.\n"
    "       ARGUMENTOS DE FILTER:\n"
    "           --brand : -b        Filtra pela marca do veículo.\n"
    "           --model : -m        Filtra pela modelo do veículo.\n"
    "           --color : -c        Filtra pela cor do veículo.\n"
    "           --year  : -y        Filtra pelo ano do veículo.\n"
    "           --rented : -r       Filtra por estado de aluguel. "    
    "Passar -t para verdadeiro e -f para falso.\n"
    "\n");
}

