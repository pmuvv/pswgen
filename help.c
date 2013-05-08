#include "main.h"

unsigned char printHelp(void)
{
    printf("Generate a password with the specified length and parameters\n\n");
    printf("PSWGEN [number] [/m] [/d] [/a] [/u[[ ]attributes]]\n\n");
    printf("    [number]    The number of numbers in the password\n");
    printf("    [/m]        Generation matrix passwords dimension [number]*[number]\n");
    printf("    [/d]        Geniration string passwords using mixed case letters and numbers\n");
    printf("    [/a]        Geniration string passwords using all simbols\n");
    printf("    [/u]        Geniration string passwords with the specified attributes\n");
    printf("Attributes: b  Using big letters       n  Using numbers\n");
    printf("            s  Using small letters     c  Using special simbols\n\n");
    printf("    Examples:\n\n");
    printf("        pswgen 8 /d      make password is 8 simbols using mixed case letters \n");
    printf("                         and numbers\n");
    printf("        pswgen 12 /u bs  make password is 12 simbols using big and small letters");
    printf("                         only");
    return 0;
}
