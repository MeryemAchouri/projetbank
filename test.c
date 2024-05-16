#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    system("cls");
    typedef struct User User;
    struct User
    {
        int id;
        User *pNext;
    };
    
     User *user1,*user2;
     user1 =malloc(sizeof(User));
     user1->id=0;
     user1->pNext=NULL; 
     user2 =malloc(sizeof(User));
      user2->id=1;
      user1->pNext=user2;
      printf("%d\n%d",user1->id,user2->id);


    return 0;
}