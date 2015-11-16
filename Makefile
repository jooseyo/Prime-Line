all: prime testPrime

prime: main.c prime.c
	gcc -std=c99 -g -o prime main.c prime.c

testPrime: testPrime.c prime.c
	gcc -std=c99 -g -o testPrime testPrime.c prime.c
