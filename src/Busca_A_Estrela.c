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

 int main(int argc, char** argv){
 	char * nome_arquivo;
 	FILE * arquivo;

 	if(argc != 3){
 		erroArgs();
 		return 0;
 	}
 	int quantidade_de_locais = atoi(argv[2]);
 	char nomes_dos_locais[quantidade_de_locais][TAMANHO_DA_PALAVRA];
 	int valores_das_distancias[quantidade_de_locais][quantidade_de_locais];
 	int valores_da_cidade1_para_cidaden[quantidade_de_locais-1];

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
 			
 			valores_das_distancias[array_i][array_j] = atoi(axuliar); 			
 			printf("%d ", valores_das_distancias[array_i][array_j]);
 			if(++array_i == quantidade_de_locais){ 
 				printf("\n");
 				array_i = 0;
 				array_j++;
 			} 		}
 		if(quantidade_de_locais == i && array_i == -1){
			array_i++;
		}

		if(tabela_finalizada){
			valores_da_cidade1_para_cidaden[cont_distancia] = atoi(axuliar);
			printf("%d\n", valores_da_cidade1_para_cidaden[cont_distancia]);
			if(++cont_distancia == quantidade_de_locais-1){
				break;
			}
		}

		if(cont_valores == quantidade_de_locais*quantidade_de_locais){
			tabela_finalizada = 1;
		}
 	}

 	printf("Começando a busca A*\n");
 	

 	return 1; 	
 }