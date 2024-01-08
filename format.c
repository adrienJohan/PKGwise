#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

///	AFFICHAGE D'ACCUEIL
void begin(){
	printf("\n\n\t\t\t\t\e[48;2;140;140;140m\t                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[48;2;140;140;140m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[1;5;48;2;140;140;140m         G E S T I O N N A I R E    D E    P A Q U E T S        \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;140;140;140m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[48;2;140;140;140m                                                                \e[0m\n");
		
	printf("\n\n\t\t\t\t\t\e[48;2;130;60;60m\t                                         \e[0m\n");
	printf("\t\t\t\t\t\t\e[1;48;2;130;60;60m              1.POURSUIVRE               \e[0m\n");
	printf("\t\t\t\t\t\e[48;2;130;60;60m\t                                         \e[0m\n\n");

	printf("\t\t\t\t\t\e[48;2;120;60;60m\t                                         \e[0m\n");
	printf("\t\t\t\t\t\t\e[1;48;2;120;60;60m                 2.AIDE                  \e[0m\n");
	printf("\t\t\t\t\t\e[48;2;120;60;60m\t                                         \e[0m\n\n");

	printf("\t\t\t\t\t\t\e[48;2;110;60;60m                                         \e[0m\n");
	printf("\t\t\t\t\t\t\e[1;48;2;110;60;60m                3.QUITTER                \e[0m\n");
	printf("\t\t\t\t\t\e[48;2;110;60;60m\t                                         \e[0m\n\n");

}
/// À PROPOS DU PROGRAMME
void descriptionPack (){
	printf("\t\t\t\t\t\e[48;2;120;60;60m\t                               \e[0m\n");
	printf("\t\t\t\t\t\t\e[1;5;48;2;120;60;60m             AIDE              \e[0m\n");
	printf("\t\t\t\t\t\e[48;2;120;60;60m\t                               \e[0m\n\n");

	printf("\n\n\t\e[3mCe programme consistitue un gestionnaire de paquets. Les deux différentes systèmes de package vous facilite la manipulation d'un paquet selon votre distribution.\n");
	printf("Vous pouvez \e[1;38;2;255;100;150minstaller\e[0m, \e[1;38;2;255;100;150msupprimer\e[0m, \e[1;3;38;2;255;100;150mréparer\e[0m, \e[1;3;38;2;255;100;150mmettre à jour\e[0m \e[3mvotre paquet.\n\n");
	printf("\n\e[3;4mMode d'utilisation \e[0m: \n\n\t. Suivre les instructions disponibles au cours de l'emploi du programme\n\t. Des choix seront proposés pour que vous y naviguer sûrement\e[0m\n\n");
	printf("\e[3;31mPar rapport aux choix, il vous suffit d'entrer le chiffre correspondant aux proposition.\e[0m\n\n\n");
}

