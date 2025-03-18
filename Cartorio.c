#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuarios no sitema
{
	//inicio criação de variáveis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //Final criação de variáveis/string
   
   printf("Digite O Cpf a ser cadastrado: "); //coletando informação do usuário.
   scanf("%s", cpf); //%s refere-se a string //salva dentro de uma string
   
   strcpy(arquivo, cpf); //resposável por copiar os valores das string
   
   FILE *file; //cria o arquivo 
   file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever.
   fprintf(file, cpf);//salvo o valor da variável 
   fclose(file); //fecha o arquivo 
   
   file = fopen(arquivo, "a"); //cria o arquivo
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o nome a ser cadastrado: ");
   scanf("%s",nome);
   
   file = fopen(arquivo, "a");
   fprintf(file, nome);
   fclose(file); 
   
   file = fopen(arquivo, "a");
   fprintf(file, ",");
   fclose(file);
   
   printf("Digite o sobrenome a ser cadastrado: ");
   scanf("%s",sobrenome);
   
   file = fopen(arquivo,"a");
   fprintf(file, sobrenome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file, ",");
   fclose(file);
   
   printf("Digite o cargo a ser cadastrado: ");
   scanf("%s", cargo);
   
   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);
   

   system("pause"); 
   
}

int consulta()
{
	 setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
	 
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o Cpf a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file; 
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
	  printf("Não foi possivel abrir o arquivo, não localizado!\n");

	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{ printf ("\nEssas são as informações do usúario: ");
      printf("%s" , conteudo);
	  printf("\n\n");	
	} 
	
	system("pause");
}
    


int deletar() //deletando o usuario
{

    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: \n");
    scanf("%s", cpf);
    
    remove(cpf);
    
	FILE *file; 
	file = fopen(cpf, "r");
	

	
	if(file == NULL) 
	{ 
        printf("O usuário não se encontra no sistema!. \n");
		system ("Pause");
	}      
}

int main()
   {
	int opcao=0;  //Definindo as variáveis
	int laco=1;
	
	for (laco=1;laco=1;)
   {
         
        system("cls"); 
	
	    setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
	    
	    
	    printf("### Cartórtio da EBAC ###\n\n");  //Inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar Nomes\n\n"); 
	    printf("Opção: "); //fim do menu
	    
	    scanf("%d", &opcao); //armazenando a escolha do usuário
	
	    system("cls"); //responsável por limpar a tela
	    
	    switch(opcao) //inicio de seleção, escolha
	    {  
	    case 1: //case, variável.
	    registro(); //chama de funções
		break; //encerra opção
		 
		case 2: //case, variável
		consulta();
	    break; //encerra opção
	    
	    case 3: //case, variável.
	    deletar();
		break; //encerra opção
		
		
		
		default: // é usado para direcionar o programa quando é digitado um valor inválido
		printf("Essa opção não está disponivel!\n");
		system("pause");
		break; //encerra opção
		}
	
   }
}



