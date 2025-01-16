#include "sha3.h"

#include <stdlib.h>
#include <string.h>

#include "keccak_c.h"
#include "utils.h"

// Returns a new array with the two bits suffix 01
char *prepare_sha3(char *M, size_t n) {
    char *N = (char *)malloc(sizeof(char) * (n + 1));
    memcpy(N, M, n);
    set_bit(&N[n], 0, 0);
    set_bit(&N[n], 1, 1);
    return N;
}

char *sha3_224(char *M, size_t n) {
    char *N = prepare_sha3(M, n);
    return keccak_c(56, N, 8 * n + 2, 28);
}

char *sha3_256(char *M, size_t n) {
    char *N = prepare_sha3(M, n);
    return keccak_c(64, N, 8 * n + 2, 32);
}

char *sha3_384(char *M, size_t n) {
    char *N = prepare_sha3(M, n);
    return keccak_c(96, N, 8 * n + 2, 48);
}

char *sha3_512(char *M, size_t n) {
    char *N = prepare_sha3(M, n);
    return keccak_c(128, N, 8 * n + 2, 64);
}

// Returns a new array with the 4 bits suffix 1111
char *prepare_shake(char *M, size_t n) {
    char *N = (char *)malloc(sizeof(char) * (n + 1));
    memcpy(N, M, n);
    set_bit(&N[n], 0, 1);
    set_bit(&N[n], 1, 1);
    set_bit(&N[n], 2, 1);
    set_bit(&N[n], 3, 1);
    return N;
}

char *shake128(char *M, size_t n, size_t d) {
    char *N = prepare_shake(M, n);
    return keccak_c(32, N, 8 * n + 4, d);
}

char *shake256(char *M, size_t n, size_t d) {
    char *N = prepare_shake(M, n);
    return keccak_c(64, N, 8 * n + 4, d);
}
