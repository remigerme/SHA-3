CC = gcc
CFLAGS = -g -O2 -Wall -Wextra -Werror # -DDEBUG
INCLUDES = -lm -Isrc

shake128: src/utils.c src/keccak_rho.c src/sponge.c src/keccak_c.c src/sha3.c src/main.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

clean:
	rm -f shake128
