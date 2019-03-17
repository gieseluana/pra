#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define TAM 50
#define TAM1 30
/*Estruturas de Aluno.*/
typedef struct {
	char nome[TAM];
	int matricula;
	char curso[TAM1];
} Aluno;

/*Estruturas de Professor.*/
typedef struct {
    char nome[TAM];
    int matricula;
    char curso[TAM1];
} Professor;

/*Estrutura de Curso.*/
typedef struct {
    char nome[TAM];
    char professor[TAM];
    int id;
}Curso;

/*Variáveis mais usadas ao longo do código.*/
int opcao;
int opcao1;
int opcao2;
char c;
int matricula_buscada;
int achou_matricula = 0;

/*Função de cadastro de curso.*/
int cad_curso(){
/*Criando e/ou acessando o arquivo do curso.*/
    FILE *arquivo_curso;
    arquivo_curso = fopen("curso.txt", "a+");
	Curso curso_fac;

    if(arquivo_curso == NULL)
    {
        printf("Erro ao abrir");
        return 1;
    }

/*Menu do Cadastro de Curso como as inserções de dados no arquivo curso.*/
            system("clear || cls");
            printf("\n********* Cadastro de Curso *********\n");
            printf("* 1.Id do curso:                    *\n");
            scanf("%d",&curso_fac.id);
            fprintf(arquivo_curso, "%d  ",curso_fac.id);
            printf("* 2.Nome do curso:                  *\n");
            scanf(" %[^\n]s",curso_fac.nome);
            fprintf(arquivo_curso, "%s ",curso_fac.nome);
            printf("*************************************\n");
            fprintf(arquivo_curso, "\n \n");
/*Fechando o arquivo curso.*/
            fclose(arquivo_curso);
            printf("Pressione 0 para voltar: ");
                scanf("%d",&opcao2);
}

/*Função de cadastro de aluno.*/
int cad_aluno(){
/*Acessando o arquivo curso.*/
	FILE *arquivo_curso;
	arquivo_curso = fopen("curso.txt", "a+");
    Aluno aluno_fac;

	     system("clear || cls");
/*Verificando a existência de um curso.*/
            if(arquivo_curso == NULL || fscanf(arquivo_curso, "%c", &c) == EOF)
            {
                printf("Curso nao encontrado!\n");
                cad_curso();
            }
                else{
/*Criando e/ou acessando o arquivo do aluno.*/
    FILE *arquivo_aluno;
    arquivo_aluno = fopen("aluno.txt", "a+");

    if(arquivo_aluno == NULL)
    {
        printf("Erro ao abrir");
        return 1;
    }
/*Menu do Cadastro de Aluno como as inserções de dados no arquivo aluno.*/
            printf("********* Cadastro de Aluno *********\n");
            printf("* 1.ID do aluno:                    *\n");
            scanf("%d",&aluno_fac.matricula);
            fprintf(arquivo_aluno, "%d  ",aluno_fac.matricula);
            printf("* 2.Nome do aluno:                  *\n");
            scanf(" %[^\n]s", aluno_fac.nome);
            fprintf(arquivo_aluno, "%s  ",aluno_fac.nome);
            printf("* 3.Curso do aluno:                 *\n");
            scanf(" %[^\n]s", aluno_fac.curso);
            fprintf(arquivo_aluno, "%s  ",aluno_fac.curso);
            printf("*************************************\n");
            fprintf(arquivo_aluno, "\n \n");
/*Fechando o arquivo aluno.*/
            fclose(arquivo_aluno);
            printf("Pressione 0 para voltar: ");
                scanf("%d",&opcao2);
    }
}

/*Função de cadastro de professor.*/
int cad_prof(){
/*Acessando o arquivo curso.*/
    FILE *arquivo_curso;
    arquivo_curso = fopen("curso.txt", "a+");
	Curso curso_fac;
    system("clear || cls");
/*Verificando a existência de um curso.*/
            if(arquivo_curso == NULL || fscanf(arquivo_curso, "%c", &c) == EOF)
            {
                printf("Curso nao encontrado!\n");
                cad_curso();
            }
                else{
/*Criando e/ou acessando o arquivo do professor.*/
    FILE *arquivo_prof;
    arquivo_prof = fopen("professor.txt", "a+");
    Professor professor_fac;

    if(arquivo_prof == NULL)
    {
        printf("Erro ao abrir");
        return 1;
    }
/*Menu do Cadastro de Professor como as inserções de dados no arquivo professor.*/
            system("clear || cls");
            printf("********* Cadastro de Professor *****\n");
            printf("* 1.ID do Professor:                *\n");
            scanf("%d",&professor_fac.matricula);
            fprintf(arquivo_prof, "%d  ",professor_fac.matricula);
            printf("* 2.Nome do Professor:              *\n");
            scanf(" %[^\n]s",professor_fac.nome);
            fprintf(arquivo_prof, "%s  ",professor_fac.nome);
            printf("* 3.Curso do Professor:             *\n");
            scanf(" %[^\n]s",professor_fac.curso);
            fprintf(arquivo_prof, "%s  ",professor_fac.curso);
            printf("*************************************\n");
            fprintf(arquivo_prof, "\n \n");
/*Fechando o arquivo professor.*/
            fclose(arquivo_prof);
            printf("Pressione 0 para voltar: ");
                scanf("%d",&opcao2);
                }
}

