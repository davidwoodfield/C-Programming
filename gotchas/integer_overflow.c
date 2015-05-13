#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main()
{
    printf("\n------------------------- START ----------------------------\n");
    
    
    /*
     * A quick demonstration of integer overflow.
     *
     * When the value of (random * pid) is greater than the maximum size of an
     * integer, integer overflow happens. In two's complement the most
     * significant bit will become a 1 and make the number a large negative
     * number when an overflow happens. This of course depends on how far
     * the integer overflows.
     */
     
    int pid = 20405;
    unsigned int seed = (unsigned)time(NULL);
    int random = 0;
    int maxint = 0x7FFFFFFF;
    unsigned int maxuint = 0xFFFFFFFF;
    
    printf("\nseed                   =   %u", seed);
    
    srand(seed);
    
    printf("\nRAND_MAX               =   %d", RAND_MAX);
    
    printf("\nMax integer            =   %d", maxint);
    printf("\nMax unsigned integer   =   %u", maxuint);
    
    random = rand();
    
    printf("\nrandom number (int)    =   %d", random);
    printf("\nrandom number (uint)   =   %u", random);
    
    printf("\npid                    =   %d", pid);
    
    printf("\nrandom x pid (int)     =   %08d", (int)(random * pid));
    
    printf("\nrandom x pid (uint)    =   %08u", (unsigned int)(random * pid));

    
    printf("\n\n------------------------- END ----------------------------\n");
    
    return 0;
}
