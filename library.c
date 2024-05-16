#include <stdio.h>
#include <stdio.h>
#include "library.h"
#include <string.h>

//***************************************//
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
//***************************************//

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
  //***************************************//

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
//***************************************//

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
//***************************************//

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
//***************************************//
  
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
//***************************************//

void *afficherAccount(User *user,int numcompte) {
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
//*****************************************//
