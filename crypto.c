#include "crypto.h"

void decrypt(t_decrypto *decrypt)
{
    int j = 0;
    int size = 0;
    int tmp = (decrypt->prefix / 3.00) / j;
    char **split = ft_split(decrypt->string, ',');

    while (decrypt->string[j])
    {
        size += printf("%f", ((int)decrypt->string[j] / (decrypt->prefix / 3.00)) * (j + 1));
        decrypt->prefix--;
        if (decrypt->prefix <= 0)
            decrypt->prefix = tmp;
        j++;
    }
}

void crypto(t_crypto *crypto)
{
    int j = 0;
    int size = 0;
    int alpha = 'a';
    char *tmp1 = NULL;
    char *_tmp = NULL;
    int tmp = (crypto->prefix * 3.00);

    while (crypto->string[j])
    {
        size += printf("[%lf%c]", (int)crypto->string[j] * (crypto->prefix * 3.00) / (j + 1), alpha);
        if (!_tmp)
        {
            float m = (int)crypto->string[j] * (crypto->prefix * 3.00) / (j + 1);
            _tmp = malloc(30);
            ftoa(m, _tmp, 6);
            _tmp = ft_strjoin(_tmp, ",");
        }
        else
        {
            float m = (int)crypto->string[j] * (crypto->prefix * 3.00) / (j + 1);
            tmp1 = malloc(30);
            ftoa(m, tmp1, 6);
            _tmp = ft_strjoin(_tmp, tmp1);
            _tmp = ft_strjoin(_tmp, ",");
        }
        crypto->prefix--;
        alpha++;
        if (alpha >= 'z')
            alpha = 'a';
        if (crypto->prefix <= 0)
            crypto->prefix = tmp;
        j++;
    }
    printf("\n{%s}\n", _tmp);
}

t_crypto *init_crypto(char *str, long long prefix)
{
    t_crypto *crypt;

    crypt = malloc(sizeof(t_crypto));
    crypt->string = ft_strdup(str);
    crypt->size = ft_strlen(str);
    crypt->prefix = prefix;
    return (crypt);
}

t_decrypto *init_decrypto(char *str, long long prefix)
{
    t_decrypto *decrypt;

    decrypt = malloc(sizeof(t_decrypto));
    decrypt->string = ft_strdup(str);
    decrypt->size = ft_strlen(str);
    decrypt->prefix = prefix;
    return (decrypt);
}

int main()
{
    t_crypto *crypt;
    t_decrypto *decrypt;

    crypt = init_crypto("hamza", 1);
    crypto(crypt);
}
