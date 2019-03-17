#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	int cod; 
	char *nome;
	char *t_corrida;
	char *dt_corrida;
} Registro; //Estrutura para cada registro de um corredor

int insere_reg_quantidade(){
	int registros, i, op; //Contador i e variável de escolha op
	
	printf("\nDigite a quantidade de registros: ");
  	scanf("%d", &registros);
  	printf("Quantidade Registros = %d\n", registros);
  	
	for (i = 1; i <= registros; i++) { //Pede os dados para a quantidade de registros escolhida em main()
		FILE *arquivo_maratona; //Cria ponteiro referente ao arquivo
		arquivo_maratona = fopen("maratona.txt", "a+"); //Abre o arquivo e define o ponteiro para o arquivo
		Registro maratona_reg; // Cria uma estrutura para a inserção

		if(arquivo_maratona == NULL) { //Caso dê erro ao abrir o arquivo dá um retorno de erro
			printf("Erro ao Abrir"); 
			return 1;
		}
		
		printf("Registro %d",i); //Contador de registros
		system("clear || cls"); //A cada registro inserido a tela é limpa
		printf("|	INSERIR REGISTRO	|\n");
		printf("\n1 - Código do Corredor: ");
		scanf("%d", &maratona_reg.cod); //Pede a entrada do código do corredor
		fprintf(arquivo_maratona, "%d; ", maratona_reg.cod); //Coloca o valor informado no arquivo
		int ch = getchar(); //Verifica o último caractere digitado pelo usuário
		do {
			printf("\n2 - Nome Corredor: ");
			scanf("%s",maratona_reg.nome); //Pede a entrada do nome do corredor
			fprintf(arquivo_maratona, "%s; ", maratona_reg.nome); //Coloca o valor informado no arquivo
			printf("\n3 - Tempo de Corrida: "); 
			scanf("%s",&maratona_reg.t_corrida); //Pede a entrada do tempo de corrida do corredor
			fprintf(arquivo_maratona, "%s; ", &maratona_reg.t_corrida);	//Coloca o valor informado no arquivo
			printf("\n4 - Data da Corrida: "); 
			scanf("%s",&maratona_reg.dt_corrida); //Pede a data em que ocorreu a corrida
			fprintf(arquivo_maratona, "%s;\n", &maratona_reg.dt_corrida); //Coloca o valor informado no arquivo		
		} while (ch != '\n' && ch != EOF); //Garante que só entrarão os scanfs de strings depois de ter confirmado o primeiro scanf
		
		fclose(arquivo_maratona); //Fecha o arquivo a cada execução para não propagar possíveis erros
	}
	
	printf("<== VOLTAR - PRESSIONE 0"); //Pede se o usuário deseja fazer outra operação
	scanf("%d", &op);
	
	if (op == 0) { //Caso o usuário deseje fazer outra operação volta ao menu inicial
		return main();
	} else {
		return 0; //Sucesso
	}
}

int mostra_reg() {
	int op1,op2; //Variáveis de escolha
	char c;
	
	FILE *arquivo_maratona; //Cria ponteiro referente ao arquivo
	arquivo_maratona = fopen("maratona.txt", "a+");
	Registro maratona_reg;

	system("clear || cls");
	printf("> 1 - ID Corredor\n");
	printf("> 2 - Nome Corredor\n");
	printf("> 3 - Tempo de Corrida\n");
	printf("> 4 - Data de Corrida\n");
	printf("> Pressione 1 para listar\n");
	scanf("%d", op1);

	switch(op1){
		case 1:
			while(fscanf(arquivo_maratona, "%c", &c) != EOF) {
				printf("%c", c);
			}
			fclose(arquivo_maratona);
		break;
	}		
	printf("\n\n<== VOLTAR - PRESSIONE 0");
	scanf("%d", &op2);

	if (op2 == 0) { //Caso a pessoa deseje fazer outra operação volta ao menu inicial
		return main();
	} else {
		return 0; //Sucesso
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese"); //Seta a linguagem para português para poder utilizar acentos
  	int op1, op2, tam; //Variáveis de escolha e tamanho
	
  	do { 
  		printf("\nO que deseja realizar?\n");
  		printf("1 - INSERÇÃO DE REGISTROS\n");
  		printf("2 - LEITURA DE REGISTROS\n");
  		printf("0 - SAIR\n\n");
  		printf("Opção: ");
  		scanf("%d", &op1); //Pede a escolha do usuário, se deseja ler ou inserir registros, ou sair
	} while (op1 < 0 || op1 > 2);
	
	switch (op1) {
		case 0:
			return 0; //Caso o usuário deseje sair, sai retornando 0 (Sucesso)
		break;
		case 1: //Caso o usuário deseje inserir registros, abre um segundo menu para que escolha de que forma deseja inserir
			do {  	
  				printf("\nDefina a forma de inserção de registros\n");
  				printf("1 - POR QUANTIDADE\n");
  				printf("2 - POR TAMANHO DO ARQUIVO\n");
  				printf("0 - SAIR\n\n");
  				printf("Opção: ");
  				scanf("%d", &op2); //Pede que tipo de inserção o usuário deseja fazer, se por quantidade ou por tamanho de arquivo
			} while (op2 < 0 || op2 > 2);
			switch (op2) {
				case 0:
					return 0; //Caso o usuário deseje sair, sai retornando 0 (Sucesso)
				break;
				case 1: //Caso o usuário deseje inserir uma quantidade de registros, chama a função específica para isso
					insere_reg_quantidade(); 
				break;
				case 2: //Caso o usuário deseje inserir um registro com um tamanho definido no arquivo, chama a função específica para isso
					printf("Defina o tamanho do arquivo: ");
  					scanf("%d", &tam);
  					printf("Tamanho = %d\n", tam);
  				break;
			}
		case 2: //Caso o usuário deseje ver registros, chama a função específica para isso
			mostra_reg();
		break;
	}
  	
  	return 0;
}