/*Função para deletar alunos.*/
int del_aluno(){
/*Acessando o arquivo aluno.*/
    FILE *arquivo_aluno;
    arquivo_aluno = fopen("aluno.txt", "a+");
	Aluno aluno_fac;
    	system("clear || cls");
/*Verificando a existência de um aluno.*/
            if(fscanf(arquivo_aluno, "%c", &c) == EOF)
            {
                printf("Nenhum aluno cadastrado!\n");
                cad_aluno();
            }
               else{
/*Menu de confirmação para deletar.*/
		printf("**************************************\n");
		printf("* Deseja apagar os dados dos alunos? *\n");
		printf("**************************************\n\n");
		printf("Digite 1 para continuar: ");
		scanf("%d",&opcao1);

            	switch(opcao1){
                case 1:

	system("clear || cls");
		while( remove("aluno.txt") == 0)
                    {
/*Confirmação de deleção.*/
                        printf("Alunos deletados com sucesso!");
                    }
		break;
		}
/*Confirmação para retornar ao menu principal.*/
		printf("\n\nPressione 0 para voltar: ");
                scanf("%d",&opcao2);

	}
}

/*Função para deletar curso.*/
int del_curso(){
/*Acessando o arquivo curso.*/
    FILE *arquivo_curso;
    arquivo_curso = fopen("curso.txt", "a+");
	Curso curso_fac;
    	system("clear || cls");
/*Verificando a existência de um curso.*/
            if(fscanf(arquivo_curso, "%c", &c) == EOF)
            {
                printf("Nenhum curso cadastrado!\n");
                cad_curso();
            }
               else{
/*Menu de confirmação para deletar.*/
		printf("**************************************\n");
		printf("* Deseja apagar os dados dos cursos? *\n");
		printf("**************************************\n\n");
		printf("Digite 1 para continuar: ");
		scanf("%d",&opcao1);

        switch(opcao1){
        case 1:

        system("clear || cls");
		while( remove("curso.txt") == 0)
                    {
/*Confirmação de deleção.*/
                        printf("Cursos deletados com sucesso!");
                    }
		break;
		}
/*Confirmação para retornar ao menu principal.*/
		printf("\n\nPressione 0 para voltar: ");
                scanf("%d",&opcao2);

	}
}

/*Função para deletar professores.*/
int del_prof(){
/*Acessando o arquivo professor.*/
    FILE *arquivo_prof;
    arquivo_prof = fopen("professor.txt", "a+");
	Professor professor_fac;
    	system("clear || cls");
/*Verificando a existência de um professor.*/
            if(fscanf(arquivo_prof, "%c", &c) == EOF)
            {
                printf("Nenhum professor cadastrado!\n");
                cad_prof();
            }
               else{
/*Menu de confirmação para deletar.*/
		printf("*******************************************\n");
		printf("* Deseja apagar os dados dos professores? *\n");
		printf("*******************************************\n\n");
		printf("Digite 1 para continuar: ");
		scanf("%d",&opcao1);

            	switch(opcao1){
                case 1:

	system("clear || cls");
		while( remove("professor.txt") == 0)
                    {
/*Confirmação de deleção.*/
                        printf("Professores deletados com sucesso!");
                    }
		break;
		}
/*Confirmação para retornar ao menu principal.*/
		printf("\n\nPressione 0 para voltar: ");
                scanf("%d",&opcao2);

	}
}

/*Função para listar alunos.*/
int list_aluno(){
/*Acessando o arquivo aluno.*/
    FILE *arquivo_aluno;
    arquivo_aluno = fopen("aluno.txt", "a+");
    Aluno aluno_fac;
/*Acessando o arquivo curso.*/
    FILE *arquivo_curso;
    arquivo_curso = fopen("curso.txt", "a+");
	Curso curso_fac;
    system("clear || cls");
/*Verificando a existência de um curso.*/
            if(arquivo_curso == NULL || fscanf(arquivo_curso, "%c", &c) == EOF)
            {
                printf("Curso nao encontrado!\n");
		scanf("%d", &opcao1);
                cad_curso();
            }
                else{
/*Menu com os seguintes atributos à serem listados.*/
            system("clear || cls");
            printf("********** Listar Aluno **********\n");
            printf("* 1.ID do aluno:                 *\n");
            printf("* 2.Nome do Aluno:               *\n");
            printf("* 3.Curso do Aluno:              *\n");
            printf("**********************************\n");
            printf("Pressione 1 para listar: ");
            scanf("%d",&opcao1);
            switch(opcao1){
                case 1:
/*Listando os resultados.*/
                    while(fscanf(arquivo_aluno, "%c", &c) != EOF)
                    {
                        printf("%c", c);
                    }
/*Fechando o arquivo aluno.*/
                    fclose(arquivo_aluno);
                break;
            }
	}
/*Confirmação para retornar ao menu principal.*/
		printf("\n\nPressione 0 para voltar: ");
                scanf("%d",&opcao2);
}

