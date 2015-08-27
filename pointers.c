#include <stdio.h>
int main()
{


int a = 7;
int *pA = NULL;
int **ppA = NULL;

pA = &a;
ppA = &pA;

printf("\n ------ start of program ------ \n");

printf("\n address of a (&a) = %#08x", &a);
printf("\n value of a (a) = %d", a);

printf("\n address of pA (&pA) = %#08x", &pA);
printf("\n value of pA (pA) = %#08x", pA);
printf("\n the value of what pA points to (*pA) = %d", *pA);

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
