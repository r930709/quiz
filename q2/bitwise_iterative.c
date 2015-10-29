#include<stdio.h>
#include<stdlib.h>

int mystrlen(char str[])
{
    int count = 0;
    while(str[count]!='\0') {
        count++;
    }
    return(count);
}

/*__
	__builtin_clz() return the count of leading 0's
	__builtin_ctz() return the count of trailing zero
	__builtin_popcount() return the count of set bits as expected

*/

char Smallest_Character_Bit_Iterative(char str[], char c)
{
    int i=0,j=1;
    unsigned int bank=0;
    int size = mystrlen(str);
    for(i=0; i<size; i++) {
        bank += (0x01 << (str[i] - 97));
    }
    if(c-96 >= (32 - __builtin_clz(bank)) || c-96<(__builtin_ctz(bank)+1)) {
        return(__builtin_ctz(bank)+97);
    } else {
        while(!((bank >> (c-97+j)) & 1)) {
            j++;
        }
        return(c+j);
    }
}

