#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
//les structures
typedef struct User User;
struct User {
char name[20];
int numcompte;
float solde;
User *suiv;
};
int numcompte = 1;
// les fonctions
//User *createAccount(User * user,char name[20],float solde);
User *ajouterAccount(User * user,char name[20],float solde);
void *modifyAccount(User * user,int numcompte);
void *deleteAcount(User *user,int numcompte);
void *afficherAccount(User *user);
void *depotArgent(User *user,int numcompte);
void *retirerArgent(User *user,int numcompte);
void *transfererArgent(User *user,int numcompte1,int numcompte2);
// contenu des fonction
User* ajouterAccount(User *user, char name[20], float solde) {
    User *Nouvuser = malloc(sizeof(User));    
    strcpy(Nouvuser->name, name);
    Nouvuser->solde = solde;
     Nouvuser->numcompte = numcompte++;
    Nouvuser->suiv = NULL;

    if (user == NULL) {
        return Nouvuser;
    }

    User *courant = user;
    while (courant->suiv != NULL) {
        courant = courant->suiv;
    }
    courant->suiv = Nouvuser;

    return user;
}

void *modifyAccount(User *user,int numcompte){
    char name[50];
      while (user!=NULL)
      {
        if(user->numcompte=numcompte){
          printf("modifier votre nom : ");
          getchar();
          fgets(name, sizeof(name), stdin); 
          strcpy(user->name, name);
        }
        user=user->suiv;
      }
      return user;
  }
 void *depotArgent(User *user, int numcompte) {
    float nouvsolde;
    printf("Combien d'argent voulez-vous déposer ? ");
    scanf("%f", &nouvsolde);
    while (user != NULL) {
        if (user->numcompte == numcompte) {
            user->solde = user->solde + nouvsolde;
            return user;
        }
        user = user->suiv;
    }
    printf("Compte avec numéro %d non trouvé.\n", numcompte);
    return NULL;
}
void *retirerArgent(User *user, int numcompte) {
    int accountFound=0;
    float nouvsolde;

    while (user != NULL) {
        if (user->numcompte == numcompte) {
            accountFound=1;
            while (1) {
               printf("Combien d'argent voulez-vous retirer ? ");
                scanf("%f", &nouvsolde); 
                if (nouvsolde <= user->solde) {
                    user->solde = user->solde - nouvsolde;
                    return user;
                } else {
                    printf("Le montant que vous essayez de retirer est superieur a votre solde. Veuillez reessayer : \n ");
                }
            }
        }
        user = user->suiv;
    }

  if (!accountFound) {
        printf("Compte avec numéro %d non trouvé.\n", numcompte);
    }    return NULL;


}

void *transfererArgent(User *user, int numcompte1, int numcompte2) {
    float montant = 0;
   

    if (user == NULL) {
        printf("Compte avec numero %d non trouve.\n", numcompte1);
        return NULL;
    }
     
    printf("Saisir le montant a transferer depuis le compte %d vers le compte %d : ", numcompte1, numcompte2);
    scanf("%f", &montant);
    
    if (montant >= user->solde) {
        printf("Le montant que vous essayez de transferer est superieur au solde du compte %d. Veuillez reessayer.\n", numcompte1);
        return NULL;
    }
       while (user != NULL) {
        if (user->numcompte == numcompte1) {
            user->solde -= montant;
            break;
        }
        user = user->suiv;
    }
    while (user != NULL) {
        if (user->numcompte == numcompte2) {
            user->solde += montant;
            break;
        }
        user = user->suiv;
    }

    if (user == NULL) {
        printf("Compte avec numéro %d non trouvé.\n", numcompte2);
        return NULL;
    }
    user = user->suiv;
    

    printf("Transfert de %.2f DH du compte %d vers le compte %d effectue avec succès.\n", montant, numcompte1, numcompte2);
}

  
 void *deleteAcount(User *user, int numcompte) {
    User *current = user;
    User *prev = NULL;
        while (current != NULL) {
        if (current->numcompte == numcompte) {
            if (prev == NULL) {
                user = current->suiv;
            } else {
                prev->suiv = current->suiv;
            }
            free(current);
            printf("le compte avec le numero %d supprime avec succes.\n", numcompte);
            return user;
        }
        prev = current;
        current = current->suiv;
    }
    printf("le compte avec le numero %d est introuvable.\n", numcompte);
    return user;
}

void *afficherAccount(User *user) {
    User *courant = user;

    printf("Liste des comptes actuelle : \n");
    if (user == NULL) {
        printf("Aucun compte cree.\n");
    } else {
        while (courant != NULL) {
            printf("Le nom est : %s \n", courant->name);
            printf("Numéro de compte : %d \n", courant->numcompte);
            printf("Votre solde est : %.2f \n", courant->solde);
            printf("*****************************\n");
            courant = courant->suiv;
        }
    }
}

int main() {
int choix;
int num;
int num1,num2;
char name[20];
float solde;
    User *user;
    user=NULL; 
     do {
        system("cls");
        printf("\n--- //// **gestion bancaire** //// ---\n");
        printf("1 - Creer un compte\n");
        printf("2 - Modifier le compte\n");
        printf("3 - Deposer de l'argent sur votre compte \n");
        printf("4 - Retirer de l'argent du votre compte \n");
        printf("5 - transferer un montant vers un compte \n");
        printf("6 - Supprimer le compte \n");
        printf("7 - afficher mes comptes \n");
        printf("8 - Exit\n");
        printf("Veuillez entrer votre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
             printf("saisir votre nom : ");
            getchar();
              fgets(name, sizeof(name), stdin); 
               printf("saisir votre solde initiale : ");
              scanf("%f",&solde);  
                user = ajouterAccount(user,name,solde);
                while(getchar() != '\n');
                  printf("Appuyez sur Entrée pour revenir au menu...");
                  getchar();
                break;
            case 2:
         printf("saisir le numero du compte : \n");
           scanf("%d",&num);
                if (user != NULL) {
                     modifyAccount(user,num);
            
                } else {
                    printf("Erreur : Aucun compte n'a été créé.\n");
                }
                break;
                  case 3 :
                printf("saisir votre numero du compte : \n");
                scanf("%d",&num);
                  depotArgent(user,num);
                  while (getchar() != '\n');
                  printf("Appuyez sur Entrée pour revenir au menu...");
                  getchar();
                break;
                 case 4 :
                printf("saisir votre numero du compte : \n");
                scanf("%d",&num);
                  retirerArgent(user,num);
                  while (getchar() != '\n');
                  printf("Appuyez sur Entrée pour revenir au menu...");
                  getchar();
                break;
                 case 5 :
                printf("saisir votre numero du compte : \n");
                scanf("%d",&num1);
                 printf("saisir le numero du compte destinataire : \n");
                scanf("%d",&num2);
                  transfererArgent(user,num1,num2);
                  while (getchar() != '\n');
                  printf("Appuyez sur Entrée pour revenir au menu...");
                  getchar();
                break;
                case 6 :
                printf("saisir votre numero du compte : \n");
                scanf("%d",&num);
                if (user != NULL) {
                  user =   deleteAcount(user,num);
                  while (getchar() != '\n');
                  printf("Appuyez sur Entrée pour revenir au menu...");
                  getchar();
                }
                
                break;
                 case 7 :
                if (user != NULL) {
                 afficherAccount(user);
                  while (getchar() != '\n');
                  printf("Appuyez sur Entrée pour revenir au menu...");
                  getchar();
                } 
                
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix!=8);
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