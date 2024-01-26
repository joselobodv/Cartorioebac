# include <stdio.h> // biblioteca de comuica��o com o usu�rio
# include <stdlib.h> // biblioteca de espa�o de loca��o de mem�ria
# include <locale.h> // biblioteca de loca��o de textos por regi�o
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro() //fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio de cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de cria��o de variaveis/string

	
	printf("Digite o CPF a ser cadastrado: "); //coletando infor��o do usuario
	scanf("%s", cpf); //%s refere-se a string

	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; // cria onarquivo 
	file = fopen(arquivo, "w"); // cria o arquivo, "w" escrever
	fprintf(file, "\nCPF: ");
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nNome: ");
	fclose(file);	
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a sere cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");			
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar o arquivo, n�o encontrado!.\n");		
	}
	
	printf("\nEssas s�o as informa��es do usu�rio: \n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{	
		printf("%s", conteudo);
		printf("\n\n");				
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
		
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!. \n");
		system("pause");
		
	}
	
	
}




int main()
	{
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
				
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
		
		printf("#### Cart�rio Da EBAC ### \n\n"); //inicio
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n");
		printf("Op�ao:"); //fim do menu	
		
		scanf("%d", &opcao); //armazenando a escolha do usuario
		
		system("cls");// responsavel por limpar a tela
	
		
		switch(opcao) //inicio de sele��o
		{
			case 1:
			registro(); // chamada de sele��o
			break;
			
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;

			default:
			printf("Essa opcao nao esta disponivel!\n");
			system("pause");
			break;
		}
	}
}
