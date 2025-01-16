# SHA-3 implementation

The code have been implemented using [FIPS 202](https://csrc.nist.gov/pubs/fips/202/final).

I followed the FIPS 202 publication, and tried to keep things general. The only restriction on the parameters presented in the paper is I fixed b=1600 bits (=200 bytes). This isn't annoying because it is possible to use all the “goal” functions defined in the paper (SHA-3 of different sizes, SHAKE128, SHAKE256).

## Installation

```shell
make
```

## Tests

For now, there are only some manual tests available.

You can use the main program (SHAKE128) :

```shell
./shake128 32 < /dev/null
```

```shell
./shake128 32 < tests/short-text.txt
```

```shell
./shake128 32 < tests/short-binary.bin
```

```shell
./shake128 50 < tests/long-text.txt
```

Code implemented in the context for "Advanced Cryptology" course at École polytechnique by Rémi Germe.
