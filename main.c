#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
//les structures
typedef struct User User;
struct User {
char name[50];
int numcompte;
double solde;
User *suiv;
};
// les fonctions
User *createAccount();
User *modifyAccount(User *user);
User *deleteAcount(User *user);


// contenu des compte
User *createAccount(){

User *user=malloc(sizeof(*user));
    printf("saisir votre nom : ");
          getchar();
            fgets(user->name, sizeof(user->name), stdin); 
                user->numcompte++;
    printf("saisir votre solde initiale : ");
          scanf("%f",&(user->solde));  
    return user;
}
User *modifyAccount(User *user){
    int choix;
     
    printf("1 - modifiez votre nom : \n");
    printf("2 -modifiez votre solde : \n");
    printf("--------------------------------- \n");
    while (choix >2 || choix <1){
    scanf("%d",&choix);
     if(choix==1){
        printf("saisir votre nouveau nom : \n");
            getchar();
            fgets(user->name, sizeof(user->name), stdin);    }
    else if(choix==2){
      printf("saisir votre nouveau solde : ");
         scanf("%f",user->solde);    }
    }
   
    return user;
  }
  User *deleteAcount(User *user){
        user=NULL;
        printf("compte supprime avec succes");
    return user;
   
  }

int main() {
int choix;
    User *user = NULL; // Initialisez user à NULL
    
     do {
        printf("\n--- //// **gestion bancaire** //// ---\n");
        printf("1. Creer un compte\n");
        printf("2. Modifier le compte\n");
        printf("3 - Supprimer lee compte \n");
        printf("4 - ajouter");
        printf("4. Exit\n");
        printf("Veuillez entrer votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                user = createAccount();
                break;
            case 2:
                if (user != NULL) {
                    user = modifyAccount(user);
                } else {
                    printf("Erreur : Aucun compte n'a été créé.\n");
                }
                break;
                case 3 :
                if (user != NULL) {
                    user = deleteAcount(user);
                } 
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix!=3);
    {
        /* code */
    }
    

    // Libérer la mémoire allouée pour l'utilisateur avant de quitter le programme
    if (user != NULL) {
        free(user);
    }

    return 0;
}
 /*while(user!=NULL){
    printf("votre nom est : %s \n",user->name);
   printf("votre numero de compte est : %d \n",user->numcompte);
      printf("votre solde actuelle est : %f DH",user->solde);

    user=user->suiv;
  }
*/