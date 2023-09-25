#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */	
struct deadline {
    int jour;
    int mois;
    int annee;
};
	
typedef struct {
    int id;
    char titre[100];
    char description[100];
    struct deadline deadln;
    char statut[100];
} Task;

int id = 0;
int counter = 0;
Task tk[100];

void Ajouter() {
    printf("Votre id est: %i\n", tk[counter].id);
    printf("Entrez le titre : \n");
    scanf(" %s[^\n]", tk[counter].titre);
    printf("Entrez la description : \n");
    scanf(" %s[^\n]", tk[counter].description);
    printf("Entrez la deadline (jour/mois/annee) : \n");
    printf("Le jour : ");
    scanf("%i", &tk[counter].deadln.jour);
    printf("Le mois : ");
    scanf("%i", &tk[counter].deadln.mois);
    printf("L'annee : ");
    scanf("%i", &tk[counter].deadln.annee);
    printf("Entrez le statut en choisissant parmi les options suivantes : \n[a realise] \n[en cours de realise] \n[finalise] : \n");
    scanf(" %s[^\n]", tk[counter].statut);
    counter++;
}

void Ajouterplus() {
    int i, n;
    printf("Entrez le nombre de taches que vous voulez ajouter : \n");
    scanf("%i", &n);
    for (i = 0; i < n; i++) {
        printf("Votre id est: %i\n", tk[counter].id );
        printf("Entrez le titre : \n");
        scanf("%s", tk[counter].titre);
        printf("Entrez la description : \n");
        scanf("%s", tk[counter].description);
        printf("Entrez la deadline (jour/mois/annee) : \n");
        printf("Le jour : ");
        scanf("%i", &tk[counter].deadln.jour);
        printf("Le mois : ");
        scanf("%i", &tk[counter].deadln.mois);
        printf("L'annee : ");
        scanf("%i", &tk[counter].deadln.annee);
        printf("Entrez le statut en choisissant parmi les options suivantes : \n[realise] \n[en cours de realise] \n[finalise] : \n");
        scanf("%s", tk[counter].statut);
        counter++;
        tk[counter].id=counter;
    }
}

void Afficher() {
	int i;
    printf("===========================================\n");
    printf("Liste des taches :\n");

    if (counter == 0) {
        printf("Aucune tache a afficher.\n");
        return;
    }

    printf("===========================================\n");

    for ( i = 0; i < counter; i++) {
        printf("Tache %i :\n", i + 1);
        printf("Id : %d\n", tk[i].id);
        printf("Titre : %s\n", tk[i].titre);
        printf("Description : %s\n", tk[i].description);
        printf("Deadline : %i/%i/%i\n", tk[i].deadln.jour, tk[i].deadln.mois, tk[i].deadln.annee);
        printf("Statut : %s\n", tk[i].statut);
        printf("===========================================\n");
    }
}

