//Abaixo estamos carregando a biblioteca standard input output para
//Usarmos os comandos de entrada scanf e saida printf de dados do usuario
#include <stdio.h>

/*Escreva um programa que solicite ao usuario:
    nome
    sexo
    idade
    tres notas dos n alunos em uma turma
    
    Ao final apresente:
    1- Quantidade de alunos cadastrados na turma.....  OK
    2- A quantidade de alunos e alunas (%) aprovados/reprovados na turma..... OK 
    3- A media de idade dos alunos aprovados e reprovados..... OK
    4- Gerar relatorio de alunos
    5- Tornar configuravel:.... OK
    5.1- A media de aprovação;.... OK
    5.2- A quantidade de provas a serem realizadas pelo aluno..... OK
    6- Fazer tratamento de dados na entrada do usuario (notas, idade, media, sexo).... OK
    6.1- 0 < nota < 10..... OK
    6.2- 16 < idade  < 90..... OK
    6.3- 5 < media < 8..... OK
    6.4- sexo M/m/F/f...... OK
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
    int qtdAlunos=0, qtdAlunosM=0, qtdAlunasF=0, qtdAlunosReprovadosM=0, qtdAlunasReprovadasF=0, qtdAlunasAprovadasF=0, qtdAlunosAprovadosM=0, qtdTotalAprovados=0, qtdTotalReprovados=0, somaIdadesA=0, somaIdadesR=0;
    int qtdProvas;
    float mediaAprovacao, porcentagemAprovacaoF, porcentagemAprovacaoM, porcentagemReprovacaoF, porcentagemReprovacaoM, mediaIdadesA, mediaIdadesR;
    struct Aluno Alunos[100];
    float media;
    float somaNotas;
    
    
    printf("Informe a quantidade de alunos da turma: ");
    scanf("%i",&qtdAlunos);
    
    printf("Informe a quantidade de provas realizadas: ");
    scanf("%i", &qtdProvas);
    
    //Loop para tratar os dados de entrada em relação a media de aprovação
    do {
    printf("Informe a media de aprovacao: ");
    scanf("%f", &mediaAprovacao);
	} while(mediaAprovacao < 5 or mediaAprovacao > 8);
	
    // Informação do nome, idade e sexo dos alunos
    for(int i =0; i<qtdAlunos;i++){
    	media = 0;
    	somaNotas = 0;
    	
    	printf("\n");
    	
        printf("Informe o nome do %i. aluno: ", i+1);
        scanf("%s",&Alunos[i].Nome);
        
        //Loop para tratar a entrada de dados do usuario em relação a idade
        do {
         printf("Informe a idade de %s: ", Alunos[i].Nome);
         scanf("%i",&Alunos[i].Idade);
        } while(Alunos[i].Idade < 16 or Alunos[i].Idade > 90);
        
         //Loop para tratar a entrada de dados do usuario em relação ao sexo
        do {
         printf("Informe o sexo de %s (M - Masculino, F - Feminino): ", Alunos[i].Nome);
         scanf("%s",&Alunos[i].Sexo);
        } while(Alunos[i].Sexo != 'M' && Alunos[i].Sexo != 'm' && Alunos[i].Sexo != 'F' && Alunos[i].Sexo != 'f');
        
        printf("\n");

	    //Informação das notas dos alunos
        for(int j = 0; j<qtdProvas; j++){ 
        
         //Loop para tratar a entrada de dados do usuario em relação as notas
         do {
          printf("Informe a nota %i: ", j+1);
          scanf("%f",&Alunos[i].Notas[j]);
         } while(Alunos[i].Notas[j] < 0 or Alunos[i].Notas[j] > 10);
         
            //Soma das notas
            somaNotas += Alunos[i].Notas[j]; 
        }
        
        //Calculo da média 
        media = somaNotas/qtdProvas;
        
        //Verificação da situação do aluno
        Alunos[i].Aprovado = media >= mediaAprovacao;
        
        //verificação de quantos alunos e alunas foram aprovados/reprovados e a soma das idades deles
        if((Alunos[i].Sexo =='F' || Alunos[i].Sexo == 'f' )&& Alunos[i].Aprovado) {
        	qtdTotalAprovados++;
         	qtdAlunasF++;
         	qtdAlunasAprovadasF++;
         	somaIdadesA += Alunos[i].Idade;
		}
		else if ((Alunos[i].Sexo =='F' || Alunos[i].Sexo == 'f') && !Alunos[i].Aprovado) {
			qtdTotalReprovados++;
			qtdAlunasF++;
			qtdAlunasReprovadasF++;
			somaIdadesR += Alunos[i].Idade;
		}
		 else if ((Alunos[i].Sexo == 'M' || Alunos[i].Sexo == 'm') && Alunos[i].Aprovado) {
		 	qtdTotalAprovados++;
			qtdAlunosM++;
			qtdAlunosAprovadosM++;
			somaIdadesA += Alunos[i].Idade;
		}
		else if ((Alunos[i].Sexo == 'M' || Alunos[i].Sexo == 'm') && !Alunos[i].Aprovado) {
			qtdTotalReprovados++;
			qtdAlunosM++;
			qtdAlunosReprovadosM++;
			somaIdadesR += Alunos[i].Idade;
		}
		
        //Relatório sobre o aluno 
        printf("\n");
        printf("------RELATORIO DO ALUNO (%s) ------\n", Alunos[i].Nome);
        printf("Media do Aluno %s: %0.2f \n", Alunos[i].Nome, media);
    }
    
    //Calculo da porcetagem de alunos aprovados/reprovados
    if (qtdAlunosReprovadosM > 0) {
    	porcentagemReprovacaoM = (qtdAlunosReprovadosM * 100.0) / qtdAlunosM;
	} 
	if (qtdAlunasReprovadasF > 0) {
		porcentagemReprovacaoF = (qtdAlunasReprovadasF * 100.0) / qtdAlunasF;
	}
    if (qtdAlunosAprovadosM > 0) {
    	porcentagemAprovacaoM = (qtdAlunosAprovadosM * 100.0) / qtdAlunosM;
	}
    if (qtdAlunasAprovadasF > 0) {
	   porcentagemAprovacaoF = (qtdAlunasAprovadasF * 100.0) / qtdAlunasF;
	}
    
    //relatorio das porcentagens dos alunos 
    printf("\n");
    printf("---------------------RELATORIO DE DA TURMA--------------------- \n");
    printf("Quantidade de alunos cadastrados na turma: %d \n", qtdAlunos);
    printf("Quantidades de mulheres: %d \n", qtdAlunasF);
    printf("Quantidade de Homens: %d \n", qtdAlunosM);
    printf("Porcentagem de alunos homens reprovados: %0.2f%% \n", porcentagemReprovacaoM);
    printf("Porcentagem de alunas mulheres reprovados: %0.2f%% \n", porcentagemReprovacaoF);
    printf("Porcentagem de alunos homens aprovados: %0.2f%% \n", porcentagemAprovacaoM);
    printf("Porcentagem de alunas mulheres aprovadas: %0.2f%% \n", porcentagemAprovacaoF);
    
    //Media da idade de aprovacao/reprovacao dos alunos
    if(qtdTotalAprovados > 0 ){
	  mediaIdadesA = somaIdadesA / qtdTotalAprovados;
	  printf("\n");
	  printf("Media das idades dos alunos aprovados: %0.2f \n", mediaIdadesA);
	} else {
		printf("\n");
		printf("NAO TEM ALUNOS APROVADOS \n");
	}
	if (qtdTotalReprovados > 0) {
		mediaIdadesR = somaIdadesR / qtdTotalReprovados;
		printf("\n");
		printf("Media das idades dos alunos reprovados: %0.2f", mediaIdadesR);
	} else {
		printf("\n");
		printf("NAO TEM ALUNOS REPROVADOS \n");
	}

    return 0;
}
