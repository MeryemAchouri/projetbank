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
typedef struct Admin Admin;
struct Admin {
 char name[20];
 char password[20];   
 Admin *suiv;
};
int num_compte = 1;
// les fonctions
User *ajouterAccount(User * user,char name[20],float solde);
void *modifyAccount(User * user,int numcompte);
void *deleteAcount(User *user,int numcompte);
void *afficherAccount(User *user,int numcompte);
void *affichageAdmin(User *user);
void *depotArgent(User *user,int numcompte);
void *retirerArgent(User *user,int numcompte);
void *transfererArgent(User *user,int numcompte1,int numcompte2);
// contenu des fonction
User* ajouterAccount(User *user, char name[20], float solde) {
    User *Nouvuser = malloc(sizeof(User));    
    strcpy(Nouvuser->name, name);
    Nouvuser->solde = solde;
     Nouvuser->numcompte = num_compte++;
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
        if(user->numcompte==numcompte){
          printf("modifier votre nom : ");
          getchar();
          fgets(name, sizeof(name), stdin); 
          strcpy(user->name, name);
        }
        else printf("aucun compte avec le numero %d \n",numcompte);
        user=user->suiv;
      }
      return user;
  }
 void *depotArgent(User *user, int numcompte) {
    float nouvsolde;
    printf("Combien d'argent voulez-vous deposer ? ");
    scanf("%f", &nouvsolde);
    while (user != NULL) {
        if (user->numcompte == numcompte) {
            user->solde = user->solde + nouvsolde;
            return user;
        }
        user = user->suiv;
    }
    printf("Compte avec numéro %d non trouve.\n", numcompte);
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
        printf("Compte avec numero %d non trouve.\n", numcompte);
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
        printf("Compte avec numéro %d non trouve.\n", numcompte2);
        return NULL;
    }
    user = user->suiv;
    

    printf("Transfert de %.2f DH du compte %d vers le compte %d effectue avec succes.\n", montant, numcompte1, numcompte2);
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

void *afficherAccount(User *user, int numcompte) {
    User *courant = user;
    bool compteTrouve = false;

    printf("Liste des comptes actuelle : \n \n");
    while (courant != NULL) {
        if (courant->numcompte == numcompte) {
            printf("Le nom est : %s \n", courant->name);
            printf("Numéro de compte : %d \n", courant->numcompte);
            printf("Votre solde est : %.2f \n", courant->solde);
            printf("*****************************\n");
            compteTrouve = true;
        }
        courant = courant->suiv;
    }

    if (!compteTrouve) {
        printf("Aucun compte trouve avec le numero : %d.\n", numcompte);
    }
}
void *affichageAdmin(User *user){
    while(user!=NULL){
    
    printf("votre nom est : %s \n",user->name);
   printf("votre numero de compte est : %d \n",user->numcompte);
      printf("votre solde actuelle est : %.2f DH \n",user->solde);
     printf("****************************\n");
    user=user->suiv;
  }  
}


