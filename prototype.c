#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "format.h"
#include "prototype.h"


/*****************************************************************************************************************/
/*                                           RECHERCHE SYSYTEME DE PACKAGE                                       */
/*****************************************************************************************************************/
int testSystem(){
	system("find /usr/bin/apt|awk -F/ '{printf $4}' > exemple.txt");
	
	int test=0;
	
	FILE* file=fopen("exemple.txt","r");
	 char ess[80];
	fgets(ess,80,file);
	
	if(strcmp(ess,"apt")==0){
		test=1;
	}
	else{
		test=2;
	}
	fclose(file);
	return test;
}

/*******************************************************************************************************/
/*                                               FONCTION YUM                                          */
/*******************************************************************************************************/

void apt(){    ///fonction principale pour apt
	
	char a[10]="0";            // variable de choix

	while(strcmp(a,"r\n")!=0 && strcmp(a,"q\n")!=0){    
		
		aptVisual();
		
		choice();
		fgets(a,10,stdin);
		
		while(strcmp(a,"1\n")!=0 && strcmp(a,"2\n")!=0 && strcmp(a,"3\n")!=0 && strcmp(a,"4\n")!=0 && strcmp(a,"5\n")!=0 && strcmp(a,"6\n")!=0 && strcmp(a,"r\n")!=0 && strcmp(a,"q\n")!=0){  //le choix user ne figure pas dans la liste
			reAsk();                                                  //fonction pour demande de choix 
			fgets(a,10,stdin);	
		}
		
		system("clear");
		loading();
		if(strcmp(a,"1\n")==0){	depot();	}
		else if(strcmp(a,"2\n")==0){	install();	}
		else if(strcmp(a,"3\n")==0){	restore();	}
		else if(strcmp(a,"4\n")==0){	suppress();	}
		else if(strcmp(a,"5\n")==0){	recherche();	}
		else if(strcmp(a,"6\n")==0){	descri();	}
	}
	if(strcmp(a,"r\n")==0){
		system("clear");
		return ;
	}
	else if(strcmp(a,"q\n")==0){
		fin();
	}	
}

