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