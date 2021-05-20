#ifndef CRYPTO
#define CRYPTO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_crypto
{
    int size;
    char *string;
    long long prefix;
} t_crypto;

typedef struct s_decrypto
{
    int size;
    char *string;
    long long prefix;
} t_decrypto;
void ftoa(float n, char *res, int afterpoint);
#endif