void depot(){                                          ///fonction apt pour voir des paquets disponibles ou installés                              
	char d[10]="0";
	char d1[10]="0";
	
	while(strcmp(d,"r\n")!=0 && strcmp(d,"q\n")!=0){
		char* begin =(char*)malloc(80*sizeof(char));
		system("clear");
		
		depotVisual();                              //visuel pour les possibilités sur depot
		
		choice();                               	//choix user
		fgets(d,10,stdin);
		while(strcmp(d,"1\n")!=0 && strcmp(d,"2\n")!=0 && strcmp(d,"r\n")!=0 && strcmp(d,"q\n")!=0){       //le choix user ne figure pas dans la liste
			reAsk();
			fgets(d,10,stdin);	
		}

		system("clear");
		
		if(strcmp(d,"1\n")==0){                    
			char* list = (char*)malloc(80*sizeof(char));
			strcpy(list,"apt list ");
			
			printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Liste des paquets dans votre dépôts  \e[0m\n\n");
			
			packBegin();
			scanf(" %s", begin);
			
			warn();             //remarque pour l'utilisation
			
			sleep(5);
			system(modeleDeux(list,begin));                         //executer cmd 
			
			strcat(modeleUn(list,begin)," > texte"); 
			system(modeleUn(list,begin));	
			siVide();

			backQuit(d1);
		}
		if(strcmp(d,"2\n")==0){
			char* listGot = (char*)malloc(80*sizeof(char));
			strcpy(listGot,"dpkg -l ");
			printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Liste des paquets installés  \e[0m\n\n");
			
			packBegin();
			scanf(" %s", begin);
			
			warn();            //remarque pour l'utilisation
			sleep(5);
			system(modeleTrois(listGot,begin));           //executer 
			
			strcat(modeleUn(listGot,begin)," > texte"); 
			system(modeleUn(listGot,begin));	
			siVide();

			backQuit(d1);
		}
	}
	
	if(strcmp(d,"r\n")==0){
		system("clear");
		return;
	}
	else if(strcmp(d,"q\n")==0){
		fin();               //fonction pour quitter le programme
	}	
}

void install(){                  ///fonction pour les installations diverses
	char e[20]="0";
	char e1[20]="0";
	char* paquet=malloc(40*sizeof(char));
	
	while(strcmp(e,"r\n")!=0 && strcmp(e,"q\n")!=0){   //boucle pour le choix de retour et quitter
		
		system("clear");
		
		installVisual();         //choix d'utilisation
		
		choice();
		fgets(e,10,stdin);	
		
		while(strcmp(e,"1\n")!=0 && strcmp(e,"2\n")!=0 && strcmp(e,"r\n")!=0 && strcmp(e,"q\n")!=0){  //cas de choix exterieur aux choix proposés
			reAsk();
			fgets(e,10,stdin);	
		}
		
		system("clear");

		if(strcmp(e,"1\n")==0){			/// installe paquet
			char* install=(char*)malloc(80*sizeof(char));
			strcpy(install,"sudo apt-get install ");
			printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Installation d'un paquet  \e[0m\n\n");
			
			packName();                //demande de nom de paquet
			scanf("%s",paquet);

			system(modeleUn(install,paquet));
			
			backQuit(e1);
		}
		else if(strcmp(e,"2\n")==0){		/// mise à jour d'un paquet
			char* update=(char*)malloc(80*sizeof(char));
			strcpy(update,"sudo apt-get install -V ");
			printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Mise à jour d'un paquet  \e[0m\n\n");
			packName();
			scanf("%s",paquet);

			system(modeleUn(update,paquet));
			
			backQuit(e1);
		}
	}
	if(strcmp(e,"r\n")==0){
		system("clear");
		return;
	}
	else if(strcmp(e,"q\n")==0){
		fin();
	}	
}

void restore(){                        ///fonction pour les réparations
	printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Réparation d'un paquet  \e[0m\n\n");

    char i[20]="0";
	char* paquet=malloc(40*sizeof(char));
	char* restore=(char*)malloc(80*sizeof(char));
	strcpy(restore,"sudo apt-get install -f ");
	packName();           //fonction demande de nom de paquet
	scanf("%s",paquet);

	system(modeleUn(restore,paquet));
	
	backQuit(i);
}

void suppress(){               ///fonction de suppression et plus
	char h[20]="0";
	char h1[20]="0";
	char* paquet=malloc(40*sizeof(char));

	while(strcmp(h,"r\n")!=0 && strcmp(h,"q\n")!=0){
		
		suppressAptVisual();   //visuel de choix 
		
		choice();         //demande de choix
		fgets(h,20,stdin);	
		
		while(strcmp(h,"1\n")!=0 && strcmp(h,"2\n")!=0 && strcmp(h,"r\n")!=0 && strcmp(h,"q\n")!=0){  //cas choix exterieur aux choix proposés
			reAsk();
			fgets(h,20,stdin);	
		}
		
		system("clear");
		
		if(strcmp(h,"1\n")==0){
			char j[20]="0";
			
			printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Suppression d'un paquet  \e[0m\n\n");  
			
			packName();     //demande du nom de paquet
			scanf("%s",paquet);
			
			printf("\nVoulez-vous supprimer :\n\e[1;3m1 . Avec ses dépendances\n2 . Sans ses dépendeces\nr . Retour\nq . Quitter\e[0m\n"); //choix
			choice();
			fgets(j,20,stdin);
			fgets(j,20,stdin);	
			
			while(strcmp(j,"1\n")!=0 && strcmp(j,"2\n")!=0 && strcmp(j,"r\n")!=0 && strcmp(j,"q\n")!=0){ //cas choix exterieur aux choix proposés
				reAsk();
				fgets(j,20,stdin);	
			}
			
			if(strcmp(j,"1\n")==0){
				char*depends=(char*)malloc(80*sizeof(char));
				strcpy(depends,"sudo apt-get autoremove ");
			
				system(modeleUn(depends,paquet));
				backQuit(h1);
			}
			else if(strcmp(j,"2\n")==0){
				char*noDepends=(char*)malloc(80*sizeof(char));
				strcpy(noDepends,"sudo apt-get remove ");
			
				system(modeleUn(noDepends,paquet));
				backQuit(h1);
			}
			else if(strcmp(j,"r\n")==0){
				system("clear");
			}
			else if(strcmp(j,"q\n")!=0){
				fin();
			}
		}
		else if(strcmp(h,"2\n")==0){
			char k[20]="0";
			printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Désinstallation les paquets inutiles  \e[0m\n\n");
			
			printf("\nVoulez-vous supprimer :\n\e[1;3m1 . les dépendances inutiles\n2 . tous les paquets dans /var/cache/apt/archives\n3 . dans /var/cache/apt/archives mais conserver les paquets qui ont un équivalent dans les dépôts\nr . Retour\nq . Quitter\e[0m\n");
			choice();
			fgets(k,20,stdin);
			//fgets(k,20,stdin);	
			
			while(strcmp(k,"1\n")!=0 && strcmp(k,"2\n")!=0 && strcmp(k,"3\n")!=0 && strcmp(k,"r\n")!=0 && strcmp(k,"q\n")!=0){
				reAsk();
				fgets(k,20,stdin);	
			}
			
			if(strcmp(k,"1\n")==0){
				char*purge=(char*)malloc(80*sizeof(char));
				strcpy(purge,"sudo apt-get autoremove --purge");
				
				system(purge);
				backQuit(h1);
			}
			else if(strcmp(k,"2\n")==0){
				char*clean=(char*)malloc(80*sizeof(char));
				strcpy(clean,"sudo apt-get clean");
				
				system(clean);
				backQuit(h1);
			}
			else if(strcmp(k,"3\n")==0){
				char*clean=(char*)malloc(80*sizeof(char));
				strcpy(clean,"sudo apt-get autoclean");
				
				system(clean);
			}
			else if(strcmp(k,"r\n")==0){
				system("clear");
			}
			else if(strcmp(k,"q\n")==0){
				fin();
			}
		}

		else if(strcmp(h,"r\n")==0){
			system("clear");
			return;
		}
		else if(strcmp(h,"q\n")==0){
			fin();
		}
	}	
}

void descri(){      ///fonction de description de paquet
	char g[20]="0";
	char g1[20]="0";

	while( strcmp(g,"r\n")!=0 && strcmp(g,"q\n")!=0){
		
		descriVisual();            //fonction visuel de description
		
		char* paquet=malloc(40*sizeof(char));
	
		choice();
		fgets(g,20,stdin);
		
		while(strcmp(g,"1\n")!=0 && strcmp(g,"r\n")!=0 && strcmp(g,"q\n")!=0){
			reAsk();
			fgets(g,20,stdin);	
		}

		system("clear");

		if (strcmp(g,"1\n")==0){
			char*descri=(char*)malloc(80*sizeof(char));
			strcpy(descri,"apt show ");
			printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Visualiser les descriptions  \e[0m\n\n");
			packName();
			scanf("%s",paquet);
			system(modeleUn(descri,paquet));
			
			backQuit(g1);
		}
	}
	if (strcmp(g,"r\n")==0){
		system("clear");
		return;
	}
	else if (strcmp(g,"q\n")==0){
		fin();            //fonction pour quitter le programme
	}
} 
void recherche(){                       ///fonction de recherche de paquet
	char* paquet=(char*)malloc(sizeof(char)*30);
	char h[20]="0";
	
	char*recherche=(char*)malloc(80*sizeof(char));
	strcpy(recherche,"apt-cache search -n ");	
	
	printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Rechercher un paquet  \e[0m\n\n");
		
	printf("\e[1;3mEntrez une initiale ou un semblable au paquet que vous recherchez :\e[0m ");   //l'user doit entrer un semblable du paquet
	scanf("%s",paquet);   
		
	system(modeleUn(recherche,paquet));
	
	system(strcat(modeleUn(recherche,paquet)," > texte")); 	
	siVide();
	
	backQuit(h);
}


/*******************************************************************************************************/
/*                                               FONCTION YUM                                          */
/*******************************************************************************************************/

void yum () {    ///fonction principale pour yum
	system("clear");
	char c[20]="0";      //variable de cchoix
	
	while(strcmp(c,"r\n")!=0 && strcmp(c,"q\n")!=0){          //boucle pour rester tant que user n'a pas choisi retour ou quitter
		system("clear");
		
		yumVisual();   //visuel d'affichage yum
		choice();
		fgets(c,20,stdin);

		while(strcmp(c,"1\n")!=0 && strcmp(c,"2\n")!=0 && strcmp(c,"3\n")!=0 && strcmp(c,"4\n")!=0 && strcmp(c,"5\n")!=0 && strcmp(c,"6\n")!=0 && strcmp(c,"r\n")!=0 && strcmp(c,"q\n")!=0){ //cas choix exterieur aux choix proposés
			reAsk();                 //redemander un choix 
			fgets(c,20,stdin);
		}
		
		system("clear");
		loading();
		if(strcmp(c,"1\n")==0){	yDepot();	}
		else if(strcmp(c,"2\n")==0){	yInstall();	}
		else if(strcmp(c,"3\n")==0){	repare();	}
		else if(strcmp(c,"4\n")==0){	ySuppress();	}
		else if(strcmp(c,"5\n")==0){	yRecherche();	}
		else if(strcmp(c,"6\n")==0){ about();}
	}
	if(strcmp(c,"r\n")==0){
		return;
	}
	else if(strcmp(c,"q\n")==0){
		fin();
	}	
}

void yDepot () {                ///fonction pour lister des paquets disponibles ou installés
	char d[20]= "0";
	char d1[5];
	char* begin =(char*)malloc(80*sizeof(char));

	while(strcmp(d,"r\n")!=0 && strcmp(d,"q\n")!=0){
		system("clear");
		YUM();
		depotVisual();                //visuel de depot
		
		choice();
		fgets(d,20,stdin);
		
		while(strcmp(d,"1\n")!=0 && strcmp(d,"2\n")!=0 && strcmp(d,"r\n")!=0 && strcmp(d,"q\n")!=0){       //cas choix exterieur aux choix proposés
			reAsk();
			fgets(d,20,stdin);
		}
		if(strcmp(d,"1\n")==0){		 //cas de choix 1
			char* list = (char*)malloc(80*sizeof(char));
			strcpy(list,"sudo yum list ");

			system("clear");
			printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Liste des paquets dans votre dépôts  \e[0m\n\n");    //liste des paquets disponibles 
		
			packBegin();                      //fonction d'entrée de mot pour faciliter l'utilisation 
			scanf(" %s", begin);    
			
			warn();    //remarques pour optimisation d'utilisation
			sleep(5);
			
			system(modeleDeux(list,begin));
			backQuit(d1);        //fonction pour les choix de retour ou quitter
		}

		if(strcmp(d,"2\n")==0){
			char* listGot = (char*)malloc(80*sizeof(char));
			strcpy(listGot,"yum list installed ");
			system("clear");
			printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Liste des paquets installés  \e[0m\n\n");
			packBegin();          //fonction pour demander par quoi pet commencer le paquet
			scanf(" %s", begin);
			
			warn();
			sleep(5);
			
			system(modeleDeux(listGot,begin));
			backQuit(d1);
		}
	}
	if(strcmp(d,"r\n")==0){
		return;
	}
	if(strcmp(d,"q\n")==0){
		
		fin();      //fonction pour quitter le programme
	}	
}

void yInstall() {           ///fonction pour les installations diverses
	char e[20] = "0";
	char e1[6];
	char* paquet = (char*)malloc(80*sizeof(char));
	while(strcmp(e,"r\n")!=0 && strcmp(e,"q\n")!=0){                //reiteration tant que les options retour et quitter ne sont pas choisis
		YUM();
		installVisual();
		
		choice();
		fgets(e,20,stdin);
		
		while(strcmp(e,"1\n")!=0 && strcmp(e,"2\n")!=0 && strcmp(e,"r\n")!=0 && strcmp(e,"q\n")!=0){        //cas choix exterieur aux choix proposés
			reAsk();
			fgets(e,20,stdin);
		}
		if(strcmp(e,"1\n")==0){    //cas d'installation de paquet
			char*install=(char*)malloc(80*sizeof(char));
			strcpy(install,"sudo yum install ");
			system("clear");
			printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Installation d'un paquet  \e[0m\n\n");
			
			packName();                  //demander le nom du paquet
			scanf("%s", paquet);
			system(modeleUn(install,paquet));
			
			backQuit(e1);         //fonction pour les choix retour ou quitter
		}
		
		if(strcmp(e,"2\n")==0){   //cas de mise à jour de paquet
			char*update=(char*)malloc(80*sizeof(char));
			strcpy(update,"sudo yum update ");
			system("clear");
			printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Mise à jour d'un paquet  \e[0m\n\n");
			
			packName();   //demander le nom du paquet
			scanf("%s", paquet);
			system(modeleUn(update,paquet));
			
			backQuit(e1);
		}
	}
	if(strcmp(e,"r\n")==0){
		return;
	}
	if(strcmp(e,"q\n")==0){
		fin();	
	}	
}

void repare() {           ///fonction pour les reparations de paquet
	char x[20] = "0";
	char x1[6];

	char* findDef= (char*)malloc(80*sizeof(char));
	char* paquet = (char*)malloc(80*sizeof(char));
	findDef = "sudo rpm -Va";           //commande pour voir les defaillances
	
	while(strcmp(x,"1\n")!=0 && strcmp(x,"2\n")!=0){
		YUM();
		printf("\e[1;3mVoici les defaillances des paquets:\e[0m\n");
		
		system(findDef);
		
		printf("\e[1;3mVoulez-vous réinstaller un paquet défaillant?\e[0m\t\e[1;31m1-OUI\t2-NON\e[0m\n");
		fgets(x,20,stdin);
		while(strcmp(x,"1\n")==0 && strcmp(x,"2\n")==0){     //cas choix exterieur aux choix proposés
			fgets(x,20,stdin);
		}
		if(strcmp(x,"1\n")==0){    //reinstaller les paquets defaillants
			char*repare=(char*)malloc(80*sizeof(char));
			strcpy(repare,"sudo dnf --refresh reinstall ");

			system("clear");
			printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Réinstallation d'un paquet  \e[0m\n\n");
			
			packName();
			scanf("%s", paquet);
			system(modeleUn(repare,paquet));

			backQuit(x1);
		}
		else if(strcmp(x,"2\n")==0){
			backQuit(x1);
		}
	}
}

void ySuppress () {     ///suppression ou autre sur un paquet
	char* paquet = (char*)malloc(80*sizeof(char));
	char y[20]= "0";
	char y1[6];

	while(strcmp(y,"r\n")!=0 && strcmp(y,"q\n")!=0){
		YUM();
		suppressYumVisual();    //visuel des choix de fonction suppression
		
		choice();
		fgets(y,20,stdin);
		while(strcmp(y,"1\n")!=0 && strcmp(y,"2\n")!=0 && strcmp(y,"3\n")!=0 && strcmp(y,"r\n")!=0 && strcmp(y,"q\n")!=0){    //cas choix exterieur aux choix proposés
			reAsk();
			fgets(y,20,stdin);
		}
		
		if(strcmp(y,"1\n")==0){     //cas suppression de paquet
			char*suppress =(char*)malloc(80*sizeof(char));
			strcpy(suppress, "sudo yum remove ");
			system("clear");
			printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Suppression d'un paquet  \e[0m\n\n");
			packName();
			scanf("%s", paquet);
			system(modeleUn(suppress,paquet));
			backQuit(y1);
		}
		if(strcmp(y,"2\n")==0){    //cas suppression de paquet et des dependances inutiles 
			char*noDepends=(char*)malloc(80*sizeof(char));
			strcpy(noDepends,"sudo yum autoremove ");
			system("clear");
			printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Désinstallation de paquet avec les dépendances inutiles  \e[0m\n\n");
			printf("Desinstallation de paquet et d'une dépendance inutile\n\n");
			packName();
			scanf("%s", paquet);
			
			system(modeleUn(noDepends,paquet));
			backQuit(y1);
		}
		if(strcmp(y,"3\n")==0){     //downgrade de paquet
			char*downgrade=(char*)malloc(80*sizeof(char));
			strcpy(downgrade,"sudo yum downgrade ");
			system("clear");
			printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Downgrade d'un paquet  \e[0m\n\n");
			packName();
			scanf("%s", paquet);
			system(modeleUn(downgrade,paquet));
			backQuit(y1);
		}
	}
	if(strcmp(y,"r\n")==0){
		return;
	}
	if(strcmp(y,"q\n")==0){
		fin();
	}
}

void about () {           ///a propos d'un paquet
	char* paquet = (char*)malloc(80*sizeof(char));
	char z[20] = "0";
	char z1[6];
	while(strcmp(z,"r\n")!=0 && strcmp(z,"q\n")!=0){       //reiteration tant que les options retour et quitter ne sont pas choisis
		YUM();
		descriVisual();    //visuel des options dans la fonction
		
		choice();
		fgets(z,20,stdin);
		while(strcmp(z,"1\n")!=0 && strcmp(z,"r\n")!=0 && strcmp(z,"q\n")!=0){      //cas choix exterieur aux choix proposés 
			reAsk();
			fgets(z,20,stdin);
		}
		if(strcmp(z,"1\n")==0){    //description de paquet
			char*about=(char*)malloc(80*sizeof(char));
			strcpy(about,"sudo yum info ");
			system("clear");
			printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Visualiser les descriptions  \e[0m\n\n");
			packName();
			scanf("%s", paquet);
			system(modeleUn(about,paquet));
			
			backQuit(z1);
		}
		else if(strcmp(z,"r\n")!=0){
			return;
		}
		else if(strcmp(z,"q\n")==0){
			fin();
		}
	}
} 
 
void yRecherche(){    ///fonction de recherche de paquet
	char* paquet=(char*)malloc(sizeof(char)*30);
	char h[20]="0";
	char*search=(char*)malloc(80*sizeof(char));
	strcpy(search,"sudo yum list ");
	YUM();
		
	printf("\n\t\t\t\t\t\t\e[3;5;48;2;40;140;150m  Rechercher un paquet  \e[0m\n\n");
		
	printf("\e[1;3m Entrez une initiale ou un semblable au paquet que vous recherchez :\e[0m \n");
	scanf("%s",paquet);
	warn();	
	system(modeleDeux(search,paquet));
		
	strcat(modeleDeux(search,paquet)," > texte");  //redirection de resultat de  cmd vers texte
	system(modeleDeux(search,paquet));	
	siVide();

	backQuit(h);
}

char* modeleUn(char*cmd,char*name){
	strcat(cmd,name);
	return cmd;
}

char* modeleDeux(char*cmd,char* initial){
	strcat(cmd,"|grep ^");
	strcat(cmd,initial);
	strcat(cmd," |more");
	return cmd;
}

char* modeleTrois(char *cmd, char* initial){
	strcat(cmd,"|grep ");
	strcat(cmd,"\"^ii  ");
	strcat(cmd, initial);
	strcat(cmd, "\"");
	strcat(cmd," |more");
	return cmd;
}
