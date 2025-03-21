#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usuarios no sitema
{
	//inicio cria��o de vari�veis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //Final cria��o de vari�veis/string
   
   printf("Digite O Cpf a ser cadastrado: "); //coletando informa��o do usu�rio.
   scanf("%s", cpf); //%s refere-se a string //salva dentro de uma string
   
   strcpy(arquivo, cpf); //respos�vel por copiar os valores das string
   
   FILE *file; //cria o arquivo 
   file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever.
   fprintf(file, cpf);//salvo o valor da vari�vel 
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
	  printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");

	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{ printf ("\nEssas s�o as informa��es do us�ario: ");
      printf("%s" , conteudo);
	  printf("\n\n");	
	} 
	
	system("pause");
}
    


int deletar() //deletando o usuario
{

    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado: \n");
    scanf("%s", cpf);
    
    remove(cpf);
    
	FILE *file; 
	file = fopen(cpf, "r");
	

	
	if(file == NULL) 
	{ 
        printf("O usu�rio n�o se encontra no sistema!. \n");
		system ("Pause");
	}      
}

int main()
   {
	int opcao=0;  //Definindo as vari�veis
	int laco=1;
	
	for (laco=1;laco=1;)
   {
         
        system("cls"); 
	
	    setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
	    
	    
	    printf("### Cart�rtio da EBAC ###\n\n");  //Inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar Nomes\n"); 
	    printf("\t4 - Sair do Sistema\n\n");
	    printf("Op��o: "); //fim do menu
	    
	    scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	    system("cls"); //respons�vel por limpar a tela
	    
	    switch(opcao) //inicio de sele��o, escolha
	    {  
	    case 1: //case, vari�vel.
	    registro(); //chama de fun��es
		break; //encerra op��o
		 
		case 2: //case, vari�vel
		consulta();
	    break; //encerra op��o
	    
	    case 3: //case, vari�vel.
	    deletar();
		break; //encerra op��o
		
		case 4:
		printf("Obrigado por Utilizar o sistema!\n"); 
		return 0; //retorna o valor zero e quebra a fun��o saindo do sistema
		break;  //
		
		
		
		default: // � usado para direcionar o programa quando � digitado um valor inv�lido
		printf("Essa op��o n�o est� disponivel!\n");
		system("pause");
		break; //encerra op��o
		}
	
   }
}



