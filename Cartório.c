#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings


int registro()
{
	setlocale(LC_ALL,"Portuguese"); // Para configurar a linguagem (previamente existente na biblioteca).
	
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; // Criação das strings (previamente existentes na biblioteca).
	
	printf("Insira os dados abaixo \n\n");
	printf("CPF: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); 
	
	FILE *file; 
	file = fopen(arquivo, "w"); // Cria o arquivo.
	fprintf(file, cpf); // Escreve no arquivo as informações dadas pelo usuário.
	fclose(file);
	
		file = fopen(arquivo, "a"); // Abre o arquivo e o atualiza.
		fprintf(file,", "); // Insere a virgula para organizar a informação no banco de dados.
		fclose(file); // Fecha o arquivo.
	
	printf("Nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file,", ");
		fclose(file);
		
	printf("Sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file,", ");
		fclose(file);
		
	printf("Cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	
	printf("Digite o CPF do usuário a ser consultado: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // Abre o arquivo e lê as informações do usuário.
	
	if(file == NULL)
	{
		printf("Usuário não encontrado. Por favor tente novamente.");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Condicional para retornar as informações do usuário.
	{
		printf("Informações do usuário: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); 
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado. \n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema.");
	}
	
	system("pause");
}


int main()

{
	int opcao=0;
	int laco=1;
	
	for(laco=1; laco=1;) // Cria um laço de repetição para conduzir as telas do programa de volta para o menu principal.
	{
	
		system("cls"); //Responsável por limpar a tela.
		
		setlocale(LC_ALL,"Portuguese");
		
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada no menu\n\n");
		printf("\t1 - Registrar \n");
		printf("\t2 - Consultar \n");
		printf("\t3 - Deletar \n\n");
		printf("\t4 - Sair do sistema \n\n");
		printf("Opção: ");
		
		scanf("%d", &opcao); // Armazena a escolha do usuário.
		
		system("cls");
		
		switch(opcao) // Forma otimizada sem o uso repetitivo de if e else na criação de opções no menu.
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Até a próxima! \n");
			return 0;
			break;
			
			default:
			printf("Opção inválida. Por favor, tente novamente. \n");
			system("pause");
			break;
		}
		
	}
}