int main() {
int choix,type,num,num1,num2;
char name[20];
float solde;
char nom[20];
char password[20];
    User *user;
    user=NULL; 
Admin admin1 = {"amin","12345",NULL};
 do {
        system("cls");
        printf("\n--- //// **Menu principal** //// ---\n");
        printf("1 - Espace client\n");
        printf("2 - Espace administrateur\n");
        printf("3 - Quitter\n");
        printf("Veuillez entrer votre choix : ");
        scanf("%d", &type);
     switch (type)
    {
        case 1:
        do{
        system("cls");
        
        printf("\n--- //// **Espace client** //// ---\n");
        printf("1 - Creer un compte\n");
        printf("2 - Modifier le compte\n");
        printf("3 - Deposer de l'argent sur votre compte \n");
        printf("4 - Retirer de l'argent du votre compte \n");
        printf("5 - transferer un montant vers un compte \n");
        printf("6 - Supprimer le compte \n");
        printf("7 - afficher votre compte \n");
        printf("8 - Revenir au menu principal\n");
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
              User *courant=user;
            while (courant->suiv!=NULL){
               courant=courant->suiv;
              }
               printf("votre numero de compte est : %d \n ",courant->numcompte);

                while(getchar() != '\n');
                  printf("Appuyez sur Entree pour revenir au menu...");
                  getchar();
                break;
            case 2:
         printf("saisir le numero du compte : \n");
           scanf("%d",&num);
                if (user != NULL) {
                     modifyAccount(user,num);
              while(getchar() != '\n');
                  printf("Appuyez sur Entree pour revenir au menu...");
                  getchar();
                }
                break;
                  case 3 :
                printf("saisir votre numero du compte : \n");
                scanf("%d",&num);
                  depotArgent(user,num);
                  while (getchar() != '\n');
                  printf("Appuyez sur Entree pour revenir au menu...");
                  getchar();
                break;
                 case 4 :
                printf("saisir votre numero du compte : \n");
                scanf("%d",&num);
                  retirerArgent(user,num);
                  while (getchar() != '\n');
                  printf("Appuyez sur Entree pour revenir au menu...");
                  getchar();
                break;
                 case 5 :
                printf("saisir votre numero du compte : \n");
                scanf("%d",&num1);
                 printf("saisir le numero du compte destinataire : \n");
                scanf("%d",&num2);
                  transfererArgent(user,num1,num2);
                  while (getchar() != '\n');
                  printf("Appuyez sur Entree pour revenir au menu...");
                  getchar();
                break;
                case 6 :
                printf("saisir votre numero du compte : \n");
                scanf("%d",&num);
                  deleteAcount(user,num);
                  while (getchar() != '\n');
                  printf("Appuyez sur Entree pour revenir au menu...");
                  getchar();
                
                
                break;
                 case 7 :
                printf("saisir votre numero du compte : \n");
                scanf("%d",&num);
               
                 afficherAccount(user,num);
                  while (getchar() != '\n');
                  printf("Appuyez sur Entree pour revenir au menu...");
                  getchar();
                
                
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                 while (getchar() != '\n');
                  printf("Appuyez sur Entree pour revenir au menu...");
                  getchar();
        }
        }while(choix!=8);
        break;
       case 2 :
     system("cls");
    printf("\n Saisir votre nom : ");
    getchar();
    fgets(nom, sizeof(nom), stdin); 
    nom[strcspn(nom, "\n")] = '\0'; 
    printf("Saisir votre mot de passe : ");
    fgets(password, sizeof(password), stdin); 
    password[strcspn(password, "\n")] = '\0';
    if (strcmp(admin1.name, nom) == 0 && strcmp(admin1.password, password) == 0) {
         do{
          system("cls");
        printf("\n--- //// **Espace administrateur** //// ---\n");
        printf("1 - Afficher la liste des comptes\n");
        printf("2 - Revenir au menu principal\n");
        printf("Veuillez entrer votre choix : ");
        scanf("%d", &choix);
        switch (choix){
        case 1 :
           affichageAdmin(user); 
             while (getchar() != '\n');
                  printf("Appuyez sur Entree pour revenir au menu...");
                  getchar();
           break;
             case 2:
                printf("Exiting...\n");
                break;
         default :
        printf("choix incorrecte");   
        }
         }while (choix!=2);
       
    } else {
        printf("Nom d'utilisateur ou mot de passe incorrect.");
        while (getchar() != '\n');
                  getchar();

    }
    break;
    case 3 :
    printf("exiting ...");
    break;
         default :
       printf("choix incorrect");
       while (getchar() != '\n');
                  getchar();
      
    }
    
    
 }while (type!=3);
         return 0;

 
}
  /*if (type == 1) {
    system("cls");
    printf("Saisir votre nom : ");
    getchar();
    fgets(nom, sizeof(nom), stdin); 
    nom[strcspn(nom, "\n")] = '\0'; 
    printf("Saisir votre mot de passe : ");
    fgets(password, sizeof(password), stdin); 
    password[strcspn(password, "\n")] = '\0';
    if (strcmp(admin1.name, nom) == 0 && strcmp(admin1.password, password) == 0) {
        printf("1 - Afficher la liste des comptes\n");
        printf("Saisir votre choix : ");
        scanf("%d", &choix);
        switch (choix){
        case 1 :
           affichageAdmin(user); 
           break;
         default :
        printf("choix incorrecte");   
        }
       
       
    } else {
        printf("Nom d'utilisateur ou mot de passe incorrect.\n");
    }
}


     */ 
    
   