/*Função para listar cursos.*/
int list_curso(){
/*Acessando o arquivo curso.*/
    FILE *arquivo_curso;
    arquivo_curso = fopen("curso.txt", "a+");
	Curso curso_fac;
            system("clear || cls");
/*Menu com os seguintes atributos à serem listados.*/
            printf("********** Listar Cursos ************\n");
            printf("* 1.Id do curso:                    *\n");
            printf("* 2.Nome do curso:                  *\n");
            printf("*************************************\n");
            printf("Pressione 1 para listar: ");
            scanf("%d", &opcao1);
            switch(opcao1){
                case 1:
/*Listando os resultados.*/
                    while(fscanf(arquivo_curso, "%c", &c) != EOF)
                    {
                        printf("%c", c);
                    }
/*Fechando o arquivo curso.*/
                    fclose(arquivo_curso);
                break;
            }
/*Confirmação para retornar ao menu principal.*/
		printf("\n\nPressione 0 para voltar: ");
                scanf("%d",&opcao2);
}

/*Função para listar professores.*/
int list_prof(){
/*Acessando o arquivo professor.*/
    FILE *arquivo_prof;
    arquivo_prof = fopen("professor.txt", "a+");
    Professor professor_fac;
/*Acessando o arquivo curso.*/
    FILE *arquivo_curso;
    arquivo_curso = fopen("curso.txt", "a+");
	Curso curso_fac;
    system("clear || cls");
/*Verificando a existência de um curso.*/
            if(arquivo_curso == NULL || fscanf(arquivo_curso, "%c", &c) == EOF)
            {
                printf("Curso nao encontrado!\n");
                cad_curso();
            }
                else{
/*Menu com os seguintes atributos à serem listados.*/
            system("clear || cls");
            printf("********* Listar Professor *******\n");
            printf("* 1.ID do Professor:             *\n");
            printf("* 2.Nome do Professor:           *\n");
            printf("* 3.Curso do Professor:          *\n");
            printf("**********************************\n");
            printf("Pressione 1 para listar: ");
            scanf("%d", &opcao1);
            switch(opcao1){
                case 1:
/*Listando os resultados.*/
                    while(fscanf(arquivo_prof, "%c", &c) != EOF)
                    {
                        printf("%c", c);
                    }
/*Fechando o arquivo professor.*/
                    fclose(arquivo_prof);
                break;
            }
	}
/*Confirmação para retornar ao menu principal.*/
		printf("\n\nPressione 0 para voltar: ");
                scanf("%d",&opcao2);
}


/*Função do menu principal.*/
int menu(){
for(;;){
    system("clear || cls");
/*Menu principal com as opções.*/
    printf("*************** Menu ****************\n");
    printf("* 1.Cadastrar Aluno                 *\n");
    printf("* 2.Cadastrar Curso                 *\n");
    printf("* 3.Cadastrar Professor             *\n");
    printf("* 4.Deletar Aluno                   *\n");
    printf("* 5.Deletar Curso                   *\n");
    printf("* 6.Deletar Professor               *\n");
    printf("* 7.Listar Alunos                   *\n");
    printf("* 8.Listar Cursos                   *\n");
    printf("* 9.Listar Professores              *\n");
    printf("* 0.Sair                            *\n");
    printf("*************************************\n\n");
    printf("Digite uma opcao: ");

    scanf("%d", &opcao);

/*Escolha de opções retornando a função desejada.*/ 
    switch(opcao){
        case 1:
/*Acessando a função de cadastro de aluno.*/ 
            cad_aluno();
        break;

        case 2:
/*Acessando a função de cadastro de curso.*/
            cad_curso();
        break;

        case 3:
/*Acessando a função de cadastro de professor.*/
            cad_prof();
        break;

        case 4:
/*Acessando a função de deleção de aluno.*/
            del_aluno();
        break;

        case 5:
/*Acessando a função de deleção de curso.*/
            del_curso();
        break;

        case 6:
/*Acessando a função de deleção de professor.*/
            del_prof();
        break;

        case 7:
/*Acessando função para listagem de aluno.*/
            list_aluno();
        break;

        case 8:
/*Acessando função para listagem de curso.*/
            list_curso();
        break;

        case 9:
/*Acessando função para listagem de professor.*/
            list_prof();
        break;

        case 0:
        exit(0);

	}
  }
}

/*Função principal.*/
int main(){
for(;;){
/*Acessando a função do menu principal.*/
    menu();
}
    return 0;
}