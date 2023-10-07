#include "ft_printf.h"

// Function to calculate the number of digits in an integer
int numDigits(int num)
{
    int count = 0;
    while (num != 0) {
        num /= 16;  // Assuming hexadecimal representation for address
        count++;
    }
    return count;
}

// Function to convert an integer to a hexadecimal string
void intToHexStr(int num, char* buffer)
{
    const char* hexChars = "0123456789abcdef";
    int numDigits = 8; // Assuming 8 digits for address

    for (int i = numDigits - 1; i >= 0; i--) {
        buffer[i] = hexChars[num & 0xF];
        num >>= 4; // Shift right by 4 bits
    }

    buffer[numDigits] = '\0'; // Null-terminate the string
}

int ft_putadress(void *p, int i)
{
    if (p == NULL) {
        i = ft_putstr_pf("(nil)", i);
    } else {
        size_t addr = (size_t)p;

        // Calculate the number of hexadecimal digits needed
        int numDigits = 1;
        size_t temp = addr;
        while (temp > 15) {
            temp >>= 4;
            numDigits++;
        }

        // Allocate memory for the address string
        char* addrStr = (char*)malloc(numDigits + 1); // +1 for null terminator
        if (addrStr == NULL) {
            // Handle memory allocation failure if needed
            return -1;
        }

        // Convert the address to a hexadecimal string
        int u = numDigits - 1;
        while (u >= 0) {
            int digit = addr & 0xF;
            addrStr[u] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
            addr >>= 4;
            u--;
        }

        addrStr[numDigits] = '\0'; // Null-terminate the string

        i = ft_putstr_pf("0x", i);
        // Write the formatted address
        int written = 0;
        while (written < numDigits) {
            written += write(STDOUT_FILENO, addrStr + written, numDigits - written);
        }

        i = i + written;
        // Free the allocated memory
        free(addrStr);
    }
    
    return (i);
}