/// PROPOSITION DE TRAITEMENT D'UN PAQUET
void optionNavigue(){

	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;130;150;255m                      1 .  Listes  paquets                      \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;130;150;255m                      2  .  Installation                        \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;130;150;255m                      3  .  Réparation                          \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;130;150;255m                      4  .  Suppression                         \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;130;150;255m                      5  .  Recherche                           \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;130;150;255m                      6  .  À propos d'un paquet                \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[0m  \e[0m\e[48;2;40;140;150m                           \e[0m\t");printf(" \e[48;2;40;140;150m                             \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;40;140;150m        r . R E T O U R      \e[0m\t");printf(" \e[3;48;2;40;140;150m      q . Q U I T T E R        \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[0m  \e[0m\e[48;2;40;140;150m                           \e[0m\t");printf(" \e[48;2;40;140;150m                             \e[0m\n\n");

}
/// APT
void APT(){
	printf("\n\n\t\t\t\t\t\e[0m  \e[0m\e[48;2;40;140;150m                                                            \e[0m\n");
	printf("\t\t\t\t\t\e[48;2;40;140;150m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[1;5;48;2;40;140;150m                              A P T                             \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;40;140;150m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[0m  \e[0m\e[48;2;40;140;150m                                                            \e[0m\n\n");
}
/// YUM
void YUM(){
	printf("\n\n\t\t\t\t\t\e[0m  \e[0m\e[48;2;40;140;150m                                                            \e[0m\n");
	printf("\t\t\t\t\t\e[48;2;40;140;150m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[1;5;48;2;40;140;150m                              Y U M                             \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;40;140;150m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[0m  \e[0m\e[48;2;40;140;150m                                                            \e[0m\n\n");
}
/// SYSTÈME APT
void aptVisual(){
	system("clear");
	APT();
	optionNavigue();
}
/// SYSTÈME YUM
void yumVisual(){
	system("clear");
	YUM();
	optionNavigue();
}
///	VISUEL DANS DÉPOTS
void depotVisual(){
	printf("\t\t\t\t\t\e[48;2;140;140;140m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;140;140;140m                          L I S T E S                           \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;140;140;140m                                                                \e[0m\n\n");
	
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;130;150;255m          1 . Lister les paquets disponibles dans le dépots     \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;130;150;255m                2 . Lister les paquets installés                \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[0m  \e[0m\e[48;2;40;140;150m                           \e[0m\t");printf(" \e[48;2;40;140;150m                             \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;40;140;150m       r . R E T O U R       \e[0m\t");printf(" \e[3;48;2;40;140;150m      q . Q U I T T E R        \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[0m  \e[0m\e[48;2;40;140;150m                           \e[0m\t");printf(" \e[48;2;40;140;150m                             \e[0m\n\n");

}
///	VISUEL INSTALLATION
void installVisual(){
	printf("\t\t\t\t\t\e[48;2;140;140;140m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;140;140;140m                    I N S T A L L A T I O N                     \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;140;140;140m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;130;150;255m                 1 . Installation d'un paquet                   \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;130;150;255m                  2 . Mise à jour d'un paquet                   \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[0m  \e[0m\e[48;2;40;140;150m                           \e[0m\t");printf(" \e[48;2;40;140;150m                             \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;40;140;150m       r . R E T O U R       \e[0m\t");printf(" \e[3;48;2;40;140;150m      q . Q U I T T E R        \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[0m  \e[0m\e[48;2;40;140;150m                           \e[0m\t");printf(" \e[48;2;40;140;150m                             \e[0m\n\n");

}
///	VISUEL SUPPRESSION APT
void suppressAptVisual(){
	printf("\t\t\t\t\t\e[48;2;140;140;140m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;140;140;140m                      S U P P R E S S I O N                     \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;140;140;140m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;130;150;255m                   1 . Supprimer un paquet                      \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;130;150;255m           2 . Désinstallation des paquets inutiles             \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[0m  \e[0m\e[48;2;40;140;150m                           \e[0m\t");printf(" \e[48;2;40;140;150m                             \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;40;140;150m       r . R E T O U R       \e[0m\t");printf(" \e[3;48;2;40;140;150m      q . Q U I T T E R        \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[0m  \e[0m\e[48;2;40;140;150m                           \e[0m\t");printf(" \e[48;2;40;140;150m                             \e[0m\n\n");

}
///	VISUEL SUPPRESSION YUM
void suppressYumVisual(){
	printf("\t\t\t\t\t\e[48;2;140;140;140m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;140;140;140m                      S U P P R E S S I O N                     \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;140;140;140m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;130;150;255m                   1 . Supprimer un paquet                      \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;130;150;255m    2 . Désinstallation des paquets et dépendances inutiles     \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n\n");
	
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;130;150;255m                     3 . Downgrade d'un paquet                  \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n\n");
	
	printf("\t\t\t\t\t\e[0m  \e[0m\e[48;2;40;140;150m                           \e[0m\t");printf(" \e[48;2;40;140;150m                             \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;40;140;150m       r . R E T O U R       \e[0m\t");printf(" \e[3;48;2;40;140;150m      q . Q U I T T E R        \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[0m  \e[0m\e[48;2;40;140;150m                           \e[0m\t");printf(" \e[48;2;40;140;150m                             \e[0m\n\n");
}
/// VISUEL DESCRIPTION
void descriVisual(){
	printf("\t\t\t\t\t\e[48;2;140;140;140m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;140;140;140m                      D E S C R I P T I O N                     \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;140;140;140m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;130;150;255m          1 . Visualiser les descriptions d'un paquets          \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[48;2;130;150;255m                                                                \e[0m\n\n");

	printf("\t\t\t\t\t\e[0m  \e[0m\e[48;2;40;140;150m                           \e[0m\t");printf(" \e[48;2;40;140;150m                             \e[0m\n");
	printf("\t\t\t\t\t\e[3;48;2;40;140;150m       r . R E T O U R       \e[0m\t");printf(" \e[3;48;2;40;140;150m      q . Q U I T T E R        \t\t\e[0m\n");
	printf("\t\t\t\t\t\e[0m  \e[0m\e[48;2;40;140;150m                           \e[0m\t");printf(" \e[48;2;40;140;150m                             \e[0m\n\n");

}
/// AFFICHAGE DE SORTIE DU PROGRAMME
void fin(){
	system("clear");
	char end[10]="AU REVOIR";

		printf("\n\n\t\t");
		for (int i = 0; end[i]!='\0' ; ++i){
			printf("\e[3;48;2;140;140;140m %c ",end[i]);
			usleep(200000);
			fflush(stdout);	
		}
		printf("\e[0m\n\n");
		sleep(2);
		fflush(stdout);	
		system("clear");
		system("rm exemple.txt texte");
		exit(0);
}
/// Affichage lorsque la réponse est incorrecte aux propositions
void reAsk(){
	printf("\n\n\t\e[31m Ce choix ne figure pas dans la liste. Prenez soin de choisir une option valable.\n\e[0m");
	printf("\t\e[3mVeuillez entrer votre choix : \e[0m");
}
/// Affichage pour entrer un choix
void choice(){
	printf("\n\n\t\e[1;4mEntrer votre choix\e[0m : ");
}
///	COMMENCEMENT DU NOM D'UN PAQUET
void packBegin(){
	printf("\n\n\t\e[1;4mVotre paquet commence par :\e[0m ");
}
/// NOM DU PAQUET
void packName(){
	printf("\t\e[1;4mEntrer le nom du paquet :\e[0m ");
}
/// REMARQUE POUR LE FONCTIONNEMENT DU LISTAGE
void warn(){
	printf("\n\t\e[1;5;31mR E M A R Q U E\e[0m\n");
	printf("\t\e[3mIl vous faut maintenir la touche entrée pour faire defiler la liste\nle nom des paquets sont listés avant chaque antislash\e[0m\nAppuyez sur \e[1;5;31mq\e[0m pour \e[1mQUITTER\e[0m\n");		
}
/// RETOUR ET QUITTER 
void backQuit(char* variable){
	printf("\n\t\e[3;48;2;40;140;150m       r . R E T O U R       \e[0m\t");printf(" \e[3;48;2;40;140;150m      q . Q U I T T E R        \t\t\e[0m\n");

	choice();
	fgets(variable,10,stdin);
	fgets(variable,10,stdin);
	
	while(strcmp(variable,"r\n")!=0 && strcmp(variable,"q\n")!=0){
		reAsk();
		fgets(variable,10,stdin);
	}
	if(strcmp(variable,"r\n")==0){
		system("clear");
		return;
	}
	else if(strcmp(variable,"q\n")==0){
		fin();
	}
}
void loading(){
	int i=0;
	char loading[4] = "...";
	for   (int j=0;j<5;j++){
		printf("\t\t\t\t\t\t\t\t\e[3;1;34mChargement %s\e[0m",loading);
		fflush(stdout);
		usleep(500000);
		loading[i] = ' ';
		i = (i+1)%3;
		loading[i]= '.';
		printf("\r");
		
	}
	system("clear");
	
}
void siVide() {
 
	 int compteur = 0;
	 FILE * file;
	 
	file = fopen("texte", "r");
	   /* parcours du fichier */
	 while(fgetc(file) != EOF){
		compteur ++; /* incrémentation du compteur */
	 }
	 if (compteur==0)
	 printf("\n\nAucun élément de ce type\n\n");
	 
	 /* fermeture du fichier */
	 fclose(file);
	 
}

void makeMaj(char* opt){
	for (int i = 0; i < strlen(opt); ++i){
		opt[i]=toupper(opt[i]);
	}
}
