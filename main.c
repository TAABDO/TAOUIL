#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

 
 // struct task ; 
 typedef struct{
	    int id;
	    char titre [100];
	    char description [100];
	    char date[11];
	    char statut [100];
    }Task;
    //declaration de table
            int count = 0;
           Task tk[100]; 
           
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
	              count++;
	                         };
			void Ajouterplus() {
				
				int i,n;
				printf("entere les nomber des tache:\n");
				scanf("%i",&n);
				
				for(i=0;i<n;i++){
	            printf("Enter le Titre :\n");
	              scanf("%s",tk[count].titre);
	            printf("Enter le Description :\n");
	              scanf("%s",tk[count].description);
	            printf("Enter le Deadline (jour/mois/ans)");
	              scanf("%s",tk[count].date);
	            printf("Enter le Statut [* a realise *,* en cours de realise *,* finalise *]:\n");
	              scanf("%s",tk[count].statut);
	               count++;
	                         }
	                        
	                  };
   void Afficher() {
                  int i;
                  printf("Les informations que vous avez entrées sont :\n");
              for ( i = 0; i < count; i++) {
                   printf("Tâche %d:\n", i + 1);
                   printf("Id: %d\n", tk[i].id); // Initialize or increment id when adding tasks
                   printf("Titre: %s\n", tk[i].titre);
                   printf("Description: %s\n", tk[i].description);
                   printf("Deadline: %s\n", tk[i].date);
                   printf("Statut: %s\n", tk[i].statut);
                   printf("\n");
    }
}

void Modifier(){
	char choixmod;
	printf("[a] Modifier la description d'une tâche");
	printf("[b] Modifier  le statut d’une tâche");
	printf("[c] Modifier le deadline d’une tâche");
	scanf("%c",&choixmod);
    switch(choixmod)
	{
		case 'a':
			
			break;
		case 'b':
			break;
		case 'c':
			break;
	}
	
	
};
//char Supprimer(char titre){
//	int pos;
//	pos=-1;
//	int i;
//	for (i=0;i<tk.count;i++){
//		if(strcmp(titre,tk[i].titre))
//		pos=1;
//	}
//	return pos;
//}

int main() {
	
	int choix ,n;
	char choixAj,a,b;

	printf("=========================================== \n \t \t");
	
	printf("Menu Gestion de Taches ToDo \n");
	
	printf("=========================================== \n");
	do{
			printf("=========================================== \n ");

		printf("[1]Ajouter Une tache \n");
		printf("[2]Ajouter Une tache \n");
		printf("[3]Afficher \n");
		printf("[4]Modifier \n");
		printf("[5]Supprimer \n");
		printf("[6]Rechercher  \n");
		printf("[7]Statistiques \n");
	    scanf("%i",&choix);

		printf("=========================================== \n");

	switch (choix) {
		case 1:
		     	Ajouter();
	        break;
	    
	    case 2:
	    	Ajouterplus();
	        break;
	    case 3:
	    	Afficher();
	    	break;
	    case 4:
	    	Modifier();
	    break;
	        case 5:
//	        Supprimer();
	    break;
	    
	}
	}while(choix!=3);
	return 0;
}
