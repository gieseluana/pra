#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct {
	int cod; 
	char *nome;
	char *t_corrida;
	char *dt_corrida;
} Registro; //Estrutura para cada registro de um corredor

int insere_reg_quantidade(){
	int registros, i, op; //Contador i e variável de escolha op
	clock_t ticks[2]; //Vetor com os valores de horário para retornar o tempo para processamento
	
	printf("\nDigite a quantidade de registros: ");
  	scanf("%d", &registros); //Lê a quantidade de registros que o usuário deseja inserir
  	printf("\nQuantidade Registros = %d\n", registros);
  	
	for (i = 1; i <= registros; i++) { //Lê os dados para a quantidade de registros escolhida 
		ticks[0] = clock();	//Horário inicial
		FILE *arquivo_maratona; //Define ponteiro referente ao arquivo
		arquivo_maratona = fopen("maratona.txt", "a+"); //Abre o arquivo e define o ponteiro para o arquivo
		Registro maratona_reg; //Define uma estrutura para a inserção		
		if(arquivo_maratona == NULL) { //Caso dê erro ao abrir o arquivo dá um retorno de erro
			printf("Erro ao Abrir"); 
			return 1;
		}

		printf("Registro %d\n",i); //Contador de registros
		system("clear || cls"); //A cada registro inserido a tela é limpa	
		printf("|	INSERIR REGISTRO	|\n");
		printf("\n1 - Código do Corredor: ");
		
		ticks[1] = clock(); //Horário final
		double t_decorrido = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC; //Tempo decorrido
				
		scanf("%d", &maratona_reg.cod); //Lê a entrada do código do corredor
		fprintf(arquivo_maratona, "%d; ", maratona_reg.cod); //Coloca o valor informado no arquivo
		
		int ch = getchar(); //Verifica o último caractere digitado pelo usuário
		
		do {
			printf("\n2 - Nome Corredor: ");
			scanf("%s",maratona_reg.nome); //Lê a entrada do nome do corredor
			ticks[0] = clock();	//Horário inicial
			fprintf(arquivo_maratona, "%s; ", maratona_reg.nome); //Coloca o valor informado no arquivo
			ticks[1] = clock();	//Horário final
			t_decorrido = t_decorrido + (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC; //Tempo decorrido
			
			printf("\n3 - Tempo de Corrida: "); 
			scanf("%s",&maratona_reg.t_corrida); //Lê a entrada do tempo de corrida do corredor
			ticks[0] = clock();	//Horário inicial
			fprintf(arquivo_maratona, "%s; ", &maratona_reg.t_corrida);	//Coloca o valor informado no arquivo
			ticks[1] = clock(); //Horário final
			t_decorrido = t_decorrido + (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC; //Tempo decorrido
			
			printf("\n4 - Data da Corrida: "); 
			scanf("%s",&maratona_reg.dt_corrida); //Lê a data em que ocorreu a corrida
			ticks[0] = clock();	//Horário inicial
			fprintf(arquivo_maratona, "%s;\n", &maratona_reg.dt_corrida); //Coloca o valor informado no arquivo	
			ticks[1] = clock(); //Horário final
			t_decorrido = t_decorrido + (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC; //Tempo decorrido
			
			printf("\n Tempo decorrido: %g ms.\n",&t_decorrido); //Mostra tempo decorrido
			printf("\n> Pressione qualquer tecla para continuar\n");
			getchar();	
			getchar(); //Informa ao usuário o tempo decorrido no processo e pede para que pressione qualquer tecla para continuar
		} while (ch != '\n' && ch != EOF); //Garante que só entrarão os scanfs de strings depois de ter confirmado o primeiro scanf
		
		fclose(arquivo_maratona); //Fecha o arquivo a cada execução para não propagar possíveis erros
	}
	
	printf("\n<== VOLTAR - PRESSIONE 0\n"); 
	scanf("%d", &op); //Lê se o usuário deseja fazer outra operação
	
	if (op == 0) { //Caso o usuário deseje fazer outra operação volta ao menu inicial
		system("clear || cls");
		return main();
	} else {
		return 0; //Sucesso
	}
}

int mostra_reg(int opcao) {
	int op1,op2, i = 1; //Variáveis de escolha op1, op2 e op3 e variável de contagem i que controla o número de registros exibido
	char c; //Variável auxiliar de leitura do arquivo
	clock_t ticks[2]; //Vetor com os valores de horário para retornar o tempo para processamento
	
	FILE *arquivo_maratona; //Define ponteiro referente ao arquivo
	arquivo_maratona = fopen("maratona.txt", "r"); //Abre o arquivo e define o ponteiro para o arquivo
	Registro maratona_reg; //Define uma estrutura para a inserção

	system("clear || cls"); //Limpa a tela do cmd
		
	printf("> 1 - ID Corredor\n");
	printf("> 2 - Nome Corredor\n");
	printf("> 3 - Tempo de Corrida\n");
	printf("> 4 - Data de Corrida\n");
	printf("> Pressione qualquer tecla para continuar\n");
	getchar();
	getchar(); //Informa ao usuário o que cada linha do registro representa e pede para que pressione qualquer tecla para continuar

	switch(opcao) {
		case 1:
			printf("\nDigite a quantidade de registros a serem visualizados = ");
			scanf("%d",&op1);
			ticks[0] = clock(); //Horário inicial
			if ((c = getc(arquivo_maratona)) != EOF) { //Se existir pelo menos um registro coloca o título Registro 1 antes dos dados do primeiro registro
				printf("\n Registro 1:\n %c",c);
			}
			else  {
				printf("\n Nenhum registro encontrado!\n"); //Caso não exista nenhum registro retorna que nenhum foi encontrado
			}
			while ((c = getc(arquivo_maratona)) != EOF && i <= op1) { //Loop para mostrar somente a quantidade de linhas desejada
				if (c == ';') { 
					printf("\n"); //Ao encontrar ";" insere uma quebra de linha para melhor visualização
				}
				else if (c == '\n' && (c = getc(arquivo_maratona)) != EOF) { //Ao encontrar "\n" considera um registro como mostrado, utilizado para controlar a quantidade de registros
					i++;
					if (i != op1 + 1) { 
						printf("\n Registro %d:\n %c",i,c); //Se não for o último registro sendo lido coloca o título "Registro + i" antes dos dados
					}	
				}
				else { 
					printf("%c", c); //Caso não entre em nenhuma das tratativas acima apenas mostra o caractere
				}
			}	
			fclose(arquivo_maratona); //Fecha o arquivo
			break;
		case 2:
			if ((c = getc(arquivo_maratona)) != EOF) {
				printf("\n Registro 1:\n %c",c); //Se existir pelo menos um registro coloca o título Registro 1 antes dos dados do primeiro registro
			}
			else {
				printf("\n Nenhum registro encontrado!\n"); //Caso não exista nenhum registro retorna que nenhum foi encontrado
			}
			while ((c = getc(arquivo_maratona)) != EOF) {
 				if (c == ';') {
					printf("\n"); //Ao encontrar ";" insere uma quebra de linha para melhor visualização
				}
				else if (c == '\n' && (c = getc(arquivo_maratona)) != EOF) {
					i++;
					printf("\n Registro %d:\n %c",i,c); //Se não for o último registro sendo lido coloca o título "Registro + i" antes dos dados
				}
				else {
					printf("%c", c); //Caso não entre em nenhuma das tratativas acima apenas mostra o caractere
				}
			}		
			fclose(arquivo_maratona); //Fecha o arquivo
			break;
	break;
	}
		
	ticks[1] = clock(); //Horário final
	double t_decorrido = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC; //Tempo decorrido
	printf("\n Tempo decorrido: %g ms.\n",&t_decorrido); //Tempo decorrido
	printf("\n<== VOLTAR - PRESSIONE 0\n");
	scanf("%d", &op2); //Lê se o usuário deseja fazer outra operação

	if (op2 == 0) { //Caso a pessoa deseje fazer outra operação volta ao menu inicial
		system("clear || cls");
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
  				printf("\nDefina a forma de inserção de registros:\n");
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
  					printf("\nTamanho = %d", tam);
  				break;
			}
		case 2: //Caso o usuário deseje ver registros, chama a função específica para isso
			printf("\nDefina a forma de visualização dos registros:\n");
			printf("1 - VISUALIZAR X PRIMEIROS REGISTROS\n");
  			printf("2 - VISUALIZAR TODOS OS REGISTROS\n");
  			printf("0 - SAIR\n\n");
  			printf("Opção: ");
  			scanf("%d", &op2); //Pede que tipo de visualização o usuário deseja fazer, se por quantidade de registros ou todos
			switch (op2) {
				case 0:
					return 0; //Caso o usuário deseje sair, sai retornando 0 (Sucesso)
				break;
				case 1: //Caso o usuário deseje visualizar uma quantidade de registros, chama a função específica para isso
					mostra_reg(1);
				break;
				case 2: //Caso o usuário deseje visualizar todos os registros, chama a função específica para isso
					mostra_reg(2);
  				break;
			}
		break;
	}
  	return 0;
}
