#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char name[30];
	char course[20];
	int phase;
	float average;
}Aluno;


int main(int argc, char *argv[]) {
	int n,i;
	printf("Digite o tamanho do vetor: ");
	scanf("%d",&n);
	
	Aluno *v = malloc(sizeof(Aluno)*n);
	
	for(i = 0; i < n; i++){fflush(stdin);
		printf("Digite o nome : ");
		fgets(v[i].name,30,stdin);
		printf("Digite o curso : ");
		fgets(v[i].course,20,stdin);
		printf("Digite a fase do curso : ");
		scanf("%d",&v[i].phase);
		printf("Digite a média : ");
		scanf("%f",v[i].average);				
	} 
	
	for(i = 0; i < n; i++){fflush(stdin);
		if(v[i].average < 7){
			printf("%s Reprovado! \n", v[i].name);
		}
	}
	
	return 0;
}
