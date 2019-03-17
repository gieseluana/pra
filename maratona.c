#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	int cod;
	char *nome;
	char *t_corrida;
	char *dt_corrida;
} Registro;

int insere_reg_quantidade(int registros){
	int i, op;
	
	for (i = 0; i < registros; i++) {
		FILE *arquivo_maratona;
		arquivo_maratona = fopen("maratona.txt", "a+");
		Registro maratona_reg;

		if(arquivo_maratona == NULL){
			printf("Erro ao Abrir");
			return 1;
		}
		
		printf("Registro %d",i);
		system("clear || cls");
		printf("|	INSERIR REGISTRO	|\n");
		printf("\n1 - CÃ³digo Corredor: ");
		scanf("%d", &maratona_reg.cod);
		fprintf(arquivo_maratona, "%d  ", maratona_reg.cod);
		int ch = getchar();
		do {
			printf("\n2 - Nome Corredor: ");
			fgets(maratona_reg.nome, sizeof(maratona_reg.nome), stdin);
			fputs(maratona_reg.nome, arquivo_maratona);
			printf("\n2 - Nome Corredor: ");
			fgets(maratona_reg.t_corrida, sizeof(maratona_reg.t_corrida), stdin);
			fputs(maratona_reg.t_corrida, arquivo_maratona);
		} while (ch != '\n' && ch != EOF);
		
		fclose(arquivo_maratona);	

		
			/*printf("\n4 - Data da Corrida: ");
			fgets(maratona_reg.dt_corrida, sizeof(maratona_reg.dt_corrida), stdin);
			fprintf(arquivo_maratona, "%s ", maratona_reg.dt_corrida);*/
		
		
	}
	
	printf("<== VOLTAR - PRESSIONE 0");
	scanf("%d", &op);
}

int mostra_reg(){
	int op1,op2;
	char c;
	
	FILE *arquivo_maratona;
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
			while(fscanf(arquivo_maratona, "%c", &c) != EOF){
				printf("%c", c);
			}
			fclose(arquivo_maratona);
		break;
	}
	printf("\n\n<== VOLTAR - PRESSIONE 0");
	scanf("%d", &op2);
}



int main(){
	setlocale(LC_ALL, "Portuguese");
  	int op, registros, tam;
  	
  	printf("Defina a quantidade de registros\n");
  	printf("1 - POR QUANTIDADE\n");
  	printf("2 - POR TAMANHO DO ARQUIVO\n");
  	printf("0 - SAIR\n\n");
  	printf("Opção: ");
  	scanf("%d", &op);
  	if(op == 1){
  		printf("Digite a quantidade de registros = ");
  		scanf("%d", &registros);
  		printf("Quantidade Registros = %d\n", registros);
  		insere_reg_quantidade(registros);
  	}else if(op == 2){
  		printf("Defina o tamanho do arquivo = ");
  		scanf("%d", &tam);
  		printf("Tamanho = %d\n", tam);
  	}else{
  		return 0;
  	}
  	return 0;
}
