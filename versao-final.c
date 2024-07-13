#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	typedef struct{	//struct anonima com o "apelido" de central_zoo;

		char raca[100]; //teste

		char sexo[30];

		int idade;

		int codigo;

		char data_entrada[10];

	}central_zoo;

	int tela_inicial(int menu){ //menu inicial do programa com 5 opcoes de gerenciamento do zoo;

    	puts("Bem vindo ao menu de gerenciamento do zoologico!"); //a variavel menu armazena a opcao do usuario;

    	puts("Escolha uma das opcoes abaixo:");

    	puts("1 - Cadastrar animal");

    	puts("2 - Pesquisar");

    	puts("3 - Relatorio");

   	 	puts("4 - Animais por sexo");

    	puts("5 - Sair");

    	scanf("%d", &menu);
    	
    	system("cls");

    	return menu; //retorna a opcao do usuario;
	}

	void imprimir_dados(central_zoo animais[], int total_cadastrado){ //funcao para imprimir o relatorio;
		
		for(int i=0; i<total_cadastrado; i++){ //laco que imprime os dados de todos os animais;

			printf("Raca: %s\n", animais[i].raca);

			printf("Sexo: %s\n", animais[i].sexo);

			printf("Idade: %d\n", animais[i].idade);

			printf("codigo: %.3d\n", animais[i].codigo);

			printf("Data de entrada: %s", animais[i].data_entrada);

			printf("\n\n");
			
		}
	}
	
	void verifica_codigo(central_zoo animais[], int total_cadastrado){ //funcao para verificar se novos codigos ja existem no sistema;
    																   //caso existam, solicita um novo codigo valido;
		int i, j; 

    	for (i = 0; i < total_cadastrado; i++){
        	for (j = i + 1; j < total_cadastrado; j++){ //laco a onde compara as posicoes, nunca comparando uma posicao com ela mesma;

				if (animais[i].codigo == animais[j].codigo){ //compara os codigos inseridos;

					printf("O codigo %.3d ja foi cadastrado, insira um novo codigo:\n", animais[i].codigo);
					scanf("%d", &animais[j].codigo);

                	i = 0;
                	j = 0;
            	}
        	}
    	}
	}

	int cadastro_zoo(central_zoo animais[], int total_cadastrado){ //funcao para cadastrar novos animais;

    	int i = total_cadastrado, escolha_sexo = 0, continua_cadastro;

    	do{ //laco para cadastrar n animais;
			
        	printf("Insira a raca:\n");
        	fflush(stdin);
        	gets(animais[i].raca);

			while(escolha_sexo != 1 || escolha_sexo != 2){
				
        		printf("Insira o sexo 1-macho ou 2-femea:\n");
        		scanf("%d", &escolha_sexo);
        	
        		if(escolha_sexo == 1){
        	
					strcpy(animais[i].sexo, "Macho");
					break;
    		
				} 
			
				else if(escolha_sexo == 2){
				
        			strcpy(animais[i].sexo, "Femea");
        			break;
    			} 
			
				else{
				
        			printf("Escolha invalida.\n");
    		
				}
			
			}
			
			printf("Insira a idade: (0-120)\n");
        	scanf("%d", &animais[i].idade);
			
        	printf("Insira o codigo de registro (exemplo: 007):\n");
        	scanf("%d", &animais[i].codigo);

        	total_cadastrado++; //incrementa a quantidade de animais cadastrados;

			verifica_codigo(animais, total_cadastrado); //verifica se o codigo esta disponivel;

        	puts("Insira a data de entrada do cadastro (exemplo: 20/20/2020)");
        	fflush(stdin);
        	gets(animais[i].data_entrada);

        	i++; //incrementa i para um novo cadastro;

        	printf("Deseja fazer outro cadastro? 1-sim / 2-nao\n"); //interacao com o usuario;
        	scanf("%d", &continua_cadastro);
        	
        	system("cls");
        	
   		}while(continua_cadastro != 2); //condicao de parada do laco;

   		return total_cadastrado; //retorna o numero total de animais cadastrados;
	}	

	int submenu_pesquisa(int escolha_pesquisa, char pesquisa_raca[]){ //funcao que administra escolha de pesquisa do usuario

		int sub_escolha;

		printf("Escolha a o tipo de pesquisa que deseja realiza: 1-por sexo ou 2-por raca \n");
		scanf("%d", &escolha_pesquisa);
		
		system("cls");

		if(escolha_pesquisa == 1){

			printf("escolha o genero: 1-macho ou 2-femea \n");
			scanf("%d", &sub_escolha);
			
			system("cls");

			escolha_pesquisa = sub_escolha;

			return escolha_pesquisa;			
		}

		else if(escolha_pesquisa == 2){
			
			puts("Digite a raca desejada:");
			fflush(stdin);
			gets(pesquisa_raca);
			
			system("cls");
			
			escolha_pesquisa = 3;

			return escolha_pesquisa;
			return pesquisa_raca[30];
			
		}
	}

	void funcao_pesquisa(central_zoo animais[], int total_cadastrado){ //funcao de pesquisa por sexo ou raca

		int escolha_pesquisa = 0;
		
		char pesquisa_raca[30];

		escolha_pesquisa = submenu_pesquisa(escolha_pesquisa, pesquisa_raca);

		switch(escolha_pesquisa){

			case 1: 

				for(int i=0; i<total_cadastrado;i++){

					if(strcmp(animais[i].sexo, "Macho") == 0){

						printf("Raca: %s\n", animais[i].raca);

						printf("Sexo: %s\n", animais[i].sexo);

						printf("Idade: %d\n", animais[i].idade);

						printf("codigo: %.3d\n", animais[i].codigo);

						printf("Data de entrada: %s", animais[i].data_entrada);

						printf("\n\n");
					}
				}
				
				system("pause");
				system("cls");
				break;
			
			case 2:
				
				for(int i=0; i<total_cadastrado;i++){

					if(strcmp(animais[i].sexo, "Femea") == 0){

						printf("Raca: %s\n", animais[i].raca);

						printf("Sexo: %s\n", animais[i].sexo);

						printf("Idade: %d\n", animais[i].idade);

						printf("codigo: %.3d\n", animais[i].codigo);

						printf("Data de entrada: %s", animais[i].data_entrada);

						printf("\n\n");
					}
				}
				
				system("pause");
				system("cls");
				break;

			case 3:

				for(int i=0; i<total_cadastrado;i++){

					if(strcmp(animais[i].raca, pesquisa_raca) == 0){

						printf("Raca: %s\n", animais[i].raca);

						printf("Sexo: %s\n", animais[i].sexo);

						printf("Idade: %d\n", animais[i].idade);

						printf("codigo: %.3d\n", animais[i].codigo);

						printf("Data de entrada: %s", animais[i].data_entrada);

						printf("\n\n");
					}
				}
				
				system("pause");
				system("cls");
				break;
		}		
	}

	void relatorio_animais_zoo(central_zoo animais[], int total_cadastrado){ //gera um relatorio dos animais cadastrados;

		printf("O zoologico possui um total de %d animais cadastrados no sistema:\n\n", total_cadastrado);

		imprimir_dados(animais, total_cadastrado);
		
		system("pause");
		system("cls");
		
	}

	int submenu_animais_por_sexo(int op){ //funcao para administrar a escolha do usuario
		

		printf("\nEscolha uma das opcoes:\n");
		
		printf("1 - Apresentar total de animais por sexo \n");
		
		printf("2 - Apresentar a media de idade de animais por sexo \n");
		
		printf("Sua escolha: \n "); //interage com o usuario
		scanf("%d", &op);
		
		system("cls");
		
		return op; //retorna a escolha;

	}

	void funcao_animais_por_sexo(central_zoo animais[], int total_cadastrado){ //faz a media das idades e o numero por sexo de animais
		
		int i, contM = 0, contF = 0, SomaM = 0, SomaF = 0, Md = 0;
		
		int op = submenu_animais_por_sexo(op); //abre o submenu da funcao;

		if(op == 1) { //se retorna 1 imprime o total de cada animal;

			for(i = 0; i < total_cadastrado; i++)	{

				if(strcmp(animais[i].sexo, "Macho") == 0) {

					contM++;
				}

				if(strcmp(animais[i].sexo, "Femea") == 0) {

					contF++;
				}
			}

			printf("\nTotal de machos: %d \n", contM);
			printf("\nTotal de femeas: %d \n", contF);
			
			printf("\n");
			
			system("pause");
			system("cls");
		}

		else if(op == 2){ //se retorna 2 imprime a media das suas idades

			for(i = 0; i < total_cadastrado; i++) {

				if(strcmp(animais[i].sexo, "Macho") == 0) {
					contM++;
					SomaM = SomaM + animais[i].idade;
				}

				else if(strcmp(animais[i].sexo, "Femea") == 0) {
					contF++;
					SomaF = SomaF + animais[i].idade;
				}
				
			}
			
			if(total_cadastrado > 0){
			
			printf("\nMedia de idades dos machos: %d", Md = SomaM/contM);
			printf("\nMedia de idades das femeas: %d", Md = SomaF/contF);
			printf("\n\n");
			
			}
			else{
				
				printf("nenhum animal cadastrado!\n\n");
			}
			
			system("pause");
			system("cls");	
		}
		
	}
		
	int main(){ //main do programa

		int total_cadastrado = 0, menu = 0;

		central_zoo animais[12000]; //numero baseado no maior zoologico do mundo;

    	while(menu != 5){ //laco que permite o usuario interragir com o programa n vezes;

			menu = tela_inicial(menu); //abre a funcao de escolha do menu;

        	switch(menu){ //menu basico com switch case, a onde menu direciona a opcao do usuario;

				case 1:

					total_cadastrado = cadastro_zoo(animais, total_cadastrado);
					break;

				case 2:

					funcao_pesquisa(animais, total_cadastrado);
                	break;

				case 3:

                	relatorio_animais_zoo(animais, total_cadastrado);
                	break;

            	case 4:
            		
					funcao_animais_por_sexo(animais, total_cadastrado);
                	break;

            	case 5:

					puts("Saindo do programa...");
                	break;

				default:

					puts("Opcao invalida, ente novamente.");
        	}
    	}

    	return 0;
	}
