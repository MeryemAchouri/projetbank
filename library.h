#ifndef AMM_H_INCLUDED
#define AMM_H_INCLUDED

// les structures
typedef struct User User;
struct User
{
    char name[20];
    int numcompte;
    float solde;
    User *suiv;
};
typedef struct Admin Admin;
struct Admin
{
    char name[20];
    char password[20];
    Admin *suiv;
};
int num_compte = 1;
// les fonctions
void sauvegarderUtilisateurs(User *user);
User *ajouterAccount(User *user, char name[20], float solde);
void *modifyAccount(User *user, int numcompte);
void *depotArgent(User *user, int numcompte);
void *retirerArgent(User *user, int numcompte);
void *transfererArgent(User *user, int numcompte1, int numcompte2);
User *deleteAccount(User *user, int numcompte);
void *afficherAccount(User *user, int numcompte);
void *affichageAdmin(User *user);
void backtohome();
#endif