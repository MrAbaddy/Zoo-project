#include <stdio.h>
#include <string.h>

	typedef struct{	//struct anonimo com o "apelido" de central_zoo;
    	
		char raca[100];
    	
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
                	
					printf("O codigo %.3d ja foi cadastrado, insira um novo codigo:\n", animais[j].codigo);
					scanf("%d", &animais[j].codigo);
                	
                	j = i; //igua-la j a i para realizar a verificacao novamente;
            	}
        	}
    	}
	}
	
	int cadastro_zoo(central_zoo animais[], int total_cadastrado){ //funcao para cadastrar novos animais;
    	
    	int i = 0;
    	
		char continua_cadastro[4]; //string que serve como condicao de parada para do-while;
		
    	do{ //laco para cadastrar n animais;

        	printf("Insira a raca:\n");
        	fflush(stdin);
        	gets(animais[i].raca);

        	printf("Insira o sexo:\n");
        	fflush(stdin);
        	gets(animais[i].sexo);

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

	void funcao_pesquisa(){
	
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
	
	void funcao_animais_sexo(){
		
	}
	
	int main(){ //main do programa
    
		int total_cadastrado = 0, menu = 0;
    
		central_zoo animais[total_cadastrado];

    	while(menu != 5){ //laco que permite o usuario interragir com o programa n vezes;
        	
			menu = tela_inicial(menu); //abre a funcao de escolha do menu;

        	switch(menu){ //menu basico com switch case, a onde menu direciona a opcao do usuario;
            	
				case 1:
                	
					total_cadastrado = cadastro_zoo(animais, total_cadastrado);
					break;
            	
				case 2:
                
					puts("Pesquisa selecionada.");
                	break;
            	
				case 3:
					
                	relatorio_animais_zoo(animais, total_cadastrado);
                	break;
                	
        case 4:
                	
					        puts("Listagem de animais por sexo selecionada.");
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
