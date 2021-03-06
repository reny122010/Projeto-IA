/**
 * @Busca_A_estrela.c
 * @Autor Angelina Sales
 * @Autor Renê Alves
 * @Autor Luana Reis
 * @date 26 outubro 2015
 * @Sobre: Implementação por meio de busca
 */


#include <stdio.h> //C I/O
#include <stdlib.h>
#include <string.h> 

#define TAMANHO_DA_PALAVRA 100
#define POSICAO_INICIAL 0

 void erroArgs(){
 	printf("./Busca_A_estrela.c [nome_da_tabela.txt] [quantidade_de_locais]\n");
 }

 teste(void * teste){
 	printf("%s\n", (char *) teste);
 }

 int main(int argc, char** argv){
 	char * nome_arquivo;
 	FILE * arquivo;

 	if(argc != 3){
 		erroArgs();
 		return 0;
 	}
 	int quantidade_de_locais = atoi(argv[2]);
 	char nomes_dos_locais[quantidade_de_locais][TAMANHO_DA_PALAVRA];
 	int mapa[quantidade_de_locais][quantidade_de_locais];
 	int valores[quantidade_de_locais-1];

 	int n_origem, n_destino;

 	nome_arquivo = argv[1];
 	arquivo = fopen(nome_arquivo, "r");

 	if(arquivo == NULL){
 		printf("Arquivo não encontrado, por favor, forceça a tabela de entrada do algoritimo!\n");
 		return -1;
 	}

 	printf("Preparando Tabela!\n");
 	int i = 0, array_i = -1, array_j = 0, cont_valores = 0, tabela_finalizada = 0, cont_distancia = 0; 
 	char axuliar[TAMANHO_DA_PALAVRA];
 	while(!feof(arquivo)){
 		
 		fscanf(arquivo,"%s",axuliar);

 		if(quantidade_de_locais > i && array_i == -1){
 			strcpy(&nomes_dos_locais[i][POSICAO_INICIAL], axuliar);
 			printf("%s\n",&nomes_dos_locais[i][POSICAO_INICIAL]);
 			i++;
 			
 		}
 		if(array_i != -1 && cont_valores < quantidade_de_locais*quantidade_de_locais){
 			cont_valores++;

 			mapa[array_i][array_j] = atoi(axuliar); 			
 			printf("%d ", mapa[array_i][array_j]);
 			if(++array_i == quantidade_de_locais){ 
 				printf("\n");
 				array_i = 0;
 				array_j++;
 			} 		
 		}
 		if(quantidade_de_locais == i && array_i == -1){
			array_i++;
		}

		if(tabela_finalizada){
			valores[cont_distancia] = atoi(axuliar);
			printf("%d\n", valores[cont_distancia]);
			if(++cont_distancia == quantidade_de_locais-1){
				break;
			}
		}

		if(cont_valores == quantidade_de_locais*quantidade_de_locais){
			tabela_finalizada = 1;
		}
 	}

 	printf("Decidindo origem e destino\n"); 	

 	fscanf(arquivo,"%s",axuliar);
 	char nome_origem[TAMANHO_DA_PALAVRA];
 	strcpy(nome_origem, axuliar);

 	fscanf(arquivo,"%s",axuliar);
 	char nome_destino[TAMANHO_DA_PALAVRA];
 	strcpy(nome_destino, axuliar);

 	int aux = 0;
 	while(quantidade_de_locais > aux){
 		if(!strcmp(nome_origem,&nomes_dos_locais[aux][POSICAO_INICIAL])){
 			n_origem = aux;
 			break;
 		}
 		aux++;
 		if(aux == quantidade_de_locais){
 			printf("Não foi encontrado o local de origem!\n");
 			return -1;
 		}
 	}

 	aux = 0;

 	while(quantidade_de_locais > aux){
 		if(!strcmp(nome_destino,&nomes_dos_locais[aux][POSICAO_INICIAL])){
 			n_destino = aux;
 			break;
 		}
 		aux++;
 		if(aux == quantidade_de_locais){
 			printf("Não foi encontrado o local de destino!\n");
 			return -1;
 		}
 	}
 	printf("Começando a busca A*\n");

 	int posicao_origem = -1;
 	aux = 0;

 	while(aux < quantidade_de_locais){
 		if(!strcmp(&nomes_dos_locais[aux][POSICAO_INICIAL], nome_origem)){
 			posicao_origem = aux;
 			break;
 		}
 		aux++;
 	}
 	int proxima_origem = -1, menor_distacia = 0;

 	while(1){
 		aux = 0;
 		menor_distacia = 0;

 		printf("Estamos em: %s\n", &nomes_dos_locais[posicao_origem][POSICAO_INICIAL]);
 		printf("Os próximos locais são:\n");
 		while(aux < quantidade_de_locais){
 			if(mapa[posicao_origem][aux] > 0){

	 			if(valores[aux] < menor_distacia || menor_distacia == 0){
	 				menor_distacia = valores[aux];
	 				proxima_origem = aux;	 					 				
	 			}
	 			printf("%s\t", &nomes_dos_locais[aux][POSICAO_INICIAL]);			
	 		}
	 		aux++;
 		}
 		aux = 0;
 		while(aux < quantidade_de_locais){
 			mapa[posicao_origem][aux] = 0;
 			mapa[aux][posicao_origem] = 0;
 			aux++;
 		} 		
 		
 		printf("\nEscolhendo o destino mais próximo!\n");

 		posicao_origem = proxima_origem;
 		printf("Destino selecionado: %s\n", &nomes_dos_locais[proxima_origem][POSICAO_INICIAL]);

 		if(!strcmp(&nomes_dos_locais[posicao_origem][POSICAO_INICIAL],nome_destino)){
 			printf("\nChegou à: %s \n", &nomes_dos_locais[posicao_origem][POSICAO_INICIAL]);
 			return 1;
 		}
 		if(menor_distacia == 0){
 			printf("\nNão existe forma de chegar ao seu destino\n");
 			return -2;
 		}
 		printf("\n");

 	}

 	return 1; 	
 }