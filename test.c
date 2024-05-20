#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct eleve
{
    int num_eleve;
    char nom_eleve[50];
    int age;
    int classe;
    int note;
};
struct admin
{
    char username[50];
    char password[20];
};
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
void afficherDetailsEleves(struct eleve eleves[], int nbEleves)
{

    for (int i = 0; i < nbEleves; i++)
    {

        printf("Détails de l'eleve :\n");
        printf("Numero d'eleve Num  %d : %d\n", i, eleves[i].num_eleve);
        printf("Nom de l'eleve Num %d: %s\n", i, eleves[i].nom_eleve);
        printf("age de l'eleve Num %d : %d\n", i, eleves[i].age);
        printf("Classe de l'eleve Num %d: %d\n", i, eleves[i].classe);
        printf("Note de l'eleve Num %d: %d\n", i, eleves[i].note);
        printf("*******************");
        break;
    }
}
///////////////////////////////// fonction ajouter ///////////////////////////
struct eleve ajoutereleve(int *id)
{
    struct eleve eleves;
    eleves.num_eleve = *id;
    *id = *id + 1;

    printf("enter le nom d'eleve  :");
    getchar();
    fgets(eleves.nom_eleve, sizeof(eleves.nom_eleve), stdin);
    printf("enter l'age d'eleve  :\n");
    scanf("%d", &eleves.age);
    printf("enter la classe d'eleve :\n");
    scanf("%d", &eleves.classe);
    printf("entrer la note d'eleve :\n");
    scanf("%d", &eleves.note);

    printf("l'étudiant est ajouté avec succès");

    return eleves;
}
/////////////////////////////////fonction rechercher /////////////////////////////
void afficherDetailsEleveParNumero(struct eleve eleves[], int nbEleves, int numero)
{
    int eleveTrouve = 0;
    for (int i = 0; i < nbEleves; i++)
    {
        if (eleves[i].num_eleve == numero)
        {
            eleveTrouve = -1;
            printf("Détails de l'eleve :\n");
            printf("Numero d'eleve : %d\n", eleves[i].num_eleve);
            printf("Nom de l'eleve : %s\n", eleves[i].nom_eleve);
            printf("age de l'eleve : %d\n", eleves[i].age);
            printf("Classe de l'eleve : %d\n", eleves[i].classe);
            printf("Note de l'eleve : %d\n", eleves[i].note);
            break;
        }
    }
    if (!eleveTrouve)
    {
        printf("Aucun eleve trouve avec le numero %d.\n", numero);
    }
}
/////////////////////////////////////fonction supprimer eleve ////////////////////
void supprimerEleve(struct eleve eleves[], int nbEleves, int numero)
{
    int index = -1; // Initialisation de l'index de l'élève à supprimer

    // Recherche de l'index de l'élève à supprimer
    for (int i = 0; i < nbEleves - 1; i++)
    {
        if (eleves[i].num_eleve == numero)
        {
            index = i;
            break; // Sortir de la boucle dès que l'élève est trouvé
        }
    }

    // Si l'élève est trouvé, le supprimer en décalant les éléments suivants
    if (index != -1)
    {
        for (int i = index; i < nbEleves; i++)
        {
            eleves[i] = eleves[i + 1];
        }
        (nbEleves)--; // Réduire le nombre total d'élèves
        printf("Eleve supprime avec succes.\n");
    }
    else
    {
        printf("Aucun eleve trouve avec le numero %d.\n", numero);
    }
}
/////////////////////////////////// fonction modifier////////////////////////////

void modifiereleve(struct eleve eleves[], int nbEleves, int numero)
{
    int eleveTrouve = 0;
    for (int i = 0; i < nbEleves; i++)
    {
        if (eleves[i].num_eleve == numero)
        {
            eleveTrouve = -1;
            printf("enter les nouveaux Détails de l'eleve :\n");
            printf("nouveau Nom de l'eleve :\n");
            getchar();
            fgets(eleves[i].nom_eleve, sizeof(eleves[i].nom_eleve), stdin);
            printf("nouveau Âge de l'eleve :\n");
            scanf("%d", &eleves[i].age);
            printf("nouveau Classe de l'eleve : \n");
            scanf("%d", &eleves[i].classe);
            printf("nouvelle note de l'eleve : \n");
            scanf("%d", &eleves[i].note);
            break;
        }
    }
    printf("eleve modifier avec succes !");
    if (!eleveTrouve)
    {
        printf("Aucun eleve trouve avec le numero %d.\n", numero);
    }
}

