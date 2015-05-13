#include <stdio.h>

int main()
{
    printf("---- START ----\n");

    /*
     * Start off with a 64 bit number
     * 
     * Binary = 00000010 00000010 00000010 00000010
     *          00000001 00000011 00110101 01010100
     *
     * Decimal = 144680345659454804
     *
     * The idea is to split the 64 bit number into two 32 bit numbers.
     *
     * Why?
     *
     */

    /*
     * Cannot be defined like this as constants are only integer constants
     * by default. Using the suffix ULL tells the compiler it's a unsigned
     * long long.
     * unsigned long long postDataSize = 144680345659454804;
     */
    unsigned long long postDataSize = 144680345659454804ULL;
    
    unsigned int filesize_multiplier = 0;
    unsigned int filesize_remainder = 0;
    
    printf("\noriginal postDataSize = %llu", postDataSize);
    
    /*
     * Shift postDataSize >> 32 and store in filesize_multiplier
     * This removes the first 32 bits, leaving the last 32 bits
     *
     * Casting an unsigned long long to an unsigned int will take the first
     * 32 bits (from the right) of the 64 bit number and put them into the 32
     * bit number.
     */
    filesize_multiplier = (unsigned int)(postDataSize >> 32);
    
    printf("\nshifted postDataSize = %llu", postDataSize);
    
    printf("\nuint postDataSize = %u", (unsigned int)postDataSize);
    
    printf("\nfilesize_multiplier = %u", filesize_multiplier);
    
    /*
     * Bitwise & 0xFFFFFFFF with postDataSize
     */
    
    
    
    printf("\n\n----- END -----\n");
    
    return 0;
}

