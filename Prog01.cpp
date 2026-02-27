//abaixo estamos carregando a biblioteca standard input output para
//usarmos os comandos de entrada scanf e saida printf de dados do usuario
#include <stdio.h>

/*escreva um programa que solicite ao usuario:
    nome
    sexo
    idade
    tres notas
    dos n alunos em uma turma
    
    ao final apresente:
    1- quantidade de alunos cadastrados na turma
    2- a quantidade de alunos e alunas (%) aprovados/reprovados na turma
    3- a media de idade dos alunos aprovados e reprovados
    4- gerar relatorio de alunos
*/

struct Aluno {
    char Nome[30];
    char Sexo;
    int Idade;
    float Notas[3];
    bool Aprovado;
};

//a seguir temos a funcao princirpal
int main()
{
    int QtdAlunos;
    struct Aluno Alunos[100];
    
    printf("Informe a quantidade de alunos da turma: ");
    scanf("%i",&QtdAlunos);
    
    for(int i =0; i<QtdAlunos;i++){
    	printf("\n");
        printf("Informe o nome do %i. aluno: ", i+1);
        scanf("%s",&Alunos[i].Nome);
        
        printf("Informe a idade de %s: ", Alunos[i].Nome);
        scanf("%i",&Alunos[i].Idade);

        printf("Informe o sexo de %s: ", Alunos[i].Nome);
        scanf("%s",&Alunos[i].Sexo);

        printf("\n");

        for(int j = 0; j<3; j++){
            printf("Informe a nota %i: ", j+1);
            scanf("%f",&Alunos[i].Notas[j]);
        }
    }

    return 0;
}