void Modifier() {
    int id;
    printf("Entrez l'ID de la tache a modifier : ");
    scanf("%d", &id);

    if (id < 1 || id > counter) {
        printf("ID de tache invalide.\n");
        return;
    }

    char choixModif;
    printf("Que voulez-vous modifier ?\n");
    printf("[a] Modifier la description\n");
    printf("[b] Modifier le statut\n");
    printf("[c] Modifier la deadline\n");
    scanf(" %c", &choixModif);

    switch (choixModif) {
        case 'a':
            printf("Nouvelle description : ");
            scanf("%s", tk[id].description);
            printf("Description modifiee avec succes.\n");
            break;
        case 'b':
            printf("Nouveau statut : ");
            scanf("%s", tk[id].statut);
            printf("Statut modifie avec succes.\n");
            break;
        case 'c':
            printf("Nouvelle deadline (jour/mois/annee) : ");
            scanf("%i %i %i", &tk[id].deadln.jour, &tk[id].deadln.mois, &tk[id ].deadln.annee);
            printf("Deadline modifiee avec succes.\n");
            break;
        default:
            printf("Option invalide.\n");
            break;
    }
};
//function supprimer par id
void Supprimer() {
    int id,i;
//la verification de l'id si vailid 
    printf("Entrez l'ID de la tache a supprimer : ");
    scanf("%d", &id);
    if (id < 1 || id > counter) {
        printf("ID de tache invalide.\n");
        return;
    }
    //la supprission de taske 
    for ( i = id - 1; i < counter - 1; i++) {
        tk[i] = tk[i + 1];
    }
    counter--;
    printf("Tache supprimee avec succes.\n");
}
//la function rechercher
void Rechercher() {
    int choixRch;
    printf("Choisissez ce que vous  de recherche :\n");
    printf("[1] Rechercher par ID\n");
    printf("[2] Rechercher par Titre\n");
    scanf("%i", &choixRch);

    if (choixRch == 1) {
        // Rechercher par ID
        int idReche;
        printf("Entrez l'ID de la tache a rechercher : ");
        scanf("%i", &idReche);
        printf("Resultats de la recherche par ID (%d) :\n", idReche);
        int i;
        for ( i = 0; i < counter; i++) {
            if (tk[i].id == idReche) {
                printf("Tache %i :\n", tk[i].id);
                printf("Titre : %s\n", tk[i].titre);
                printf("Description : %s\n", tk[i].description);
                printf("Deadline : %i/%i/%i\n", tk[i].deadln.jour, tk[i].deadln.mois, tk[i].deadln.annee);
                printf("Statut : %s\n", tk[i].statut);
                printf("===========================================\n");
                return; // Stop Rechercher apres trouver le meme 
            }
        }

        printf("Aucune tache correspondante trouvee.\n");
    } else if (choixRch == 2) {
        // Rechercher par Titre
        char mottitre[100];
        int found = 0;
        printf("Entrez un mot du titre a rechercher : ");
        scanf("%s", mottitre);
        printf("Resultats de la recherche par Titre ('%s') :\n", mottitre);
        int i;
        for ( i = 0; i < counter; i++) {
            if (strstr(tk[i].titre, mottitre) != NULL) {
                printf("Tache %i:\n", tk[i].id);
                printf("Titre : %s\n", tk[i].titre);
                printf("Description : %s\n", tk[i].description);
                printf("Deadline : %i/%i/%i\n", tk[i].deadln.jour, tk[i].deadln.mois, tk[i].deadln.annee);
                printf("Statut : %s\n", tk[i].statut);
                printf("===========================================\n");
                found = 1;
            }
        }
        if (!found) {
            printf("Aucune tache correspondante trouvee.\n");
        }
    } else {
        printf("Option de recherche invalide.\n");
    }
};
void Statistiques() {
	int i;
    int Count = 0;
    int notCount = 0;

    // Parcourir les tâches pour compter les statuts
    for (i = 0; i < counter; i++) {
        if (strcmp(tk[i].statut, "finalise") == 0) {
            Count++;
        } else {
            notCount++;
        }
    }
    // Afficher les statistiques
    printf("Nombre de taches completes: %d\n", Count);
    printf("Nombre de taches incompletes: %d\n", notCount);
    printf("Nombre total de taches: %d\n", counter);
}
int main() {
    int choix;

    printf("===========================================\n");
    printf("\t\tMenu Gestion de Taches ToDo\n");
    printf("===========================================\n");

    do {
        printf("===========================================\n");
        printf("[1] Ajouter une tache\n");
        printf("[2] Ajouter plusieurs taches\n");
        printf("[3] Afficher les taches\n");
        printf("[4] Modifier une tache\n");
        printf("[5] Supprimer une tache\n");
        printf("[6] Rechercher\n");
        printf("[7] Statistiques\n");
        printf("[8] Quitter\n");
        printf("===========================================\n");

        scanf("%d", &choix);

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
            	Supprimer();
                break;
            case 6:
                Rechercher();
                break;
            case 7:
               Statistiques();
                break;
            default:
                printf("Option invalide\n");
                break;
        }
	}while(1);
	return 0;
}
