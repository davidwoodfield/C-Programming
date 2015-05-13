#include <stdio.h>

int main()
{
    printf("\n------------------------- START ----------------------------\n");

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
    unsigned long long wsub2 = 0;
    unsigned int filesize_multiplier = 0;
    unsigned int filesize_remainder = 0;
    
    unsigned long long received_filesize = 0;
    
    printf("\noriginal postDataSize               =    %llu", postDataSize);
    
    /*
     * Divide postDataSize by 0xFFFFFFFF
     * 
     *
     *  =   00000010 00000010 00000010 00000010
     *      00000001 00000011 00110101 01010100
     *   /  
     *      00000000 00000000 00000000 00000000
     *      11111111 11111111 11111111 11111111
     *
     *  =   00000000 00000000 00000000 00000000
     *      00000010 00000010 00000010 00000010
     *
     * Decimal = 33686018
     *
     * Casting an unsigned long long to an unsigned int will take the first
     * 32 bits (from the right) of the 64 bit number and put them into the 32
     * bit number.
     */
    wsub2 = postDataSize / 0xFFFFFFFF;
    
    filesize_multiplier = (unsigned int)(wsub2);
    
    printf("\npostDataSize                        =    %llu", postDataSize);
    
    printf("\nuint postDataSize                   =    %u", (unsigned int)postDataSize);
    
    printf("\nfilesize_multiplier                 =    %u", filesize_multiplier);
    
    /*
     *
     * first set the value of wsub2 equal to wsub2 * (unsigned long long)0xFFFFFFFF
     *
     *  =    00000000 00000000 00000000 00000000
     *       00000010 00000010 00000010 00000010
     *    x
     *       00000000 00000000 00000000 00000000
     *       11111111 11111111 11111111 11111111
     *
     *  =    00000010 00000010 00000010 00000001
     *       11111101 11111101 11111101 11111110
     *
     *  Dec = 144680345608781310
     */
    wsub2 = wsub2 * (unsigned long long)0xFFFFFFFF;
    
    printf("\nwsub2                               =    %llu", wsub2);
    
    /*
     * Next, take wsub2 away from postDataSize
     * and store in filesize_remainder
     */
    filesize_remainder = (unsigned int)(postDataSize - wsub2);
    
    printf("\nfilesize_remainder                  =    %u", filesize_remainder);
    
    
    /*
     * Now we have our two 32bit integers.
     * filesize_multiplier and filesize_remainder
     */
     
    printf("\nfilesize_multiplier                 =    %u", filesize_multiplier);
    printf("\nfilesize_remainder                  =    %u", filesize_remainder);
    
    /*
     * Now let's convert them back to a 64 bit integer
     * received_filesize
     */
     
    /*
     * filesize_multiplier must be cast to an unsigned long long first else the
     * multiplication will be treated as an unsigned int and then when assigned
     * to a unsigned long long only the first right most 32 bits will be copied.
     *
     * received_filesize =  ((unsigned long long)filesize_multiplier) * 0xFFFFFFFF
     *
     *  =   00000010 00000010 00000010 00000010
     *    x
     *      11111111 11111111 11111111 11111111
     *
     *  =   00000010 00000010 00000010 00000001 
     *      11111101 11111101 11111101 11111110
     *
     * Dec = 144680345608781310
     */
    received_filesize = ((unsigned long long)filesize_multiplier) * 0xFFFFFFFF;
    
    printf("\nreceived_filesize                   =    %llu", received_filesize);
    
    /*
     * Now add on the filesize_remainder
     * - because that's the reverse of what we did earlier
     * 
     */
    received_filesize += filesize_remainder;
    
    printf("\nreceived_filesize                   =    %llu", received_filesize);
    
    printf("\n\n------------------------- END ----------------------------\n");
    
    return 0;
}
