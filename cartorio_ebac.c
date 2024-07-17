#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca de responsável de cuidar das strings

int registro()  //função responsável pelos registros
{
	setlocale(LC_ALL, "Portuguese");  //Definindo lijguagens
	//início da criação de variáveis/strings (cochete se refere ao número máximo de variaveis dentro das strings)
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variáveis/strings 
	
	printf("Digite o CPF a ser cadastrado:  "); //comando de comunicação com o usuário
	scanf("%s", cpf); //campo para ser preenchido pelo usuário  ("%s" refere-se às strings)
	
	strcpy(arquivo, cpf);  //responsavel por copiar o valor das strings
	
	FILE *file;  //Chama o arquivo
	file = fopen(arquivo, "w");  //Abre o arquivo (o "W" é o comando para escrever)
	fprintf(file,cpf); //Salva o valor da variavel
	fclose(file);  //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo (o "A" é o comando para atualizar)
	fprintf(file, ", "); //Atualiza o arquivo com o que estiver digitado entre aspas
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:  "); //Se comunica com o usuário
	scanf("%s",nome); //Aba para o usuário preencher
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,nome); //Escreve a variável no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ", "); //Escreve no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:  "); //Se comunica com o usuário
	scanf("%s",sobrenome); //Aba para o usuário preencher
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,sobrenome); //Escreve a variável no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file, ", "); //Escreve no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:  "); //Se comunica com o usuário
	scanf("%s",cargo); //Aba para o usuário preencher
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file,cargo); //Escreve a variável no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo
	fprintf(file, ".\n"); //Escreve no arquivo
	fclose(file); //fecha o arquivo
	
	system("pause"); //só avança se clicar qualquer tecla
}

int consulta() //função das consultas
{
	setlocale(LC_ALL, "Portuguese"); //Definindo lijguagens
	
	//início da criação de variáveis
	char cpf[40];
	char conteudo[200];
	//fim da criação de variáveis
	
	printf("Digite o cpf a ser consultado: "); //Se comunica com o usuário
	scanf("%s",cpf); //Aba para o usuário preencher
	
	FILE *file; //Chama o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo (o "R" tem a função de escanear)
	
	if(file == NULL) //Comando caso o arquivo for nullo
	{
		printf("O cadastro não foi localizado!\n"); //Se comunica com o usuário
	}
	
	while(fgets(conteudo, 200,file)!=NULL) //Comando de escaneamento (se escanear e não encontrar o arquivo se torna nullo)
	{
		printf("\nEssas são as informações do usuário:\n\n "); //Se comunica com o usuário
		printf("%s", conteudo); //Aba para o usuário preencher
		printf("\n\n"); //Se comunica com o usuário (nesse casso, apenas pulou duas linhas)
	}
	
	fclose(file); //fecha o arquivo
    system("pause"); //só avança se clicar qualquer tecla
}

int deletar() //função de deletar usuários
{
	char cpf[40]; //Criação de variável
	
	printf("Digite o CPF a ser deletado: "); //Se comunica com o usuário
	scanf("%s",cpf); //Aba para o usuário preencher
	
	
	FILE *file; //Chama o arquivo
	file = fopen(cpf,"r"); // //Abre o arquivo  (o "r" é para escanear)
	
    
	if(file == NULL) //Comando caso o arquivo for nullo
    {
    	printf("O usário não se encontra no sistema!\n"); //Se comunica com o usuário
	}
	
	else //comando caso não seja conforme o comando "IF" exige
	    
	    printf("O usuário foi deletado com sucesso!\n"); //Se comunica com o usuário
	    fclose(file);    //fecha o arquivo
	    
	    remove(cpf); //remove a váriavél citada
	    system("pause"); //só avança se clicar qualquer tecla

   
}
int main() //Função principal
{
	int opcao=0; //Definindo variáveis do tipo inteira
    int laco=1;	 //Definindo variáveis do tipo inteira
    
	for(laco=1;laco=1;) //comando de comparação
	{
		system("cls"); //limpa a tela
					
	setlocale(LC_ALL, "Portuguese"); //Definindo lijguagens
	    
	    //Inicio do menu
	    printf("### Registro geral de alunos da EBAC ####\n\n"); //Se comunica com o usuário
    	printf("Selecione a opção desejada:\n\n"); //Se comunica com o usuário
    	printf("\t1 - Registrar alunos\n"); //Se comunica com o usuário
    	printf("\t2 - Consultar alunos\n"); //Se comunica com o usuário
    	printf("\t3 - Deletar alunos\n"); //Se comunica com o usuário
    	printf("\t4 - Sair do sistema\n\n"); //Se comunica com o usuário
    	printf("Opção:");  //Se comunica com o usuário
		//Final do menu
	
    	scanf("%d", &opcao); //Armazenando a escolha do usuário (O "%d" se refere às variáveis inteiras
	
        system("cls"); //Comando para limpar a tela
        
        
		switch(opcao) //comando de múltiplas escolhas "switchcase"
		{
			//início do menu de seleções
			case 1: //caso aplicar determinada variável
			registro(); //chamada de função
	     	break; //fecha o caso
	     	case 2: //caso aplicar determinada variável
			consulta(); //chamada de função
	    	break; //fecha o caso
	    	
	    	case 3: //caso aplicar determinada variável
	        deletar(); //chamada de função
    		break; //fecha o caso
    		
    		case 4: //caso aplicar determinada variável
    		printf("Obrigado por utilizar o sistema!\n\n"); //Se comunica com o usuário
    		return 0;  //queba laço e sai do sistema
    		break;
    		
    		default: //Comando caso a variável digitada não seja nenhuma das opções acima
    		printf("###Essa opção não é válida###\n"); //Se comunica com o usuário
    		system("pause"); //só avança se clicar qualquer tecla
    		break; //fecha o caso
		}
}
	
}
