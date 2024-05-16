#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "library.h"
#include <string.h>

//***************************************//
User *ajouterAccount(User *user, char name[20], float solde)
{
    User *Nouvuser = malloc(sizeof(User));
    strcpy(Nouvuser->name, name);
    Nouvuser->solde = solde;
    Nouvuser->numcompte = num_compte++;
    Nouvuser->suiv = NULL;

    if (user == NULL)
    {
        return Nouvuser;
    }

    User *courant = user;
    while (courant->suiv != NULL)
    {
        courant = courant->suiv;
    }
    courant->suiv = Nouvuser;

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
    return user;
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

    if (user == NULL)
    {
        printf("Compte avec numero %d non trouve.\n", numcompte1);
        return NULL;
    }

    printf("Saisir le montant a transferer depuis le compte %d vers le compte %d : ", numcompte1, numcompte2);
    scanf("%f", &montant);

    if (montant >= user->solde)
    {
        printf("Le montant que vous essayez de transferer est superieur au solde du compte %d. Veuillez reessayer.\n", numcompte1);
        return NULL;
    }
    while (user != NULL)
    {
        if (user->numcompte == numcompte1)
        {
            user->solde -= montant;
            break;
        }
        user = user->suiv;
    }
    while (user != NULL)
    {
        if (user->numcompte == numcompte2)
        {
            user->solde += montant;
            break;
        }
        user = user->suiv;
    }

    if (user == NULL)
    {
        printf("Compte avec numéro %d non trouve.\n", numcompte2);
        return NULL;
    }
    user = user->suiv;

    printf("Transfert de %.2f DH du compte %d vers le compte %d effectue avec succes.\n", montant, numcompte1, numcompte2);
}

//***************************************//
void *deleteAcount(User *user, int numcompte)
{
    User *current = user;
    User *prev = NULL;
    while (current != NULL)
    {
        if (current->numcompte == numcompte)
        {
            if (prev == NULL)
            {
                user = current->suiv;
            }
            else
            {
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
