/**************************************************************************************************************/
/*									Programme interactif									                  */
/*							Auteurs : Adrien, Iantso, Mirado, Peniala						                  */
/**************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "prototype.h"
#include "format.h"


int main (){
	char* choix = malloc(10);
	
	
	while(strcmp(choix, "3\n") != 0)
	{
		begin(); ///visuel options
		
		choice();
		fgets(choix,10,stdin);
		while(strcmp(choix,"1\n")!=0 && strcmp(choix,"2\n")!=0 && strcmp(choix,"3\n")!=0 ){	/// réponse différente des propositions
			reAsk();
			fgets(choix,10,stdin);
		}
		if (strcmp(choix,"1\n")==0){
			system("clear");

			int b=0;
			b=testSystem();
			
			printf("\e[1;3mRecherche de votre système de package\n\e[0m");
			loading();
			
			if(b==1){
				apt();
			}
			else if(b==2){
				yum();
			}
		}
		else if (strcmp(choix,"2\n")==0){
			system("clear");

			descriptionPack();		/// visuel des options
			
			char retour[20]="0";
			printf(" Entrer \e[1mR\e[0m pour \e[1mRETOUR\e[0m : ");
			fgets(retour,20,stdin);
			makeMaj(retour);

			while(strcmp(retour,"R\n")!=0){
				reAsk();
				fgets(retour,20,stdin);
				makeMaj(retour);
			}
			if (strcmp(retour,"R\n")==0){
				system("clear");
			}
		}
		else if (strcmp(choix,"3\n")==0){	
			system("clear");
			fin();		/// visuel des options
		}		
		
	}


	return 0;
}

