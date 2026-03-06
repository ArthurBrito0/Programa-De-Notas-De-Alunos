//Abaixo estamos carregando a biblioteca standard input output para
//Usarmos os comandos de entrada scanf e saida printf de dados do usuario
#include <stdio.h>

/*Escreva um programa que solicite ao usuario:
    nome
    sexo
    idade
    tres notas dos n alunos em uma turma
    
    Ao final apresente:
    1- Quantidade de alunos cadastrados na turma.....  ok
    2- A quantidade de alunos e alunas (%) aprovados/reprovados na turma
    3- A media de idade dos alunos aprovados e reprovados
    4- Gerar relatorio de alunos
    5- Tornar configuravel:
    5.1- A media de aprovação;
    5.2- A quantidade de provas a serem realizadas pelo aluno.
    6- Fazer tratamento de dados na entrada do usuario (notas, idade, media, sexo)
    6.1- 0 < nota < 10
    6.2- 16 < idade  < 90
    6.3- 5 < media < 8
    6.4- sexo M/m/F/f
*/

struct Aluno {
    char Nome[30];
    char Sexo;
    int Idade;
    float Notas[10];
    bool Aprovado;
};

//A seguir temos a função princirpal
int main()
{
    int qtdAlunos, qtdAlunosM=0, qtdAlunasF=0;
    int qtdProvas;
    int somaIdades;
    float mediaAprovacao;
    struct Aluno Alunos[100];
    float media;
    float somaNotas;
    
    
    printf("Informe a quantidade de alunos da turma: ");
    scanf("%i",&QtdAlunos);
    
    printf("Informe a quantidade de provas realizadas: ");
    scanf("%i", &qtdProvas);
    
    printf("Informe a media de aprovacao: ");
    scanf("%f", &mediaAprovacao);
    
    // Informação do nome, idade e sexo dos alunos
    for(int i =0; i<qtdAlunos;i++){
    	media = 0;
    	somaNotas = 0;
    	
    	printf("\n");
        printf("Informe o nome do %i. aluno: ", i+1);
        scanf("%s",&Alunos[i].Nome);
        
        printf("Informe a idade de %s: ", Alunos[i].Nome);
        scanf("%i",&Alunos[i].Idade);

        printf("Informe o sexo de %s (M - Mulher, H - Homem): ", Alunos[i].Nome);
        scanf("%s",&Alunos[i].Sexo);
        
        if(Alunos[i].Sexo =='F' || Akunos[i].Sexo == 'f') {
        	
		}

        printf("\n");

	//Informação das notas dos alunos
        for(int j = 0; j<qtdProvas; j++){ 
            printf("Informe a nota %i: ", j+1);
            scanf("%f",&Alunos[i].Notas[j]);
            
            //Soma das notas
            somaNotas += Alunos[i].Notas[j]; 
            
        }
        
        //Calculo da média 
        media = somaNotas/qtdProvas;
        
        //Verificação da situação do aluno
        Alunos[i].Aprovado = media >= mediaAprovacao;
        
        printf("\n Quantidade de alunos cadastrados na turma %d", QtdAlunos);
        printf("Media do Aluno %s: %0.2f", Alunos[i].Nome, media);
        printf("\n Situacao do aluno: %d", Alunos[i].Aprovado);
    }
    

    return 0;
}
