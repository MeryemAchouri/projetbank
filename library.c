#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "library.h"
#include <string.h>

void sauvegarderUtilisateurs(User *user) {
    FILE *fichier = fopen("users.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        exit(EXIT_FAILURE);
    }

    User *courant = user;
    while (courant != NULL) {
        fprintf(fichier, "%s %.2f %d\n", courant->name, courant->solde, courant->numcompte);
        courant = courant->suiv;
    }

    fclose(fichier);
}
//***************************************//
int getHighestAccountNumber() {
    FILE *f = fopen("listedescompte.txt", "r");
    int highestAccountNumber = 0;
    if (f != NULL) {
        int num;
        char line[100];
        while (fgets(line, sizeof(line), f)) {
            if (sscanf(line, "Numéro de compte : %d", &num) == 1) {
                if (num > highestAccountNumber) {
                    highestAccountNumber = num;
                }
            }
        }
        fclose(f);
    }
    return highestAccountNumber;
}

User *ajouterAccount(User *user, char name[20], float solde) {
    FILE *f;
    f = fopen("listedescompte.txt", "a");
    if (f == NULL) {
        printf("Impossible d'ouvrir le fichier");
        return user;
    }

    User *Nouvuser = malloc(sizeof(User));
    if (Nouvuser == NULL) {
        printf("Allocation mémoire échouée");
        return user;
    }

    strcpy(Nouvuser->name, name);
    Nouvuser->solde = solde;
    Nouvuser->numcompte = getHighestAccountNumber() + 1; 
    Nouvuser->suiv = NULL;

    fprintf(f, "*****************\n");
    fprintf(f, "Nom : %s\n",  Nouvuser->name);
    fprintf(f, "Numéro de compte : %d\n",  Nouvuser->numcompte);
    fprintf(f, "Solde : %.2f\n",  Nouvuser->solde);
    fprintf(f, "*****************\n");

    if (user == NULL) {
        fclose(f);
        return Nouvuser;
    }

    User *courant = user;
    while (courant->suiv != NULL) {
        courant = courant->suiv;
    }
    courant->suiv = Nouvuser;

    fclose(f);
    return user;
}
//***************************************//
void *modifyAccount(User *user, int numcompte)
{
    char name[50];
    while (user != NULL)
    {
        if (user->numcompte == numcompte)
        {
            printf("modifier votre nom : ");
            getchar();
            fgets(name, sizeof(name), stdin);
            strcpy(user->name, name);
        }
        else
            printf("aucun compte avec le numero %d \n", numcompte);
        user = user->suiv;
    }
}
//***************************************//

void *depotArgent(User *user, int numcompte)
{
    float nouvsolde;
    printf("Combien d'argent voulez-vous deposer ? ");
    scanf("%f", &nouvsolde);
    while (user != NULL)
    {
        if (user->numcompte == numcompte)
        {
            user->solde = user->solde + nouvsolde;
            return user;
        }
        user = user->suiv;
    }
    printf("Compte avec numéro %d non trouve.\n", numcompte);
    return NULL;
}
//***************************************//
void *retirerArgent(User *user, int numcompte)
{
    int accountFound = 0;
    float nouvsolde;

    while (user != NULL)
    {
        if (user->numcompte == numcompte)
        {
            accountFound = 1;
            while (1)
            {
                printf("Combien d'argent voulez-vous retirer ? ");
                scanf("%f", &nouvsolde);
                if (nouvsolde <= user->solde)
                {
                    user->solde = user->solde - nouvsolde;
                    return user;
                }
                else
                {
                    printf("Le montant que vous essayez de retirer est superieur a votre solde. Veuillez reessayer : \n ");
                }
            }
        }
        user = user->suiv;
    }

    if (!accountFound)
    {
        printf("Compte avec numero %d non trouve.\n", numcompte);
    }
    return NULL;
}
//***************************************//

void *transfererArgent(User *user, int numcompte1, int numcompte2)
{
    float montant = 0;

    User *temp = user; 

    while (temp != NULL)
    {
        if (temp->numcompte == numcompte1)
        {
            printf("Saisir le montant a transferer depuis le compte %d vers le compte %d : ", numcompte1, numcompte2);
            scanf("%f", &montant);

            if (montant > temp->solde)
            {
                printf("Le montant que vous essayez de transferer est superieur au solde du compte %d. Veuillez reessayer.\n", numcompte1);
            }
            temp->solde -= montant;
            break;
        }
        temp = temp->suiv;
    }

    if (temp == NULL)
    {
        printf("Compte avec numero %d non trouve.\n", numcompte1);
    }

    temp = user; 
    while (temp != NULL)
    {
        if (temp->numcompte == numcompte2)
        {
            temp->solde += montant;
            printf("Transfert de %.2f DH du compte %d vers le compte %d effectue avec succes.\n", montant, numcompte1, numcompte2);
        }
        temp = temp->suiv;
    }

    printf("Compte avec numéro %d non trouve.\n", numcompte2);
}

//***************************************//
User* deleteAccount(User *user, int numcompte) {
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

//*****************************************//
void *afficherAccount(User *user, int numcompte)
{
    User *courant = user;
    bool compteTrouve = false;

    printf("Liste des comptes actuelle : \n \n");
    while (courant != NULL)
    {
        if (courant->numcompte == numcompte)
        {
            printf("Le nom est : %s \n", courant->name);
            printf("Numéro de compte : %d \n", courant->numcompte);
            printf("Votre solde est : %.2f \n", courant->solde);
            printf("*****************************\n");
            compteTrouve = true;
        }
        courant = courant->suiv;
    }

    if (!compteTrouve)
    {
        printf("Aucun compte trouve avec le numero : %d.\n", numcompte);
    }
}
//***************************************//
void *affichageAdmin(User *user)
{
    while (user != NULL)
    {

        printf("votre nom est : %s \n", user->name);
        printf("votre numero de compte est : %d \n", user->numcompte);
        printf("votre solde actuelle est : %.2f DH \n", user->solde);
        printf("****************************\n");
        user = user->suiv;
    }
}
//***************************************//
void backtohome()
{
    while (getchar() != '\n')
        ;
    printf("Appuyez sur Entree pour revenir au menu...");
    getchar();
}
