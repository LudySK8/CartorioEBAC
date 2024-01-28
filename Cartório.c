#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()
{
    char arquivo[50];
    char cpf[15];
    char nome[20];
    char sobrenome[20];
    char cargo[20];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);

    FILE *file;
    file = fopen(arquivo, "w");
    fprintf(file, "%s", cpf);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome para ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    system("pause");
}

int consulta()
{
    setlocale(LC_ALL, "Português"); //Definindo variáveis

    char cpf[40];
    char conteudo[200]; 

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("Não foi possivel abrir o arquivo, não localizado!.\n");
    }

    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
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
    	printf("O usuário não se encontra no sistema!.\n");
    	system("pause");
	}
}

int main()
{
    int opcao = 0; //Definindo variáveis
    int laco = 1;

    while (laco == 1)
    {
        system("cls");
        setlocale(LC_ALL, "Português"); //Definindo variáveis
        printf("### Cartório da EBAC ###\n\n"); //inicio do menu
        printf("Escolha a opção desejada do menu\n\n");
        printf("\t1 - Nomes de registradores\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Removendo nomes\n");
        printf("Opção: "); //fim do menu
        scanf("%d", &opcao); //armazenando a escolha do usuário
        system("cls");
        switch (opcao) //inicio da seleção
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
        default:
            printf("Essa opção não está disponível!\n");
            system("pause");
            break;
        } //fim da seleção
    }

}
