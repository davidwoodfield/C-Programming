#include <stdio.h>   
#include <string.h>

/*
 * Standard variables have two values:
 *
 * 1. An address value - the place in memory the 
 *                       variables is stored.
 *                        
 * 2. An object value - the data stored at it's
 *                      address value.
 *
 *
 * A pointer is a special variable that holds a memory address
 *
 */

int main()
{

/*
 * Intergers
 */
int a;
int *pA = NULL;
int **ppA = NULL;

/*
 * Characters and strings
 */
char c;
char s[6];
char *pS = NULL;

/*
 * integers
 */
a = 7;
pA = &a;
ppA = &pA;


/*
 * Characters and strings
 */
memset(s,
       0,
       sizeof(s));
c = 'x';
strncpy(s,
        "hello",
        sizeof(s) - 1);
pS = s;  // or pS = &s[0];


printf("\n ------ start of program ------ \n");  


printf("\n ------ INTEGERS ------ \n");

printf("\n sizeof of a (sizeof(a)) = %u", sizeof(a));
printf("\n address of a (&a) = %p", &a);
printf("\n value of a (a) = %d", a);

printf("\n sizeof of a (sizeof(pA)) = %u", sizeof(pA));
printf("\n address of pA (&pA) = %p", &pA);
printf("\n value of pA (pA) = %p", pA);
printf("\n the value of what pA points to (*pA) = %d", *pA);

printf("\n sizeof of a (sizeof(ppA)) = %u", sizeof(ppA));
printf("\n address of ppA (&ppA) = %p", &ppA);
printf("\n value of ppA (ppA) = %p", ppA);
printf("\n the value of what ppA points to (*ppA) = %p", *ppA);
printf("\n the value of the value of what ppA points to (**ppA) = %d", **ppA);

printf("\n now change a to 8 via the pointer to the pointer ppA (**ppA = 8)");
**ppA = 8;

printf("\n value of a (a) = %d", a);
printf("\n the value of what pA points to (*pA) = %d", *pA);
printf("\n the value of the value of what ppA points to (**ppA) = %d", **ppA);      

//printf("\n ------ CHARACTERS AND STRINGS ------ \n");






printf("\n\n ------ end of program ------ \n");


return 0;
}   
                   
