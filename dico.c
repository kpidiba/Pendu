#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
void vidercache(){
	int c;
	do {
		c=getchar();
	}while (c!='\n' && c!=EOF);
}

void motachercher(char *mot){
	//c'est la variable qui permet de choisir le mot
    int aleatoire;
	// i est utilise dans la boucle while
    int i=0;
	//r est le pointeur qui permet de verifier si on a pu lire tous les donnes de la sortie standard ou remplace \n par \0
    char *r=NULL;
	//choix de la valeur aleatoire
    srand(time(NULL));
	aleatoire=(rand()%(11))+1;

	FILE*fichier=NULL;

    fichier=fopen("liste.txt","r");
	if( fichier == NULL){
		printf("error de lecture du fichier");
		exit(0);
	}
	//permet de choisir le mot
	   for(i=0;i<aleatoire;i++){
		 if(fgets( mot , sizeof(mot) , fichier) == NULL){
			 printf("erreur lors de la recuperation");
			 exit(0);
	         r=strchr(mot,'\n');
		 //verifie si tout les caracteres ont ete lu
	         if(r == NULL){
		        vidercache();
	         }else {
			//remplace le caractere de fin de ligne par le cartere nul qui designe la fin de la chaine de caractere
	         *r='\0';
	         }
	    }
    }
	if (fclose(fichier) == EOF) {
		exit(0);
	}
	//fin du choix de mot
}
