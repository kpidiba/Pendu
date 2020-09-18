#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dico.h"


int main(int argc,char *argv[]){
    //declaration des variables
	//
	//la chaine de caratere qui contient la reponse
	char mot[20];
    int  len;
	//variable qui contiendra la lettre entre par l' utilisateur
	char lettre;
    char k[3]; 
	//variable de recherche de /n
	 char*r=NULL;
    
	//connaitre le nombre de mots trouves
	 int nmot=0;
	//la chaine de caratere qui affiche les mots
	char* affiche;

	//compteur de boucle
	int i=0;
    int j=0;
    //compteur de tour
	 int c=10;
    
	//permet de choisir le mot
     motachercher(mot);
	//allouer de la memoire pour stocker les lettres entres
	 len=strlen(mot);
	 affiche=malloc(len*sizeof(char));
	 if(affiche==NULL){
		 printf("erreur");
		 exit(0);
	 }
     printf("la longueur est %d",len);
	 //initialisation de affiche avec *
	 for(j=0;j<len-1;j++){
		 *(affiche+j)='*';
	 }
	 //boucle principal
	 for(i=0;i<10;i++){
		 //boucle qui affiche les mots trouves ou non
		 printf(" mot secret : ");
		 for (j=0;j<len-1;j++){
		   printf("%c",*(affiche+j));
	     }

		 printf("\n");
		 //recoit la lettre
		 printf("Vous avez %d essaie(s)\n",10-i);
	     printf("Entrez la lettre majuscule: ");
	     lettre=fgetc(stdin);
	     if(lettre==EOF){
		     printf("erreur de getc");
	     }
	     //on envoie la lettre dans une chaine et on verifie si il y a pas de caractere de retour
	     snprintf(k, sizeof(k), "%c",lettre);
	     r=strchr(k,'\n');
		     vidercache();
		 //structure conditionnel verifiant si la lettre est en majuscule et la convertie sinon
		 if(!(isupper(lettre))){
             if (toupper(lettre)==0) {
				 printf("error lors de la conversion");
             }else {
             lettre=toupper(lettre);
             }
		 };
	   //verification et affichage des lettres
	   for(j=0;j<len;j++){
		   if(mot[j]==lettre){
			   *(affiche +j)=lettre;
			   ++nmot;
			   --i;
	       }
	   }
	   //verification du resultat
	   if(nmot==len-1){
	    printf("\n");
	    printf("======Felicitaion====================\n");
		printf("le mot est: %s",mot);
		break;
	    }	   
	 }
	 printf("\n");
	 if(nmot!=len){
		 printf("Desole vous avez ete incapable de trouver le mot");
	 }
	 free(affiche);
   	return 0;
}
