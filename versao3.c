#include <stdio.h>
#include <string.h>

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

    	return menu; //retorna a opcao do usuario;
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

    	int i = 0, escolha_sexo = 0;

		char continua_cadastro[4]; //string que serve como condicao de parada para do-while;

    	do{ //laco para cadastrar n animais;

        	printf("Insira a raca:\n");
        	fflush(stdin);
        	gets(animais[i].raca);

        	printf("Insira o sexo 1-macho ou 2-femea:\n");
        	scanf("%d", &escolha_sexo);
        	
        	if(escolha_sexo == 1){
        	
				strcpy(animais[i].sexo, "Macho");
    		
			} 
			
			else if(escolha_sexo == 2){
				
        		strcpy(animais[i].sexo, "Femea");
    		} 
			
			else{
				
        		printf("Escolha invalida.\n");
    		
			}

        	printf("Insira a idade:\n");
        	scanf("%d", &animais[i].idade);

        	printf("Insira o codigo de registro (exemplo: 777):\n");
        	scanf("%d", &animais[i].codigo);

        	total_cadastrado++; //incrementa a quantidade de animais cadastrados;

			verifica_codigo(animais, total_cadastrado); //verifica se o codigo esta disponivel;

        	puts("Insira a data de entrada do cadastro (exemplo: 20/20/2020)");
        	fflush(stdin);
        	gets(animais[i].data_entrada);

        	i++; //incrementa i para um novo cadastro;

        	printf("Deseja fazer outro cadastro? sim / nao\n"); //interacao com o usuario;
        	fflush(stdin);
        	gets(continua_cadastro);


   		}while (strcmp(continua_cadastro, "sim") == 0); //condicao de parada do laco;

   		return total_cadastrado; //retorna o numero total de animais cadastrados;
	}	

	int submenu_pesquisa(int escolha_pesquisa){ //funcao que administra escolha de pesquisa do usuario

		int sub_escolha;

		printf("Escolha a o tipo de pesquisa que deseja realiza: 1-por sexo ou 2-por raca \n");
		scanf("%d", &escolha_pesquisa);

		if(escolha_pesquisa == 1){

			printf("escolha o genero: 1-macho ou 2-femea \n");
			scanf("%d", &sub_escolha);

			escolha_pesquisa = sub_escolha;

			return escolha_pesquisa;			
		}

		if(escolha_pesquisa == 2){

			escolha_pesquisa = 3;

			return escolha_pesquisa;

		}
	}

	void funcao_pesquisa(central_zoo animais[], int total_cadastrado){ //funcao de pesquisa por sexo ou raca

		int escolha_pesquisa = 0;

		char pesquisa_raca[30];

		escolha_pesquisa = submenu_pesquisa(escolha_pesquisa);

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

				break;

			case 3:

				puts("Digite a raca desejada:");
				fflush(stdin);
				gets(pesquisa_raca);

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

				break;
		}		
	}

	void relatorio_animais_zoo(central_zoo animais[], int total_cadastrado){ //gera um relatorio dos animais cadastrados;

		printf("O zoologico possui um total de %d animais cadastrados no sistema:\n\n", total_cadastrado);

		for(int i=0; i<total_cadastrado; i++){ //laco que imprime os dados de todos os animais;

			printf("Raca: %s\n", animais[i].raca);

			printf("Sexo: %s\n", animais[i].sexo);

			printf("Idade: %d\n", animais[i].idade);

			printf("codigo: %.3d\n", animais[i].codigo);

			printf("Data de entrada: %s", animais[i].data_entrada);

			printf("\n\n");
		}

	}

	int submenu_animais_por_sexo(){ //funcao para administrar a escolha do usuario



	}

	void funcao_animais_sexo(){ //listagem de animais 


	}

	void pesquisa_sexo(central_zoo animais[], int total_cadastrado)  {
		char sexo[20];
		int op, i, contM = 0, contF = 0; 
		float SomaM = 0, SomaF = 0, Md;

		printf("\nEscolha uma das opcoes \n");
		printf("\n1 - Apresentar total de animais por sexo \n");
		printf("2 - Apresentar a media de idade de animais por sexo \n");
		printf("Sua escolha: ");
		scanf("%d", &op);


		if(op == 1) {

			for(i = 0; i < total_cadastrado; i++)	{

				if(strcmp(animais[i].sexo, "macho") == 0) {

					contM++;
				}

				if(strcmp(animais[i].sexo, "femea") == 0) {

					contF++;
				}
			}

			printf("\nTotal de machos: %d \n", contM);
			printf("\nTotal de femeas: %d \n", contF);
		}

		if(op == 2) {

			for(i = 0; i < total_cadastrado; i++) {

				if(strcmp(animais[i].sexo, "macho") == 0) {
					contM++;
					SomaM = SomaM + animais[i].idade;
				}

				if(strcmp(animais[i].sexo, "femea") == 0) {
					contF++;
					SomaF = SomaF + animais[i].idade;
				}
			}

			printf("\nMedia de idades dos machos: %.2f", Md = SomaM/contM);
			printf("\nMedia de idades das femeas: %.2f", Md = SomaF/contF);
			printf("\n");
		}
	}

	int main(){ //main do programa

		int total_cadastrado = 0, menu = 0;

		central_zoo animais[1000];

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

					puts("Listagem de animais por sexo selecionada.");
					pesquisa_sexo(animais, total_cadastrado);
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
