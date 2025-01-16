#include "sha3.h"

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr,
                "[Usage] ./shake128 d\n\tWhere d is the length of the output in bytes\n");
        return 1;
    }

    size_t d = atoi(argv[1]);

    size_t buf_size = 2048;
    char buf[buf_size];
    for (size_t i = 0; i < buf_size; ++i)
        buf[i] = 0;
    size_t bytes_read = read(STDIN_FILENO, buf, buf_size);

    char *res = shake128(buf, bytes_read, d);
    for (size_t i = 0; i < d; ++i)
        printf("%02hhx", res[i]);
    printf("\n");
}
