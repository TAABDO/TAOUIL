#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

 int count = 0;
 
 typedef struct{
	    int id;
	    char titre [100];
	    char description [100];
	    char date[11];
	    char statut [100];
    }Task;
     Task tk[100]; 
           // struct task ;
            
        void Ajouter(){
        	
		     //apre le client choisx nous fait un choix si le choix == a donc ajouter une fois sinon si le choix == b l'ajout dois affiche plusieur fois
		    	 printf("entre les info suivant:\n");
	             printf("Enter le Titre :\n");
	              scanf("%s",tk[count].titre);
	            printf("Enter le Description :\n");
	              scanf("%s",tk[count].description);
	            printf("Enter le Deadline (jour/mois/ans)");
	              scanf("%s",tk[count].date);
	            printf("Enter le Statut [* realise *,* en cours de realise *,* finalise *]:\n");
	              scanf("%s",tk[count].statut);
	              
	                         }
			void Ajouterplus() {
				int i;
				
				for(i=0;i<3;i++){
	            printf("Enter le Titre :\n");
	              scanf("%s",tk[i].titre);
	            printf("Enter le Description :\n");
	              scanf("%s",tk[i].description);
	            printf("Enter le Deadline (jour/mois/ans)");
	              scanf("%s",tk[i].date);
	            printf("Enter le Statut [* a realise *,* en cours de realise *,* finalise *]:\n");
	              scanf("%s",tk[i].statut);
	                         }
	};
	
void Afficher (){
	             int count;
	     for(count=0;count<3;count++){
	     	printf("le info que vous enter est :\n");
		printf("Id: %i \n",tk[count].id);
		printf("titre: %s\n",tk[count].titre);
		printf("description: %s\n",tk[count].description);
		printf("deadline: %s\n",tk[count].date);
		printf("statut: %s\n",tk[count].statut);	
		 }
	    
};

int main() {
	
	int choix;
	char choixAj,a,b;

	printf("=========================================== \n \t \t");
	
	printf("Menu Gestion de Taches ToDo \n");
	
	printf("=========================================== \n");
	do{
			printf("=========================================== \n ");

		printf("[1]Ajouter Une tache \n");
		printf("[2]Afficher \n");
		printf("[3]Modifier \n");
		printf("[4]Supprimer \n");
		printf("[5]Rechercher  \n");
		printf("[6]Statistiques \n");
	    scanf("%i",&choix);

		printf("=========================================== \n");

	switch (choix) {
		case 1:
		
	         
	         printf("[a]Ajouter Une tache \n");
		    printf("[b]Ajouter plusieur tache \n");
		     scanf("%c",&choixAj);
		     switch(choixAj){
		     	case 'a':
		     		Ajouter();
		     		break;
		     	case 'b':
		     			Ajouterplus();
		     			break;
			 }
		    
	    break;
	    
	    case 2:
	    	Afficher();
	    break;
	    
	}
	}while(choix!=3);
	return 0;
}
