#include "sha3.h"

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

// Max input size (in bytes) is 100Mb
#define MAX_INPUT_SIZE (1024 * 1024 * 100)

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "[Usage] ./shake128 d\n\tWhere d is the length of the "
                        "output in bytes\n");
        return 1;
    }

    size_t d = atoi(argv[1]);

    char *buf = (char *)calloc(MAX_INPUT_SIZE, sizeof(char));
    if (buf == NULL) {
        fprintf(stderr, "Couldn't allocate %d bytes\n", MAX_INPUT_SIZE);
        return 1;
    }
    size_t bytes_read = read(STDIN_FILENO, buf, MAX_INPUT_SIZE);

    char *res = (char *)malloc(d);
    shake128(buf, bytes_read, d, res);

#if DEBUG
    for (size_t i = 0; i < d; ++i)
        printf("%02hhx", res[i]);
    printf("\n");
#else
    printf("%.*s\n", (int)d, res);
#endif

    free(buf);
    free(res);
}
