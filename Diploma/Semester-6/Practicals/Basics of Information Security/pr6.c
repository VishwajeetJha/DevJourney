//Practical 6: Implement RSA Encryption
#include <stdio.h>

long long modExpo(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long p = 3, q = 11;
    long long N = p * q;
    long long phi = (p - 1) * (q - 1);
    long long e = 7;

    int msg = 14;

    printf("Original Message: %d\n", msg);

    printf("Encrypted: ");

    printf("%lld ", modExpo(msg, e, N));
    
    return 0;
}