int main()
{

    struct eleve eleves[100];
    struct admin admins[50];
    int choice1;
    int choice2;
    int choice;
    int lastStudentId = 1;
    int counter = 1;

    int *ptr = &lastStudentId;
    char ch;

    int numeroRecherche;
    int i = 0;
    char correctUsername[] = "rim kharmache";
    char correctPassword[] = "123456";
    while (strcmp(admins[0].username, correctUsername) != 0 || strcmp(admins[0].password, correctPassword) != 0)
    {

        system("cls");

        printf("=== Login ===\n");
        printf("Enter username: ");
        fgets(admins[0].username, sizeof(admins[0].username), stdin);
        admins[0].username[strcspn(admins[0].username, "\n")] = '\0'; // Remove trailing newline if present

        printf("Enter password: ");
        fgets(admins[0].password, sizeof(admins[0].password), stdin);
        admins[0].password[strcspn(admins[0].password, "\n")] = '\0'; // Remove trailing newline if present
    }
    if (strcmp(admins[0].username, correctUsername) == 0 && strcmp(admins[0].password, correctPassword) == 0)
    {
        printf("Login successful. Welcome, %s!\n", admins[0].username);

        do
        {
            printf("\n1. espace professeur .");
            printf("\n2. espace eleve .");
            printf("\n3. exit ");
            printf("\nEntrer votre choix :");
            scanf("%d", &choice2);
            system("cls");

            switch (choice2)
            {
            case 1:
                system("cls");
                // printf("saisir votre username :");
                // scanf("%s",admins[50].username);
                // printf("\nentrer votre mot de passe :");
                //     while (1) {
                //     ch = getch();  // Get a character without echoing to the console
                //     if (ch == '\r') {  // If Enter key is pressed
                //         admins[50].password[i] = '\0';  // Null-terminate the string
                //         break;
                //     } else if (ch == '\b' && i > 0) {  // If Backspace is pressed
                //         printf("\b \b");  // Move cursor back, print space, move cursor back again
                //         i--;  // Move back one character in the password array
                //     } else {
                //         printf("");  // Print asterisk () to the console
                //         admins[50].password[i] = ch;  // Store the character in the password array
                //         i++;  // Move forward one character in the password array
                //     }
                //     }

                //     if (strcmp(admins[50].username, correctUsername) == 0 && strcmp(admins[50].password, correctPassword) == 0){
                //         printf("******welcome!!!**** ");
                do
                {
                    printf("\n\t \t \t ---------------ECOLE RIM--------------------\n\n");
                    printf("menu :\n");
                    printf("1. ajouter un eleve .\n");
                    printf("2. affichier les details d'un eleve .\n");
                    printf("3. supprimer les details d'un eleve .\n");
                    printf("4. modifier les details d'un eleve .\n");
                    printf("5.exit\n");
                    printf("veuillez enter votre choix : ");
                    scanf("%d", &choice);

                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        eleves[lastStudentId] = ajoutereleve(ptr);
                        counter++;
                        break;
                    case 2:
                        system("cls");
                        for (int i = 1; i < lastStudentId; i++)
                        {

                            printf("Détails de l'eleve :\n");
                            printf("Numero d'eleve Num  %d : %d\n", i, eleves[i].num_eleve);
                            printf("Nom de l'eleve Num %d: %s\n", i, eleves[i].nom_eleve);
                            printf("age de l'eleve Num %d : %d\n", i, eleves[i].age);
                            printf("Classe de l'eleve Num %d: %d\n", i, eleves[i].classe);
                            printf("Note de l'eleve Num %d: %d\n", i, eleves[i].note);
                            printf("*******************");
                        }
                        break;
                    case 3:
                        system("cls");
                        printf("\n Entrez le numero de l'eleve dont vous souhaitez supprimer les details : \n");
                        scanf("%d", &numeroRecherche);
                        int eleveTrouve = 0;
                        for (i = 0; i < lastStudentId; i++)
                        {

                            if (numeroRecherche == eleves[i].num_eleve)
                            {
                                supprimerEleve(eleves, 100, numeroRecherche);
                                eleveTrouve = 1;
                            }
                        }
                        break;
                    case 4:
                        system("cls");
                        printf("\n Entrez le numero de l'eleve dont vous souhaitez modifier les details : \n");
                        scanf("%d", &numeroRecherche);
                        for (i = 0; i < lastStudentId; i++)
                        {

                            if (numeroRecherche == eleves[i].num_eleve)
                            {
                                modifiereleve(eleves, 100, numeroRecherche);
                                eleveTrouve = 1;
                            }
                        }
                        break;

                    case 5:
                        system("cls");
                        printf("log out ...\n");
                        break;
                    default:
                        printf("Choix invalide. Veuillez réessayer.\n");

                        break;
                    }
                } while (choice != 5);

                // }
                // else

                // printf("\nusername ou mots de passe incorrect");

                break;

            case 2:
                system("cls");
                printf("entrer votre numero :\n");
                scanf("%d", &numeroRecherche);
                printf("\nvotre details sont :");
                for (int i = 0; i < lastStudentId; i++)
                {

                    if (numeroRecherche == eleves[i].num_eleve)
                    {
                        afficherDetailsEleveParNumero(eleves, 100, numeroRecherche);
                    }
                }
                break;
            case 3:
                system("cls");
                printf("exiting .....");

                break;

            default:
                printf("choice unvalid ");
                break;
            }

        } while (choice1 != 3);
    }
    return 0;
}