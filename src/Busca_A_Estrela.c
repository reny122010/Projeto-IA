/**
 * @Busca_A_estrela.c
 * @Autor Angelina Sales
 * @Autor Renê Alves
 * @Autor Luana Reis
 * @date 26 outubro 2015
 * @Sobre: Implementação por meio de busca
 */


 #include <stdio.h> //C I/O

 void erroArgs(){
 	printf("./Busca_A_estrela.c [nome_da_tabela.txt]\n");
 }

 int main(int argc, char** argv){
 	char * nome_arquivo;
 	FILE * arquivo;

 	if(argc != 2){
 		erroArgs();
 		return 0;
 	}
 	
 	nome_arquivo = argv[1];

 	arquivo = fopen(nome_arquivo, "r");

 	if(arquivo == NULL){
 		printf("Arquivo não encontrado, por favor, forceça a tabela de entrada do algoritimo!\n");
 		return -1;
 	}

 	return 1; 	
 }