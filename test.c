#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Système de gestion bancaire

void clearInputBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

int operationsOfOurBank(void)
{
  int serviceNumber;
  system("cls");
  printf("Créer votre compte en tapant le numéro                    : 0\n");
  printf("Voir les informations de votre compte en tapant le numéro : 1\n");
  printf("Modifier votre solde en tapant le numéro                  : 2\n");
  printf("Transférer un montant vers un autre compte                : 3\n");
  printf("Voir tous les comptes existants dans la base de données   : 4\n");

  bool isValid = false;
  while (!isValid)
  {
    printf("Entrez un numéro pour débuter une opération : ");
    scanf("%d", &serviceNumber);
    clearInputBuffer();
    if (serviceNumber == 0 ||
        serviceNumber == 1 ||
        serviceNumber == 2 ||
        serviceNumber == 3 ||
        serviceNumber == 4)
    {
      isValid = true;
      return serviceNumber;
    }
    else
    {
      while (getchar() != '\n')
        ;
      system("cls");
      printf("Veuillez entrer un nombre entre 0 et 4.\n");
    }
  }
}

struct user
{
  char fullName[50];
  int acountNumber;
  float balance;
};

int main()
{

  struct user newUser[50];
  for (int i = 0; i < 50; i++)
  {
    newUser[i].acountNumber = 0;
  }

  int lastAcountNumber = 0;
  int tmpAcountNumber;
  char tmpFullName[50];
  system("cls");
  int serviceNumber;
  while (true)
  {
    serviceNumber = operationsOfOurBank();
    switch (serviceNumber)
    {
    case 0:
      system("cls");
      printf("Votre numéro est : %d \n", serviceNumber);
      printf("Pour créer votre compte, il faut quelques informations sur vous.\n");
      printf("Votre nom et prénom : ");
      fgets(tmpFullName, sizeof(tmpFullName), stdin);
      clearInputBuffer();
      lastAcountNumber++;
      newUser[lastAcountNumber].balance = 0;
      newUser[lastAcountNumber].acountNumber = lastAcountNumber;
      strcpy(newUser[lastAcountNumber].fullName, tmpFullName);
      printf("Votre nom : %s\n", newUser[lastAcountNumber].fullName);
      printf("Votre numéro de compte : %d\n", newUser[lastAcountNumber].acountNumber);
      printf("Votre solde : %d\n", (int)newUser[lastAcountNumber].balance); // Correction pour l'affichage du solde
      printf("Pour revenir à la page principale, tapez 0 : ");

      int exitVar;
      scanf("%d", &exitVar);
      clearInputBuffer();
      if (exitVar == 0)
      {
        break;
      }
      break;
    case 1:
      system("cls");
      printf("Le numéro de votre opération est : %d\n", serviceNumber);
      printf("Pour voir vos informations, tapez votre numéro de compte : ");

      scanf("%d", &tmpAcountNumber);
      clearInputBuffer();
      for (int i = 0; i < 50; i++)
      {
        if (newUser[i].acountNumber == tmpAcountNumber)
        {
          printf("Votre nom : %s\n", newUser[i].fullName);
          printf("Votre numéro de compte : %d\n", newUser[i].acountNumber);
          printf("Votre solde : %d\n", (int)newUser[i].balance); // Correction pour l'affichage du solde
          break;
        }
      }
      printf("Pour revenir à la page principale, tapez 0 : ");
      scanf("%d", &exitVar);
      clearInputBuffer();
      if (exitVar == 0)
      {
        break;
      }
      break;
    case 2:
      system("cls");
      printf("Le numéro de votre opération est : %d\n", serviceNumber);
      printf("Pour modifier votre solde, entrez votre numéro de compte : ");
      scanf("%d", &tmpAcountNumber);
      clearInputBuffer();
      for (int i = 0; i < 50; i++)
      {
        if (newUser[i].acountNumber == tmpAcountNumber)
        {
          printf("Votre nom : %s\n", newUser[i].fullName);
          printf("Votre numéro de compte : %d\n", newUser[i].acountNumber);
          printf("Votre solde : %d\n", (int)newUser[i].balance); // Correction pour l'affichage du solde
          break;
        }
      }
      int nouv;
      for (int i = 0; i < 50; i++)
      {
        if (newUser[i].acountNumber == tmpAcountNumber)
        {
            
          printf("Entrez votre nouveau solde : ");
          scanf("%d", &nouv);
          newUser[i].balance=nouv;
          printf("Nouveau solde : %f\n",newUser[i].balance); 
          break;
        }
      }

      printf("Pour revenir à la page principale, tapez 0 : ");
      scanf("%d", &exitVar);
      clearInputBuffer();
      if (exitVar == 0)
      {
        break;
      }
      break;
    case 3:
      system("cls");
      int acountNumber_post;
      int acountNumber_get;
      int moneyValue;
      printf("Le numéro de votre opération est : %d\n", serviceNumber);
      printf("Vous êtes ici pour transférer de l'argent vers un autre compte.\n");
      printf("Veuillez entrer le numéro de votre compte : ");
      scanf("%d", &acountNumber_post);
      clearInputBuffer();
      printf("Entrez le numéro du compte destinataire : ");
      scanf("%d", &acountNumber_get);
      clearInputBuffer();
      printf("Entrez le montant à transférer : ");
      scanf("%d", &moneyValue);
      clearInputBuffer();

      for (int i = 0; i < 50; i++)
      {
        if (newUser[i].acountNumber == acountNumber_post)
        {
          newUser[i].balance -= moneyValue;
          break;
        }
      }

      for (int i = 0; i < 50; i++)
      {
        if (newUser[i].acountNumber == acountNumber_get)
        {
          newUser[i].balance += moneyValue;
          break;
        }
      }
      printf("Pour revenir à la page principale, tapez 0 : ");
      scanf("%d", &exitVar);
      clearInputBuffer();
      if (exitVar == 0)
      {
        break;
      }
      break;
    case 4:
      for (int i = 0; i < 50; i++)
      {
        if (newUser[i].acountNumber != 0)
        {
          printf("Votre nom : %s\n", newUser[i].fullName);
          printf("Votre numéro de compte : %d\n", newUser[i].acountNumber);
          printf("Votre solde : %d\n", (int)newUser[i].balance); // Correction pour l'affichage du solde
        }
      }
      printf("Pour revenir à la page principale, tapez 0 : ");
      scanf("%d", &exitVar);
      clearInputBuffer();
      if (exitVar == 0)
      {
        break;
      }
      break;
    default:
      serviceNumber = operationsOfOurBank();
      break;
    }
  }
  return 0;
}