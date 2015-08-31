#include <stdio.h>
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
char s[6] = NULL;
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
c = 'x';
strncpy(s,
        "hello",
        sizeof(s) - 1);
pS = &s;


printf("\n ------ start of program ------ \n");

printf("\n sizeof of a (sizeof(a)) = %u", sizeof(a));
printf("\n address of a (&a) = %#08x", &a);
printf("\n value of a (a) = %d", a);

printf("\n sizeof of a (sizeof(pA)) = %u", sizeof(pA));
printf("\n address of pA (&pA) = %#08x", &pA);
printf("\n value of pA (pA) = %#08x", pA);
printf("\n the value of what pA points to (*pA) = %d", *pA);

printf("\n sizeof of a (sizeof(ppA)) = %u", sizeof(ppA));
printf("\n address of ppA (&ppA) = %#08x", &ppA);
printf("\n value of ppA (ppA) = %#08x", ppA);
printf("\n the value of what ppA points to (*ppA) = %#08x", *ppA);
printf("\n the value of the value of what ppA points to (**ppA) = %d", **ppA);

printf("\n now change a to 8 via the pointer to the pointer ppA (**ppA = 8)");
**ppA = 8;

printf("\n value of a (a) = %d", a);
printf("\n the value of what pA points to (*pA) = %d", *pA);
printf("\n the value of the value of what ppA points to (**ppA) = %d", **ppA);






printf("\n\n ------ end of program ------ \n");


return 0;
}                      
