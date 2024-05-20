#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.c"
int main()
{
    int choix, type, num, num1, num2;
    char name[20];
    float solde;
    char nom[20];
    char password[20];
    User *user;
    user = NULL;
    Admin admin1 = {"amin", "12345", NULL};
    do
    {
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
            do
            {
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
                switch (choix)
                {
                case 1:
                    printf("saisir votre nom : ");
                    getchar();
                    fgets(name, sizeof(name), stdin);
                    printf("saisir votre solde initiale : ");
                    scanf("%f", &solde);
                    user = ajouterAccount(user, name, solde);
                    User *courant = user;
                    while (courant->suiv != NULL)
                    {
                        courant = courant->suiv;
                    }
                    printf("votre numero de compte est : %d \n ", courant->numcompte);
                    backtohome();
                    break;
                case 2:
                    printf("saisir le numero du compte : \n");
                    scanf("%d", &num);
                    if (user != NULL)
                    {
                        modifyAccount(user, num);
                        backtohome();
                    }
                    break;
                case 3:
                    printf("saisir votre numero du compte : \n");
                    scanf("%d", &num);
                    depotArgent(user, num);
                    backtohome();
                    break;
                case 4:
                    printf("saisir votre numero du compte : \n");
                    scanf("%d", &num);
                    retirerArgent(user, num);
                    backtohome();
                    break;
                case 5:
                    printf("saisir votre numero du compte : \n");
                    scanf("%d", &num1);
                    printf("saisir le numero du compte destinataire : \n");
                    scanf("%d", &num2);
                    transfererArgent(user, num1, num2);
                    backtohome();
                    break;
                case 6:
                    printf("saisir votre numero du compte : \n");
                    scanf("%d", &num);
                    user=deleteAccount(user, num);
                    backtohome();

                    break;
                case 7:
                    printf("saisir votre numero du compte : \n");
                    scanf("%d", &num);

                    afficherAccount(user, num);
                    backtohome();

                    break;
                case 8:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Choix invalide. Veuillez réessayer.\n");
                    backtohome();
                }
            } while (choix != 8);
            break;
        case 2:
            system("cls");
            printf("\n Saisir votre nom : ");
            getchar();
            fgets(nom, sizeof(nom), stdin);
            nom[strcspn(nom, "\n")] = '\0';
            printf("Saisir votre mot de passe : ");
            fgets(password, sizeof(password), stdin);
            password[strcspn(password, "\n")] = '\0';
            if (strcmp(admin1.name, nom) == 0 && strcmp(admin1.password, password) == 0)
            {
                do
                {
                    system("cls");
                    printf("\n--- //// **Espace administrateur** //// ---\n");
                    printf("1 - Afficher la liste des comptes\n");
                    printf("2 - Revenir au menu principal\n");
                    printf("Veuillez entrer votre choix : ");
                    scanf("%d", &choix);
                    switch (choix)
                    {
                    case 1:
                        affichageAdmin(user);
                        backtohome();
                        break;
                    case 2:
                        printf("Exiting...\n");
                        break;
                    default:
                        printf("choix incorrecte");
                    }
                } while (choix != 2);
            }
            else
            {
                printf("Nom d'utilisateur ou mot de passe incorrect.");
                while (getchar() != '\n')
                {
                    getchar();
                }
            }
            break;
        case 3:
            printf("exiting ...");
            break;
        default:
            printf("choix incorrect");
            while (getchar() != '\n')
            {
                getchar();
            }
        }

    } while (type != 3);
    return 0;
}
    /* User *current = user;
                    while (current!= NULL)
                    {   fprintf(f, "*****************\n");
                        fprintf(f, "Nom : %s\n", current->name);
                        fprintf(f, "Numéro de compte : %d\n", current->numcompte);
                        fprintf(f, "Solde : %.2f\n", current->solde);
                        fprintf(f, "*****************\n");

                        current = current->suiv;
                    }
                    */
 

