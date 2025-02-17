CC = gcc
CFLAGS = -O2 -Wall -Wextra -Werror # -g -DDEBUG
INCLUDES = -lm -Isrc

shake128: src/sha3_utils.c src/keccak_rho.c src/sponge.c src/keccak_c.c src/sha3.c src/main.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

clean:
	rm -f shake128
