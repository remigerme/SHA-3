#!/bin/bash

let "N = 1024 * 1024 * 100"

let "O = 1024 * 1024 * 10"

time openssl rand $N | ./shake128 $O
