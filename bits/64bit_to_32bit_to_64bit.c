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
    
    unsigned int filesize_multiplier = 0;
    unsigned int filesize_remainder = 0;
    
    unsigned long long received_filesize = 0;
    
    printf("\noriginal postDataSize               =    %llu", postDataSize);
    
    /*
     * Shift postDataSize >> 32 and store in filesize_multiplier
     * This removes the first 32 bits (left), leaving the last 32 bits (right most)
     *
     * Binary = 00000000 00000000 00000000 00000000
     *          00000010 00000010 00000010 00000010
     *
     * Decimal = 33686018
     *
     * Casting an unsigned long long to an unsigned int will take the first
     * 32 bits (from the right) of the 64 bit number and put them into the 32
     * bit number.
     */
    filesize_multiplier = (unsigned int)(postDataSize >> 32);
    
    printf("\npostDataSize                        =    %llu", postDataSize);
    
    printf("\nuint postDataSize                   =    %u", (unsigned int)postDataSize);
    
    printf("\nfilesize_multiplier                 =    %u", filesize_multiplier);
    
    /*
     * Bitwise & 0xFFFFFFFF with postDataSize
     * Equilavent of doing bitwise & 0x00000000FFFFFFFF with postDateSize
     * This means the first 32bits (from the left) will be 0
     * and the last 32bits(from the left) will be unchanged
     *
     * Binary = 00000000 00000000 00000000 00000000
     *          00000001 00000011 00110101 01010100 
     *
     * Is this any different to simply casting postDataSize to an unsigned int?
     * cast to unsigned int and store in filesize_remainder
     */
    filesize_remainder = (unsigned int)(postDataSize & 0xFFFFFFFF);
    
    printf("\npostDataSize                        =    %llu", postDataSize);
    printf("\nfilesize_remainder                  =    %u", filesize_remainder);
    printf("\npostDataSize cast as uint           =    %u", postDataSize);
    printf("\npostDataSize & 0xFFFFFFFF           =    %llu", (postDataSize & 0xFFFFFFFF));
    printf("\npostDataSize & 0x00000000FFFFFFFF   =    %llu", (postDataSize & 0x00000000FFFFFFFF));
    
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
     * Casting filesize_multiplier to an unsigned int
     *
     * Binary = 00000000 00000000 00000000 00000000
     *          00000010 00000010 00000010 00000010
     *
     * Decimal = 33686018
     */
    received_filesize = (unsigned long long)filesize_multiplier;
     
    printf("\nreceived_filesize                   =    %llu", received_filesize);
    
    /*
     * But our filesize_multiplier is the left side 32 bits of the original
     * 64 bit number
     * Now shift received_filesize to the left 32 bits so the original 32 bits
     * from filesize_multiplier is correctly on the left.
     *
     * Binary = 00000010 00000010 00000010 00000010
     *          00000000 00000000 00000000 00000000
     *
     * Decimal = 144680345642467328
     */
    received_filesize = (received_filesize << 32);
    
    printf("\nreceived_filesize                   =    %llu", received_filesize);
    
    /*
     * Now we have the left most 32 bits correctly in place and the right most
     * 32 bits as all zeros.
     * We must bitwise or (|) the right most 32 bits with the filesize_remainder
     * (we can ignore the left most 32 bits of filesize_remainder as they will
     *  or'd with zero's)
     *
     *   00000000 00000000 00000000 00000000 (received_filesize right most 32bits)
     * | 00000001 00000011 00110101 01010100 (filesize_remainder 32 bits)
     *   ------------------------------------
     *   00000001 00000011 00110101 01010100
     *
     *   These bits are now set in received_filesize.
     *   
     *   Binary = 00000010 00000010 00000010 00000010
     *            00000001 00000011 00110101 01010100
     *
     *   Decimal = 144680345659454804
     *
     * Which is our orginal number. We have successfully gone from 64 bit to 32
     * bit back to 64 bit.
     */
    received_filesize = received_filesize | filesize_remainder;
    
    printf("\nreceived_filesize                   =    %llu", received_filesize);
    
    printf("\n\n------------------------- END ----------------------------\n");
    
    return 0;
}
