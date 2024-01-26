# include <stdio.h> // biblioteca de comuicação com o usuário
# include <stdlib.h> // biblioteca de espaço de locação de memória
# include <locale.h> // biblioteca de locação de textos por região
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro() //função responsavel por cadastrar os usuários no sistema
{
	//inicio de criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de criação de variaveis/string

	
	printf("Digite o CPF a ser cadastrado: "); //coletando inforção do usuario
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
		printf("Não foi possível localizar o arquivo, não encontrado!.\n");		
	}
	
	printf("\nEssas são as informações do usuário: \n");
	
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
		
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!. \n");
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
		
		printf("#### Cartório Da EBAC ### \n\n"); //inicio
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n");
		printf("Opçao:"); //fim do menu	
		
		scanf("%d", &opcao); //armazenando a escolha do usuario
		
		system("cls");// responsavel por limpar a tela
	
		
		switch(opcao) //inicio de seleção
		{
			case 1:
			registro(); // chamada de seleção
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
